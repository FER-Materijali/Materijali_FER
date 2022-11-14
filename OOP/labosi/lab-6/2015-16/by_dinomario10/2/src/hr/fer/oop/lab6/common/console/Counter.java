package hr.fer.oop.lab6.common.console;

import java.io.PrintStream;

import hr.fer.oop.lab6.common.iface.Consumer;
import hr.fer.oop.lab6.common.iface.OutputMessage;

/**
 * Implements the interface {@link Consumer}, so it is a {@link Consumer} who is
 * counting the number of {@link OutputMessage}s and is printing that number on
 * the {@link PrintStream} periodically.
 * 
 * @author dinomario10
 */
public class Counter implements Consumer {
	
	/** The hashes seen. */
	private static int hashesSeen = 0;
	/** The period. */
	private int period;
	/** The print stream. */
	private PrintStream printStream;
	
	/**
	 * Instantiates a new counter.
	 *
	 * @param period the period
	 * @param printStream the print stream
	 */
	public Counter(int period, PrintStream printStream) {
		this.period = period;
		this.printStream = printStream;
	}
	
	@Override
	public synchronized void evaluate(OutputMessage out) {
		hashesSeen++;
		if (hashesSeen % period == 0) {
			printStream.println("Counter: " + hashesSeen);
		}
	}

}
