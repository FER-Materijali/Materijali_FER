package hr.fer.oop.lab4.prob2;

import java.util.Collection;
import java.util.function.Predicate;
import hr.fer.oop.lab4.prob1.*;

/**
 * Classes that implement this interface agree to define all football team
 * management associated methods. The following methods are for managing the
 * team.
 * 
 * @author dinomario10
 */
public interface IManageableTeam {
	/**
	 * Registers a player by adding him to the registered players collection.
	 * Throws a {@code NotEligiblePlayerException} if the player doesn't have
	 * the right to enter the team.
	 * 
	 * @param player player to be registered
	 * @throws NotEligiblePlayerException
	 *         if the player doesn't have the right to enter the team:
	 *         <ul>
	 *         <li>Player's and the national team's countries don't match
	 *         <li>Player's skill is too low compared to the club's reputation
	 *         <li>There's no more room in the registered players collection
	 *         <li>The player has already been registered (added)
	 *         </ul>
	 */
	public void registerPlayer(FootballPlayer player) throws NotEligiblePlayerException;
	
	/**
	 * Unregisters a player by removing him from the registered players
	 * collection. Trying to remove a non-existing player from the collection
	 * will result in throwing a {@code NotEligiblePlayerException}.
	 * 
	 * @param player player to be unregistered
	 * @throws IllegalArgumentException if the player was not found
	 */
	public void unregisterPlayer(FootballPlayer player) throws IllegalArgumentException;
	
	/**
	 * Empties the starting eleven collection. Empty collection becomes null.
	 */
	public void clearStartingEleven();
	
	/**
	 * Adds a player to the starting eleven collection. Maximum number of
	 * players in this collection is eleven. Trying to add any player past the
	 * eleventh will result with a thrown {@code NotEligiblePlayerException}.
	 * 
	 * @param player player to be added
	 * @throws NotEligiblePlayerException if:
	 *             <ul>
	 *             <li>the player isn't previously registered
	 *             <li>there is no more room in the starting eleven collection
	 *             <li>the player is already in the starting eleven collection
	 *             </ul>
	 */
	public void addPlayerToStartingEleven(FootballPlayer player) throws NotEligiblePlayerException;
	
	/**
	 * Removes the player from the starting eleven collection. Trying to remove
	 * a non-existing player from the collection will result in throwing an
	 * {@code IllegalArgumentException}.
	 * 
	 * @param player player to be removed
	 * @throws IllegalArgumentException if the player was not found
	 */
	public void removePlayerFromStartingEleven(FootballPlayer player) throws IllegalArgumentException;
	
	/**
	 * Returns true if the player can be registered to a team. The player gets
	 * added to the registered players collection if there is free room in the
	 * collection.
	 * 
	 * @param player player to be registered
	 * @return true if the player can be registered to a team
	 */
	public boolean isPlayerRegistrable(FootballPlayer player);

	/**
	 * Returns a <b>new</b> collection that contains called object's registered
	 * players.
	 * 
	 * @return a new collection containing all object's registered players
	 */
	public Collection<FootballPlayer> getRegisteredPlayers();

	/**
	 * Returns a <b>new</b> collection that contains called object's starting
	 * eleven players.
	 * 
	 * @return a new collection containing all object's starting eleven
	 */
	public Collection<FootballPlayer> getStartingEleven();

	/**
	 * Returns a <b>new</b> collection of registered players that meets the
	 * given criteria. Criteria is passed by creating a new object that
	 * implements Predicate.
	 * 
	 * @param criteria criteria for filtering players
	 * @return a new collection that meets the given criteria
	 * @see Predicate
	 */
	public Collection<FootballPlayer> filterRegisteredPlayers(Predicate<FootballPlayer> criteria);

	/**
	 * Sets the given formation for object of type {@code Team}.
	 * 
	 * @param formation a formation
	 */
	public void setFormation(Formation formation);

	/**
	 * Returns the formation for object of type {@code Team}.
	 * 
	 * @return returns the formation for wanted object
	 */
	public Formation getFormation();
}
