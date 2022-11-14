package hr.fer.oop.lab6.zad3;

import java.awt.Dimension;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;

import javax.swing.JFrame;
import javax.swing.JTabbedPane;
import javax.swing.LookAndFeel;
import javax.swing.SwingUtilities;
import javax.swing.UIManager;
import javax.swing.UIManager.LookAndFeelInfo;
import javax.swing.WindowConstants;

import hr.fer.oop.lab6.zad2.StudentsPanel;

/**
 * You can change the look and feel of this frame by pressing the TAB key.
 *
 * @author dinomario10
 */
public class DataFrame extends JFrame implements KeyListener {
	private static final long serialVersionUID = -8379680153806526494L;
	
	/** Tabbed pane that contains the students panel and courses panel */
	protected JTabbedPane tabbedPane;
	/** Students panel */
	protected StudentsPanel studentsPanel = new StudentsPanel(this);
	/** Courses panel */
	public CoursesPanel coursesPanel = new CoursesPanel(this);
	/** Look and feel info installed on this computer */
	private LookAndFeelInfo[] lfis = UIManager.getInstalledLookAndFeels();

	/**
	 * Constructs a new main frame with basic details and initialized GUI.
	 */
	public DataFrame() {
		setDefaultCloseOperation(WindowConstants.DISPOSE_ON_CLOSE);
		setTitle("Baza podataka");
		setSize(560, 435);
		setMinimumSize(new Dimension(280, 300));

		addKeyListener(this);
		setFocusable(true);
		setFocusTraversalKeysEnabled(false);
		
		initGUI();
		
		setLocationRelativeTo(null);
	}

	/**
	 * Used for initializing the look of this panel. This method is used only
	 * for creating the user interface of the given frame and does not set
	 * window size and does not do any top-level container stuff.
	 */
	private void initGUI() {
		tabbedPane = new JTabbedPane();
		tabbedPane.add("Studenti", studentsPanel);
		tabbedPane.add("Predmeti", coursesPanel);
		
		add(tabbedPane);
	}
	
	/**
	 * Changes the look and feel of this frame to the next one. Updates all
	 * components to agree with the selected look and feel.
	 */
	private void changeLookAndFeel() {
		LookAndFeel currentLook = UIManager.getLookAndFeel();
		
		int amount = lfis.length;
		for (int i = 0; i < amount; i++) {
			if (lfis[i].getName().equals(currentLook.getName()) || currentLook.getName().equals("GTK look and feel")) {
				String nextLook;
				if (i == amount-1) {
					nextLook = lfis[0].getClassName();
				} else {
					nextLook = lfis[i+1].getClassName();
				}
				try {
					UIManager.setLookAndFeel(nextLook);
					SwingUtilities.updateComponentTreeUI(this);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		}
	}
	
	/**
	 * Initializes the frame.
	 * 
	 * @param args not used
	 */
	public static void main(String[] args) {
		SwingUtilities.invokeLater(() -> {
			new DataFrame().setVisible(true);
		});
	}

	@Override
	public void keyTyped(KeyEvent e) {}

	@Override
	public void keyPressed(KeyEvent e) {
		if (e.getKeyCode() == KeyEvent.VK_TAB)
		changeLookAndFeel();
	}

	@Override
	public void keyReleased(KeyEvent e) {}
}
