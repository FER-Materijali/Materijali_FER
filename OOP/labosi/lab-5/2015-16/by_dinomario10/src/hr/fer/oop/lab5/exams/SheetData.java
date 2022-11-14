package hr.fer.oop.lab5.exams;

import java.util.List;
import java.util.OptionalDouble;

/**
 * This class represents all data for one student's exam. In order for an exam
 * to be graded, the group of the exam must not be {@code null}. If the group is
 * {@code null}, this exam is ignored while calculating statistics. For it to be
 * ignored, the student's {@link SheetData#totalScore total score} on this exam is
 * represented by {@linkplain OptionalDouble}.
 * 
 * @author dinomario10
 */
public class SheetData implements Comparable<SheetData> {

	/** Student's ID */
	private String jmbag;
	/** Group of the exam */
	private String group;
	/** List of student's answers */
	private List<String> answers;
	/** List of student's answer scores */
	private List<AnswerScore> answerScores;
	/** Student's total score on the exam. */
	private OptionalDouble totalScore = OptionalDouble.empty();
	
	/** Represents a blank answer */
	private static final String BLANK = "BLANK";
	
	/**
	 * Constructs a new SheetData object with its variables set as desired.
	 * 
	 * @param jmbag student's ID
	 * @param group the group of the exam
	 * @param answers list of student's answers
	 */
	public SheetData(String jmbag, String group, List<String> answers) {
		super();
		if (jmbag == null) {
			throw new IllegalArgumentException("Student's ID cannot be null.");
		}
		
		this.jmbag = jmbag;
		this.group = group;
		this.answers = answers;
	}
	
	/**
	 * Returns the student's ID.
	 * 
	 * @return the student's ID
	 */
	public String getJmbag() {
		return jmbag;
	}

	/**
	 * Returns the group of the exam.
	 * 
	 * @return the group of the exam
	 */
	public String getGroup() {
		return group;
	}
	
	/**
	 * Returns the list of student's answers.
	 * 
	 * @return the list of student's answers
	 */
	public List<String> getAnswers() {
		return answers;
	}

	/**
	 * Returns the list of student's answer scores.
	 * 
	 * @return the list of student's answer scores
	 */
	public List<AnswerScore> getAnswerScores() {
		return answerScores;
	}
	
	/**
	 * Sets the list of student's answer scores.
	 * 
	 * @param answerScores the list of student's answer scores
	 */
	public void setAnswerScores(List<AnswerScore> answerScores) {
		this.answerScores = answerScores;
	}
	
	/**
	 * Returns the student's total score on the exam.
	 * 
	 * @return the student's total score on the exam
	 */
	public OptionalDouble getTotalScore() {
		return totalScore;
	}

	/**
	 * Sets the student's total score on the exam.
	 * 
	 * @param totalScore the student's total score on the exam
	 */
	public void setTotalScore(OptionalDouble totalScore) {
		this.totalScore = totalScore;
	}

	@Override
	public String toString() {
		StringBuilder sb = new StringBuilder();
		sb	.append(jmbag)
			.append(", ")
			.append(group.equals(BLANK) ? "-" : group)
			.append(": [");
		
		for (String ans : answers) {
			if (ans.equals(BLANK))
				sb.append("- ");
			else
				sb.append(ans).append(" ");
		}
		
		int r = sb.lastIndexOf(" ");
		sb.replace(r, r+1, "]");
		
		sb.append(", total score: ");
		if (totalScore.isPresent())
			sb.append(totalScore.getAsDouble());
		else
			sb.append("Ungraded");
		
		return sb.toString();
	}

	@Override
	public int hashCode() {
		final int prime = 31;
		int result = 1;
		result = prime * result + jmbag.hashCode();
		return result;
	}

	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (!(obj instanceof SheetData))
			return false;
		SheetData other = (SheetData) obj;
		if (!jmbag.equals(other.jmbag))
			return false;
		return true;
	}

	@Override
	public int compareTo(SheetData other) {
		OptionalDouble od1 = this.getTotalScore();
		Double value1;
		if (od1.isPresent())
			value1 = od1.getAsDouble();
		else
			value1 = Double.NEGATIVE_INFINITY;
		
		OptionalDouble od2 = other.getTotalScore();
		Double value2;
		if (od2.isPresent())
			value2 = od2.getAsDouble();
		else
			value2 = Double.NEGATIVE_INFINITY;
		
		return -value1.compareTo(value2);
	}

}
