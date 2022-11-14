package drugi0910;

public class VisitorRacun implements Visitor {

	@Override
	public void operation(Guest g) {
		// TODO Auto-generated method stub
		System.out.println("Gost " + g.getName() + " je dobio racun");
		g.setRacun();
	}

}
