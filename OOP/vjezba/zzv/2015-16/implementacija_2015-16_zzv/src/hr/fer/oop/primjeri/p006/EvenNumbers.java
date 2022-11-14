package hr.fer.oop.primjeri.p006;

import java.util.Iterator;

public class EvenNumbers implements Iterable<Integer> {

	int start,size;
	
	public EvenNumbers(int start,int size){
		if(start%2 != 0){
			throw new IllegalArgumentException("Prvi broj mora biti paran.");
		}
		if(size < 1){
			throw new IllegalArgumentException("Drugi broj mora biti pozitivan cijeli broj.");
		}
		this.start = start;
		this.size = size;
	}
	
	public Iterator<Integer> iterator(){
		return new numbersIterator();
	}

	class numbersIterator implements Iterator<Integer>{
		int currentNumber,currentSize;
		
		public numbersIterator(){
			currentNumber = start;
			currentSize = size;
		}
		
		@Override
		public boolean hasNext() {
			return currentSize > 0;
		}

		@Override
		public Integer next() {
			currentNumber+=2;
			currentSize--;
			return currentNumber-2;
		}
	}
}
