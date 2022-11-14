package hr.fer.oop.lab6.common.console;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.PrintStream;
import java.util.HashSet;
import java.util.Set;
import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.BlockingQueue;

import hr.fer.oop.lab6.common.iface.Consumer;
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
 * Demonstrates the use of {@link GeneratorThread}, {@link ProcessingThread},
 * {@link ConsumerThread}, {@link RandomStringGenerator}, {@link MD5Digester},
 * {@link SuffixCheck}, {@link Counter}, {@link Statistics} and {@link
 * CompositeConsumer}.
 * 
 * @author dinomario10
 */
public class FinalDemonstration {

	/** Queue size */
	private static final int QUEUE_SIZE = 5;
	/** Number of generators */
	private static final int NO_GENERATORS = 2;
	/** Number of processors */
	private static final int NO_PROCESSORS = 5;
	/** Number of consumers */
	private static final int NO_CONSUMERS = 1;
	/** A print stream */
	private static final PrintStream OUT = System.out;

	/**
	 * Instances the new {@link GeneratorThread}, {@link ProcessingThread},
	 * {@link ConsumerThread}, {@link RandomStringGenerator}, {@link
	 * MD5Digester}, {@link SuffixCheck}, {@link Counter}, {@link Statistics}
	 * and {@link CompositeConsumer}. Synchronizes them with two {@link
	 * BlockingQueue BlockingQueues}.
	 *
	 * @param args the arguments
	 * @throws IOException if an I/O exception has occurred
	 */
	public static void main(String[] args) throws IOException {
		File results = new File("results.txt");
		results.createNewFile();
		FileOutputStream stream = new FileOutputStream(results);
		PrintStream ps = new PrintStream(stream);

		BlockingQueue<InputMessage> inputQueue = new ArrayBlockingQueue<>(QUEUE_SIZE);
		BlockingQueue<OutputMessage> outputQueue = new ArrayBlockingQueue<>(QUEUE_SIZE);

		Set<Consumer> consumers = new HashSet<>();
		consumers.add(new Counter(500000, OUT));
		consumers.add(new Statistics(800000, OUT));
		consumers.add(new SuffixCheck(new byte[] { (byte) 0xFE, (byte) 0xFF }, ps));

		Generator generator = new RandomStringGenerator();
		Processor processor = new MD5Digester();
		Consumer consumer = new CompositeConsumer(consumers);
		
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