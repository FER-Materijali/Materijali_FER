package hr.fer.oop.lab3.prob1;
import hr.fer.oop.lab3.pic.*;

/**
 * Demonstration program.
 * 
 * @author dinomario10
 */
public class Demonstration {

	public static void main(String[] args) {
		
		final int M = 1;
		
		GeometricFigure[] figures = new GeometricFigure[] {
			new EquilateralTriangle(M*80, M*10, M*8),
			new EquilateralTriangle(M*25, M*5, M*12),
			new Circle(M*5, M*25, M*30),
			new Circle(M*10, M*5, M*5),
			new Rectangle(M*75, M*10, M*5, M*5),
			new Rectangle(M*80, M*45, M*10, M*15)
		};
		
		Picture pic = new Picture(M*100, M*50);
		for (GeometricFigure figure : figures) {
			figure.drawOnPicture(pic);
		}
		pic.renderImageToStream(System.out);
		PictureDisplay.showPicture(pic);
	}

}
