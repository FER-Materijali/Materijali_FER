package hr.fer.oop.lab3.topic1.shell.commands;

import hr.fer.oop.lab3.topic1.shell.CommandStatus;
import hr.fer.oop.lab3.topic1.shell.Environment;
import hr.fer.zemris.java.util.Utility;

import java.io.BufferedInputStream;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.nio.charset.Charset;
import java.nio.file.Paths;

/**
 * Command that prints out the content of a given file.
 * 
 * @author Filip
 *
 */
public class TypeCommand extends AbstractCommand {

	/**
	 * Default buffer capacity used when reading a file.
	 */
	private static final int BUFFER_CAPACITY = 4096;

	public TypeCommand() {
		super("type", "type arg -> show content of <arg>");
	}

	@Override
	public CommandStatus execute(Environment e, String arg) {

		Charset charset = Charset.defaultCharset();
		File f = Paths.get(Utility.getAbsPath(e, arg)).toFile();
		System.out.println(f);

		// reading from file and printing it out
		try (BufferedReader fileReader = new BufferedReader(
				new InputStreamReader(new BufferedInputStream(
						new FileInputStream(f)), charset));) {

			char[] cbuf = new char[BUFFER_CAPACITY];
			while (fileReader.read(cbuf) > 0) {
				e.write(new String(cbuf));
			}
			e.writeln("");

		} catch (FileNotFoundException fnfe) {
			e.writeln("File '" + arg + "' doesn't exist.");
		} catch (IOException ioe) {
			e.writeln("Error occured while reading file.");
		}
		return CommandStatus.Continue;

	}
}
