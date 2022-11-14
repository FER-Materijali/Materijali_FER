package hr.fer.oop.lab2.prob6;

/**
 * Prints out some pretty weird shapes.
 * 
 * @author dinomario10
 */
public class Shapes {
	
	public static void main(String[] args) {
		hourglass();
		geometricFigure();
		System.out.println();
		cup();
		cap();
	}
	
	private static void hourglass() {
		topOrBottom();
		bottomCup();
		topCup();
		topOrBottom();
	}
	
	private static void geometricFigure() {
		topCup();
		bottomCup();
	}
	
	private static void cup() {
		bottomCup();
		topOrBottom();
	}
	
	private static void cap() {
		topCup();
		topOrBottom();
	}
	
	private static void topOrBottom() {
		System.out.println("+--------+");
	}
	
	private static void bottomCup() {
		System.out.println("\\        /");
		System.out.println(" \\______/");
	}
	
	private static void topCup() {
		System.out.println("  ______");
		System.out.println(" /      \\");
		System.out.println("/        \\");
	}
}
