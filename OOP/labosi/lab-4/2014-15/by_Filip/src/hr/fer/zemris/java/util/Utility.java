package hr.fer.zemris.java.util;

import hr.fer.oop.lab3.topic1.shell.Environment;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.Arrays;

/**
 * Class used for things needed for this project. Mostly I/O operations.
 * 
 * @author Filip
 *
 */
final public class Utility {

	private Utility() {
	}

	/**
	 * Checks if the given value can be parsed as a double
	 * 
	 * @param value checked value
	 * @return <code>true</code> if can be parsed as a double,
	 *         <code>false</code> otherwise
	 */
	public static boolean isInteger(String value) {
		try {
			Integer.parseInt(value);
		} catch (Exception e) {
			return false;
		}
		return true;
	}

	/**
	 * Method used for copying directories from one place to another.
	 * 
	 * @param e environment
	 * @param arg0 path to the directory
	 * @param arg1 path to the destination
	 */
	public static void copyDir(Environment e, String arg0, String arg1) {
		File f1 = new File(arg0);
		File f2 = new File(arg1);

		if (!f1.isDirectory()) {
			e.writeln("Directory " + arg0 + " doesn't exist");
			return;
		}

		File f;

		if (f2.exists()) {
			if (f2.isDirectory()) {
				f = new File(arg1 + File.separator + f1.getName());
			} else {
				e.writeln("Destination is a file.");
				return;
			}
		} else {
			File parent = f2.getParentFile();
			if (!parent.isDirectory()) {
				e.writeln("Source directory doesn't exist");
				return;
			}
			f = f2;
		}

		if (!f.mkdir()) {
			e.writeln("Unable to create new directory");
			return;
		}

		copyDir1(f1, f.toPath(), f1.toPath());
	}

	/**
	 * Used for copying a directory from one place to another.
	 * 
	 * @param f1 starting directory
	 * @param pNew path to which directory is copied
	 * @param pOld path from which directory is copied
	 */
	private static void copyDir1(File f1, Path pNew, Path pOld) {
		if (f1 == null) {
			return;
		}
		for (File f : f1.listFiles()) {
			if (f == null) {
				continue;
			}

			Path path = pOld.relativize(f.toPath());
			path = pNew.resolve(path);

			if (f.isDirectory()) {
				path.toFile().mkdir();
				copyDir1(f, pNew, pOld);
			} else {
				try {
					copyFileUsingFileStreams(f.getAbsoluteFile(), path.toFile());
				} catch (IOException e1) {
				}
			}
		}
	}

	/**
	 * Copies a file from given location 'arg0' to 'arg1'
	 * 
	 * @param e environment
	 * @param arg0 source
	 * @param arg1 destination
	 */
	public static void copyFile(Environment e, String arg0, String arg1) {

		File f1 = new File(arg0);
		File f2 = new File(arg1);

		if (!f1.exists()) {
			e.writeln("File doesn't exist");
			return;
		}
		if (!f1.isFile()) {
			e.writeln("Given file doesn't exist");
			return;
		}

		File f;
		if (!f2.exists()) {
			f = f2;
			try {
				f.createNewFile();
			} catch (IOException ioe) {
				e.writeln("Couldn't create a new file.");
				return;
			}
		} else if (f2.isFile()) {
			e.writeln("Destination file already exists");
			return;
		} else {
			f = new File(f2.toString() + File.separator + f1.getName());
		}

		// copying from f1 to f
		try {
			copyFileUsingFileStreams(f1, f);
			e.writeln("Successfully copied " + arg0 + " to " + arg1);
		} catch (IOException ioe) {
			e.writeln("Error occured while copying files");
		}

	}

	/**
	 * Used for copying a file (source) to a new file (destination)
	 * 
	 * @param source source file
	 * @param dest destination file
	 * @throws IOException error with streams
	 */
	private static void copyFileUsingFileStreams(File source, File dest) throws IOException {

		try (InputStream input = new FileInputStream(source); OutputStream output = new FileOutputStream(dest)) {
			byte[] buf = new byte[1024];
			int bytesRead;
			while ((bytesRead = input.read(buf)) > 0) {
				output.write(buf, 0, bytesRead);
			}
			output.flush();
		}
	}

	/**
	 * Custom splitting that works with paths that have quotation marks in them
	 * 
	 * @param str string to split
	 * @return an array of strings from the parameter
	 */
	public static String[] mySplit(String str) {

		if (str.trim().isEmpty()) {
			return new String[0];
		}

		int argsCapacity = 10;

		String s = str.trim().replaceAll("\\s+", " ");
		String[] result = new String[argsCapacity];
		int i = 0;
		StringBuffer buff = new StringBuffer();
		int qm = 0; // quotationmark

		for (Character c : s.toCharArray()) {
			if (c == '\"') {
				qm++;
			} else if (c == ' ') {
				if (qm % 2 == 0) {
					if (i == argsCapacity - 2) {
						argsCapacity *= 2;
						result = Arrays.copyOf(result, argsCapacity);
					}
					result[i++] = buff.toString();
					buff.setLength(0);
				} else {
					// unutar navodnika
					buff.append(' ');
				}
			} else {
				buff.append(c);
			}
		}
		result[i++] = buff.toString();
		return Arrays.copyOfRange(result, 0, i);
	}

	/**
	 * Returns an absolute path given the current path stored in the active
	 * terminal in the environment.
	 * 
	 * @param e environment
	 * @param path path to resolve
	 * @return absolute path
	 */
	public static String getAbsPath(Environment e, String path) {
		Path p = Paths.get(path);
		if (!p.isAbsolute()) {
			p = e.getActiveTerminal().getCurrentPath().resolve(p);
		}
		return p.toString();
	}

	/**
	 * Returns a regex expression that resembles the parameter s.
	 * 
	 * @param s string to convert
	 * @return regex expression
	 */
	public static String getRegex(String s) {
		return s.replaceAll("\\.", "\\\\.").replaceAll("\\*", ".*");
	}

}
