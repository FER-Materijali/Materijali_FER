package hr.fer.oop.lab5.shell;

import java.io.File;
import java.io.IOException;
import java.nio.file.FileVisitResult;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.SimpleFileVisitor;
import java.nio.file.attribute.BasicFileAttributes;

/**
 * A command that is used for copying one directory and one directory only, to
 * another location. The given location may be absolute or relative to the
 * current working directory. The destination directory may or may not be
 * existent. If the last name in the pathname's name sequence is an existing
 * directory, the original directory will be copied into that directory, with
 * all its contents. Else if the last name in the pathname's name sequence is a
 * non-existing directory, a new directory will be created and the contents of
 * the original directory will be copied into the newly created directory.
 *
 * @author dinomario10
 */
public class XcopyCommand extends AbstractCommand implements CopyFeatures {

	/** Defines the proper syntax for using this command */
	private static final String SYNTAX = "xcopy <path1> <path2>";

	/**
	 * Constructs a new command object of type {@code XcopyCommand}.
	 */
	public XcopyCommand() {
		super("XCOPY", "Copies one directory to another location, recursively.");
	}

	@Override
	public CommandStatus execute(Environment env, String s) {
		if (s == null || !s.contains(" ")) {
			printSyntaxError(env, SYNTAX);
			return CommandStatus.CONTINUE;
		}
		
		String args[] = Helper.extractArguments(s);
		
		Path path1;
		Path path2;
		try {
			path1 = Helper.resolveAbsolutePath(env, args[0]);
			path2 = Helper.resolveAbsolutePath(env, args[1]);
		} catch (ArrayIndexOutOfBoundsException e) {
			printSyntaxError(env, SYNTAX);
			return CommandStatus.CONTINUE;
		}

		if (path1 == null || path2 == null) {
			env.writeln("Invalid path!");
			return CommandStatus.CONTINUE;
		}
		
		File dir1 = path1.toFile();
		File dir2 = path2.toFile();
		
		copyDirectory(dir1, dir2, env);
		
		return CommandStatus.CONTINUE;
	}
	
	/**
	 * Validates both directories and copies {@code dir1} to {@code dir2}.
	 * 
	 * @param dir1 the directory to be copied
	 * @param dir2 the destination directory
	 * @param env an environment
	 */
	private void copyDirectory(File dir1, File dir2, Environment env) {
		if (!dir1.exists()) {
			env.writeln("The system cannot find the directory specified.");
			return;
		}
		if (dir1.isFile()) {
			env.writeln("Cannot copy files using the xcopy command. Use copy instead.");
			return;
		}
		if (dir2.isFile()) {
			env.writeln("Cannot copy directory onto a file.");
			return;
		}
		
		XcopyFileVisitor xcopyVisitor;
		if (dir2.exists()) {
			/* Copy dir1 to dir2, leaving the name of dir1 */
			File newDir = new File(dir2, dir1.getName());
			xcopyVisitor = new XcopyFileVisitor(dir1, newDir, env);
		} else {
			/* Copy dir1 to dir2 parent, renaming dir1 to dir2 */
			File newDir = new File(dir2.getParentFile(), dir2.getName());
			xcopyVisitor = new XcopyFileVisitor(dir1, newDir, env);
		}
		
		try {
			Files.walkFileTree(dir1.toPath(), xcopyVisitor);
		} catch (IOException e) {
			env.writeln(e.getMessage());
		}
	}
	
	/**
	 * A {@linkplain SimpleFileVisitor} extended and used to serve the {@linkplain
	 * XcopyCommand}. This file visitor is used to copy all contents of a source
	 * directory to a destination directory.
	 *
	 * @author dinomario10
	 */
	private static class XcopyFileVisitor extends SimpleFileVisitor<Path> implements CopyFeatures {
		
		/** Source directory */
		private File sourceDir;
		/** Destination directory */
		private File destDir;
		/** An environment */
		private Environment environment;

		/**
		 * Initializes a new instance of this class setting the source directory,
		 * destination directory and an environment used only for writing out
		 * messages.
		 * 
		 * @param sourceDir source directory
		 * @param destDir destination directory
		 * @param environment an environment
		 * 
		 */
		public XcopyFileVisitor(File sourceDir, File destDir, Environment environment) {
			super();
			this.sourceDir = sourceDir;
			this.destDir = destDir;
			this.environment = environment;
		}

		@Override
		public FileVisitResult preVisitDirectory(Path dir, BasicFileAttributes attrs) throws IOException {
			Path subPath = getSubPath(sourceDir.toPath(), dir);
			File fullPath = combinePaths(destDir, subPath);
			
			environment.writeln("Mkdir: " + fullPath);
			fullPath.mkdir();
			
			return super.preVisitDirectory(dir, attrs);
		}
		
		@Override
		public FileVisitResult visitFile(Path file, BasicFileAttributes attrs) throws IOException {
			Path subPath = getSubPath(sourceDir.toPath(), file);
			File fullPath = combinePaths(destDir, subPath);
			
			createNewFile(file.toFile(), fullPath.getParentFile(), fullPath.getName(), environment);
			
			return super.visitFile(file, attrs);
		}
		
		@Override
		public FileVisitResult visitFileFailed(Path file, IOException exc) throws IOException {
			System.out.println("Failed to access " + file);
			return FileVisitResult.CONTINUE;
		}
		
		/**
		 * Returns the subpath in relation to the {@code sourceDir} and {@code path}.
		 * For an example, if the {@code sourceDir} is {@code /a/b} and the
		 * {@code path} is {@code /a/b/c/d}, the returned value is {@code c/d}.
		 * 
		 * @param sourceDir source directory
		 * @param path a path relative to source directory
		 * @return relativized subpath
		 */
		private Path getSubPath(Path sourceDir, Path path) {
			return sourceDir.relativize(path);
		}
		
		/**
		 * Combines two paths into one. For an example if the {@code parent} is
		 * {@code /a/b}, and the {@code child} is {@code /c/d}, the combined path is
		 * {@code /a/b/c/d}.
		 * 
		 * @param parent parent file
		 * @param child child path
		 * @return a combined path
		 */
		private File combinePaths(File parent, Path child) {
			File fullPath = new File(parent, child.toString());
			return fullPath;
		}
	}

}
