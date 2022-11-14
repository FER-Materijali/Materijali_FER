package hr.fer.oop.lab3.topic1.shell.commands;

import hr.fer.oop.lab3.topic1.shell.CommandStatus;
import hr.fer.oop.lab3.topic1.shell.Environment;

/**
 * This method exits the shell.
 * 
 * @author Filip
 *
 */
public class QuitCommand extends AbstractCommand {

	public QuitCommand() {
		super("quit", "quit -> exit from the shell");
	}

	@Override
	public CommandStatus execute(Environment e, String arg) {
		return CommandStatus.Exit;
	}

}
