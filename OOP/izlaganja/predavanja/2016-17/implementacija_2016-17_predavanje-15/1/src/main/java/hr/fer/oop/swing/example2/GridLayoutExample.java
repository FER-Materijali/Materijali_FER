package hr.fer.oop.swing.example2;

import java.awt.Container;
import java.awt.GridLayout;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.SwingUtilities;
import javax.swing.WindowConstants;

public class GridLayoutExample extends JFrame {

	private static final long serialVersionUID = 1L;

	public GridLayoutExample() {
		setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
		setLocation(20, 20);
		pack();
		
		initGUI();
	}

	private void initGUI() {
		Container cp = getContentPane();
		cp.setLayout(new GridLayout(3, 2));

		cp.add(new JButton("Gumb 1"));
		cp.add(new JButton("2"));
		cp.add(new JButton("Gumb 3"));
		cp.add(new JButton("Dugački naziv gumba 4"));
		cp.add(new JButton("Gumb 5"));
	}

	public static void main(String[] args) {
		SwingUtilities.invokeLater(()->{
			new GridLayoutExample().setVisible(true);
		});
	}

}
