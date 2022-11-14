package hr.fer.oop.primjeri.p007;

import java.util.Iterator;

public class IteratorConcatenator<T> implements Iterator<T>{
	private Iterator<T>[] table;
	private Iterator<T> active;
	private int currentSlot;
	private int slotSize;
	
	@SuppressWarnings("unchecked")
	@SafeVarargs
	public IteratorConcatenator(Iterator<T> ... iterators) {
		
		slotSize = iterators.length;
		
		table = (Iterator<T>[])new Iterator[slotSize];
		for(int i = 0;i < slotSize;i++){
			table[i] = iterators[i];
		}
		
		active = table[0];
		currentSlot = 0;
		
		int i = 1;
		while(active.hasNext() == false && i < slotSize){
			active = table[i];
			currentSlot = i;
			i++;
		}
	}
	
	@Override
	public boolean hasNext() {
		return active.hasNext();
	}

	@Override
	public T next() {
		T element = active.next();
		int i = currentSlot + 1;
		while(active.hasNext() == false && i < slotSize){
			active = table[i];
			currentSlot = i;
			i++;
		}
		return element;
	}
	
}
