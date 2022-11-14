package hr.fer.oop.primjeri.p011;

public final class MathematicalConstant {
	// public constants:
	// -----------------
	/**
	 * Constant PI (the ratio of circle's circumference to its diameter).
	 */
	public static final MathematicalConstant PI = new MathematicalConstant(3.14159265358979323846);
	/**
	 * Constant E (base of natural logarithm).
	 */
	public static final MathematicalConstant E = new MathematicalConstant(2.7182818284590452354);
	/**
	 * First natural number. Neutral element for addition.
	 */
	public static final MathematicalConstant ZERO = new MathematicalConstant(0.0);
	/**
	 * Second natural number. Neutral element for multiplication.
	 */
	public static final MathematicalConstant ONE = new MathematicalConstant(1.0);
	// private final member variables:
	// -------------------------------
	/**
	 * The value of this constant.
	 */
	private final double value;

	/**
	 * Constructor.
	 * 
	 * @param value
	 *            constant's value
	 */
	private MathematicalConstant(double value) {
		super();
		this.value = value;
	}

	/**
	 * Getter for value.
	 *
	 * @return value of this constant
	 */
	public double getValue() {
		return value;
	}
}
