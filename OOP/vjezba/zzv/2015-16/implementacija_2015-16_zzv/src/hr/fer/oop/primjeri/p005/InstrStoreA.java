package hr.fer.oop.primjeri.p005;

public class InstrStoreA implements Instruction {
	
	private int address;
	
	public InstrStoreA(int address) {
		this.address = address;
	}

	@Override
	public void execute(Registers registers, Memory memory) {
		memory.storeAtLocation(address, registers.getA());
	}
	
	@Override
	public String toString(){
		return "storeA ["+address+"]";
	}
}
