package drugi1011;

public class TimeDecorator extends Decorator {

	private Error e;

	public TimeDecorator(Error e) {
		// TODO Auto-generated constructor stub
		this.e = e;
	}

	public void print() {
		System.out.println("Wrapped up with time decorator");
		e.print();
	}
}
