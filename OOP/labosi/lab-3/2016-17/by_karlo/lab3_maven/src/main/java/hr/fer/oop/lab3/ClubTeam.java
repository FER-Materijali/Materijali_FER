package hr.fer.oop.lab3;

import hr.fer.oop.lab3.welcomepack.Constants;
import hr.fer.oop.lab3.welcomepack.Formation;

/**
 * This class is derived from the Team class and represents a Club Team with the
 * name of the team, its formation and reputation points. Maximum number of
 * registered players for this type of team is 25.
 * 
 * @author karlo
 *
 */
public class ClubTeam extends Team {
	private int reputation = Constants.DEFAULT_REPUTATION;

	/**
	 * Constructs a new object of type {@code ClubTeam}
	 */
	public ClubTeam() {
		super(Constants.MAX_NO_PLAYERS_CLUB);
	}

	/**
	 * Constructs a new object of type {@code ClubTeam}. All variables in this
	 * type must be initialized when calling a constructor. Variable
	 * {@code name}, is unchangeable after calling this constructor.
	 * 
	 * @param name
	 *            name of the team
	 * @param formation
	 *            formation of the team
	 * @param reputation
	 *            reputation of the team
	 */
	public ClubTeam(String name, Formation formation, int reputation) {
		super(name, formation, Constants.MAX_NO_PLAYERS_CLUB);
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
	 * Sets the club team's reputation.
	 * 
	 * @param reputation
	 *            club team's reputation, should be in range [0, 100].
	 */
	public void setReputation(int reputation) {
		this.reputation = Math.max(Constants.MIN_REPUTATION, Math.min(Constants.MAX_REPUTATION, reputation));
	}

	/**
	 * Registeres a player in the team unless it's playing skill is lower than
	 * the team's reputation, or the team is already full.
	 * 
	 * @param player
	 *            FootballPlayer object
	 * @return success or not
	 */
	@Override
	public boolean registerPlayer(FootballPlayer player) {
		if (player.getPlayingSkill() < getReputation()) {
			return false;
		}
		return super.registerPlayer(player);
	}

	/**
	 * Calculates and returns the club team's rating with the following formula:
	 * <br>
	 * 70% skill + 30% emotion
	 */
	@Override
	public double calculateRating() {
		double skillRating = getRegisteredPlayers().calculateSkillSum() * Constants.SEVENTY_PERCENT;
		double emotionRating = getRegisteredPlayers().calculateEmotionSum() * Constants.THIRTY_PERCENT;
		return skillRating + emotionRating;
	}
}
