package hr.fer.oop.lab6.common.console;

import java.util.Set;

import hr.fer.oop.lab6.common.iface.Consumer;
import hr.fer.oop.lab6.common.iface.OutputMessage;

/**
 * Implements the interface {@link Consumer}, so it is a {@link Consumer} who
 * has other {@link Consumer} components and is starting them one at the time.
 * 
 * @author dinomario10
 */
public class CompositeConsumer implements Consumer {

	/** The consumers. */
	private Set<Consumer> consumers;

	/**
	 * Instantiates a new composite consumer.
	 *
	 * @param consumers the consumers
	 */
	public CompositeConsumer(Set<Consumer> consumers) {
		this.consumers = consumers;
	}

	
	@Override
	public void evaluate(OutputMessage out) {
		for (Consumer c : consumers) {
			out.reset();
			c.evaluate(out);
		}
	}
}