package hr.fer.oop.lab4.prob2;

import java.util.Collection;
import java.util.LinkedHashSet;
import java.util.function.Predicate;

import hr.fer.oop.lab4.prob1.FootballPlayer;
import hr.fer.oop.lab4.prob1.Formation;

/**
 * The {@code Team} class represents football teams, with the name of the team
 * and its formation. All {@code Team} classed also have implemented collections
 * containing registered players and starting eleven players of type
 * {@code FootballPlayer}. This class is used as a base class for its
 * subclasses.
 * 
 * @author dinomario10
 */
public abstract class Team implements IManageableTeam, IMatchInspectableTeam {
	
	/** Name of the football team */
	private final String name;
	/** Football team's formation */
	private Formation formation;
	/** Collection of registered players, containing no duplicates */
	protected Collection<FootballPlayer> registeredPlayers;
	/** Collection of starting players, containing no duplicates */
	private Collection<FootballPlayer> startingEleven;
	/** Maximum number of players in starting eleven */
	public static final int STARTING_ELEVEN_SIZE = 11;
	
	/**
	 * Base constructor for its subclasses. Variables name and formation are
	 * unchangeable after calling this constructor.
	 * 
	 * @param name name of the football team
	 * @param formation football team's formation
	 * @param teamCapacity maximum number of registered players in a team
	 * @throws IllegalArgumentException
	 *             if either the given name of formation is null
	 */
	public Team(String name, Formation formation, int teamCapacity) {
		if (name == null) {
			throw new IllegalArgumentException("Name must not be null.");
		}
		this.name = name;
		setFormation(formation);
		this.registeredPlayers = new LinkedHashSet<>(teamCapacity);
		this.startingEleven = new LinkedHashSet<>(STARTING_ELEVEN_SIZE);
	}
		
	/**
	 * Returns the name of the team.
	 * 
	 * @return name of the team
	 */
	public String getName() {
		return name;
	}
	
	@Override
	public Formation getFormation() {
		return formation;
	}
	
	@Override
	public void setFormation(Formation formation) {
		if (formation == null) {
			throw new IllegalArgumentException("Formation must not be null.");
		}
		this.formation = formation;
	}
	
	@Override
	public abstract void registerPlayer(FootballPlayer player) throws NotEligiblePlayerException;
	
	@Override
	public void unregisterPlayer(FootballPlayer player) throws IllegalArgumentException {
		if (!registeredPlayers.remove(player)) {
			throw new IllegalArgumentException(
				"Player " + player.getName()
				+ " not found in registered players of team "
				+ this.getName() + "."
			);
		}
	}
	
	@Override
	public void clearStartingEleven() {
		startingEleven.clear();
	}
	
	@Override
	public void addPlayerToStartingEleven(FootballPlayer player) throws NotEligiblePlayerException {
		if (!registeredPlayers.contains(player)) {
			throw new NotEligiblePlayerException(
				"Player " + player.getName()
				+ " not found in registered players of team "
				+ this.getName() + "."
			);
		}
		if (startingEleven.size() == 11) {
			throw new NotEligiblePlayerException(
				"Can't fit player " + player.getName() + " in starting eleven. "
				+ "Already eleven players in starting eleven."
			);
		}
		if (startingEleven.contains(player)) {
			throw new NotEligiblePlayerException(
				"Player " + player.getName() + " is already in the starting eleven."
			);
		}
		startingEleven.add(player);
	}
	
	@Override
	public void removePlayerFromStartingEleven(FootballPlayer player) throws IllegalArgumentException {
		if (!startingEleven.remove(player)) {
			throw new IllegalArgumentException(
				"Player " + player.getName() + "is not found in the starting eleven."
			);
		}
	}
	
	@Override
	public abstract boolean isPlayerRegistrable(FootballPlayer player);
	
	@Override
	public Collection<FootballPlayer> getRegisteredPlayers() {
		return new LinkedHashSet<>(registeredPlayers);
	}
	
	@Override
	public Collection<FootballPlayer> getStartingEleven() {
		return new LinkedHashSet<>(startingEleven);
	}
	
	@Override
	public Collection<FootballPlayer> filterRegisteredPlayers(Predicate<FootballPlayer> criteria) {
		Collection<FootballPlayer> filteredPlayers = new LinkedHashSet<>();
		for (FootballPlayer player : this.registeredPlayers) {
			if (criteria.test(player)) {
				filteredPlayers.add(player);
			}
		}
		return filteredPlayers;
	}
	
	@Override
	public boolean isMatchReady() {
		return startingEleven.size() >= 7;
	}
	
	@Override
	public int calculateTeamSpirit() {
		int emotionSum = 0;
		for (FootballPlayer player : startingEleven) {
			emotionSum += player.getEmotion();
		}
		return emotionSum;
	}
	
	@Override
	public int calculateTeamSkill() {
		int skillSum = 0;
		for (FootballPlayer player : startingEleven) {
			skillSum += player.getPlayingSkill();
		}
		return skillSum;
	}
	
	@Override
	public abstract double calculateRating();
	
	/**
	 * Calculates the team rating based on the following formula:
	 * <br>Skill % * team skill + Spirit % * team spirit
	 * 
	 * @param skillPercentage percentage of the team skill
	 * @param spiritPercentage percentage of the team spirit
	 * @return the team rating based on the previously mentioned formula
	 */
	protected double rating(double skillPercentage, double spiritPercentage) {
		int teamSkill = this.calculateTeamSkill();
		int teamSpirit = this.calculateTeamSpirit();
		return skillPercentage*teamSkill + spiritPercentage*teamSpirit;
	}
	
	/**
	 * Checks if the player for registration is already registered or if there
	 * is any more room for the player. Throws an exception if either of the
	 * criteria is not satisfied.
	 * 
	 * @param player player to be registered
	 * @param maxPlayers maximum number of players in team
	 * @throws NotEligiblePlayerException
	 *             if player is already registered or if there is no more room
	 *             for registration
	 */
	protected void checkRegisteredPlayers(FootballPlayer player, int maxPlayers) throws NotEligiblePlayerException {
		if (registeredPlayers.contains(player)) {
			throw new NotEligiblePlayerException(
				"Player " + player.getName() + "is already registered."
			);
		}
		if (registeredPlayers.size() == maxPlayers) {
			throw new NotEligiblePlayerException(
				"Can't register player " + player.getName() + ". There"
				+ " are already " + maxPlayers + " players registered."
			);
		}
	}
	
	/**
	 * Class containing number of players in certain individual playing
	 * positions. When the object of type {@code FormationPlayers} is created,
	 * all variables are set to 0. This is used for creating formations with the
	 * correct amount of players in it.
	 * 
	 * @author dinomario10
	 */
	public static class FormationPlayers {
		/** Number of goalkeepers */
		public int gks;
		/** Number of defenders */
		public int dfs;
		/** Number of midfielders */
		public int mfs;
		/** Number of forwards */
		public int fws;
	}
}
