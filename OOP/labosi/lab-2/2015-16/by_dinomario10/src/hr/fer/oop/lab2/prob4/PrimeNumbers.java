package hr.fer.oop.lab2.prob4;


/**
 * This program accepts a single command-line argument: an integer n that is
 * greater than 0, and computes and prints first n prime numbers. One is not
 * considered as a prime number, whereas two is.
 *
 * @author dinomario10
 */
public class PrimeNumbers {

	/**
	 * This is the program's main method. Only one argument is expected and
	 * processed.
	 * 
	 * @param args quantity of the first prime numbers to be printed out
	 */
	public static void main(String[] args) {
		if (args.length != 1) {
			System.err.println("Expected one argument. You entered: " + args.length);
			return;
		}
		
		int quantity = Integer.parseInt(args[0]);
		if (quantity <= 0) {
			System.err.println("Please enter a number greater than 0.");
			return;
		}
		
		System.out.printf("You requested calculation of first %d prime numbers. Here they are:%n", quantity);
		int counter = 0;
		int i = 2;
		while (counter < quantity) {
			if (isPrime(i)) {
				counter++;
				System.out.println(counter + ". " + i);
			}
			i++;
		}
	}

	/**
	 * Returns true if passed arguments is a prime number. This method considers
	 * the first prime number to be 2.
	 * 
	 * @param number number that is tested for prime
	 * @return true if number is prime
	 */
	private static boolean isPrime(int number) {
		if (number == 1) {
			return false;
		} 
		
		// lowest value for checking for prime numbers
		int numberSqrt = (int) Math.sqrt((double) number);
		for (int i = 2; i <= numberSqrt; i++) {
			if (number % i == 0) {
				return false;
			}
		}
		return true;
	}

}