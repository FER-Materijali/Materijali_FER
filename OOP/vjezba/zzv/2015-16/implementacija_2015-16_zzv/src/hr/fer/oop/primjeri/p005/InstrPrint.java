package hr.fer.oop.primjeri.p005;

public class InstrPrint implements Instruction {

	public InstrPrint(){
		super();
	}
	
	@Override
	public void execute(Registers registers, Memory memory) {
		System.out.println(registers.getA());
	}
	
	@Override
	public String toString(){
		return "print";
	}
}
