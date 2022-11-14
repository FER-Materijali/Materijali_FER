package hr.fer.oop.lab6.common.iface;

/**
 * Interface which describes {@link Consumer} who is receiving {@link
 * OutputMessage OutputMessages} and does something with them.<br>
 * 
 * Offers a method for evaluating a {@link OutputMessage}.
 * 
 * @author dinomario10
 */
public interface Consumer {

	/**
	 * Evaluates the output message.
	 *
	 * @param out the output message
	 */
	public void evaluate(OutputMessage out);

}
