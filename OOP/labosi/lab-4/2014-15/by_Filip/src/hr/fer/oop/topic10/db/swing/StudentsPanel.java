package hr.fer.oop.topic10.db.swing;

import hr.fer.oop.topic10.db.model.CourseRecord;
import hr.fer.oop.topic10.db.model.Database;
import hr.fer.oop.topic10.db.model.EnrollmentRecord;
import hr.fer.oop.topic10.db.model.StudentRecord;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.util.ArrayList;
import java.util.Collection;
import java.util.List;

import javax.swing.AbstractAction;
import javax.swing.BorderFactory;
import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;

/**
 * panel used for presenting students
 * 
 * @author Filip
 *
 */
@SuppressWarnings("serial")
public class StudentsPanel extends JPanel {

	private static final int gap = 8;

	private Database base;
	private JComboBox<StudentRecord> picker;
	private JLabel jmbag;
	private JLabel prezime;
	private JLabel ime;
	private PredmetiPanel predmeti;

	public StudentsPanel(Database d) {
		base = d;
		initGui();
	}

	/**
	 * Initializes gui
	 */
	private void initGui() {
		setLayout(new BorderLayout(gap, gap));

		jmbag = createWhiteLabel();
		ime = createWhiteLabel();
		prezime = createWhiteLabel();
		predmeti = new PredmetiPanel(base);

		picker = new JComboBox<StudentRecord>(students());
		// picker.setBorder(BorderFactory.createBevelBorder(BevelBorder.RAISED));
		picker.addActionListener(new AbstractAction() {
			@Override
			public void actionPerformed(ActionEvent e) {
				updatePanel();
			}
		});
		add(picker, BorderLayout.PAGE_START);
		updatePanel();

		JPanel center = new JPanel(new BorderLayout(gap, gap));
		JPanel text = new JPanel(new BorderLayout(gap, gap));
		center.add(text, BorderLayout.PAGE_START);
		center.add(predmeti, BorderLayout.CENTER);

		JPanel left = new JPanel(new GridLayout(3, 0, gap, gap));
		left.add(new RLabel("JMBAG:"));
		left.add(new RLabel("Ime:"));
		left.add(new RLabel("Prezime:"));

		JPanel right = new JPanel(new GridLayout(3, 0, gap, gap));
		right.add(jmbag);
		right.add(ime);
		right.add(prezime);

		text.add(left, BorderLayout.LINE_START);
		text.add(right, BorderLayout.CENTER);
		text.setBorder(BorderFactory.createEmptyBorder(3, 3, 3, 3));

		add(center, BorderLayout.CENTER);

	}

	/**
	 * Creates a label with white background
	 * 
	 * @return white jlabel
	 */
	private JLabel createWhiteLabel() {
		JLabel l = new JLabel();
		l.setOpaque(true);
		l.setBackground(Color.white);
		return l;
	}

	/**
	 * Sets a new student to show
	 */
	public void setStudent(StudentRecord sr) {
		picker.setSelectedItem(sr);
		updatePanel();
	}

	/**
	 * This is called when picked student changes
	 */
	private void updatePanel() {
		StudentRecord sr = (StudentRecord) picker.getSelectedItem();
		jmbag.setText(sr.getJmbag());
		ime.setText(sr.getFirstName());
		prezime.setText(sr.getLastName());
		predmeti.changedStudent(sr.getJmbag());
	}

	/**
	 * Returns an array of all students
	 * 
	 * @return students
	 */
	private StudentRecord[] students() {
		Collection<StudentRecord> col = base.getStudentTable().getAllStudents();
		StudentRecord[] array = new StudentRecord[col.size()];
		col.toArray(array);
		return array;
	}

	/**
	 * This class is used for presenting courses in which a student is enrolled
	 * 
	 * @author Filip
	 *
	 */
	private class PredmetiPanel extends JPanel {

		private Database d;

		public PredmetiPanel(Database d) {
			super();
			this.d = d;
			setBorder(BorderFactory.createTitledBorder(BorderFactory.createLineBorder(Color.black), "Upisani predmeti"));
			setLayout(new BorderLayout(gap, gap));
		}

		/**
		 * This method is called when a different student is picked.
		 * 
		 * @param jmbag new jmbag
		 */
		public void changedStudent(String jmbag) {
			List<CourseRecord> lcr = new ArrayList<>();
			Collection<EnrollmentRecord> col = d.getEnrolmentTable().findByStudent(jmbag);
			if (col != null) {
				for (EnrollmentRecord er : col) {
					lcr.add(d.getCourseTable().findById(er.getCourseId()));
				}
			}

			removeAll();
			updateUI();
			JPanel content = new JPanel(new GridLayout(lcr.size(), 1));
			add(content, BorderLayout.PAGE_START);
			for (CourseRecord cr : lcr) {
				content.add(new MyButton(cr, jmbag, base));
			}
		}
	}

	/**
	 * Button that opens a jopiton pane showing the grade in the given course.
	 * 
	 * @author Filip
	 *
	 */
	private class MyButton extends JButton {

		private String cid;
		private String sid;
		private Database base;

		public MyButton(CourseRecord cr, String jmbag, Database d) {
			cid = cr.getCourseID();
			sid = jmbag;
			base = d;
			setAction(new AbstractAction(cr.getCourseName()) {

				@Override
				public void actionPerformed(ActionEvent e) {
					EnrollmentRecord er = base.getEnrolmentTable().findByStudentAndCourse(sid, cid);
					String ocjena = "0";
					if (er != null) {
						ocjena = er.getGrade();
					}
					JOptionPane.showMessageDialog(StudentsPanel.this, "Ocjena je: " + ocjena, "Informacije",
							JOptionPane.INFORMATION_MESSAGE);
				}
			});
		}

	}

	/**
	 * A JLabel that has right text alignment
	 * 
	 * @author Filip
	 *
	 */
	private class RLabel extends JLabel {
		public RLabel(String s) {
			super(s);
			setHorizontalAlignment(JLabel.RIGHT);
		}
	}

}
