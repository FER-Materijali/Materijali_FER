package hr.fer.oop.lab6.common.iface;

/**
 * Interface which describes {@link Processor} who is receiving {@link
 * InputMessage}s, and generates a new {@link OutputMessage} based on the
 * content of received {@link InputMessage}.<br>
 * 
 * Offers a method for generating new {@link OutputMessage}.
 * 
 * @author dinomario10
 */
public interface Processor {

	/**
	 * Processes a given {@link InputMessage} and generates a new {@link
	 * OutputMessage} based on the content of the received {@link InputMessage}.
	 * 
	 * @param in input message
	 * @return the output message
	 */
	public OutputMessage process(InputMessage in);

}
