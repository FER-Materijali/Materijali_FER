package hr.fer.oop.lab4.prob1;

import hr.fer.oop.lab4.pic.Picture;

/**
 * A class that represents a Rectangle object and draws it using lines.
 * 
 * @author karlo
 *
 */
public class RectangleFast extends Rectangle {

	/**
	 * Instantiates a new rectangle fast.
	 *
	 * @param x the x
	 * @param y the y
	 * @param w the w
	 * @param h the h
	 */
	public RectangleFast(int x, int y, int w, int h) {
		super(x, y, w, h);
	}
	
	/**
	 * Instantiates a new rectangle fast.
	 *
	 * @param rect the rect
	 */
	public RectangleFast(Rectangle rect) {
		super(rect);
	}
	
	/* (non-Javadoc)
	 * @see hr.fer.oop.lab4.prob1.GeometricFigure#drawOnPicture(hr.fer.oop.lab4.pic.Picture)
	 */
	@Override
    public void drawOnPicture(Picture img) {
        int x0 = getX();
        int x1 = x0 + getWidth();
        int height = getY() + getHeight();

        for(int y0 = getY(); y0 < height; y0++) {
            img.drawLine(x0, x1, y0);
        }
    }

}
