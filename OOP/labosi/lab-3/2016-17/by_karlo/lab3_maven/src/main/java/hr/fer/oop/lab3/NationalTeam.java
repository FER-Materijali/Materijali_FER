package hr.fer.oop.lab3;

import hr.fer.oop.lab3.welcomepack.Constants;
import hr.fer.oop.lab3.welcomepack.Formation;

/**
 * This class represents football national teams, with the name of the team, its
 * formation and country name. Maximum number of allowed registered players for
 * the national team is 23.
 * 
 * @author karlo
 *
 */
public class NationalTeam extends Team {

	/** The country. */
	private String country = Constants.DEFAULT_COUNTRY;

	/**
	 * Constructs a new object of type {@code NationalTeam}.
	 */
	public NationalTeam() {
		super(Constants.MAX_NO_PLAYERS_NATIONAL);
	}

	/**
	 * Constructs a new object of type {@code NationalTeam}. All variables in
	 * this type must be initialized when calling a constructor. Variables name,
	 * and country are unchangeable after calling this constructor.
	 * 
	 * @param name
	 *            name of the national football team
	 * @param formation
	 *            formation of the national football team
	 * @param country
	 *            national team country
	 */
	public NationalTeam(String name, Formation formation, String country) {
		super(name, formation, Constants.MAX_NO_PLAYERS_NATIONAL);
		setCountry(country);
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
	 * Sets the national team's country.
	 * 
	 * @param country
	 *            national team's country.
	 */
	private void setCountry(String country) {
		if (country == null) {
			return;
		}
		this.country = country;
	}

	/*
	 * (non-Javadoc)
	 * 
	 * @see hr.fer.oop.lab3.Team#registerPlayer(hr.fer.oop.lab3.FootballPlayer)
	 */
	@Override
	public boolean registerPlayer(FootballPlayer player) {
		if (!player.getCountry().equals(getCountry())) {
			return false;
		}
		return super.registerPlayer(player);
	}

	/**
	 * Calculates and returns the national team's rating with the following
	 * formula: <br>
	 * 30% skill + 70% emotion.
	 *
	 * @return the double
	 */
	@Override
	public double calculateRating() {
		double skillRating = getRegisteredPlayers().calculateSkillSum() * Constants.THIRTY_PERCENT;
		double emotionRating = getRegisteredPlayers().calculateEmotionSum() * Constants.SEVENTY_PERCENT;
		return skillRating + emotionRating;
	}
}
