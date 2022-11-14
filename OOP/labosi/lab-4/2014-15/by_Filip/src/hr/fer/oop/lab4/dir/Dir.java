package hr.fer.oop.lab4.dir;

import hr.fer.zemris.java.util.Utility;

import java.io.File;
import java.io.FileFilter;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

public class Dir {

	private File dir;
	private String type;
	private String filter;

	private List<File> files;

	/**
	 * Creates a new Dir object. It filters out files by given filter and type,
	 * and sorts them by given sort attributes.
	 * 
	 * @param dir
	 *            directory
	 * @param sort
	 *            sort attributes
	 * @param type
	 *            type of files
	 * @param filter
	 *            filter
	 */
	public Dir(File dir, String sort, String type, String filter) {
		this.dir = dir;
		this.type = type;
		this.filter = Utility.getRegex(filter);
		filterOut();
		if (!sort.isEmpty()) {
			Collections.sort(files, FileComparator.fromString(sort));
		}
	}

	/**
	 * Returns files in this dir.
	 * 
	 * @return files
	 */
	public List<File> files() {
		return files;
	}

	/**
	 * Used for filtering out by type and given filter.
	 */
	private void filterOut() {
		final FileFilter byType = new FileFilter() {

			private String type = Dir.this.type;
			private boolean file = type.equalsIgnoreCase("f");
			private boolean directory = type.equalsIgnoreCase("d");

			@Override
			public boolean accept(File f) {
				if (directory) {
					return f.isDirectory();
				}
				if (file) {
					return f.isFile();
				} else {
					return true;
				}
			}
		};

		final FileFilter byName = new FileFilter() {

			private String filter = Dir.this.filter;
			boolean isEmpty = filter.isEmpty();

			@Override
			public boolean accept(File f) {
				if (isEmpty) {
					return true;
				} else {
					return f.getName().matches(Dir.this.filter);
				}
			}
		};

		FileFilter all = new FileFilter() {

			@Override
			public boolean accept(File f) {
				return byName.accept(f) && byType.accept(f);
			}
		};

		this.files = Arrays.asList(dir.listFiles(all));
	}

}
