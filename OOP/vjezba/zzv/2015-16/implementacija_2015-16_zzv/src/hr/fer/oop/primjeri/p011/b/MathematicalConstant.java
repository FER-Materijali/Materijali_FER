package hr.fer.oop.primjeri.p011.b;

public enum MathematicalConstant {
	// public constants:
	// -----------------
	/**
	 * Constant PI (the ratio of circle's circumference to its diameter).
	 */
	PI(3.14159265358979323846),
	/**
	 * Constant E (base of natural logarithm).
	 */
	E(2.7182818284590452354),
	/**
	 * First natural number. Neutral element for addition.
	 */
	ZERO(0.0),
	/**
	 * Second natural number. Neutral element for multiplication.
	 */
	ONE(1.0);
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
