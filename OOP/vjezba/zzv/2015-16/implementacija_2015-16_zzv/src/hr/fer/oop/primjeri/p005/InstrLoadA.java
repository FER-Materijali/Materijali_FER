package hr.fer.oop.primjeri.p005;

public class InstrLoadA implements Instruction {

	int address;
	
	public InstrLoadA(int address){
		this.address = address;
	}
	
	@Override
	public void execute(Registers registers, Memory memory) {
		registers.setA(memory.getFromLocation(address));
	}

	@Override
	public String toString(){
		return "loadA ["+address+"]";
	}
}
