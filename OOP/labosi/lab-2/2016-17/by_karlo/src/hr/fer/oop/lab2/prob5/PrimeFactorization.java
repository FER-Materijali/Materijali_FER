package hr.fer.oop.lab2.prob5;

/**
 * This program accepts a single argument and prints out the factorization of
 * this number using the prime numbers.
 * 
 * @author karlo
 *
 */
public class PrimeFactorization {

	/**
	 * This is the program's main method. It requires one argument to be passed.
	 * 
	 * @param args
	 *            the amount of the first prime numbers to print out
	 */
	public static void main(String[] args) {

		int n = Integer.parseInt(args[0]);
		System.out.println(
				String.format("You requested decomposition of number %1$d into prime factors. Here they are:", n));

		for (int i = 2, count = 0; n > 1; i++) {
			if (n % i == 0) {
				while (n % i == 0) {
					n /= i;
					System.out.println(String.format("%1$d. %2$d", ++count, i));
				}
			}
		}

	}
}
