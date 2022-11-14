package hr.fer.oopj.pokusaj1;

import java.util.Arrays;

public class FixedSizeCollection<T> {

	private T[] elements;
	
	public FixedSizeCollection(T ... elems) {
		this.elements = Arrays.copyOf(elems, elems.length);
	}

	public int size() {
		return elements.length;
	}
	
	public T get(int index) {
		return elements[index];
	}
	
}
