package hr.fer.oop.lab5.shell;

/**
 * A command that is used for displaying all other commands, including this one,
 * and its descriptions. This command can also be used to display a description
 * for only a certain command, by passing the wanted command name as this
 * command's argument.
 *
 * @author dinomario10
 */
public class HelpCommand extends AbstractCommand {

	/**
	 * Constructs a new command object of type {@code HelpCommand}.
	 */
	public HelpCommand() {
		super("HELP", "Provides help information for MyShell commands.");
	}

	@Override
	public CommandStatus execute(Environment env, String s) {
		Iterable<ShellCommand> commands = env.commands();

		if (s == null) {
			printAllCommands(env, commands);
		} else {
			s = s.toUpperCase();
			printSpecifiedCommand(env, commands, s);
		}

		return CommandStatus.CONTINUE;
	}

	/**
	 * Writes out all the command names and their descriptions.
	 * 
	 * @param env an environment
	 * @param commands this Shell's commands
	 */
	private void printAllCommands(Environment env, Iterable<ShellCommand> commands) {
		for (ShellCommand command : commands) {
			env.writeln(command.getCommandName() + ": " + command.getCommandDescription());
		}
	}

	/**
	 * Writes out description of a a certain command.
	 * 
	 * @param env an environment
	 * @param commands supported MyShell commands
	 * @param s name of the specified command
	 */
	private void printSpecifiedCommand(Environment env, Iterable<ShellCommand> commands, String s) {
		for (ShellCommand command : commands) {
			if (command.getCommandName().equals(s)) {
				env.writeln((command.getCommandDescription()));
				return;
			}
		}
		env.writeln("Cannot provide help for command: " + s);
	}

}
