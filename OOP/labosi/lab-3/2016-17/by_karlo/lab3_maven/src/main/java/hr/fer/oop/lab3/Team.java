package hr.fer.oop.lab3;

import hr.fer.oop.lab3.welcomepack.Constants;
import hr.fer.oop.lab3.welcomepack.Formation;
import hr.fer.oop.lab3.welcomepack.ManageableTeam;
import hr.fer.oop.lab3.welcomepack.SimpleFootballPlayerCollection;

/**
 * This class represents football teams, with the name of the team and its formation. 
 * All {@code Team} classes also have implemented collections containing registered 
 * players and starting eleven players of type {@code FootballPlayer}. 
 * This class is used as a base class for its subclasses. 
 * 
 * @author karlo
 *
 */
public abstract class Team implements ManageableTeam {
	
	/** The name. */
	private String name = Constants.DEFAULT_TEAM_NAME;
	
	/** The formation. */
	private Formation formation = Constants.DEFAULT_FORMATION;
	
	/** The registered players. */
	private SimpleFootballPlayerCollection registeredPlayers;
	
	/** The starting eleven. */
	private SimpleFootballPlayerCollection startingEleven = new SimpleFootballPlayerCollectionImpl(Constants.STARTING_ELEVEN_SIZE);

	/**
	 * Base constructor for its subclasses.
	 *
	 * @param maxRegisteredPlayers the max registered players
	 */
	public Team(int maxRegisteredPlayers) {
		registeredPlayers = new SimpleFootballPlayerCollectionImpl(maxRegisteredPlayers);
	}
	
	/**
	 * Base constructor for its subclasses. Variables name and formation 
	 * are unchangeable after calling this constructor.
	 *
	 * @param name name of the football team
	 * @param formation football team's formation
	 * @param maxRegisteredPlayers the max registered players
	 */
	public Team(String name, Formation formation, int maxRegisteredPlayers) {
		setName(name);
		setFormation(formation);
		registeredPlayers = new SimpleFootballPlayerCollectionImpl(maxRegisteredPlayers);
	}
	
	/**
	 * Returns the name of the team.
	 * 
	 * @return name of the team
	 */
	public String getName() {
		return name;
	}
	
	/**
	 * Sets the team's name.
	 * 
	 * @param name team's name
	 */
	private void setName(String name) {
		if(name == null) {
			return;
		}
		this.name = name;
	}
	
	/* (non-Javadoc)
	 * @see hr.fer.oop.lab3.welcomepack.ManageableTeam#getFormation()
	 */
	public Formation getFormation() {
		return formation;
	}
	
	/* (non-Javadoc)
	 * @see hr.fer.oop.lab3.welcomepack.ManageableTeam#setFormation(hr.fer.oop.lab3.welcomepack.Formation)
	 */
	public void setFormation(Formation formation) {
		if(formation == null) {
			return;
		}
		this.formation = formation;
	}
	
	/* (non-Javadoc)
	 * @see hr.fer.oop.lab3.welcomepack.ManageableTeam#addPlayerToStartingEleven(hr.fer.oop.lab3.FootballPlayer)
	 */
	public boolean addPlayerToStartingEleven(FootballPlayer player) {
		if(getStartingEleven().contains(player)) {
			return false;
		}
		return getStartingEleven().add(player);
	}
	
	/* (non-Javadoc)
	 * @see hr.fer.oop.lab3.welcomepack.ManageableTeam#registerPlayer(hr.fer.oop.lab3.FootballPlayer)
	 */
	public boolean registerPlayer(FootballPlayer player) {
		if(isPlayerRegistered(player)) {
			return false;
		}
		return getRegisteredPlayers().add(player);
	}
	
	/* (non-Javadoc)
	 * @see hr.fer.oop.lab3.welcomepack.ManageableTeam#isPlayerRegistered(hr.fer.oop.lab3.FootballPlayer)
	 */
	public boolean isPlayerRegistered(FootballPlayer player) {
		return getRegisteredPlayers().contains(player);
	}
	
	/* (non-Javadoc)
	 * @see hr.fer.oop.lab3.welcomepack.ManageableTeam#getRegisteredPlayers()
	 */
	public SimpleFootballPlayerCollection getRegisteredPlayers() {
		return registeredPlayers;
	}

	/* (non-Javadoc)
	 * @see hr.fer.oop.lab3.welcomepack.ManageableTeam#getStartingEleven()
	 */
	public SimpleFootballPlayerCollection getStartingEleven() {
		return startingEleven;
	}
	
	/* (non-Javadoc)
	 * @see hr.fer.oop.lab3.welcomepack.ManageableTeam#clearStartingEleven()
	 */
	public void clearStartingEleven() {
		getStartingEleven().clear();
	}
	
	/* (non-Javadoc)
	 * @see hr.fer.oop.lab3.welcomepack.ManageableTeam#calculateRating()
	 */
	public abstract double calculateRating();
}
