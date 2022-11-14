package hr.fer.oop.lab6.threading;

import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.BlockingQueue;

import hr.fer.oop.lab6.common.console.SuffixCheck;
import hr.fer.oop.lab6.common.iface.Consumer;
import hr.fer.oop.lab6.common.iface.Generator;
import hr.fer.oop.lab6.common.iface.InputMessage;
import hr.fer.oop.lab6.common.iface.OutputMessage;
import hr.fer.oop.lab6.common.iface.Processor;
import hr.fer.oop.lab6.common.impl.MD5Digester;
import hr.fer.oop.lab6.common.impl.RandomStringGenerator;

/**
 * Demonstrates the use of {@link GeneratorThread}, {@link ProcessingThread} and
 * {@link ConsumerThread} synchronized with {@link BlockingQueue BlockingQueues}.
 * 
 * @author dinomario10
 */
public class ParallelHashSearch {
	
	/** Queue size */
	private static final int QUEUE_SIZE = 5;
	/** Number of generators */
	private static final int NO_GENERATORS = 1;
	/** Number of processors */
	private static final int NO_PROCESSORS = 5;
	/** Number of consumers */
	private static final int NO_CONSUMERS = 1;

	/**
	 * The main method.
	 *
	 * @param args not used
	 */
	public static void main(String[] args) {
		BlockingQueue<InputMessage> inputQueue = new ArrayBlockingQueue<>(QUEUE_SIZE, true);
		BlockingQueue<OutputMessage> outputQueue = new ArrayBlockingQueue<>(QUEUE_SIZE, true);
		Generator generator = new RandomStringGenerator();
		Processor processor = new MD5Digester();
		Consumer consumer = new SuffixCheck(new byte[] { (byte) 0xFE, (byte) 0xFF }, System.out);
		
		for (int i = 0; i < NO_GENERATORS; i++) {
			new Thread(new GeneratorThread(generator, inputQueue)).start();
		}
		for (int i = 0; i < NO_PROCESSORS; i++) {
			new Thread(new ProcessingThread(processor, inputQueue, outputQueue)).start();
		}
		for (int i = 0; i < NO_CONSUMERS; i++) {
			new Thread(new ConsumerThread(consumer, outputQueue)).start();
		}
	}

}
