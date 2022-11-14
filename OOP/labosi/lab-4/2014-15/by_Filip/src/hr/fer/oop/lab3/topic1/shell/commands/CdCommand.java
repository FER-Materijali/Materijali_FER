package hr.fer.oop.lab3.topic1.shell.commands;

import hr.fer.oop.lab3.topic1.shell.CommandStatus;
import hr.fer.oop.lab3.topic1.shell.Environment;
import hr.fer.oop.lab3.topic1.shell.Terminal;
import hr.fer.zemris.java.util.Utility;

import java.io.File;
import java.nio.file.Paths;

/**
 * Change directory command, used for changing directories inside the shell.
 * 
 * @author Filip
 *
 */
public class CdCommand extends AbstractCommand {

	public CdCommand() {
		super("cd", "cd <arg> -> change directory to <arg>");
	}

	@Override
	public CommandStatus execute(Environment e, String arg) {
		String arg0 = Utility.mySplit(arg)[0];
		Terminal t = e.getActiveTerminal();
		String p = Utility.getAbsPath(e, arg0);

		if (!new File(p).isDirectory()) {
			e.writeln("Provided directory doesn't exist");
			return CommandStatus.Continue;
		}

		t.setCurrentPath(Paths.get(p));
		e.writeln("Current directory is now set to " + p);
		return CommandStatus.Continue;
	}

}
