package hr.fer.oop.lab5.shell;

import java.nio.file.Path;

/**
 * A command that is used for changing the current working directory. The given
 * path may be absolute or relative to the current working directory. It can
 * also be inputed with quotation marks, which is widely used to interpret files
 * and directories containing whitespaces.
 *
 * @author dinomario10
 */
public class CdCommand extends AbstractCommand {

	/**
	 * Constructs a new command object of type {@code CdCommand}.
	 */
	public CdCommand() {
		super("CD", "Changes the current directory.");
	}

	@Override
	public CommandStatus execute(Environment env, String s) {
		if (s == null) {
			env.setCurrentPath(env.getHomePath());
			return CommandStatus.CONTINUE;
		}

		Path newPath = Helper.resolveAbsolutePath(env, s);
		if (newPath == null) {
			env.writeln("Invalid path!");
			return CommandStatus.CONTINUE;
		}
		
		if (!newPath.toFile().exists()) {
			env.writeln("The system cannot find the path specified.");
		} else {
			env.setCurrentPath(newPath);
		}

		return CommandStatus.CONTINUE;
	}

}
