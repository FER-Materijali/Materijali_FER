package hr.fer.oop.lab5.first;

import java.io.*;
import java.nio.file.*;

/**
 * The Class MyByteWriter.
 */
public class MyByteWriter {

	/** The stream. */
	protected InputStream stream;
	
	/** The path. */
	protected Path path;
	
	/**
	 * Instantiates a new my byte writer.
	 *
	 * @param stream the stream
	 * @param path the path
	 */
	public MyByteWriter(InputStream stream, Path path) {
		this.stream = stream;
		this.path = path;
	}
	
	/**
	 * Run.
	 *
	 * @throws IOException Signals that an I/O exception has occurred.
	 */
	public void run() throws IOException {
		BufferedInputStream in = new BufferedInputStream(stream);
		BufferedOutputStream out = new BufferedOutputStream(Files.newOutputStream(path, StandardOpenOption.CREATE));
		byte[] buffer = new byte[1024];
	    int lenght;	    
	    while ((lenght = in.read(buffer)) > 0) {
	    	out.write(buffer, 0, lenght);
	    }         
	    in.close();
	    out.close();
	}
	
}
