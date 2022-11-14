package studenti;

// Model baze podataka koja nudi pristup pojedinačnoj
// bazi podataka za traženi kolegij.

public interface IStudentDatabase {

	ICourseDatabase getForCourse(String code);
	
}
