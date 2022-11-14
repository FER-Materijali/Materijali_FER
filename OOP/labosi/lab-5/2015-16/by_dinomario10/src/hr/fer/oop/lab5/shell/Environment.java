package hr.fer.oop.lab5.shell;

import java.nio.file.Path;

/**
 * This interface represents an environment where the whole program works. It is
 * used for claiming the current user's path, working with commands and writing
 * out informational messages to the user.
 *
 * @author dinomario10
 * @author Marko Cupic
 */
public interface Environment {

	/**
	 * Reads the user's input and returns it as a string.
	 * 
	 * @return the user's input
	 */
	public String readLine();

	/**
	 * Writes the given string using the writer.
	 * 
	 * @param s string to be written
	 */
	public void write(String s);
	
	/**
	 * Writes the given array of characters using the writer.
	 * 
	 * @param cbuf array of characters to be written
	 * @param off offset
	 * @param len lenght to be written
	 */
	public void write(char cbuf[], int off, int len);

	/**
	 * Writes the given string using the writer, inputting a new line at the
	 * end.
	 * 
	 * @param s string to be written
	 */
	public void writeln(String s);

	/**
	 * Returns an iterable object containing this Shell's commands.
	 * 
	 * @return an iterable object containing this Shell's commands
	 */
	public Iterable<ShellCommand> commands();

	/**
	 * Returns the current working directory path.
	 * 
	 * @return the current working directory path
	 */
	public Path getCurrentPath();

	/**
	 * Sets the current working directory path.
	 * 
	 * @param path path to be set
	 */
	public void setCurrentPath(Path path);

	/**
	 * Returns the path of a directory where this program was run.
	 * 
	 * @return the path of a directory where this program was run
	 */
	public Path getHomePath();
}
