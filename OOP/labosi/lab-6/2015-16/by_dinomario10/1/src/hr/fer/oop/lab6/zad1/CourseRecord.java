package hr.fer.oop.lab6.zad1;

import java.util.Objects;

/**
 * This class represents records for individual courses.
 *
 * @author dinomario10
 */
public class CourseRecord {

	/** Course ID */
	private String courseID;
	/** Course name */
	private String courseName;
	
	/**
	 * Constructs a new course record object.
	 * 
	 * @param courseID course ID
	 * @param courseName course name
	 */
	public CourseRecord(String courseID, String courseName) {
		super();
		Objects.requireNonNull(courseID, "Course ID must not be null.");
		this.courseID = courseID;
		this.courseName = courseName;
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
	 * Returns the course name.
	 * 
	 * @return the course name
	 */
	public String getCourseName() {
		return courseName;
	}
	
	@Override
	public String toString() {
		return courseName;
	}

	@Override
	public int hashCode() {
		final int prime = 31;
		int result = 1;
		result = prime * result + courseID.hashCode();
		return result;
	}

	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (!(obj instanceof CourseRecord))
			return false;
		CourseRecord other = (CourseRecord) obj;
		if (!courseID.equals(other.courseID))
			return false;
		return true;
	}

}
