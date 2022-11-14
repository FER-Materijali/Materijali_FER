package hr.fer.oop.lab5.exams;

/**
 * This command sets the active data sheets back to the previous one. This is
 * useful if a {@link FilterCommand filtering function} has gone wrong.
 *
 * @author dinomario10
 */
public class UndoCommand extends AbstractCommand {

	/**
	 * Constructs a new command object of type {@code UndoCommand}.
	 */
	public UndoCommand() {
		super("UNDO");
	}

	@Override
	public void execute(ExamData data, String arg) {
		data.setActive(data.getPrevious());
		System.out.format("There are %d sheets left in the active sheet collection.%n",
				data.getActive().size()
		);
	}

}
