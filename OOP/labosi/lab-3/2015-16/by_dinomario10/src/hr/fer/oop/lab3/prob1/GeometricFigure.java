package hr.fer.oop.lab3.prob1;
import hr.fer.oop.lab3.pic.*;

/**
 * The abstract superclass from which all geometric figures should be derived.
 * The default methods for geometric figures are for drawing the shape itself and
 * for checking if the shape contains a specific point. The implementation of
 * the {@linkplain #draw(BWRaster)} is the assumed drawing method for all
 * geometric figures and it is advised that a subclass overrides this method.
 * This extending classes should provide the
 * {@linkplain #containsPoint(int, int)} implementation, as the abstract
 * geometric figure itself is unable to determine if it contains a point.
 *
 * @author dinomario10
 * @see Rectangle
 * @see Circle
 * @see EquilateralTriangle
 */
public abstract class GeometricFigure {
	
	/**
	 * Checks if specified (x, y) point belongs to this geometric figure and
	 * returns a <tt>boolean</tt> value of the result. The general contract for
	 * this method is that it must return false only if the location is outside
	 * of the geometric figure. Otherwise it must return true.
	 * 
	 * @param x the x coordinate of the point
	 * @param y the y coordinate of the point
	 * @return true if the specified point belongs to the geometric figure 
	 */
	public abstract boolean hasPoint(int x, int y);
	
	/**
	 * This method draws a filled image of the geometric figure (not only its
	 * outline). The default method is the assumed drawing method for all
	 * geometric figure that checks the whole picture of points. It is
	 * recommended that all subclasses override this method.
	 * 
	 * @param pic a picture
	 */
	public void drawOnPicture(Picture pic) {
		for (int y = 0, h = pic.getHeight(); y < h; y++) {
			for (int x = 0, w = pic.getWidth(); x < w; x++) {
				if (this.hasPoint(x, y)) {
					pic.turnPixelOn(x, y);
				}
			}
		}
	}

}
