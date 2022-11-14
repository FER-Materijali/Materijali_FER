package drugi1011;

public class ShortMessageDecorator extends Decorator{
	
	private Error e;
	
	public ShortMessageDecorator(Error e) {
		// TODO Auto-generated constructor stub
		this.e=e;
	}
	
	public void print(){
		System.out.println("Wrapped up with short message");
		e.print();
	}
	
}
