package hr.fer.oop.lab6.common.iface;

import java.io.InputStream;

/**
 * Interface which describes an {@link InputMessage} of an system. {@link
 * InputMessage} is created by {@link Generator} and received and processed by
 * {@link Processor} to an {@link OutputMessage}.<br>
 * 
 * Offers a method for getting {@link InputMessage}'s stream of data.
 */
public interface InputMessage {

	/**
	 * Returns the input stream.
	 *
	 * @return the input stream
	 */
	public InputStream getStream();
	
}
