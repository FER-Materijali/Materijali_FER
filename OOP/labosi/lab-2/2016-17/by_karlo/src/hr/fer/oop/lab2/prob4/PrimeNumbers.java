package hr.fer.oop.lab2.prob4;

/**
 * This program accepts a single argument and prints out first n prime numbers.
 * 
 * @author karlo
 *
 */
public class PrimeNumbers {

	/**
	 * This is the program's main method. It requires one argument to be passed.
	 * 
	 * @param args
	 *            the amount of the first prime numbers to print out
	 */
	public static void main(String[] args) {

		int n = Integer.parseInt(args[0]);
		System.out.println(String.format("You requested calculation of first %1$d prime numbers. Here they are:", n));

		for (int i = 2, count = 0; count < n; i++) {
			if (isPrime(i)) {
				System.out.println(String.format("%1$d. %2$d", ++count, i));
			}
		}
	}

	/**
	 * Checks if the integer is prime.
	 * 
	 * @param n
	 *            the number that has to be checked
	 * @return returns true if the number is prime, false otherwise
	 */
	private static boolean isPrime(int n) {
		if (n == 1) {
			return false;
		}
		for (int i = 2; i <= Math.sqrt(n); i++) {
			if (n % i == 0) {
				return false;
			}
		}
		return true;
	}

}
