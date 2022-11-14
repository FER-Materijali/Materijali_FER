package drugi0910;

public class VisitorUsluga implements Visitor {

	@Override
	public void operation(Guest g) {
		// TODO Auto-generated method stub
		System.out.println("Gost " + g.getName() + " je posluzen");
		g.setUsluga();
	}

}
