package hr.fer.oop.lab6.threading;

import java.util.concurrent.BlockingQueue;

import hr.fer.oop.lab6.common.iface.Generator;
import hr.fer.oop.lab6.common.iface.InputMessage;

/**
 * Implements the interface {@link Runnable} and represents the work of the
 * {@link Thread} which is performing the work of one {@link Generator}. The
 * {@link GeneratorThread}'s work is synchronized by the {@link BlockingQueue}
 * of {@link InputMessage InputMessages} with other {@link GeneratorThread
 * GeneratorThreads} and {@link ProcessingThread ProcessingThreads}.
 */
public class GeneratorThread implements Runnable {

	/** The generator */
	private Generator generator;
	/** A blocking thread-safe queue */
	private BlockingQueue<InputMessage> queue;

	/**
	 * Instantiates a new generator thread.
	 *
	 * @param generator the generator
	 * @param queue a blocking queue
	 */
	public GeneratorThread(Generator generator, BlockingQueue<InputMessage> queue) {
		this.generator = generator;
		this.queue = queue;
	}

	@Override
	public void run() {
		while (true) {
			synchronized (generator) {
				try {
					InputMessage message = generator.generateMessage();
					queue.add(message);
				} catch (IllegalStateException e) {
				}
			}
		}
	}

}
