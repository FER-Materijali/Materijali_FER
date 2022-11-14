package hr.fer.oop.lab4.prob1;

import hr.fer.oop.lab4.pic.*;

/**
 * The demonstration class which draws object on screen.
 * 
 * @author karlo
 *
 */
public class Demonstration {
	
	/** The Constant SCALE. */
	private static final int SCALE = 10;
	
	/**
	 * The main method.
	 *
	 * @param args the arguments
	 */
	public static void main(String[] args) {		
		GeometricFigure[] figures = new GeometricFigure[] {	
			new Rectangle(SCALE * 30, SCALE * 15, SCALE * 20, SCALE * 10),
			new RectangleFast(SCALE * 70, SCALE * 5, SCALE * 15, SCALE * 15),
			new Circle(SCALE * 25, SCALE * 25, SCALE * 5),
			new CircleFast(SCALE * 50, SCALE * 20, SCALE * 6),
			new EquilateralTriangle(SCALE * 25, SCALE * 35, SCALE * 10),
			new EquilateralTriangleFast(SCALE * 55, SCALE * 40, SCALE * 10),
		};
		
		Picture pic = new Picture(SCALE * 100, SCALE * 50);
		for (GeometricFigure figure : figures) {
			figure.drawOnPicture(pic);
		}
		
		pic.renderImageToStream(System.out);
		PictureDisplay.showPicture(pic);
	}
}
