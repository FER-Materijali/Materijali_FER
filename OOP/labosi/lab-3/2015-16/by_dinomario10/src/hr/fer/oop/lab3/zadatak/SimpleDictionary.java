package hr.fer.oop.lab3.zadatak;

import java.util.Collections;
import java.util.Dictionary;
import java.util.Enumeration;
import java.util.NoSuchElementException;

/**
 * Additional task for 6 points.
 *
 * @author dinomario10
 * @param <K> key argument
 * @param <V> value argument
 */
public class SimpleDictionary<K, V> extends Dictionary<K, V> {
	
	/** Current number of entered elements */
	private int size;
	
	/** Slot in a hash table */
	private Entry<K, V>[] table;

	/**
	 * Constructs a new {@code SimpleDictionary} object with
	 * the given initial capacity.
	 * 
	 * @param initialCapacity number of slots in a hash table
	 */
	@SuppressWarnings("unchecked")
	public SimpleDictionary(int initialCapacity) {
		table = new Entry[initialCapacity];
		size = 0;
	}

	/**
	 * Constructs a new {@code SimpleDictionary} object with the capacity of 10.
	 * 
	 */
	public SimpleDictionary() {
		this(10);
	}
	/**
	 * 
	 * Calculates and returns hash code for a given key argument.
	 * 
	 * @param key entry's key
	 * @return hash code for a given key argument
	 */
	private int determineSlot(Object key) {
		return Math.abs(key.hashCode()) % table.length;
	}
	
	@Override
	public int size() {
		return this.size;
	}
	
	@Override
	public boolean isEmpty() {
		return this.size == 0;
	}

	@Override
	public Enumeration<K> keys() {
		return this.<K>getEnumeration(KEYS);
	}
	
	@Override
	public Enumeration<V> elements() {
		return this.<V>getEnumeration(VALUES);
	}
	
	@Override
	public V get(Object key) {
		if (this.isEmpty()) {
			return null;
		}
		
		int slot = determineSlot(key);
		
		Entry<K, V> currentInList = table[slot];
		while (currentInList != null) {
			if (currentInList.key.equals(key)) {
				return currentInList.getValue();
			}
			currentInList = currentInList.next;
		}
		return null;
	}
	
	@Override
	public V put(K key, V value) {
		if (key == null || value == null) {
			System.err.println("Arguments must not be null.");
			return null;
		}
		
		int slot = determineSlot(key);
		
		// First entry in slot
		if (table[slot] == null) {
			table[slot] = new Entry<K, V>(key, value, null);
			size++;
			return null;
		}
		
		// Set reference to the first element in list
		Entry<K, V> currentInList = table[slot];
		while (currentInList.next != null) {
			if (currentInList.key.equals(key)) {
				V previousValue = currentInList.value;
				currentInList.setValue(value);
				return previousValue;
			}
			currentInList = currentInList.next;
		}
		// Last element in list
		if (currentInList.key.equals(key)) {
			V previousValue = currentInList.value;
			currentInList.setValue(value);
			return previousValue;
		}
		currentInList.next = new Entry<K, V>(key, value, null);
		size++;
		return null;
	}
	
	@Override
	public V remove(Object key) {
		if (this.isEmpty()) {
			return null;
		}
		
		int slot = determineSlot(key);
		
		Entry<K, V> currentInList = table[slot];
		// Check if the wanted element is the first element
		if (currentInList.key.equals(key)) {
			V oldValue = currentInList.value;
			table[slot] = currentInList.next;
			size--;
			return oldValue;
		}
		// Check if the wanted element is somewhere in list
		while (currentInList.next != null) {
			if (currentInList.next.key.equals(key)) {
				V oldValue = currentInList.value;
				currentInList.next = currentInList.next.next;
				size--;
				return oldValue;
			}
			currentInList = currentInList.next;
		}
		// Element is not found
		return null;
	}
	
	private static final int KEYS = 0;
	private static final int VALUES = 1;
	
	private <T> Enumeration<T> getEnumeration(int type) {
        if (size == 0) {
            return Collections.emptyEnumeration();
        } else {
            return new Enumerator<>(type);
        }
    }
    
    private class Enumerator<T> implements Enumeration<T> {
    	
        int type;
        private int elementIndex;
		private int currentSlot;
		private int remainingElements;

        Enumerator(int type) {
            this.type = type;
            currentSlot = 0;
			elementIndex = 0;
			remainingElements = SimpleDictionary.this.size();
        }

        @Override
		public boolean hasMoreElements() {
			return remainingElements > 0;
		}
		
        @SuppressWarnings("unchecked")
		@Override
		public T nextElement() {
			if (!hasMoreElements()) {
				throw new NoSuchElementException("No more elements are available.");
			}
			
			Entry<K, V> currentElement = table[currentSlot];
			// Skip all empty slots
			while (currentElement == null) {
				currentSlot++;
				currentElement = table[currentSlot];
			}
			// Skip all elements to reach last returned element
			int elementsToSkip = this.elementIndex;
			while (elementsToSkip != 0) {
				currentElement = currentElement.next;
				elementsToSkip--;
			}
			this.elementIndex++;
			// End of elements in current slot
			if (currentElement.next == null) {
				currentSlot++;
				this.elementIndex = 0;
			}
			this.remainingElements--;
			return type == KEYS ? (T)currentElement.key : (T)currentElement.value;
		}
    }
	
	/**
	 * A class that represents an array for {@code SimpleHashtable} class.
	 * Used to store entries by their key and value.
	 * 
	 * @author dinomario10
	 *
	 * @param <K> key argument
	 * @param <V> value argument
	 */
	static class Entry<K, V> {
		
		private K key;
		private V value;
		private Entry<K, V> next;
		
		/**
		 * Constructs a new table entry for its superclass
		 * {@code SimpleHashtable} with given key, value and
		 * next table entry in a singly linked list.
		 * 
		 * @param key entry's key
		 * @param value entry's value
		 * @param next next table entry in a singly linked list
		 */
		private Entry(K key, V value, Entry<K, V> next) {
			this.key = key;
			this.value = value;
			this.next = next;
		}
		
		/**
		 * @return entry's key
		 */
		public K getKey() {
			return this.key;
		}
		
		/**
		 * @return entry's value
		 */
		public V getValue() {
			return this.value;
		}
		
		/**
		 * @param value entry's value
		 */
		public void setValue(V value) {
			this.value = value;
		}
		
		/**
		 * Returns a string representation of the object.
		 */
		@Override
		public String toString() {
			StringBuilder sb = new StringBuilder();
			sb.append(this.key).append(" => ").append(this.value);
			return sb.toString();
		}
	}
}
