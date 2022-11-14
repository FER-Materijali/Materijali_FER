package brojevi;

import java.util.List;

public class Numbers {

	public static boolean isEven(int number) {
		return (number & 1) == 0;
	}

	public static void addEvenNumbers(int from, int to, List<Integer> list) {
		if(from > to) throw new IllegalArgumentException("From ("+from+") must not be greater than to ("+to+").");
		for(int i = from; i <= to; i++) {
			if(isEven(i)) list.add(i);
		}
	}
}
