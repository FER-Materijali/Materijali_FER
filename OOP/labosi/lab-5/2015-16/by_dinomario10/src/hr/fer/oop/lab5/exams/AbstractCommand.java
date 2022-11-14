package hr.fer.oop.lab5.exams;

import java.util.Collection;

/**
 * Used as a superclass for other, usable commands.
 * 
 * @author dinomario10
 */
public abstract class AbstractCommand {
	
	/** Name of the command */
	private String commandName;
	
	/** Represents a blank answer */
	protected static final String BLANK = "BLANK";

	/**
	 * Generates a new command of a type extending {@code AbstractCommand}.
	 * 
	 * @param commandName name of the command
	 */
	public AbstractCommand(String commandName) {
		super();
		this.commandName = commandName;
	}

	/**
	 * Returns the name of the command.
	 * 
	 * @return the name of the command
	 */
	public String getCommandName() {
		return commandName;
	}
	
	/**
	 * Executes the given Shell command. Every shell command has its own unique
	 * way of executing. Arguments may or may not exist (String has a valid
	 * value or {@code null}).
	 * 
	 * @param data exam data
	 * @param arg argument
	 */
	public abstract void execute(ExamData data, String arg);
	
	/**
	 * For most of the commands to work, the active collection of sheet data
	 * needs to be {@code non-null}. The subclasses extending this class must
	 * have a way to check if the active collection of sheet data is loaded, and
	 * if not, notice the user that he must load the neccessary files. Returns
	 * true if the active collection of sheet data <b>is</b> {@code null}. False
	 * otherwise.
	 * 
	 * @param active active collection of sheet data
	 * @return true if the active collection of sheet data <b>is</b> {@code null}.
	 * 		   False otherwise.
	 */
	protected static boolean isNull(Collection<SheetData> active) {
		if (active == null) {
			System.out.println("Sheet data needs to be loaded first!");
			return true;
		}
		
		return false;
	}
	
}
