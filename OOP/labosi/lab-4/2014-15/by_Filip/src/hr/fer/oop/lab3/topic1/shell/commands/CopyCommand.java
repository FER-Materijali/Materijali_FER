package hr.fer.oop.lab3.topic1.shell.commands;

import hr.fer.oop.lab3.topic1.shell.CommandStatus;
import hr.fer.oop.lab3.topic1.shell.Environment;
import hr.fer.zemris.java.util.Utility;

/**
 * Used to copy files inside the shell.
 * 
 * @author Filip
 *
 */
public class CopyCommand extends AbstractCommand {

	public CopyCommand() {
		super("copy", "copy <f1> <f2> -> copies the file <f1> to file <f2>");
	}

	@Override
	public CommandStatus execute(Environment e, String arg) {
		String[] args = Utility.mySplit(arg);
		int len = args.length;
		if (len == 0) {
			e.writeln("Please provide source file and destination");
		} else if (len == 1) {
			e.writeln("Please provide a destination");
		} else {
			String arg0 = Utility.getAbsPath(e, args[0]);
			String arg1 = Utility.getAbsPath(e, args[1]);
			Utility.copyFile(e, arg0, arg1);
		}

		return CommandStatus.Continue;
	}
}
