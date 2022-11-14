package hr.fer.oop.swing.example2;

import java.awt.Container;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.SpringLayout;
import javax.swing.SwingUtilities;
import javax.swing.WindowConstants;

public class SpringLayoutExample extends JFrame {

	private static final long serialVersionUID = 1L;

	public SpringLayoutExample() {
		setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
		setLocation(20, 20);
		setSize(400, 400);
		
		initGUI();
	}

	private void initGUI() {
		Container cp = getContentPane();
		SpringLayout layout = new SpringLayout();
		cp.setLayout(layout);

		JButton btn1 = new JButton("Gumb 1");
		cp.add(btn1);
		JButton btn2 = new JButton("Gumb 2");
		cp.add(btn2);
		JButton btn3 = new JButton("Gumb 3");
		cp.add(btn3);

		layout.putConstraint(SpringLayout.WEST, btn1, 5, SpringLayout.WEST, cp);
		layout.putConstraint(SpringLayout.NORTH, btn1, 5, SpringLayout.NORTH, cp);
		layout.putConstraint(SpringLayout.WEST, btn2, 10, SpringLayout.EAST, btn1);
		layout.putConstraint(SpringLayout.NORTH, btn2, 10, SpringLayout.SOUTH, btn1);
		layout.putConstraint(SpringLayout.EAST, btn2, -5, SpringLayout.EAST, cp);
		layout.putConstraint(SpringLayout.SOUTH, btn3, -5, SpringLayout.SOUTH, cp);
		layout.putConstraint(SpringLayout.EAST, btn3, -5, SpringLayout.EAST, cp);
	}

	public static void main(String[] args) {
		SwingUtilities.invokeLater(()->{
			new SpringLayoutExample().setVisible(true);
		});
	}

}
