package hr.fer.oop.lab4.prob1;

/**
 * A miscellaneous class. Used for defining miscellaneous helper methods.
 * 
 * @author dinomario10
 */
public class Misc {
	
	/** Minimum value of all ranged variables */
	public static final int MIN_RANGE = 0;
	/** Maximum value of all ranged variables */
	public static final int MAX_RANGE = 100;
	
	/**
	 * Returns true if the value is within the range [0, 100].
	 * 
	 * @param value a value
	 * @return true if the value is within the range [0, 100]
	 */
	public static boolean isInRange(int value) {
		return value >= MIN_RANGE && value <= MAX_RANGE;
	}
}
