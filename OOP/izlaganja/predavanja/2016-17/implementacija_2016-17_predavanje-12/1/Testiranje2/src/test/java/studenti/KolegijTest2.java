package studenti;

import java.util.OptionalDouble;

import org.hamcrest.Matchers;
import org.junit.Before;
import org.junit.Test;
import org.mockito.Mock;
import org.mockito.Mockito;
import org.mockito.MockitoAnnotations;

import studenti.ICourseDatabase;
import studenti.IStudentDatabase;
import studenti.Kolegij;
import static org.junit.Assert.*;
import static org.hamcrest.CoreMatchers.*;

// Modifikacija gdje se imitacijski objekti navode kao članske varijable uz anotaciju @Mock.
// u setUp metodi nužno je pozvati MockitoAnnotations.initMocks(this); jer bez toga ne bi došlo
// do inicijalizacije imitacijskih objekata (ostali bi null reference). Možete jednostavno provjeriti
// tako da zakomentirate MockitoAnnotations.initMocks(this); pa pokrenete test.

public class KolegijTest2 {

	@Mock
	private IStudentDatabase studentMock;
	@Mock
	private ICourseDatabase courseMock;

	@Before
	public void setUp() {
		MockitoAnnotations.initMocks(this);
	}
	
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
