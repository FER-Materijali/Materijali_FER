package hr.fer.oop.lab6.zad2;

import java.io.FileNotFoundException;

import javax.swing.JFrame;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.WindowConstants;

import hr.fer.oop.lab6.zad1.CourseTable;
import hr.fer.oop.lab6.zad1.Database;
import hr.fer.oop.lab6.zad1.EnrollmentTable;
import hr.fer.oop.lab6.zad1.MalformedLineError;
import hr.fer.oop.lab6.zad1.StudentTable;
import hr.fer.oop.lab6.zad3.DataFrame;

/**
 * Superclass of the {@linkplain StudentsPanel} and {@linkplain CoursesPanel}.
 *
 * @author dinomario10
 */
public abstract class DataPanel extends JPanel {
	private static final long serialVersionUID = 1L;
	
	/** Data frame in which this panel is invoked */
	protected DataFrame frame;
	
	/** Table of student records */
	protected static StudentTable studentTable;
	/** Table of course records */
	protected static CourseTable courseTable;
	/** Table of enrollment records */
	protected static EnrollmentTable enrollmentTable;
	
	/**
	 * Constructs a new DataPanel for the extending subclasses.
	 */
	public DataPanel() {
		try {
			studentTable = Database.getStudentTable();
			courseTable = Database.getCourseTable();
			enrollmentTable = Database.getEnrollmentTable();
		} catch (MalformedLineError | FileNotFoundException e) {
			JOptionPane.showMessageDialog(this, e.getMessage(), "CRITICAL ERROR", JOptionPane.ERROR_MESSAGE);
			System.exit(-1);
		}
		initGUI();
	}
	
	/**
	 * Constructs a new DataPanel with the given data frame.
	 * 
	 * @param frame data frame that owns this object.
	 */
	public DataPanel(DataFrame frame) {
		this();
		this.frame = frame;
	}
	
	/**
	 * Used for initializing the look of this panel. This method is used only
	 * for creating the user interface of the given frame and does not set
	 * window size and does not do any top-level container stuff.
	 */
	protected abstract void initGUI();
	
	/**
	 * Optional task.
	 */
	protected void addNewElement(String title) {
		JFrame inputFrame = new JFrame(title);
		inputFrame.setDefaultCloseOperation(WindowConstants.DISPOSE_ON_CLOSE);
		inputFrame.setSize(280, 230);
		inputFrame.setLocationRelativeTo(this);
		
		initAddNewElementGUI(inputFrame);
		
		inputFrame.setVisible(true);
	}

	/**
	 * Optional task.
	 */
	protected abstract void initAddNewElementGUI(JFrame inputFrame);
	
}
