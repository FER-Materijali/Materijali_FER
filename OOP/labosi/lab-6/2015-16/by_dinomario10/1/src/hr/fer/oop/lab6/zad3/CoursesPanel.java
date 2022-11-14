package hr.fer.oop.lab6.zad3;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.GridLayout;
import java.awt.event.ItemEvent;
import java.util.Collection;

import javax.swing.BorderFactory;
import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JTextField;
import javax.swing.SwingConstants;

import hr.fer.oop.lab6.zad1.CourseRecord;
import hr.fer.oop.lab6.zad1.EnrollmentRecord;
import hr.fer.oop.lab6.zad1.StudentRecord;
import hr.fer.oop.lab6.zad2.DataPanel;

/**
 * Panel used for navigating courses. The user gets the look from courses'
 * perspective.
 *
 * @author dinomario10
 */
public class CoursesPanel extends DataPanel {
	private static final long serialVersionUID = 1L;

	/** ComboBox of courses */
	private JComboBox<CourseRecord> comboCourses;
	
	/** Light gray color used for painting the students info */
	private static final Color LIGHT_GRAY = new Color(200, 200, 200);
	/** Gray color used for painting the students info */
	private static final Color GRAY = new Color(160, 160, 160);
	
	/**
	 * Constructs a new CoursesPanel from superclass.
	 */
	public CoursesPanel() {
		super();
	}
	
	/**
	 * Constructs a new CoursesPanel with the given data frame.
	 * 
	 * @param frame data frame that owns this object.
	 */
	public CoursesPanel(DataFrame frame) {
		super(frame);
	}
	
	/**
	 * Used for initializing the look of this panel. This method is used only
	 * for creating the user interface of the given frame and does not set
	 * window size and does not do any top-level container stuff.
	 */
	@Override
	protected void initGUI() {
		setLayout(new BorderLayout(0, 10));
		
		/* Create the main upper and lower panel */
		JPanel upper = new JPanel(new BorderLayout());
		JPanel lower = new JPanel(new BorderLayout());
		upper.setBorder(BorderFactory.createEmptyBorder(4, 6, 6, 6));
		lower.setBorder(BorderFactory.createEmptyBorder(0, 6, 0, 6));
		
		add(upper, BorderLayout.PAGE_START);
		add(lower, BorderLayout.CENTER);
		
		/* Add student names */
		comboCourses = new JComboBox<>(); 
		for (CourseRecord record : courseTable) {
			comboCourses.addItem(record);
		}
		upper.add(comboCourses);
		
		/* Add a new course button */
		JButton btnAddNew = new JButton("Dodaj");
		upper.add(btnAddNew, BorderLayout.LINE_END);
		
		btnAddNew.addActionListener((event) -> addNewElement("Dodaj novi predmet"));
		
		/* Create student fields and details section */
		JPanel fields = new JPanel(new BorderLayout());
		JPanel studentFields = new JPanel(new GridLayout(0, 1, 0, 5));
		JPanel detailsPanel = new JPanel(new GridLayout(0, 1, 0, 5));
		studentFields.setBorder(BorderFactory.createEmptyBorder(0, 5, 0, 5));
		detailsPanel.setBorder(BorderFactory.createEmptyBorder(0, 5, 0, 5));
		
		lower.add(fields, BorderLayout.PAGE_START);
		fields.add(studentFields, BorderLayout.CENTER);
		fields.add(detailsPanel, BorderLayout.LINE_END);
		
		/* Create students and details panels */
		CourseRecord selectedItem = (CourseRecord) comboCourses.getSelectedItem();
		createStudentFields(studentFields, detailsPanel, selectedItem);
		
		
		/* Enable data changing after selecting a new course from the combo box */
		comboCourses.addItemListener((e) -> {
			if (e.getStateChange() == ItemEvent.SELECTED) {
				CourseRecord selected = (CourseRecord) comboCourses.getSelectedItem();
				createStudentFields(studentFields, detailsPanel, selected);
			}
		});
	}
	
