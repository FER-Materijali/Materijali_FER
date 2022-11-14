package hr.fer.oop.primjeri.p005;

public class InstrTestZero implements Instruction {
	
	public InstrTestZero() {
		super();
	}

	@Override
	public void execute(Registers registers, Memory memory) {
		if(registers.getA().equals(0)){
			registers.setTest(true);
		}
	}
	
	@Override
	public String toString(){
		return "testZero";
	}
}
