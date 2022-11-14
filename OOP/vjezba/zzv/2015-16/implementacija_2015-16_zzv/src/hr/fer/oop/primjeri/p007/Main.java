package hr.fer.oop.primjeri.p007;

import java.util.Iterator;
import hr.fer.oop.primjeri.p002.ListCollection;

public class Main {
	public static void main(String[] args) {
		ListCollection<Integer> list1 = new ListCollection<>();
		ListCollection<Integer> list2 = new ListCollection<>();
		ListCollection<Integer> list3 = new ListCollection<>();
		list1.add(1).add(2).add(3);
		list2.add(11).add(12).add(13);
		list3.add(21).add(22).add(23);
		Iterator<Integer> it = new IteratorConcatenator<>(list1.iterator(), list2.iterator(), list3.iterator());
		System.out.println("Ispis:");
		while (it.hasNext()) {
			System.out.println(it.next());
		}
	}
}
