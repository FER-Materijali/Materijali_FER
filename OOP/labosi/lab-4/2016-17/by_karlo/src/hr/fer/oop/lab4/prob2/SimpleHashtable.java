package hr.fer.oop.lab4.prob2;

import java.util.NoSuchElementException;

/**
 * A class that represents a simple Hash Table.
 *
 * @author karlo
 * @param <K>
 *            the key type
 * @param <V>
 *            the value type
 */
public class SimpleHashtable<K, V> implements Obilaznik<K> {

	/**
	 * The Class TableEntry.
	 *
	 * @param <K>
	 *            the key type
	 * @param <V>
	 *            the value type
	 */
	private static class TableEntry<K, V> {

		/** The key. */
		private final K key;

		/** The value. */
		private V value;

		/** The next. */
		private TableEntry<K, V> next;

		/**
		 * Instantiates a new table entry.
		 *
		 * @param key
		 *            the key
		 * @param value
		 *            the value
		 * @param next
		 *            the next
		 */
		public TableEntry(K key, V value, TableEntry<K, V> next) {
			this.key = key;
			this.value = value;
			this.next = next;
		}

		/**
		 * Gets the key.
		 *
		 * @return the key
		 */
		public K getKey() {
			return key;
		}

		/**
		 * Gets the value.
		 *
		 * @return the value
		 */
		public V getValue() {
			return value;
		}

		/**
		 * Sets the value.
		 *
		 * @param value
		 *            the new value
		 */
		public void setValue(V value) {
			this.value = value;
		}

		/*
		 * (non-Javadoc)
		 * 
		 * @see java.lang.Object#toString()
		 */
		@Override
		public String toString() {
			return "Key: " + getKey() + "\tValue: " + getValue();
		}
	}

	/** The Constant DEFAULT_SIZE. */
	private static final int DEFAULT_SIZE = 16;

	/** The table. */
	private TableEntry<K, V>[] table;

	/** The size. */
	private int size;

	/**
	 * Instantiates a new simple hashtable.
	 */
	@SuppressWarnings("unchecked")
	public SimpleHashtable() {
		table = (TableEntry<K, V>[]) new TableEntry<?, ?>[DEFAULT_SIZE];
		size = 0;
	}

	/**
	 * Instantiates a new simple hashtable.
	 *
	 * @param capacity
	 *            the capacity
	 */
	@SuppressWarnings("unchecked")
	public SimpleHashtable(int capacity) {
		if (capacity < 0) {
			throw new IllegalArgumentException("Capacity can't be negative");
		}

		capacity = nextPowerOfTwo(capacity);
		table = (TableEntry<K, V>[]) new TableEntry<?, ?>[capacity];
		size = 0;
	}

	/**
	 * Next power of two.
	 *
	 * @param x
	 *            the x
	 * @return the int
	 */
	private static int nextPowerOfTwo(int x) {
		return (int) Math.pow(2, Math.ceil(Math.log10(x) / Math.log10(2)));
	}

	/**
	 * Gets the hash.
	 *
	 * @param key
	 *            the key
	 * @return the hash
	 */
	private int getHash(K key) {
		return Math.abs(key.hashCode()) % table.length;
	}

	/**
	 * Puts the element with the given key and value.
	 *
	 * @param key
	 *            the key
	 * @param value
	 *            the value
	 */
	public void put(K key, V value) {
		if (key == null) {
			return;
		}
		int hash = getHash(key);
		if (table[hash] == null) {
			table[hash] = new TableEntry<>(key, value, null);
			size++;
		} else {
			TableEntry<K, V> entry = table[hash];
			while (entry.next != null && entry.getKey() != key) {
				entry = entry.next;
			}

			if (key == entry.getKey()) {
				entry.setValue(value);
			} else {
				entry.next = new TableEntry<>(key, value, null);
				size++;
			}
		}
	}

