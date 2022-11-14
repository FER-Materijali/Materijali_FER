package studenti;

import java.util.OptionalDouble;

import org.hamcrest.Matchers;
import org.junit.Test;
import org.mockito.Mockito;

import studenti.ICourseDatabase;
import studenti.IStudentDatabase;
import studenti.Kolegij;
import static org.junit.Assert.*;
import static org.hamcrest.CoreMatchers.*;

public class KolegijTest {

	@Test
	public void prosjekTest() {
		// Stvaramo imitacijske objekte:
		IStudentDatabase studentMock = Mockito.mock(IStudentDatabase.class);
		ICourseDatabase courseMock = Mockito.mock(ICourseDatabase.class);
		
		// Podešavamo što trebaju vratiti kada se pozove neka metoda:
		Mockito.when(studentMock.getForCourse("19674")).thenReturn(courseMock);
		Mockito.when(courseMock.hasGrade("1")).thenReturn(true);
		Mockito.when(courseMock.hasGrade("2")).thenReturn(false);
		Mockito.when(courseMock.hasGrade("3")).thenReturn(true);
		Mockito.when(courseMock.getGrade("1")).thenReturn(4);
		Mockito.when(courseMock.getGrade("3")).thenReturn(5);
		
		// Pozovemo testirani algoritam i predamo imitacijski objekt:
		Kolegij k = new Kolegij("19674");
		OptionalDouble result = k.prosjecnaOcjena(studentMock, "1", "2", "3");
		
		// Provjere ispravnosti rezultata:
		assertThat(result, notNullValue());
		assertTrue(result.isPresent());
		assertThat(result.getAsDouble(), Matchers.closeTo(4.5, 1E-6));

		// Provjere da su pozivane očekivane metode:
		Mockito.verify(studentMock, Mockito.times(1)).getForCourse("19674");
		Mockito.verify(courseMock, Mockito.atLeastOnce()).hasGrade("1");
		Mockito.verify(courseMock, Mockito.atLeastOnce()).hasGrade("2");
		Mockito.verify(courseMock, Mockito.atLeastOnce()).hasGrade("3");
		Mockito.verify(courseMock, Mockito.times(1)).getGrade("1");
		Mockito.verify(courseMock, Mockito.times(0)).getGrade("2");
		Mockito.verify(courseMock, Mockito.times(1)).getGrade("3");
		
	}

}
