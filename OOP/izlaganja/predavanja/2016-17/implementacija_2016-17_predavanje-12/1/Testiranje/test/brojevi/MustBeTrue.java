package brojevi;

import org.hamcrest.BaseMatcher;
import org.hamcrest.Description;

public class MustBeTrue extends BaseMatcher<Boolean> {

	@Override
	public boolean matches(Object item) {
		if(!(item instanceof Boolean)) return false;
		return ((Boolean)item).booleanValue() == true;
	}

	@Override
	public void describeTo(Description description) {
		description.appendText("Must be true.");
	}

	public static MustBeTrue mustBeTrue() {
		return new MustBeTrue();
	}
}
