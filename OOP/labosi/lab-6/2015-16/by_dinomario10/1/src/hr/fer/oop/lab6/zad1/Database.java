package hr.fer.oop.lab6.zad1;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

/**
 * A loader class used for loading the student table, the course table and the
 * enrollment table. Data is loaded from files that contain the specified data.
 *
 * @author dinomario10
 */
public class Database {
	
	/** Path to the student data file */
	private static final String STUDENT_DATA = "studenti.txt";
	/** Path to the course data file */
	private static final String COURSE_DATA = "predmeti.txt";
	/** Path to the enrollment data file */
	private static final String ENROLLMENT_DATA = "UpisaniPredmeti.txt";

	/**
	 * Returns the student data table loaded from the {@link
	 * Database#STUDENT_DATA student data file}.
	 * 
	 * @return the student data table loaded from the student data file
	 * @throws FileNotFoundException if the file is not found
	 * @throws MalformedLineError in case of detecting a malformed line in file
	 */
	public static StudentTable getStudentTable() throws FileNotFoundException {
		List<Line> lines = new ArrayList<>();
		
		try (Scanner sc = new Scanner(new File(STUDENT_DATA), "UTF-8")) {
			while (sc.hasNextLine()) {
				Line line = new Line(sc.nextLine());
				lines.add(line);
			}
		} catch (FileNotFoundException e) {
			throw new FileNotFoundException("File " + STUDENT_DATA + " not found.");
		}

		StudentTable table = new StudentTable();
		for (Line line : lines) {
			try {
				List<String> args = line.getArgs();
				String jmbag = args.get(0);
				String lastName = args.get(1);
				String firstName = args.get(2);
				Integer finalGrade = Integer.parseInt(args.get(3));
				StudentRecord record = new StudentRecord(jmbag, lastName, firstName, finalGrade);
				table.add(record);
			} catch (Exception e) {
				throw new MalformedLineError("Malformed line in " + STUDENT_DATA + ": " + line);
			}
		}
		
		return table;
	}

	/**
	 * Returns the course data table loaded from the {@link
	 * Database#COURSE_DATA course data file}.
	 * 
	 * @return the course data table loaded from the course data file
	 * @throws FileNotFoundException if the file is not found
	 * @throws MalformedLineError in case of detecting a malformed line in file
	 */
	public static CourseTable getCourseTable() throws FileNotFoundException {
		List<Line> lines = new ArrayList<>();
		
		try (Scanner sc = new Scanner(new File(COURSE_DATA), "UTF-8")) {
			while (sc.hasNextLine()) {
				Line line = new Line(sc.nextLine());
				lines.add(line);
			}
		} catch (FileNotFoundException e) {
			throw new FileNotFoundException("File " + COURSE_DATA + " not found.");
		}
		
		CourseTable table = new CourseTable();
		for (Line line : lines) {
			try {
				List<String> args = line.getArgs();
				String courseID = args.get(0);
				String courseName = args.get(1);
				CourseRecord record = new CourseRecord(courseID, courseName);
				table.add(record);
			} catch (Exception e) {
				throw new MalformedLineError("Malformed line in " + COURSE_DATA + ": " + line);
			}
			
		}
		
		return table;
	}

	/**
	 * Returns the enrollment data table loaded from the {@link
	 * Database#ENROLLMENT_DATA enrollment data file}.
	 * 
	 * @return the enrollment data table loaded from the enrollment data file
	 * @throws FileNotFoundException if the file is not found
	 * @throws MalformedLineError in case of detecting a malformed line in file
	 */
	public static EnrollmentTable getEnrollmentTable() throws FileNotFoundException {
		List<Line> lines = new ArrayList<>();
		
		try (Scanner sc = new Scanner(new File(ENROLLMENT_DATA), "UTF-8")) {
			while (sc.hasNextLine()) {
				Line line = new Line(sc.nextLine());
				lines.add(line);
			}
		} catch (FileNotFoundException e) {
			throw new FileNotFoundException("File " + ENROLLMENT_DATA + " not found.");
		}

		EnrollmentTable table = new EnrollmentTable();
		for (Line line : lines) {
			try {
				List<String> args = line.getArgs();
				String courseID = args.get(0);
				String studentJMBAG = args.get(1);
				Integer grade = Integer.parseInt(args.get(2));
				EnrollmentRecord record = new EnrollmentRecord(courseID, studentJMBAG, grade);
				table.add(record);
			} catch (Exception e) {
				throw new MalformedLineError("Malformed line in " + ENROLLMENT_DATA + ": " + line);
			}
		}
		
		return table;
	}
	
	/**
	 * Represents a line read from a file.
	 * @author dinomario10
	 */
	private static class Line {
		/** Line text */
		private String text;
		/** Line column splitter */
		private static final String SPLITTER = "\\t";
		
		/**
		 * Constructs a new Line object.
		 * @param text line text
		 */
		public Line(String text) {
			this.text = text;
		}
		
		/**
		 * Splits the line text on columns and returns a {@linkplain List} of
		 * separated arguments.
		 * @return a List of separated arguments
		 */
		public List<String> getArgs() {
			return Arrays.asList(text.split(SPLITTER));
		}
		
		@Override
		public String toString() {
			return text.replace('\t', ' ');
		}
	}

}
