// fps60 TG: full decompiled C dump, one file per module (split into parts above a size limit).
// Usage (headless, read-only): -postScript DumpDecomp.java <out dir> <threads> <timeout s> <split MB> <modules|all>
// Writes <out dir>/<module>.c (or <module>_01.c, _02.c ...), functions.tsv, summary.txt.
// Every function starts with:   // FUNC 0x<addr> <name> (<module>)
// followed by one info line:    //   sym <mangled> | size 0x.. | file <Module>+0x.. | callers(N): 0x.. ...
//@category fps60
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileOutputStream;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.nio.charset.StandardCharsets;
import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedHashMap;
import java.util.LinkedHashSet;
import java.util.List;
import java.util.Map;
import java.util.TreeMap;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileOptions;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionIterator;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.listing.InstructionIterator;
import ghidra.program.model.mem.MemoryBlock;
import ghidra.program.model.symbol.Reference;
import ghidra.program.model.symbol.ReferenceIterator;
import ghidra.program.model.symbol.Symbol;
import ghidra.util.task.TaskMonitor;

public class DumpDecomp extends GhidraScript {

    private final List<DecompInterface> allIfc = Collections.synchronizedList(new ArrayList<>());
    private ThreadLocal<DecompInterface> tl;
    private int timeout;

    static String moduleOfBlock(MemoryBlock b) {
        if (b == null) {
            return "?";
        }
        String n = b.getName();
        int i = n.indexOf('.');
        return i > 0 ? n.substring(0, i) : n;
    }

    private DecompInterface newIfc() {
        DecompInterface ifc = new DecompInterface();
        DecompileOptions opts = new DecompileOptions();
        opts.grabFromProgram(currentProgram);
        ifc.setOptions(opts);
        ifc.toggleCCode(true);
        ifc.toggleSyntaxTree(false);
        ifc.setSimplificationStyle("decompile");
        if (!ifc.openProgram(currentProgram)) {
            throw new IllegalStateException("decompiler open failed: " + ifc.getLastMessage());
        }
        allIfc.add(ifc);
        return ifc;
    }

    /** Returns [status, text]. */
    private String[] decompile(Function f) {
        DecompInterface ifc = tl.get();
        String err;
        try {
            DecompileResults r = ifc.decompileFunction(f, timeout, TaskMonitor.DUMMY);
            if (r != null && r.decompileCompleted() && r.getDecompiledFunction() != null) {
                return new String[] {"ok", r.getDecompiledFunction().getC()};
            }
            err = r == null ? "no result" : r.getErrorMessage();
            if (r != null && r.isTimedOut()) {
                err = "timeout " + timeout + "s";
            }
        }
        catch (Exception e) {
            err = e.toString();
        }
        // restart this thread's decompiler (it may have died), then emit disassembly instead
        try {
            ifc.dispose();
        }
        catch (Exception e) {
            // ignore
        }
        tl.set(newIfc());
        String status = err != null && err.startsWith("timeout") ? "timeout" : "failed";
        return new String[] {status, "/* DECOMPILATION FAILED: " + (err == null ? "?" : err.trim().replace("*/", "* /")) +
            " -- disassembly follows */\n" + disassembly(f)};
    }

    String disassembly(Function f) {
        StringBuilder sb = new StringBuilder();
        InstructionIterator it = currentProgram.getListing().getInstructions(f.getBody(), true);
        int n = 0;
        while (it.hasNext() && n < 20000) {
            Instruction ins = it.next();
            sb.append(String.format("//   %08x: %s%n", ins.getAddress().getOffset(), ins.toString()));
            n++;
        }
        return sb.toString();
    }

    String infoLine(Function f, String module, MemoryBlock blk) {
        StringBuilder sb = new StringBuilder("//  ");
        String mangled = null;
        for (Symbol s : currentProgram.getSymbolTable().getSymbols(f.getEntryPoint())) {
            if (s.getName().startsWith("_Z")) {
                mangled = s.getName();
                break;
            }
        }
        if (mangled != null) {
            sb.append(" sym ").append(mangled).append(" |");
        }
        sb.append(String.format(" size 0x%x", f.getBody().getNumAddresses()));
        if (!module.equals("static")) {
            long base = f.getEntryPoint().getOffset() & ~0x7FFFFFL;
            sb.append(String.format(" | file %s+0x%x", module, f.getEntryPoint().getOffset() - base));
        }
        LinkedHashSet<Long> callers = new LinkedHashSet<>();
        int dataRefs = 0;
        ReferenceIterator ri = currentProgram.getReferenceManager().getReferencesTo(f.getEntryPoint());
        while (ri.hasNext()) {
            Reference r = ri.next();
            if (r.getReferenceType().isCall() || r.getReferenceType().isJump()) {
                Function c = getFunctionContaining(r.getFromAddress());
                callers.add(c != null ? c.getEntryPoint().getOffset() : r.getFromAddress().getOffset());
            }
            else {
                dataRefs++;
            }
        }
        sb.append(" | callers(").append(callers.size()).append(")");
        int k = 0;
        for (Long c : callers) {
            if (k++ == 8) {
                sb.append(" ...");
                break;
            }
            sb.append(String.format(" 0x%08x", c));
        }
        if (dataRefs > 0) {
            sb.append(" | datarefs ").append(dataRefs);
        }
        return sb.toString();
    }

