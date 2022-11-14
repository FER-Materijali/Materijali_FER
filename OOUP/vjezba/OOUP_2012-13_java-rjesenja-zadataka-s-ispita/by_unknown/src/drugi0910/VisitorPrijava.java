package drugi0910;

public class VisitorPrijava implements Visitor {

	@Override
	public void operation(Guest g) {
		// TODO Auto-generated method stub
		System.out.println("Gost " + g.getName() + " se prijavio");
		g.setPrijava();
	}

}
