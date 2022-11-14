package hr.fer.oop.lab6.common.impl;

import java.io.IOException;
import java.io.InputStream;

import hr.fer.oop.lab6.common.iface.InputMessage;
import hr.fer.oop.lab6.common.iface.OutputMessage;

/**
 * Implements an interface {@link OutputMessage} and is an {@link OutputMessage}
 * which contains the data of its {@link InputStream} and the {@link
 * InputMessage} based on which was made on.
 * 
 * @author dinomario10
 */
public class OutputMessageImpl implements OutputMessage {
	
	/** The input message. */
	private InputMessage inputMessage;
	/** The hash. */
	private InputStream hash;
	
	/**
	 * Instantiates a new output message implementation.
	 *
	 * @param inputMessage the input message
	 * @param hash the hash
	 */
	public OutputMessageImpl(InputMessage inputMessage, InputStream hash) {
		this.inputMessage = inputMessage;
		this.hash = hash;
	}

	@Override
	public InputStream getOutput() {
		return hash;
	}

	@Override
	public InputMessage getInputMessage() {
		return inputMessage;
	}

	@Override
	public void reset() {
		try {
			inputMessage.getStream().reset();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

}
