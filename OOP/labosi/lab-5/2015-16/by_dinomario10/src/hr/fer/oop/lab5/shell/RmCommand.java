package hr.fer.oop.lab5.shell;

import java.io.File;
import java.io.IOException;
import java.nio.file.FileVisitResult;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.SimpleFileVisitor;
import java.nio.file.attribute.BasicFileAttributes;

/**
 * A command that is used for removing files and non-empty directories.
 *
 * @author dinomario10
 */
public class RmCommand extends AbstractCommand {

	/** Defines the proper syntax for using this command */
	private static final String SYNTAX = "rm <path/filename>";

	/**
	 * Constructs a new command object of type {@code RmCommand}.
	 */
	public RmCommand() {
		super("RM", "Removes a file or a directory.");
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

		if (!file.exists()) {
			env.writeln("The system cannot find the file specified.");
			return CommandStatus.CONTINUE;
		}
		
		if (file.isDirectory()) {
			RmFileVisitor rmVisitor = new RmFileVisitor(env);
			try {
				Files.walkFileTree(file.toPath(), rmVisitor);
			} catch (IOException e) {
				env.writeln(e.getMessage());
			}
		} else if (file.delete() == true) {
			env.writeln("Deleted file " + file.getName());
		} else {
			env.writeln("Failed to delete file " + file.getName());
		}
			
		return CommandStatus.CONTINUE;
	}
	
	/**
	 * A {@linkplain SimpleFileVisitor} extended and used to serve the {@linkplain
	 * RmCommand}. This file visitor is mostly used to remove non-empty directories.
	 *
	 * @author dinomario10
	 */
	private static class RmFileVisitor extends SimpleFileVisitor<Path> {
		
		/** An environment */
		private Environment environment;

		/**
		 * Initializes a new instance of this class setting only an environment used
		 * only for writing out messages.
		 * 
		 * @param environment an environment
		 */
		public RmFileVisitor(Environment environment) {
			super();
			this.environment = environment;
		}

		@Override
		public FileVisitResult visitFile(Path file, BasicFileAttributes attrs) throws IOException {
			File f = file.toFile();
			f.delete();
			environment.writeln("Deleted file " + f.getName());

			return super.visitFile(file, attrs);
		}
		
		@Override
		public FileVisitResult visitFileFailed(Path file, IOException exc) throws IOException {
			System.out.println("Failed to remove " + file);
			return FileVisitResult.CONTINUE;
		}
		
		@Override
		public FileVisitResult postVisitDirectory(Path dir, IOException exc) throws IOException {
			File d = dir.toFile();
			d.delete();
			environment.writeln("Removed directory " + d.getName());

			return super.postVisitDirectory(dir, exc);
		}
	}

}
