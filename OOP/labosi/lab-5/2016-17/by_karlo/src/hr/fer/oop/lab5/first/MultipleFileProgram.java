package hr.fer.oop.lab5.first;

import java.io.*;
import java.nio.file.*;

/**
 * The Class MultipleFileProgram.
 */
public class MultipleFileProgram {
	
	/** The byte reader. */
	private static FileVisitor<Path> byteReader;
	
	/** The Constant DIR. */
	private static final String DIR = "racuni/";
	
	/** The Constant OUTPUT. */
	private static final String OUTPUT = "multiout.txt";
	
	/**
	 * The main method.
	 *
	 * @param args the arguments
	 */
	public static void main(String[] args) {
		Path input = Paths.get(DIR);
		Path output = Paths.get(OUTPUT);
		
		try(OutputStream os = Files.newOutputStream(output, StandardOpenOption.CREATE)) {
			byteReader = new MyByteReader(os);
			Files.walkFileTree(input, byteReader);
			System.out.println("File dumped to: " + output.toAbsolutePath());
		}
		catch (IOException e) {
			System.err.println(e);
		}	
	}
}
