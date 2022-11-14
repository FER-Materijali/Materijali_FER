package hr.fer.oop.primjeri.p009;

import hr.fer.oop.primjeri.p001.*;

public class ImmutableFixedRangeIntegerSet extends FixedRangeIntegerSet {
	
	public ImmutableFixedRangeIntegerSet(int lowerBound, int upperBound, Integer... elements) {
		super(lowerBound, upperBound, elements);
	}

	public ImmutableFixedRangeIntegerSet(int lowerBound, int upperBound, Iterable<Integer> elements) {
		super(lowerBound, upperBound, elements);
	}

	@Override
	public boolean add(Integer element) {
		throw new UnsupportedOperationException("Dodavanje nije dozvoljeno!");
	}

	@Override
	public boolean remove(Integer element) {
		throw new UnsupportedOperationException("Uklanjanje nije dozvoljeno!");
	}
}
