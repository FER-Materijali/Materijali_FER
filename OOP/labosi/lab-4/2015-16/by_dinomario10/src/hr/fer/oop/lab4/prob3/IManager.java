package hr.fer.oop.lab4.prob3;

import java.util.function.Predicate;
import hr.fer.oop.lab4.prob1.FootballPlayer;
import hr.fer.oop.lab4.prob2.IManageableTeam;

/**
 * The {@code IManager} interface contains the manager's default methods for
 * team management. Unsurprisingly, the coach must be employed to be able to
 * manage teams. Trying to call an {@code IManager} method by an unemployed
 * coach will result with a thrown {@code UnemployedCoachException}.
 * 
 * @author dinomario10
 */
public interface IManager {
	/**
	 * Registers the qualified offered players based on {@code criteria}. This
	 * method does not remove the existing previously registered players. This
	 * method is guaranteed not to exceed the maximum number of allowed
	 * registered players based on team type. It will not try to add players
	 * that have no right to be registered (e.g. player's playing skill is lower
	 * than team's reputation or the player's and team's countries do not match).
	 * 
	 * @param offeredPlayers players offered to be registered
	 * @param criteria criteria that needs to be met
	 * @throws UnemployedCoachException if the coach is unemployed
	 */
	public void registerPlayers(Iterable<FootballPlayer> offeredPlayers, Predicate<FootballPlayer> criteria)
			throws UnemployedCoachException;

	/**
	 * Picks the starting eleven players from the collection of registered
	 * players. Starting eleven players must meet the given {@code criteria}.
	 * Independently of the {@criteria}, this method ensures that the chosen
	 * starting eleven can form a formation. In case the {@code Predicate} meets
	 * more than the needed number of players on some playing position, this
	 * method chooses the players which were added to the registered players
	 * collection <b>earlier</b>. It also is possible that not all eleven
	 * players are picked.
	 * 
	 * @param criteria criteria that needs to be met
	 * @throws UnemployedCoachException if the coach is unemployed
	 */
	public void pickStartingEleven(Predicate<FootballPlayer> criteria) throws UnemployedCoachException;

	/**
	 * Sets the team's formation to the coaches' favorite formation.
	 * 
	 * @throws UnemployedCoachException if the coach is unemployed
	 */
	public void forceMyFormation() throws UnemployedCoachException;
	
	/**
	 * Sets the given {@code team} under this coaches' management.
	 * 
	 * @param team team to be managed by this coach
	 */
	public void setManagingTeam(IManageableTeam team);
}
