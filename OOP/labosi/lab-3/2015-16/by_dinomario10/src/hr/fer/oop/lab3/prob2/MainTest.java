package hr.fer.oop.lab3.prob2;

public class MainTest {

	public static void main(String[] args) {
		SimpleHashtable<String,Integer> examMarks = new SimpleHashtable<>(2);
		
		examMarks.put("Ivana", 2);
		examMarks.put("Ante", 2);
		examMarks.put("Jasna", 2);
		examMarks.put("Kristina", 5);
		examMarks.put("Ivana", 5); // overwrites old grade for Ivana
		examMarks.put("Dominik", 3);
		
		Integer kristinaGrade = examMarks.get("Kristina");
		System.out.println("Kristina's exam grade is: " + kristinaGrade);
		
		System.out.println("Number of stored pairs: " + examMarks.size());
		
		System.out.println("First print:");
		System.out.println(examMarks.toString());
		
		// Trying to remove a non-existing entry
		examMarks.remove("Domagoj");
		
		System.out.println("Does it contain Ivana? " + examMarks.containsKey("Ivana"));
		System.out.println("Does it contain 4? " + examMarks.containsValue(4));
		System.out.println("Does it contain 5? " + examMarks.containsValue(5));
		
		examMarks.remove("Ivana");
		System.out.println("Ivana has been removed.");
		System.out.println("Does it contain Ivana? " + examMarks.containsKey("Ivana"));
		
		System.out.println("Number of stored pairs: " + examMarks.size());
		
		System.out.println("Second print:");
		System.out.println(examMarks.toString());
		
	}

}
