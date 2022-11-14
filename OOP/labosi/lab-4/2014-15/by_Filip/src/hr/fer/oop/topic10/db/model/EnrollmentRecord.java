package hr.fer.oop.topic10.db.model;

public class EnrollmentRecord extends AbstractRecord {

	public EnrollmentRecord(String courseId, String studentJmbag, String grade) {
		super(courseId, studentJmbag, grade);
	}

	public EnrollmentRecord(String row) {
		super(row);
	}

	public String getCourseId() {
		return getElements()[0];
	}

	public String getStudentJmbag() {
		return getElements()[1];
	}

	public String getGrade() {
		return getElements()[2];
	}

}
