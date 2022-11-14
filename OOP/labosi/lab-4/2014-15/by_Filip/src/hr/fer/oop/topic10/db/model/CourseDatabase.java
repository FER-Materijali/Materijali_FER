package hr.fer.oop.topic10.db.model;

import hr.fer.oop.topic10.db.IFilter;
import hr.fer.zemris.java.util.Utility;

import java.util.Collection;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * Represents a database with course records.
 * 
 * @author Filip
 *
 */
public class CourseDatabase {

	/**
	 * Used for internal storage of records.
	 */
	private Map<String, CourseRecord> base;

	/* maximal course id */
	private int max = -1;

	/**
	 * Populates this CourseDatabase with a file
	 * 
	 * @param file
	 *            list of lines read from file
	 */
	public CourseDatabase(List<String> file) {
		base = new HashMap<>();
		for (String row : file) {
			CourseRecord cr = new CourseRecord(row);
			String cid = cr.getCourseID();
			base.put(cid, cr);

			if (Utility.isInteger(cid)) {
				max = Math.max(max, Integer.parseInt(cid));
			}
		}
	}

	/**
	 * Returns course record that has given courseID or null if there isn't such
	 * 
	 * @param courseId
	 *            courseId
	 * @return wanted courseRecord
	 */
	public CourseRecord findById(String courseId) {
		return base.get(courseId);
	}

	/**
	 * Used for adding a course to the course database.
	 * 
	 * @param name
	 *            name of the course
	 */
	public void addCourse(String name) {
		for (CourseRecord c : base.values()) {
			if (c.getCourseName().equals(name)) {
				System.err.println("There already is a course with name: "
						+ name);
				return;
			}
		}

		max++;
		String id = Integer.toString(max);
		base.put(id, new CourseRecord(id, name));
	}

	/**
	 * Finds first course record that matches partial name
	 * 
	 * @param partialName
	 *            course's partial name
	 * @return course record
	 */
	public CourseRecord findFirstByName(final String partialName) {
		IFilter<CourseRecord> ifcr = new IFilter<CourseRecord>() {
			private String mask = partialName.replaceAll("\\*", ".\\*");

			@Override
			public boolean accepts(CourseRecord record) {
				return record.getCourseName().matches(mask);
			}
		};

		for (CourseRecord cr : base.values()) {
			if (ifcr.accepts(cr)) {
				return cr;
			}
		}
		return null;
	}

	public Collection<CourseRecord> getAllCourses() {
		return base.values();
	}

}
