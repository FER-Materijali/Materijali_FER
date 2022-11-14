package hr.fer.oop.lab5.shell;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.HashMap;
import java.util.Map;
import java.util.stream.Collectors;

/**
 * MyShell, this is where the magic happens. Scans the user's input and searches
 * for a matching command. Some commands require arguments, so the user must
 * input them as well. If the inputed command is found, the command is
 * executed, otherwise an error message is displayed. The program stops and
 * prints out a goodbye message if the inputed command is {@linkplain
 * QuitCommand}. The program also indicates the current user's position by
 * prompting the current directory while waiting for a command to be inputed.
 *
 * @author dinomario10
 * @author Marko Cupic
 */
public class MyShell {
	
	/** A map of commands */
	private static Map<String, ShellCommand> commands;
	
	static {
		commands = new HashMap<>();
		ShellCommand[] cc = {
				new HelpCommand(),
				new QuitCommand(),
				new CdCommand(),
				new PwdCommand(),
				new DateCommand(),
				new LsCommand(),
				new TypeCommand(),
				new FilterCommand(),
				new CopyCommand(),
				new MkdirCommand(),
				new RmdirCommand(),
				new XcopyCommand(),
				new RmCommand(),
				new NameShuffleCommand(),
				new ConnectCommand(),
				new HostCommand(),
				new ByteShuffleCommand(),
				new DumpCommand(),
				new LargestCommand(),
				new RenameAllCommand()
		};
		for (ShellCommand c : cc) {
			commands.put(c.getCommandName(), c);
		}
	}
	
	/** An environment */
	private static EnvironmentImpl environment = new EnvironmentImpl();
	
	/**
	 * Scans the user's input and searches for a matching command. Some commands
	 * require arguments, so the user must input them as well. If the inputed
	 * command is found, the command is executed, otherwise an error message is
	 * displayed. The program stops and prints out a goodbye message if the
	 * inputed command is {@linkplain QuitCommand}. The program also indicates
	 * the current user's position by prompting the current directory while
	 * waiting for a command to be inputed.
	 * 
	 * @param args an array of {@code String} arguments
	 * @throws IOException if an IO exception occurs while writing or reading the input
	 */
	public static void main(String[] args) throws IOException {
		environment.writeln("Welcome to MyShell! You may enter commands.");
		
		while (true) {
			Path path = environment.getCurrentPath();
			environment.write("$" + (path.equals(path.getRoot()) ? path : path.getFileName()) + "> ");
			String line = environment.readLine().trim();
			String cmd;
			String arg;
			int splitter = line.indexOf(' ');
			if (splitter != -1) {
				cmd = line.substring(0, splitter).toUpperCase();
				arg = line.substring(splitter+1).trim();
			} else {
				cmd = line.toUpperCase();
				arg = null;
			}
			ShellCommand shellCommand = commands.get(cmd);
			if (shellCommand == null) {
				environment.writeln("Unknown command!");
				continue;
			}
			if (shellCommand.execute(environment, arg) == CommandStatus.EXIT) {
				break;
			} else {
				environment.writeln("");
			}
		}
		
		environment.writeln("Thank you for using this shell. Goodbye!");
	}
	
	/**
	 * Redirects the input and output stream to the client to establish a
	 * connection with the host. This method does not close the previously
	 * opened reader and writer.
	 * 
	 * @param in new online reader
	 * @param out new online writer
	 */
	public static void connectStreams(BufferedReader in, BufferedWriter out) {
		environment.reader = in;
		environment.writer = out;
	}
	
	/**
	 * Redirects the input and output stream to standard input and output.
	 * This method does not close the previously opened reader and writer.
	 */
	public static void disconnectStreams() {
		environment.reader = new BufferedReader(new InputStreamReader(System.in));
		environment.writer = new BufferedWriter(new OutputStreamWriter(System.out));
	}
	
	/**
	 * An environment implemented. Both reader and writer are implemented to
	 * work with the standard input and output. The initial home path is
	 * determined by the running path of the program.
	 *
	 * @author dinomario10
	 */
	public static class EnvironmentImpl implements Environment {
		
		/** A reader that reads from the standard input */
		private BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		/** A writer that writes on the standard output */
		private BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));
		/** Path where the program was ran */
		private Path homePath = Paths.get(".").normalize().toAbsolutePath();
		/** Current path of the user positioning */
		private Path currentPath = homePath;
		
		@Override
		public Path getHomePath() {
			return homePath;
		}
		
		@Override
		public Path getCurrentPath() {
			return currentPath.toAbsolutePath();
		}
		
		@Override
		public void setCurrentPath(Path path) {
			currentPath = path;
			writeln("Current directory is now set to " + currentPath);
		}
		
		@Override
		public String readLine() {
			String line = null;
			try {
				line = reader.readLine();
			} catch (IOException e) {}
			return line;
		}
		
		@Override
		public void write(String s){
			try {
				writer.write(s);
				writer.flush();
			} catch (IOException e) {}
		}
		
		@Override
		public void write(char cbuf[], int off, int len){
			try {
				writer.write(cbuf, off, len);
				writer.flush();
			} catch (IOException e) {}
		}
		
		@Override
		public void writeln(String s) {
			write(s);
			try {
				writer.newLine();
				writer.flush();
			} catch (IOException e) {}
		}
		
		@Override
		public Iterable<ShellCommand> commands() {
			return commands.values()
				.stream()
				.sorted((cmd1, cmd2) -> cmd1.getCommandName().compareTo(cmd2.getCommandName()))
				.collect(Collectors.toList());
		}
	}
	
}
