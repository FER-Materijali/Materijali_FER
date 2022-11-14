package hr.fer.oop.lab4.prob4;

/**
 * Exception that is thrown when a match is not playable. The match is not
 * playable if it doesn't meet the following criteria:
 * <ul>
 * <li>Teams must be set (home and away)
 * <li>Match type must be set
 * <li>If match type is {@code COMPETITIVE}, both teams must be of same type
 * (two club teams or two national teams)
 * <li>Teams must be ready for the match (isMatchReady() must be true)
 * </ul>
 * 
 * @author dinomario10
 */
public class NotPlayableMatchException extends Exception {

	/**
     * Constructs a {@code NotEligiblePlayerException} with no
     * detail message and no cause.
     */
    public NotPlayableMatchException() {
        super();
    }
    
    /**
     * Constructs a {@code NotEligiblePlayerException} with the
     * specified detail message.
     *
     * @param message the detail message
     */
    public NotPlayableMatchException(String message) {
        super(message);
    }
    
    /**
     * Constructs a {@code NotEligiblePlayerException} with the
     * specified detail message and cause.
     * 
	 * @param message the detail message
	 * @param cause the cause
	 */
	public NotPlayableMatchException(String message, Throwable cause) {
		super(message, cause);
	}

	/**
	 * Constructs a {@code NotEligiblePlayerException} with the
     * specified cause.
	 * 
	 * @param cause the cause
	 */
	public NotPlayableMatchException(Throwable cause) {
		super(cause);
	}
    
    private static final long serialVersionUID = 6924996625626226179L;
}
