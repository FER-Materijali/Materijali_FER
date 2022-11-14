package hr.fer.oop.primjeri.p006;

public class Main {

	public static void main(String[] args) {

		EvenNumbers en = new EvenNumbers(14, 4);
		for (Integer n : en) {
			System.out.println(n);
		}
	}
}
