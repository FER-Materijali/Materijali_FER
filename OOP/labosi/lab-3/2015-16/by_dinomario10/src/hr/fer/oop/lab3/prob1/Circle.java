package hr.fer.oop.lab3.prob1;

/**
 * The class Circle extends {@linkplain GeometricFigure} as it is a geometric
 * figure that represents a circle. A circle is specified by the <tt>x</tt> and
 * <tt>y</tt> coordinates of its center and its <tt>radius</tt>.
 * 
 * @author dinomario10
 */
public class Circle extends GeometricFigure {
	
	private int r;
	private int cx;
	private int cy;

	/**
	 * Constructs a new circle object with given radius,
	 * center x coordinate and center y coordinate.
	 * 
	 * @param r radius of the circle
	 * @param cx x coordinate of the circle
	 * @param cy y coordinate of the circle
	 */
	public Circle(int r, int cx, int cy) {
		this.r = r;
		this.cx = cx;
		this.cy = cy;
	}
	
	/**
	 * Constructs a new circle equal to the argument circle.
	 * 
	 * @param c a circle
	 */
	public Circle(Circle c) {
		this(c.r, c.cx, c.cy);
	}
	
	@Override
	public boolean hasPoint(int x, int y) {
		int dx = Math.abs(cx - x);
		int dy = Math.abs(cy - y);
		return dx*dx + dy*dy <= r*r;
//		int dist = (int) Math.sqrt(dx*dx + dy*dy);
//		if (dist > r) return false;
//		return true;
	}

}
