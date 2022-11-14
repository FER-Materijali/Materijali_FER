package hr.fer.oop.lab5.exams;

import java.io.IOException;
import java.nio.file.InvalidPathException;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.NoSuchElementException;
import java.util.OptionalDouble;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 * A heavy command that does most of the work. Upon executing, this command
 * extracts five arguments from the input:
 * <ul>
 * <li>the student sheets file path
 * <li>the answers file path
 * <li>number of points for every correct answer
 * <li>number of points for every incorrect answer
 * <li>number of points for every unanswered question
 * </ul>
 * For the loaded files to be usable, this command needs to procces all exams
 * and grade them.
 *
 * @author dinomario10
 */
public class LoadCommand extends AbstractCommand {

	/**
	 * Constructs a new command object of type {@code LoadCommand}.
	 */
	public LoadCommand() {
		super("LOAD");
	}

	@Override
	public void execute(ExamData data, String arg) {
		String[] args;
		try {
			args = extractArguments(arg);
		} catch (NullPointerException|NoSuchElementException e) {
			System.out.println("Please enter a valid number of arguments.");
			return;
		}
		
		Path sheetsPath;
		Path answersPath;
		try {
			sheetsPath = Paths.get(args[0]);
			answersPath = Paths.get(args[1]);
		} catch (InvalidPathException e) {
			System.out.println("Arguments #1 and #2 must be valid paths.");
			return;
		}
		
		double correct;
		double incorrect;
		double unanswered;
		try {
			correct = Double.parseDouble(args[2]);
			incorrect = Double.parseDouble(args[3]);
			unanswered = Double.parseDouble(args[4]);
		} catch (Exception e) {
			System.out.println("Arguments #3, #4 and #5 must be numbers.");
			return;
		}

		List<SheetData> sheets;
		Map<String, String[]> correctAnswers;
		try {
			sheets = SheetDataLoader.loadSheets(sheetsPath);
			correctAnswers = SheetDataLoader.loadCorrectAnswers(answersPath);
		} catch (IOException e) {
			System.out.println(e.getMessage());
			return;
		}
		
		processExams(data, sheets, correctAnswers, correct, incorrect, unanswered);
		StatisticsCommand.printAverageScore(data.getActive());
	}
	
	/**
	 * Used for extracting arguments passed to a load function. This method
	 * supports an unlimited number of arguments, and can be inputed either
	 * with quotation marks or not. Returns an array of strings containing the
	 * extracted arguments.
	 * 
	 * @param s a string containing arguments
	 * @return an array of strings containing extracted arguments.
	 */
	private static String[] extractArguments(String s) {
		List<String> list = new ArrayList<>();
		
		String regex = "\"([^\"]*)\"|(\\S+)";
		Matcher m = Pattern.compile(regex).matcher(s);
		while (m.find()) {
			if (m.group(1) != null) {
				list.add(m.group(1));
			} else {
				list.add(m.group(2));
			}
		}

		return list.toArray(new String[list.size()]);
	}
	
	/**
	 * Processes exams given by the {@code sheets} param by comparing their
	 * answers with the {@code correctAnswers} sheet. Upon comparing, the exam
	 * task may be given {@code correctPts} points for a correct answer,
	 * {@code incorrectPts} for an incorrect answer and {@code unansweredPts}
	 * for an unanswered question. This is then set as the initial sheet for
	 * {@code data}.
	 * 
	 * @param data exam data
	 * @param sheets student answer sheets
	 * @param correctAnswers correct answers sheet
	 * @param correctPts points given for a correct answer
	 * @param incorrectPts points given for an incorrect answer
	 * @param unansweredPts points given for an unanswered question
	 */
	private static void processExams(ExamData data, List<SheetData> sheets, Map<String, String[]> correctAnswers,
			double correctPts, double incorrectPts, double unansweredPts) {
		
		Map<String, SheetData> initial = new HashMap<>();
		
		for (SheetData sheet : sheets) {
			sheet = gradeExam(sheet, correctAnswers, correctPts, incorrectPts, unansweredPts);
			initial.put(sheet.getJmbag(), sheet);
		}
		
		data.setInitial(initial);
	}

	/**
	 * Grades an exam given by the {@code sheet} param by comparing its answers
	 * with the {@code correctAnswers} sheet. Upon comparing, the exam task may
	 * be given {@code correctPts} points for a correct answer,
	 * {@code incorrectPts} for an incorrect answer and {@code unansweredPts}
	 * for an unanswered question. If the group is unavailable, a message is
	 * printed out on the standard output and grading this sheet is not done.
	 * 
	 * @param sheet a student answer sheet
	 * @param correctAnswers correct answers sheet
	 * @param correctPts points given for a correct answer
	 * @param incorrectPts points given for an icorrect answer
	 * @param unansweredPts points given for an unanswered question
	 * @return a graded sheet data
	 */
	private static SheetData gradeExam(SheetData sheet, Map<String, String[]> correctAnswers,
			double correctPts, double incorrectPts, double unansweredPts) {
		String group = sheet.getGroup();
		
		List<AnswerScore> answerScores = new ArrayList<>();
		
		OptionalDouble optionalScore;
		if (group.equals(BLANK)) {
			System.out.println("Student " + sheet.getJmbag() + " did not mark his group.");
			optionalScore = OptionalDouble.empty();
		} else if (!correctAnswers.containsKey(group)) {
			System.out.println("Student " + sheet.getJmbag() + " marked a non-existent group: " + group);
			optionalScore = OptionalDouble.empty();
		} else {
			List<String> answers = sheet.getAnswers();
			String[] correct = correctAnswers.get(group);

			double totalScore = 0;
			for (int i = 0; i < correct.length; i++) {
				String answer = answers.get(i);
				if (answer.equals(BLANK)) {
					totalScore += unansweredPts;
					answerScores.add(new AnswerScore(unansweredPts, AnswerStatus.UNANSWERED));
				} else if (answer.equals(correct[i])) {
					totalScore += correctPts;
					answerScores.add(new AnswerScore(correctPts, AnswerStatus.ANSWERED_CORRECT));
				} else {
					totalScore += incorrectPts;
					answerScores.add(new AnswerScore(incorrectPts, AnswerStatus.ANSWERED_INCORRECT));
				}
			}
			optionalScore = OptionalDouble.of(totalScore);
		}
		
		sheet.setTotalScore(optionalScore);
		sheet.setAnswerScores(answerScores);
		return sheet;
	}

}
