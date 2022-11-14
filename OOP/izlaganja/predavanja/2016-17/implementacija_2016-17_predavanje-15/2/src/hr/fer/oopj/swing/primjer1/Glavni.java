package hr.fer.oopj.swing.primjer1;

import javax.swing.JFrame;
import javax.swing.SwingUtilities;
import javax.swing.WindowConstants;

public class Glavni {

	public static void main(String[] args) {
		Runnable posao = new Runnable() {
			@Override
			public void run() {
				JFrame prozor = new JFrame();
				prozor.setSize(400, 300);
				prozor.setLocation(200, 100);
				prozor.setTitle("Moj prvi prozor!");
				prozor.setDefaultCloseOperation(WindowConstants.DISPOSE_ON_CLOSE);
				prozor.setVisible(true);
			}
		};

		SwingUtilities.invokeLater(posao);
	}
	
}
