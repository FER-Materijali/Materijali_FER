package hr.fer.oop.primjeri.p009;

import hr.fer.oop.primjeri.p001.*;

public class Main {
	public static void main(String[] args) {
		FixedRangeIntegerSet set1 = stvoriSkup(false);
		obrada(set1);
		FixedRangeIntegerSet set2 = stvoriSkup(true);
		obrada(set2);
	}

	private static FixedRangeIntegerSet stvoriSkup(boolean readOnly) {
		if (!readOnly) {
			return new FixedRangeIntegerSet(-10, 10, 1, 2, 5);
		} else {
			return new ImmutableFixedRangeIntegerSet(-10, 10, 1, 2, 5);
		}
	}

	private static void obrada(FixedRangeIntegerSet set) {
		System.out.println("Ispisujem elemente:");
		for (Integer i : set) {
			System.out.println(i);
		}
		System.out.println("Idem dodati broj u kolekciju:");
		try {
			set.add(3);
		} catch (UnsupportedOperationException ex) {
			System.out.println("Izmjena nije uspjela!");
		}
		System.out.println("Nakon dodavanja broja:");
		for (Integer i : set) {
			System.out.println(i);
		}
		System.out.println();
	}
}
