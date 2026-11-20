// fps60 TG: decompile selected functions for scripts/fps60/ghidra/decomp.py (read-only run on a snapshot).
// Usage (headless): -postScript DecompFuncs.java <out file> <flags> <target> [<target> ...]
//   flags: comma list of asm, xrefs, nodecomp, timeout=<s>, maxmatch=<n>   ("-" = none)
//   target: 0x<address> (any address inside a function) or a name: exact symbol / mangled name,
//           full path a::b::c, or a case-insensitive substring of the full function name.
//@category fps60
import java.io.File;
import java.io.PrintWriter;
import java.nio.charset.StandardCharsets;
import java.util.ArrayList;
import java.util.LinkedHashMap;
import java.util.LinkedHashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileOptions;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.app.util.NamespaceUtils;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionIterator;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.listing.InstructionIterator;
import ghidra.program.model.mem.MemoryBlock;
import ghidra.program.model.symbol.Reference;
import ghidra.program.model.symbol.ReferenceIterator;
import ghidra.program.model.symbol.Symbol;
import ghidra.program.model.symbol.SymbolIterator;

public class DecompFuncs extends GhidraScript {

    private PrintWriter out;

    static String moduleOf(MemoryBlock b) {
        if (b == null) {
            return "?";
        }
        String n = b.getName();
        int i = n.indexOf('.');
        return i > 0 ? n.substring(0, i) : n;
    }

    private String module(Address a) {
        return moduleOf(currentProgram.getMemory().getBlock(a));
    }

    private List<Function> resolve(String t, int maxMatch) {
        List<Function> res = new ArrayList<>();
        if (t.matches("(?i)0x[0-9a-f]+|[0-9]+")) {
            Address a = currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(Long.decode(t) & ~1L);
            Function f = getFunctionContaining(a);
            if (f == null) {
                f = getFunctionAt(a);
            }
            if (f != null) {
                res.add(f);
            }
            else {
                out.println("// " + t + ": no function contains this address (" + module(a) + ")");
            }
            return res;
        }
        Set<Function> found = new LinkedHashSet<>();
        SymbolIterator si = currentProgram.getSymbolTable().getSymbols(t);
        while (si.hasNext()) {
            Symbol s = si.next();
            Function f = getFunctionAt(s.getAddress());
            if (f != null) {
                found.add(f);
            }
        }
        if (found.isEmpty() && t.contains("::")) {
            for (Symbol s : NamespaceUtils.getSymbols(t, currentProgram)) {
                Function f = getFunctionAt(s.getAddress());
                if (f != null) {
                    found.add(f);
                }
            }
        }
        if (found.isEmpty()) {
            String q = t.toLowerCase();
            FunctionIterator fi = currentProgram.getListing().getFunctions(true);
            while (fi.hasNext()) {
                Function f = fi.next();
                if (f.getName(true).toLowerCase().contains(q)) {
                    found.add(f);
                }
                else {
                    for (Symbol s : currentProgram.getSymbolTable().getSymbols(f.getEntryPoint())) {
                        if (s.getName().toLowerCase().contains(q)) {
                            found.add(f);
                            break;
                        }
                    }
                }
            }
        }
        if (found.size() > maxMatch) {
            out.println("// " + t + ": " + found.size() + " matches; refine the name or use an address:");
            int k = 0;
            for (Function f : found) {
                if (k++ == 60) {
                    out.println("//   ...");
                    break;
                }
                out.printf("//   0x%08x %s (%s)%n", f.getEntryPoint().getOffset(), f.getName(true),
                    module(f.getEntryPoint()));
            }
            return res;
        }
        if (found.isEmpty()) {
            out.println("// " + t + ": no matching function");
        }
        res.addAll(found);
        return res;
    }

    private String header(Function f) {
        String m = module(f.getEntryPoint());
        String name = f.isThunk() && f.getThunkedFunction(true) != null ? "->" + f.getThunkedFunction(true).getName(true)
            : f.getName(true);
        StringBuilder sb = new StringBuilder(String.format("// FUNC 0x%08x %s (%s)%n//  ",
            f.getEntryPoint().getOffset(), name, m));
        for (Symbol s : currentProgram.getSymbolTable().getSymbols(f.getEntryPoint())) {
            if (s.getName().startsWith("_Z")) {
                sb.append(" sym ").append(s.getName()).append(" |");
                break;
            }
        }
        sb.append(String.format(" size 0x%x", f.getBody().getNumAddresses()));
        if (!m.equals("static")) {
            long base = f.getEntryPoint().getOffset() & ~0x7FFFFFL;
            sb.append(String.format(" | file %s+0x%x", m, f.getEntryPoint().getOffset() - base));
        }
        return sb.toString();
    }

