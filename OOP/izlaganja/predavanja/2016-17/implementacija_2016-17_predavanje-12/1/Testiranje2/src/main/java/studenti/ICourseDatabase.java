package studenti;

// Model baze podataka za jedan konkretan kolegij
// koja čuva za studente ocjene s kojima su položili
// kolegij.

public interface ICourseDatabase {

	boolean hasGrade(String jmbag);
	int getGrade(String jmbag);

}
