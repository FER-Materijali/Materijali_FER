package hr.fer.oop.lab5.second;

import java.io.*;
import java.nio.file.*;

/**
 * The Class Program.
 */
public class Program {

/** The byte reader. */
private static MySecondByteReader byteReader;
	
	/** The Constant DIR. */
	private static final String DIR = "racuni/";
	
	/** The Constant OUTPUT_UTF8. */
	private static final String OUTPUT_UTF8 = "cjenik.utf8.txt";
	
	/** The Constant OUTPUT_ISO. */
	private static final String OUTPUT_ISO = "cjenik.88592.txt";
	
	/**
	 * The main method.
	 *
	 * @param args the arguments
	 */
	public static void main(String[] args) {
		Path input = Paths.get(DIR);

		try(Writer bw = new BufferedWriter(new OutputStreamWriter(new BufferedOutputStream(new FileOutputStream(OUTPUT_UTF8)), "UTF-8"))) {
			byteReader = new MySecondByteReader();
			Files.walkFileTree(input, byteReader);
			
			//bw.write(String.format("%-100s%s%n%n", "IME ARTIKLA", "CIJENA S PDV-om"));
			for(Artikl artikl : byteReader.artikli) {
				bw.write(artikl.toString());
			}
		}
		catch(IOException e) {
			System.err.println(e);
		}
		
		try(Writer bw = new BufferedWriter(new OutputStreamWriter(new BufferedOutputStream(new FileOutputStream(OUTPUT_ISO)), "ISO-8859-2"))) {
			byteReader = new MySecondByteReader();
			Files.walkFileTree(input, byteReader);
			
			//bw.write(String.format("%-100s%s%n%n", "IME ARTIKLA", "CIJENA S PDV-om"));
			for(Artikl artikl : byteReader.artikli) {
				bw.write(artikl.toString());
			}
		}
		catch(IOException e) {
			System.err.println(e);
		}
	}
	
}
