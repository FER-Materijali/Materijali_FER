package hr.fer.oop.lab4.dir;

import java.io.File;
import java.io.Serializable;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * Used for applying multiple comparators.
 * 
 * @author Filip Hreni�
 * @version 1.0
 */
public class FileComparator implements Comparator<File>, Serializable {

	/**
	 * Serial Version UID
	 */
	private static final long serialVersionUID = 452664393058640568L;
	/**
	 * Used to store comparators.
	 */
	private List<Comparator<File>> list;

	/**
	 * Creates a new comparator that uses its internal comparators to compare
	 * Files.
	 * 
	 * @param comparators wanted comparators
	 */
	private FileComparator(final List<Comparator<File>> comparators) {
		this.list = new ArrayList<>(comparators);
	}

	/**
	 * Creates a new file comparator from the given string. Supports esdnt
	 * characters in given string
	 * 
	 * @param s string
	 * @return file comparator
	 */
	public static FileComparator fromString(String s) {
		char[] original = s.toCharArray();
		String lowerS = s.toLowerCase();
		char[] lower = lowerS.toCharArray();

		List<Comparator<File>> comparators = new ArrayList<>();

		for (int i = 0; i < lower.length; i++) {

			Comparator<File> comp = mapaKomparatora.get(Character.valueOf(lower[i]));
			if (comp == null) {
				throw new IllegalArgumentException("Unkown sorting attribute: " + original[i]);
			}
			if (Character.isUpperCase(original[i])) {
				comp = Collections.reverseOrder(comp);
			}
			comparators.add(comp);
		}
		return new FileComparator(comparators);
	}

	/**
	 * Compares the two Files by all given comparators.
	 * 
	 * @param o1 first file
	 * @param o2 second file
	 * @return negative, zero or positive number if the f1 is "smaller", equal
	 *         or "bigger"
	 */
	@Override
	public final int compare(final File o1, final File o2) {
		for (Comparator<File> comparator : this.list) {
			int c = comparator.compare(o1, o2);
			if (c != 0) {
				return c;
			}
		}
		return 0;
	}

	/**
	 * Compares files by their extension.
	 */
	public static final Comparator<File> BY_EXTENSION = new Comparator<File>() {
		@Override
		public int compare(File o1, File o2) {
			return getExtension(o1).compareTo(getExtension(o2));
		}
	};

	/**
	 * Compares files by their size.
	 */
	public static final Comparator<File> BY_SIZE = new Comparator<File>() {
		@Override
		public int compare(File o1, File o2) {
			return Long.compare(o1.length(), o2.length());
		}
	};

	/**
	 * Compares files by last modification.
	 */
	public static final Comparator<File> BY_LAST_MODIFICATION = new Comparator<File>() {
		@Override
		public int compare(File o1, File o2) {
			return Long.compare(o1.lastModified(), o2.lastModified());
		}
	};

	/**
	 * Compares files by their name.
	 */
	public static final Comparator<File> BY_NAME = new Comparator<File>() {
		@Override
		public int compare(File o1, File o2) {
			return o1.getName().compareTo(o2.getName());
		}
	};

	/**
	 * Compares files by type, directories are "smaller" than files.
	 */
	public static final Comparator<File> BY_TYPE = new Comparator<File>() {
		@Override
		public int compare(File o1, File o2) {
			if (o1.isDirectory() && o2.isFile()) {
				return -1;
			} else if (o1.isFile() && o2.isDirectory()) {
				return 1;
			}
			return 0;
		}
	};

	/* mapa za dobavljanje comparatora */
	private static Map<Character, Comparator<File>> mapaKomparatora = new HashMap<>();
	static {
		mapaKomparatora.put(Character.valueOf('e'), BY_EXTENSION);
		mapaKomparatora.put(Character.valueOf('s'), BY_SIZE);
		mapaKomparatora.put(Character.valueOf('d'), BY_LAST_MODIFICATION);
		mapaKomparatora.put(Character.valueOf('n'), BY_NAME);
		mapaKomparatora.put(Character.valueOf('t'), BY_TYPE);
	}

	/**
	 * Returns file's extension
	 * 
	 * @param f file
	 * @return extension
	 */
	private static final String getExtension(File f) {
		String name = f.getName().toLowerCase();
		int i = name.lastIndexOf('.');
		if (i == -1 || i == name.length()) {
			return "";
		}
		return name.substring(i + 1);
	}

}
