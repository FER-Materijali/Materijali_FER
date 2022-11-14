package hr.fer.oop.lab6.zad2;

import java.awt.BorderLayout;
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
import javax.swing.WindowConstants;

import hr.fer.oop.lab6.zad1.CourseRecord;
import hr.fer.oop.lab6.zad1.EnrollmentRecord;
import hr.fer.oop.lab6.zad1.StudentRecord;
import hr.fer.oop.lab6.zad3.DataFrame;

/**
 * Panel used for navigating students. The user gets the look from students'
 * perspective.
 *
 * @author dinomario10
 */
public class StudentsPanel extends DataPanel {
	private static final long serialVersionUID = 1L;

	/** Enrolled courses panel containing student's enrolled courses */
	protected JPanel enrolledCourses;
	/** ComboBox of student names */
	private JComboBox<StudentRecord> comboNames;

	/**
	 * Constructs a new StudentsPanel from superclass.
	 */
	public StudentsPanel() {
		super();
	}
	
	/**
	 * Constructs a new StudentsPanel with the given data frame.
	 * 
	 * @param frame data frame that owns this object.
	 */
	public StudentsPanel(DataFrame frame) {
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
		comboNames = new JComboBox<>(); 
		for (StudentRecord record : studentTable) {
			comboNames.addItem(record);
		}
		upper.add(comboNames);
		
		/* Add a new student button */
		JButton btnAddNew = new JButton("Dodaj");
		upper.add(btnAddNew, BorderLayout.LINE_END);
		
		btnAddNew.addActionListener((event) -> addNewElement("Dodaj novog studenta"));
		
		/* Create panels for the lower main panel */
		JPanel basicData = new JPanel(new BorderLayout());
		enrolledCourses = new JPanel(new BorderLayout());
		
		lower.add(basicData, BorderLayout.PAGE_START);
		lower.add(enrolledCourses, BorderLayout.CENTER);
		basicData.setBorder(BorderFactory.createEmptyBorder(0, 0, 10, 0));
		
		/* Create panels for labels and text fields */
		JPanel basicDataLeft = new JPanel(new GridLayout(0, 1, 0, 5));
		JPanel basicDataRight = new JPanel(new GridLayout(0, 1, 0, 5));
		basicDataLeft.setBorder(BorderFactory.createEmptyBorder(0, 0, 0, 5));
		
		basicData.add(basicDataLeft, BorderLayout.LINE_START);
		basicData.add(basicDataRight, BorderLayout.CENTER);
		
		/* Add labels onto the left side */
		basicDataLeft.add(new JLabel("JMBAG:", SwingConstants.RIGHT));
		basicDataLeft.add(new JLabel("Prezime:", SwingConstants.RIGHT));
		basicDataLeft.add(new JLabel("Ime:", SwingConstants.RIGHT));
		
		/* Print the selected student for the first time */
		StudentRecord selectedItem = (StudentRecord) comboNames.getSelectedItem();
		JTextField tfJmbag = new JTextField(selectedItem.getJmbag());
		JTextField tfLastName = new JTextField(selectedItem.getLastName());
		JTextField tfFirstName = new JTextField(selectedItem.getFirstName());
		
		tfJmbag.setEditable(false);
		tfLastName.setEditable(false);
		tfFirstName.setEditable(false);
		
		basicDataRight.add(tfJmbag);
		basicDataRight.add(tfLastName);
		basicDataRight.add(tfFirstName);
		
		
		/* Edit the enrolled courses panel */
		enrolledCourses.setBorder(BorderFactory.createTitledBorder(null, "Upisani predmeti"));
		
		/* Create student's course buttons */
		createCourseButtons(selectedItem);
		
		
		/* Enable data changing after selecting a new name from the combo box */
		comboNames.addItemListener((e) -> {
			if (e.getStateChange() == ItemEvent.SELECTED) {
				StudentRecord selected = (StudentRecord) comboNames.getSelectedItem();
				tfJmbag.setText(selected.getJmbag());
				tfLastName.setText(selected.getLastName());
				tfFirstName.setText(selected.getFirstName());
				createCourseButtons(selected);
			}
		});
	}
	
	/**
	 * Creates the course buttons based on the currently selected student.
	 * 
	 * @param selectedItem currently selected student
	 */
	private void createCourseButtons(StudentRecord selectedItem) {
		enrolledCourses.removeAll();
		enrolledCourses.revalidate();
		enrolledCourses.repaint();
		
		JPanel enrolledPanel = new JPanel(new BorderLayout());
		enrolledCourses.add(enrolledPanel, BorderLayout.PAGE_START);
		
		JPanel buttonPanel = new JPanel(new GridLayout(0, 1, 0, 8));
		buttonPanel.setBorder(BorderFactory.createEmptyBorder(5, 5, 0, 5));
		enrolledPanel.add(buttonPanel);
		
		Collection<EnrollmentRecord> byStudent = enrollmentTable.findByStudent(selectedItem.getJmbag());
		
		for (EnrollmentRecord record : byStudent) {
			CourseRecord course = courseTable.findById(record.getCourseID());
			JButton courseButton = new JButton(course.getCourseName());
			courseButton.addActionListener((event) -> JOptionPane.showMessageDialog(this, "Ocjena: " + record.getGrade()));
			buttonPanel.add(courseButton);
		}
		
		JButton btnAddCourse = new JButton("Dodaj novi predmet");
		btnAddCourse.addActionListener((event) -> addCourseToStudent(selectedItem));
		buttonPanel.add(btnAddCourse);
	}

