package hr.fer.oop.primjeri.p005;

public class Processor {
	
	private Memory memory;
	private Registers registers;
	
	public Processor(){
		this.memory = new Memory() {
			
			Object[] memoryArray = new Object[1024];
			
			@Override
			public Object getFromLocation(int address) {
				return memoryArray[address];
			}

			@Override
			public void storeAtLocation(int address, Object object) {
				memoryArray[address] = object;
			}
			
		};
		registers = new Registers();
	}
	
	public void run(){
		while(!registers.isHalt()){
			Instruction instrukcija = (Instruction) memory.getFromLocation(registers.getProgramCounter());
			registers.setProgramCounter(registers.getProgramCounter() + 1);
			instrukcija.execute(registers, memory);
		}
	}
	
	public Memory getMemory(){
		return memory;
	}
	
	public Registers gerRegisters(){
		return registers;
	}
}