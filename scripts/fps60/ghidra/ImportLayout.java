// fps60 TG: pre-analysis import of one game (static code.bin + all relocated CROs in ONE program).
// Reads work/fps60/ghidra/<game>/layout.tsv written by scripts/fps60/ghidra/prepare.py.
// Usage (headless): -preScript ImportLayout.java <layout.tsv>
//@category fps60
import java.io.File;
import java.math.BigInteger;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import ghidra.app.cmd.disassemble.ArmDisassembleCommand;
import ghidra.app.cmd.disassemble.DisassembleCommand;
import ghidra.app.cmd.function.CreateFunctionCmd;
import ghidra.app.cmd.function.CreateThunkFunctionCmd;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.address.AddressSet;
import ghidra.program.model.address.AddressSpace;
import ghidra.program.model.data.PointerDataType;
import ghidra.program.model.lang.Register;
import ghidra.program.model.listing.Data;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.listing.Listing;
import ghidra.program.model.mem.Memory;
import ghidra.program.model.mem.MemoryBlock;
import ghidra.program.model.symbol.Namespace;
import ghidra.program.model.symbol.SourceType;
import ghidra.program.model.symbol.Symbol;
import ghidra.program.model.symbol.SymbolTable;

public class ImportLayout extends GhidraScript {

    private AddressSpace space;
    private Register tmode;
    private final Map<String, byte[]> fileCache = new HashMap<>();
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

    private byte[] fileBytes(String path) throws Exception {
        byte[] b = fileCache.get(path);
        if (b == null) {
            b = Files.readAllBytes(new File(path).toPath());
            fileCache.put(path, b);
        }
        return b;
    }

    private void perms(MemoryBlock b, String p) {
        b.setRead(p.contains("r"));
        b.setWrite(p.contains("w"));
        b.setExecute(p.contains("x"));
    }

    private Namespace ns(String name) throws Exception {
        if (name == null || name.equals("-")) {
            return currentProgram.getGlobalNamespace();
        }
        SymbolTable st = currentProgram.getSymbolTable();
        return st.getOrCreateNameSpace(currentProgram.getGlobalNamespace(), name, SourceType.IMPORTED);
    }

    private boolean setThumb(Address at) {
        if (currentProgram.getListing().getInstructionContaining(at) != null) {
            return false;  // already decoded (in whichever mode the flow chose); never re-mode
        }
        try {
            currentProgram.getProgramContext().setValue(tmode, at, at, BigInteger.ONE);
            return true;
        }
        catch (Exception e) {
            warn("TMode " + at + ": " + e.getMessage());
            return false;
        }
    }

    private boolean disasm(Address at, boolean thumb) {
        Listing l = currentProgram.getListing();
        if (l.getInstructionAt(at) != null) {
            return true;
        }
        Data d = l.getDefinedDataContaining(at);
        if (d != null) {
            return false;
        }
        ArmDisassembleCommand cmd = new ArmDisassembleCommand(at, null, thumb);
        cmd.applyTo(currentProgram, monitor);
        return l.getInstructionAt(at) != null;
    }

    private Function ensureFunction(Address at, boolean thumb) throws Exception {
        Function f = getFunctionAt(at);
        if (f != null) {
            return f;
        }
        if (thumb) {
            setThumb(at);
        }
        if (!disasm(at, thumb)) {
            return null;
        }
        CreateFunctionCmd cmd = new CreateFunctionCmd(at);
        cmd.applyTo(currentProgram, monitor);
        return getFunctionAt(at);
    }

    private int makeVeneers(List<String[]> veneers) {
        Listing listing = currentProgram.getListing();
        int nThunk = 0;
        for (String[] r : veneers) {
            Address v = a(r[1]);
            long t = Long.decode(r[2]);
            Address ta = space.getAddress(t & ~1L);
            try {
                Function tf = ensureFunction(ta, (t & 1) != 0);
                if (tf == null) {
                    warn("veneer " + v + ": no target function at " + ta);
                    continue;
                }
                if (listing.getInstructionAt(v) == null) {
                    warn("veneer " + v + ": not disassembled");
                    continue;
                }
                Function vf = getFunctionAt(v);
                Function cont = getFunctionContaining(v);
                if (vf == null && cont != null && !cont.getEntryPoint().equals(v)) {
                    AddressSet nb = new AddressSet(cont.getBody());
                    nb.deleteRange(v, v.add(7));
                    cont.setBody(nb);  // a tail branch absorbed the veneer; cut it out again
                }
                if (vf == null) {
                    CreateThunkFunctionCmd cmd = new CreateThunkFunctionCmd(v, new AddressSet(v, v.add(3)), ta);
                    if (cmd.applyTo(currentProgram, monitor)) {
                        nThunk++;
                    }
                    else {
                        Function c2 = getFunctionContaining(v);
                        warn("thunk " + v + ": " + cmd.getStatusMsg() + (c2 == null ? "" :
                            " [in " + c2.getName(true) + "@" + c2.getEntryPoint() + " body " + c2.getBody() + "]"));
                    }
                }
                else if (!vf.isThunk()) {
                    vf.setThunkedFunction(tf);
                    nThunk++;
                }
            }
            catch (Exception e) {
                warn("veneer " + v + " -> " + ta + ": " + e.getMessage());
            }
        }
        return nThunk;
    }

