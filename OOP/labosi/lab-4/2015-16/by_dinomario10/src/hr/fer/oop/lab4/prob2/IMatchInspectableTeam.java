package hr.fer.oop.lab4.prob2;

/**
 * Classes that implement this interface agree to define all football team
 * management associated methods. Methods in this interface are for match
 * inspecting.
 * 
 * @author dinomario10
 */
public interface IMatchInspectableTeam {
	/**
	 * Returns true if the team is ready for a match. The team is ready if it
	 * meets the following criteria: the number of players in the starting
	 * eleven collection is at least seven.
	 * 
	 * @return true if the team is ready for a match
	 */
	public boolean isMatchReady();
	
	/**
	 * Calculates and returns the team spirit defined as a sum of emotion values
	 * of individual players in the starting eleven collection.
	 * 
	 * @return the team spirit defined as a sum of all player's emotions
	 */
	public int calculateTeamSpirit();

	/**
	 * Calculates and returns the team skill defined as a sum of playing skill
	 * values of individual players in the starting eleven collection.
	 * 
	 * @return the team skill defined as a sum of all player's playing skill
	 */
	public int calculateTeamSkill();

	/**
	 * Calculates and returns the team rating. Each team type defines their own
	 * methods for calculating the team rating.
	 * 
	 * @return the team rating
	 */
	public double calculateRating();
}
