package hr.fer.oop.lab2.prob5;

/**
 * This program accepts a single command-line argument: an integer n that is
 * greater than 1, and computes and prints out the factorization of this number
 * onto prime factors.
 *
 * @author dinomario10
 */
public class PrimeFactorization {

	/**
	 * This is the program's main method. Only one argument is expected and
	 * processed.
	 * 
	 * @param args an integer to be decomposed onto prime factors
	 */
	public static void main(String[] args) {
		if (args.length != 1) {
			System.err.println("Expected one argument. You entered: " + args.length);
			return;
		}
		
		int number = Integer.parseInt(args[0]);
		if (number <= 0) {
			System.err.println("Please enter a number greater than 1.");
			return;
		}
		
		System.out.printf("You requested decomposition of number %d onto prime factors. Here they are:%n", number);
		int counter = 0;
		for (int i = 2; i <= number; i++) {
			if (number % i == 0) {
				counter++;
				System.out.println(counter + ". " + i);
				number /= i;
				i = 1;
			}
		}
	}

}
