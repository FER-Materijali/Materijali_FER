package hr.fer.oop.lab6.threading;

import java.util.NoSuchElementException;
import java.util.concurrent.BlockingQueue;

import hr.fer.oop.lab6.common.iface.Consumer;
import hr.fer.oop.lab6.common.iface.OutputMessage;

/**
 * Implements the interface {@link Runnable} and is representing a work of one
 * {@link Thread} which is performing a work of one {@link Consumer}. The {@link
 * ConsumerThread} is synchronized by the {@link BlockingQueue} of {@link
 * OutputMessage OutputMessages} with other {@link ProcessingThread
 * ProcessingThread}.
 * 
 * @author dinomario10
 */
public class ConsumerThread implements Runnable {

	/** The consumer */
	private Consumer consumer;
	/** A blocking thread-safe queue */
	private BlockingQueue<OutputMessage> queue;

	/**
	 * Instantiates a new consumer thread.
	 *
	 * @param consumer the consumer
	 * @param queue a blocking queue
	 */
	public ConsumerThread(Consumer consumer, BlockingQueue<OutputMessage> queue) {
		this.consumer = consumer;
		this.queue = queue;
	}

	@Override
	public void run() {
		while (true) {
			synchronized (consumer) {
				try {
					OutputMessage output = queue.remove();
					consumer.evaluate(output);
				} catch (NoSuchElementException e) {
				}
			}
		}
	}

}
