package hr.fer.oop.lab5.shell;

import java.io.File;
import java.io.IOException;
import java.nio.file.FileVisitResult;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.SimpleFileVisitor;
import java.nio.file.attribute.BasicFileAttributes;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

/**
 * Walks the directory tree from the given path, or current path if no path is
 * entered. Prints out the given maximum quantity of largest files (or less, if
 * that many files are not found) to the current environment. If no quantity is
 * given, the quantity is set to 10 by default.
 *
 * @author dinomario10
 */
public class LargestCommand extends AbstractCommand {

	/** Defines the proper syntax for using this command */
	private static final String SYNTAX = "largest <quantity> <path>";

	/** Default amount of top largest files */
	private static final int DEF_QUANTITY = 10;
	
	/**
	 * Constructs a new command object of type {@code LargestCommand}.
	 */
	public LargestCommand() {
		super("LARGEST", "Displays the specified quantity number of largest files in the specified directory tree.");
	}
	
	@Override
	public CommandStatus execute(Environment env, String s) {
		int quantity;
		String pathname = ".";
		
		if (s == null) {
			quantity = DEF_QUANTITY;
		} else if (!s.contains(" ")) {
			try {
				quantity = Integer.parseInt(s);
			} catch (NumberFormatException e) {
				printSyntaxError(env, SYNTAX);
				return CommandStatus.CONTINUE;
			}
		} else {
			try (Scanner sc = new Scanner(s)) {
				quantity = sc.nextInt();
				pathname = sc.nextLine().trim();
			} catch (Exception e) {
				printSyntaxError(env, SYNTAX);
				return CommandStatus.CONTINUE;
			}
		}

		Path path = Helper.resolveAbsolutePath(env, pathname);
		if (path == null) {
			env.writeln("Invalid path!");
			return CommandStatus.CONTINUE;
		}
		File dir = path.toFile();
		
		if (!dir.isDirectory()) {
			env.writeln("The system cannot find the path specified.");
			return CommandStatus.CONTINUE;
		}
		
		LargestFileVisitor largestVisitor = new LargestFileVisitor(env, quantity);
		try {
			Files.walkFileTree(path, largestVisitor);
		} catch (IOException e) {
			env.writeln(e.getMessage());
		}
		
		List<File> largestFiles = largestVisitor.getLargest();
		for (File f : largestFiles) {
			env.writeln(f + " (" + Helper.humanReadableByteCount(f.length()) + ")");
		}
		
		return CommandStatus.CONTINUE;
	}

	/**
	 * A {@linkplain SimpleFileVisitor} extended and used to serve the
	 * {@linkplain LargestCommand}. Only the {@code visitFile} method is
	 * overridden.
	 *
	 * @author dinomario10
	 */
	private static class LargestFileVisitor extends SimpleFileVisitor<Path> {

		/** An environment */
		private Environment environment;
		/** Number of largest files to be printed out */
		private int quantity;
		/** List of largest files in the given directory tree */
		private List<File> largestFiles;

		/** A comparator that compares files by their size, largest first */
		private static final Comparator<File> BY_SIZE = (f1, f2) -> {
			return -Long.compare(f1.length(), f2.length());
		};
		
		/**
		 * Initializes a new instance of this class setting the quantity and
		 * an environment used only for writing out messages.
		 * 
		 * @param environment an environment
		 * @param quantity number of largest files to be printed out
		 */
		public LargestFileVisitor(Environment environment, int quantity) {
			this.environment = environment;
			this.quantity = quantity;
			largestFiles = new ArrayList<>();
		}
		
		/**
		 * Adds the file to the list of candidates for largest files.
		 */
		@Override
		public FileVisitResult visitFile(Path file, BasicFileAttributes attrs) throws IOException {
			addCandidate(file.toFile());
			return FileVisitResult.CONTINUE;
		}
		
		/**
		 * Continues searching for largest files.
		 */
		@Override
		public FileVisitResult visitFileFailed(Path file, IOException exc) throws IOException {
			environment.writeln("Failed to access " + file);
			return FileVisitResult.CONTINUE;
		}
		
		/**
		 * Adds files unconditionally if the list has not yet reached the
		 * desired maximum quantity. If the list has been filled, the smallest
		 * file is checked with param {@code file} and the largest of these two
		 * will be left in the list.
		 * 
		 * @param file candidate file
		 */
		private void addCandidate(File file) {
			if (largestFiles.size() < quantity) {
				largestFiles.add(file);
			} else {
				int lastIndex = quantity-1;
				File lastFile = largestFiles.get(lastIndex);
				if (lastFile.length() < file.length()) {
					largestFiles.remove(lastIndex);
					largestFiles.add(file);
				}
			}
			
			Collections.sort(largestFiles, BY_SIZE);
		}
		
		/**
		 * Returns the list of largest files in the directory tree.
		 * 
		 * @return the list of largest files in the directory tree
		 */
		public List<File> getLargest() {
			return largestFiles;
		}
	}

}
