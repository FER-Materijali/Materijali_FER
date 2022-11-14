package hr.fer.oop.lab4.prob1;

import hr.fer.oop.lab4.pic.Picture;

/**
 * A class that represents an Equilateral Triangle object and draws it using lines.
 * 
 * @author karlo
 *
 */
public class EquilateralTriangleFast extends EquilateralTriangle {

	/**
	 * Instantiates a new equilateral triangle fast.
	 *
	 * @param x the x
	 * @param y the y
	 * @param height the height
	 */
	public EquilateralTriangleFast(int x, int y, int height) {
		super(x, y, height);
	}
	
	/**
	 * Instantiates a new equilateral triangle fast.
	 *
	 * @param t the t
	 */
	public EquilateralTriangleFast(EquilateralTriangle t) {
		super(t);
	}

	/* (non-Javadoc)
	 * @see hr.fer.oop.lab4.prob1.GeometricFigure#drawOnPicture(hr.fer.oop.lab4.pic.Picture)
	 */
	@Override
    public void drawOnPicture(Picture img) {
        int x1 = getX();
        int x2 = x1 + getSide();
        int height = getY() - getHeight();

        for(int y0 = getY(); y0 >= height && x2 >= x1; y0--, x2--, x1++) {
            img.drawLine(x1, x2, y0);
        }
    }

}
