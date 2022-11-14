package hr.fer.oop.lab6.common.iface;

/**
 * Interface which describes a {@link Generator} which is producing {@link
 * InputMessage InputMessages} of some kind.<br>
 * 
 * Offers method for generating the new {@link InputMessage}.
 * 
 * @author dinomario10
 */
public interface Generator {

	/**
	 * Generates the input message.
	 *
	 * @return a generated message
	 */
	public InputMessage generateMessage();
	
}
