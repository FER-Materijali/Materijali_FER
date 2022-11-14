package hr.fer.oop.topic10.db;

import hr.fer.oop.topic10.db.model.StudentDatabase;
import hr.fer.oop.topic10.db.model.StudentRecord;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.List;

/**
 * Main class that handles queries over {@link StudentDatabase} given through <code>database.txt</code> file.
 * 
 * @author Filip Hrenić
 * @version 1.0
 */
public class StudentDB {

	/**
	 * Used database for storing student records
	 */
	private static StudentDatabase database;

	/**
	 * Main method that is called when the program is started.
	 * 
	 * @param args don't matter
	 * @throws IOException when there's a problem with reading a file, or with
	 *             queries
	 */
	public static void main(String[] args) throws IOException {

		// opening a new reader
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in, StandardCharsets.UTF_8));
		// getting a list of strings from "database.txt" file
		List<String> rows = Files.readAllLines(Paths.get("./database.txt"), StandardCharsets.UTF_8);

		database = new StudentDatabase(rows);

		while (true) {
			System.out.print("> ");
			String line = in.readLine();
			if (line == null) {
				continue;
			}
			if (line.isEmpty()) {
				continue;
			}
			/*
			 * We transform the line into a format we can work with. First we
			 * remove trailing spaces. Then we replace '=' with ' = ' so we
			 * eliminate lastName="name" case. Then we replace all "big spaces"
			 * (a lot of spaces together) with only one space Then we split the
			 * formatted string with made spaces
			 */
			String[] keywords = line.trim().replaceAll("=", " = ").replaceAll("\\s+", " ").split(" ");

			if (keywords[0].equalsIgnoreCase("quit")) {
				break;
			} else if (keywords[0].equalsIgnoreCase("query")) {
				query(keywords);
			} else {
				System.out.println("Unknown command: " + keywords[0]);
			}
		}
	}

	/**
	 * This method is called when user wants to query the database.
	 * 
	 * @param keywords keywords given by user
	 */
	private static void query(String[] keywords) {
		if (keywords.length < 2) {
			System.out.println("Wrong command syntax.");
			return;
		}

		if (keywords[1].equalsIgnoreCase("lastname")) {
			lastname(keywords);
		} else if (keywords[1].equalsIgnoreCase("jmbag")) {
			jmbag(keywords);
		} else {
			System.out.println("Unkwnon command: " + keywords[1]);
		}
	}

	/**
	 * This method is called when user want to query the database by last names.
	 * 
	 * @param keywords keywords given by user
	 */
	private static void lastname(String[] keywords) {
		if (keywords.length < 4) {
			System.out.println("Wrong command syntax.");
			return;
		}

		if (!keywords[2].equals("=")) {
			System.out.println("Unknown command syntax.");
			return;
		}

		String filter = keywords[3].replaceAll("\"", ""); // remove " signs
		LastNameFilter lnf = new LastNameFilter(filter); // create a filter
		List<StudentRecord> list = database.filter(lnf); // create a list of filtered records
		print(list);
	}

	/**
	 * This method is called when user want to query the database by given jmbag.
	 * 
	 * @param keywords keywords given by user
	 */
	private static void jmbag(String[] keywords) {
		if (keywords.length < 4) {
			System.out.println("Wrong command syntax.");
			return;
		}

		if (!keywords[2].equals("=")) {
			System.out.println("Unknown command syntax.");
			return;
		}

		StudentRecord student = database.forJMBAG(keywords[3].replaceAll("\"", "")); // remove " signs
		if (student != null) {
			List<StudentRecord> list = new ArrayList<>();
			list.add(student);
			print(list);
		} else {
			System.out.println("Records selected: 0");
		}

	}

	/**
	 * This method is used for formatting the output.
	 * It prints a list of students in a table format + how many records were selected.
	 * 
	 * @param list list of students to print
	 */
	private static void print(List<StudentRecord> list) {

		int[] lenghts = { 0, 0, 0, 0 };
		for (StudentRecord student : list) {
			lenghts[0] = Math.max(lenghts[0], student.getJmbag().length());
			lenghts[1] = Math.max(lenghts[1], student.getLastName().length());
			lenghts[2] = Math.max(lenghts[2], student.getFirstName().length());
			lenghts[3] = Math.max(lenghts[3], student.getFinalGrade().length());
		}

		printFirstOrLastLine(lenghts);
		for (StudentRecord student : list) {
			StringBuilder forPrint = new StringBuilder();
			forPrint.append("|");
			forPrint.append(String.format(" %-" + lenghts[0] + "s |", student.getJmbag()));
			forPrint.append(String.format(" %-" + lenghts[1] + "s |", student.getLastName()));
			forPrint.append(String.format(" %-" + lenghts[2] + "s |", student.getFirstName()));
			forPrint.append(String.format(" %-" + lenghts[3] + "s |", student.getFinalGrade()));
			System.out.println(forPrint);
		}
		printFirstOrLastLine(lenghts);
		System.out.println("Records selected: " + list.size());
	}

	/**
	 * A helper method used for printing header and footer of the output table.
	 * ie. "+===+======+=======+======+", based on lengths from the parameter
	 * 
	 * @param lenghts parameters that determine the width of each column
	 */
	private static void printFirstOrLastLine(int[] lenghts) {
		System.out.print('+');
		for (Integer len : lenghts) {
			for (int i = 0; i < len + 2; i++) {
				System.out.print('=');
			}
			System.out.print('+');
		}
		System.out.print('\n');
	}

}
