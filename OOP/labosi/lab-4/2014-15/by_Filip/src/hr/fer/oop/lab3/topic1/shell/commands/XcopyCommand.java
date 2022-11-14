package hr.fer.oop.lab3.topic1.shell.commands;

import hr.fer.oop.lab3.topic1.shell.CommandStatus;
import hr.fer.oop.lab3.topic1.shell.Environment;
import hr.fer.zemris.java.util.Utility;

/**
 * This method is used to copy a whole directory structure to a given directory.
 * 
 * @author Filip
 *
 */
public class XcopyCommand extends AbstractCommand {

	public XcopyCommand() {
		super("xcopy", "xcopy <d1> <d2> -> copies the dir <d1> to dir <d2>");
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
			Utility.copyDir(e, arg0, arg1);
		}

		return CommandStatus.Continue;
	}
}
