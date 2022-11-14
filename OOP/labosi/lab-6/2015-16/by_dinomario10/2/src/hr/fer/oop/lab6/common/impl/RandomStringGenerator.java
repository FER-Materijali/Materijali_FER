package hr.fer.oop.lab6.common.impl;

import hr.fer.oop.lab6.common.iface.Generator;
import hr.fer.oop.lab6.common.iface.InputMessage;

/**
 * Implements an interface {@link Generator}, so it is a {@link Generator} which
 * is generating an {@link InputMessage InputMessages} based on the randomly
 * chosen letters from English alphabet as an array of {@link Byte Bytes}.
 * 
 * @author dinomario10
 */
public class RandomStringGenerator implements Generator {
	
	/** The minimum length of the string */
	private final int MIN_LENGTH;
	/** The maximum length of the string */
	private final int MAX_LENGTH;
	
	/**
	 * Instantiates a new random string generator.
	 */
	public RandomStringGenerator() {
		this(10, 20);
	}
	
	/**
	 * Instantiates a new random string generator.
	 *
	 * @param min the min
	 * @param max the max
	 */
	public RandomStringGenerator(int min, int max) {
		super();
		MIN_LENGTH = min;
		MAX_LENGTH = max;
	}

	@Override
	public InputMessage generateMessage() {
		int len = (int) (Math.random() * (MAX_LENGTH - MIN_LENGTH) + MIN_LENGTH);
		StringBuilder sb = new StringBuilder(len);
		
		for (int i = 0; i < len; i++) {
			int caseChooser = (int) (Math.random() * 10);
			if (caseChooser < 5)
				sb.append((char) (Math.random() * ('z' - 'a') + 'a'));
			else
				sb.append((char) (Math.random() * ('Z' - 'A') + 'A'));
		}

		return new InputMessageImpl(sb.toString());
	}

}
