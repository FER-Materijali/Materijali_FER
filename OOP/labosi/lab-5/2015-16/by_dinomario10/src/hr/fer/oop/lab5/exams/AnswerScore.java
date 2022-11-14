package hr.fer.oop.lab5.exams;

/**
 * This class represents the answer status and the total score achieved that one
 * student achieved on one answer.
 *
 * @author dinomario10
 */
public class AnswerScore {
	
	/** Score achieved on this answer */
	private double score;
	/** This answer's status */
	private AnswerStatus status;

	/**
	 * Constructs a new AnswerScore object with its score variable set to zero
	 * and its status variable set to {@code null}.
	 */
	public AnswerScore() {
	}

	/**
	 * Constructs a new AnswerScore object with its variables set as desired.
	 * 
	 * @param score score achieved on this answer
	 * @param status this answer's status
	 */
	public AnswerScore(double score, AnswerStatus status) {
		super();
		this.score = score;
		this.status = status;
	}

	/**
	 * Returns the score achieved on this answer.
	 * 
	 * @return the score achieved on this answer
	 */
	public double getScore() {
		return score;
	}
	
	/**
	 * Sets the score achieved on this answer.
	 * 
	 * @param score score achieved on this answer
	 */
	public void setScore(double score) {
		this.score = score;
	}
	
	/**
	 * Returns this answer's status.
	 * 
	 * @return this answer's status
	 */
	public AnswerStatus getStatus() {
		return status;
	}

	/**
	 * Sets this answer's status.
	 * 
	 * @param status this answer's status
	 */
	public void setStatus(AnswerStatus status) {
		this.status = status;
	}
	
	

}
