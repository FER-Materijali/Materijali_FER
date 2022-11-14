package hr.fer.oop.primjeri.p002;

import java.util.Iterator;

public class Main {
	public static void main(String[] args) {
		ListCollection<String> lista = new ListCollection<>();
		lista.add("Ana").add("Jasna").add("Ivana").add(new String("Ana")).add("Ivana").add(new String("Ana"));
		
		System.out.printf("Velièina je: %d%n", lista.getSize());
		System.out.println();
		for (int i = 0, n = lista.getSize(); i < n; i++) {
			System.out.printf("Na lokaciji %d je element %s%n", i, lista.getElementAt(i));
		}
		System.out.println();
		
		
		lista.remove("Jasna");
		lista.remove("Ivana");
		lista.remove("Ivana");
		lista.remove("Ana");
		lista.remove("Ana");
		lista.remove("Ana");
		
		lista.add("Jasna");
		lista.add("Kristina");
		
		System.out.printf("Velièina je: %d%n", lista.getSize());
		System.out.println();
		for (int i = 0, n = lista.getSize(); i < n; i++) {
			System.out.printf("Na lokaciji %d je element %s%n", i, lista.getElementAt(i));
		}
		System.out.println();
		
		System.out.println("Obilazak iteratorom:");
		for (String e : lista) {
			System.out.println(e);
		}
		System.out.println();
		
		System.out.println("Drugi obilazak iteratorom:");
		Iterator<String> iter = lista.iterator();
		String a;
		while(iter.hasNext()){
			a = iter.next();
			if(a.equals("Ana")){
				iter.remove();
			}
		}
		for (String e : lista) {
			System.out.println(e);
		}
		System.out.println();
		
		String[] elems = { "Ana", "Kristina", new String("Ana"), new String("Ivana") };
		for (String e : elems) {
			System.out.printf("Sadrži %s? %b%n", e, lista.contains(e));
		}
		
		
	}
}
