package hr.fer.oop.lab3.prob1;

/**
 * The class Rectangle extends {@linkplain GeometricFigure} as it is a geometric
 * figure that represents a rectangle. A rectangle is specified by the
 * <tt>x</tt> and <tt>y</tt> coordinates of its uppermost leftmost corner and
 * its <tt>width</tt> and <tt>height</tt>.
 * 
 * @author dinomario10
 */
public class Rectangle extends GeometricFigure {

	private int x;
	private int y;
	private int w;
	private int h;
	
	/**
	 * Constructs a new rectangle with given x and y coordinates
	 * of the upper left corner and given width and height.
	 * 
	 * @param x x coordinate of the upper left corner
	 * @param y y coordinate of the upper left corner
	 * @param w width of a rectangle
	 * @param h height of a rectangle
	 */
	public Rectangle(int x, int y, int w, int h) {
		this.x = x;
		this.y = y;
		this.w = w;
		this.h = h;
	}
	
	/**
	 * Constructs a new rectangle equal to the argument rectangle.
	 * 
	 * @param r a rectangle
	 */
	public Rectangle(Rectangle r) {
		this(r.x, r.y, r.w, r.h);
	}
	
	@Override
	public boolean hasPoint(int x, int y) {
		if(this.x < x) return false;
		if(this.y < y) return false;
		if(this.x >= x+w) return false;
		if(this.y >= y+h) return false;
		return true;
	}

}
