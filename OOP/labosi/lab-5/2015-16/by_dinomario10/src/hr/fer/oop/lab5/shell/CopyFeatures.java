package hr.fer.oop.lab5.shell;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;

/**
 * An interface containing some default methods for copying classes.
 *
 * @author dinomario10
 */
public interface CopyFeatures {
	
	/**
	 * Used for extracting arguments passed to a copying function. This method
	 * currently supports only 2 arguments. If an argument has spaces in its
	 * name, it is necessary to surround it in quotation marks. Returns an
	 * array of strings containing extracted arguments.
	 * 
	 * @param s a string containing arguments
	 * @return an array of strings containing extracted arguments.
	 * @deprecated Use generic method {@linkplain Helper#extractArguments(String)}
	 */
	@Deprecated
	default String[] extractTwoArguments(String s) {
		String s1;
		String s2;
		int delimiter;
		
		if (s.startsWith("\"")) {
			delimiter = s.indexOf("\"", 1);
			s1 = s.substring(1, delimiter);
		} else {
			delimiter = s.indexOf(' ');
			s1 = s.substring(0, delimiter);
		}
		
		String substr = s.substring(delimiter+1).trim();
		if (substr.startsWith("\"")) {
			delimiter = substr.indexOf("\"", 1);
			s2 = substr.substring(1, delimiter);
		} else {
			s2 = substr;
		}
		
		String[] args = {s1, s2};
		return args;
	}

	/**
	 * A file creator method. It copies the exact same contents from the
	 * {@code originalFile} into the {@code parent} directory, creating a new
	 * file named {@code name}. This method also writes out the full path to the
	 * newly created file upon succeeding. <br>
	 * Implementation note: creates files using binary streams.
	 * 
	 * @param originalFile an original file to be copied
	 * @param parent the destination directory
	 * @param name name of the new file
	 * @param env an environment
	 */
	default void createNewFile(File originalFile, File parent, String name, Environment env) {
		File newFile = new File(parent, name);
		if (newFile.exists()) {
			env.writeln("The file cannot be copied onto itself.");
		} else {
			try (	FileInputStream in = new FileInputStream(originalFile);
					FileOutputStream out = new FileOutputStream(newFile)) {
				byte[] buff = new byte[1024];
				int len;
				while ((len = in.read(buff)) > 0) {
					out.write(buff, 0, len);
				}
				env.writeln("Copy: " + newFile);
			} catch (IOException e) {
				env.writeln("An error occured during the copying of file " + originalFile);
				env.writeln(e.getMessage());
			}
		}
	}

}
