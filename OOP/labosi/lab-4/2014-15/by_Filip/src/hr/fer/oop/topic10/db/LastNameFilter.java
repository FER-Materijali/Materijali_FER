package hr.fer.oop.topic10.db;

import hr.fer.oop.topic10.db.model.StudentRecord;

/**
 * Creates a filter that filters students based on their last name. It can
 * contain wildcards <code>*</code>.
 * 
 * @author Filip Hrenić
 * @version 1.0
 */
public class LastNameFilter implements IFilter<StudentRecord> {
	public String mask;

	/**
	 * Constructs a new filter with mask being a valid regex.
	 * 
	 * @param mask wanted regular expression
	 */
	public LastNameFilter(String mask) {
		this.mask = mask.replaceAll("\\*", ".\\*");
	}

	/**
	 * Checks if the given {@link StudentRecord} matches the mask.
	 * 
	 * @return <code>true</code> if it matches, <code>false</code> otherwise
	 */
	public boolean accepts(StudentRecord record) {
		return record.getLastName().matches(this.mask);
	}
}
