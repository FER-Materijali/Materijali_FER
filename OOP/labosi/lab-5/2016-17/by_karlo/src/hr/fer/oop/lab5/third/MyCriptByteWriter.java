package hr.fer.oop.lab5.third;

import java.io.*;
import java.nio.file.*;

import hr.fer.oop.lab5.first.MyByteWriter;

/**
 * The Class MyCriptByteWriter.
 */
public class MyCriptByteWriter extends MyByteWriter {

	/**
	 * Instantiates a new my cript byte writer.
	 *
	 * @param stream the stream
	 * @param path the path
	 */
	public MyCriptByteWriter(InputStream stream, Path path) {
		super(stream, path);
	}

	/* (non-Javadoc)
	 * @see hr.fer.oop.lab5.first.MyByteWriter#run()
	 */
	@Override
	public void run() throws IOException {
		BufferedInputStream in = new BufferedInputStream(stream);
		OutputStream out = new MaskStream(Files.newOutputStream(path), (byte) 0x1337);
		byte[] buffer = new byte[1024];
	    int lenght;
	    while ((lenght = in.read(buffer)) > 0) {
	    	out.write(buffer, 0, lenght);
	    }         
	    in.close();
	    out.close();
	}
}
