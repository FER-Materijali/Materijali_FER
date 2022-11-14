package hr.fer.oop.topic10.db.swing;

import hr.fer.oop.topic10.db.model.StudentRecord;

import javax.swing.JTabbedPane;

/**
 * Custom {@link JTabbedPane} used for changing tabs when "Detalji" is pressed
 * in {@link CoursePanel}
 * 
 * @author Filip
 *
 */
@SuppressWarnings("serial")
public class DatabasePane extends JTabbedPane {

	private StudentsPanel sp;

	public DatabasePane(StudentsPanel sp) {
		this.sp = sp;
	}

	/**
	 * This will be called when "Detalji" is pressed"
	 * 
	 * @param sr
	 */
	public void changeTab(StudentRecord sr) {
		setSelectedIndex(0);
		sp.setStudent(sr);
	}

}
