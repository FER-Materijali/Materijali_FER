package hr.fer.oop.lab6.common.console;

import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.BlockingQueue;

import hr.fer.oop.lab6.common.iface.Generator;
import hr.fer.oop.lab6.common.iface.InputMessage;
import hr.fer.oop.lab6.common.iface.OutputMessage;
import hr.fer.oop.lab6.common.iface.Processor;
import hr.fer.oop.lab6.common.impl.MD5Digester;
import hr.fer.oop.lab6.common.impl.RandomStringGenerator;
import hr.fer.oop.lab6.threading.ConsumerThread;
import hr.fer.oop.lab6.threading.GeneratorThread;
import hr.fer.oop.lab6.threading.ProcessingThread;

/**
 * Demonstrates the use of {@link RandomStringGenerator}, {@link MD5Digester},
 * {@link Counter} and {@link Statistics}.
 * 
 * @author dinomario10
 */
public class HashCounter {
	
	/** Queue size */
	private static final int QUEUE_SIZE = 5;
	/** Number of generators */
	private static final int NO_GENERATORS = 1;
	/** Number of processors */
	private static final int NO_PROCESSORS = 5;
	/** Number of consumers */
//	private static final int NO_COUNTERS = 1;
	/** Number of statistics */
	private static final int NO_STATISTICS = 1;

	/**
	 * Instances a new {@link RandomStringGenerator}, {@link MD5Digester},
	 * {@link Counter} and {@link Statistics} and performs their work in an
	 * infinite loop.
	 * 
	 * @param args not used
	 */
	public static void main(String[] args) {
		BlockingQueue<InputMessage> inputQueue = new ArrayBlockingQueue<>(QUEUE_SIZE, true);
		BlockingQueue<OutputMessage> outputQueue = new ArrayBlockingQueue<>(QUEUE_SIZE, true);
		Generator generator = new RandomStringGenerator();
		Processor processor = new MD5Digester();
//		Consumer consumer = new Counter(100000, System.out);
		Statistics statistics = new Statistics(100000, System.out);
		
		for (int i = 0; i < NO_GENERATORS; i++) {
			new Thread(new GeneratorThread(generator, inputQueue)).start();
		}
		for (int i = 0; i < NO_PROCESSORS; i++) {
			new Thread(new ProcessingThread(processor, inputQueue, outputQueue)).start();
		}
//		for (int i = 0; i < NO_COUNTERS; i++) {
//			new Thread(new ConsumerThread(consumer, outputQueue)).start();
//		}
		for (int i = 0; i < NO_STATISTICS; i++) {
			new Thread(new ConsumerThread(statistics, outputQueue)).start();
		}
	}
}
