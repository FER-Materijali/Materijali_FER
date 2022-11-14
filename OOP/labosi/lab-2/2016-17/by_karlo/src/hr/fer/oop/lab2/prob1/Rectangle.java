package hr.fer.oop.lab2.prob1;

import java.util.Locale;
import java.util.Scanner;

/**
 * This program calculates rectangle's area and perimeter. The rectangle
 * parameters can be obtained either through command line as program arguments
 * or through keyboard while the program is running. If there is any number of
 * arguments from the command line, and if it's not two, an error message is
 * printed and the program stops running, else the program reads from keyboard
 * until the user inputs a non-negative width and height value.
 * 
 * @author karlo
 *
 */
public class Rectangle {

	private static double width, height, area, perimeter;

	/**
	 * This is the program's main method. It accepts two arguments, width and
	 * height of a rectangle, and prints out the area and perimeter of that
	 * rectangle.
	 * 
	 * @param args
	 *            command line arguments
	 */
	public static void main(String[] args) {

		if (args.length != 0) {
			if (args.length != 2) {
				System.err.println("Invalid number of arguments was provided.");
				return;
			}

			width = Double.parseDouble(args[0]);
			height = Double.parseDouble(args[1]);
		} else {
			Scanner sc = new Scanner(System.in);

			while (width == 0f) {
				System.out.println("Please provide width: ");
				width = getInputValue("width", sc.nextLine().trim());
			}
			while (height == 0f) {
				System.out.println("Please provide height: ");
				height = getInputValue("height", sc.nextLine().trim());
			}
		}

		area = calculateArea(width, height);
		perimeter = calculatePerimeter(width, height);

		System.out.format(Locale.ROOT,
				"You have specified a rectangle of width %1$.1f and height %2$.1f. Its area is %3$.1f and its perimeter is %4$.1f.",
				width, height, area, perimeter);
	}

	/**
	 * Gets the input value from the main program and checks if the input is
	 * valid. If it's not it returns 0, else it returns the user's input
	 * represented as <code>double</code>.
	 * 
	 * @param param
	 *            either width or height, used to print out the error message
	 * @param input
	 *            user's input from the main program
	 * @return the user's input represented as <code>double</code>
	 */
	private static double getInputValue(String param, String input) {

		if (input.isEmpty()) {
			System.out.println("The input must not be blank.");
			return 0;
		}

		double value = Double.parseDouble(input);

		if (value < 0) {
			System.err.println("The " + param + " must not be negative.");
			return 0;
		}

		return value;
	}

	/**
	 * Calculates and returns the rectangle's area based on the given parameters
	 * <code>width</code> and <code>height</code>.
	 * 
	 * @param width
	 *            width of a rectangle
	 * @param height
	 *            height of a rectangle
	 * @return the area of a rectangle
	 */
	private static double calculateArea(double width, double height) {
		return width * height;
	}

	/**
	 * Calculates and returns the rectangle's perimeter based on the given
	 * parameters <code>width</code> and <code>height</code>.
	 * 
	 * @param width
	 *            width of a rectangle
	 * @param height
	 *            height of a rectangle
	 * @return the perimeter of a rectangle
	 */
	private static double calculatePerimeter(double width, double height) {
		return 2 * (width + height);
	}

}
