package hr.fer.oopj.pokusaj3;

import java.util.Iterator;

public class Glavni {

	public static void main(String[] args) {
		FixedSizeCollection<String> col = new FixedSizeCollection<>("Ivo", "Ana", "Pero");
		
		for(int i = 0, n = col.size(); i < n; i++) {
			System.out.println(col.get(i));
		}
		
		System.out.println();
		
		Iterator<String> iter = col.new MojIterator();
		while(iter.hasNext()) {
			String ime = iter.next();
			System.out.println(ime);
		}
		
		System.out.println();

		for(String ime : col) {
			System.out.println(ime);
		}
/*		
		Iterator<String> iter = col.iterator();
		while(iter.hasNext()) {
			String ime = iter.next();
			System.out.println(ime);
		}
*/
	}

}
