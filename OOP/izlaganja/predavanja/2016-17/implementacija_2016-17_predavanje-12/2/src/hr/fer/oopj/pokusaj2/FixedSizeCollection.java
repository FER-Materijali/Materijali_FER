package hr.fer.oopj.pokusaj2;

import java.util.Arrays;
import java.util.Iterator;
import java.util.NoSuchElementException;

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
	
	public static class MojIterator<E> implements Iterator<E> {
		private FixedSizeCollection<E> mojaKolekcijaPoKojojIteriram;
		private int nextIndex;
		
		public MojIterator(FixedSizeCollection<E> mojaKolekcijaPoKojojIteriram) {
			super();
			this.mojaKolekcijaPoKojojIteriram = mojaKolekcijaPoKojojIteriram;
			this.nextIndex = 0;
		}
		
		@Override
		public boolean hasNext() {
			return nextIndex < mojaKolekcijaPoKojojIteriram.size();
		}
		
		@Override
		public E next() {
			if(!hasNext()) throw new NoSuchElementException();
			E sljedeci = mojaKolekcijaPoKojojIteriram.elements[nextIndex];
			nextIndex++;
			return sljedeci;
		}
	}
}
