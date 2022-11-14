package hr.fer.oop.primjeri.p003;

import hr.fer.oop.primjeri.p002.*;
import hr.fer.oop.primjeri.p010.*;
import java.util.Iterator;

public class RangeIntegerSet implements IFixedRangeIntegerSet,IntegerSet {
	ListCollection<Integer> collection;
	int lowerBound;
	int upperBound;
	
	public RangeIntegerSet(int lowerBound,int upperBound){
		this.lowerBound = lowerBound;
		this.upperBound = upperBound;
		collection = new ListCollection<Integer>();
	}
	
	public RangeIntegerSet(int lowerBound,int upperBound,Iterable<Integer> elements){
		this(lowerBound,upperBound);
		for(Integer element : elements){
			collection.add(element);
		}
	}
	
	public RangeIntegerSet(int lowerBound,int upperBound,Integer ... elements){
		this(lowerBound, upperBound);
		for(int i = 0;i < elements.length;i++){
			collection.add(elements[i]);
		}
	}
	
	@Override
	public boolean add(Integer element) {
		if(collection.contains(element) == true){
			return false;
		}
		collection.add(element);
		return true;
	}

	@Override
	public boolean remove(Integer element) {
		return collection.remove(element);
	}

	@Override
	public boolean containsElement(Integer element) {
		return collection.contains(element);
	}

	@Override
	public int getSize() {
		return collection.getSize();
	}

	@Override
	public int getLowerBound() {
		return lowerBound;
	}

	@Override
	public int getUpperBound() {
		return upperBound;
	}

	@Override
	public Iterator<Integer> iterator() {
		return collection.iterator();
	}

}
