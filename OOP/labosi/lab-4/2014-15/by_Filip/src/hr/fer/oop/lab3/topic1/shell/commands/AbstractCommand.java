package hr.fer.oop.lab3.topic1.shell.commands;

import hr.fer.oop.lab3.topic1.shell.ShellCommand;

/**
 * Command that implements getName and getDescription methods.
 * 
 * @author Filip
 *
 */
public abstract class AbstractCommand implements ShellCommand {

	private String commandName;
	private String commandDescription;

	/**
	 * Creates a new command with given parameters
	 * 
	 * @param commandName
	 *            name
	 * @param commandDescription
	 *            description
	 */
	public AbstractCommand(String commandName, String commandDescription) {
		this.commandName = commandName;
		this.commandDescription = commandDescription;
	}

	@Override
	public String getCommandName() {
		return commandName;
	}

	@Override
	public String getCommandDescription() {
		return commandDescription;
	}

}
