package hr.fer.oop.lab5.exams;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * A loader class for the sheet data.
 *
 * @author dinomario10
 */
public class SheetDataLoader {
	
	private static final String SPLITTER = "\\t";

	/**
	 * Constructs a new {@code SheetDataLoader} object.
	 */
	public SheetDataLoader() {
	}
	
	/**
	 * Loads all of the student's sheet data from a file with the given
	 * {@code path}. The data is then processed and returned as a {@code List}
	 * of {@linkplain SheetData}.
	 * 
	 * @param path path to the sheets file
	 * @return a list containing all of the student's sheet data
	 * @throws IOException if the file loads unsuccessfully
	 */
	public static List<SheetData> loadSheets(Path path) throws IOException {
		validateFile(path);
		
		File sheets = path.toFile();
		List<SheetData> list = new ArrayList<>();
		
		BufferedReader in = new BufferedReader(new FileReader(sheets));
		String line;
		while ((line = in.readLine()) != null) {
			List<String> temp = Arrays.asList(line.split(SPLITTER));
			String jmbag = temp.get(0);
			String group = temp.get(1);
			List<String> answers = temp.subList(2, temp.size());
			
			SheetData sd = new SheetData(jmbag, group, answers);
			list.add(sd);
		}
		in.close();
		
		return list;
	}
	
	/**
	 * Loads all the correct answers from a file with the given {@code path}.
	 * The data is then processed and returned as a {@code Map}, the key being
	 * the group of the exam and the value being an array of correct answers.
	 * 
	 * @param path path to the correct answers file
	 * @return a map containing a group with its correct answers
	 * @throws IOException if the file loads unsuccessfully
	 */
	public static Map<String, String[]> loadCorrectAnswers(Path path) throws IOException {
		validateFile(path);
		
		File answersFile = path.toFile();
		Map<String, String[]> map = new HashMap<>();
		
		BufferedReader in = new BufferedReader(new FileReader(answersFile));
		String line;
		while ((line = in.readLine()) != null) {
			String[] temp = line.split(SPLITTER);
			String group = temp[0];
			String[] answers = Arrays.copyOfRange(temp, 1, temp.length);
			
			map.put(group, answers);
		}
		in.close();
		
		return map;
	}
	
	/**
	 * Validates the path argument by testing if it leads to an existing file.
	 * Throws an exception if the path cannot be resolved.
	 * 
	 * @param path a path
	 * @throws NullPointerException if the path is set to {@code null}
	 * @throws FileNotFoundException if the file is not found
	 */
	private static void validateFile(Path path) throws FileNotFoundException {
		if (path == null) {
			throw new NullPointerException("Path must not be null.");
		}
		
		File file = path.toFile();
		if (!file.exists()) {
			throw new FileNotFoundException("File " + file + " not found.");
		}
	}

}
