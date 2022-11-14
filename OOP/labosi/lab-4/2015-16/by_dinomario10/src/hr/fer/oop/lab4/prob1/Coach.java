package hr.fer.oop.lab4.prob1;

import static hr.fer.oop.lab4.prob1.Misc.*;

import java.util.Collection;
import java.util.function.Predicate;

import hr.fer.oop.lab4.prob2.IManageableTeam;
import hr.fer.oop.lab4.prob2.NotEligiblePlayerException;
import hr.fer.oop.lab4.prob2.Team;
import hr.fer.oop.lab4.prob2.Team.FormationPlayers;
import hr.fer.oop.lab4.prob3.IManager;
import hr.fer.oop.lab4.prob3.UnemployedCoachException;

/**
 * The {@code Coach} class represents football coaches, with their name, country
 * and emotion level inherited from the {@code Person class}, with the addition
 * of Coaches' coaching skill and his favorite formation. Both emotion level and
 * coaching skill range within [0, 100].
 * 
 * @author dinomario10
 */
public class Coach extends Person implements IManager {

	/** Coaches' coaching skill, going from 0 to 100 */
	private int coachingSkill;
	/** Coaches' favorite formation */
	private Formation formation;
	/** A team managed by Coach */
	private IManageableTeam managingTeam;

	/**
	 * Constructs a new object of type {@code Coach}. All variables in this type
	 * must be initialized when calling a constructor. Variables name, country
	 * and emotions are unchangeable after calling this constructor. Variables
	 * coachingSkill and formation can be set through setters when desired.
	 * 
	 * @param name name of the Person
	 * @param country country in which the Person lives
	 * @param emotion Person's emotion level
	 * @param coachingSkill Coaches' coaching skill
	 * @param formation Coaches' favorite formation
	 * @throws IllegalArgumentException
	 *             if either the given name, country or formation is null, or
	 *             the emotion or coaching skill are not within range [0, 100]
	 */
	public Coach(String name, String country, int emotion, int coachingSkill, Formation formation) {
		super(name, country, emotion);
		setCoachingSkill(coachingSkill);
		setFavoriteFormation(formation);
		this.managingTeam = null;
	}
	
	/**
	 * Returns the Coaches' coaching skill
	 * 
	 * @return the Coaches' coaching skill
	 */
	public int getCoachingSkill() {
		return coachingSkill;
	}
	/**
	 * Sets the Coaches' coaching skill
	 * 
	 * @param coachingSkill Coaches' coaching skill to set
	 */
	public void setCoachingSkill(int coachingSkill) {
		if (!isInRange(coachingSkill)) {
			throw new IllegalArgumentException(
				"Coaching skill out of range: " + coachingSkill
			);
		}
		this.coachingSkill = coachingSkill;
	}
	
	/**
	 * Returns the Coaches' favorite formation
	 * 
	 * @return the Coaches' favorite formation
	 */
	public Formation getFavoriteFormation() {
		return formation;
	}
	/**
	 * Sets the given formation to be the Coaches' favorite formation
	 * 
	 * @param formation Coaches' favorite formation to set
	 */
	public void setFavoriteFormation(Formation formation) {
		if (formation == null) {
			throw new IllegalArgumentException("Formation must not be null.");
		}
		this.formation = formation;
	}
	
	/**
	 * Returns the team under this coaches' management.
	 * 
	 * @return managingTeam team managed by this coach
	 */
	public IManageableTeam getManagingTeam() {
		return managingTeam;
	}
	
	@Override
	public void setManagingTeam(IManageableTeam team) {
		managingTeam = team;
	}

	@Override
	public void registerPlayers(Iterable<FootballPlayer> offeredPlayers,
			Predicate<FootballPlayer> criteria) throws UnemployedCoachException {
		this.checkCoachEmployment();
		for (FootballPlayer player : offeredPlayers) {
			if (criteria.test(player)) {
				if (managingTeam.isPlayerRegistrable(player)) {
					try {
						managingTeam.registerPlayer(player);
					} catch(NotEligiblePlayerException e) {
						continue;
					}
				}
			}
		}
	}

	@Override
	public void pickStartingEleven(Predicate<FootballPlayer> criteria) throws UnemployedCoachException {
		this.checkCoachEmployment();
		
		managingTeam.clearStartingEleven();
		
		FormationPlayers formationPlayers = new Team.FormationPlayers();
		
		Collection<FootballPlayer> registeredPlayers = managingTeam.getRegisteredPlayers();
		for (FootballPlayer player : registeredPlayers) {
			if (criteria.test(player)) {
				if (player.canFitInFormation(managingTeam, formationPlayers)) {
					managingTeam.addPlayerToStartingEleven(player);
				}
			}
		}
	}

	@Override
	public void forceMyFormation() throws UnemployedCoachException {
		this.checkCoachEmployment();
		managingTeam.setFormation(getFavoriteFormation());
		
	}
	
	/**
	 * Checks if the coach is employed by testing if he manages a team.
	 * If he is unemployed, this method throws an exception.
	 * 
	 * @throws UnemployedCoachException if the coach is unemployed
	 */
	private void checkCoachEmployment() throws UnemployedCoachException {
		if (this.managingTeam == null) {
			throw new UnemployedCoachException(
				"The coach " + getName() + " has no team to manage."
			);
		}
	}
}
