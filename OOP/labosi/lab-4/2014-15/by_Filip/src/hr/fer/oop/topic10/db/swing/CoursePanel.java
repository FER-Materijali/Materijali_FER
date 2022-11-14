package hr.fer.oop.topic10.db.swing;

import hr.fer.oop.topic10.db.model.CourseRecord;
import hr.fer.oop.topic10.db.model.Database;
import hr.fer.oop.topic10.db.model.EnrollmentRecord;
import hr.fer.oop.topic10.db.model.StudentRecord;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;
import java.util.Collection;
import java.util.List;

import javax.swing.AbstractAction;
import javax.swing.Action;
import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JComponent;
import javax.swing.JLabel;
import javax.swing.JPanel;

/**
 * Panel used for previewing courses
 * 
 * @author Filip
 *
 */
@SuppressWarnings("serial")
public class CoursePanel extends JPanel {

	private static final int gap = 8;

	private static final Color[] C = new Color[] { Color.yellow, Color.green };

	private DatabasePane parent;
	private Database d;

	private JComboBox<CourseRecord> picker;
	private InfoPanel text;

	/**
	 * Creates a new Course Panel
	 * 
	 * @param parent used when switching tabs
	 * @param d source of data
	 */
	public CoursePanel(DatabasePane parent, Database d) {
		this.parent = parent;
		this.d = d;
		initGui();
	}

	/**
	 * Initializes gui
	 */
	private void initGui() {

		picker = new JComboBox<CourseRecord>(courses());
		picker.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				updatePanel();
			}
		});

		setLayout(new BorderLayout(gap, gap));
		add(picker, BorderLayout.NORTH);
		JPanel center = new JPanel(new BorderLayout(gap, gap));
		add(center, BorderLayout.CENTER);

		text = new InfoPanel(d);
		center.add(text, BorderLayout.NORTH);
		updatePanel();

	}

	/**
	 * Updates the panel
	 */
	private void updatePanel() {
		CourseRecord cr = (CourseRecord) picker.getSelectedItem();
		text.changedCourse(cr.getCourseID());
	}

	/**
	 * Returns an array of courses
	 * 
	 * @return courses
	 */
	private CourseRecord[] courses() {
		Collection<CourseRecord> col = d.getCourseTable().getAllCourses();
		CourseRecord[] array = new CourseRecord[col.size()];
		col.toArray(array);
		return array;
	}

	/**
	 * Panel that is used to present students which are enrolled in some course
	 * 
	 * @author Filip
	 *
	 */
	private class InfoPanel extends JPanel {

		private Database d;
		private MyPanel sText;

		public InfoPanel(Database d) {
			this.d = d;
			sText = new MyPanel("Ime i prezime", "Ocjena", new JLabel("                       "));
			setLayout(new BorderLayout());
		}

		/**
		 * This method is called when course is changed
		 * 
		 * @param cid course id of the new course
		 */
		public void changedCourse(String cid) {
			// student, ocjena
			List<Pair<StudentRecord, String>> lsr = new ArrayList<>();
			Collection<EnrollmentRecord> col = d.getEnrolmentTable().findByCourse(cid);
			if (col != null) {
				for (EnrollmentRecord er : col) {
					StudentRecord sr = d.getStudentTable().forJMBAG(er.getStudentJmbag());
					lsr.add(new Pair<>(sr, er.getGrade()));
				}
			}

			removeAll();
			updateUI();
			JPanel content = new JPanel(new GridLayout(1 + lsr.size(), 1, gap, gap));
			add(content, BorderLayout.PAGE_START);
			content.add(sText);
			boolean color = false;
			for (final Pair<StudentRecord, String> p : lsr) {

				Action action = new AbstractAction("Detalji") {
					@Override
					public void actionPerformed(ActionEvent e) {
						parent.changeTab(p.getA());
					}
				};

				JButton button = new JButton(action);
				MyPanel mp = new MyPanel(p.getA().toString(), p.getB() + "     ", button);

				mp.changeColor(color);
				content.add(mp);
				color ^= true;
			}
		}
	}

	/**
	 * Panel used for presenting students name and grades
	 * 
	 * @author Filip
	 *
	 */
	private class MyPanel extends JPanel {

		private JLabel l1;
		private JLabel l2;

		public MyPanel(String s1, String s2, JComponent c) {
			setLayout(new BorderLayout(gap, gap));

			l1 = new JLabel(s1);
			l1.setHorizontalAlignment(JLabel.LEFT);
			l1.setOpaque(true);

			l2 = new JLabel(s2);
			l2.setHorizontalAlignment(JLabel.RIGHT);
			l2.setOpaque(true);

			JPanel center = new JPanel(new GridLayout(1, 2));
			center.add(l1);
			center.add(l2);

			add(center, BorderLayout.CENTER);
			add(c, BorderLayout.EAST);
		}

		public void changeColor(boolean odd) {
			if (odd) {
				l1.setBackground(C[1]);
				l2.setBackground(C[1]);
			} else {
				l1.setBackground(C[0]);
				l2.setBackground(C[0]);
			}
		}

	}

	/**
	 * Represents a pair of 2 (different) types of objects
	 * 
	 * @author Filip
	 *
	 * @param <A>
	 * @param <B>
	 */
	private class Pair<A, B> {
		A a;
		B b;

		public Pair(A a, B b) {
			this.a = a;
			this.b = b;
		}

		public A getA() {
			return a;
		}

		public B getB() {
			return b;
		};

	}

}
