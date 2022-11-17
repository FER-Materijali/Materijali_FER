import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.nio.charset.Charset;
import java.nio.charset.StandardCharsets;
import java.nio.file.FileSystems;
import java.nio.file.FileVisitResult;
import java.nio.file.FileVisitor;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.PathMatcher;
import java.nio.file.Paths;
import java.nio.file.attribute.BasicFileAttributes;
import java.util.ArrayList;
import java.util.List;
import java.util.Objects;

public class Evaluator {
	
	
	private static class ProgramEvaluator implements FileVisitor<Path> {
		
		private final Path program;
		
		private List<String> actual;
		private List<String> expected;
					
		private boolean in = false;
		private boolean out = false;
		
		private int hits = 0;
		private int overall = 0;
		
		private final boolean verbose;
		
		ProgramEvaluator(Path program, boolean verbose) {
			this.verbose = verbose;
			this.program = Objects.requireNonNull(program);
		}

		@Override
		public FileVisitResult preVisitDirectory(Path dir, BasicFileAttributes attrs) throws IOException {
			return FileVisitResult.CONTINUE;
		}

		@Override
		public FileVisitResult visitFile(Path file, BasicFileAttributes attrs) throws IOException {
			if (isInFile(file)) {
				actual = run(program, file);
				
				in = true;
				out = false;
			}
			
			if (isOutFile(file)) {
				expected = Files.readAllLines(file, CS);
				
				out = true;
			}
			
			if (in && out) {
				overall ++;
				
				String result = "incorrect";
				
				if (actual.equals(expected)) {
					hits ++;
					result = "correct";
				}
				
				if (verbose) {
					System.out.println(file.getParent().getFileName() + ": " + result);
					System.out.println("Actual: " + actual);
					System.out.println("Expected: " + expected + System.lineSeparator());
				}
			}
			
			return FileVisitResult.CONTINUE;
		}

		@Override
		public FileVisitResult visitFileFailed(Path file, IOException exc) throws IOException {
			return FileVisitResult.CONTINUE;
		}

		@Override
		public FileVisitResult postVisitDirectory(Path dir, IOException exc) throws IOException {
			return FileVisitResult.CONTINUE;
		}
		
		int getHits() {
			return hits;
		}
		
		int getOverall() {
			return overall;
		}
	}
	
	/**
	 * Default encoding.
	 */
	private static final Charset CS = StandardCharsets.UTF_8;
	
	/**
	 * Matches any .java file.
	 */
	private static final PathMatcher javaMatcher = FileSystems.getDefault().getPathMatcher("glob:**.java");
	
	/**
	 * Matches any .in file.
	 */
	private static final PathMatcher inMatcher = FileSystems.getDefault().getPathMatcher("glob:**.in");
	
	/**
	 * Matches any .out file.
	 */
	private static final PathMatcher outMatcher = FileSystems.getDefault().getPathMatcher("glob:**.out");
		
	/**
	 * Program entry point. Obtains the path to the .java file as a command line argument.
	 * 
	 * @param args Two arguments from the command line: path to the .java file and root folder with test cases.
	 * @throws Exception 
	 */
	public static void main(String[] args) throws Exception {
		if (args.length != 2 && args.length != 3) {
			throw new IllegalArgumentException(
					String.format("Expected atleast two arguments from the command line: %s and %s.", 
							"path to the .java file", "test cases root folder"));
		}
		
		Path program = null;
		Path tests = null;
		boolean verbose = false;
		
		if (args.length == 2) {
			program = Paths.get(args[0]);
			tests = Paths.get(args[1]);
		}
		
		if (args.length == 3) {
			if (!args[0].equals("-v") && !args[0].equals("--verbose")) {
				throw new IllegalArgumentException("First of the three arguments should be -v. This argument is optional.");
			}
			verbose = true;
			program = Paths.get(args[1]);
			tests = Paths.get(args[2]);
		}
		
		if (!javaMatcher.matches(program)) {
			throw new IllegalArgumentException(
					String.format("File %s is not a valid java file.", program));
		}
		
		// compile a program
		compile(program);
		
		// run the evaluator
		evaluate(program, tests, verbose);
	}
	
	private static void evaluate(Path program, Path tests, boolean verbose) {
		System.out.println("Evaluating the program ...");
		
		ProgramEvaluator eval = new ProgramEvaluator(program, verbose);
		
		try {
			Files.walkFileTree(tests, eval);
			System.out.println(String.format("Evaluation of %s: %d/%d hits.", 
					program.getFileName(), eval.getHits(), eval.getOverall()));
			
		} catch (IOException e) {
			System.err.println("Error reading test cases. Terminating ...");
			System.exit(-1);
		}
	}
	
	/**
	 * Compiles a program.
	 * 
	 * @throws Exception
	 */
	private static void compile(Path program) {
		System.out.println("Compiling the program ...");

		try {
			Process p = Runtime.getRuntime().exec("javac " + program);

			output(p.getInputStream());
			output(p.getErrorStream());
			p.waitFor();
		} catch (IOException | InterruptedException e) {
			throw new IllegalStateException("Error compiling the program!", e);
		}
		
		System.out.println("Program successfully compiled!" + System.lineSeparator());
	}
	
	/**
	 * Runs a program.
	 * 
	 * @throws Exception
	 */
	private static List<String> run(Path program, Path test) {	
		try {			
			Process p = Runtime.getRuntime().exec(new String[]{
					"/bin/bash", 
					"-c", 
					"java -cp " + program.getParent() + " " + getProgramName(program.getFileName()) + " < " + test.toString()});
			
			List<String> lines = output(p.getInputStream());
			p.waitFor();
			
			return lines;
			
		} catch (IOException | InterruptedException e) {
			throw new IllegalStateException("Error running the program!", e);
		}	
	}

	private static List<String> output(InputStream in) throws IOException {		
		BufferedReader reader = new BufferedReader(new InputStreamReader(in, CS));	
		List<String> lines = new ArrayList<>();
		
		for (String line = reader.readLine(); line != null; line = reader.readLine()) {
			lines.add(line);
		}
		
		return lines;
	}
	
	private static String getProgramName(Path path) {
		return path.toString().replace(".java", "");
	}
	
	private static boolean isInFile(Path path) {
		return inMatcher.matches(path);
	}
	
	private static boolean isOutFile(Path path) {
		return outMatcher.matches(path);
	}
}
