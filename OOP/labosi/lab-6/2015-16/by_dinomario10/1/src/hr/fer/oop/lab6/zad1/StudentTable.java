package hr.fer.oop.lab6.zad1;

import java.util.Iterator;
import java.util.LinkedHashMap;
import java.util.Map;

/**
 * This class represents a table of student records stored in the database. It
 * acts as a list of all {@link StudentRecord StudentRecords} and is organized
 * to get student records in time complexity of O(1).
 *
 * @author dinomario10
 */
public class StudentTable implements Iterable<StudentRecord> {
	
	/** Map of students */
	private Map<String, StudentRecord> students;
	
	/**
	 * Constructs an initial student table object, with the students map
	 * initialized.
	 */
	public StudentTable() {
		students = new LinkedHashMap<>();
	}
	
	/**
	 * Returns the {@linkplain StudentRecord} to which the specified JMBAG is
	 * assigned, or {@code null} if this table contains no mapping for the
	 * specified JMBAG.
	 * 
	 * @param jmbag student's jmbag
	 * @return	the StudentRecord to which the specified JMBAG is assigned, or
	 * 			null if this table does not contain the JMBAG
	 */
	public StudentRecord get(String jmbag) {
		return students.get(jmbag);
	}
	
	/**
	 * Adds a student record to the table. Returns the previous value associated
	 * with this student record, or {@code null} if the previous value doesn't
	 * exist.
	 * 
	 * @param student student record
	 * @return the previous value associated with this student record
	 */
	public StudentRecord add(StudentRecord student) {
		return students.put(student.getJmbag(), student);
	}
	
	/**
	 * Removes a student record from the table. Returns the value previously
	 * associated with this student record, or {@code null} if the table
	 * contained no mapping for the student.
	 * 
	 * @param student student record
	 * @return the previous value associated with this student record
	 */
	public StudentRecord remove(StudentRecord student) {
		return students.remove(student.getJmbag());
	}
	
	@Override
	public String toString() {
		return students.toString();
	}
	
	@Override
	public int hashCode() {
		return students.hashCode();
	}

	@Override
	public boolean equals(Object obj) {
		return students.equals(obj);
	}
	
	/**
	 * Returns an iterator over the elements in this table.
	 * 
	 * @return an iterator over the elements in this table
	 */
	@Override
	public Iterator<StudentRecord> iterator() {
        return students.values().iterator();
    }
	
}