    static String mangledOf(ghidra.program.model.listing.Program p, Function f) {
        for (Symbol s : p.getSymbolTable().getSymbols(f.getEntryPoint())) {
            if (s.getName().startsWith("_Z")) {
                return s.getName();
            }
        }
        return "";
    }

    private class PartWriter {
        final File dir;
        final String module;
        final long split;
        int part = 0;
        long bytes = 0;
        long line = 0;
        PrintWriter w;
        final List<String[]> index = new ArrayList<>();  // addr, end, size, name, sym, part, line, status, ncallers

        PartWriter(File dir, String module, long split) {
            this.dir = dir;
            this.module = module;
            this.split = split;
        }

        File partFile(int p) {
            return new File(dir, String.format("%s_%02d.c", module, p));
        }

        void open() throws Exception {
            if (w != null) {
                w.close();
            }
            part++;
            w = new PrintWriter(new BufferedWriter(new OutputStreamWriter(new FileOutputStream(partFile(part)),
                StandardCharsets.UTF_8), 1 << 20));
            bytes = 0;
            line = 1;
            String hdr = String.format("// fps60 TG decompiled C: %s module %s part %d (Ghidra %s, %s)%n" +
                "// Addresses: static = runtime address; CRO = fixed analysis base (crolink.py), NOT runtime.%n%n",
                currentProgram.getName(), module, part, ghidra.framework.Application.getApplicationVersion(),
                currentProgram.getLanguageID() + ":" + currentProgram.getCompilerSpec().getCompilerSpecID());
            emit(hdr);
        }

        void emit(String s) {
            w.write(s);
            bytes += s.getBytes(StandardCharsets.UTF_8).length;
            for (int i = 0; i < s.length(); i++) {
                if (s.charAt(i) == '\n') {
                    line++;
                }
            }
        }

        void add(Function f, String name, String info, String status, String body, int ncallers) throws Exception {
            if (w == null || bytes > split) {
                open();
            }
            long startLine = line;
            emit(String.format("// FUNC 0x%08x %s (%s)%n", f.getEntryPoint().getOffset(), name, module));
            emit(info + "\n");
            emit(body.endsWith("\n") ? body : body + "\n");
            emit("\n");
            index.add(new String[] {String.format("0x%08x", f.getEntryPoint().getOffset()),
                String.format("0x%08x", f.getBody().getMaxAddress().getOffset() + 1),
                String.format("0x%x", f.getBody().getNumAddresses()), name, mangledOf(currentProgram, f),
                Integer.toString(part), Long.toString(startLine), status, Integer.toString(ncallers)});
        }

        List<String> finish() throws Exception {
            if (w != null) {
                w.close();
            }
            List<String> names = new ArrayList<>();
            if (part == 1) {
                File single = new File(dir, module + ".c");
                single.delete();
                if (!partFile(1).renameTo(single)) {
                    throw new IllegalStateException("rename failed " + single);
                }
                names.add(single.getName());
            }
            else {
                for (int p = 1; p <= part; p++) {
                    names.add(partFile(p).getName());
                }
            }
            return names;
        }
    }

