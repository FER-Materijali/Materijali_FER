package hr.fer.oop.primjeri.p001;

import java.util.Iterator;
import java.util.NoSuchElementException;

import hr.fer.oop.primjeri.p010.*;

public class FixedRangeIntegerSet implements Iterable<Integer>,IntegerSet {

	private int size;
	private int lowerBound;
	private int upperBound;
	private boolean[] elementFlags;

	public FixedRangeIntegerSet(int lowerBound, int upperBound) {
		size = 0;
		if(upperBound <= lowerBound){
			throw new IllegalArgumentException("Donja granica mora biti nuzno manja od gornje granice.");
		}
		this.lowerBound = lowerBound;
		this.upperBound = upperBound;
		elementFlags = new boolean[upperBound - lowerBound + 1];
	}

	public FixedRangeIntegerSet(int lowerBound, int upperBound, Iterable<Integer> elements) {
		this(lowerBound, upperBound);
		for (Integer element : elements) {
			//this.add(element); bolji nacin ali stvara probleme u 9. zadatku
			if (element == null || element < lowerBound || element > upperBound) {
				throw new IllegalArgumentException("Element " + element + " ne zadovoljava kriterije unosa u polje!");
			}
			elementFlags[element - lowerBound] = true;
			size += 1;
		}
	}

	public FixedRangeIntegerSet(int lowerBound, int upperBound, Integer... elements) {
		this(lowerBound, upperBound);
		for (int i = 0; i < elements.length; i++) {
			//this.add(element); bolji nacin ali stvara probleme u 9. zadatku
			if (elements[i] == null || elements[i] < lowerBound || elements[i] > upperBound) {
				throw new IllegalArgumentException(
						"Element " + elements[i] + " ne zadovoljava kriterije unosa u polje!");
			}
			elementFlags[elements[i] - lowerBound] = true;
			size += 1;
		}

	}

	public boolean add(Integer element) {
		if (element == null || element < lowerBound || element > upperBound) {
			throw new IllegalArgumentException("Element " + element + " ne zadovoljava kriterije unosa u polje!");
		}
		if (elementFlags[element - lowerBound] == true) {
			return false;
		}
		elementFlags[element - lowerBound] = true;
		size += 1;
		return true;
	}

	public boolean remove(Integer element) {
		if (element == null || element < lowerBound || element > upperBound) {
			throw new IllegalArgumentException("Element " + element + " ne zadovoljava kriterije brisanja iz polja!");
		}
		if (elementFlags[element - lowerBound] == false) {
			return false;
		}
		elementFlags[element - lowerBound] = false;
		size -= 1;
		return true;
	}

	public boolean containsElement(Integer element) {
		if (element == null || element < lowerBound || element > upperBound) {
			return false;
		}
		return elementFlags[element - lowerBound];
	}

	public int getSize() {
		return size;
	}

	public int getLowerBound() {
		return lowerBound;
	}

	public int getUpperBound() {
		return upperBound;
	}

	public Iterator<Integer> iterator() {
		return new memberIterator();
	}

	class memberIterator implements Iterator<Integer> {
		int currentIndex;
		int previousIndex;

		public memberIterator() {
			currentIndex = 0;
			previousIndex = 0;
			while (currentIndex < upperBound - lowerBound + 1 && !elementFlags[currentIndex]){
				currentIndex++;
			}
		}

		@Override
		public boolean hasNext() {
			return currentIndex < upperBound - lowerBound + 1;
		}

		@Override
		public Integer next() {
			if(this.hasNext() == false){
				throw new NoSuchElementException("Nema vise clanova za obilazak.");
			}
			int help = currentIndex + lowerBound;
			previousIndex = currentIndex;
			while (++currentIndex < upperBound - lowerBound + 1 && !elementFlags[currentIndex]){
				;
			}
			return help;
		}

		@Override
		public void remove() {
			elementFlags[previousIndex] = false;
			size--;
		}
	}

}
