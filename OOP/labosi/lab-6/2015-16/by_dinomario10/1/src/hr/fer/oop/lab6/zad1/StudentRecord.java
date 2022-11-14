package hr.fer.oop.lab6.zad1;

import java.util.Objects;

/**
 * This class represents records for individual students.
 *
 * @author dinomario10
 */
public class StudentRecord {
	
	/** Student's JMBAG */
	private String jmbag;
	/** Student's last name */
	private String lastName;
	/** Student's first name */
	private String firstName;
	/** Student's final grade */
	private Integer finalGrade;
	
	/**
	 * Constructs a new student record object.
	 * 
	 * @param jmbag student's JMBAG
	 * @param lastName student's last name
	 * @param firstName student's first name
	 * @param finalGrade student's final grade
	 */
	public StudentRecord(String jmbag, String lastName, String firstName, Integer finalGrade) {
		super();
		Objects.requireNonNull(jmbag, "Student's JMBAG must not be null.");
		this.jmbag = jmbag;
		this.lastName = lastName;
		this.firstName = firstName;
		this.finalGrade = finalGrade;
	}

	/**
	 * Returns the student's JMBAG.
	 * 
	 * @return the student's JMBAG
	 */
	public String getJmbag() {
		return jmbag;
	}

	/**
	 * Returns the student's last name.
	 * 
	 * @return the student's last name
	 */
	public String getLastName() {
		return lastName;
	}

	/**
	 * Returns the student's first name.
	 * 
	 * @return the student's first name
	 */
	public String getFirstName() {
		return firstName;
	}

	/**
	 * Returns the student's final grade.
	 * 
	 * @return the student's final grade
	 */
	public Integer getFinalGrade() {
		return finalGrade;
	}
	
	@Override
	public String toString() {
		return lastName + " " + firstName;
	}

	@Override
	public int hashCode() {
		final int prime = 31;
		int result = 1;
		result = prime * result + jmbag.hashCode();
		return result;
	}

	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (!(obj instanceof StudentRecord))
			return false;
		StudentRecord other = (StudentRecord) obj;
		if (!jmbag.equals(other.jmbag))
			return false;
		return true;
	}

}
