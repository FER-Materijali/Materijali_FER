package hr.fer.oop.lab3.prob1;

/**
 * The class EquilateralTriangle extends {@linkplain GeometricFigure} as it is a
 * geometric figure that represents an equilateral triangle.
 * 
 * @author dinomario10
 */
public class EquilateralTriangle extends GeometricFigure {

	private int x;
	private int y;
	private int side;
	
	/**
	 * Constructs a new equilateral triangle with given
	 * top point x and y coordinates and length of base.
	 * 
	 * @param x x coordinate of the top point
	 * @param y y coordinate of the top point
	 * @param length of equilateral triangle sides
	 */
	public EquilateralTriangle(int x, int y, int side) {
		this.x = x;
		this.y = y;
		this.side = side;
	}
	
	/**
	 * Constructs a new equilateral triangle
	 * equal to the argument triangle.
	 * @param t an equilateral triangle
	 */
	public EquilateralTriangle(EquilateralTriangle t) {
		this(t.x, t.y, t.side);
	}
	
	@Override
	public boolean hasPoint(int x, int y) {
		int height = (int) (side / 2 * Math.sqrt(3));
		if (y < this.y) return false;
		if (y > this.y + height) return false;
		int space = (int) (Math.tan(Math.PI/6) * (y - this.y));
		if (x < this.x - space) return false;
		if (x > this.x + space) return false;
		return true;
	}

}
