package hr.fer.oop.lab5.first;

import java.io.*;
import java.nio.file.*;

/**
 * The Class SingleFileProgram.
 */
public class SingleFileProgram {

	/** The byte writer. */
	private static MyByteWriter byteWriter;
	
	/** The Constant INPUT. */
	private static final String INPUT = "racuni/2015/1/Racun_0.txt";
	
	/** The Constant OUTPUT. */
	private static final String OUTPUT = "singleout.txt";
	
	/**
	 * The main method.
	 *
	 * @param args the arguments
	 */
	public static void main(String[] args) {
		Path input = Paths.get(INPUT);
		Path output = Paths.get(OUTPUT);
		
		try(InputStream is = Files.newInputStream(input)) {
			byteWriter = new MyByteWriter(is, output);
			byteWriter.run();
			System.out.println("File dumped to: " + output.toAbsolutePath());
		}
		catch (IOException e) {
			System.err.println(e);
		}		
	}

}
