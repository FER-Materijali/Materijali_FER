package hr.fer.oop.lab5.exams;

/**
 * An enumeration that defines the status of an answer in a student's exam. This
 * enumeration contains a text value that is used in {@linkplain StatisticsCommand}.
 *
 * @author dinomario10
 */
public enum AnswerStatus {
	/**
	 * When the question is left unanswered.
	 */
	UNANSWERED("unanswered"),
	/**
	 * When the question is answered correctly.
	 */
	ANSWERED_CORRECT("answered correct"),
	/**
	 * When the question is answered incorrectly.
	 */
	ANSWERED_INCORRECT("answered incorrect");
	
	/** A textual description of the constant */
	private String text;
	
	/**
	 * Constructs a new enumeration constant with the pre-defined text value.
	 * @param text constant textual description
	 */
	AnswerStatus(String text) {
		this.text = text;
	}
	
	@Override
	public String toString() {
		return text;
	}
}
