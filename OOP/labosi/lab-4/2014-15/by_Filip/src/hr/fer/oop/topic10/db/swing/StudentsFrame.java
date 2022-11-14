package hr.fer.oop.topic10.db.swing;

import hr.fer.oop.topic10.db.model.Database;

import java.awt.BorderLayout;

import javax.swing.BorderFactory;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.SwingUtilities;
import javax.swing.UIManager;
import javax.swing.UnsupportedLookAndFeelException;
import javax.swing.WindowConstants;
import javax.swing.border.Border;

/**
 * Main frame for this assignment
 * 
 * @author Filip
 *
 */
@SuppressWarnings("serial")
public class StudentsFrame extends JFrame {

	private Database d;

	/**
	 * Creates a new frame
	 */
	public StudentsFrame() {
		setTitle("Students database v1.0");
		setDefaultCloseOperation(WindowConstants.DISPOSE_ON_CLOSE);
		setSize(400, 400);

		try {
			UIManager.setLookAndFeel(UIManager.getSystemLookAndFeelClassName());
		} catch (ClassNotFoundException | InstantiationException | IllegalAccessException
				| UnsupportedLookAndFeelException e) {
		}
		d = Database.getDefault();
		initGui();
	}

	/**
	 * Initializes the gui
	 */
	private void initGui() {
		getContentPane().setLayout(new BorderLayout());

		StudentsPanel sp = new StudentsPanel(d);
		DatabasePane dbp = new DatabasePane(sp);
		CoursePanel cp = new CoursePanel(dbp, d);

		dbp.addTab("Studenti", sp);
		dbp.addTab("Predmeti", cp);

		JPanel contentPanel = new JPanel(new BorderLayout());
		Border padding = BorderFactory.createEmptyBorder(10, 10, 10, 10);
		contentPanel.setBorder(padding);
		contentPanel.add(dbp, BorderLayout.CENTER);

		getContentPane().add(contentPanel, BorderLayout.CENTER);
	}

	public static void main(String[] args) {
		SwingUtilities.invokeLater(new Runnable() {
			@Override
			public void run() {
				new StudentsFrame().setVisible(true);
			}
		});
	}

}
