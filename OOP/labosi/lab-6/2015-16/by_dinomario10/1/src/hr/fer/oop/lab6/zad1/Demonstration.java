package hr.fer.oop.lab6.zad1;

import java.io.FileNotFoundException;
import java.util.Collection;

/**
 * A demonstration of task 1.
 *
 * @author dinomario10
 */
public class Demonstration {
	
	/** Table of student records */
	private static StudentTable studentTable;
	/** Table of course records */
	private static CourseTable courseTable;
	/** Table of enrollment records */
	private static EnrollmentTable enrollmentTable;

	public static void main(String[] args) throws FileNotFoundException {
		/* Initialize tables */
		studentTable = Database.getStudentTable();
		courseTable = Database.getCourseTable();
		enrollmentTable = Database.getEnrollmentTable();
		
		/* Print students */
		printStudents();
		System.out.println();
		
		/* Print courses of one student */
		String student = "6873004907";
		printStudentCourses(student);
		System.out.println();
		
		/* Creating a new course */
		CourseRecord newCourse = new CourseRecord("5", "Osnove kori?tenja programskog jezika Java");
		courseTable.add(newCourse);
		
		/* Enrollment of a new course */
		enrollmentTable.newCourse("5", student);
		
		/* Setting the grade */
		setCourseGrade(student, "5", 5);
		
		/* Removing the enrollment */
		enrollmentTable.deleteRecord("4", student);
		
		printStudentCourses(student);
		System.out.println();
	}
	
	/**
	 * Prints all the students onto the standard output. This method prints out
	 * student's JMBAG, last and first name and the student's final grade.
	 */
	private static void printStudents() {
		for (StudentRecord record : studentTable) {
			System.out.println(record.getJmbag() + " " + record + ": " + record.getFinalGrade());
		}
	}
	
	/**
	 * Prints out all the courses that the given student has enrolled.
	 * 
	 * @param student student's JMBAG
	 */
	private static void printStudentCourses(String student) {
		Collection<EnrollmentRecord> byStudent = enrollmentTable.findByStudent(student);
		
		System.out.println("Courses of student " + student + ":");
		for (EnrollmentRecord record : byStudent) {
			CourseRecord course = courseTable.findById(record.getCourseID());
			System.out.println("  " + course.getCourseName() + ", grade: " + record.getGrade());
		}
	}
	
	/**
	 * Sets the student's course grade with the given params.
	 * 
	 * @param student student's JMBAG
	 * @param courseID course ID
	 * @param grade grade to be set
	 */
	private static void setCourseGrade(String student, String courseID, Integer grade) {
		EnrollmentRecord record = enrollmentTable.findByCourseAndStudent(courseID, student);
		record.setGrade(grade);
		enrollmentTable.updateEnrollment(record);
	}

}
