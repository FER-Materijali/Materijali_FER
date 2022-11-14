package hr.fer.oop.topic10.db.model;

import hr.fer.oop.topic10.db.IFilter;

import java.util.Collection;
import java.util.LinkedHashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;

/**
 * The name is self-explanatory, it is a class whose instances have a database
 * of student records. Index is student's JMBAG.
 * 
 * @author Filip Hrenić
 * @version 1.0
 */
public class StudentDatabase {

	/**
	 * Used as a database of student records.
	 */
	private Map<String, StudentRecord> base;

	/**
	 * Constructs a new database using a collection of student records.
	 * 
	 * @param c
	 *            collection in which student records are stored
	 */
	public StudentDatabase(List<String> c) {
		base = new LinkedHashMap<>();
		for (String s : c) {
			StudentRecord sr = new StudentRecord(s);
			base.put(sr.getJmbag(), sr);
		}
	}

	public Collection<StudentRecord> getAllStudents() {
		return base.values();
	}

	/**
	 * Returns a {@link StudentRecord} whit given jmbag.
	 * 
	 * @param jmbag
	 *            student's jmbag
	 * @return student with given jmbag, or null if there is no such student
	 */
	public StudentRecord forJMBAG(String jmbag) {
		if (!base.containsKey(jmbag)) {
			return null;
		}
		return base.get(jmbag);
	}

	/**
	 * Returns a list of records filtered with given filter.
	 * 
	 * @param filter
	 *            we filter the records with it
	 * @return a list of records that satisfy given filter
	 */
	public List<StudentRecord> filter(IFilter<StudentRecord> filter) {
		List<StudentRecord> list = new LinkedList<>();
		for (StudentRecord record : base.values()) {
			if (filter.accepts(record)) {
				list.add(record);
			}
		}
		return list;
	}
}
