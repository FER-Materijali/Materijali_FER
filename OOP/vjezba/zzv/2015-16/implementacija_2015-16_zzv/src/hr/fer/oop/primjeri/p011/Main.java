package hr.fer.oop.primjeri.p011;

public class Main {
	public static void main(String[] args) {
		obrada(MathematicalConstant.E);
	}

	private static void obrada(MathematicalConstant e) {
		System.out.println("Dobio sam broj: " + e.getValue());
	}
}