    @Override
    protected void run() throws Exception {
        String[] args = getScriptArgs();
        File out = new File(args[0]);
        int threads = Integer.parseInt(args[1]);
        timeout = Integer.parseInt(args[2]);
        long split = Long.parseLong(args[3]) * 1024L * 1024L;
        String filter = args.length > 4 ? args[4] : "all";
        out.mkdirs();
        // read-only run: uninitialised blocks (bss, hw pages) must not look constant to the decompiler
        for (MemoryBlock b : currentProgram.getMemory().getBlocks()) {
            if (!b.isInitialized() && !b.isWrite()) {
                b.setWrite(true);
            }
        }
        tl = ThreadLocal.withInitial(this::newIfc);

        Map<String, List<Function>> byModule = new TreeMap<>((x, y) -> {
            if (x.equals(y)) {
                return 0;
            }
            if (x.equals("static")) {
                return -1;
            }
            if (y.equals("static")) {
                return 1;
            }
            return x.compareTo(y);
        });
        FunctionIterator fi = currentProgram.getListing().getFunctions(true);
        while (fi.hasNext()) {
            Function f = fi.next();
            String m = moduleOfBlock(currentProgram.getMemory().getBlock(f.getEntryPoint()));
            byModule.computeIfAbsent(m, k -> new ArrayList<>()).add(f);
        }
        List<String> wanted = new ArrayList<>();
        for (String m : byModule.keySet()) {
            if (filter.equals("all") || ("," + filter + ",").contains("," + m + ",")) {
                wanted.add(m);
            }
        }
        ExecutorService pool = Executors.newFixedThreadPool(threads);
        Map<String, String> summary = new LinkedHashMap<>();
        File indexFile = new File(out, filter.equals("all") ? "functions.tsv" : "functions_" + filter.replace(',', '_') + ".tsv");
        try (PrintWriter idx = new PrintWriter(indexFile, StandardCharsets.UTF_8)) {
            idx.println("addr\tend\tsize\tmodule\tname\tsymbol\tfile\tline\tstatus\tcallers");
            for (String m : wanted) {
                List<Function> funcs = byModule.get(m);
                long t0 = System.currentTimeMillis();
                PartWriter pw = new PartWriter(out, m, split);
                int ok = 0, failed = 0, timeouts = 0, thunks = 0;
                final int chunk = 400;
                for (int i = 0; i < funcs.size(); i += chunk) {
                    monitor.checkCancelled();
                    List<Function> sub = funcs.subList(i, Math.min(funcs.size(), i + chunk));
                    List<Future<String[]>> fut = new ArrayList<>();
                    for (Function f : sub) {
                        if (f.isThunk()) {
                            fut.add(null);
                        }
                        else {
                            fut.add(pool.submit(() -> decompile(f)));
                        }
                    }
                    for (int j = 0; j < sub.size(); j++) {
                        Function f = sub.get(j);
                        MemoryBlock blk = currentProgram.getMemory().getBlock(f.getEntryPoint());
                        String info = infoLine(f, m, blk);
                        int nc = 0;
                        int p = info.indexOf("callers(");
                        if (p >= 0) {
                            nc = Integer.parseInt(info.substring(p + 8, info.indexOf(')', p)));
                        }
                        if (fut.get(j) == null) {
                            Function t = f.getThunkedFunction(true);
                            String tn = t == null ? "?" : t.getName(true);
                            String tm = t == null ? "?" : moduleOfBlock(currentProgram.getMemory().getBlock(t.getEntryPoint()));
                            String body = String.format("// veneer/thunk -> 0x%08x %s (%s)%n",
                                t == null ? 0 : t.getEntryPoint().getOffset(), tn, tm);
                            pw.add(f, "->" + tn, info, "thunk", body, nc);
                            thunks++;
                            continue;
                        }
                        String[] r = fut.get(j).get();
                        pw.add(f, f.getName(true), info, r[0], r[1], nc);
                        if (r[0].equals("ok")) {
                            ok++;
                        }
                        else if (r[0].equals("timeout")) {
                            timeouts++;
                        }
                        else {
                            failed++;
                        }
                    }
                    if ((i / chunk) % 10 == 9) {
                        println(String.format("  %s: %d/%d functions, %.0fs", m, i + sub.size(), funcs.size(),
                            (System.currentTimeMillis() - t0) / 1000.0));
                    }
                }
                List<String> files = pw.finish();
                for (String[] e : pw.index) {
                    String file = files.size() == 1 ? files.get(0) : files.get(Integer.parseInt(e[5]) - 1);
                    idx.println(String.join("\t", e[0], e[1], e[2], m, e[3], e[4], file, e[6], e[7], e[8]));
                }
                idx.flush();
                String s = String.format("%s\tfunctions %d\tok %d\tfailed %d\ttimeout %d\tthunks %d\tfiles %s\t%.0fs",
                    m, funcs.size(), ok, failed, timeouts, thunks, String.join(",", files),
                    (System.currentTimeMillis() - t0) / 1000.0);
                summary.put(m, s);
                println("DUMP " + s);
            }
        }
        finally {
            pool.shutdownNow();
            for (DecompInterface d : allIfc) {
                try {
                    d.dispose();
                }
                catch (Exception e) {
                    // ignore
                }
            }
        }
        try (PrintWriter w = new PrintWriter(new File(out, filter.equals("all") ? "summary.txt" : "summary_" + filter.replace(',', '_') + ".txt"), StandardCharsets.UTF_8)) {
            for (String s : summary.values()) {
                w.println(s);
            }
        }
    }
}
