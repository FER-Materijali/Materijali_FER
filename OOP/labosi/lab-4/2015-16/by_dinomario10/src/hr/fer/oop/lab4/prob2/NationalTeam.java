package hr.fer.oop.lab4.prob2;

import hr.fer.oop.lab4.prob1.FootballPlayer;
import hr.fer.oop.lab4.prob1.Formation;

/**
 * The {@code NationalTeam} class represents football national teams, with the
 * name of the team, its formation and country name. Maximum number of
 * registered players for the national team is 23.
 * 
 * @author dinomario10
 */
public class NationalTeam extends Team {

	/** Country of the national team */
	private final String country;
	/** Maximum number of players in a national team */
	public static final int MAX_PLAYERS = 23;
	
	/**
	 * Constructs a new object of type {@code NationalTeam}. All variables in
	 * this type must be initialized when calling a constructor. Variables name,
	 * and country are unchangeable after calling this constructor. Variable
	 * formation can be changed through a setter when desired.
	 * 
	 * @param name name of the national football team
	 * @param formation formation of the national football team
	 * @param country national team country
	 */
	public NationalTeam(String name, Formation formation, String country) {
		super(name, formation, MAX_PLAYERS);
		if (country == null) {
			throw new IllegalArgumentException("Country must not be null.");
		}
		this.country = country;
	}
	
	/**
	 * Returns the national team's country.
	 * 
	 * @return the national team's country
	 */
	public String getCountry() {
		return country;
	}
	/**
	 * Returns true if the player can be registered to a team. The player gets
	 * added to the registered players collection if there is free room in the
	 * collection and if the player's and the team's country match.
	 * 
	 * @param player player to be registered
	 * @return true if the player can be registered to a team
	 */
	@Override
	public boolean isPlayerRegistrable(FootballPlayer player) {
		return player.getCountry().equals(country);
	}

	@Override
	public void registerPlayer(FootballPlayer player) throws NotEligiblePlayerException {
		if (!isPlayerRegistrable(player)) {
			throw new NotEligiblePlayerException(
				"Player " + player.getName() + " (" + player.getCountry() + ") "
				+ "cannot be registered in national team " + this.getName()
				+ " because the countries do not match."
			);
		}
		checkRegisteredPlayers(player, MAX_PLAYERS);
		registeredPlayers.add(player);
	}

	/**
	 * Calculates and returns the team rating. For a national team, the team
	 * rating is calculated with the following formula: <br>
	 * 30% team's skill + 70% team spirit
	 */
	@Override
	public double calculateRating() {
		final double SKILL_PERC = 0.3;
		final double SPIRIT_PERC = 0.7;
		return rating(SKILL_PERC, SPIRIT_PERC);
	}

}
