package hr.fer.oop.lab6.common.impl;

import java.io.ByteArrayInputStream;
import java.io.InputStream;

import hr.fer.oop.lab6.common.iface.InputMessage;

/**
 * Implements an interface {@link InputMessage} and is representation of the
 * {@link InputMessage} by the {@link Byte} data.
 * 
 * @author dinomario10
 */
public class InputMessageImpl implements InputMessage {
	
	/** The message. */
	private String message;

	/**
	 * Instantiates a new input message impl.
	 *
	 * @param message the message
	 */
	public InputMessageImpl(String message) {
		this.message = message;
	}

	@Override
	public InputStream getStream() {
		return new ByteArrayInputStream(message.getBytes());
	}

}
