package hr.fer.oop.lab5.shell;

import java.io.File;
import java.nio.file.Path;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.stream.Collectors;

/**
 * A command that is used for shuffling file names. If no argument has been
 * provided to the command, the command uses the current path of the
 * environment.
 *
 * @author dinomario10
 */
public class NameShuffleCommand extends AbstractCommand {
	
	/** Prefix used for temporarily renaming files */
	private static final String RENAMING_PREFIX = "__temp-";

	/**
	 * Constructs a new command object of type {@code NameShuffleCommand}.
	 */
	public NameShuffleCommand() {
		super("NAMESHUFFLE", "Shuffles the file names of a specified directory.");
	}
	
	@Override
	public CommandStatus execute(Environment env, String s) {
		Path path;
		if (s == null) {
			path = env.getCurrentPath();
		} else {
			path = Helper.resolveAbsolutePath(env, s);
			if (path == null) {
				env.writeln("Invalid path!");
				return CommandStatus.CONTINUE;
			}
		}

		File dir = path.toFile();
		
		if (!dir.exists() || !dir.isDirectory()) {
			env.writeln("The system cannot find the path specified.");
			return CommandStatus.CONTINUE;
		}
		
		/* Create an original list of files and keep it for later printing */
		List<File> originalListOfFiles = Arrays.asList(dir.listFiles());
		
		/* Check if the directory was empty */
		if (originalListOfFiles.size() == 0) {
			env.writeln("There are no files in the specified directory.");
			return CommandStatus.CONTINUE;
		}
		
		/* Create a list of file names and shuffle it */
		List<String> listOfFileNames = originalListOfFiles.stream()
				.map((file) -> {
					return file.getName();
				})
				.collect(Collectors.toList());
		
		Collections.shuffle(listOfFileNames);
		
		/* Temporarily rename all files */
		for (int i = 0, n = originalListOfFiles.size(); i < n; i++) {
			File tempFile = new File(dir, RENAMING_PREFIX + Integer.toString(i));
			originalListOfFiles.get(i).renameTo(tempFile);
		}
		
		/* Make a list of temp files */
		List<File> tempListOfFiles = Arrays.asList(dir.listFiles());
		
		/* Start shuffle-renaming */
		for (int i = 0, n = tempListOfFiles.size(); i < n; i++) {
			File originalFile = originalListOfFiles.get(i);
			File tempFile = tempListOfFiles.get(i);
			File renamingFile = new File(dir, listOfFileNames.get(i));
			
			tempFile.renameTo(renamingFile);
			
			env.writeln(originalFile.getName() + " renamed to " + renamingFile.getName());
		}
		
		return CommandStatus.CONTINUE;
	}

}
