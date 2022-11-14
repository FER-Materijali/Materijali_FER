package zadatak2;

public class ShapeLineSegment implements Shape {

	String id;
	Point pocetnaTocka;
	Point zavrsnaTocka;
	static Integer brojac=0;
	
	public ShapeLineSegment(String id) {
		super();
		this.id = id;
	}

	
	public ShapeLineSegment(Point pocetnaTocka, Point zavrsnaTocka) {
		super();
		
		this.id = brojac.toString();
		brojac++;
		this.pocetnaTocka = pocetnaTocka;
		this.zavrsnaTocka = zavrsnaTocka;
	}
	

	@Override
	public String id() {
		return id;
	}

	@Override
	public void translate(Point tocka) {

		System.out.println("Pomičem liniju na poziciju " + tocka.toString());

		zavrsnaTocka.x = zavrsnaTocka.x + tocka.x - pocetnaTocka.x;
		zavrsnaTocka.y = zavrsnaTocka.y + tocka.y - pocetnaTocka.y;
		pocetnaTocka.x = tocka.x;
		pocetnaTocka.y = tocka.y;
	}
	
	public String toString(){
		return "Ja sam linija sa Idom: " + id + " i nalazim se na poziciji " + pocetnaTocka.x +","+pocetnaTocka.y;
	}

}
