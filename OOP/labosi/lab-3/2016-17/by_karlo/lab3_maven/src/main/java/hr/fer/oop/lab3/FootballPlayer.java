package hr.fer.oop.lab3;

import hr.fer.oop.lab3.welcomepack.Constants;
import hr.fer.oop.lab3.welcomepack.PlayingPosition;

/**
 * This class represents football players, with their name, country and emotion
 * level inherited from the {@code Person class}, with the addition of Football
 * Player's playing skill and his natural playing position.
 * 
 * @author karlo
 *
 */
public class FootballPlayer extends Person {
	private int playingSkill = Constants.DEFAULT_PLAYING_SKILL;
	private PlayingPosition playingPosition = Constants.DEFAULT_PLAYING_POSITION;

	/**
	 * Constructs a new object of type {@code FootballPlayer}
	 */
	public FootballPlayer() {
		super();
	}

	/**
	 * Constructs a new object of type {@code FootballPlayer}. All variables in
	 * this type must be initialized when calling a constructor. Variables name,
	 * country and emotions are unchangeable after calling this constructor.
	 * 
	 * @param name
	 *            name of the Person
	 * @param country
	 *            country in which the Person lives
	 * @param emotion
	 *            Person's emotion level
	 * @param playingSkill
	 *            Football Player's playing skill
	 * @param playingPosition
	 *            Football Player's natural playing position
	 */
	public FootballPlayer(String name, String country, int emotion, int playingSkill, PlayingPosition playingPosition) {
		super(name, country, emotion);
		setPlayingSkill(playingSkill);
		setPlayingPosition(playingPosition);
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
	 * @param playingSkill
	 *            Football Player's playing skill to set, should be in range [0,
	 *            100].
	 */
	public void setPlayingSkill(int playingSkill) {
		this.playingSkill = Math.max(Constants.MIN_PLAYING_SKILL, Math.min(Constants.MAX_PLAYING_SKILL, playingSkill));
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
	 * @param playingPosition
	 *            Football Player's natural playing position to set
	 */
	public void setPlayingPosition(PlayingPosition playingPosition) {
		if (playingPosition == null) {
			return;
		}
		this.playingPosition = playingPosition;
	}
}
