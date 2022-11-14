package hr.fer.oop.topic10.db.model;

import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.List;

/**
 * This class is responsible of reading in all files and supplying all of the
 * tables
 * 
 * @author Filip
 * 
 */
public class Database {

	private static final String STUDENT_FILE = "database.txt";
	private static final String COURSE_FILE = "predmeti.txt";
	private static final String ENROLMENT_FILE = "upisaniPredmeti.txt";

	/**
	 * Simulation of some simple work with database
	 * 
	 * @param args
	 */
	public static void main(String[] args) {

		Database dbase = Database.getDefault();
		EnrollmentDatabase e = dbase.getEnrolmentTable();
		CourseDatabase c = dbase.getCourseTable();
		StudentDatabase s = dbase.getStudentTable();

		System.out.println(s.forJMBAG("0000000005"));
		System.out.println(c.findById("1"));

		String jmbag = "0000000002";
		System.out.println("\nIspisujem upisane predmete studenta s jmbagom " + jmbag);
		for (EnrollmentRecord er : e.findByStudent(jmbag)) {
			System.out.println(er);
		}

		c.addCourse("Random course");

		String jmbag2 = "0000000005";
		String id2 = "4";
		String grade = "5";
		EnrollmentRecord er2 = new EnrollmentRecord(id2, jmbag2, grade);
		e.newCourse(jmbag2, id2);
		e.updateEnrolment(er2);

		System.out.println("\nIspisujem enrolmente od studenta s jmbagom " + jmbag2);
		for (EnrollmentRecord er : e.findByStudent(jmbag2)) {
			System.out.println(er);
		}

		e.deleteEnrolment(jmbag2, id2);
		System.out.println("\nSad sam mu obrisao taj upis pa bi se nebi trebalo ispisati ništa.");
		for (EnrollmentRecord er : e.findByStudent(jmbag2)) {
			System.out.println(er);
		}

	}

	private CourseDatabase cdbase;
	private EnrollmentDatabase edbase;
	private StudentDatabase sdbase;

	/**
	 * Returns a default database for this lab.
	 * 
	 * @return default database
	 */
	public static Database getDefault() {
		return new Database(STUDENT_FILE, COURSE_FILE, ENROLMENT_FILE);
	}

	/**
	 * Creates a new database with students, courses and enrolments tables
	 * 
	 * @param student path to the students file
	 * @param course path to the courses file
	 * @param enrolment path to the enrolments file
	 */
	public Database(String student, String course, String enrolment) {
		cdbase = new CourseDatabase(f(course));
		edbase = new EnrollmentDatabase(f(enrolment));
		sdbase = new StudentDatabase(f(student));
	}

	/**
	 * Reads all strings from a given file into a list
	 * 
	 * @param s path to a file
	 * @return list of rows from file
	 */
	private List<String> f(String s) {
		try {
			return Files.readAllLines(Paths.get(s), StandardCharsets.UTF_8);
		} catch (IOException e) {
			System.err.println("Something wrong with input file " + s + ".");
			e.printStackTrace();
		}
		return null;
	}

	/**
	 * 
	 * @return students database
	 */
	public StudentDatabase getStudentTable() {
		return sdbase;
	}

	/**
	 * 
	 * @return courses database
	 */
	public CourseDatabase getCourseTable() {
		return cdbase;
	}

	/**
	 * 
	 * @return enrolments database
	 */
	public EnrollmentDatabase getEnrolmentTable() {
		return edbase;
	}

}