	/**
	 * Used by other classes to set the selected student.
	 * 
	 * @param student student to be set
	 */
	public void setSelectedStudent(StudentRecord student) {
		comboNames.setSelectedItem(student);
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
		basicDataLeft.add(new JLabel("JMBAG:", SwingConstants.RIGHT));
		basicDataLeft.add(new JLabel("Prezime:", SwingConstants.RIGHT));
		basicDataLeft.add(new JLabel("Ime:", SwingConstants.RIGHT));
		basicDataLeft.add(new JLabel("Final grade:", SwingConstants.RIGHT));
		
		/* Prompt for student info */
		JTextField tfJmbag = new JTextField();
		JTextField tfLastName = new JTextField();
		JTextField tfFirstName = new JTextField();
		JTextField tfFinalGrade = new JTextField();
		
		basicDataRight.add(tfJmbag);
		basicDataRight.add(tfLastName);
		basicDataRight.add(tfFirstName);
		basicDataRight.add(tfFinalGrade);
		
		/* Add a finish and a cancel button */
		JButton btnFinish = new JButton("Finish");
		JButton btnCancel = new JButton("Cancel");
		lower.add(btnFinish);
		lower.add(btnCancel);
		
		btnFinish.addActionListener((event) -> {
			boolean ok = addStudentData(tfJmbag.getText(), tfLastName.getText(), tfFirstName.getText(), tfFinalGrade.getText());
			if (ok) inputFrame.dispose();
		});
		btnCancel.addActionListener((event) -> inputFrame.dispose());
	}
	
	/**
	 * Optional task.
	 */
	private boolean addStudentData(String jmbag, String lastName, String firstName, String finalGradeString) {
		Integer finalGrade;
		try {
			finalGrade = Integer.parseInt(finalGradeString);
		} catch (NumberFormatException e) {
			JOptionPane.showMessageDialog(frame, "Dragi korisniče, unio si glupost!", "Glupost unijeta.", JOptionPane.ERROR_MESSAGE);
			return false;
		}
		
		StudentRecord newStudent = new StudentRecord(jmbag, lastName, firstName, finalGrade);
		
		if (studentTable.get(jmbag) == null) {
			studentTable.add(newStudent);
			comboNames.addItem(newStudent);
			return true;
		} else {
			JOptionPane.showMessageDialog(frame, "Zapis s istim JMBAG-om već postoji!", "Zapis postoji.", JOptionPane.ERROR_MESSAGE);
			return false;
		}
	}
	
	/**
	 * Optional task.
	 */
	private void addCourseToStudent(StudentRecord selectedStudent) {
		JFrame inputFrame = new JFrame("Dodaj novi predmet");
		inputFrame.setDefaultCloseOperation(WindowConstants.DISPOSE_ON_CLOSE);
		inputFrame.setSize(280, 180);
		inputFrame.setLocationRelativeTo(this);
		
		JPanel panel = new JPanel(new BorderLayout());
		inputFrame.add(panel);
		
		/* Creating panels */
		JPanel upper = new JPanel(new BorderLayout());
		JPanel middle = new JPanel(new BorderLayout());
		JPanel lower = new JPanel(new BorderLayout());
		
		panel.add(upper, BorderLayout.PAGE_START);
		panel.add(middle, BorderLayout.CENTER);
		panel.add(lower, BorderLayout.PAGE_END);
		
		/* Upper panel */
		upper.setBorder(BorderFactory.createTitledBorder("Predmet"));
		JComboBox<CourseRecord> comboCourses = new JComboBox<>(); 
		for (CourseRecord record : courseTable) {
			comboCourses.addItem(record);
		}
		upper.add(comboCourses);
		
		/* Middle panel */
		middle.setBorder(BorderFactory.createTitledBorder("Ocjena"));
		JTextField tfGrade = new JTextField("0");
		middle.add(tfGrade);
		
		/* Lower panel */
		JButton btnAdd = new JButton("Dodaj");
		btnAdd.addActionListener((event) -> {
			CourseRecord selectedCourse = (CourseRecord) comboCourses.getSelectedItem();
			addToEnrollmentTable(selectedStudent, selectedCourse, tfGrade.getText());
		});
		lower.add(btnAdd);
		
		inputFrame.setVisible(true);
	}
	
	/**
	 * Optional task.
	 */
	private void addToEnrollmentTable(StudentRecord selectedStudent, CourseRecord selectedCourse, String gradeString) {
		Integer grade;
		try {
			grade = Integer.parseInt(gradeString);
		} catch (NumberFormatException e) {
			JOptionPane.showMessageDialog(frame, "Dragi korisniče, unio si glupost!", "Glupost unijeta", JOptionPane.ERROR_MESSAGE);
			return;
		}
		
		if (enrollmentTable.findByCourseAndStudent(selectedCourse.getCourseID(), selectedStudent.getJmbag()) == null) {
			EnrollmentRecord newEnrollment = new EnrollmentRecord(selectedCourse.getCourseID(), selectedStudent.getJmbag(), grade);
			enrollmentTable.add(newEnrollment);
			createCourseButtons(selectedStudent);
		} else {
			JOptionPane.showMessageDialog(frame, "Zapis već postoji!", "Zapis postoji", JOptionPane.ERROR_MESSAGE);
		}
	}

}
