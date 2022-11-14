package hr.fer.oop.topic10.db;


/**
 * Implementing <code>IFilter</code> allows an object to filter something.
 * 
 * @author Filip Hrenić
 * @version 1.0
 */
public interface IFilter<TR> {
	public boolean accepts(TR record);
}
