package hr.fer.oop.primjeri.p008;

public class Student {
	private String firstName;
	private String lastName;
	private String id;
	private int firstEnrollmentYear;
	private Sex sex;

	public Student(String id, String firstName, String lastName, Sex sex, int firstEnrollmentYear) {
		super();
		this.id = id;
		this.firstName = firstName;
		this.lastName = lastName;
		this.sex = sex;
		this.firstEnrollmentYear = firstEnrollmentYear;
	}

	public String getFirstName() {
		return firstName;
	}

	public void setFirstName(String firstName) {
		this.firstName = firstName;
	}

	public String getLastName() {
		return lastName;
	}

	public void setLastName(String lastName) {
		this.lastName = lastName;
	}

	public String getId() {
		return id;
	}

	public void setId(String id) {
		this.id = id;
	}

	public int getFirstEnrollmentYear() {
		return firstEnrollmentYear;
	}

	public void setFirstEnrollmentYear(int firstEnrollmentYear) {
		this.firstEnrollmentYear = firstEnrollmentYear;
	}

	public Sex getSex() {
		return sex;
	}

	public void setSex(Sex sex) {
		this.sex = sex;
	}

	@Override
	public String toString() {
		return String.format("%s %s %s (%s, %d)", getId(), getFirstName(), getLastName(), getSex(),
				getFirstEnrollmentYear());
	}
}