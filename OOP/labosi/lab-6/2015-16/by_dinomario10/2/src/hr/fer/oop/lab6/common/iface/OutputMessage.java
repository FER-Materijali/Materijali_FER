package hr.fer.oop.lab6.common.iface;

import java.io.InputStream;

/**
 * Interface which describes an {@link OutputMessage} of an system. {@link
 * OutputMessage}} is created by {@link Processor} and received and processed by
 * {@link Consumer}.<br>
 * 
 * Offers a method for getting {@link OutputMessage}'s stream of data, getting
 * the {@link InputMessage} based on which this {@link OutputMessage} was made
 * and resetting both, the {@link InputMessage} and {@link OutputMessage} to the
 * beginning.
 * 
 * @author dinomario10
 */
public interface OutputMessage {

	/**
	 * Returns the output.
	 *
	 * @return the output
	 */
	public InputStream getOutput();

	/**
	 * Returns the input message.
	 *
	 * @return the input message
	 */
	public InputMessage getInputMessage();

	/**
	 * Resets both, the {@link InputMessage} and {@link OutputMessage} to the
	 * beginning.
	 */
	public void reset();

}
