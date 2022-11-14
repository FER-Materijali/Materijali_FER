package hr.fer.oop.lab6.prob2;

import java.util.Arrays;

/**
 * The Enum CellState.
 */
public enum CellState {

	/** The dead. */
	DEAD,
	/** The alive. */
	ALIVE;

	/**
	 * Array of default.
	 *
	 * @param width
	 *            the width
	 * @param height
	 *            the height
	 * @return the cell state[][]
	 */
	public static CellState[][] arrayOfDefault(int width, int height) {
		CellState[][] result = new CellState[width][height];
		for (int i = 0; i < result.length; i++) {
			Arrays.fill(result[i], DEAD);
		}
		return result;
	}
}
