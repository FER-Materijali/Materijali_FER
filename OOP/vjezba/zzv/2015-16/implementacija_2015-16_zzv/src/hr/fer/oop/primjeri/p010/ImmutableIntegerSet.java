package hr.fer.oop.primjeri.p010;

import java.util.Iterator;

public class ImmutableIntegerSet implements IntegerSet {
	IntegerSet set;
	
	public ImmutableIntegerSet(IntegerSet set){
		this.set = set;
	}
	
	@Override
	public Iterator<Integer> iterator() {
		return set.iterator();
	}

	@Override
	public boolean add(Integer element) {
		throw new UnsupportedOperationException("Dodavanje nije dozvoljeno!");
	}

	@Override
	public boolean remove(Integer element) {
		throw new UnsupportedOperationException("Uklanjanje nije dozvoljeno!");
	}

	@Override
	public boolean containsElement(Integer element) {
		return set.containsElement(element);
	}

	@Override
	public int getSize() {
		return set.getSize();
	}

}
