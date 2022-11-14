package hr.fer.oop.collections_and_customclasses.example8b;


import java.util.TreeSet;

import hr.fer.oop.collections_and_customclasses.Common;

import java.util.Comparator;
import java.util.Set;

public class TreeSetMain {
	
	public static void main(String[] args) {		
		// Tri načina kako iskoristiti člansku metodu koju smo dodali u razred Student:
		Set<Student> students1a = new TreeSet<>(new Comparator<Student>() {
			@Override
			public int compare(Student o1, Student o2) {
				return o1.usporediMe(o2);
			}
		});
		Set<Student> students1b = new TreeSet<>((o1,o2) -> o1.usporediMe(o2));
		Set<Student> students1c = new TreeSet<>(Student::usporediMe);
		
		// Tri načina kako iskoristiti statičku metodu koju smo dodali u razred Student:
		Set<Student> students2a = new TreeSet<>(new Comparator<Student>() {
			@Override
			public int compare(Student o1, Student o2) {
				return Student.usporediDva(o1, o2);
			}
		});
		Set<Student> students2b = new TreeSet<>((o1,o2) -> Student.usporediDva(o1, o2));
		Set<Student> students2c = new TreeSet<>(Student::usporediDva);

		// Ovo je samo nastavak primjera example8.
		Set<Student> students = students1a;
		Common.fillStudentsCollection(students, Student::new);			
		System.out.println("I have following students:");
		Common.printCollection(students);
		
		Student s = new Student("Poe", "Edgar Allan", "2345678901");		
		System.out.println("Poe present: " + students.contains(s));
	}
}
