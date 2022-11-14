package hr.fer.oop.primjeri.p003;

public class Main {
	public static void main(String[] args) {
		RangeIntegerSet skup = new RangeIntegerSet(-100_000_000, 200_000_000);
		if (skup.add(12)) {
			System.out.println("Dodao sam.");
		} else {
			System.out.println("Nisam dodao - izgleda da je element veæ tamo.");
		}
		if (skup.add(12)) {
			System.out.println("Dodao sam.");
		} else {
			System.out.println("Nisam dodao - izgleda da je element veæ tamo.");
		}
		skup.add(14);
		skup.add(16);
		skup.add(18);
		System.out.println("Elementi skupa:");
		for (Integer e : skup) {
			System.out.println(e);
		}
		System.out.println("Velièina skupa: " + skup.getSize());
		System.out.println("Sadrži 5: " + skup.containsElement(5));
		System.out.println("Sadrži 9: " + skup.containsElement(9));
		System.out.println("Sadrži 10: " + skup.containsElement(10));
		System.out.println("Sadrži 13: " + skup.containsElement(13));
		System.out.println("Sadrži 14: " + skup.containsElement(14));
		System.out.println("Sadrži 20: " + skup.containsElement(20));
		System.out.println("Sadrži 21: " + skup.containsElement(21));
		System.out.println("Sadrži 24: " + skup.containsElement(24));
		RangeIntegerSet skup2 = new RangeIntegerSet(-100_000_000, 200_000_000, skup);
		skup2.remove(16);
		System.out.println("Opet iteriram po skupu 1:");
		for (Integer e : skup) {
			System.out.println(e);
		}
		System.out.println("Iteriram po skupu 2:");
		for (Integer e : skup2) {
			System.out.println(e);
		}
	}
}