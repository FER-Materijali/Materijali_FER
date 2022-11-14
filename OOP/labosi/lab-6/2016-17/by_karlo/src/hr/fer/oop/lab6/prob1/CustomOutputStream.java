package hr.fer.oop.lab6.prob1;

import java.io.IOException;
import java.io.OutputStream;

import javax.swing.JTextArea;

/**
 * The Class CustomOutputStream.
 */
public class CustomOutputStream extends OutputStream {
	
	/** The text area. */
	private JTextArea textArea;

	/**
	 * Instantiates a new custom output stream.
	 *
	 * @param textArea the text area
	 */
	public CustomOutputStream(JTextArea textArea) {
		this.textArea = textArea;
	}

	/* (non-Javadoc)
	 * @see java.io.OutputStream#write(int)
	 */
	@Override
	public void write(int b) throws IOException {
		// redirects data to the text area
		textArea.append(String.valueOf((char) b));
		// scrolls the text area to the end of data
		textArea.setCaretPosition(textArea.getDocument().getLength());
	}
}