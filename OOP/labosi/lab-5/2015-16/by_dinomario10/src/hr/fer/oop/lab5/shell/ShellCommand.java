package hr.fer.oop.lab5.shell;

/**
 * An interface that is used as a contract for implementing Shell commands.
 *
 * @author dinomario10
 */
public interface ShellCommand {

	/**
	 * Returns the name of the Shell command.
	 * 
	 * @return the name of the Shell command
	 */
	public String getCommandName();
	
	/**
	 * Returns the description of the Shell command.
	 * 
	 * @return the description of the Shell command
	 */
	public String getCommandDescription();
	
	/**
	 * Executes the given Shell command. Every shell command has its own unique
	 * way of executing. Most Shell commands write out their steps of executing,
	 * or they write out certain errors, so the {@code Environment} type param
	 * is given. Arguments may or may not exist (String has a valid value or
	 * {@code null}). The user is advised to check the implementing class
	 * documentation in order to see what this command does.
	 * 
	 * @param env an environment
	 * @param s arguments
	 * @return the status of this command
	 */
	public CommandStatus execute(Environment env, String s);
}
