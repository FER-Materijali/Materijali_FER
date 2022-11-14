package hr.fer.oop.lab2.prob3;

/**
 * A struct which represents a complex number.
 * 
 * @author karlo
 *
 */
class Complex {
	public double re;
	public double im;

	public Complex(double re, double im) {
		this.re = re;
		this.im = im;
	}
}

/**
 * The program computes and prints all requested roots of given complex number
 * in a formatted form. It accepts three arguments: real part of complex number,
 * imaginary part of complex number, and the number of roots to calculate.
 * 
 * @author karlo
 *
 */
public class Roots {

	private static double real, imaginary;
	private static int root;
	private static Complex complex;

	/**
	 * This is the program's main method. It accepts three arguments and prints
	 * out a set of solutions formatted as complex numbers.
	 * 
	 * @param args
	 *            real part, imaginary part and the amount of roots that have to
	 *            be calculated
	 */
	public static void main(String[] args) {

		real = Double.parseDouble(args[0]);
		imaginary = Double.parseDouble(args[1]);
		root = Integer.parseInt(args[2]);

		System.out.println(String.format("You requested calculation of %1$d. roots. Solutions are:", root));
		for (int i = 0; i < root; i++) {
			complex = sqrt(real, imaginary, i);
			String imaginaryPrefix = complex.im > 0 ? "+" : "-";
			System.out.println(String.format("%1$d) %2$d " + imaginaryPrefix + " %3$di", i + 1, Math.round(complex.re),
					Math.round(Math.abs(complex.im))));
		}
	}

	/**
	 * Calculates and returns the length of a complex number represented in
	 * Cartesian coordinate system.
	 * 
	 * @param re
	 *            real part
	 * @param im
	 *            imaginary part
	 * @return the length of a complex number in Cartesian coordinate system
	 */
	private static double r(double re, double im) {
		return Math.sqrt(re * re + im * im);
	}

	/**
	 * Calculates and returns the angle of a complex number represented in
	 * Cartesian coordinate system.
	 * 
	 * @param re
	 *            real part
	 * @param im
	 *            imaginary part
	 * @return the angle of a complex number in Cartesian coordinate system
	 */
	private static double theta(double re, double im) {
		return Math.atan2(im, re);
	}

	/**
	 * Calculates and returns the square roots of a given complex number.
	 * 
	 * @param re
	 *            real part
	 * @param im
	 *            imaginary part
	 * @param k
	 *            the amount of roots
	 * @return the square root represented as a <code>Complex</code> number
	 */
	private static Complex sqrt(double re, double im, int k) {
		double length = r(re, im);
		double angle = theta(re, im);

		return new Complex(Math.sqrt(length) * Math.cos((angle + 2 * k * Math.PI) / 2),
				Math.sqrt(length) * Math.sin((angle + 2 * k * Math.PI) / 2));
	}

}
