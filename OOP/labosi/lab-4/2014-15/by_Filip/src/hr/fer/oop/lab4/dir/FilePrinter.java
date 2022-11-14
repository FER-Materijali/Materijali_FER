package hr.fer.oop.lab4.dir;

import hr.fer.oop.lab3.topic1.shell.Environment;

import java.io.File;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * Used for printing out files/directories contained in the given directory.
 * 
 * @author Filip Hreni�
 * @version 1.0
 */
public class FilePrinter {

	/**
	 * Files that we want to print.
	 */
	private List<File> files;
	/**
	 * Types of attributes (n for name, l for length...)
	 */
	private List<String> types;
	/**
	 * Records to be printed, {@link FileRecord} determines the format.
	 */
	private List<FileRecord> records;
	/**
	 * List of maximal sizes of attributes in a column.
	 */
	private List<Integer> maxSizes;

	/**
	 * Creates new file printer
	 * 
	 * @param files files to be printed
	 * @param types what attributes to print (n for name, l for length...)
	 */
	public FilePrinter(List<File> files, List<String> types) {
		this.files = new ArrayList<>(files);
		if (types.isEmpty()) {
			this.types = Arrays.asList("n");
		} else {
			this.types = new ArrayList<>(types);
		}

		this.createRecords();
		this.createMaxSizes(this.types.size());
	}

	/**
	 * Generates max sizes for print
	 */
	private void createMaxSizes(int size) {
		// initialize maxSizes
		this.maxSizes = new ArrayList<>(size);
		for (int i = 0; i < size; i++) {
			this.maxSizes.add(0);
		}

		int limit = this.types.size();
		for (FileRecord fr : this.records) {
			for (int i = 0; i < limit; i++) {
				this.maxSizes.set(i, Math.max(this.maxSizes.get(i), fr.getAttribute(i).length()));
			}
		}
	}

	/**
	 * Creates records from files.
	 * 
	 * @return list of records
	 */
	private void createRecords() {
		this.records = new ArrayList<>();
		for (File f : this.files) {
			this.records.add(new FileRecord(f, this.types));
		}
	}

	/**
	 * Prints the records.
	 */
	public void printRecords(Environment e) {
		if (this.records.size() == 0) {
			e.writeln("Output done, no files selected.");
			return;
		}

		String headerFooter = this.createHeaderFooter(maxSizes);
		e.writeln(headerFooter);
		for (FileRecord r : this.records) {
			e.writeln(r.printRecord(maxSizes));
		}
		e.writeln(headerFooter);

		e.writeln("Output done, " + this.records.size() + " file" + (this.records.size() == 1 ? "" : "s")
				+ " selected.");
	}

	/**
	 * Creates a header/footer for the print. +----+---+--------+ format
	 * 
	 * @param sizes widths of columns
	 * @return a string
	 */
	private String createHeaderFooter(List<Integer> sizes) {
		StringBuilder s = new StringBuilder();
		s.append("+");
		for (Integer i : sizes) {
			for (int j = 0; j < i + 2; j++) {
				s.append("-");
			}
			s.append("+");
		}
		return s.toString();
	}

}
