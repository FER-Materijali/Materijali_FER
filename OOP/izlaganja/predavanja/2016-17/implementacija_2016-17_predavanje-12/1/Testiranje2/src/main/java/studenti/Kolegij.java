package studenti;

import java.util.OptionalDouble;

// Ovo je razred čiju metodu prosjecnaOcjena želimo testirati.

public class Kolegij {
	private String code;

	public Kolegij(String code) {
		super();
		this.code = code;
	}
	
	public OptionalDouble prosjecnaOcjena(IStudentDatabase database, String...jmbags) {
		ICourseDatabase db = database.getForCourse(code);
		int suma = 0;
		int broj = 0;
		for(String jmbag : jmbags) {
			if(db.hasGrade(jmbag)) {
				suma += db.getGrade(jmbag);
				broj++;
			}
		}
		if(broj==0) return OptionalDouble.empty();
		return OptionalDouble.of(suma/(double)broj);
	}
}
