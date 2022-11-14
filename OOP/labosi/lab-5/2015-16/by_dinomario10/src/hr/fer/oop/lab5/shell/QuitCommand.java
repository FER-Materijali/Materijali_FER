package hr.fer.oop.lab5.shell;

/**
 * A command that is used for terminating the Shell.
 *
 * @author dinomario10
 */
public class QuitCommand extends AbstractCommand {

	/**
	 * Constructs a new command object of type {@code HelpCommand}.
	 */
	public QuitCommand() {
		super("QUIT", "Quits the MyShell program.");
	}

	@Override
	public CommandStatus execute(Environment env, String s) {
		return CommandStatus.EXIT;
	}

}
