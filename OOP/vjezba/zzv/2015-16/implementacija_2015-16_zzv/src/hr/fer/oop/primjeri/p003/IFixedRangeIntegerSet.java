package hr.fer.oop.primjeri.p003;

import java.util.Iterator;

public interface IFixedRangeIntegerSet extends Iterable<Integer> {
	public boolean add(Integer element);
	public boolean remove(Integer element);
	public boolean containsElement(Integer element);
	public int getSize();
	public int getLowerBound();
	public int getUpperBound();
	public Iterator<Integer> iterator();
}
