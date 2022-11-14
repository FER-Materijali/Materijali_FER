package hr.fer.oopj.pokusaj1;

public class Glavni {

	public static void main(String[] args) {
		FixedSizeCollection<String> col = new FixedSizeCollection<>("Ivo", "Ana", "Pero");
		
		for(int i = 0, n = col.size(); i < n; i++) {
			System.out.println(col.get(i));
		}
	}

}
