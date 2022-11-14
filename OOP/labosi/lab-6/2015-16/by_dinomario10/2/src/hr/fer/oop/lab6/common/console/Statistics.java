package hr.fer.oop.lab6.common.console;

import java.io.PrintStream;

import hr.fer.oop.lab6.common.iface.Consumer;
import hr.fer.oop.lab6.common.iface.OutputMessage;

/**
 * Implements the interface {@link Consumer}, so it is a {@link Consumer} which is
 * receiving {@link OutputMessage}s and calculates the speed of generating them
 * and printing the results on the printer periodically.
 * 
 * @author dinomario10
 */
public class Statistics implements Consumer {

	/** Total hashes. */
	private static int totalHashes = 0;
	/** Start time. */
	private static long startTime = System.nanoTime();
	/** Last time seen. */
	private static int lastTimeSeen = 0;
	/** The period. */
	private int period;
	/** A print stream. */
	private PrintStream printStream;
	
	/**
	 * Instantiates a new statistics object.
	 *
	 * @param period the period
	 * @param printStream a print stream
	 */
	public Statistics(int period, PrintStream printStream) {
		this.period = period;
		this.printStream = printStream;
	}

	@Override
	public void evaluate(OutputMessage out) {
		totalHashes++;
		if (totalHashes % period == 0) {
			double speed = (totalHashes - lastTimeSeen) / (double)(System.nanoTime() - startTime) * 1000000000.0;
			startTime = System.nanoTime();
			lastTimeSeen = totalHashes;
			printStream.println("throughput = " + String.format("%.4f", speed) + " hashes/seconds");
			printStream.flush();
		}
	}

}
