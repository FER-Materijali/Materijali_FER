package hr.fer.oop.lab5.shell;

import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Date;

/**
 * A simple command that is used for writing out the current date and time.
 *
 * @author dinomario10
 */
public class DateCommand extends AbstractCommand {

	/**
	 * Constructs a new command object of type {@code HelpCommand}.
	 */
	public DateCommand() {
		super("DATE", "Displays the current date.");
	}

	@Override
	public CommandStatus execute(Environment env, String s) {
		Date date = new Date();
		DateFormat df = new SimpleDateFormat("dd.MM.yyyy. HH:mm:ss");
		env.writeln(df.format(date));
		
		return CommandStatus.CONTINUE;
	}

}
