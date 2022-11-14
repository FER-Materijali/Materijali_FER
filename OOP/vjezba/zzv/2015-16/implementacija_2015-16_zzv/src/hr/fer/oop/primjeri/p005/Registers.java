package hr.fer.oop.primjeri.p005;

public class Registers {
	private Object a;
	private int programCounter;
	private boolean halt;
	private boolean test;

	public Registers(){
		super();
	}
	
	public int getProgramCounter() {
		return programCounter;
	}

	public void setProgramCounter(int programCounter) {
		this.programCounter = programCounter;
	}

	public Object getA() {
		return a;
	}

	public void setA(Object a) {
		this.a = a;
	}

	public boolean isHalt() {
		return halt;
	}

	public void setHalt(boolean halt) {
		this.halt = halt;
	}

	public boolean isTest() {
		return test;
	}

	public void setTest(boolean test) {
		this.test = test;
	}
}
