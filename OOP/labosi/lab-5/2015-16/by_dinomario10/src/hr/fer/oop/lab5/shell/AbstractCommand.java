package hr.fer.oop.lab5.shell;

/**
 * Used as a superclass for other, usable Shell commands.
 * 
 * @author dinomario10
 */
public abstract class AbstractCommand implements ShellCommand {
	
	/** Name of the Shell command */
	private String commandName;
	/** Description of the Shell command */
	private String commandDescription;

	/**
	 * Generates a new command of a type extending {@code AbstractCommand}.
	 * 
	 * @param commandName name of the Shell command
	 * @param commandDescription description of the Shell command
	 */
	public AbstractCommand(String commandName, String commandDescription) {
		super();
		this.commandName = commandName;
		this.commandDescription = commandDescription;
	}
	
	/**
	 * Writes out the syntax error of a command. Also shows what the command
	 * expected as arguments.
	 * 
	 * @param env an environment
	 * @param syntax the expected syntax
	 */
	public static final void printSyntaxError(Environment env, String syntax) {
		env.writeln("The syntax of the command is incorrect. Expected: " + syntax);
	}

	@Override
	public String getCommandName() {
		return commandName;
	}

	@Override
	public String getCommandDescription() {
		return commandDescription;
	}

	@Override
	public abstract CommandStatus execute(Environment env, String s);

	@Override
	public int hashCode() {
		final int prime = 31;
		int result = 1;
		result = prime * result + ((commandName == null) ? 0 : commandName.hashCode());
		return result;
	}

	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (!(obj instanceof AbstractCommand))
			return false;
		AbstractCommand other = (AbstractCommand) obj;
		if (commandName == null) {
			if (other.commandName != null)
				return false;
		} else if (!commandName.equals(other.commandName))
			return false;
		return true;
	}

}
