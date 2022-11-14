package hr.fer.oopj.liste;

import java.util.Iterator;
import java.util.NoSuchElementException;
import java.util.function.Consumer;

public class MyList<E> implements Iterable<E> {

	private MyListElement<E> glava;
	
	public Iterator<E> iterator() {
		return new MojIterator<>(glava);
	}
	
	
	public void addLast(E value) {
		MyListElement<E> cvor = new MyListElement<>(null,value);
		
		if(glava==null) {
			glava = cvor;
			return;
		}
		
		MyListElement<E> current = glava;
		while(current.next != null) {
			current = current.next;
		}
		
		current.next = cvor;
	}

	public int size() {
		int broj = 0;
		
		MyListElement<E> current = glava;
		while(current != null) {
			broj++;
			current = current.next;
		}
		
		return broj;
	}

	public void removeAt(int index) {
		if(index < 0) return;
		
		if(index == 0) {
			if(glava == null) return;
			glava = glava.next;
		}
		
		MyListElement<E> current = glava;
		int ostalo = index-1;
		
		while(ostalo > 0) {
			if(current==null) return;
			ostalo--;
			current = current.next;
		}
		
		if(current==null) return;
		current.next = current.next.next;
	}

	public E elementAt(int index) {
		int left = index;
		
		MyListElement<E> current = glava;
		while(left > 0) {
			if(current==null) return null;
			left--;
			current = current.next;
		}
		
		if(current==null) return null;
		return current.value;
	}

	public void forEachX(Consumer<E> obrada) {
		MyListElement<E> current = glava;
		
		while(current != null) {
			obrada.accept(current.value);
			current = current.next;
		}
	}
	
	
	private static class MojIterator<E> implements Iterator<E> {
		private MyListElement<E> trenutni;

		public MojIterator(MyListElement<E> glava) {
			super();
			this.trenutni = glava;
		}
		
		@Override
		public boolean hasNext() {
			return trenutni != null;
		}
		
		@Override
		public E next() {
			if(!hasNext()) throw new NoSuchElementException();
			E zaVratiti = trenutni.value;
			trenutni = trenutni.next;
			return zaVratiti;
		}
		
	}
	
	private static class MyListElement<E> {
		MyListElement<E> next;
		E value;
		
		public MyListElement(MyListElement<E> next, E value) {
			super();
			this.next = next;
			this.value = value;
		}
	}
	
	
}
