package hr.fer.oop.lab3;

import hr.fer.oop.lab3.welcomepack.Constants;
import hr.fer.oop.lab3.welcomepack.Formation;
import hr.fer.oop.lab3.welcomepack.ManageableTeam;
import hr.fer.oop.lab3.welcomepack.Manager;

/**
 * This class represents football coaches, with their name, country and emotion
 * level inherited from the {@code Person class}, with the addition of coaching
 * skill and it's favorite formation.
 * 
 * @author karlo
 *
 */
public class Coach extends Person implements Manager, ITrainer {

	/** The coaching skill. */
	private int coachingSkill = Constants.DEFAULT_COACHING_SKILL;

	/** The formation. */
	private Formation formation = Constants.DEFAULT_FORMATION;

	/** The managing team. */
	private ManageableTeam managingTeam = null;

	/**
	 * Constructs a new object of type {@code Coach}.
	 */
	public Coach() {
		super();
	}

	/**
	 * Constructs a new object of type {@code Coach}. All variables in this type
	 * must be initialized when calling a constructor. Variables name, country
	 * and emotions are unchangeable after calling this constructor.
	 * 
	 * @param name
	 *            name of the Person
	 * @param country
	 *            country in which the Person lives
	 * @param emotion
	 *            Person's emotion level
	 * @param coachingSkill
	 *            Coaches' coaching skill
	 * @param formation
	 *            Coaches' favorite formation
	 */
	public Coach(String name, String country, int emotion, int coachingSkill, Formation formation) {
		super(name, country, emotion);
		setCoachingSkill(coachingSkill);
		setFormation(formation);
	}

	/**
	 * Returns the Coaches coaching skill.
	 *
	 * @return the Coaches coaching skill
	 */
	public int getCoachingSkill() {
		return coachingSkill;
	}

	/**
	 * Sets the Coaches coaching skill.
	 *
	 * @param coachingSkill
	 *            Coaches coaching skill to set, should be in range [0, 100].
	 */
	public void setCoachingSkill(int coachingSkill) {
		this.coachingSkill = Math.max(Constants.MIN_COACHING_SKILL,
				Math.min(Constants.MAX_COACHING_SKILL, coachingSkill));
	}

	/**
	 * Returns the Coaches formation.
	 *
	 * @return the Coaches formation
	 */
	public Formation getFormation() {
		return formation;
	}

	/**
	 * Sets the given formation to be the Coaches formation.
	 *
	 * @param formation
	 *            Coaches formation to set
	 */
	public void setFormation(Formation formation) {
		if (formation == null) {
			return;
		}
		this.formation = formation;
	}

	/**
	 * Returns the team under this coaches management.
	 * 
	 * @return managingTeam team managed by this coach
	 */
	public ManageableTeam getManagingTeam() {
		return managingTeam;
	}

	/*
	 * (non-Javadoc)
	 * 
	 * @see hr.fer.oop.lab3.welcomepack.Manager#setManagingTeam(hr.fer.oop.lab3.
	 * welcomepack.ManageableTeam)
	 */
	@Override
	public void setManagingTeam(ManageableTeam team) {
		if (team == null) {
			return;
		}
		managingTeam = team;
	}

	/*
	 * (non-Javadoc)
	 * 
	 * @see hr.fer.oop.lab3.welcomepack.Manager#pickStartingEleven()
	 */
	@Override
	public void pickStartingEleven() {
		if (getManagingTeam() == null) {
			return;
		}

		getManagingTeam().clearStartingEleven();
		FootballPlayer[] players = getManagingTeam().getRegisteredPlayers().getPlayers();
		sortPlayersBySkill(players);
		int gk = 0, df = 0, mf = 0, fw = 0;
		for (int i = 0; i < getManagingTeam().getRegisteredPlayers().size(); i++) {
			switch (players[i].getPlayingPosition()) {
			case GK:
				if (gk < getFormation().getNoGK()) {
					gk++;
					getManagingTeam().addPlayerToStartingEleven(players[i]);
				}
				break;
			case DF:
				if (df < getFormation().getNoDF()) {
					df++;
					getManagingTeam().addPlayerToStartingEleven(players[i]);
				}
				break;
			case MF:
				if (mf < getFormation().getNoMF()) {
					mf++;
					getManagingTeam().addPlayerToStartingEleven(players[i]);
				}
				break;
			case FW:
				if (fw < getFormation().getNoFW()) {
					fw++;
					getManagingTeam().addPlayerToStartingEleven(players[i]);
				}
				break;
			}
		}
	}

	/**
	 * This method sorts the given array of Football Players by skill using
	 * reverse BubbleSort algorithm. It has the complexity of O(n^2).
	 * 
	 * @param players
	 *            {@code FootballPlayer array}
	 */
	private void sortPlayersBySkill(FootballPlayer[] players) {
		int size = getManagingTeam().getRegisteredPlayers().size();
		for (int i = 0; i < size - 1; i++) {
			for (int j = 1; j < size - i; j++) {
				if (players[j - 1].getPlayingSkill() < players[j].getPlayingSkill()) {
					FootballPlayer tmp = null;
					tmp = players[j - 1];
					players[j - 1] = players[j];
					players[j] = tmp;
				}
			}
		}
	}

	/*
	 * (non-Javadoc)
	 * 
	 * @see hr.fer.oop.lab3.welcomepack.Manager#forceMyFormation()
	 */
	@Override
	public void forceMyFormation() {
		if (getManagingTeam() == null) {
			return;
		}
		getManagingTeam().setFormation(getFormation());
	}

	/*
	 * (non-Javadoc)
	 * 
	 * @see hr.fer.oop.lab3.ITrainer#performTeamTrainingSession()
	 */
	@Override
	public void performTeamTrainingSession() {
		FootballPlayer[] players = getManagingTeam().getRegisteredPlayers().getPlayers();
		for (int i = 0; i < getManagingTeam().getRegisteredPlayers().size(); i++) {
			if (getManagingTeam().getStartingEleven().contains(players[i])) {
				continue;
			}
			if (players[i].getPlayingSkill() >= getCoachingSkill()) {
				continue;
			}
			int increasingSKill = (int) (0.1 * getCoachingSkill());
			players[i].setPlayingSkill(players[i].getPlayingSkill() + increasingSKill);
		}
	}
}
