package hr.fer.oop.lab5.shell;

import java.io.File;
import java.nio.file.Path;

/**
 * A command that is used for copying one file and only one file, to another
 * location. The given location may be absolute or relative to the current
 * working directory. The destination directory must be existent in order for
 * the file to be copied. If the last name in the pathname's name sequence is an
 * existing directory, the newly made file will be named as the original file.
 * Else if the last name in the pathname's name sequence is a non-existing
 * directory (a file), the newly made file will be named as it.
 *
 * @author dinomario10
 */
public class CopyCommand extends AbstractCommand implements CopyFeatures {
	
	/** Defines the proper syntax for using this command */
	private static final String SYNTAX = "copy <filename1> <filename2>";

	/**
	 * Constructs a new command object of type {@code CopyCommand}.
	 */
	public CopyCommand() {
		super("COPY", "Copies one file to another location.");
	}

	@Override
	public CommandStatus execute(Environment env, String s) {
		if (s == null || !s.contains(" ")) {
			printSyntaxError(env, SYNTAX);
			return CommandStatus.CONTINUE;
		}
		
		String args[] = Helper.extractArguments(s);
		
		Path path1 = Helper.resolveAbsolutePath(env, args[0]);
		Path path2 = Helper.resolveAbsolutePath(env, args[1]);
		if (path1 == null || path2 == null) {
			env.writeln("Invalid path!");
			return CommandStatus.CONTINUE;
		}
		
		File file1 = path1.toFile();
		File file2 = path2.toFile();
		
		copyFile(file1, file2, env);
		
		return CommandStatus.CONTINUE;
	}

	/**
	 * Validates both files and copies {@code file1} to {@code file2}.
	 * 
	 * @param file1 the file to be copied
	 * @param file2 the destination file
	 * @param env an environment
	 */
	private void copyFile(File file1, File file2, Environment env) {
		if (!file1.exists()) {
			env.writeln("The system cannot find the file specified.");
			return;
		}
		if (file1.isDirectory()) {
			env.writeln("Cannot copy directories using the regular copy command. Use xcopy instead.");
			return;
		}
		if (file2.isDirectory()) {
			createNewFile(file1, file2, file1.getName(), env);
		} else {
			createNewFile(file1, file2.getParentFile(), file2.getName(), env);
		}
	}

}
