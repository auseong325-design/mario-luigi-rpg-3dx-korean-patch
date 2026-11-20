// fps60 TG: post-analysis fix-ups for one game.
//  * vtable address points get labels  <Class>::vtable  (secondary vtables: vtable_sec0x<off>)
//  * unnamed virtual functions get  <Class>::vfunc_0x<slot offset>  (owner = most-base class using it)
//  * undefined gaps in executable blocks are scanned for ARM prologues (push {..,lr} / str lr,[sp,#-4]!)
//  * per-module coverage statistics are written to <stats.tsv>
// Usage (headless): -postScript PostAnalysis.java <layout.tsv> <stats.tsv>
//@category fps60
import java.io.File;
import java.io.PrintWriter;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.TreeMap;

import ghidra.app.cmd.disassemble.ArmDisassembleCommand;
import ghidra.app.cmd.function.CreateFunctionCmd;
import ghidra.app.script.GhidraScript;
import ghidra.app.util.NamespaceUtils;
import ghidra.program.model.address.Address;
import ghidra.program.model.address.AddressRange;
import ghidra.program.model.address.AddressSet;
import ghidra.program.model.address.AddressSetView;
import ghidra.program.model.address.AddressSpace;
import ghidra.program.model.data.IntegerDataType;
import ghidra.program.model.data.PointerDataType;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionIterator;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.listing.InstructionIterator;
import ghidra.program.model.listing.Listing;
import ghidra.program.model.mem.Memory;
import ghidra.program.model.mem.MemoryBlock;
import ghidra.program.model.symbol.Namespace;
import ghidra.program.model.symbol.SourceType;
import ghidra.program.model.symbol.SymbolTable;

public class PostAnalysis extends GhidraScript {

    private AddressSpace space;
    private int warnings = 0;

    private Address a(String hex) {
        return space.getAddress(Long.decode(hex));
    }

    private void warn(String msg) {
        warnings++;
        if (warnings <= 200) {
            println("WARN " + msg);
        }
    }

    private Namespace classNs(String path) {
        try {
            Namespace n = NamespaceUtils.createNamespaceHierarchy(path, null, currentProgram, SourceType.ANALYSIS);
            if (n != null && !(n instanceof ghidra.program.model.listing.GhidraClass)) {
                n = NamespaceUtils.convertNamespaceToClass(n);
            }
            return n;
        }
        catch (Exception e) {
            warn("namespace " + path + ": " + e.getMessage());
            return null;
        }
    }

    private static boolean isPrologue(int w) {
        if ((w & 0xFFFF4000) == 0xE92D4000) {
            return true;  // stmdb sp!, {..., lr}
        }
        return w == 0xE52DE004;  // str lr, [sp, #-4]!
    }

    private static String moduleOf(MemoryBlock b) {
        String n = b.getName();
        int i = n.indexOf('.');
        return i > 0 ? n.substring(0, i) : n;
    }

