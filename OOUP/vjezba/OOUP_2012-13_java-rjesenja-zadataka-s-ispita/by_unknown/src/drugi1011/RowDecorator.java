package drugi1011;

public class RowDecorator extends Decorator {

	private Error e;

	public RowDecorator(Error e) {
		// TODO Auto-generated constructor stub
		this.e = e;
	}

	public void print() {
		System.out.println("Wrapped up with row finder decorator");
		e.print();
	}

}
