package hr.fer.oop.lab5.exams;

/**
 * This command resets the active data sheets back to the initial (loaded) one.
 *
 * @author dinomario10
 */
public class ResetCommand extends AbstractCommand {

	/**
	 * Constructs a new command object of type {@code ResetCommand}.
	 */
	public ResetCommand() {
		super("RESET");
	}

	@Override
	public void execute(ExamData data, String arg) {
		data.setActive(data.getInitial().values());
		System.out.println("Active sheet data has been set to initial value.");
	}

}
