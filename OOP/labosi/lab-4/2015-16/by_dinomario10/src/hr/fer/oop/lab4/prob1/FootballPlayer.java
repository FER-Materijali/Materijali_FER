package hr.fer.oop.lab4.prob1;

import static hr.fer.oop.lab4.prob1.Misc.*;

import hr.fer.oop.lab4.prob2.IManageableTeam;
import hr.fer.oop.lab4.prob2.Team.FormationPlayers;

/**
 * The {@code FootballPlayer} class represents football players, with their
 * name, country and emotion level inherited from the {@code Person class}, with
 * the addition of Football Player's playing skill and his natural playing
 * position. Both emotion level and playing skill range within [0, 100].
 * 
 * @author dinomario10
 */
public class FootballPlayer extends Person {

	/** Football Player's playing skill, going from 0 to 100 */
	private int playingSkill;	
	/** Football Player's natural playing position */
	private PlayingPosition playingPosition;
	
	/**
	 * Constructs a new object of type {@code FootballPlayer}. All variables in
	 * this type must be initialized when calling a constructor. Variables name,
	 * country and emotions are unchangeable after calling this constructor.
	 * Variables playingSkill and playingPosition can be set through setters
	 * when desired.
	 * 
	 * @param name name of the Person
	 * @param country country in which the Person lives
	 * @param emotion Person's emotion level
	 * @param playingSkill Football Player's playing skill
	 * @param playingPosition Football Player's natural playing position
	 * @throws IllegalArgumentException
	 *             if either the given name, country or playing position is
	 *             null, or the emotion or playing skill are not within [0, 100]
	 */
	public FootballPlayer(String name, String country, int emotion, int playingSkill, PlayingPosition playingPosition) {
		super(name, country, emotion);
		setPlayingSkill(playingSkill);
		setPlayingPosition(playingPosition);
		this.playingSkill = playingSkill;
		this.playingPosition = playingPosition;
	}

	/**
	 * Returns the Football Player's playing skill
	 * 
	 * @return the Football Player's playing skill
	 */
	public int getPlayingSkill() {
		return playingSkill;
	}
	/**
	 * Sets the Football Player's playing skill
	 * 
	 * @param playingSkill Football Player's playing skill to set
	 */
	public void setPlayingSkill(int playingSkill) {
		if (!isInRange(playingSkill)) {
			throw new IllegalArgumentException(
				"Playing skill out of range: " + playingSkill
			);
		}
		this.playingSkill = playingSkill;
	}

	/**
	 * Returns the Football Player's natural playing position
	 * 
	 * @return the Football Player's natural playing position
	 */
	public PlayingPosition getPlayingPosition() {
		return playingPosition;
	}
	/**
	 * Sets the Football Player's natural playing position
	 * 
	 * @param playingPosition Football Player's natural playing position to set
	 */
	public void setPlayingPosition(PlayingPosition playingPosition) {
		if (playingPosition == null) {
			throw new IllegalArgumentException("Playing position must not be null.");
		}
		this.playingPosition = playingPosition;
	}
	
	/**
	 * Helper class that returns true if the given player can fit in formation
	 * for starting eleven. Returns false otherwise. The player can be fit in
	 * formation if there are less players of a certain playing position than
	 * maximum.
	 * 
	 * @param team a manageable team
	 * @param fp structure containing number of players in formation
	 * @return true if the given player can fit in formation, false otherwise
	 */
	protected boolean canFitInFormation(IManageableTeam team, FormationPlayers fp) {
		PlayingPosition playerPosition = this.getPlayingPosition();
		Formation formation = team.getFormation();
		
		switch (playerPosition) {
		case GK:
			if (fp.gks < formation.MAX_GKS) {
				fp.gks++;
				return true;
			}
			break;
		case DF:
			if (fp.dfs < formation.MAX_DFS) {
				fp.dfs++;
				return true;
			}
			break;
		case MF:
			if (fp.mfs < formation.MAX_MFS) {
				fp.mfs++;
				return true;
			}
			break;
		case FW:
			if (fp.fws < formation.MAX_FWS) {
				fp.fws++;
				return true;
			}
			break;
		default:
			break;
		}
		return false;
	}
}
