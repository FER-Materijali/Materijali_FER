package hr.fer.oop.lab5.exams;

import java.util.ArrayList;
import java.util.Collection;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.OptionalDouble;
import java.util.stream.Collectors;

/**
 * This command considers only the active sheet data. It calculates and prints
 * out exam statistics onto the standard output. Statistics are consisted of:<br>
 * <ul>
 * <li>the average score of all graded sheets
 * <li>the number of students that answered correctly on a certain task
 * <li>the number of students that answered incorrectly on a certain task
 * <li>the number of students that did not provide an answer on a certain task
 * <li>the average score of all graded sheets for each group
 * </ul>
 *
 * @author dinomario10
 */
public class StatisticsCommand extends AbstractCommand {
	
	/**
	 * Constructs a new command object of type {@code StatisticsCommand}.
	 */
	public StatisticsCommand() {
		super("STATISTICS");
	}

	@Override
	public void execute(ExamData data, String arg) {
		Collection<SheetData> active = data.getActive();
		
		if (isNull(active))
			return;
		
		if (printAverageScore(active) == false) {
			return;
		} else {
			active = active.stream()
					.filter(dat -> dat.getTotalScore().isPresent())
					.collect(Collectors.toList());
		}
		
		System.out.println();
		printStatusStats(active);
		
		printScoresByGroup(active);
	}

	/**
	 * Calculates and returns the score data of all graded active sheets. Notice
	 * that ungraded sheets have no total score so these sheets are not
	 * considered while calculating the average score.
	 * 
	 * @param active active collection of sheet data
	 * @return the score data of all graded active sheets
	 */
	private static ScoreData calculateScoreData(Collection<SheetData> active) {
		double totalScore = 0d;
		int count = 0;
		
		for (SheetData sheet : active) {
			OptionalDouble od = sheet.getTotalScore();
			if (od.isPresent()) {
				totalScore += od.getAsDouble();
				count++;
			}
		}
		
		return new ScoreData(totalScore, count);
	}
	
	/**
	 * Returns a {@linkplain List}, that represents a list of questions, each
	 * containing a {@linkplain Map} of the achieved {@linkplain AnswerStatus}
	 * and the number of students that achieved that answer status.
	 * 
	 * @param active active collection of sheet data
	 * @return a list, each containing a map of the achieved answer status and
	 * 		   the number of students that achieved that answer status
	 */
	private static List<Map<AnswerStatus, Integer>> getStats(Collection<SheetData> active) {		
		List<Map<AnswerStatus, Integer>> list = new ArrayList<>();
		
		int noAnswers = active.stream().findAny().get().getAnswers().size();
		
		for (int i = 0; i < noAnswers; i++) {
			list.add(getTaskStatuses(active, i));
		}
		
		return list;
	}
	
	/**
	 * Returns a {@linkplain Map} of the achieved {@linkplain AnswerStatus} and
	 * the number of students that achieved that answer status for a specified
	 * {@code taskNum} by going through all the active data sheets and counting
	 * the number answers for that {@code taskNum}.
	 * 
	 * @param active active collection of sheet data
	 * @param taskNum task number
	 * @return a map of the achieved answer status and the number of students
	 * 		   that achieved that answer status for a specified {@code taskNum}
	 */
	private static Map<AnswerStatus, Integer> getTaskStatuses(Collection<SheetData> active, int taskNum) {
		Map<AnswerStatus, Integer> map = new HashMap<>();
		
		for (SheetData sheet : active) {
			AnswerScore ansScore = sheet.getAnswerScores().get(taskNum);
			AnswerStatus ansStatus = ansScore.getStatus();
			map.compute(ansStatus, (key, value) -> value==null ? 1 : value+1);
		}
		
		return map;
	}
	
	/**
	 * Prints the average score based on the given param {@code scoreData}.
	 * Average score is calculated by dividing the total score with the amount
	 * of graded sheets. Returns true if the average score has successfully been
	 * printed to the standard output. Returns false if the average score could
	 * not be calculated.
	 * 
	 * @param active active collection of sheet data
	 * @return true if the average score could be calculated, false otherwise
	 */
	protected static boolean printAverageScore(Collection<SheetData> active) {
		ScoreData scoreData = calculateScoreData(active);
		
		if (scoreData.count != 0) {
			double averageScore = scoreData.totalScore / scoreData.count;
			System.out.format("Average score of %d sheets: %f%n", scoreData.count, averageScore);
			return true;
		} else {
			System.out.println("Could not calculate statistics - all active sheets are ungraded.");
			return false;
		}
	}
	
	/**
	 * Prints the {@linkplain AnswerStatus} statistics of each task in the
	 * active collection of sheet data.
	 * 
	 * @param active active collection of sheet data
	 */
	private static void printStatusStats(Collection<SheetData> active) {
		List<Map<AnswerStatus, Integer>> stats = getStats(active);
		int i = 1;
		for (Map<AnswerStatus, Integer> mapElem : stats) {
			System.out.println(i + ". task:");
			mapElem.entrySet()
				.stream()
				.forEach(entry -> System.out.format("   %d %s%n",
									entry.getValue(),
									entry.getKey()
				));
			i++;
		}
		System.out.println();
	}
	
	/**
	 * Prints the average score of each group. Average score is calculated by
	 * dividing the total score with the amount of graded sheets, for each
	 * specific group.
	 * 
	 * @param active active collection of sheet data
	 */
	private static void printScoresByGroup(Collection<SheetData> active) {
		Map<String, List<SheetData>> map = active.stream()
				.collect(Collectors.groupingBy(SheetData::getGroup));
		
		map.forEach((key, value) -> {
			ScoreData scoreData = calculateScoreData(value);
			double averageScore = scoreData.totalScore / scoreData.count;
			System.out.format("Average score of %d sheets of group %s: %f%n",
					scoreData.count, key, averageScore);
		});
	}
	
	/**
	 * A private class used for retrieving score data. Used upon executing the
	 * {@linkplain StatisticsCommand}, when calculating the average score.
	 *
	 * @author dinomario10
	 */
	private static class ScoreData {
		
		/** Total score of all graded active sheets */
		private double totalScore;
		/** Amount of graded active sheets */
		private int count;
		
		/**
		 * Constructs a new {@code ScoreData} object.
		 * 
		 * @param totalScore total score of all graded active sheets
		 * @param count amount of graded active sheets
		 */
		public ScoreData(double totalScore, int count) {
			this.totalScore = totalScore;
			this.count = count;
		}
	}

}
