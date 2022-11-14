package hr.fer.oop.lab5.shell;

import java.io.File;
import java.nio.file.Path;

/**
 * A command that is used for creating directories.
 *
 * @author dinomario10
 */
public class MkdirCommand extends AbstractCommand {

	/** Defines the proper syntax for using this command */
	private static final String SYNTAX = "mkdir <path>";

	/**
	 * Constructs a new command object of type {@code MkdirCommand}.
	 */
	public MkdirCommand() {
		super("MKDIR", "Creates a directory.");
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
		
		if (dir.exists()) {
			env.writeln(dir.getName() + " already exists!");
		} else {
			dir.mkdirs();
			env.writeln(dir.getName() + " created in " + dir.getParent());
		}
		
		return CommandStatus.CONTINUE;
	}

}
