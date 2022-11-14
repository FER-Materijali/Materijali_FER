package hr.fer.oop.lab3.topic1.shell;

/**
 * Every class that implements this interface knows how to execute it self in
 * the given {@link Environment}.
 * 
 * @author Filip
 *
 */
public interface ShellCommand {

	/**
	 * Returns the command's name
	 * 
	 * @return name
	 */
	public String getCommandName();

	/**
	 * Returns the command's description
	 * 
	 * @return description
	 */
	public String getCommandDescription();

	/**
	 * Executes the command in the given {@link Environment}
	 * 
	 * @param e environment
	 * @param arg arguments for the command
	 * @return continue if shell should continue, exit otherwise
	 */
	public CommandStatus execute(Environment e, String arg);

}
