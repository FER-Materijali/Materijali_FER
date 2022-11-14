package hr.fer.oop.primjeri.p005;

public class InstrJump implements Instruction {
	private int address;

	public InstrJump(int address){
		this.address = address;
	}

	@Override
	public void execute(Registers registers, Memory memory) {
		registers.setProgramCounter(address);
	}

	@Override
	public String toString() {
		return "bezuvjetni skok na lokaciju " + address;
	}
}
