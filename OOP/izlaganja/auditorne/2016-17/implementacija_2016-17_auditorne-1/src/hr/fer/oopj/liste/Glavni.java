package hr.fer.oopj.liste;

import java.util.Iterator;
import java.util.OptionalDouble;
import java.util.function.Consumer;

public class Glavni {

	public static void main(String[] args) {
		MyList<Integer> brojevi = new MyList<>();

		brojevi.addLast(10);
		brojevi.addLast(5);
		brojevi.addLast(1);
		brojevi.addLast(2);
		brojevi.addLast(18);
		brojevi.addLast(3);

		System.out.println("Prvi:");
		brojevi.forEach(new Ispisivac());
		System.out.println();
		
		System.out.println("Drugi:");
		brojevi.forEach(new IspisivacVeciOd4());
		System.out.println();
		
		Prosjek p = new Prosjek();
		brojevi.forEach(p);
		OptionalDouble prosjek = p.vratiMiProsjek();
		if(prosjek.isPresent()) {
			System.out.println("Prosjek je: " + prosjek.getAsDouble());
		} else {
			System.out.println("Lista je bila prazna. Prosjek ne postoji!");
		}
		
		System.out.println();
		Iterator<Integer> it = brojevi.iterator();
		while(it.hasNext()) {
			System.out.println("Vratio mi je: " + it.next());
		}
		
		for(Integer broj : brojevi) {
			System.out.println("Izkratke petlje: " + broj);
		}
	}
	
	private static class Prosjek implements Consumer<Integer> {
		double tekucaSuma;
		int brojElemenata;
		
		@Override
		public void accept(Integer t) {
			tekucaSuma += t;
			brojElemenata++;
		}
		
		public OptionalDouble vratiMiProsjek() {
			if(brojElemenata==0) {
				return OptionalDouble.empty();
			}
			return OptionalDouble.of(tekucaSuma / brojElemenata);
		}
		
	}
	
	private static class Ispisivac implements Consumer<Integer> {
		@Override
		public void accept(Integer t) {
			System.out.println(t);
		}
	}
	private static class IspisivacVeciOd4 implements Consumer<Integer> {
		@Override
		public void accept(Integer t) {
			if(t>4) {
				System.out.println(t);
			}
		}
	}
}
