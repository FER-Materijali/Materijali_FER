package hr.fer.oop.lab5.shell;

/**
 * A command that is used for printing the current working directory.
 *
 * @author dinomario10
 */
public class PwdCommand extends AbstractCommand {
	
	/**
	 * Constructs a new command object of type {@code PwdCommand}.
	 */
	public PwdCommand() {
		super("PWD", "Prints out the working directory (absolute directory path).");
	}

	@Override
	public CommandStatus execute(Environment env, String s) {
		env.writeln(env.getCurrentPath().toString());
		return CommandStatus.CONTINUE;
	}

}