    @Override
    protected void run() throws Exception {
        String[] args = getScriptArgs();
        space = currentProgram.getAddressFactory().getDefaultAddressSpace();
        Listing listing = currentProgram.getListing();
        Memory mem = currentProgram.getMemory();
        SymbolTable st = currentProgram.getSymbolTable();
        List<String[]> rows = new ArrayList<>();
        for (String line : Files.readAllLines(new File(args[0]).toPath(), StandardCharsets.UTF_8)) {
            if (!line.isEmpty() && !line.startsWith("#")) {
                rows.add(line.split("\t", -1));
            }
        }

        // ---- vtables ----
        int nVt = 0;
        for (String[] r : rows) {
            if (!r[0].equals("VTABLE")) {
                continue;
            }
            Address vt = a(r[1]);
            String cls = r[2];
            int ott = Integer.parseInt(r[3]);
            int nslots = Integer.parseInt(r[4]);
            Address ap = vt.add(8);
            try {
                if (listing.getDefinedDataAt(vt) == null) {
                    listing.clearCodeUnits(vt, vt.add(7), false);
                    listing.createData(vt, IntegerDataType.dataType);
                    listing.createData(vt.add(4), PointerDataType.dataType);
                }
                for (int i = 0; i < nslots; i++) {
                    Address s = ap.add(4L * i);
                    if (listing.getDefinedDataAt(s) == null && listing.getInstructionContaining(s) == null) {
                        listing.clearCodeUnits(s, s.add(3), false);
                        listing.createData(s, PointerDataType.dataType);
                    }
                }
                String name = ott == 0 ? "vtable" : String.format("vtable_sec0x%x", -ott);
                if (!cls.equals("-")) {
                    Namespace n = classNs(cls);
                    if (n != null) {
                        st.createLabel(ap, name, n, SourceType.ANALYSIS).setPrimary();
                        nVt++;
                    }
                }
                else {
                    st.createLabel(ap, name + "_for_" + r[5], currentProgram.getGlobalNamespace(),
                        SourceType.ANALYSIS).setPrimary();
                    nVt++;
                }
            }
            catch (Exception e) {
                warn("vtable " + vt + " " + cls + ": " + e.getMessage());
            }
        }
        println("vtable address points labelled: " + nVt);

        // ---- virtual function names ----
        int nSlot = 0;
        for (String[] r : rows) {
            if (!r[0].equals("VTSLOT")) {
                continue;
            }
            Address at = a(r[1]);
            Function f = getFunctionAt(at);
            if (f == null) {
                if (listing.getInstructionAt(at) == null) {
                    new ArmDisassembleCommand(at, null, false).applyTo(currentProgram, monitor);
                }
                new CreateFunctionCmd(at).applyTo(currentProgram, monitor);
                f = getFunctionAt(at);
            }
            if (f == null || f.isThunk() || f.getSymbol().getSource() != SourceType.DEFAULT) {
                continue;
            }
            Namespace n = classNs(r[2]);
            if (n == null) {
                continue;
            }
            try {
                f.setParentNamespace(n);
                f.setName("vfunc_" + r[3], SourceType.ANALYSIS);
                nSlot++;
            }
            catch (Exception e) {
                warn("vfunc " + at + " " + r[2] + ": " + e.getMessage());
            }
        }
        println("virtual functions named: " + nSlot);

        // ---- prologue gap fill ----
        AddressSet text = new AddressSet();
        for (MemoryBlock b : mem.getBlocks()) {
            if (b.isExecute() && b.isInitialized()) {
                text.add(b.getStart(), b.getEnd());
            }
        }
        int totalNew = 0;
        for (int round = 0; round < 4 && !monitor.isCancelled(); round++) {
            AddressSetView undef = listing.getUndefinedRanges(text, false, monitor);
            List<Address> starts = new ArrayList<>();
            for (AddressRange rg : undef) {
                long s = (rg.getMinAddress().getOffset() + 3) & ~3L;
                long e = rg.getMaxAddress().getOffset();
                for (long p = s; p + 3 <= e; p += 4) {
                    Address pa = space.getAddress(p);
                    if (isPrologue(mem.getInt(pa))) {
                        starts.add(pa);
                    }
                }
            }
            int made = 0;
            for (Address p : starts) {
                if (listing.getInstructionAt(p) != null || listing.getDefinedDataContaining(p) != null) {
                    continue;
                }
                new ArmDisassembleCommand(p, null, false).applyTo(currentProgram, monitor);
                if (listing.getInstructionAt(p) != null && getFunctionAt(p) == null) {
                    if (new CreateFunctionCmd(p).applyTo(currentProgram, monitor)) {
                        made++;
                    }
                }
            }
            println("gap fill round " + round + ": candidates " + starts.size() + " new functions " + made);
            totalNew += made;
            if (made == 0) {
                break;
            }
            analyzeChanges(currentProgram);
        }

        // ---- statistics ----
        Map<String, long[]> stats = new TreeMap<>();  // text, instr, undefined, funcs, named, thunks
        for (MemoryBlock b : mem.getBlocks()) {
            if (!(b.isExecute() && b.isInitialized())) {
                continue;
            }
            long[] s = stats.computeIfAbsent(moduleOf(b), k -> new long[6]);
            s[0] += b.getSize();
            AddressSet bs = new AddressSet(b.getStart(), b.getEnd());
            InstructionIterator it = listing.getInstructions(bs, true);
            while (it.hasNext()) {
                Instruction ins = it.next();
                s[1] += ins.getLength();
            }
            s[2] += listing.getUndefinedRanges(bs, false, monitor).getNumAddresses();
            FunctionIterator fi = listing.getFunctions(bs, true);
            while (fi.hasNext()) {
                Function f = fi.next();
                s[3]++;
                if (f.isThunk()) {
                    s[5]++;
                }
                else if (f.getSymbol().getSource() != SourceType.DEFAULT) {
                    s[4]++;
                }
            }
        }
        try (PrintWriter w = new PrintWriter(new File(args[1]), StandardCharsets.UTF_8)) {
            w.println("module\ttext_bytes\tinstr_bytes\tinstr_pct\tundefined_bytes\tfunctions\tnamed\tthunks");
            long[] tot = new long[6];
            for (Map.Entry<String, long[]> e : stats.entrySet()) {
                long[] s = e.getValue();
                for (int i = 0; i < 6; i++) {
                    tot[i] += s[i];
                }
                w.printf("%s\t%d\t%d\t%.1f\t%d\t%d\t%d\t%d%n", e.getKey(), s[0], s[1], 100.0 * s[1] / s[0], s[2],
                    s[3], s[4], s[5]);
            }
            w.printf("TOTAL\t%d\t%d\t%.1f\t%d\t%d\t%d\t%d%n", tot[0], tot[1], 100.0 * tot[1] / tot[0], tot[2],
                tot[3], tot[4], tot[5]);
        }
        println("PostAnalysis done; gap-fill functions " + totalNew + "; warnings " + warnings);
    }
}
