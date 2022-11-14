package hr.fer.oop.lab3.prob2;

import java.util.Iterator;
import java.util.NoSuchElementException;

/**
 * The {@code SimpleHashtable} class represents a hash table used to implement
 * an associative array, a structure that can map keys to values.
 * <p>
 * A hash table uses a hash function to compute an index into an array of
 * slots, from which the desired value can be found.
 * </p>
 * 
 * @author dinomario10
 * @param <K> key argument
 * @param <V> value argument
 */
public class SimpleHashtable<K, V> implements Iterable<SimpleHashtable.TableEntry<K, V>> {

	private TableEntry<K, V>[] table;
	private int size;

	/**
	 * Constructs a new {@code SimpleHashtable} object that stores entries in a
	 * table of size 16. The object is initially empty.
	 */
	public SimpleHashtable() {
		this(16);
	}

	/**
	 * Constructs a new {@code SimpleHashtable} object that stores entries in a
	 * table sized the first power of two that is greater than or equal to the
	 * argument value. The object is initially empty.
	 * 
	 * @param n a value
	 */
	@SuppressWarnings("unchecked")
	public SimpleHashtable(int n) {
		int tableSize = nextPowerOfTwo(n);
		table = new TableEntry[tableSize];
		size = 0;
	}

	/**
	 * Returns the first power of two that is greater than or equal to the
	 * argument value. Special cases:
	 * <ul>
	 * <li>If the argument value is already a power of two, then the result
	 * is the same as the argument.
	 * <li>If the argument value is less than or equal to zero, then the
	 * result is first positive power of two, which is 1.
	 * </ul>
	 * 
	 * @param n a value
	 * @return the first integer power of two that is greater than or equal to
	 *         the argument
	 */
	private int nextPowerOfTwo(int n) {
		if (n <= 0) return 1;
		int exponent = (int) (Math.ceil(Math.log(n) / Math.log(2)));
		return (int) Math.pow(2, exponent);
	}
	
	/**
	 * Calculates and returns hash code for a given key argument.
	 * 
	 * @param key entry's key
	 * @return hash code for a given key argument
	 */
	private int determineSlot(K key) {
		return Math.abs(key.hashCode()) % table.length;
	}
	
	/**
	 * Puts a new entry into the given object {@SimpleHashtable}
	 * by determining the key's hash code for insertion.
	 * <p>Time complexity: O(1)</p>
	 * 
	 * @param key entry's key
	 * @param value entry's value
	 */
	public void put(K key, V value) {
		if (key == null) {
			System.err.println("Key must not be null.");
			return;
		}
		
		int slot = determineSlot(key);
		
		// First entry in slot
		if (table[slot] == null) {
			table[slot] = new TableEntry<K, V>(key, value, null);
			size++;
			return;
		}
		
		// Set reference to the first element in list
		TableEntry<K, V> currentInList = table[slot];
		while (currentInList.next != null) {
			if (currentInList.key.equals(key)) {
				currentInList.setValue(value);
				return;
			}
			currentInList = currentInList.next;
		}
		// Last element in list
		if (currentInList.key.equals(key)) {
			currentInList.setValue(value);
			return;
		}
		currentInList.next = new TableEntry<K, V>(key, value, null);
		size++;
	}
	
	/**
	 * Returns a value of an entry given with its key.
	 * If the searched entry does not exist, {@code null} is returned.
	 * <p>Time complexity: O(1)</p>
	 * 
	 * @param key entry's key
	 * @return existing entry if found, {@code null} otherwise
	 */
	public V get(K key) {
		int slot = determineSlot(key);
		
		TableEntry<K, V> currentInList = table[slot];
		while (currentInList != null) {
			if (currentInList.key.equals(key)) {
				return currentInList.getValue();
			}
			currentInList = currentInList.next;
		}
		return null;
	}
	
	/**
	 * Returns the size of a {@code SimpleHashtable} object.
	 * Size is determined by the number of entries in object.
	 * 
	 * @return the size of a {@code SimpleHashtable} object
	 */
	public int size() {
		return this.size;
	}
	
	/**
	 * Returns true if {@code SimpleHashtable} object contains
	 * the desired key. False otherwise.
	 * <p>Time complexity: O(1)</p>
	 * 
	 * @param key entry's key
	 * @return true if object contains the desired key. False otherwise.
	 */
	public boolean containsKey(K key) {
		int slot = determineSlot(key);
		
		TableEntry<K, V> currentInList = table[slot];
		while (currentInList != null) {
			if (currentInList.key.equals(key)) {
				return true;
			}
			currentInList = currentInList.next;
		}
		return false;
	}
	
