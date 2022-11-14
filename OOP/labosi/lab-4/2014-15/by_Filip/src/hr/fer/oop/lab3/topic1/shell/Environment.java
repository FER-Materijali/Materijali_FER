package hr.fer.oop.lab3.topic1.shell;

/**
 * Okruženje za izvođenje.
 * 
 * @author Filip
 *
 */
public interface Environment {

	/**
	 * Read a line from somewhere
	 * 
	 * @return line
	 */
	public String readLine();

	/**
	 * Writes a line to somewhere
	 * 
	 * @param s line to write
	 */
	public void write(String s);

	/**
	 * The same as write, but with <code>\n</code> at the end
	 * 
	 * @param s line to write
	 */
	public void writeln(String s);

	/**
	 * Returns the active terminal
	 * 
	 * @return active terminal
	 */
	public Terminal getActiveTerminal();

	/**
	 * Set a new active terminal
	 * 
	 * @param t terminal to set
	 */
	public void setActiveTerminal(Terminal t);

	/**
	 * Returns a terminal with given id
	 * 
	 * @param id id of the terminal
	 * @return terminal
	 */
	public Terminal getOrCreateTerminal(int id);

	/**
	 * List of all available terminals (in no particular order)
	 * 
	 * @return list of terminals
	 */
	public Terminal[] listTerminals();

	/**
	 * Iterable object on available commands
	 * 
	 * @return commands iterable
	 */
	public Iterable<? extends ShellCommand> commands();

}
