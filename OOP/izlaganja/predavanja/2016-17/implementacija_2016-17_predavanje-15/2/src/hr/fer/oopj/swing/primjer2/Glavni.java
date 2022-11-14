package hr.fer.oopj.swing.primjer2;

import javax.swing.JFrame;
import javax.swing.SwingUtilities;
import javax.swing.WindowConstants;

public class Glavni extends JFrame {

	private static final long serialVersionUID = 1L;

	public Glavni() {
		setSize(400, 300);
		setLocation(200, 100);
		setTitle("Moj prvi prozor!");
		setDefaultCloseOperation(WindowConstants.DISPOSE_ON_CLOSE);
	}
	
	public static void main(String[] args) {
		SwingUtilities.invokeLater(() -> {
			new Glavni().setVisible(true);
		});
	}
	
}
