package drugi1011;

public class LongMessageDecorator extends Decorator {

	private Error e;
	
	public LongMessageDecorator(Error e) {
		// TODO Auto-generated constructor stub
		this.e=e;
	}
	
	public void print(){
		System.out.println("Wrapped up with long message");
		e.print();
	}
	
}
