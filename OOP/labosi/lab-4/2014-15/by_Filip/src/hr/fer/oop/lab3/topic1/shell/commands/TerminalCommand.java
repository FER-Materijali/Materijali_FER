package hr.fer.oop.lab3.topic1.shell.commands;

import hr.fer.oop.lab3.topic1.shell.CommandStatus;
import hr.fer.oop.lab3.topic1.shell.Environment;
import hr.fer.zemris.java.util.Utility;

/**
 * Command used for changing terminals.
 * 
 * @author Filip
 *
 */
public class TerminalCommand extends AbstractCommand {

	public TerminalCommand() {
		super("terminal", "terminal <n> -> use terminal <n>");
	}

	@Override
	public CommandStatus execute(Environment e, String arg) {
		if (!Utility.isInteger(arg)) {
			e.writeln("Provided argument to terminal command is not a number");
		} else {
			int N = Integer.parseInt(arg);
			e.setActiveTerminal(e.getOrCreateTerminal(N));
			e.writeln("Changed current terminal to " + N);
		}
		return CommandStatus.Continue;
	}

}
