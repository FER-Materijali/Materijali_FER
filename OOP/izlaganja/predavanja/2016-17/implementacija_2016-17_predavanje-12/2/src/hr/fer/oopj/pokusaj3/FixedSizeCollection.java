package hr.fer.oopj.pokusaj3;

import java.util.Arrays;
import java.util.Iterator;
import java.util.NoSuchElementException;

public class FixedSizeCollection<T> implements Iterable<T> {

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
	
	public Iterator<T> iterator() {
		return new MojIterator();
		//return this.new MojIterator();
	}
	
	public class MojIterator implements Iterator<T> {
		private int nextIndex;
		
		public MojIterator() {
			super();
			this.nextIndex = 0;
		}
		
		@Override
		public boolean hasNext() {
			return nextIndex < size();
		}
		
		@Override
		public T next() {
			if(!hasNext()) throw new NoSuchElementException();
			T sljedeci = elements[nextIndex];
			nextIndex++;
			return sljedeci;
		}
	}
}
