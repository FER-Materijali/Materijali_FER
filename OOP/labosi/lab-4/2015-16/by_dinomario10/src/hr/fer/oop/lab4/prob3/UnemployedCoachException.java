package hr.fer.oop.lab4.prob3;

/**
 * Exception that is thrown if an unemployed coach tries to manage a team.
 * An unemployed coach is a coach that doesn't have a team to manage.
 * 
 * @author dinomario10
 */
public class UnemployedCoachException extends RuntimeException {
	
	/**
     * Constructs a {@code UnemployedCoachException} with no
     * detail message and no cause.
     */
    public UnemployedCoachException() {
        super();
    }
    
    /**
     * Constructs a {@code UnemployedCoachException} with the
     * specified detail message.
     *
     * @param message the detail message.
     */
    public UnemployedCoachException(String message) {
        super(message);
    }
    
    /**
     * Constructs a {@code UnemployedCoachException} with the
     * specified detail message and cause.
     * 
	 * @param message the detail message
	 * @param cause the cause
	 */
	public UnemployedCoachException(String message, Throwable cause) {
		super(message, cause);
	}

	/**
	 * Constructs a {@code UnemployedCoachException} with the
     * specified cause.
	 * 
	 * @param cause the cause
	 */
	public UnemployedCoachException(Throwable cause) {
		super(cause);
	}
    
    private static final long serialVersionUID = 8152418717152031639L;
}
