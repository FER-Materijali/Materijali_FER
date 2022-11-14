package hr.fer.oop.lab4.prob2;

import hr.fer.oopj.lab4.data.StudentGrades;
import hr.fer.oopj.lab4.data.StudentRecord;

/**
 * Test class.
 * 
 * @author karlo
 *
 */
public class HashTest {

	/**
	 * The main method.
	 *
	 * @param args
	 *            the arguments
	 */
	public static void main(String[] args) {
		/*
		 * // create collection: SimpleHashtable<String, Integer> examMarks =
		 * new SimpleHashtable<>(2); // fill data: examMarks.put("Ivana",
		 * Integer.valueOf(2)); examMarks.put("Ante", Integer.valueOf(2));
		 * examMarks.put("Jasna", Integer.valueOf(2)); examMarks.put("Kristina",
		 * Integer.valueOf(5)); examMarks.put("Ivana", Integer.valueOf(5)); //
		 * overwrites old grade for Ivana // query collection: Integer
		 * kristinaGrade = examMarks.get("Kristina");
		 * System.out.println("Kristina's exam grade is: " + kristinaGrade); //
		 * writes: 5 // What is collection's size? Must be four!
		 * System.out.println("Number of stored pairs: " + examMarks.size()); //
		 * writes: 4
		 */

		SimpleHashtable<String, Integer> studenti = new SimpleHashtable<>();
		for (int i = 0; i < StudentGrades.getNumberOfRecords(); i++) {
			StudentRecord record = StudentGrades.getRecord(i);
			studenti.put(record.getStudentID(), record.getGrade());
		}

		Obilaznik<String> obilaznik = studenti.stvoriObilaznik();

		for (int i = 0; i < StudentGrades.getNumberOfRecords() + 1; i++) {
			String sljedeci = obilaznik.vratiSljedeceg();
			if (sljedeci == null) {
				System.out.println("KRAJ");
				break;
			}
			System.out.println("JMBAG: " + sljedeci);
		}
	}
}
