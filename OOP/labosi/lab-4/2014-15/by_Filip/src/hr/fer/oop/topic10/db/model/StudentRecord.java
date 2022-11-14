package hr.fer.oop.topic10.db.model;

/**
 * Instances of this class represent records for each student. Each student has
 * a jmbag, firstName, lastName and finalGrade property.
 * 
 * @author Filip Hrenić
 * @version 1.0
 */
public class StudentRecord extends AbstractRecord {

	/**
	 * Constructs a new student record with data given through parameter.
	 * 
	 * @param row
	 *            string being parsed into a record
	 */
	public StudentRecord(String row) {
		super(row);
	}

	public StudentRecord(String jmbag, String lastName, String firstName,
			String grade) {
		super(jmbag, lastName, firstName, grade);
	}

	/**
	 * Getter method for the jmbag property.
	 * 
	 * @return jmbag
	 */
	public String getJmbag() {
		return getElements()[0];
	}

	/**
	 * Getter method for the lastName property.
	 * 
	 * @return last name
	 */
	public String getLastName() {
		return getElements()[1];
	}

	/**
	 * Getter method for the firstName property.
	 * 
	 * @return first name
	 */
	public String getFirstName() {
		return getElements()[2];
	}

	/**
	 * Getter method for the finalGrade property.
	 * 
	 * @return final grade
	 */
	public String getFinalGrade() {
		return getElements()[3];
	}

	@Override
	public String toString() {
		return getFirstName() + " " + getLastName();
	}

}
