package hr.fer.oop.lab5.third;

import java.io.*;

/**
 * The Class MaskStream.
 */
public class MaskStream extends OutputStream {

	/** The stream. */
	private OutputStream stream;
	
	/** The key. */
	private byte key;
	
	/**
	 * Instantiates a new mask stream.
	 *
	 * @param stream the stream
	 * @param key the key
	 */
	public MaskStream(OutputStream stream, byte key) {
		this.stream = stream;
		this.key = key;
	}

	/* (non-Javadoc)
	 * @see java.io.OutputStream#write(int)
	 */
	@Override
	public void write(int b) throws IOException {
		stream.write(b ^ key);
	}
}
