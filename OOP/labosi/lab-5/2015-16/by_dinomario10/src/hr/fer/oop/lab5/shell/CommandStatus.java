package hr.fer.oop.lab5.shell;

/**
 * An enumeration that names the procedure that should be followed after a
 * certain command is executed. Although most commands should return
 * {@link CommandStatus#CONTINUE CONTINUE} on successful executing, an
 * {@link CommandStatus#EXIT EXIT} command status should be considered upon
 * encountering a critical error in executing.
 * 
 * @author dinomario10
 */
public enum CommandStatus {
	/**
	 * Continue running the Shell and accepting new commands.
	 */
	CONTINUE,
	/**
	 * Exit upon executing the last command.
	 */
	EXIT
}
