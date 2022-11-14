package hr.fer.oopj.statistika;

public class Glavni {

	public static void main(String[] args) {
		Statistics statistics = new Statistics();
		statistics.addStudentWithGrade("Pero", 2);
		statistics.addStudentWithGrade("Pero", 3);
		statistics.addStudentWithGrade("Mara", 5);
		statistics.addStudentWithGrade("Ana", 2);
		System.out.println("**Statistics**");
		statistics.writeGrades();
		System.out.println("**Details**");
		statistics.writeDetails();
	}

}
