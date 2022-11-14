package hr.fer.oop.lab6.prob2;

import java.util.*;

/**
 * The Class Board.
 */
public class Board {

	/** The height. */
	private int width, height;
	
	/** The board. */
	private CellState[][] board;

	/** The listeners. */
	private LinkedList<BoardListener> listeners = new LinkedList<>();

	/**
	 * Instantiates a new board.
	 *
	 * @param width the width
	 * @param height the height
	 */
	public Board(int width, int height) {
		this.width = width;
		this.height = height;
		board = CellState.arrayOfDefault(width, height);
	}

	/**
	 * Checks if is cell alive.
	 *
	 * @param x the x
	 * @param y the y
	 * @return true, if is cell alive
	 */
	public boolean isCellAlive(int x, int y) {
		if (x < 0 || y < 0 || x >= getWidth() || y >= getHeight())
			return false;
		return board[x][y] == CellState.ALIVE;
	}

	/**
	 * Sets the cell.
	 *
	 * @param x the x
	 * @param y the y
	 * @param alive the alive
	 */
	public void setCell(int x, int y, boolean alive) {
		board[x][y] = alive ? CellState.ALIVE : CellState.DEAD;
	}

	/**
	 * Count alive neighbors.
	 *
	 * @param x the x
	 * @param y the y
	 * @return the int
	 */
	public int countAliveNeighbors(int x, int y) {
		int aliveNeighbors = 0;
		for (int i = x - 1; i <= x + 1; i++) {
			for (int j = y - 1; j <= y + 1; j++) {
				if (i == x && j == y)
					continue;
				if (isCellAlive(i, j))
					aliveNeighbors++;
			}
		}
		return aliveNeighbors;
	}

	/**
	 * Play one iteration.
	 */
	public void playOneIteration() {
		List<Pair<Integer, Integer>> deadElements = new ArrayList<>();
		List<Pair<Integer, Integer>> aliveElements = new ArrayList<>();

		for (int i = 0; i < board.length; i++) {
			for (int j = 0; j < board[i].length; j++) {
				if (board[i][j] == CellState.ALIVE) {
					if (countAliveNeighbors(i, j) < 2 || countAliveNeighbors(i, j) > 3) {
						deadElements.add(new Pair<Integer, Integer>(i, j));
					}
				} else if (board[i][j] == CellState.DEAD) {
					if (countAliveNeighbors(i, j) == 3) {
						aliveElements.add(new Pair<Integer, Integer>(i, j));
					}
				}
			}
		}

		for (Pair<Integer, Integer> p : deadElements) {
			board[p.getLeft()][p.getRight()] = CellState.DEAD;
		}

		for (Pair<Integer, Integer> p : aliveElements) {
			board[p.getLeft()][p.getRight()] = CellState.ALIVE;
		}

		listeners.forEach(listener -> listener.boardChanged(this));
	}

	/**
	 * Adds the listener.
	 *
	 * @param listener the listener
	 */
	public void addListener(BoardListener listener) {
		listeners.add(listener);
	}

	/**
	 * Removes the listener.
	 *
	 * @param listener the listener
	 */
	public void removeListener(BoardListener listener) {
		listeners.remove(listener);
	}

	/**
	 * Gets the width.
	 *
	 * @return the width
	 */
	public int getWidth() {
		return width;
	}

	/**
	 * Gets the height.
	 *
	 * @return the height
	 */
	public int getHeight() {
		return height;
	}

	/**
	 * The Class Pair.
	 *
	 * @param <L> the generic type
	 * @param <R> the generic type
	 */
	private class Pair<L, R> {

		/** The left. */
		private final L left;
		
		/** The right. */
		private final R right;

		/**
		 * Instantiates a new pair.
		 *
		 * @param left the left
		 * @param right the right
		 */
		public Pair(L left, R right) {
			this.left = left;
			this.right = right;
		}

		/**
		 * Gets the left.
		 *
		 * @return the left
		 */
		public L getLeft() {
			return left;
		}

		/**
		 * Gets the right.
		 *
		 * @return the right
		 */
		public R getRight() {
			return right;
		}

		/* (non-Javadoc)
		 * @see java.lang.Object#hashCode()
		 */
		@Override
		public int hashCode() {
			return left.hashCode() ^ right.hashCode();
		}

		/* (non-Javadoc)
		 * @see java.lang.Object#equals(java.lang.Object)
		 */
		@Override
		public boolean equals(Object o) {
			if (!(o instanceof Pair))
				return false;
			Pair pairObj = (Pair) o;
			return left.equals(pairObj.getLeft()) && right.equals(pairObj.getRight());
		}

	}
}
