package hr.fer.oop.lab5.exams;

import java.util.Collection;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

/**
 * Operator, this is where the magic happens. Scans the user's input and
 * searches for a matching command. Some commands require arguments, so the user
 * must input them as well. If the inputed command is found, the command is
 * executed, otherwise an error message is displayed. If the user's input {@link
 * String#equals(Object) equals} "quit", the program stops and prints out a
 * goodbye message.
 *
 * @author dinomario10
 * @author Marko Cupic
 */
public class Operator {
	
	/** A map of commands */
	private static Map<String, AbstractCommand> commands;
	
	static {
		commands = new HashMap<>();
		AbstractCommand[] cmds = {
				new LoadCommand(),
				new FilterCommand(),
				new ResetCommand(),
				new StatisticsCommand(),
				new ProblemStatisticsCommand(),
				new StudentResultCommand(),
				new PrintCommand(),
				new UndoCommand()
		};
		for (AbstractCommand c : cmds) {
			commands.put(c.getCommandName(), c);
		}
	}
	
	/** An exam data environment, containing student sheets */
	private static ExamData data = new ExamDataImpl();
	
	/**
	 * Scans the user's input and searches for a matching command. Some commands
	 * require arguments, so the user must input them as well. If the inputed
	 * command is found, the command is executed, otherwise an error message is
	 * displayed. If the user's input {@link String#equals(Object) equals}
	 * "quit", the program stops and prints out a goodbye message.
	 * 
	 * @param args an array of {@code String} arguments
	 */
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("Welcome to the operator! You may enter commands.");
		
		while (true) {
			System.out.print("> ");
			
			String line = sc.nextLine().trim();
			if (line.equalsIgnoreCase("quit")) {
				break;
			}
			
			String cmd;
			String arg;
			int splitter = line.indexOf(' ');
			try {
				cmd = line.substring(0, splitter).toUpperCase();
				arg = line.substring(splitter+1).trim();
			} catch (StringIndexOutOfBoundsException e) {
				cmd = line.toUpperCase();
				arg = null;
			}
			
			AbstractCommand command = commands.get(cmd);
			if (command == null) {
				System.out.println("Unknown command!");
				System.out.println();
				continue;
			}
			command.execute(data, arg);
			System.out.println();
		}
		
		sc.close();
		System.out.println("Goodbye!");
	}
	
	/**
	 * An {@linkplain ExamData} implemented.
	 *
	 * @author dinomario10
	 */
	public static class ExamDataImpl implements ExamData {
		
		/** Initial collection of sheet data */
		private Map<String, SheetData> initial;
		/** Active collection of sheet data */
		private Collection<SheetData> active;
		/** Collection of sheet data before the last change */
		private Collection<SheetData> previous;

		@Override
		public Map<String, SheetData> getInitial() {
			return initial;
		}
		
		@Override
		public void setInitial(Map<String, SheetData> initial) {
			this.initial = initial;
			setActive(this.initial.values());
		}
		
		@Override
		public Collection<SheetData> getActive() {
			return active;
		}

		@Override
		public void setActive(Collection<SheetData> active) {
			previous = this.active;
			this.active = active;
		}
		
		@Override
		public Collection<SheetData> getPrevious() {
			return previous;
		}
	}
	
}
