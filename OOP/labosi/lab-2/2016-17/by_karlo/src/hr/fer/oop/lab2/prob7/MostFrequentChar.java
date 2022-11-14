package hr.fer.oop.lab2.prob7;

/**
 * This program checks what is the most frequent character in a string provided
 * from the command line argument.
 * 
 * @author karlo
 *
 */
public class MostFrequentChar {

	private static int charCounter;

	/**
	 * This is the program's main method. It accepts one argument of type
	 * <code>String</code> and prints out the most frequent character containted
	 * in that string.
	 * 
	 * @param args
	 *            provided string
	 */
	public static void main(String[] args) {
		if (args.length != 1) {
			System.err.println("Only 1 argument expected!");
			return;
		}

		System.out.format("%1$s, %2$d", getMostFrequentChar(args[0]), charCounter);
	}

	/**
	 * This method returns the most frequent character from a string and counts
	 * the frequency of that character and saves it in the
	 * <code>charCounter</code> variable.
	 * 
	 * @param word
	 *            the string that has to be checked
	 * @return most frequent character
	 */
	private static char getMostFrequentChar(String word) {
		char mostFrequentChar = ' ';
		int[] characters = new int[Character.MAX_VALUE + 1];

		for (int i = 0; i < word.length(); i++) {
			char ch = word.toLowerCase().charAt(i);
			if (++characters[ch] >= charCounter) {
				charCounter = characters[ch];
				mostFrequentChar = ch;
			}
		}
		return mostFrequentChar;
	}

}
