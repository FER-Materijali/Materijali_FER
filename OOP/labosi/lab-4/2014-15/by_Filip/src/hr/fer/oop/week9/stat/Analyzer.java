package hr.fer.oop.week9.stat;

import java.io.IOException;
import java.nio.file.FileVisitResult;
import java.nio.file.FileVisitor;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.attribute.BasicFileAttributes;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Analyzer implements FileVisitor<Path> {

	public static void main(String[] args) throws IOException {
		if (args.length != 1) {
			System.err.println("Očekujem 1 argument: putanju do direktorija.");
			System.exit(0);
		}

		Path p = Paths.get(args[0]);
		if (!p.toFile().isDirectory()) {
			System.err.println("Predana staza nije staza do direktorija.");
			System.exit(0);
		}

		Analyzer a = new Analyzer();
		Files.walkFileTree(p, a);

		System.out.println("# ~ =========== Statistika ============ ~ #");
		System.out.println("# ~ ========== Po ekstenziji ========== ~ #");
		for (DataEntry d : a.getByExtension()) {
			System.out.println(d);
		}
		System.out.println("# ~ ========= Po prvom slovu ========== ~ #");
		for (DataEntry d : a.getByLetter()) {
			System.out.println(d);
		}
		System.out.println("# ~ =================================== ~ #");
		System.out.println("Ukupna veličina: " + a.getAllSize());
		System.out.println("Ukupan broj:     " + a.getAllNumber());

	}

	public static class DataEntry {

		private String key;
		private long size;
		private int n;

		public DataEntry(String key) {
			size = 0L;
			n = 0;
			this.key = key;
		}

		void addFile(Path p) {
			n++;
			size += p.toFile().length();
		}

		public String getKey() {
			return key;
		}

		public int getN() {
			return n;
		}

		public long getSize() {
			return size;
		}

		@Override
		public String toString() {
			return key + " [size=" + size + "; number=" + n + "]";
		}

	}

	private static List<DataEntry> getBy(Map<String, DataEntry> map, Comparator<DataEntry> c) {
		List<DataEntry> ret = new ArrayList<>(map.values());
		Collections.sort(ret, c);
		return ret;
	}

	private static final String getExtension(Path p) {
		String name = p.toFile().getName().toLowerCase();
		int i = name.lastIndexOf('.');
		if (i == -1 || i == name.length()) {
			return "";
		}
		return name.substring(i + 1);
	}

	private static final String getFirstLetter(Path p) {
		String name = p.toFile().getName().toLowerCase();
		char first = name.charAt(0);
		if (Character.isLetter(first)) {
			return Character.valueOf(first).toString();
		} else {
			return "-";
		}
	}

	private Map<String, DataEntry> extension;

	private Map<String, DataEntry> letter;

	private DataEntry allTogether;

	public Analyzer() {
		extension = new HashMap<>();
		letter = new HashMap<>();
		allTogether = new DataEntry("");
	}

	public int getAllNumber() {
		return allTogether.getN();
	}

	public long getAllSize() {
		return allTogether.getSize();
	}

	public List<DataEntry> getByExtension() {
		return getBy(extension, BY_SIZE);
	}

	public List<DataEntry> getByLetter() {
		return getBy(letter, BY_NAME);
	}

	@Override
	public FileVisitResult postVisitDirectory(Path dir, IOException exc) throws IOException {
		return FileVisitResult.CONTINUE;
	}

	@Override
	public FileVisitResult preVisitDirectory(Path dir, BasicFileAttributes attrs) throws IOException {
		return FileVisitResult.CONTINUE;
	}

	@Override
	public FileVisitResult visitFile(Path file, BasicFileAttributes attrs) throws IOException {

		String ext = getExtension(file);
		DataEntry de = extension.get(ext);
		if (de == null) {
			de = new DataEntry(ext);
		}
		de.addFile(file);
		extension.put(ext, de);

		String l = getFirstLetter(file);
		DataEntry dc = letter.get(l);
		if (dc == null) {
			dc = new DataEntry(l);
		}
		dc.addFile(file);
		letter.put(l, dc);

		allTogether.addFile(file);
		return FileVisitResult.CONTINUE;

	}

	@Override
	public FileVisitResult visitFileFailed(Path file, IOException exc) throws IOException {
		return FileVisitResult.CONTINUE;
	}

	/**
	 * Compares files by their size.
	 */
	private static final Comparator<DataEntry> BY_SIZE = new Comparator<DataEntry>() {
		@Override
		public int compare(DataEntry o1, DataEntry o2) {
			int c = -Long.compare(o1.getSize(), o2.getSize());
			if (c == 0) {
				return BY_NAME.compare(o1, o2);
			}
			return c;
		}
	};

	/**
	 * Compares files by their name.
	 */
	private static final Comparator<DataEntry> BY_NAME = new Comparator<DataEntry>() {
		@Override
		public int compare(DataEntry o1, DataEntry o2) {
			return o1.getKey().compareTo(o2.getKey());
		}
	};

}
