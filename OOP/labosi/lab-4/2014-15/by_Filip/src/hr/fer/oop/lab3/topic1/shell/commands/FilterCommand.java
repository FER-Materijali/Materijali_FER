package hr.fer.oop.lab3.topic1.shell.commands;

import hr.fer.oop.lab3.topic1.shell.CommandStatus;
import hr.fer.oop.lab3.topic1.shell.Environment;
import hr.fer.zemris.java.util.Utility;

import java.io.IOException;
import java.nio.file.FileVisitResult;
import java.nio.file.FileVisitor;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.attribute.BasicFileAttributes;

/**
 * Used to filter files in the current directory by some filter.
 * 
 * @author Filip
 *
 */
public class FilterCommand extends AbstractCommand {

	public FilterCommand() {
		super("filter", "filter <arg> -> searches all subfolders for"
				+ " files that match the given filter <arg>");
	}

	@Override
	public CommandStatus execute(final Environment e, String arg) {

		final String regex = Utility.getRegex(Utility.mySplit(arg)[0]);

		Path p = e.getActiveTerminal().getCurrentPath();
		FileVisitor<Path> fv = new FileVisitor<Path>() {

			@Override
			public FileVisitResult preVisitDirectory(Path dir,
					BasicFileAttributes attrs) throws IOException {
				return FileVisitResult.CONTINUE;
			}

			@Override
			public FileVisitResult visitFile(Path file,
					BasicFileAttributes attrs) throws IOException {
				String s = file.toFile().getName();
				if (s.matches(regex)) {
					e.writeln(s);
				}
				return FileVisitResult.CONTINUE;
			}

			@Override
			public FileVisitResult visitFileFailed(Path file, IOException exc)
					throws IOException {
				return FileVisitResult.CONTINUE;
			}

			@Override
			public FileVisitResult postVisitDirectory(Path dir, IOException exc)
					throws IOException {
				return FileVisitResult.CONTINUE;
			}
		};

		try {
			Files.walkFileTree(p, fv);
		} catch (IOException e1) {
			e.writeln("Error while going through directories");
		}

		return CommandStatus.Continue;
	}

}