	/**
	 * Returns true if {@code SimpleHashtable} object contains
	 * the desired value. False otherwise.
	 * <p>Time complexity: O(n)</p>
	 * 
	 * @param value entry's value
	 * @return true if object contains the desired value. False otherwise.
	 */
	public boolean containsValue(V value) {
		int currentSlot = 0;
		// Go through all table entries
		while (currentSlot < table.length) {
			TableEntry<K, V> currentInList = table[currentSlot];
			while (currentInList != null) {
				if (currentInList.value.equals(value)) {
					return true;
				}
				currentInList = currentInList.next;
			}
			currentSlot++;
		}
		return false;
	}
	
	/**
	 * Removes an existing entry with the given key. Prints out
	 * an error message if there is no entry with the given key.
	 * <p>Time complexity: O(1)</p>
	 * 
	 * @param key entry's key
	 */
	public void remove(K key) {
		if (containsKey(key) == false) {
			System.err.println("There is no entry with the given key.");
			return;
		}
		
		int slot = determineSlot(key);
		
		TableEntry<K, V> currentInList = table[slot];
		// Check if the wanted element is the first element
		if (currentInList.key.equals(key)) {
			table[slot] = currentInList.next;
			size--;
			return;
		}
		// Check if the wanted element is somewhere in list
		while (currentInList.next != null) {
			if (currentInList.next.key.equals(key)) {
				currentInList.next = currentInList.next.next;
				size--;
				return;
			}
			currentInList = currentInList.next;
		}
	}
	
	/**
	 * Returns true if {@code SimpleHashtable} object contains no entries.
	 * False otherwise.
	 * 
	 * @return true if object contains no entries. False otherwise.
	 */
	public boolean isEmpty() {
		if (size == 0) return true;
		else return false;
	}
	/**
	 * Returns a string representation of the object.
	 */
	@Override
	public String toString() {
		int currentSlot = 0;
		StringBuilder sb = new StringBuilder();
		// Circulate all table entries
		while (currentSlot < table.length) {
			TableEntry<K, V> currentInList = table[currentSlot];
			while (currentInList != null) {
				sb.append(currentInList.toString()).append('\n');
				currentInList = currentInList.next;
			}
			currentSlot++;
		}
		return sb.toString();
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
	static class TableEntry<K, V> {
		
		private K key;
		private V value;
		private TableEntry<K, V> next;
		
		/**
		 * Constructs a new table entry for its superclass
		 * {@code SimpleHashtable} with given key, value and
		 * next table entry in a singly linked list.
		 * 
		 * @param key entry's key
		 * @param value entry's value
		 * @param next next table entry in a singly linked list
		 */
		private TableEntry(K key, V value, TableEntry<K, V> next) {
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
	
	@Override
	public Iterator<TableEntry<K, V>> iterator() {
		return new SimpleHashTableIterator();
	}
	
	/**
	 * Iterates through all elements in {@code SimpleHashtable} firstly finding
	 * a non-empty slot, then iterating through singly linked list elements.
	 * 
	 * @author dinomario10
	 *
	 */
	public class SimpleHashTableIterator implements Iterator<TableEntry<K, V>>{
		
		private TableEntry<K, V> lastReturnedElement;
		private int currentSlot;
		private int remainingElements;
		
		/**
		 * Constructs a new iterator for class {@code SimpleHashtable}. Sets the
		 * current slot for iteration initially at 0, the element index from
		 * where to continue also initially at 0 and the total number of
		 * remaining elements initially at {@code SimpleHashtable} size.
		 */
		public SimpleHashTableIterator() {
			currentSlot = 0;
			lastReturnedElement = null;
			remainingElements = SimpleHashtable.this.size();
		}
		
		@Override
		public boolean hasNext() {
			return remainingElements > 0;
		}
		
		public TableEntry<K, V> next() {
			if (!hasNext()) {
				throw new NoSuchElementException("No more elements are available.");
			}
			
			TableEntry<K, V> currentElement = table[currentSlot];
			// Skip all empty slots
			while (currentElement == null) {
				currentSlot++;
				currentElement = table[currentSlot];
			}
			// Skip all elements to reach last returned element
			if (lastReturnedElement != null) {
				currentElement = lastReturnedElement.next;
			} else {
				currentElement = table[currentSlot];
			}
			lastReturnedElement = currentElement;
			// End of elements in current slot, go to the next
			if (currentElement.next == null) {
				currentSlot++;
				lastReturnedElement = null;
			}
			this.remainingElements--;
			return currentElement;
		}
	}
}
