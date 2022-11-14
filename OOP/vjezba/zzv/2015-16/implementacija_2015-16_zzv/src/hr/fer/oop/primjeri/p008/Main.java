package hr.fer.oop.primjeri.p008;

import java.util.function.Consumer;
import java.util.function.Predicate;
import hr.fer.oop.primjeri.p002.ListCollection;

public class Main {

	public static void main(String[] args) {
		Iterable<Student> students = loadStudents();

		// Poziv funkcije filtriraj_2 (sucelje predicate) sa prikladnim
		// anonimnim razredom:
		ListCollection<Student> filtered1 = filtriraj_2(students, new Predicate<Student>() {
			@Override
			public boolean test(Student s) {
				return s.getFirstEnrollmentYear() == 2013;
			}
		});

		// Poziv funkcije obradi_2 (sucelje consumer) sa prikladnim anonimnim
		// razredom:
		obradi_2(filtered1, new Consumer<Student>() {
			@Override
			public void accept(Student s) {
				System.out.println(s);
			}
		});

		// Poziv funkcije filtriraj_2 (sucelje predicate) sa prikladnim lambda
		// izrazom:
		ListCollection<Student> filtered2 = filtriraj_2(students, s -> s.getFirstEnrollmentYear() == 2013);

		// Poziv funkcije obradi_2 (sucelje consumer) sa prikladnim lambda
		// izrazom:
		obradi_2(filtered2, s -> System.out.println(s));
	}

	// Originalna verzija funkcije filtriraj:
	@SuppressWarnings("unused")
	private static ListCollection<Student> filtriraj(Iterable<Student> students) {
		ListCollection<Student> newCollection = new ListCollection<>();
		for (Student s : students) {
			if (s.getFirstEnrollmentYear() == 2013) {
				newCollection.add(s);
			}
		}
		return newCollection;
	}

	// Originalna verzija funkcije obradi:
	@SuppressWarnings("unused")
	private static void obradi(ListCollection<Student> students) {
		for (Student s : students) {
			System.out.println(s);
		}
	}

	// Verzija funkcije filtriraj koja implementira sucelje predicate:
	private static ListCollection<Student> filtriraj_2(Iterable<Student> students, Predicate<Student> condition) {
		ListCollection<Student> newCollection = new ListCollection<>();
		for (Student s : students) {
			if (condition.test(s)) {
				newCollection.add(s);
			}
		}
		return newCollection;
	}

	// Verzija funkcije obradi koja implementira sucelje consumer:
	private static void obradi_2(ListCollection<Student> students, Consumer<Student> action) {
		for (Student s : students) {
			action.accept(s);
		}
	}

	private static Iterable<Student> loadStudents() {
		return new ListCollection<Student>(new Student("0012345678", "Ivo", "Iviæ", Sex.MALE, 2013),
				new Student("0023456789", "Iva", "Iviæ", Sex.FEMALE, 2013),
				new Student("0034567890", "Ante", "Aniæ", Sex.MALE, 2012),
				new Student("0045678901", "Ana", "Aniæ", Sex.FEMALE, 2012),
				new Student("0056789012", "Petar", "Beriæ", Sex.MALE, 2014),
				new Student("0067890123", "Petra", "Beriæ", Sex.FEMALE, 2014));
	}
}
