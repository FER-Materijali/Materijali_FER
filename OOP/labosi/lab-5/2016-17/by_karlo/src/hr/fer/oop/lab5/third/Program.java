package hr.fer.oop.lab5.third;

import java.io.*;
import java.nio.file.*;

/**
 * The Class Program.
 */
public class Program {

	/** The Constant INPUT. */
	private static final String INPUT = "racuni/2015/1/Racun_0.txt";
	
	/** The Constant OUTPUT_ENCRYPTED. */
	private static final String OUTPUT_ENCRYPTED = "encrypted.txt";
	
	/** The Constant OUTPUT_DECRYPTED. */
	private static final String OUTPUT_DECRYPTED = "decrypted.txt";
	
	/** The cript byte writer. */
	private static MyCriptByteWriter criptByteWriter;
	
	/**
	 * The main method.
	 *
	 * @param args the arguments
	 */
	public static void main(String[] args) {
		
		Path input = Paths.get(INPUT);
		Path outputEncrypted = Paths.get(OUTPUT_ENCRYPTED);
		Path outputDecrypted = Paths.get(OUTPUT_DECRYPTED);
		
		try(InputStream is = Files.newInputStream(input)) {
			criptByteWriter = new MyCriptByteWriter(is, outputEncrypted);
			criptByteWriter.run();
			System.out.println("Generated encrypted file at: " + outputEncrypted.toAbsolutePath());
		}
		catch (IOException e) {
			System.err.println(e);
		}
		
		try(InputStream is = Files.newInputStream(outputEncrypted)) {
			criptByteWriter = new MyCriptByteWriter(is, outputDecrypted);
			criptByteWriter.run();
			System.out.println("Generated decrypted file at: " + outputDecrypted.toAbsolutePath());
		}
		catch (IOException e) {
			System.err.println(e);
		}	
	}
}
