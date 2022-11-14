package hr.fer.oop.lab5.shell;

import java.util.List;
import java.io.File;
import java.nio.file.Path;
import java.util.Arrays;
import java.util.Collections;

/**
 * A command that is used for renaming all files and directories with the path
 * and new name specified as command arguments.
 * <p>
 * If the new name is <tt>example</tt> the and there are 101 files to be
 * renamed, the renamed files would be:
 * <blockquote><pre>
 *    example000
 *    example001
 *    ...
 *    example099
 *    example100
 * </blockquote></pre>
 * A start index can also be specified for this command
 *
 * @author dinomario10
 */
public class RenameAllCommand extends AbstractCommand {

	/** Defines the proper syntax for using this command */
	private static final String SYNTAX = "renameall <path> <newname> (optional: <startindex>)";

	/** Default numbering start index */
	private static final int DEF_START_INDEX = 0;
	
	/**
	 * Constructs a new command object of type {@code RenameAllCommand}.
	 */
	public RenameAllCommand() {
		super("RENAMEALL", "Renames all files and directories specified by a "
				+ "path and the new name. Optional start index may be included.");
	}
	
	@Override
	public CommandStatus execute(Environment env, String s) {
		if (s == null) {
			printSyntaxError(env, SYNTAX);
			return CommandStatus.CONTINUE;
		}
		
		String[] args = Helper.extractArguments(s);
		if (args.length < 2) {
			printSyntaxError(env, SYNTAX);
			return CommandStatus.CONTINUE;
		}
		
		Path path = Helper.resolveAbsolutePath(env, args[0]);
		if (path == null) {
			env.writeln("Invalid path!");
			return CommandStatus.CONTINUE;
		}
		File dir = path.toFile();
		
		if (!dir.exists() || !dir.isDirectory()) {
			env.writeln("The system cannot find the path specified.");
			return CommandStatus.CONTINUE;
		}
		
		String name = args[1];
		
		int offset = DEF_START_INDEX;
		try {
			offset = Integer.parseInt(args[2]);
		} catch (NumberFormatException e) {
			printSyntaxError(env, SYNTAX);
			return CommandStatus.CONTINUE;
		} catch (IndexOutOfBoundsException e) {}
		
		if (offset < 0) {
			env.writeln("The start index must be positive: " + offset);
			return CommandStatus.CONTINUE;
		}
		
		/* Create a sorted list of files in the specified directory */
		List<File> listOfFiles = Arrays.asList(dir.listFiles());
		Collections.sort(listOfFiles);
		
		/* Check if the directory was empty */
		if (listOfFiles.size() == 0) {
			env.writeln("There are no files in the specified directory.");
			return CommandStatus.CONTINUE;
		}
		
		/* Rename all files */
		for (int i = 0, n = listOfFiles.size(); i < n; i++) {
			int index = i + offset;
			String newName = name + getLeadingZeros(n, index) + index;
			
			File originalFile = listOfFiles.get(i);
			File renamingFile = new File(dir, newName);
			
			boolean renamed = originalFile.renameTo(renamingFile);
			if (renamed) {
				env.writeln(originalFile.getName() + " renamed to " + renamingFile.getName());
			} else {
				env.writeln(originalFile.getName() + " cannot be renamed to " + renamingFile.getName());
			}
		}
		
		return CommandStatus.CONTINUE;
	}
	
	/**
	 * Returns a string of zeroes that should be leading the
	 * <code>currentIndex</code> in relation to <code>numOfFiles</code>.
	 * 
	 * @param numOfFiles total number of files
	 * @param currentIndex index of the current processing object
	 * @return a string of leading zeroes
	 */
	private static String getLeadingZeros(int numOfFiles, int currentIndex) {
		int decimalPlaces = Integer.toString(numOfFiles).length();
		int numZeroes = decimalPlaces - (Integer.toString(currentIndex).length() % 10);
		
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < numZeroes; i++) {
			sb.append('0');
		}
		return sb.toString();
	}

}
