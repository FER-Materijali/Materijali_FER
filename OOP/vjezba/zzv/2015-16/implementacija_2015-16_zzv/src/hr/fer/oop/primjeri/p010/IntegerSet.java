package hr.fer.oop.primjeri.p010;

public interface IntegerSet extends Iterable<Integer> {
	public boolean add(Integer element);
	public boolean remove(Integer element);
	public boolean containsElement(Integer element);
	public int getSize();
}
