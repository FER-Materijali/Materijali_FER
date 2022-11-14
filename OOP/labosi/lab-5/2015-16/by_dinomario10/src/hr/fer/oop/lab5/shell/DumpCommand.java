package hr.fer.oop.lab5.shell;

import java.io.BufferedOutputStream;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.nio.file.Path;
import java.util.Scanner;

/**
 * Dumps empty bytes (zeroes) to the given file name. Number of dumped bytes is
 * user-defined.
 *
 * @author dinomario10
 */
public class DumpCommand extends AbstractCommand {
	
	/** Defines the proper syntax for using this command */
	private static final String SYNTAX = "dump <size> <filename>";
	
	/** Standard size for the loading byte buffer array */
	public static final int STD_LOADER_SIZE = 16384;

	/**
	 * Constructs a new command object of type {@code DumpCommand}.
	 */
	public DumpCommand() {
		super("DUMP", "Creates a new dump file with the given size in bytes and file name.");
	}
	
	@Override
	public CommandStatus execute(Environment env, String s) {
		if (s == null || !s.contains(" ")) {
			printSyntaxError(env, SYNTAX);
			return CommandStatus.CONTINUE;
		}

		long size;
		String pathname;
		try (Scanner sc = new Scanner(s)) {
			size = sc.nextLong();
			pathname = sc.nextLine().trim();
		} catch (Exception e) {
			printSyntaxError(env, SYNTAX);
			return CommandStatus.CONTINUE;
		}

		Path path = Helper.resolveAbsolutePath(env, pathname);
		if (path == null) {
			env.writeln("Invalid path!");
			return CommandStatus.CONTINUE;
		}
		File file = path.toFile();
		
		if (file.isDirectory()) {
			env.writeln("Directory " + file.getName() + " already exists.");
			return CommandStatus.CONTINUE;
		}
		
		if (file.exists()) {
			if (!promptOverwrite(env, file)) {
				return CommandStatus.CONTINUE;
			}
		}
		
		dumpBytes(env, file, size);
		env.writeln("Dumped " + Helper.humanReadableByteCount(size) + " in file " + file.getName());
		
		return CommandStatus.CONTINUE;
	}
	
	/**
	 * Prompts the user to overwrite the currently existing file. Returns true
	 * if the user answers "yes" and false if the user answers "no". Goes in an
	 * infinite loop if none of the answers are given.
	 * 
	 * @param env an environment
	 * @param file the currently existing file
	 * @return true if the user answers "yes", false if "no"
	 */
	private static boolean promptOverwrite(Environment env, File file) {
		env.write("File " + file.getName() + " already exists. Overwrite? (Y/N) ");
		while (true) {
			String answer = env.readLine();
			if ("y".equalsIgnoreCase(answer) || "yes".equalsIgnoreCase(answer)) {
				return true;
			} else if ("n".equalsIgnoreCase(answer) || "no".equalsIgnoreCase(answer)) {
				return false;
			} else {
				env.writeln("Unknown answer: " + answer);
			}
		}
	}
	
	/**
	 * Dumps random bytes into the given {@code file} with the given
	 * {@code size}.
	 * 
	 * @param file file to be created
	 * @param size number of bytes to be generated
	 */
	private static void dumpBytes(Environment env, File file, long size) {
		long writtenBytes = 0;
		
		try (BufferedOutputStream out = new BufferedOutputStream(new FileOutputStream(file))) {
			int len = STD_LOADER_SIZE;
			byte[] bytes = new byte[STD_LOADER_SIZE];

			while (writtenBytes < size) {
				if (size - writtenBytes < len) {
					len = (int) (size - writtenBytes);
				}
				out.write(bytes, 0, len);
				writtenBytes += len;
			}
			
		} catch (IOException e) {
			env.writeln("An I/O error occured!");
			env.writeln(e.getMessage());
		}
	}

}
