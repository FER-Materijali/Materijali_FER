package hr.fer.oop.primjeri.p002;

import java.util.EmptyStackException;
import java.util.Iterator;
import java.util.NoSuchElementException;

public class ListCollection<T> implements Iterable<T> {

	private ListNode<T> first;
	private ListNode<T> last;
	private int size;

	public ListCollection() {
		super();
	}
	
	@SafeVarargs
	public ListCollection(T ... elements) {
		super();
		for(int i = 0;i < elements.length;i++){
			this.add(elements[i]);
		}
	}
	
	public ListCollection(Iterable<T> elements){
		super();
		for(T element : elements){
			this.add(element);
		}
	}

	private static class ListNode<E> {
		private ListNode<E> next;
		private ListNode<E> previous;
		private E value;

		private ListNode() {
			super();
		}
	}

	public ListCollection<T> addToFirst(T element) {
		if (element == null) {
			throw new IllegalArgumentException("Vrijednost unosa nemoze biti null.");
		}

		ListNode<T> newEntry = new ListNode<>();
		newEntry.value = element;

		// Check if list was empty and this is first entry
		if (this.first == null) {
			if (this.last != null) {
				throw new AssertionError("Neispravno stanje prazne liste.");
			}
			this.first = newEntry;
			this.last = newEntry;
		} else {
			first.previous = newEntry;
			newEntry.previous = null;
			newEntry.next = this.first;
			first = newEntry;
		}
		size++;
		return this;
	}

	public ListCollection<T> add(T element) {
		if (element == null) {
			throw new IllegalArgumentException("Vrijednost unosa nemoze biti null.");
		}

		ListNode<T> newEntry = new ListNode<>();
		newEntry.value = element;

		// Check if list was empty and this is first entry
		if (this.first == null) {
			if (this.last != null) {
				throw new AssertionError("Neispravno stanje prazne liste.");
			}
			this.first = newEntry;
			this.last = newEntry;
		} else {
			last.next = newEntry;
			newEntry.previous = this.last;
			newEntry.next = null;
			this.last = newEntry;
		}
		size++;
		return this;
	}

	public boolean remove(Object element) {
		if (this.getSize() == 0){
			throw new EmptyStackException();
		}
		
		if (this.contains(element) == false) {
			return false;
		}

		ListNode<T> help;
		for (help = first; help.value.equals(element) == false && help.next != null; help = help.next)
			;

		// Removal of element will result in an empty list
		if (first == last) {
			first = last = null;
		}

		// Removal of element will move head pointer
		else if (first == help) {
			first = help.next;
			help.next.previous = null;
		}

		// Removal of element will move tail pointer
		else if (last == help) {
			last = help.previous;
			help.previous.next = null;
		}

		// Removal of element inside of the list
		else {
			help.previous.next = help.next;
			help.next.previous = help.previous;
		}

		size--;
		return true;
	}

	public T getElementAt(int index) {
		if (index < 0 || index >= size) {
			throw new IndexOutOfBoundsException("Trazeni index mora biti u intervalu [0," + (size - 1) + "].");
		}
		ListNode<T> help;
		int i = 0;
		for (help = first, i = 0; i != index && help.next != null; help = help.next, i++)
			;
		return help.value;
	}

	public boolean contains(Object element) {
		ListNode<T> help;
		
		//Case when collection is empty
		if(first == null){
			return false;
		}
		
		for (help = first; help.value.equals(element) == false && help.next != null; help = help.next)
			;
		return help.value.equals(element);
	}

	public int getSize() {
		return size;
	}

	@Override
	public Iterator<T> iterator() {
		return new memberIterator();
	}

	private class memberIterator implements Iterator<T> {
		ListNode<T> next, previous;

		public memberIterator() {
			next = previous = first;
		}

		@Override
		public boolean hasNext() {
			return next != null;
		}

		@Override
		public T next() {
			if(this.hasNext() == false){
				throw new NoSuchElementException("Nema vise clanova za obilazak.");
			}
			previous = next;
			next = next.next;
			return previous.value;
		}

		@Override
		public void remove() {
			if(next != null){
				next.previous = previous.previous;
			}
			if(previous.previous != null){
				previous.previous.next = next;
			}
			previous = previous.previous;
			size--;
		}
	}
}
