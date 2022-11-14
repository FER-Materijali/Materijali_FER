package hr.fer.oop.lab3.topic1.shell.commands;

import hr.fer.oop.lab3.topic1.shell.CommandStatus;
import hr.fer.oop.lab3.topic1.shell.Environment;
import hr.fer.oop.lab3.topic1.shell.ShellCommand;

/**
 * This command prints out descriptions of all methods
 * 
 * @author Filip
 *
 */
public class HelpCommand extends AbstractCommand {

	public HelpCommand() {
		super("help", "help -> descriptions of availible commands");
	}

	@Override
	public CommandStatus execute(Environment e, String arg) {
		for (ShellCommand c : e.commands()) {
			e.writeln(c.getCommandDescription());
		}
		return CommandStatus.Continue;
	}

}