	/**
	 * Gets the element with the given key.
	 *
	 * @param key
	 *            the key
	 * @return the v
	 */
	public V get(K key) {
		if (key == null) {
			return null;
		}
		int hash = getHash(key);
		TableEntry<K, V> head = table[hash];
		while (head != null) {
			if (head.getKey().equals(key)) {
				return head.getValue();
			}
			head = head.next;
		}
		return null;
	}

	/**
	 * Table size.
	 *
	 * @return the int
	 */
	public int size() {
		return size;
	}

	/**
	 * Checks if the table contains the given key.
	 *
	 * @param key
	 *            the key
	 * @return true, if successful
	 */
	public boolean containsKey(K key) {
		if (key == null) {
			return false;
		}
		int hash = getHash(key);
		TableEntry<K, V> entry = table[hash];
		while (entry != null && entry.getKey() != key) {
			entry = entry.next;
		}

		return entry != null;
	}

	/**
	 * Checks if the table contains the given value.
	 *
	 * @param value
	 *            the value
	 * @return true, if successful
	 */
	public boolean containsValue(V value) {
		for (TableEntry<K, V> entry : table) {
			while (entry != null) {
				if (entry.getValue().equals(value)) {
					return true;
				}
				entry = entry.next;
			}
		}
		return false;
	}

	/**
	 * Removes the element by the given key.
	 *
	 * @param key
	 *            the key
	 */
	public void remove(K key) {
		if (key == null) {
			return;
		}
		int hash = getHash(key);
		TableEntry<K, V> head = table[hash];
		TableEntry<K, V> prev = null;
		while (head != null) {
			if (head.getKey().equals(key)) {
				break;
			}
			prev = head;
			head = head.next;
		}
		if (head == null) {
			throw new NoSuchElementException("Key: '" + key + "' does not exist");
		}
		if (prev != null) {
			prev.next = head.next;
		} else {
			table[hash] = head.next;
		}
		size--;
	}

	/**
	 * Checks if the table is empty.
	 *
	 * @return true, if it's empty
	 */
	public boolean isEmpty() {
		return size() == 0;
	}

	/*
	 * (non-Javadoc)
	 * 
	 * @see java.lang.Object#toString()
	 */
	@Override
	public String toString() {
		StringBuilder sb = new StringBuilder();
		int i = 0;
		for (TableEntry<K, V> entry : table) {
			while (entry != null) {
				String text = String.format("Entry[%d]: ", i++);
				sb.append(text).append(entry.toString()).append("\n");
				entry = entry.next;
			}
		}
		return sb.toString();
	}

	/** The last entry. */
	private TableEntry<K, V> lastEntry;

	/** The obilaznik. */
	private Obilaznik<K> obilaznik;

	/**
	 * Instantiates a new simple hashtable.
	 *
	 * @param obj
	 *            the obj
	 */
	public SimpleHashtable(SimpleHashtable<K, V> obj) {
		if (obj == null) {
			throw new IllegalArgumentException("Argument can't be null");
		}

		table = obj.table;
		size = obj.size();
	}

	/**
	 * Stvori obilaznik.
	 *
	 * @return the obilaznik
	 */
	public Obilaznik<K> stvoriObilaznik() {
		if (obilaznik == null) {
			obilaznik = new SimpleHashtable<>(this);
		}
		return obilaznik;
	}

	/*
	 * (non-Javadoc)
	 * 
	 * @see hr.fer.oop.lab4.prob2.Obilaznik#vratiSljedeceg()
	 */
	@Override
	public K vratiSljedeceg() {
		for (TableEntry<K, V> entry : table) {
			while (entry != null) {
				if (lastEntry == null) {
					lastEntry = entry;
					return lastEntry.getKey();
				}
				if (entry == lastEntry) {
					lastEntry = entry.next;
					if (lastEntry == null) {
						break;
					}
					return lastEntry.getKey();
				}
				entry = entry.next;
			}
		}
		return null;
	}

}
