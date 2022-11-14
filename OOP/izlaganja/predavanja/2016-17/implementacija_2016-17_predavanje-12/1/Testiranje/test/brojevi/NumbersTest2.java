package brojevi;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

import org.junit.After;
import org.junit.Before;
import org.junit.Test;
import static org.junit.Assert.*;
import static brojevi.MustBeTrue.*;
import static org.hamcrest.CoreMatchers.*;

public class NumbersTest2 {

	@Test
	public void zeroIsEvenNumber() {
		boolean result = Numbers.isEven(0);
		assertEquals(true, result);
	}

	@Test
	public void twoIsEvenNumber() {
		boolean result = Numbers.isEven(2);
		assertEquals(true, result);
	}
	
	@Test
	public void minusTwoIsEvenNumber() {
		boolean result = Numbers.isEven(-2);
		assertEquals(true, result);
	}
	
	@Test
	public void oneIsNotEvenNumber() {
		boolean result = Numbers.isEven(1);
		assertFalse(result);
	}
	
	@Test
	public void minusOneIsNotEvenNumber() {
		boolean result = Numbers.isEven(-1);
		assertFalse(result);
	}

	private List<Integer> list;

	@Before
	public void setUp() {
		list = new ArrayList<>();
	}
	
	@After
	public void tearDown() {
		list = null;
	}
	
	@Test
	public void firstTwoNonNegativeEvenNumbers() {
		Numbers.addEvenNumbers(0, 2, list);
		assertEquals(Arrays.asList(0,2), list);
	}
	
	@Test
	public void evenNumbersAroundZeroNumbers() {
		Numbers.addEvenNumbers(-2, 2, list);
		assertEquals(Arrays.asList(-2,0,2), list);
	}
	
	@Test
	public void wrongIndexOrder() {
		try {
			Numbers.addEvenNumbers(2, -2, list);
		} catch(IllegalArgumentException ex) {
			return;
		}
		fail("Metoda addEvenNumbers trebala je baciti IllegalArgumentException!");
	}
	
	@Test(expected=IllegalArgumentException.class)
	public void wrongIndexOrder2() {
		Numbers.addEvenNumbers(2, -2, list);
	}
	
	@Test
	public void fourIsEvenNumber() {
		boolean result = Numbers.isEven(4);
		assertThat(!result, not(mustBeTrue()));
	}
	

}
