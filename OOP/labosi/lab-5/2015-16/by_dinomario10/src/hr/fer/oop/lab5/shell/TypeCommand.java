package hr.fer.oop.lab5.shell;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.nio.file.Path;

/**
 * A command that is used for writing out the contents of a file. This command
 * requires an argument. If the given argument is a directory, an exception is
 * thrown and caught. This command can write out contents of all kinds of files,
 * but the content is not guaranteed to make any sense for non-text files.
 *
 * @author dinomario10
 */
public class TypeCommand extends AbstractCommand {

	/** Defines the proper syntax for using this command */
	private static final String SYNTAX = "type <filename>";

	/**
	 * Constructs a new command object of type {@code TypeCommand}.
	 */
	public TypeCommand() {
		super("TYPE", "Displays the contents of a file.");
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
		File file = path.toFile();

		if (file.exists()) {
			try (BufferedReader in = new BufferedReader(new FileReader(file))) {
				String line;
				while ((line = in.readLine()) != null) {
					env.writeln(line);
				}
			} catch (IOException e) {
				/* This could happen if the specified file is a folder,
				 * or if the file is protected */
				env.writeln("Access is denied.");
			}
		} else {
			env.writeln("The system cannot find the file specified.");
		}
		
		return CommandStatus.CONTINUE;
	}

}
