package hr.fer.oop.collections_and_customclasses.example8b;


public class Student  {
	private String lastName;
	private String firstName;
	private String studentID;
	
	public Student(String lastName, String firstName, String studentID) {
		super();
		this.lastName = lastName;
		this.firstName = firstName;
		this.studentID = studentID;
	}
	
	public String getFirstName() {
		return firstName;
	}
	
	public String getLastName() {
		return lastName;
	}
	
	public String getStudentID() {
		return studentID;
	}
	
	@Override
	public String toString() {
		return String.format("(%s) %s %s", studentID, firstName, lastName);
	}
	
	@Override
	public boolean equals(Object obj) {
		if(!(obj instanceof Student)) return false;
		Student other = (Student)obj;
		return this.studentID.equals(other.studentID);
	}
	
	@Override
	public int hashCode(){
		return this.studentID.hashCode();
	}	    

	// -------------------------------------------------------
	// Za potrebe primjera dodane dvije metode za usporedbu:
	// 1) jedna koja uspoređuje trenutni objekt s predanim
	// 2) druga koja je statička, prima dva studenta i uspoređuje ih
	// Koristimo u primjeru za lambde:
	// -------------------------------------------------------
	
	public int usporediMe(Student drugi) {
		return studentID.compareTo(drugi.studentID);
	}

	public static int usporediDva(Student prvi, Student drugi) {
		return prvi.getStudentID().compareTo(drugi.getStudentID());
	}
}
