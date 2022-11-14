package hr.fer.oop.primjeri.p010;

import hr.fer.oop.primjeri.p001.FixedRangeIntegerSet;

public class Main {
	public static void main(String[] args) {
		IntegerSet set = new FixedRangeIntegerSet(-10, 10, 1, 5);
		IntegerSet immutableSet = new ImmutableIntegerSet(set);
		obrada(immutableSet);
		obrada(set);
	}

	private static void obrada(IntegerSet set) {
		System.out.println("Prije izmjena:");
		for (Integer i : set) {
			System.out.println(i);
		}
		System.out.println("Idem dodati broj u kolekciju:");
		try {
			set.add(3);
		} catch (UnsupportedOperationException ex) {
			System.out.println("Izmjena nije uspjela!");
		}
		System.out.println("Nakon izmjena:");
		for (Integer i : set) {
			System.out.println(i);
		}
		System.out.println();
	}
}