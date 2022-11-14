package zadatak1;

public class Glavni {


	public static void main(String[] args) {
		
		Drawing crtez = new DrawingVector();
		
		Shape linija = new ShapeLineSegment(new Point(0, 0), new Point(5, 5));
		crtez.addShape(linija);
		crtez.getShape(0).translate(new Point(7.0,7.0));
		crtez.removeShape(linija.id());
		
	}

}
