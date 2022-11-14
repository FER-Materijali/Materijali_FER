package hr.fer.oop.lab4.prob1;

import hr.fer.oop.lab4.pic.Picture;

/**
 * A class that represents a Circle object and draws it using lines.
 * 
 * @author karlo
 *
 */
public class CircleFast extends Circle {

	/**
	 * Instantiates a new circle fast.
	 *
	 * @param x the x
	 * @param y the y
	 * @param r the r
	 */
	public CircleFast(int x, int y, int r) {
		super(x, y, r);
	}
	
	/**
	 * Instantiates a new circle fast.
	 *
	 * @param c the c
	 */
	public CircleFast(Circle c) {
		super(c);
	}

	/* (non-Javadoc)
	 * @see hr.fer.oop.lab4.prob1.GeometricFigure#drawOnPicture(hr.fer.oop.lab4.pic.Picture)
	 */
	@Override
    public void drawOnPicture(Picture img) {
		double step = 2 * Math.PI / 500;
	    int r = getR();

	    for(double theta = 0; theta < 2 * Math.PI; theta += step) { 
	    	int x = (int) (getX() + r * Math.cos(theta));
	    	int y = (int) (getY() - r * Math.sin(theta));
	    	img.drawLine(x, getX(), y);
	     }
    }
}
