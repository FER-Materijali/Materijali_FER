package hr.fer.oop.lab2.prob3;

import java.text.DecimalFormat;

/**
 * The program accepts three command-line arguments: real part of complex
 * number, imaginary part of complex number, and required root to calculate
 * (integer greater than 1). The program computes and prints all requested roots
 * of given complex number in a formatted form.
 *
 * @author dinomario10
 */
public class Roots {

	/**
	 * This is the program's main method. Three arguments must be passed through
	 * command line.
	 * 
	 * @param args real part, imaginary part and root
	 */
	public static void main(String[] args) {
		if (args.length != 3) {
			System.err.println("Expected 3 arguments.");
			return;
		}

		double realPart = Double.parseDouble(args[0]);
		double imaginaryPart = Double.parseDouble(args[1]);
		int roots = Integer.parseInt(args[2]);
		
		if (roots <= 1) {
			System.err.println("The root must be an integer greater than one. You entered: " + args[2]);
			return;
		}
		
		double[] solutions = calculateRoots(realPart, imaginaryPart, roots);
		printRootSolutions(solutions);
	}

	/**
	 * Returns an array of solutions for the n-th root of a complex number using
	 * the given formula:<br>
	 * <code>r^(1/n) * [cos((phi + 2*k*pi)/n) + i*sin((phi + 2*k*pi)/n)]</code>
	 * <br>
	 * The returned array contains paired real-complex solutions, meaning that
	 * the first argument of the array is the real part of the first solution,
	 * the second argument is the imaginary part of the first solution, the
	 * third argument is the real part of the second solution and so on.
	 * 
	 * @param realPart real part of the complex number
	 * @param imaginaryPart imaginary part of the complex number
	 * @param roots n-th root to be calculated
	 * @return an array containing paired real&complex solutions
	 */
	private static double[] calculateRoots(double realPart, double imaginaryPart, int roots) {
		double radius = Math.sqrt(realPart*realPart + imaginaryPart*imaginaryPart);
		double radiusRoot = Math.pow(radius, 1.0 / roots);
		double angle = Math.atan2(realPart, imaginaryPart);
		
		double[] solutions = new double[2 * roots];
		
		for (int k = 0; k < roots; k++) {
			double realSolution = radiusRoot * Math.cos((angle + 2*k*Math.PI) / roots);
			double imaginarySolution = radiusRoot * Math.sin((angle + 2 * k * Math.PI) / roots);

			solutions[2 * k] = realSolution;
			solutions[2 * k + 1] = imaginarySolution;
		}
		
		return solutions;
	}
	
	/**
	 * Prints out a formatted paired set of solutions passed as an array of
	 * <code>double</code>s, with the maximum of three decimal places. If
	 * solutions are less than 0.0005 then they are recorded as 0.
	 * 
	 * @param solutions array of paired complex solutions
	 */
	private static void printRootSolutions(double[] solutions) {
		DecimalFormat df = new DecimalFormat("#.###");
		final double LIMIT = 5E-4;
		
		for (int i = 0; i < solutions.length; i = i + 2) {
			int ordinalNumber = i / 2 + 1;
			System.out.printf("%d) ", ordinalNumber);
			
			double real = solutions[i];
			double imag = solutions[i + 1];
			
			/* If both numbers are practically zero */
			if (Math.abs(real) <= LIMIT && Math.abs(imag) <= LIMIT) {
				System.out.println("0");
				continue;
			}
			
			/* Real part */
			if (Math.abs(real) >= LIMIT) {
				System.out.print(df.format(real));
				if (imag >= LIMIT) { // if the imaginary part is positive
					System.out.print(" + ");
				} else if (imag <= -LIMIT) { // if it's negative
					System.out.print(" - ");
				}
			}
			/* Imaginary part */
			if (imag >= LIMIT) { // 
				System.out.println(df.format(imag) + "i");
			} else if (imag <= -LIMIT) {
				System.out.println(df.format(Math.abs(imag)) + "i");
			} else {
				System.out.println();
			}
		}
	}

}