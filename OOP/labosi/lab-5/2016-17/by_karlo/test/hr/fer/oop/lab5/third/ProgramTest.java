package hr.fer.oop.lab5.third;

import static org.junit.Assert.*;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;

import org.junit.Test;

// TODO: Auto-generated Javadoc
/**
 * The Class ProgramTest.
 */
public class ProgramTest {
	
	/** The input. */
	private final String INPUT = "racuni/2015/1/Racun_0.txt";
	
	/** The output decrypted. */
	private final String OUTPUT_DECRYPTED = "decrypted.txt";

	/**
	 * Test file size.
	 */
	@Test
	public void testFileSize() {
		try {
			assertTrue("File size differ!", Files.size(Paths.get(INPUT)) == Files.size(Paths.get(OUTPUT_DECRYPTED)));
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	/**
	 * Test file lines.
	 */
	@Test
	public void testFileLines() {
		try {
			assertEquals("Files differ!", Files.readAllLines(Paths.get(INPUT)), Files.readAllLines(Paths.get(OUTPUT_DECRYPTED)));
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

}
