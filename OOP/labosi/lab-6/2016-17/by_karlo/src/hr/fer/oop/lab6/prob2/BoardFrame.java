package hr.fer.oop.lab6.prob2;

import java.awt.BorderLayout;
import java.awt.GridLayout;

import javax.swing.*;

/**
 * The Class BoardFrame.
 */
public class BoardFrame extends JFrame implements BoardListener {

	/** The rows. */
	private final int ROWS = 30;
	
	/** The columns. */
	private final int COLUMNS = 30;

	/** The grid. */
	private JToggleButton[][] grid;

	/** The board. */
	private Board board;
	
	/** The play job. */
	private PlayJob playJob;
	
	/** The play thread. */
	private Thread playThread;

	/**
	 * Instantiates a new board frame.
	 */
	public BoardFrame() {
		board = new Board(ROWS, COLUMNS);
		board.addListener(this);
	
		JButton start = new JButton("Start");
		JButton stop = new JButton("Stop");
		JButton oneIteration = new JButton("One Iteration");

		JPanel mainPanel = new JPanel();
		JPanel gridPanel = new JPanel();
		JPanel startPanel = new JPanel();
		JPanel titlePanel = new JPanel();

		gridPanel.setLayout(new GridLayout(ROWS, COLUMNS));

		grid = new JToggleButton[ROWS][COLUMNS];
		for (int r = 0; r < ROWS; r++) {
			for (int c = 0; c < COLUMNS; c++) {
				int x = r, y = c;
				grid[x][y] = new JToggleButton();
				grid[x][y].addActionListener(e -> {
					board.setCell(x, y, grid[x][y].isSelected());
				});
				gridPanel.add(grid[r][c]);
			}
		}

		stop.setEnabled(false);

		start.addActionListener(e -> {
			start.setEnabled(false);
			stop.setEnabled(true);
			oneIteration.setEnabled(false);

			playJob = new PlayJob();
			playThread = new Thread(playJob);
			playThread.start();
		});
		stop.addActionListener(e -> {
			stop.setEnabled(false);
			start.setEnabled(true);
			oneIteration.setEnabled(true);
			
			playJob.stop();
		});
		oneIteration.addActionListener(e -> {
			board.playOneIteration();
		});

		mainPanel.setLayout(new BorderLayout());
		mainPanel.add(gridPanel, BorderLayout.CENTER);
		mainPanel.add(startPanel, BorderLayout.PAGE_START);
		mainPanel.add(titlePanel, BorderLayout.NORTH);

		startPanel.add(start);
		startPanel.add(stop);
		startPanel.add(oneIteration);

		setTitle("Conway's Game of Life");
		setSize(720, 720);
		setLocationRelativeTo(null);
		add(mainPanel);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setVisible(true);
	}

	/* (non-Javadoc)
	 * @see hr.fer.oop.lab6.prob2.BoardListener#boardChanged(hr.fer.oop.lab6.prob2.Board)
	 */
	@Override
	public void boardChanged(Board board) {
		for (int r = 0; r < ROWS; r++) {
			for (int c = 0; c < COLUMNS; c++) {
				grid[r][c].setSelected(board.isCellAlive(r, c));
			}
		}
	}
	
	/**
	 * The Class PlayJob.
	 */
	private class PlayJob implements Runnable {
		
		/** The running. */
		private volatile boolean running = true;
		
		/* (non-Javadoc)
		 * @see java.lang.Runnable#run()
		 */
		@Override
		public void run() {
			while(running) { 
				try {
					board.playOneIteration();
					Thread.sleep(500);
				} catch (InterruptedException e) {
					running = false;
					e.printStackTrace();
				}
			}
		}
		
		/**
		 * Stop.
		 */
		public void stop(){
			running = false;
	    }
	}
}