package hr.fer.oop.primjeri.p004;

import hr.fer.oop.primjeri.p002.*;
import java.util.Iterator;

public class Stack<T> implements Iterable<T> {
	ListCollection<T> collection;
	private int stackStatus;
	
	public Stack(){
		super();
		collection = new ListCollection<>();
	}
	
	public boolean isEmpty() {
		return stackStatus == 0;
	}

	/**
	 * Zbog potreba push i pop metode ovog zadatka, u razred ListCollection je dodana
	 * dodatna metoda 'addToFirst'.
	 */
	public void push(T element) {
		collection.addToFirst(element);
		stackStatus++;
	}

	public T pop() {
		T element = collection.getElementAt(0);
		collection.remove(element);
		stackStatus--;
		return element;
	}

	public int getSize() {
		return stackStatus;
	}
	
	/**
	 * Paznja: kako smo se odlucili uvesti novu metodu 'addToFirst' zbog potreba ponasanja stoga, nas iterator ce uvijek
	 * ispisivati clanove pocevsi od vrha stoga (posljednje dodanog clana), jer je takvo ponasanje (ispis clanova liste
	 * pocevsi od prvog clana) definirano u razredu 'ListCollection'.
	 */
	@Override
	public Iterator<T> iterator() {
		return collection.iterator();
	}
}