    private void xrefs(Function f) {
        Map<Long, String> callers = new LinkedHashMap<>();
        List<String> data = new ArrayList<>();
        ReferenceIterator ri = currentProgram.getReferenceManager().getReferencesTo(f.getEntryPoint());
        while (ri.hasNext()) {
            Reference r = ri.next();
            Function c = getFunctionContaining(r.getFromAddress());
            if (r.getReferenceType().isCall() || r.getReferenceType().isJump()) {
                callers.put(r.getFromAddress().getOffset(), String.format("0x%08x in %s (%s) [%s]",
                    r.getFromAddress().getOffset(), c == null ? "?" : c.getName(true), module(r.getFromAddress()),
                    r.getReferenceType().getName()));
            }
            else {
                Symbol s = getSymbolAt(r.getFromAddress());
                data.add(String.format("0x%08x %s (%s) [%s]", r.getFromAddress().getOffset(),
                    c != null ? "in " + c.getName(true) : (s != null ? s.getName(true) : ""),
                    module(r.getFromAddress()), r.getReferenceType().getName()));
            }
        }
        // callers through veneers/thunks
        for (Address ta : f.getFunctionThunkAddresses(true) == null ? new Address[0] : f.getFunctionThunkAddresses(true)) {
            ReferenceIterator ti = currentProgram.getReferenceManager().getReferencesTo(ta);
            while (ti.hasNext()) {
                Reference r = ti.next();
                Function c = getFunctionContaining(r.getFromAddress());
                callers.put(r.getFromAddress().getOffset(), String.format("0x%08x in %s (%s) [%s via veneer 0x%08x]",
                    r.getFromAddress().getOffset(), c == null ? "?" : c.getName(true), module(r.getFromAddress()),
                    r.getReferenceType().getName(), ta.getOffset()));
            }
        }
        out.println("// xrefs: " + callers.size() + " code, " + data.size() + " data");
        for (String s : callers.values()) {
            out.println("//   " + s);
        }
        for (String s : data) {
            out.println("//   data " + s);
        }
    }

    private void asm(Function f) {
        out.println("// disassembly:");
        InstructionIterator it = currentProgram.getListing().getInstructions(f.getBody(), true);
        while (it.hasNext()) {
            Instruction ins = it.next();
            StringBuilder hex = new StringBuilder();
            try {
                for (byte b : ins.getBytes()) {
                    hex.append(String.format("%02x", b));
                }
            }
            catch (Exception e) {
                hex.append("??");
            }
            Symbol s = getSymbolAt(ins.getAddress());
            if (s != null && !ins.getAddress().equals(f.getEntryPoint())) {
                out.println("//  " + s.getName() + ":");
            }
            out.printf("//   %08x: %-8s %s%n", ins.getAddress().getOffset(), hex, ins.toString());
        }
    }

    @Override
    protected void run() throws Exception {
        String[] args = getScriptArgs();
        // args: <request file> <out file>; request: line 1 = flags (space separated), then one target per line
        List<String> req = java.nio.file.Files.readAllLines(new File(args[0]).toPath(), StandardCharsets.UTF_8);
        String flags = req.isEmpty() ? "" : req.get(0);
        List<String> targets = new ArrayList<>();
        for (int i = 1; i < req.size(); i++) {
            if (!req.get(i).isBlank()) {
                targets.add(req.get(i).trim());
            }
        }
        boolean wantAsm = false, wantX = false, noDec = false;
        int timeout = 120, maxMatch = 8;
        for (String fl : flags.trim().split("\\s+")) {
            if (fl.equals("asm")) {
                wantAsm = true;
            }
            else if (fl.equals("xrefs")) {
                wantX = true;
            }
            else if (fl.equals("nodecomp")) {
                noDec = true;
            }
            else if (fl.startsWith("timeout=")) {
                timeout = Integer.parseInt(fl.substring(8));
            }
            else if (fl.startsWith("maxmatch=")) {
                maxMatch = Integer.parseInt(fl.substring(9));
            }
        }
        for (MemoryBlock b : currentProgram.getMemory().getBlocks()) {
            if (!b.isInitialized() && !b.isWrite()) {
                b.setWrite(true);  // read-only run; see DumpDecomp
            }
        }
        out = new PrintWriter(new File(args[1]), StandardCharsets.UTF_8);
        DecompInterface ifc = null;
        try {
            if (!noDec) {
                ifc = new DecompInterface();
                DecompileOptions opts = new DecompileOptions();
                opts.grabFromProgram(currentProgram);
                ifc.setOptions(opts);
                ifc.toggleCCode(true);
                ifc.toggleSyntaxTree(false);
                ifc.setSimplificationStyle("decompile");
                ifc.openProgram(currentProgram);
            }
            for (String target : targets) {
                for (Function f : resolve(target, maxMatch)) {
                    out.println(header(f));
                    if (wantX) {
                        xrefs(f);
                    }
                    if (f.isThunk()) {
                        Function t = f.getThunkedFunction(true);
                        out.printf("// veneer/thunk -> 0x%08x %s (%s)%n", t == null ? 0 : t.getEntryPoint().getOffset(),
                            t == null ? "?" : t.getName(true), t == null ? "?" : module(t.getEntryPoint()));
                    }
                    else if (ifc != null) {
                        DecompileResults r = ifc.decompileFunction(f, timeout, monitor);
                        if (r != null && r.decompileCompleted() && r.getDecompiledFunction() != null) {
                            out.print(r.getDecompiledFunction().getC());
                        }
                        else {
                            out.println("/* DECOMPILATION FAILED: " + (r == null ? "?" : r.getErrorMessage()) + " */");
                            if (!wantAsm) {
                                asm(f);
                            }
                        }
                    }
                    if (wantAsm) {
                        asm(f);
                    }
                    out.println();
                }
            }
        }
        finally {
            if (ifc != null) {
                ifc.dispose();
            }
            out.close();
        }
    }
}
