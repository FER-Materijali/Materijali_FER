package hr.fer.oopj.pokusaj2;

import java.util.Iterator;

public class Glavni {

	public static void main(String[] args) {
		FixedSizeCollection<String> col = new FixedSizeCollection<>("Ivo", "Ana", "Pero");
		
		for(int i = 0, n = col.size(); i < n; i++) {
			System.out.println(col.get(i));
		}
		
		System.out.println();
		
		Iterator<String> iter = new FixedSizeCollection.MojIterator<>(col);
		
		while(iter.hasNext()) {
			System.out.println(iter.next());
		}
		
		System.out.println();
		
		iter = new FixedSizeCollection.MojIterator<>(col);
		
		while(true) {
			System.out.println(iter.next());
			System.out.flush();
			System.err.flush();
		}
		
	}

}
