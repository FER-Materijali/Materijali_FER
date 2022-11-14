package hr.fer.oop.lab6.zad1;

import java.util.Collection;
import java.util.HashSet;
import java.util.Iterator;
import java.util.LinkedHashMap;
import java.util.Map;
import java.util.function.Predicate;

/**
 * This class represents a table of enrollment records stored in the database.
 * It acts as a list of all {@link EnrollmentRecord EnrollmentRecords} and is
 * organized to get enrollment records in time complexity of O(1).
 *
 * @author dinomario10
 */
public class EnrollmentTable implements Iterable<EnrollmentRecord> {

	/** Map of enrollments, containing a multiple key */
	private Map<Keys, EnrollmentRecord> enrollments;
	
	/**
	 * Constructs an initial enrollment table object, with the enrollments map
	 * initialized.
	 */
	public EnrollmentTable() {
		enrollments = new LinkedHashMap<>();
	}
	
	/**
	 * Searches the map of enrollments by course ID and returns a collection of
	 * {@link EnrollmentRecord EnrollmentRecords} that match the given course
	 * ID. Returns an empty collection if the given course ID is not found.
	 * 
	 * @param courseID course ID
	 * @return a collection of enrollment records that match the given course ID
	 */
	public Collection<EnrollmentRecord> findByCourse(String courseID) {
		return findBy((enrollment) -> enrollment.getCourseID().equals(courseID));
	}
	
	/**
	 * Searches the map of enrollments by student's JMBAG and returns a
	 * collection of {@link EnrollmentRecord EnrollmentRecords} that match the
	 * given student's JMBAG. Returns an empty collection if the given student's
	 * JMBAG is not found.
	 * 
	 * @param studentJMBAG student's JMBAG
	 * @return a collection of enrollment records that match the given JMBAG
	 */
	public Collection<EnrollmentRecord> findByStudent(String studentJMBAG) {
		return findBy((enrollment) -> enrollment.getStudentJMBAG().equals(studentJMBAG));
	}
	
	/**
	 * Searches the map of enrollments and returns a collection of {@link
	 * EnrollmentRecord EnrollmentRecords} that satisfy the given {@code
	 * predicate}.
	 * 
	 * @param predicate a predicate
	 * @return a collection of enrollment records that satisfy the predicate
	 */
	private Collection<EnrollmentRecord> findBy(Predicate<EnrollmentRecord> predicate) {
		Collection<EnrollmentRecord> data = new HashSet<>();
		Collection<EnrollmentRecord> col = enrollments.values();
		
		for (EnrollmentRecord enrollment : col) {
			if (predicate.test(enrollment)) {
				data.add(enrollment);
			}
		}
		
		return data;
	}

	/**
	 * Returns an {@code EnrollmentRecord} object containing the searched course
	 * id and student's JMBAG. Returns {@code null} if the object is not found.
	 * 
	 * @param courseID course ID
	 * @param studentJMBAG student's JMBAG
	 * @return
	 */
	public EnrollmentRecord findByCourseAndStudent(String courseID, String studentJMBAG) {
		Keys keys = getKeys(new EnrollmentRecord(courseID, studentJMBAG));
		return enrollments.get(keys);
	}
	
	/**
	 * Adds an course record to the table, with the initial course grade set to
	 * 0. Returns the previous value associated with this course record, or
	 * {@code null} if the previous value doesn't exist.
	 * 
	 * @param courseID course ID
	 * @param studentJMBAG student's JMBAG
	 * @return the previous value associated with this course record
	 */
	public EnrollmentRecord newCourse(String courseID, String studentJMBAG) {
		return add(new EnrollmentRecord(courseID, studentJMBAG));
	}
	
	/**
	 * Updates an enrollment record from the table. This is used to update
	 * student's grade to the database.
	 * 
	 * @param enrollment enrollment record
	 */
	public void updateEnrollment(EnrollmentRecord enrollment) {
		add(enrollment);
	}
	
	/**
	 * Removes an enrollment record from the table, with the given course ID and
	 * student's JMBAG.
	 * 
	 * @param courseID course ID
	 * @param studentJMBAG student's JMBAG
	 */
	public void deleteRecord(String courseID, String studentJMBAG) {
		remove(new EnrollmentRecord(courseID, studentJMBAG));
	}
	
	/**
	 * Adds an enrollment record to the table. Returns the previous value
	 * associated with this enrollment record, or {@code null} if the previous
	 * value doesn't exist.
	 * 
	 * @param enrollment enrollment record
	 * @return the previous value associated with this enrollment record
	 */
	public EnrollmentRecord add(EnrollmentRecord enrollment) {
		Keys keys = getKeys(enrollment);
		return enrollments.put(keys, enrollment);
	}
	
	/**
	 * Removes an enrollment record from the table. Returns the value previously
	 * associated with this enrollment record, or {@code null} if the table
	 * contained no mapping for the enrollment.
	 * 
	 * @param enrollment enrollment record
	 * @return the previous value associated with this enrollment record
	 */
	private EnrollmentRecord remove(EnrollmentRecord enrollment) {
		Keys keys = getKeys(enrollment);
		return enrollments.remove(keys);
	}
	
	/**
	 * Gets the enrollment map keys and returns an array of its keys.
	 * 
	 * @param enrollment enrollment record
	 * @return an array of enrollment map keys
	 */
	private Keys getKeys(EnrollmentRecord enrollment) {
		Keys keys = new Keys(enrollment.getCourseID(), enrollment.getStudentJMBAG());
		return keys;
	}
	
	@Override
	public String toString() {
		return enrollments.toString();
	}
	
	@Override
	public int hashCode() {
		return enrollments.hashCode();
	}
	
	@Override
	public boolean equals(Object obj) {
		return enrollments.equals(obj);
	}
	
	/**
	 * Returns an iterator over the elements in this table.
	 * 
	 * @return an iterator over the elements in this table
	 */
	@Override
	public Iterator<EnrollmentRecord> iterator() {
        return enrollments.values().iterator();
    }
	
	/**
	 * A class that represents keys to be put into the enrollments map.
	 *
	 * @author dinomario10
	 */
	private static class Keys {
		private String courseID;
		private String studentJMBAG;
		
		public Keys(String courseID, String studentJMBAG) {
			this.courseID = courseID;
			this.studentJMBAG = studentJMBAG;
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
			if (!(obj instanceof Keys))
				return false;
			Keys other = (Keys) obj;
			if (!courseID.equals(other.courseID))
				return false;
			if (!studentJMBAG.equals(other.studentJMBAG))
				return false;
			return true;
		}
	}

}
