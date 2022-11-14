package studenti;

import static org.hamcrest.CoreMatchers.notNullValue;
import static org.hamcrest.Matchers.closeTo;
import static org.junit.Assert.assertThat;
import static org.junit.Assert.assertTrue;
import static org.mockito.Mockito.atLeastOnce;
import static org.mockito.Mockito.times;
import static org.mockito.Mockito.verify;
import static org.mockito.Mockito.when;

import java.util.OptionalDouble;

import org.junit.Test;
import org.junit.runner.RunWith;
import org.mockito.Mock;

import studenti.ICourseDatabase;
import studenti.IStudentDatabase;
import studenti.Kolegij;

// Iskorišten statički import za dobivanje preglednijeg koda:

@RunWith(org.mockito.junit.MockitoJUnitRunner.class)
public class KolegijTest4 {

	@Mock
	private IStudentDatabase studentMock;
	@Mock
	private ICourseDatabase courseMock;

	@Test
	public void prosjekTest() {
		
		when(studentMock.getForCourse("19674")).thenReturn(courseMock);
		when(courseMock.hasGrade("1")).thenReturn(true);
		when(courseMock.hasGrade("2")).thenReturn(false);
		when(courseMock.hasGrade("3")).thenReturn(true);
		when(courseMock.getGrade("1")).thenReturn(4);
		when(courseMock.getGrade("3")).thenReturn(5);
		
		Kolegij k = new Kolegij("19674");
		OptionalDouble result = k.prosjecnaOcjena(studentMock, "1", "2", "3");
		
		assertThat(result, notNullValue());
		assertTrue(result.isPresent());
		assertThat(result.getAsDouble(), closeTo(4.5, 1E-6));

		verify(studentMock, times(1)).getForCourse("19674");
		verify(courseMock, atLeastOnce()).hasGrade("1");
		verify(courseMock, atLeastOnce()).hasGrade("2");
		verify(courseMock, atLeastOnce()).hasGrade("3");
		verify(courseMock, times(1)).getGrade("1");
		verify(courseMock, times(0)).getGrade("2");
		verify(courseMock, times(1)).getGrade("3");
		
	}

}
