package drugi1011;

public class IspitniProgram {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Error e=new ShortMessageDecorator(new ConcError("Whoops!"));
		e.print();
		Error e1=new LongMessageDecorator(e);
		e1.print();
		Error e2=new RowDecorator(e1);
		e2.print();
		Error e3=new TimeDecorator(e2);
		e3.print();
	}

}
