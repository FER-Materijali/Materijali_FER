package hr.fer.oop.primjeri.p005;

public class InstrHalt implements Instruction {
	
	public InstrHalt(){
		super();
	}

	@Override
	public void execute(Registers registers, Memory memory) {
		registers.setHalt(true);
	}
	
	@Override
	public String toString(){
		return "halt";
	}
	
}
