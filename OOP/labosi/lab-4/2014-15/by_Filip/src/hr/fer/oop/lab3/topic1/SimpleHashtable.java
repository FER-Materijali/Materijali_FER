package hr.fer.oop.lab3.topic1;

import java.util.Iterator;

/**
 * This class implements a simple hash table used for storing objects. We use
 * <code>|hashcode(key)| % capacity<code> to determine the slot.
 * 
 * @author Filip
 */
public class SimpleHashtable<K, V> implements
		Iterable<SimpleHashtable.TableEntry<K, V>> {

	@SuppressWarnings("unchecked")
	public static void main(String[] args) {
		// create collection:
		SimpleHashtable<String, Integer> examMarks = new SimpleHashtable<>(2);
		// fill data:
		examMarks.put("Ivana", Integer.valueOf(2));
		examMarks.put("Ante", Integer.valueOf(2));
		examMarks.put("Jasna", Integer.valueOf(2));
		examMarks.put("Kristina", Integer.valueOf(5));
		examMarks.put("Ivana", Integer.valueOf(5)); // overwrites old grade for
													// Ivana
		for (Object entry : examMarks) {
			SimpleHashtable.TableEntry<String, Integer> pair = (SimpleHashtable.TableEntry<String, Integer>) entry;
			System.out.printf("%s => %s%n", pair.getKey(), pair.getValue());
		}

		SimpleHashtable<String, Integer> exams = new SimpleHashtable<>();
		exams.put("Ivana", Integer.valueOf(5));
		exams.put("Janko", Integer.valueOf(4));
		for (String name : exams.keys()) {
			System.out.println("Ime = " + name);
		}
		for (Integer grade : exams.values()) {
			System.out.println("Ocjena = " + grade);
		}
		for (SimpleHashtable.TableEntry<String, Integer> pair : exams) {
			System.out.println("(Ime, Ocjena) = (" + pair.getKey() + ", "
					+ pair.getValue() + ")");
		}

	}

	/**
	 * Default capacity, if none is provided.
	 */
	private static final int DEFAULT_SLOT_CAPACITY = 1 << 4;

	/**
	 * Table to store our data.
	 */
	private TableEntry<K, V>[] slots;

	/**
	 * Size of the hash table (number of elements).
	 */
	private int size;

	/**
	 * Creates a new hash table with default capacity.
	 */
	public SimpleHashtable() {
		this(DEFAULT_SLOT_CAPACITY);
	}

	/**
	 * Creates a new hash table with desired capacity rounded to the nearest >=
	 * power of 2.
	 * 
	 * @param capacity
	 *            desired capacity
	 */
	@SuppressWarnings("unchecked")
	public SimpleHashtable(int capacity) {
		if (capacity <= 0) {
			throw new IllegalArgumentException(
					"Table capacity must be positive.");
		}
		size = 0;
		final int c = adjustCapacity(capacity);
		slots = new TableEntry[c];
	}

	/**
	 * Inserts a value into the hash table. If there already was such key, it is
	 * overwritten. Otherwise, it is inserted.
	 * 
	 * @param key
	 *            key of the object
	 * @param value
	 *            value of the object
	 */
	public void put(K key, V value) {
		int slot = getSlot(key);
		TableEntry<K, V> teNew = new TableEntry<K, V>(key, value, null);

		if (slots[slot] == null) {
			slots[slot] = teNew;
			size++;
			return;
		}

		TableEntry<K, V> te = slots[slot];

		while (te != null) {
			if (te.getKey().equals(key)) {
				te.setValue(value);
				return;
			}
			te = te.getNext();
		}

		// adding the new entry to the front of the slot
		// because I don't have a reference to the last
		// one anymore

		slots[slot] = new TableEntry<K, V>(key, value, slots[slot]);
		size++;

	}

	/**
	 * Returns an iterable that iterates over keys
	 * 
	 * @return iterator of keys
	 */
	public Iterable<K> keys() {
		return new Iterable<K>() {

			@Override
			public Iterator<K> iterator() {
				return new Iterator<K>() {

					Iterator<TableEntry<K, V>> tableIterator = new HashIterator();

					@Override
					public boolean hasNext() {
						return tableIterator.hasNext();
					}

					@Override
					public K next() {
						return tableIterator.next().getKey();
					}

					@Override
					public void remove() {
						//
					}

				};
			}

		};
	}

	/**
	 * Returns an iterable object that iterates over values
	 * 
	 * @return iterator over values
	 */
	public Iterable<V> values() {
		return new Iterable<V>() {

			@Override
			public Iterator<V> iterator() {
				return new Iterator<V>() {

					Iterator<TableEntry<K, V>> tableIterator = new HashIterator();

					@Override
					public boolean hasNext() {
						return tableIterator.hasNext();
					}

					@Override
					public V next() {
						return tableIterator.next().getValue();
					}

					@Override
					public void remove() {
						//
					}

				};
			}

		};
	}

	/**
	 * Returns the value of the object stored under <code>key</code>. If there
	 * is no such key in the table, <code>null</code> is returned.
	 * 
	 * @param key
	 *            key of the object
	 * @return value of the object, <code>null</code> if there isn't such key
	 */
	public V get(K key) {
		int slot = getSlot(key);
		TableEntry<K, V> te = slots[slot];

		while (te != null) {
			if (te.getKey().equals(key)) {
				return te.getValue();
			}
			te = te.getNext();
		}

		return null;
	}

	/**
	 * Returns the size of the hash table (number of elements).
	 * 
	 * @return number of elements in the hash table
	 */
	public int size() {
		return size;
	}

	/**
	 * Checks if table contains given key. Complexity is O(1)
	 * 
	 * @param key
	 *            key of the object
	 * @return <code>true</code> if it contains, <code>false</code> otherwise
	 */
	public boolean containsKey(Object key) {
		int slot = getSlot(key);
		TableEntry<K, V> te = slots[slot];

		while (te != null) {
			if (te.getKey().equals(key)) {
				return true;
			}
			te = te.getNext();
		}

		return false;
	}

	/**
	 * Checks if table contains given value. Complexity is O(n)
	 * 
	 * @param value
	 *            value of the object
	 * @return <code>true</code> if it contains, <code>false</code> otherwise
	 */
	public boolean containsValue(Object value) {
		for (int i = 0; i < slots.length; i++) {
			TableEntry<K, V> te = slots[i];
			while (te != null) {
				if (te.getValue().equals(value)) {
					return true;
				}
				te = te.getNext();
			}
		}
		return false;
	}

	/**
	 * Removes a object with the given key from the table (if there is such
	 * object).
	 * 
	 * @param key
	 *            key of the object
	 */
	public void remove(Object key) {
		int slot = getSlot(key);
		TableEntry<K, V> te = slots[slot];

		if (te == null) {
			return; // there is no such key
		}

		if (te.getKey().equals(key)) {
			// remove the first
			slots[slot] = te.getNext();
			size--;
			return;
		}

		TableEntry<K, V> next = te.getNext();

		while (next != null) {
			if (next.getKey().equals(key)) {
				te.setNext(next.getNext());
				size--;
				return;
			}
			next = next.getNext();
			te = te.getNext();
		}
	}

	/**
	 * Returns whether the table is empty.
	 * 
	 * @return <code>true</code> if it's empty, <code>false</code> otherwise
	 */
	public boolean isEmpty() {
		return size() == 0;
	}

	/**
	 * Returns a string representation of the hash table.
	 */
	public String toString() {
		String elements = "";

		for (int i = 0; i < slots.length; i++) {
			TableEntry<K, V> t = slots[i];
			while (t != null) {
				elements += t.toString();
				elements += "; ";
				t = t.getNext();
			}
		}

		if (!elements.isEmpty()) {
			elements = elements.substring(0, elements.length() - 2);
		}

		return getClass().getSimpleName() + "[" + elements + "]";
	}

	/**
	 * Adjusts the capacity to the first equal or greater power of 2.
	 * 
	 * @param c
	 *            capacity to adjust
	 * @return adjusted capacity
	 */
	private static int adjustCapacity(int c) {
		int i = 0;
		while (1 << (i++) < c)
			;
		return 1 << (i - 1);
	}

	/**
	 * Returns the slot in which key belongs.
	 * 
	 * @param key
	 *            key of the object
	 * @return slot number
	 */
	private int getSlot(Object key) {
		if (key == null) {
			throw new IllegalArgumentException("Key can't be 'null'.");
		}
		return Math.abs(key.hashCode()) % slots.length;
	}

	/**
	 * A helper class used to represent a table entry. It has a pointer to the
	 * next entry in the slot so it acts as a list.
	 * 
	 * @author Filip
	 */
	public static class TableEntry<K, V> {

		/**
		 * Key of the entry.
		 */
		private K key;
		/**
		 * Value of the entry.
		 */
		private V value;
		/**
		 * Next table entry in the slot.
		 */
		private TableEntry<K, V> next;

		/**
		 * Creates a new table entry with given key and value. Key can't be
		 * <code>null</code>.
		 * 
		 * @param key
		 *            desired key
		 * @param value
		 *            desired value
		 * @param next
		 *            reference to the next entry
		 */
		public TableEntry(K key, V value, TableEntry<K, V> next) {
			if (key == null) {
				throw new IllegalArgumentException("Key can't be null");
			}

			this.key = key;
			this.value = value;
			this.next = next;
		}

		public K getKey() {
			return key;
		}

		public V getValue() {
			return value;
		}

		public void setValue(V value) {
			this.value = value;
		}

		public void setNext(TableEntry<K, V> next) {
			this.next = next;
		}

		public TableEntry<K, V> getNext() {
			return next;
		}

		@Override
		public String toString() {
			return key + "=" + (value == null ? "?" : value);
		}

	}

	@Override
	public Iterator<TableEntry<K, V>> iterator() {
		return new HashIterator();
	}

	/**
	 * Class used to iterate over a hash table
	 * 
	 * @author Filip
	 *
	 */
	private class HashIterator implements Iterator<TableEntry<K, V>> {

		int slot;
		TableEntry<K, V>[] table;
		TableEntry<K, V> current;

		public HashIterator() {
			table = SimpleHashtable.this.slots;
			slot = -1;
			findNext(slot);
		}

		/**
		 * Searches for the next slot in which there are some entries.
		 * 
		 * @param slot
		 *            slot in which last entry was found
		 */
		private void findNext(int slot) {
			this.slot = table.length;
			for (int i = slot + 1; i < table.length; i++) {
				if (table[i] != null) {
					current = table[i];
					this.slot = i;
					break;
				}
			}
		}

		@Override
		public boolean hasNext() {
			if (current != null) {
				return true;
			}
			findNext(slot);
			if (current != null) {
				return true;
			}
			return false;
		}

		@Override
		public TableEntry<K, V> next() {
			TableEntry<K, V> retval = current;
			current = current.next;
			return retval;
		}

		@Override
		public void remove() {
			//
		}

	}
}
