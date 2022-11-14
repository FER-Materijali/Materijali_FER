package hr.fer.oop.lab3.topic1.shell;

import java.nio.file.Path;
import java.nio.file.Paths;

/**
 * Terminals in {@link MyShell}.
 * 
 * @author Filip
 *
 */
public class Terminal {

	int id;
	Path currentPath;

	/**
	 * Creates a new terminal with given id
	 * 
	 * @param id terminals id
	 */
	public Terminal(int id) {
		this.id = id;
		setCurrentPath(Paths.get("."));
	}

	/**
	 * Return terminals id
	 * 
	 * @return id
	 */
	public int getId() {
		return id;
	}

	/**
	 * return current path in the terminal
	 * 
	 * @return current path
	 */
	public Path getCurrentPath() {
		return currentPath;
	}

	/**
	 * Set new path
	 * 
	 * @param currentPath new path to set
	 */
	public void setCurrentPath(Path currentPath) {
		this.currentPath = currentPath.toAbsolutePath().normalize();
	}

}
