package hr.fer.oop.lab4.prob2;

/**
 * Exception that is thrown when a player doesn't meet the needed criteria.
 * 
 * @author dinomario10
 */
public class NotEligiblePlayerException extends RuntimeException {
	
	/**
     * Constructs a {@code NotEligiblePlayerException} with no
     * detail message and no cause.
     */
    public NotEligiblePlayerException() {
        super();
    }
    
    /**
     * Constructs a {@code NotEligiblePlayerException} with the
     * specified detail message.
     *
     * @param message the detail message.
     */
    public NotEligiblePlayerException(String message) {
        super(message);
    }
    
    /**
     * Constructs a {@code NotEligiblePlayerException} with the
     * specified detail message and cause.
     * 
	 * @param message the detail message
	 * @param cause the cause
	 */
	public NotEligiblePlayerException(String message, Throwable cause) {
		super(message, cause);
	}

	/**
	 * Constructs a {@code NotEligiblePlayerException} with the
     * specified cause.
	 * 
	 * @param cause the cause
	 */
	public NotEligiblePlayerException(Throwable cause) {
		super(cause);
	}
    
    private static final long serialVersionUID = 1081160708067188704L;
}
