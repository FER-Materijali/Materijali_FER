package hr.fer.oop.lab6.common.console;

import java.io.PrintStream;
import java.util.Arrays;

import hr.fer.oop.lab6.common.iface.Consumer;
import hr.fer.oop.lab6.common.iface.OutputMessage;

/**
 * Implements the interface {@link Consumer}, so it is a {@link Consumer} which
 * receives an {@link OutputMessage} and checks its data if its lowest data
 * matches the pattern, and if so, writes the {@link OutputMessage} and {@link
 * InputMessage} to the {@link PrintStream}.
 * 
 * @author dinomario10
 */
public class SuffixCheck implements Consumer {
	
	/** The pattern. */
	private byte[] pattern;
	
	/** The print stream. */
	private PrintStream printStream;

	/**
	 * Instantiates a new suffix check.
	 *
	 * @param pattern the pattern
	 * @param printStream the print stream
	 */
	public SuffixCheck(byte[] pattern, PrintStream printStream) {
		this.pattern = pattern;
		this.printStream = printStream;
	}

	@Override
	public void evaluate(OutputMessage out) {
		byte[] outputBytes = Helper.inputStreamToBytes(out.getOutput());
		
		int lastNBytes = outputBytes.length - pattern.length;
		
		byte[] lastNBytesOutput = Arrays.copyOfRange(outputBytes, lastNBytes, outputBytes.length);
		
		if (Arrays.equals(lastNBytesOutput, pattern)) {
			byte[] inputBytes = Helper.inputStreamToBytes(out.getInputMessage().getStream());
			printStream.println(Helper.bytesToHexString(inputBytes) + "=>" + Helper.bytesToHexString(outputBytes));
		}
	}

}
