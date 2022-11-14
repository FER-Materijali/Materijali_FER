package hr.fer.oop.lab5.exams;

import java.util.List;
import java.util.Map;
import java.util.OptionalDouble;

/**
 * This command is used for printing text to the standard output only. If
 * student's ID is passed as an argument, this command tries to find the
 * specified ID in the initial data sheets and prints out formatted results for
 * the specified student's exam. If the given student ID does not exist, a
 * message is displayed.
 *
 * @author dinomario10
 */
public class StudentResultCommand extends AbstractCommand {

	/**
	 * Constructs a new command object of type {@code StudentResultCommand}.
	 */
	public StudentResultCommand() {
		super("STUDENT-RESULT");
	}

	@Override
	public void execute(ExamData data, String arg) {
		Map<String, SheetData> initial = data.getInitial();
		
		if (initial == null) {
			System.out.println("Sheet data needs to be loaded first!");
			return;
		}
		
		if (arg == null) {
			System.out.println("Please enter student's ID as an argument.");
			return;
		}
		
		String jmbag = arg.trim();
		
		SheetData studentSheet = initial.get(jmbag);
		if (studentSheet == null) {
			System.out.println("Student ID not found!");
		} else {
			printResult(studentSheet);
		}
	}

	/**
	 * Prints out results for a specified student.
	 * 
	 * @param sheet exam sheet
	 */
	private static void printResult(SheetData sheet) {
		OptionalDouble od = sheet.getTotalScore();
		
		System.out.println("Student ID: " + sheet.getJmbag());
		System.out.println("Total score: " + (od.isPresent() ? od.getAsDouble() : "ungraded"));
		System.out.println();
		
		if (od.isPresent()) {
			printAnswerScores(sheet);
		} else {
			printAnswers(sheet);
		}
	}
	
	/**
	 * Prints out answers for graded exam sheets.
	 * 
	 * @param sheet exam sheet
	 */
	private static void printAnswerScores(SheetData sheet) {
		List<String> answers = sheet.getAnswers();
		List<AnswerScore> answerScores = sheet.getAnswerScores();
		
		int i = 1;
		for (String ans : answers) {
			formatAnswer(i, ans);
			AnswerScore ansScore = answerScores.get(i-1);
			AnswerStatus ansStatus = ansScore.getStatus();
			switch (ansStatus) {
			case ANSWERED_CORRECT:
				System.out.print("(T)");
				break;
			case ANSWERED_INCORRECT:
				System.out.print("(N)");
				break;
			case UNANSWERED:
				System.out.print("(-)");
				break;
			}
			System.out.println(", score: " + ansScore.getScore());
			i++;
		}
	}
	
	/**
	 * Prints out answers for ungraded exam sheets.
	 * 
	 * @param sheet exam sheet
	 */
	private static void printAnswers(SheetData sheet) {
		List<String> answers = sheet.getAnswers();
		
		int i = 1;
		for (String ans : answers) {
			formatAnswer(i, ans);
			System.out.println();
			i++;
		}
	}
	
	/**
	 * Prints out a formatted answer, with the given task number.
	 * 
	 * @param i task number
	 * @param ans an answer
	 */
	private static void formatAnswer(int i, String ans) {
		System.out.format("%2d. %s ", i, (ans.equals(BLANK) ? "-" : ans));
	}

}
