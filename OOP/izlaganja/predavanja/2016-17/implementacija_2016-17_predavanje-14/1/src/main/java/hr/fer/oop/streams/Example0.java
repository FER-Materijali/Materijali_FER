package hr.fer.oop.streams;

import java.util.Comparator;
import java.util.List;
import java.util.OptionalDouble;
import java.util.function.Consumer;
import java.util.function.Function;
import java.util.function.Predicate;
import java.util.stream.Collectors;

public class Example0 {

	public static void main(String[] args) {
		List<Student> students = StudentData.load();

		students.stream().forEach(new Consumer<Student>() {
			@Override
			public void accept(Student t) {
				System.out.println(t);
			}
		});
		
		System.out.println();
		
		students.stream().forEach(System.out::println);
		
		System.out.println();

		students.stream().filter(new Predicate<Student>() {
			@Override
			public boolean test(Student t) {
				return t.getFinalGrade() > 3;
			}
		}).forEach(System.out::println);

		System.out.println();

		students
		  .stream()
		  .filter(t -> t.getFinalGrade() > 3)
		  .forEach(System.out::println);

		System.out.println();

		students
		  .stream()
		  .filter(t -> t.getFinalGrade() > 3)
		  .map(new Function<Student, String>() {
			  public String apply(Student student) {
				  return student.getStudentID();
			  };
		  })
		  .forEach(System.out::println);
		
		System.out.println();

		students
		  .stream()
		  .filter(t -> t.getFinalGrade() > 3)
		  .map(Student::getStudentID)
		  .forEach(System.out::println);

		System.out.println();

		students
		  .stream()
		  .filter(t -> t.getFinalGrade() > 3)
		  .map(Student::getStudentID)
		  //.sorted((jmbag1,jmbag2)->-jmbag1.compareTo(jmbag2))
		  //.sorted(Collections.reverseOrder(String::compareTo))
		  .sorted(((Comparator<String>)String::compareTo).reversed())
		  .forEach(System.out::println);
		
		List<String> jmbagovi = students
		  .stream()
		  .filter(t -> t.getFinalGrade() > 3)
		  .map(Student::getStudentID)
		  .sorted(((Comparator<String>)String::compareTo).reversed())
		  .collect(Collectors.toList());
		
		OptionalDouble rezultat = students
		  .stream()
		  .filter(t -> t.getFinalGrade() > 3)
		  .mapToInt(s -> s.getFinalGrade())
		  .average();

		OptionalDouble rezultat2 = students
		  .stream()
		  .mapToInt(s -> s.getFinalGrade())
		  .filter(o -> o>3) 
		  .average();

		if(rezultat.isPresent()) 
			System.out.println("prosjek je: " + rezultat.getAsDouble());
	}	
}
