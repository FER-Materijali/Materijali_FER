package hr.fer.oop.lab3.topic1.shell.commands;

import hr.fer.oop.lab3.topic1.shell.CommandStatus;
import hr.fer.oop.lab3.topic1.shell.Environment;
import hr.fer.oop.lab4.dir.Dir;
import hr.fer.oop.lab4.dir.FilePrinter;
import hr.fer.zemris.java.util.Utility;

import java.io.File;
import java.util.ArrayList;
import java.util.List;

/**
 * This command is something like the 'ls' command in Unix.
 * 
 * @author Filip
 *
 */
public class DirCommand extends AbstractCommand {

	public DirCommand() {
		super("dir", "dir [<staza>, /sort=<sort>, /type=<type>, /filter=<filter>]");
	}

	@Override
	public CommandStatus execute(Environment e, String arg) {
		String[] args = Utility.mySplit(arg);

		File dir = new File(".");
		String sort = "";
		String filter = "";
		String type = "";

		if (args.length > 0) {
			for (String s : args) {
				if (s.startsWith("/")) {
					String[] xs = s.split("=");
					if (xs.length != 2) {
						e.writeln("Wrong syntax at " + s);
						return CommandStatus.Continue;
					}
					String name = xs[0];
					String specificator = xs[1];
					if (name.equalsIgnoreCase("/sort")) {
						sort = specificator;
					} else if (name.equalsIgnoreCase("/type")) {
						type = specificator;
					} else if (name.equalsIgnoreCase("/filter")) {
						filter = specificator;
					} else {
						e.writeln("Unknown parameter " + name);
						return CommandStatus.Continue;
					}
				} else {
					dir = new File(s);
					if (!dir.exists() || dir.isFile()) {
						e.writeln("Directory doesn't exist: " + dir.toString());
						return CommandStatus.Continue;
					}
				}
			}
		}

		List<File> files = new Dir(dir, sort, type, filter).files();

		List<String> types = new ArrayList<>();
		types.add("n");
		types.add("t");
		types.add("s");
		types.add("m");

		new FilePrinter(files, types).printRecords(e);

		return CommandStatus.Continue;

	}
}
