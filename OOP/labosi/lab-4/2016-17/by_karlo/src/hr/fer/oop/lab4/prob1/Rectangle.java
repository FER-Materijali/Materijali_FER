package hr.fer.oop.lab4.prob1;

/**
 * A class that represents a Rectangle object and draws it by turning pixels on or off
 * 
 * @author karlo
 *
 */
public class Rectangle extends GeometricFigure {

	/** The x. */
	private int x;
	
	/** The y. */
	private int y;
	
	/** The w. */
	private int w;
	
	/** The h. */
	private int h;
	
	/**
	 * Instantiates a new rectangle.
	 *
	 * @param x the x
	 * @param y the y
	 * @param w the w
	 * @param h the h
	 */
	public Rectangle(int x, int y, int w, int h) {
		setX(x);
		setY(y);
		setWidth(w);
		setHeight(h);
	}
	
	/**
	 * Instantiates a new rectangle.
	 *
	 * @param r the r
	 */
	public Rectangle(Rectangle r) {
		this(r.getX(), r.getY(), r.getWidth(), r.getHeight());
	}

	/* (non-Javadoc)
	 * @see hr.fer.oop.lab4.prob1.GeometricFigure#hasPoint(int, int)
	 */
	public boolean hasPoint(int x, int y) {
		if(getX() < x || getY() < y || getX() >= x + getWidth() || getY() >= y + getHeight()) {
			return false;
		}
		return true;
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

	/**
	 * Gets the width.
	 *
	 * @return the width
	 */
	public int getWidth() {
		return w;
	}

	/**
	 * Sets the width.
	 *
	 * @param w the new width
	 */
	public void setWidth(int w) {
		this.w = w;
	}

	/**
	 * Gets the height.
	 *
	 * @return the height
	 */
	public int getHeight() {
		return h;
	}

	/**
	 * Sets the height.
	 *
	 * @param h the new height
	 */
	public void setHeight(int h) {
		this.h = h;
	}
}
