package hr.fer.oop.lab5.exams;

import java.util.Collection;

/**
 * This command is used for printing text to the standard output only. From the
 * active data sheets, it prints out the number of active sheets, and then for
 * every student sheet, the student's ID, exam group, all of the answers and
 * total score that the student achieved on this exam, is printed in a sorted
 * order.
 *
 * @author dinomario10
 */
public class PrintCommand extends AbstractCommand {

	/**
	 * Constructs a new command object of type {@code PrintCommand}.
	 */
	public PrintCommand() {
		super("PRINT");
	}

	@Override
	public void execute(ExamData data, String arg) {
		Collection<SheetData> active = data.getActive();
		
		if (isNull(active))
			return;
		
		System.out.println(" Number of sheets: " + active.size());
		System.out.println();
		
		active.stream()
			.sorted()
			.forEach(System.out::println);
	}

}
