package hr.fer.oop.lab3.topic1.shell;

import hr.fer.oop.lab3.topic1.SimpleHashtable;
import hr.fer.oop.lab3.topic1.SimpleHashtable.TableEntry;
import hr.fer.oop.lab3.topic1.shell.commands.CdCommand;
import hr.fer.oop.lab3.topic1.shell.commands.CopyCommand;
import hr.fer.oop.lab3.topic1.shell.commands.DirCommand;
import hr.fer.oop.lab3.topic1.shell.commands.FilterCommand;
import hr.fer.oop.lab3.topic1.shell.commands.HelpCommand;
import hr.fer.oop.lab3.topic1.shell.commands.QuitCommand;
import hr.fer.oop.lab3.topic1.shell.commands.TerminalCommand;
import hr.fer.oop.lab3.topic1.shell.commands.TypeCommand;
import hr.fer.oop.lab3.topic1.shell.commands.XcopyCommand;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.nio.charset.StandardCharsets;
import java.util.Iterator;

/**
 * Class that represents a shell (like Bash, or cmd)
 * 
 * @author Filip
 *
 */
public class MyShell {

	/**
	 * Table of available commands
	 */
	private static SimpleHashtable<String, ShellCommand> commands;

	static {
		commands = new SimpleHashtable<>();
		ShellCommand[] cc = { new HelpCommand(), 
				new QuitCommand(),
				new CdCommand(), 
				new TerminalCommand(),
				new TypeCommand(), 
				new FilterCommand(), 
				new CopyCommand(),
				new XcopyCommand(), 
				new DirCommand() };
		for (ShellCommand c : cc) {
			commands.put(c.getCommandName(), c);
		}
	
		
	}

	/**
	 * Environment in which shell is run
	 */
	private static Environment environment = new EnvironmentImpl();

	/**
	 * Main method that runs the shell
	 */
	public static void main(String[] args) throws IOException {
		environment.writeln("Welcome to MyShell! You may enter commands.");
		String prompt;

		while (true) {
			prompt = getPrompt();
			environment.write(prompt);
			String line = environment.readLine().trim();
			if (line.isEmpty()) {
				continue;
			}

			String cmd, arg;
			int space = line.indexOf(' ');
			if (space == -1) {
				cmd = line;
				arg = "";
			} else {
				cmd = line.substring(0, space);
				arg = line.substring(space + 1);
			}

			ShellCommand shellCommand = (ShellCommand) commands.get(cmd);
			if (shellCommand == null) {
				environment.writeln("Unknown command!");
				continue;
			}
			if (shellCommand.execute(environment, arg) == CommandStatus.Exit) {
				break;
			}
		}
		environment.writeln("Thank you for using this shell. Goodbye!");
	}

	/**
	 * Returns the prompt to write
	 * 
	 * @return prompt
	 */
	private static String getPrompt() {
		Terminal t = environment.getActiveTerminal();
		return Integer.toString(t.getId()) + "$" + t.getCurrentPath() + "> ";
	}

	/**
	 * An implementation of the {@link Environment} interface.
	 * 
	 * @author Filip
	 *
	 */
	public static class EnvironmentImpl implements Environment {

		private SimpleHashtable<Integer, Terminal> terminals;
		private Terminal activeTerminal;
		private BufferedReader reader;
		private BufferedWriter writer;

		public EnvironmentImpl() {
			terminals = new SimpleHashtable<>();
			activeTerminal = new Terminal(1);
			terminals.put(1, activeTerminal);
			reader = new BufferedReader(new InputStreamReader(System.in, StandardCharsets.UTF_8));
			writer = new BufferedWriter(new OutputStreamWriter(System.out, StandardCharsets.UTF_8));
		}

		@Override
		public String readLine() {
			String line;
			try {
				line = reader.readLine();
			} catch (IOException e) {
				line = "Error while reading from input stream.";
			}
			return line;
		}

		@Override
		public void write(String s) {
			try {
				writer.write(s);
				writer.flush();
			} catch (IOException e) {
				throw new RuntimeException("Error while writing to output stream.", e);
			}
		}

		@Override
		public void writeln(String s) {
			write(s + "\n");
		}

		@Override
		public Terminal getActiveTerminal() {
			return activeTerminal;
		}

		@Override
		public void setActiveTerminal(Terminal t) {
			activeTerminal = t;
		}

		@Override
		public Terminal getOrCreateTerminal(int id) {
			Terminal t = terminals.get(id);
			if (t != null) {
				return t;
			}
			t = new Terminal(id);
			terminals.put(id, t);
			return t;
		}

		@Override
		public Terminal[] listTerminals() {
			Terminal[] ts = new Terminal[terminals.size()];
			int i = 0;
			for (Terminal t : terminals.values()) {
				ts[i++] = t;
			}
			return ts;
		}

		@Override
		public Iterable<ShellCommand> commands() {
			return new Iterable<ShellCommand>() {

				@Override
				public Iterator<ShellCommand> iterator() {
					return new Iterator<ShellCommand>() {

						Iterator<TableEntry<String, ShellCommand>> i = commands.iterator();

						@Override
						public boolean hasNext() {
							return i.hasNext();
						}

						@Override
						public ShellCommand next() {
							return i.next().getValue();
						}

						@Override
						public void remove() {
							i.remove();
						}
					};
				}
			};
		}

	}

}
