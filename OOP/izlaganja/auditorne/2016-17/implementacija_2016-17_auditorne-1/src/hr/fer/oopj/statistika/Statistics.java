package hr.fer.oopj.statistika;

import java.util.HashMap;
import java.util.Map;
import java.util.Set;
import java.util.TreeSet;

public class Statistics {

	private Map<String, Integer> ocjene = new HashMap<>();
	private int[] histogram = new int[5];
	
	public void addStudentWithGrade(String name, int grade) {
		if(name==null || name.isEmpty()) {
			throw new IllegalArgumentException("Ime ne smije biti null ili prazno. Bilo je: "+name+".");
		}
		if(grade<1 || grade>5) {
			throw new IllegalArgumentException("Ocjena mora biti između 1 i 5. Bila je: "+grade+".");
		}
		
		if(ocjene.containsKey(name)) return;
		
		ocjene.put(name, grade);
		histogram[grade-1]++;
	}

	public void writeGrades() {
		int brojOcjena = ocjene.size();

		if(brojOcjena == 0) {
			System.out.println("Postotke nije moguće izračunati.");
			return;
		}
		
		for(int ocjena = 1; ocjena <= 5; ocjena++) {
			System.out.printf(
				"grade %d: %.2f%n", 
				ocjena,
				histogram[ocjena-1] / (double)brojOcjena * 100
			);
		}
		
	}

	public void writeDetails() {
		@SuppressWarnings("unchecked")
		Set<String>[] studentiPoOcjenama = (Set<String>[])new Set[5];
		for(int i = 0; i < 5; i++) {
			studentiPoOcjenama[i] = new TreeSet<>();
		}
		
		for(Map.Entry<String, Integer> par : ocjene.entrySet()) {
			studentiPoOcjenama[par.getValue()-1].add(par.getKey());
		}
		
		for(int i = 0; i < 5; i++) {
			System.out.println("grade "+ (i+1)+":");
			for(String student : studentiPoOcjenama[i]) {
				System.out.printf("  %s%n", student);
			}
		}
	}

}
