package hr.fer.oop.lab5.shell;

import java.io.File;
import java.nio.file.Path;

/**
 * A command that is used for removing empty directories. In order to remove a
 * non-empty directory, use {@linkplain RmCommand}.
 *
 * @author dinomario10
 */
public class RmdirCommand extends AbstractCommand {

	/** Defines the proper syntax for using this command */
	private static final String SYNTAX = "rmdir <path>";

	/**
	 * Constructs a new command object of type {@code RmdirCommand}.
	 */
	public RmdirCommand() {
		super("RMDIR", "Removes a directory.");
	}

	@Override
	public CommandStatus execute(Environment env, String s) {
		if (s == null) {
			printSyntaxError(env, SYNTAX);
			return CommandStatus.CONTINUE;
		}
		
		Path path = Helper.resolveAbsolutePath(env, s);
		if (path == null) {
			env.writeln("Invalid path!");
			return CommandStatus.CONTINUE;
		}
		File dir = path.toFile();
		
		if (!dir.exists()) {
			env.writeln("The system cannot find the directory specified.");
		} else if (dir.isFile()){
			env.writeln(dir.getName() + " is not a directory.");
		} else {
			if (dir.delete() == false) {
				env.writeln("The directory must be empty in order to be removed.");
			} else {
				env.writeln("Directory " + dir.getName() + " removed.");
			}
		}

		return CommandStatus.CONTINUE;
	}

}
