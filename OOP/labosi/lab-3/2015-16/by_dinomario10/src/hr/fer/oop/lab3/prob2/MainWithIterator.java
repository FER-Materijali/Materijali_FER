package hr.fer.oop.lab3.prob2;

public class MainWithIterator {

	public static void main(String[] args) {
		// create collection:
		SimpleHashtable<String, Integer> examMarks = new SimpleHashtable<>(2);
		// fill data:
		examMarks.put("Ivana", Integer.valueOf(2));
		examMarks.put("Ante", Integer.valueOf(2));
		examMarks.put("Jasna", Integer.valueOf(2));
		examMarks.put("Kristina", Integer.valueOf(5));
		examMarks.put("Ivana", Integer.valueOf(5)); // overwrites old grade for Ivana
		
		System.out.println("First print");
		for (SimpleHashtable.TableEntry<String, Integer> entry : examMarks) {
			System.out.printf("%s => %s%n", entry.getKey(), entry.getValue());
		}
		System.out.println();		
		System.out.println("Second print");
		for (SimpleHashtable.TableEntry<String, Integer> entry : examMarks) {
			System.out.printf("%s => %s%n", entry.getKey(), entry.getValue());
		}
		
		// Additional testing...
		System.out.println("Kartezijev obilazak kroz tablicu:");
		for (SimpleHashtable.TableEntry<String, Integer> entry : examMarks) {
			System.out.printf("%s:%n", entry.getKey());
			for (SimpleHashtable.TableEntry<String, Integer> entry2 : examMarks) {
				System.out.printf("     %s%n", entry2.getKey());
			}
		}
		
	}

}
