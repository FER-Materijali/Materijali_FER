package hr.fer.oop.lab6.threading;

import java.util.NoSuchElementException;
import java.util.concurrent.BlockingQueue;

import hr.fer.oop.lab6.common.iface.InputMessage;
import hr.fer.oop.lab6.common.iface.OutputMessage;
import hr.fer.oop.lab6.common.iface.Processor;

/**
 * Implements the interface {@link Runnable} and is representing a work of one
 * {@link Thread} who is performing a work of one {@link Processor}. The {@link
 * ProcessingThread} is synchronized by two {@link BlockingQueue BlockingQueues}
 * - one of {@link InputMessage InputMessages} used for synchronizing with other
 * {@link GeneratorThread GeneratorThreads} and the second one of {@link
 * OutputMessage OutputMessages} for synchronization with other {@link
 * ConsumerThread ConsumerThreads}.
 * 
 * @author dinomario10
 */
public class ProcessingThread implements Runnable {

	/** The processor */
	private Processor processor;
	/** The input queue */
	private BlockingQueue<InputMessage> inputQueue;
	/** The output queue */
	private BlockingQueue<OutputMessage> outputQueue;

	/**
	 * Instantiates a new processing thread.
	 *
	 * @param processor the processor
	 * @param inputQueue the input queue
	 * @param outputQueue the output queue
	 */
	public ProcessingThread(Processor processor, BlockingQueue<InputMessage> inputQueue, BlockingQueue<OutputMessage> outputQueue) {
		this.processor = processor;
		this.inputQueue = inputQueue;
		this.outputQueue = outputQueue;
	}

	@Override
	public void run() {
		while (true) {
			synchronized (processor) {
				try {
					InputMessage message = inputQueue.remove();
					OutputMessage processedMessage = processor.process(message);
					outputQueue.add(processedMessage);
				} catch (NoSuchElementException | IllegalStateException e) {
				}
			}
		}
	}

}
