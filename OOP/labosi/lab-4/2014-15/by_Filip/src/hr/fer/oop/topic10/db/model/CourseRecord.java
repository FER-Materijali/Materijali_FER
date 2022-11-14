package hr.fer.oop.topic10.db.model;

/**
 * Course record has id and course name
 * 
 * @author Filip
 *
 */
public class CourseRecord extends AbstractRecord {

	/**
	 * Creates a new Course Record from a row from a file
	 * 
	 * @param row row from a file
	 */
	public CourseRecord(String row) {
		super(row);
	}

	/**
	 * New Course record with given parameters
	 * 
	 * @param courseId id
	 * @param courseName name
	 */
	public CourseRecord(String courseId, String courseName) {
		super(courseId, courseName);
	}

	/**
	 * 
	 * @return course id
	 */
	public String getCourseID() {
		return getElements()[0];
	}

	/**
	 * 
	 * @return course name
	 */
	public String getCourseName() {
		return getElements()[1];
	}

	@Override
	public String toString() {
		return getCourseName();
	}

}
