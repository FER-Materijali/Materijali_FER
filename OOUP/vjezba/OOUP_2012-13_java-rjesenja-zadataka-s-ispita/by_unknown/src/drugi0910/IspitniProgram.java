package drugi0910;

public class IspitniProgram {

	public static void main(String[] args) {
		Agencija a=new AgencijaA("GlobalTours");
		Guest g=new GuestA(a, "Marko");
		Visitor v1=new VisitorPrijava();
		Visitor v2=new VisitorUsluga();
		Visitor v3=new VisitorRacun();
		
		g.accept(v1);
		g.accept(v2);
		g.accept(v3);
		
		System.out.println(g.isPrijava());
		System.out.println(g.isUsluga());
		System.out.println(g.isRacun());
	}
}
