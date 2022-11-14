package hr.fer.oop.lab2.prob1;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 * This program calculates the area and perimeter of a rectangle. The rectangle
 * parameters can be obtained either through command line as program arguments
 * or through keyboard while the program is running. If there is any number of
 * arguments from the command line, and if it is not two, an error message is
 * printed out and the program stops. Else the program reads from keyboard until
 * the user inputs a non-negative width and height value.
 *
 * @author dinomario10
 */
public class Rectangle {
	
	/**
	 * This is the program's main method. It accepts two arguments, width and
	 * height of a rectangle, and prints out the area and perimeter of that
	 * rectangle.
	 * 
	 * @param args command line arguments, possibly containing width and height
	 * @throws IOException if an I/O error occurs
	 */
	public static void main(String[] args) throws IOException {
		double width;
		double height;
		
		if (args.length != 0) {
			if (args.length != 2) {
				System.err.println("Invalid number of arguments was provided.");
				return;
			}
			width = Double.parseDouble(args[0]);
			height = Double.parseDouble(args[1]);
		} else {
			BufferedReader reader = new BufferedReader(
					new InputStreamReader(System.in)
			);
			
			width = getInput("Width", reader);
			height = getInput("Height", reader);
			
			reader.close();
		}

		double area = calculateArea(width, height);
		double perimeter = calculatePerimeter(width, height);
		
		System.out.format(
				"You have specified a rectangle with width %.1f and height %.1f. "
				+ "Its area is %.1f and its perimeter is %.1f.%n",
				width, height, area, perimeter
		);
	}

	/**
	 * Reads the user's input expecting a double value. This method will block
	 * until the user inputs a correct non-negative double number or if an I/O
	 * error occurs. Returns the user's input represented as <code>double</code>.
	 * 
	 * @param dimension dimension for prompting the user
	 * @param reader a buffered reader
	 * @return the user's input represented as <code>double</code>
	 * @throws IOException if an I/O error occurs
	 */
	private static double getInput(String dimension, BufferedReader reader) throws IOException {
		double input;
		
		while (true) {
			System.out.printf("Please provide %s: ", dimension.toLowerCase());
			
			/* readLine() cannot return null in this example */
			String line = reader.readLine().trim();
			if (line.isEmpty()) {
				System.err.println("Nothing was given.");
				continue;
			}
			
			input = Double.parseDouble(line);
			if (input < 0) {
				System.err.printf("%s is negative.%n", dimension);
				continue;
			} else {
				break;
			}
		}
		
		return input;
	}
	
	/**
	 * Calculates and returns the rectangle's area based on the given parameters
	 * <code>width</code> and <code>height</code>.
	 * 
	 * @param width width of a rectangle
	 * @param height height of a rectangle
	 * @return the area of a rectangle
	 */
	private static double calculateArea(double width, double height) {
		return width*height;
	}
	
	/**
	 * Calculates and returns the rectangle's perimeter based on the given
	 * parameters <code>width</code> and <code>height</code>.
	 * 
	 * @param width width of a rectangle
	 * @param height height of a rectangle
	 * @return the perimeter of a rectangle
	 */
	private static double calculatePerimeter(double width, double height) {
		return 2*(width+height);
	}

}