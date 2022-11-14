package hr.fer.oop.swing.component;

import java.awt.BorderLayout;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.SwingUtilities;
import javax.swing.WindowConstants;

public class DrawingFrame extends JFrame {

	private static final long serialVersionUID = 1L;

	public DrawingFrame() {
		setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
		setSize(300, 300);
		
		initGUI();
	}

	private void initGUI() {
		Drawing drawing = new Drawing(100);
		add(drawing, BorderLayout.NORTH);

		JButton buttonLarger = new JButton("Povećaj");
		add(buttonLarger, BorderLayout.SOUTH);
		buttonLarger.addActionListener((event) -> {
			drawing.setRadius(drawing.getRadius() + 10);
		});
	}

	public static void main(String[] args) {
		SwingUtilities.invokeLater(() -> {
			new DrawingFrame().setVisible(true);
		});
	}
}
