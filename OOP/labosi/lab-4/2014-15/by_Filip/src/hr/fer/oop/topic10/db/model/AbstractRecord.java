package hr.fer.oop.topic10.db.model;

public class AbstractRecord {

	private String[] elements;

	public AbstractRecord(String x) {
		elements = x.split("\t");
	}

	public AbstractRecord(String... xs) {
		elements = xs;
	}

	public String[] getElements() {
		return elements;
	}

	/**
	 * Returns first property as integer.
	 */
	@Override
	public int hashCode() {
		return Integer.parseInt(elements[0]);
	}

	/**
	 * Returns <code>true</code> if two objects are equal.
	 * 
	 * @param o
	 *            object being tested
	 * @return <code>true</code> if parameter is equal to this object,
	 *         <code>false</code> otherwise
	 */
	@Override
	public boolean equals(Object o) {
		if (o == null || this.getClass() != o.getClass()) {
			return false;
		}
		AbstractRecord r = (AbstractRecord) o;
		return hashCode() == r.hashCode();
	}

	@Override
	public String toString() {
		StringBuilder sb = new StringBuilder();
		for (String s : elements) {
			sb.append(s);
			sb.append(' ');
		}
		return sb.toString();
	}

}
