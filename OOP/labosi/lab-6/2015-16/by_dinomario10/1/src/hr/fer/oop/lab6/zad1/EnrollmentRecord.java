package hr.fer.oop.lab6.zad1;

import java.util.Objects;

/**
 * This class represents records for individual enrollments.
 *
 * @author dinomario10
 */
public class EnrollmentRecord {

	/** Course ID */
	private String courseID;
	/** Student's JMBAG */
	private String studentJMBAG;
	/** Student's grade */
	private Integer grade;
	
	/**
	 * Constructs a new enrollment record object with the given course ID,
	 * student's JMBAG and student's grade.
	 * 
	 * @param courseID course ID
	 * @param studentJMBAG student's JMBAG
	 * @param grade student's grade
	 */
	public EnrollmentRecord(String courseID, String studentJMBAG, Integer grade) {
		super();
		Objects.requireNonNull(courseID, "Course ID must not be null.");
		Objects.requireNonNull(studentJMBAG, "Student's JMBAG must not be null.");
		this.courseID = courseID;
		this.studentJMBAG = studentJMBAG;
		this.grade = grade;
	}
	
	/**
	 * Constructs a new enrollment record object with the given course ID and
	 * student's JMBAG. This constructor sets the grade initially to zero.
	 * 
	 * @param courseID course ID
	 * @param studentJMBAG student's JMBAG
	 */
	public EnrollmentRecord(String courseID, String studentJMBAG) {
		this(courseID, studentJMBAG, 0);
	}

	/**
	 * Returns the course ID.
	 * 
	 * @return the course ID
	 */
	public String getCourseID() {
		return courseID;
	}

	/**
	 * Returns the student's JMBAG.
	 * 
	 * @return the student's JMBAG
	 */
	public String getStudentJMBAG() {
		return studentJMBAG;
	}

	/**
	 * Returns the student's grade.
	 * 
	 * @return the student's grade
	 */
	public Integer getGrade() {
		return grade;
	}
	
	/**
	 * Sets the student's grade.
	 * 
	 * @param grade student's grade
	 */
	public void setGrade(Integer grade) {
		this.grade = grade;
	}
	
	@Override
	public String toString() {
		return courseID + " " + studentJMBAG + ": " + grade;
	}

	@Override
	public int hashCode() {
		final int prime = 31;
		int result = 1;
		result = prime * result + courseID.hashCode();
		result = prime * result + studentJMBAG.hashCode();
		return result;
	}

	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (!(obj instanceof EnrollmentRecord))
			return false;
		EnrollmentRecord other = (EnrollmentRecord) obj;
		if (!courseID.equals(other.courseID))
			return false;
		if (!studentJMBAG.equals(other.studentJMBAG))
			return false;
		return true;
	}

}
