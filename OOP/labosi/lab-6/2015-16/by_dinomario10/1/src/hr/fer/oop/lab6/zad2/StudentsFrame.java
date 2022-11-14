package hr.fer.oop.lab6.zad2;

import javax.swing.JFrame;
import javax.swing.SwingUtilities;
import javax.swing.WindowConstants;

/**
 * This frame shows only the students panel and is not as interesting to look at
 * as the {@linkplain DataFrame} frame.
 *
 * @author dinomario10
 */
public class StudentsFrame extends JFrame {
	private static final long serialVersionUID = 1011765153069255568L;

	public StudentsFrame() {
		setDefaultCloseOperation(WindowConstants.DISPOSE_ON_CLOSE);
		setTitle("Baza podataka");
		setSize(560, 435);
		
		initGUI();
		
		setLocationRelativeTo(null);
	}

	/**
	 * Used for initializing the look of this panel. This method is used only
	 * for creating the user interface of the given frame and does not set
	 * window size and does not do any top-level container stuff.
	 */
	private void initGUI() {
		add(new StudentsPanel());
	}
	
	/**
	 * Initializes the frame.
	 * 
	 * @param args not used
	 */
	public static void main(String[] args) {
		SwingUtilities.invokeLater(() -> {
			new StudentsFrame().setVisible(true);
		});
	}

}
