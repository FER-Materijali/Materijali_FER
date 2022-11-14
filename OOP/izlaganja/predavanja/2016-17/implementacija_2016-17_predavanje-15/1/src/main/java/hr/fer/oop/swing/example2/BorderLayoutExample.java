package hr.fer.oop.swing.example2;

import java.awt.BorderLayout;
import java.awt.Container;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.SwingUtilities;
import javax.swing.WindowConstants;

public class BorderLayoutExample extends JFrame {

	private static final long serialVersionUID = 1L;

	public BorderLayoutExample() {
		setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
		setLocation(20, 20);
		pack();
		
		initGUI();
	}

	private void initGUI() {
		Container cp = getContentPane();
		cp.setLayout(new BorderLayout());

		cp.add(new JButton("Sjever"), BorderLayout.PAGE_START); // zastarjelo: BorderLayout.NORTH
		cp.add(new JButton("Zapad"), BorderLayout.LINE_START); // zastarjelo: BorderLayout.WEST
		cp.add(new JButton("Centar"), BorderLayout.CENTER);
		cp.add(new JButton("Istok"), BorderLayout.LINE_END); // zastarjelo: BorderLayout.EAST
		cp.add(new JButton("Jug"), BorderLayout.PAGE_END); // zastarjelo: BorderLayout.SOUTH
	}

	public static void main(String[] args) {
		SwingUtilities.invokeLater(()->{
			new BorderLayoutExample().setVisible(true);
		});
	}
}
