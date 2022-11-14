package hr.fer.oop.lab6.common.console;

import hr.fer.oop.lab6.common.iface.*;
import hr.fer.oop.lab6.common.impl.*;

/**
 * Demonstrates the use of {@link RandomStringGenerator}, {@link MD5Digester},
 * and {@link SuffixCheck}.
 * 
 * @author dinomario10
 */
public class Demonstration {

	/**
	 * The main method.
	 *
	 * @param args the arguments
	 */
	public static void main(String[] args) {
		Generator g = new RandomStringGenerator();
		Processor p = new MD5Digester();
		Consumer c = new SuffixCheck(new byte[] { (byte) 0xFE, (byte) 0xFF }, System.out);
		while (true) {
			InputMessage msg1 = g.generateMessage();
			OutputMessage msg2 = p.process(msg1);
			c.evaluate(msg2);
		}
	}

}