	/**
	 * Creates the student fields with colored panels.
	 * 
	 * @param studentFields main panel of student fields
	 * @param detailsPanel details panel of student fields
	 * @param selectedItem selected item
	 */
	private void createStudentFields(JPanel studentFields, JPanel detailsPanel, CourseRecord selectedItem) {
		studentFields.removeAll();
		studentFields.revalidate();
		studentFields.repaint();
		detailsPanel.removeAll();
		detailsPanel.revalidate();
		detailsPanel.repaint();
		
		/* Add labels onto the top */
		JPanel titleBar = new JPanel(new GridLayout(1, 2));
		studentFields.add(titleBar, BorderLayout.PAGE_START);
		
		titleBar.add(new JLabel("Ime i prezime", SwingConstants.LEFT));
		titleBar.add(new JLabel("Ocjena", SwingConstants.RIGHT));
		detailsPanel.add(new JLabel());
		
		Collection<EnrollmentRecord> byCourse = enrollmentTable.findByCourse(selectedItem.getCourseID());
		
		int i = 0;
		for (EnrollmentRecord record : byCourse) {
			String studentJmbag = record.getStudentJMBAG();
			StudentRecord student = studentTable.get(studentJmbag);
			
			/* Create student block, with student's name and grade */
			String studentName = student.getFirstName() + " " + student.getLastName();
			JPanel studentPanel = new JPanel(new BorderLayout());
			studentPanel.setBorder(BorderFactory.createEmptyBorder(0, 2, 0, 15));
			studentPanel.add(new JLabel(studentName, SwingConstants.LEFT), BorderLayout.LINE_START);
			studentPanel.add(new JLabel(record.getGrade().toString(), SwingConstants.RIGHT), BorderLayout.LINE_END);
			
			/* Determine the color of this student block */
			if (i % 2 == 0) {
				studentPanel.setBackground(LIGHT_GRAY);
			} else {
				studentPanel.setBackground(GRAY);
			}
			studentFields.add(studentPanel, BorderLayout.CENTER);
			
			/* Create the details buttons */
			JButton detailsButton = new JButton("Detalji");
			detailsButton.addActionListener((event) -> {
				frame.tabbedPane.setSelectedIndex(0);
				frame.studentsPanel.setSelectedStudent(student);
			});
			detailsPanel.add(detailsButton);
			i++;
		}
	}
	
	/**
	 * Optional task.
	 */
	protected void initAddNewElementGUI(JFrame inputFrame) {
		inputFrame.setLayout(new BorderLayout(0, 10));
		
		/* Create the main upper and lower panel */
		JPanel upper = new JPanel(new BorderLayout());
		JPanel lower = new JPanel(new GridLayout(1, 0, 5, 0));
		upper.setBorder(BorderFactory.createEmptyBorder(4, 6, 6, 6));
		lower.setBorder(BorderFactory.createEmptyBorder(0, 6, 0, 6));
		
		inputFrame.add(upper, BorderLayout.CENTER);
		inputFrame.add(lower, BorderLayout.PAGE_END);
		
		/* Create panels for the lower main panel */
		JPanel basicData = new JPanel(new BorderLayout());
		
		upper.add(basicData, BorderLayout.PAGE_START);
		
		/* Create panels for labels and text fields */
		JPanel basicDataLeft = new JPanel(new GridLayout(0, 1, 0, 5));
		JPanel basicDataRight = new JPanel(new GridLayout(0, 1, 0, 5));
		basicDataLeft.setBorder(BorderFactory.createEmptyBorder(0, 0, 0, 5));
		
		basicData.add(basicDataLeft, BorderLayout.LINE_START);
		basicData.add(basicDataRight, BorderLayout.CENTER);
		
		/* Add labels onto the left side */
		basicDataLeft.add(new JLabel("ID predmeta:", SwingConstants.RIGHT));
		basicDataLeft.add(new JLabel("Ime predmeta:", SwingConstants.RIGHT));
		
		/* Prompt for student info */
		JTextField tfCourseID = new JTextField();
		JTextField tfCourseName = new JTextField();
		
		basicDataRight.add(tfCourseID);
		basicDataRight.add(tfCourseName);
		
		/* Add a finish and a cancel button */
		JButton btnFinish = new JButton("Finish");
		JButton btnCancel = new JButton("Cancel");
		lower.add(btnFinish);
		lower.add(btnCancel);
		
		btnFinish.addActionListener((event) -> {
			addCourseData(tfCourseID.getText(), tfCourseName.getText());
			inputFrame.dispose();
		});
		btnCancel.addActionListener((event) -> inputFrame.dispose());
	}
	
	/**
	 * Optional task.
	 */
	private void addCourseData(String courseID, String courseName) {
		CourseRecord newCourse = new CourseRecord(courseID, courseName);
		if (courseTable.findById(courseID) == null) {
			courseTable.add(newCourse);
			comboCourses.addItem(newCourse);
		} else {
			JOptionPane.showMessageDialog(null, "Zapis s istim ID-em već postoji!", "Zapis postoji.", JOptionPane.ERROR_MESSAGE);
		}
	}
	
}
