package hr.fer.oop.lab6.zad1;

import java.util.Collection;
import java.util.Iterator;
import java.util.LinkedHashMap;
import java.util.Map;

/**
 * This class represents a table of course records stored in the database. It
 * acts as a list of all {@link CourseRecord CourseRecords} and is organized to
 * get course records in time complexity of O(1).
 *
 * @author dinomario10
 */
public class CourseTable implements Iterable<CourseRecord> {

	/** Map of courses */
	private Map<String, CourseRecord> courses;
	
	/**
	 * Constructs an initial course table object, with the courses map
	 * initialized.
	 */
	public CourseTable() {
		courses = new LinkedHashMap<>();
	}
	
	/**
	 * Returns the {@linkplain CourseRecord} to which the specified ID is
	 * assigned, or {@code null} if this table contains no mapping for the
	 * specified ID.
	 * 
	 * @param courseID course ID
	 * @return	the CourseRecord to which the specified ID is assigned, or
	 * 			null if this table does not contain the ID
	 */
	public CourseRecord findById(String courseID) {
		return courses.get(courseID);
	}
	
	/**
	 * Returns the {@linkplain CourseRecord} to which the specified partial
	 * course name belongs.
	 * <p>Note that if more than one course records with the same partial name
	 * exist, this method returns the first course record that it encounters.
	 * <p>If the searched name is not found, {@code null} is returned.
	 * 
	 * @param partialCourseName partial course name
	 * @return the CourseRecord to which the specified partial course name belongs
	 */
	public CourseRecord findByName(String partialCourseName) {
		partialCourseName = partialCourseName.toLowerCase();
		Collection<CourseRecord> col = courses.values();
		
		for (CourseRecord course : col) {
			String name = course.getCourseName().toLowerCase();
			if (name.contains(partialCourseName)) {
				return course;
			}
		}
		
		return null;
	}
	
	/**
	 * Adds a course record to the table. Returns the previous value associated
	 * with this course record, or {@code null} if the previous value doesn't
	 * exist.
	 * 
	 * @param course course record
	 * @return the previous value associated with this course record
	 */
	public CourseRecord add(CourseRecord course) {
		return courses.put(course.getCourseID(), course);
	}
	
	/**
	 * Removes a course record from the table. Returns the value previously
	 * associated with this course record, or {@code null} if the table
	 * contained no mapping for the course.
	 * 
	 * @param course course record
	 * @return the previous value associated with this course record
	 */
	public CourseRecord remove(CourseRecord course) {
		return courses.remove(course.getCourseID());
	}
	
	@Override
	public String toString() {
		return courses.toString();
	}

	@Override
	public int hashCode() {
		return courses.hashCode();
	}
	
	@Override
	public boolean equals(Object obj) {
		return courses.equals(obj);
	}
	
	/**
	 * Returns an iterator over the elements in this table.
	 * 
	 * @return an iterator over the elements in this table
	 */
	@Override
	public Iterator<CourseRecord> iterator() {
        return courses.values().iterator();
    }

}
