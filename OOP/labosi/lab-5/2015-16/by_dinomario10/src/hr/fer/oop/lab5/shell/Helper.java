package hr.fer.oop.lab5.shell;

import java.nio.file.InvalidPathException;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.List;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 * A helper class. Used for defining and providing helper methods.
 *
 * @author dinomario10
 */
public class Helper {
	
	/**
	 * Resolves the given path by checking if it's relative or absolute. If the
	 * {@code str} path parameter is an absolute path then this method trivially
	 * returns the given path. In the simplest case, the given path does not
	 * have a root component, in which case this method joins the given path
	 * with the root and returns the absolute path. If the given path has
	 * invalid characters {@code null} value is returned.
	 * 
	 * @param env an environment
	 * @param str the given path string
	 * @return the absolute path of the given path
	 */
	public static Path resolveAbsolutePath(Environment env, String str) {
		str = str.replace("\"", "");
		
		Path path;
		try {
			path = Paths.get(str);
		} catch (InvalidPathException e) {
			return null;
		}
		
		Path newPath;
		if (path.isAbsolute()) {
			newPath = path;
		} else {
			newPath = env.getCurrentPath().resolve(path).normalize();
		}
		return newPath;
	}
	
	/**
	 * Used for extracting arguments passed to a function. This method
	 * supports an unlimited number of arguments, and can be inputed either
	 * with quotation marks or not. Returns an array of strings containing the
	 * extracted arguments.
	 * 
	 * @param s a string containing arguments
	 * @return an array of strings containing extracted arguments.
	 */
	public static String[] extractArguments(String s) {
		List<String> list = new ArrayList<>();
		
		String regex = "\"([^\"]*)\"|(\\S+)";
		Matcher m = Pattern.compile(regex).matcher(s);
		while (m.find()) {
			if (m.group(1) != null) {
				list.add(m.group(1));
			} else {
				list.add(m.group(2));
			}
		}

		return list.toArray(new String[list.size()]);
	}
	
	/**
	 * Converts the number of bytes to a human readable byte count with binary
	 * prefixes.
	 * 
	 * @param bytes number of bytes
	 * @return human readable byte count with binary prefixes
	 */
	public static String humanReadableByteCount(long bytes) {
		/* Use the natural 1024 units and binary prefixes. */
		int unit = 1024;
		if (bytes < unit) return bytes + " B";
		int exp = (int) (Math.log(bytes) / Math.log(unit));
		String pre = "kMGTPE".charAt(exp - 1) + "i";
		return String.format("%.1f %sB", bytes / Math.pow(unit, exp), pre);
	}
	
}
