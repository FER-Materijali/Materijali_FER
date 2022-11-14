package hr.fer.oop.lab5.exams;

import java.util.Collection;
import java.util.Map;

/**
 * This interface represents the exam data that is worked with. Upon loading,
 * the data is loaded to the initial data sheets and automatically into the
 * active data sheets. The {@code ExamData} interface also claims that upon
 * losing the current active data sheets, a previous one can be retrieved.
 *
 * @author dinomario10
 */
public interface ExamData {
	
	/**
	 * Returns the initial collection of sheet data.
	 * 
	 * @return the initial collection of sheet data
	 */
	public Map<String, SheetData> getInitial();
	
	/**
	 * Sets the initial collection of sheet data.
	 * 
	 * @param initial initial collection of sheet data
	 */
	public void setInitial(Map<String, SheetData> initial);

	/**
	 * Returns the active collection of sheet data.
	 * 
	 * @return the active collection of sheet data
	 */
	public Collection<SheetData> getActive();

	/**
	 * Sets the active collection of sheet data.
	 * 
	 * @param active active collection of sheet data
	 */
	public void setActive(Collection<SheetData> active);
	
	/**
	 * Returns a collection of sheet data before the last change.
	 * 
	 * @return a collection of sheet data before the last change
	 */
	public Collection<SheetData> getPrevious();
}
