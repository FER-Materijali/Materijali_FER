package hr.fer.oop.lab4.prob1;

/**
 * A class that represents an Equilateral Triangle object and draws it by turning pixels on or off
 * 
 * @author karlo
 *
 */
public class EquilateralTriangle extends GeometricFigure {
	
	/** The x. */
	private int x;
	
	/** The y. */
	private int y;
	
	/** The height. */
	private int height;
	
	/** The side. */
	private int side;
	
	/**
	 * Instantiates a new equilateral triangle.
	 *
	 * @param x the x
	 * @param y the y
	 * @param height the height
	 */
	public EquilateralTriangle(int x, int y, int height) {
		setX(x);
		setY(y);
		setHeight(height);
		setSide((int) (height * 2 / Math.sqrt(3)));
	}
	
	/**
	 * Instantiates a new equilateral triangle.
	 *
	 * @param t the t
	 */
	public EquilateralTriangle(EquilateralTriangle t) {
		this(t.getX(), t.getY(), t.getHeight());
	}

	/* (non-Javadoc)
	 * @see hr.fer.oop.lab4.prob1.GeometricFigure#hasPoint(int, int)
	 */
	public boolean hasPoint(int x, int y) {
		if (y < getY() || y > getY() + getHeight()) {
			return false;
		}
		int space = (int) (Math.tan(Math.PI / 6) * (y - getY()));
		if (x < getX() - space || x > getX() + space) {
			return false;
		}
		return true;
	}
	
	/**
	 * Gets the height.
	 *
	 * @return the height
	 */
	public int getHeight() {
		return height;
	}

	/**
	 * Sets the height.
	 *
	 * @param height the new height
	 */
	public void setHeight(int height) {
		this.height = height;
	}
	
	/**
	 * Gets the side.
	 *
	 * @return the side
	 */
	public int getSide() {
		return side;
	}
	
	/**
	 * Sets the side.
	 *
	 * @param side the new side
	 */
	public void setSide(int side) {
		this.side = side;
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
