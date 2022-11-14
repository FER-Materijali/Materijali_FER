package hr.fer.oop.lab5.exams;

import java.util.Collection;
import java.util.InputMismatchException;
import java.util.OptionalDouble;
import java.util.Scanner;
import java.util.function.Predicate;
import java.util.stream.Collectors;

/**
 * A useful filtering command that allows multiple kinds of filtering. To date,
 * the kinds of filtering available are:
 * <ul>
 * <li>graded or ungraded sheets
 * <li>sheets whose group is X
 * <li>sheets whose score is lower than/greater than or equal to X
 * <li>sheets whose {@link AnswerStatus answer status} on task X is Y
 * <li>sheets whose answer on task X is Y
 * </ul>
 * Filtering is done by finding the correct student's sheets from the active
 * data sheets and removing all other sheets, leaving only the correct ones.
 *
 * @author dinomario10
 */
public class FilterCommand extends AbstractCommand {

	/**
	 * Constructs a new command object of type {@code FilterCommand}.
	 */
	public FilterCommand() {
		super("FILTER");
	}

	@Override
	public void execute(ExamData data, String arg) {
		if (isNull(data.getActive()))
			return;
		
		if (arg == null) {
			System.out.println("Please enter an argument.");
			return;
		}
		
		arg = arg.trim().toLowerCase();
		
		if (arg.contains("graded")) {
			graded(data, arg);
		} else if (arg.contains("group")) {
			group(data, arg);
		} else if (arg.contains("score")) {
			score(data, arg);
		} else if (arg.contains("status")) {
			status(data, arg);
		} else if (arg.contains("answer")) {
			answer(data, arg);
		} else {
			System.out.println("Unknown filter argument: " + arg);
			return;
		}
		
		System.out.format("There are %d sheets left in the active sheet collection.%n",
				data.getActive().size()
		);
	}
	
	/**
	 * Graded or ungraded sheets from the active data sheets are filtered.<br>
	 * Syntax:
	 * <ul>
	 * <li><b>filter graded</b>
	 * <li><b>filter !graded</b>
	 * </ul>
	 * 
	 * @param data exam data
	 * @param arg argument passed by the user
	 */
	private static void graded(ExamData data, String arg) {
		if (arg.equals("graded")) {
			filterAndSet(data, dat -> dat.getTotalScore().isPresent());
		} else if (arg.equals("!graded")) {
			filterAndSet(data, dat -> !dat.getTotalScore().isPresent());
		} else {
			printSyntaxError(arg);
		}
	}
	
	/**
	 * Sheets whose group is X are filtered.<br>
	 * Syntax:
	 * <ul>
	 * <li><b>filter group=X</b>
	 * </ul>
	 * 
	 * @param data exam data
	 * @param arg argument passed by the user
	 */
	private static void group(ExamData data, String arg) {
		int r = arg.indexOf('=');
		if (r >= 0) {
			String group = arg.substring(r+1).trim().toUpperCase();
			filterAndSet(data, dat -> dat.getGroup().equals(group));
		} else {
			printSyntaxError(arg);
		}
	}

	/**
	 * Sheets whose score is lower than/greater than or equal to X are filtered.<br>
	 * Syntax:
	 * <ul>
	 * <li><b>filter score&gt;=X</b>
	 * <li><b>filter score&lt;=X</b>
	 * </ul>
	 * 
	 * @param data exam data
	 * @param arg argument passed by the user
	 */
	private static void score(ExamData data, String arg) {
		int r = arg.indexOf('=');
		double score;
		try {
			score = Double.parseDouble(arg.substring(r+1));
		} catch(NumberFormatException|IndexOutOfBoundsException e) {
			System.out.println("Please enter a valid statement.");
			return;
		}
		
		if (arg.contains(">=")) {
			filterAndSet(data, dat -> {
				OptionalDouble od = dat.getTotalScore();
				return od.isPresent() && od.getAsDouble() >= score;
			});
		} else if (arg.contains("<=")) {
			filterAndSet(data, dat -> {
				OptionalDouble od = dat.getTotalScore();
				return od.isPresent() && od.getAsDouble() <= score;
			});
		} else {
			printSyntaxError(arg);
		}
	}

	/**
	 * Sheets whose {@link AnswerStatus answer status} on task X is Y are
	 * filtered.<br>
	 * Syntax:
	 * <ul>
	 * <li><b>filter status X Y</b>
	 * </ul>
	 * 
	 * @param data exam data
	 * @param arg argument passed by the user
	 */
	private static void status(ExamData data, String arg) {
		try(Scanner sc = new Scanner(arg)) {
			sc.next();
			int taskNum = sc.nextInt();
			String statusStr = sc.next().toUpperCase();
			
			AnswerStatus status;
			switch (statusStr) {
			case "CORRECT":
				status = AnswerStatus.ANSWERED_CORRECT;
				break;
			case "INCORRECT":
				status = AnswerStatus.ANSWERED_INCORRECT;
				break;
			case "UNANSWERED":
				status = AnswerStatus.UNANSWERED;
				break;
			default:
				printSyntaxError(arg);
				return;
			}
			
			graded(data, "graded");
			filterAndSet(data, dat -> dat.getAnswerScores().get(taskNum-1).getStatus().equals(status));
			
		} catch (NumberFormatException|InputMismatchException|IndexOutOfBoundsException e) {
			printSyntaxError(arg);
		}
	}

	/**
	 * Sheets whose answer on task X is Y are filtered.<br>
	 * Syntax:
	 * <ul>
	 * <li><b>filter answer X Y</b>
	 * </ul>
	 * 
	 * @param data exam data
	 * @param arg argument passed by the user
	 */
	private static void answer(ExamData data, String arg) {
		try(Scanner sc = new Scanner(arg)) {
			sc.next();
			int taskNum = sc.nextInt();
			String answer = sc.next().toUpperCase();
			
			filterAndSet(data, dat -> dat.getAnswers().get(taskNum-1).equals(answer));
			
		} catch (NumberFormatException|InputMismatchException|IndexOutOfBoundsException e) {
			printSyntaxError(arg);
		}
	}
	
	/**
	 * Filters out and sets the new active data sheets specified by the given
	 * filter.
	 * 
	 * @param data exam data
	 * @param predicate a predicate which is passed into a filter for elements
	 * 					to be kept
	 */
	private static void filterAndSet(ExamData data, Predicate<SheetData> predicate) {
		Collection<SheetData> col = data.getActive()
				.stream()
				.filter(predicate)
				.collect(Collectors.toList());
		data.setActive(col);
	}
	
	/**
	 * Prints out a syntax error for an invalid user input.
	 * 
	 * @param arg argument of the user input
	 */
	private static void printSyntaxError(String arg) {
		System.out.println("Invalid filter syntax: filter " + arg);
	}

}
