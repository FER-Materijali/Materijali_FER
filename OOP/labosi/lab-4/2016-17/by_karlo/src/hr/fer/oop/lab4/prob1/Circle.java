package hr.fer.oop.lab4.prob1;

/**
 * A class that represents a Circle object and draws it by turning pixels on or off
 * 
 * @author karlo
 *
 */
public class Circle extends GeometricFigure {
	
	/** The r. */
	private int r;	
	
	/** The x. */
	private int x;	
	
	/** The y. */
	private int y;
	
	/**
	 * Instantiates a new circle.
	 *
	 * @param x the x
	 * @param y the y
	 * @param r the r
	 */
	public Circle(int x, int y, int r) {
		setR(r);
		setX(x);
		setY(y);
	}
	
	/**
	 * Instantiates a new circle.
	 *
	 * @param c the c
	 */
	public Circle(Circle c) {
		this(c.getX(), c.getY(), c.getR());
	}

	/* (non-Javadoc)
	 * @see hr.fer.oop.lab4.prob1.GeometricFigure#hasPoint(int, int)
	 */
	public boolean hasPoint(int x, int y) {
		int dx = Math.abs(getX() - x);
		int dy = Math.abs(getY() - y);
		return dx * dx + dy * dy <= getR() * getR();
	}
	
	/**
	 * Gets the r.
	 *
	 * @return the r
	 */
	public int getR() {
		return r;
	}

	/**
	 * Sets the r.
	 *
	 * @param r the new r
	 */
	public void setR(int r) {
		this.r = r;
	}

	/**
	 * Gets the x.
	 *
	 * @return the x
	 */
	public int getX() {
		return x;
	}

	/**
	 * Sets the x.
	 *
	 * @param x the new x
	 */
	public void setX(int x) {
		this.x = x;
	}

	/**
	 * Gets the y.
	 *
	 * @return the y
	 */
	public int getY() {
		return y;
	}

	/**
	 * Sets the y.
	 *
	 * @param y the new y
	 */
	public void setY(int y) {
		this.y = y;
	}
}
