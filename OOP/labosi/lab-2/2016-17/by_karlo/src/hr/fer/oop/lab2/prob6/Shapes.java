package hr.fer.oop.lab2.prob6;

/**
 * Program to draw shapes using the standard ASCII characters.
 * 
 * @author karlo
 *
 */
public class Shapes {

	private static final int SIZE = 20;
	private static final int LENGTH = 10;

	/**
	 * Main program that loops through the lines which represent the
	 * <code>SIZE</code> of the shapes, and prints out the generated shape based
	 * on the current line.
	 * 
	 * @param args
	 */
	public static void main(String[] args) {

		for (int i = 0; i < SIZE; i++) {
			if (i == 0 || i == 6 || i == 14 || i == 18) {
				System.out.println(getPrimaryBase());
			} else if (i == 1 || i == 10 || i == 12) {
				System.out.println(getSlope('\\', '/'));
			} else if (i == 2 || i == 11 || i == 13) {
				System.out.println(getSocket('\\', '/', true));
			} else if (i == 3 || i == 7 || i == 15) {
				System.out.println(getSecondaryBase());
			} else if (i == 4 || i == 8 || i == 16) {
				System.out.println(getSocket('/', '\\', false));
			} else if (i == 5 || i == 9 || i == 17) {
				System.out.println(getSlope('/', '\\'));
			}
		}
	}

	/**
	 * This method generates a string using the standard ASCII characters '+'
	 * and '-'.
	 * 
	 * @return returns a shape represented as a string of characters:
	 *         '+--------+'
	 */
	private static String getPrimaryBase() {
		String s = "";
		for (int i = 1; i <= LENGTH; i++) {
			if (i == 1 || i == LENGTH) {
				s += '+';
			} else {
				s += '-';
			}
		}
		return s;
	}

	/**
	 * This method generates a string using the standard ASCII characters ' '
	 * and '_'.
	 * 
	 * @return returns a shape represented as a string of characters: ' ______ '
	 */
	private static String getSecondaryBase() {
		String s = "";
		for (int i = 1; i <= LENGTH; i++) {
			if (i <= 2 || i >= LENGTH - 1) {
				s += ' ';
			} else {
				s += '_';
			}
		}
		return s;
	}

	/**
	 * This method generates a string using the standard ASCII characters
	 * provided a parameters <code>first</code> and <code>second</code>.
	 * 
	 * @param first
	 *            first character '/' or '\'
	 * @param second
	 *            second character '/' or '\'
	 * @return returns a shape represented as a string of characters: '\ /' or
	 *         '/ \' depending on the parameters.
	 */
	private static String getSlope(char first, char second) {
		String s = "";
		for (int i = 1; i <= LENGTH; i++) {
			if (i == 1) {
				s += first;
			} else if (i == LENGTH) {
				s += second;
			} else {
				s += ' ';
			}
		}
		return s;
	}

	/**
	 * This method generates a string using the standard ASCII characters
	 * provided a parameters <code>first</code> and <code>second</code>.
	 * 
	 * @param first
	 *            first character '/' or '\'
	 * @param second
	 *            second character '/' or '\'
	 * @param isUp
	 *            does the socket point up or down
	 * @return returns a shape represented as a string of characters: '\______/'
	 *         or '/ \' depending on the parameters.
	 */
	private static String getSocket(char first, char second, boolean isUp) {
		String s = "";
		for (int i = 1; i <= LENGTH; i++) {
			if (i == 2) {
				s += first;
			} else if (i == LENGTH - 1) {
				s += second;
			} else if (i > 2 && i < LENGTH - 1 && isUp) {
				s += '_';
			} else {
				s += ' ';
			}
		}
		return s;
	}

}