    @Override
    protected void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length < 1) {
            throw new IllegalArgumentException("usage: ImportLayout.java <layout.tsv>");
        }
        space = currentProgram.getAddressFactory().getDefaultAddressSpace();
        tmode = currentProgram.getProgramContext().getRegister("TMode");
        List<String[]> rows = new ArrayList<>();
        for (String line : Files.readAllLines(new File(args[0]).toPath(), StandardCharsets.UTF_8)) {
            if (line.isEmpty() || line.startsWith("#")) {
                continue;
            }
            rows.add(line.split("\t", -1));
        }
        Memory mem = currentProgram.getMemory();
        Listing listing = currentProgram.getListing();
        SymbolTable st = currentProgram.getSymbolTable();
        String staticPath = null;
        for (String[] r : rows) {
            if (r[0].equals("STATIC")) {
                staticPath = r[1];
            }
        }

        // ---- 1. memory blocks ----
        int nBlocks = 0;
        long staticEnd = -1;
        for (String[] r : rows) {
            if (r[0].equals("BLOCK") && r[5].equals(staticPath)) {
                staticEnd = Math.max(staticEnd, Long.decode(r[2]) + Long.decode(r[3]));
            }
        }
        for (String[] r : rows) {
            if (r[0].equals("BLOCK")) {
                String name = r[1];
                Address start = a(r[2]);
                long size = Long.decode(r[3]);
                String perm = r[4];
                String file = r[5];
                long off = Long.decode(r[6]);
                if (file.equals(staticPath)) {
                    MemoryBlock b = mem.getBlock(start);
                    if (b == null) {
                        throw new IllegalStateException("static block missing at " + start);
                    }
                    if (!b.getStart().equals(start)) {
                        mem.split(b, start);
                        b = mem.getBlock(start);
                    }
                    Address end = start.add(size);
                    if (b.getEnd().compareTo(end) > 0) {
                        mem.split(b, end);
                        b = mem.getBlock(start);
                    }
                    b.setName(name);
                    perms(b, perm);
                }
                else {
                    byte[] data = fileBytes(file);
                    MemoryBlock b = mem.createInitializedBlock(name, start,
                        new java.io.ByteArrayInputStream(data, (int) off, (int) size), size, monitor, false);
                    b.setSourceName(new File(file).getName());
                    perms(b, perm);
                }
                nBlocks++;
            }
            else if (r[0].equals("BSS")) {
                if (staticEnd > 0) {
                    // BinaryLoader may load the whole file; drop the zero padding after .data
                    MemoryBlock tail = mem.getBlock(space.getAddress(staticEnd));
                    if (tail != null && tail.getStart().getOffset() == staticEnd) {
                        println("removing loader tail block " + tail.getName() + " " + tail.getStart() + "-" +
                            tail.getEnd());
                        mem.removeBlock(tail, monitor);
                    }
                    staticEnd = -1;
                }
                MemoryBlock b = mem.createUninitializedBlock(r[1], a(r[2]), Long.decode(r[3]), false);
                perms(b, r[4]);
                nBlocks++;
            }
        }
        println("blocks: " + nBlocks);

        // ---- 2. static import slots bound to CRO analysis addresses ----
        int nPatch = 0;
        for (String[] r : rows) {
            if (r[0].equals("PATCH32")) {
                mem.setInt(a(r[1]), (int) Long.parseLong(r[2].substring(2), 16));
                nPatch++;
            }
        }
        println("static import slots patched: " + nPatch);

        // ---- 3. veneer literal words become pointers (so they are never disassembled) ----
        List<String[]> veneers = new ArrayList<>();
        for (String[] r : rows) {
            if (r[0].equals("VENEER")) {
                veneers.add(r);
                Address lit = a(r[1]).add(4);
                try {
                    if (listing.getDefinedDataAt(lit) == null) {
                        listing.clearCodeUnits(lit, lit.add(3), false);
                        listing.createData(lit, PointerDataType.dataType);
                    }
                }
                catch (Exception e) {
                    warn("veneer literal " + lit + ": " + e.getMessage());
                }
            }
        }

        // ---- 4. function entry points: Thumb context first, then one bulk ARM disassembly ----
        AddressSet armSeeds = new AddressSet();
        List<Address> thumbSeeds = new ArrayList<>();
        for (String[] r : rows) {
            if (r[0].equals("FUNC")) {
                Address at = a(r[1]);
                if (r[2].equals("1")) {
                    setThumb(at);
                    thumbSeeds.add(at);
                }
                else {
                    armSeeds.add(at);
                }
            }
            else if (r[0].equals("VENEER")) {
                armSeeds.add(a(r[1]));
                long t = Long.decode(r[2]);
                Address ta = space.getAddress(t & ~1L);
                if ((t & 1) != 0) {
                    setThumb(ta);
                    thumbSeeds.add(ta);
                }
                else {
                    armSeeds.add(ta);
                }
            }
        }
        for (Address t : thumbSeeds) {
            disasm(t, true);
        }
        DisassembleCommand dis = new DisassembleCommand(armSeeds, null, true);
        dis.applyTo(currentProgram, monitor);
        println("disassembled seeds: arm " + armSeeds.getNumAddresses() + " thumb " + thumbSeeds.size());

        // ---- 4b. veneers -> thunk functions of their targets (before other functions, so that a tail
        //          'b veneer' ends the caller's body instead of absorbing the veneer) ----
        int nThunk = makeVeneers(veneers);

        // ---- 5. create + name functions ----
        int nFunc = 0, nNamed = 0, nAlias = 0;
        for (String[] r : rows) {
            if (!r[0].equals("FUNC")) {
                continue;
            }
            Address at = a(r[1]);
            boolean thumb = r[2].equals("1");
            Function f;
            try {
                f = ensureFunction(at, thumb);
            }
            catch (Exception e) {
                warn("function " + at + " (" + r[3] + "): " + e.getMessage());
                continue;
            }
            if (f == null) {
                warn("no function at " + at + " (" + r[3] + ", " + r[5] + ")");
                continue;
            }
            nFunc++;
            String name = r[3];
            if (name.equals("-")) {
                continue;
            }
            Namespace n = ns(r[4]);
            if (f.getSymbol().getSource() == SourceType.DEFAULT) {
                f.setName(name, SourceType.IMPORTED);
                if (!r[4].equals("-")) {
                    f.setParentNamespace(n);
                }
                nNamed++;
            }
            else if (!f.getName().equals(name)) {
                st.createLabel(at, name, n, SourceType.IMPORTED);  // alias (C1/C2, D1/D2 ...)
                nAlias++;
            }
        }
        println("functions: " + nFunc + " named " + nNamed + " aliases " + nAlias);

        // ---- 6. data labels ----
        int nLab = 0;
        for (String[] r : rows) {
            if (!r[0].equals("LABEL")) {
                continue;
            }
            Address at = a(r[1]);
            try {
                Symbol s = st.createLabel(at, r[2], ns(r[3]), SourceType.IMPORTED);
                if (s != null && getFunctionAt(at) == null) {
                    s.setPrimary();
                }
                nLab++;
            }
            catch (Exception e) {
                warn("label " + r[2] + " @" + at + ": " + e.getMessage());
            }
        }
        println("labels: " + nLab);

        // ---- 7. (veneer thunks were created before step 5) ----
        println("veneer thunks: " + nThunk);

        // ---- 8. plate comments ----
        Map<Address, List<String>> plates = new HashMap<>();
        for (String[] r : rows) {
            if (r[0].equals("COMMENT")) {
                plates.computeIfAbsent(a(r[1]), k -> new ArrayList<>()).add(r[2]);
            }
        }
        for (Map.Entry<Address, List<String>> e : plates.entrySet()) {
            String text = String.join("\n", e.getValue());
            String old = getPlateComment(e.getKey());
            setPlateComment(e.getKey(), old == null ? text : old + "\n" + text);
        }

        // ---- 9. analysis options ----
        String[][] opts = {
            {"Embedded Media", "false"},
            {"Decompiler Parameter ID", "true"},
        };
        for (String[] o : opts) {
            try {
                setAnalysisOption(currentProgram, o[0], o[1]);
            }
            catch (Exception e) {
                warn("analysis option " + o[0] + ": " + e.getMessage());
            }
        }
        println("ImportLayout done; warnings " + warnings);
    }
}
