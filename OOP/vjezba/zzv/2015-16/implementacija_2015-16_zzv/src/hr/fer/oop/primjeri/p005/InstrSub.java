package hr.fer.oop.primjeri.p005;

public class InstrSub implements Instruction {

	int ammount;
	
	public InstrSub(int ammount){
		this.ammount = ammount;
	}
	
	@Override
	public void execute(Registers registers, Memory memory) {
		registers.setA((Integer)registers.getA()-1);
	}

	@Override
	public String toString(){
		return "sub "+ammount;
	}
}
