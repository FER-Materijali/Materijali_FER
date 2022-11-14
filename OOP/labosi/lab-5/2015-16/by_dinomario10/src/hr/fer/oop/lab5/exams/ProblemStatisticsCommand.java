package hr.fer.oop.lab5.exams;

import java.util.ArrayList;
import java.util.Collection;
import java.util.Comparator;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.OptionalDouble;
import java.util.Map.Entry;

/**
 * Based on the active data sheets, this command calculates statistics for every
 * task and prints out the number of students that gave an answer to a certain
 * question, for every task and for every answer.
 *
 * @author dinomario10
 */
public class ProblemStatisticsCommand extends AbstractCommand {

	/**
	 * Constructs a new command object of type {@code ProblemStatisticsCommand}.
	 */
	public ProblemStatisticsCommand() {
		super("PROBLEM-STATISTICS");
	}

	@Override
	public void execute(ExamData data, String arg) {
		Collection<SheetData> active = data.getActive();
		
		if (isNull(active))
			return;
		if (countGradedSheets(active) == 0) {
			System.out.println("Could not calculate problem-statistics - all active sheets are ungraded.");
			return;
		}
		
		List<Map<String, Integer>> list = getProblemStatistics(active);
		printProblemStatistics(list);
	}
	
	/**
	 * Returns a {@linkplain List}, that represents a list of questions, each
	 * containing a {@linkplain Map} of the given answer and the number of
	 * students that gave that answer.
	 * 
	 * @param active active collection of sheet data
	 * @return a list, each containing a map of the given answer and the number
	 * 		   of students that gave that answer
	 */
	private static List<Map<String, Integer>> getProblemStatistics(Collection<SheetData> active) {		
		List<Map<String, Integer>> list = new ArrayList<>();
		
		int noAnswers = active.stream().findAny().get().getAnswers().size();
		
		for (int i = 0; i < noAnswers; i++) {
			list.add(getTaskAnswers(active, i));
		}
		
		return list;
	}
	
	/**
	 * Returns a {@linkplain Map} of the given answer and the number of students
	 * that gave that answer for a specified {@code taskNum} by going through
	 * all the active data sheets and counting the number answers for that
	 * {@code taskNum}.
	 * 
	 * @param active active collection of sheet data
	 * @param taskNum task number
	 * @return a map of the given answer and the number of students that gave that
	 * 		   answer for a specified {@code taskNum}
	 */
	private static Map<String, Integer> getTaskAnswers(Collection<SheetData> active, int taskNum) {
		Map<String, Integer> map = new HashMap<>();
		
		for (SheetData sheet : active) {
			String answer = sheet.getAnswers().get(taskNum);
			map.compute(answer, (key, value) -> value==null ? 1 : value+1);
		}
		
		return map;
	}
	
	/**
	 * Prints the task answers and the number of students that gave that answer.
	 * Works with the active collection sheet data.
	 * 
	 * @param tasks list of tasks with its answers and number of student answers
	 */
	private static void printProblemStatistics(List<Map<String, Integer>> tasks) {
		int i = 1;
		for (Map<String, Integer> task : tasks) {
			System.out.println(i + ". task:");
			task.entrySet()
				.stream()
				.sorted(new ProblemStatisticComparator())
				.forEach(entry -> System.out.format("   %s %d%n",
									entry.getKey().equals(BLANK) ? "-" : entry.getKey(),
									entry.getValue()
				));
			i++;
		}
	}
	
	/**
	 * Counts and returns the total number of graded sheets in the active sheet
	 * collection.
	 * 
	 * @param active active collection of sheet data
	 * @return the total number of graded sheets in the active sheet collection
	 */
	private static int countGradedSheets(Collection<SheetData> active) {
		int count = 0;
		
		for (SheetData sheet : active) {
			OptionalDouble od = sheet.getTotalScore();
			if (od.isPresent())
				count++;
		}
		
		return count;
	}
	
	/**
	 * A comparison function, which imposes a <i>total ordering</i> for problem
	 * statistics. This comparator is used to sort the task answers
	 * alphabetically, leaving the {@link AbstractCommand#BLANK BLANK} answer last.
	 *
	 * @author dinomario10
	 */
	private static class ProblemStatisticComparator implements Comparator<Map.Entry<String, Integer>> {

		@Override
		public int compare(Entry<String, Integer> e1, Entry<String, Integer> e2) {
			String eValue1 = e1.getKey();
			String eValue2 = e2.getKey();
			if (eValue1.equals(BLANK))
				return 1;
			else if (eValue2.equals(BLANK))
				return -1;
			else
				return eValue1.compareTo(eValue2);
		}
	}

}
