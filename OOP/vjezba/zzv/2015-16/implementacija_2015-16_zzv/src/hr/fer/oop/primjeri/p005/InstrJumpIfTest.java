package hr.fer.oop.primjeri.p005;

public class InstrJumpIfTest implements Instruction {
	private int address;
	
	public InstrJumpIfTest(int address){
		this.address = address;
	}
	
	@Override
	public void execute(Registers registers,Memory memory){
		if(registers.isTest()){
			registers.setProgramCounter(address);
		}
	}
	
	@Override
	public String toString(){
		return "jumpIfTest "+address;
	}
}
