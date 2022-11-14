package hr.fer.oop.primjeri.p005;

import hr.fer.oop.primjeri.p005.InstrHalt;
import hr.fer.oop.primjeri.p005.InstrJump;
import hr.fer.oop.primjeri.p005.InstrJumpIfTest;
import hr.fer.oop.primjeri.p005.InstrLoadA;
import hr.fer.oop.primjeri.p005.InstrPrint;
import hr.fer.oop.primjeri.p005.InstrStoreA;
import hr.fer.oop.primjeri.p005.InstrSub;
import hr.fer.oop.primjeri.p005.InstrTestZero;

public class Main {
	public static void main(String[] args) {
		Processor proc = new Processor();
		loadProgram(proc);
		proc.run();
	}

	private static void loadProgram(Processor proc) {
		Object[] instructions = { new InstrJump(3), "Hello world!", 11, new InstrLoadA(2), new InstrSub(1),
				new InstrStoreA(2), new InstrTestZero(), new InstrJumpIfTest(11), new InstrLoadA(1), new InstrPrint(),
				new InstrJump(3), new InstrHalt() };
		for (int address = 0; address < instructions.length; address++) {
			proc.getMemory().storeAtLocation(address, instructions[address]);
		}
	}
}