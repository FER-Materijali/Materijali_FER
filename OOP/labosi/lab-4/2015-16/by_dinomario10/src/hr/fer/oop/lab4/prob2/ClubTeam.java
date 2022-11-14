package hr.fer.oop.lab4.prob2;

import hr.fer.oop.lab4.prob1.FootballPlayer;
import hr.fer.oop.lab4.prob1.Formation;
import static hr.fer.oop.lab4.prob1.Misc.*;

/**
 * The {@code ClubTeam} class represents football club teams, with the name of
 * the team, its formation and reputation points. Maximum number of registered
 * players for the national team is 25.
 * 
 * @author dinomario10
 */
public class ClubTeam extends Team {
	
	/** Reputation of the club team, going from 0 to 100 */
	private int reputation;
	/** Maximum number of players in a club team */
	public static final int MAX_PLAYERS = 25;

	/**
	 * Constructs a new object of type {@code ClubTeam}. All variables in this
	 * type must be initialized when calling a constructor. Variable name, is
	 * unchangeable after calling this constructor. Variables formation and
	 * reputation can be changed through a setter when desired.
	 * 
	 * @param name name of the club football team
	 * @param formation formation of the club football team
	 * @param reputation reputation of the club football team
	 */
	public ClubTeam(String name, Formation formation, int reputation) {
		super(name, formation, MAX_PLAYERS);
		setReputation(reputation);
	}
	
	/**
	 * Returns the club team's reputation.
	 * 
	 * @return the club team's reputation
	 */
	public int getReputation() {
		return reputation;
	}
	
	/**
	 * Sets the club team's reputation. Must be within range [0, 100].
	 * 
	 * @param reputation club team's reputation
	 */
	public void setReputation(int reputation) {
		if (!isInRange(reputation)) {
			throw new IllegalArgumentException("Reputation out of range: " + reputation);
		}
		this.reputation = reputation;
	}

	/**
	 * Returns true if the player can be registered to a team. The player gets
	 * added to the registered players collection if there is free room in the
	 * collection and if the player's playing skill is greater than or equal to
	 * the club's reputation.
	 * 
	 * @param player player to be registered
	 * @return true if the player can be registered to a team
	 */
	@Override
	public boolean isPlayerRegistrable(FootballPlayer player) {
		return player.getPlayingSkill() >= reputation;
	}
	
	@Override
	public void registerPlayer(FootballPlayer player) throws NotEligiblePlayerException {
		if (!isPlayerRegistrable(player)) {
			throw new NotEligiblePlayerException(
				"Player " + player.getName() + " (Skill: " + player.getPlayingSkill()
				+ ") cannot be registered in club team " + this.getName()
				+ " because his playing skill is lower than club's reputation."
			);
		}
		checkRegisteredPlayers(player, MAX_PLAYERS);
		registeredPlayers.add(player);
	}

	/**
	 * Calculates and returns the team rating. For a club team, the team rating
	 * is calculated with the following formula: <br>
	 * 30% team's skill + 70% team spirit
	 */
	@Override
	public double calculateRating() {
		final double SKILL_PERC = 0.7;
		final double SPIRIT_PERC = 0.3;
		return rating(SKILL_PERC, SPIRIT_PERC);
	}

}
