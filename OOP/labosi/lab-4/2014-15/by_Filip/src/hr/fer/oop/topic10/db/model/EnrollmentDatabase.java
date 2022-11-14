package hr.fer.oop.topic10.db.model;

import java.util.ArrayList;
import java.util.Collection;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Map;

/**
 * Enrolments database
 * 
 * @author Filip
 *
 */
public class EnrollmentDatabase {

	// key = courseId, list represents all students that are enrolled
	private Map<String, List<EnrollmentRecord>> byCourse;

	// key = student jmbag, list represents pairs of (course,grade) for that
	// student
	private Map<String, List<EnrollmentRecord>> byStudent;

	/**
	 * Creates a new enrolment database from rows in a file
	 * 
	 * @param file
	 */
	public EnrollmentDatabase(List<String> file) {
		byCourse = new LinkedHashMap<>();
		byStudent = new LinkedHashMap<>();
		for (String row : file) {
			EnrollmentRecord er = new EnrollmentRecord(row);
			insert(er);
		}
	}

	/**
	 * Inserts the enrolment record in both maps
	 * 
	 * @param er enrolment record
	 */
	private void insert(EnrollmentRecord er) {
		insertEr(er, er.getCourseId(), byCourse);
		insertEr(er, er.getStudentJmbag(), byStudent);
	}

	/**
	 * Inserts the given enrolment record in some map
	 * 
	 * @param er enrolment record
	 * @param key key under which it will be stored
	 * @param m map
	 */
	private void insertEr(EnrollmentRecord er, String key, Map<String, List<EnrollmentRecord>> m) {
		List<EnrollmentRecord> le = m.get(key);
		if (le == null) {
			le = new ArrayList<>();
		}
		le.add(er);
		m.put(key, le);
	}

	/**
	 * Collection of enrollment records in which some student is enrolled
	 * 
	 * @param studentJMBAG
	 * @return
	 */
	public Collection<EnrollmentRecord> findByStudent(String studentJMBAG) {
		return byStudent.get(studentJMBAG);
	}

	/**
	 * Collection of enrollment records of students who are enrolled in some
	 * course
	 * 
	 * @param courseId
	 * @return
	 */
	public Collection<EnrollmentRecord> findByCourse(String courseId) {
		return byCourse.get(courseId);
	}

	public EnrollmentRecord findByStudentAndCourse(String studentJmbag, String courseId) {
		List<EnrollmentRecord> list = byStudent.get(studentJmbag);
		if (list == null) {
			return null;
		}
		for (EnrollmentRecord er : list) {
			if (er.getCourseId().equals(courseId)) {
				return er;
			}
		}
		return null;
	}

	/**
	 * Adds a newCourse to some student
	 * 
	 * @param studentJmbag
	 * @param courseId
	 * @return
	 */
	public EnrollmentRecord newCourse(String studentJmbag, String courseId) {
		EnrollmentRecord er = new EnrollmentRecord(courseId, studentJmbag, "0");
		insert(er);
		return er;
	}

	/**
	 * Updates some enrolment record
	 * 
	 * @param record
	 */
	public void updateEnrolment(EnrollmentRecord record) {
		deleteEnrolment(record.getStudentJmbag(), record.getCourseId());
		insert(record);
	}

	/**
	 * Deletes an enrollment record from the database.
	 * 
	 * @param studentJmbag
	 * @param courseId
	 */
	public void deleteEnrolment(String studentJmbag, String courseId) {
		EnrollmentRecord er = new EnrollmentRecord(courseId, studentJmbag, "");
		remove(studentJmbag, er, byStudent);
		remove(courseId, er, byCourse);

	}

	/**
	 * Used to remove an enrollment record from a map
	 * 
	 * @param key key
	 * @param er enrollment record
	 * @param m map
	 */
	private void remove(String key, EnrollmentRecord er, Map<String, List<EnrollmentRecord>> m) {
		List<EnrollmentRecord> le;
		le = m.get(key);
		if (le == null) {
			return;
		}
		le.remove(er);
		m.put(key, le);
	}

}
