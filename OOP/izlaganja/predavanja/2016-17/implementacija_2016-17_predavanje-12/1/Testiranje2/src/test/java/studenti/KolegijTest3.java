package studenti;

import static org.hamcrest.CoreMatchers.notNullValue;
import static org.junit.Assert.assertThat;
import static org.junit.Assert.assertTrue;

import java.util.OptionalDouble;

import org.hamcrest.Matchers;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.mockito.Mock;
import org.mockito.Mockito;

import studenti.ICourseDatabase;
import studenti.IStudentDatabase;
import studenti.Kolegij;

// Modifikacija gdje se za pokretanje testova koristi specijalizirani objekt
// MockitoJUnitRunner koji sam zna potražiti ima li članskih varijabli koje
// su anotirane s @Mock i ako ih ima, inicijalizira ih (stvara imitacijske objekte).
// Kod ovog pristupa više nije potrebno ručno pokretati inicijalizaciju pozivom
// metode MockitoAnnotations.initMocks(this);

@RunWith(org.mockito.junit.MockitoJUnitRunner.class)
public class KolegijTest3 {

	@Mock
	private IStudentDatabase studentMock;
	@Mock
	private ICourseDatabase courseMock;

	@Test
	public void prosjekTest() {
		
		Mockito.when(studentMock.getForCourse("19674")).thenReturn(courseMock);
		Mockito.when(courseMock.hasGrade("1")).thenReturn(true);
		Mockito.when(courseMock.hasGrade("2")).thenReturn(false);
		Mockito.when(courseMock.hasGrade("3")).thenReturn(true);
		Mockito.when(courseMock.getGrade("1")).thenReturn(4);
		Mockito.when(courseMock.getGrade("3")).thenReturn(5);
		
		Kolegij k = new Kolegij("19674");
		OptionalDouble result = k.prosjecnaOcjena(studentMock, "1", "2", "3");
		
		assertThat(result, notNullValue());
		assertTrue(result.isPresent());
		assertThat(result.getAsDouble(), Matchers.closeTo(4.5, 1E-6));

		Mockito.verify(studentMock, Mockito.times(1)).getForCourse("19674");
		Mockito.verify(courseMock, Mockito.atLeastOnce()).hasGrade("1");
		Mockito.verify(courseMock, Mockito.atLeastOnce()).hasGrade("2");
		Mockito.verify(courseMock, Mockito.atLeastOnce()).hasGrade("3");
		Mockito.verify(courseMock, Mockito.times(1)).getGrade("1");
		Mockito.verify(courseMock, Mockito.times(0)).getGrade("2");
		Mockito.verify(courseMock, Mockito.times(1)).getGrade("3");
		
	}

}
