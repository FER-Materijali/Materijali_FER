package hr.fer.oop.lab4.prob1;

import hr.fer.oop.lab4.pic.Picture;

/**
 * Abstract class that defines a geometrical figure
 * 
 * @author karlo
 *
 */
public abstract class GeometricFigure {

	/**
	 * Method that checks if the given point is located in the geometircal figure
	 * 
	 * @param x X coordinate
	 * @param y Y coordinate
	 * @return true if the point is inside the figure, false otherwise
	 */
	public abstract boolean hasPoint(int x, int y);
	
	/**
	 * Method that draws a picture on the screen
	 * 
	 * @param pic Picture
	 */
	public void drawOnPicture(Picture pic) {
		for (int y = 0, h = pic.getHeight(); y < h; y++) {
			for (int x = 0, w = pic.getWidth(); x < w; x++) {
				if (hasPoint(x, y)) {
					pic.turnPixelOn(x, y);
				}
			}
		}
	}
}
