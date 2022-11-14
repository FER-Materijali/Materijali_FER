package hr.fer.oop.lab3;

import hr.fer.oop.lab3.welcomepack.Constants;

/**
 * This class represents individual persons, with their name, representing
 * country and emotion level within the range of [0, 100]. This class is used as
 * a base class for its subclasses.
 * 
 * @author karlo
 *
 */
public abstract class Person {

	/** The name. */
	private String name = Constants.DEFAULT_PLAYER_NAME;

	/** The country. */
	private String country = Constants.DEFAULT_COUNTRY;

	/** The emotion. */
	private int emotion = Constants.DEFAULT_EMOTION;

	/**
	 * Base constructor for its subclasses.
	 */
	public Person() {
	}

	/**
	 * Base constructor for its subclasses. Variables name, country and emotion
	 * are unchangeable after calling this constructor.
	 * 
	 * @param name
	 *            name of the Person
	 * @param country
	 *            country that the Person represents
	 * @param emotion
	 *            Person's emotion level
	 */
	public Person(String name, String country, int emotion) {
		setName(name);
		setCountry(country);
		setEmotion(emotion);
	}

	/**
	 * Returns the person's name.
	 *
	 * @return the person's name
	 */
	public String getName() {
		return name;
	}

	/**
	 * Sets the person's name.
	 * 
	 * @param name
	 *            person's name
	 */
	private void setName(String name) {
		if (name == null) {
			return;
		}
		this.name = name;
	}

	/**
	 * Returns the country that the person represents.
	 * 
	 * @return the country that the person represents
	 */
	public String getCountry() {
		return country;
	}

	/**
	 * Sets the person's country.
	 * 
	 * @param country
	 *            person's country
	 */
	private void setCountry(String country) {
		if (country == null) {
			return;
		}
		this.country = country;
	}

	/**
	 * Returns the person's emotion.
	 * 
	 * @return the person's emotion
	 */
	public int getEmotion() {
		return emotion;
	}

	/**
	 * Sets the person's emotion.
	 * 
	 * @param emotion
	 *            person's emotion, should be in range [0, 100].
	 */
	public void setEmotion(int emotion) {
		this.emotion = Math.max(Constants.MIN_EMOTION, Math.min(Constants.MAX_EMOTION, emotion));
	}

	/**
	 * Returns true if both Person objects are equal. Two Persons are equal if
	 * they have the same name and tge country that they represent
	 * 
	 * @param obj
	 *            an object. Possibly a Person object
	 * @return true if both Person objects are equal
	 */
	@Override
	public boolean equals(Object obj) {
		if (obj == null) {
			return false;
		}
		Person other = (Person) obj;
		if (obj.getClass() == Coach.class) {
			other = (Coach) obj;
		} else if (obj.getClass() == FootballPlayer.class) {
			other = (FootballPlayer) obj;
		}
		return other.getName().equals(getName()) && other.getCountry().equals(getCountry());
	}

	/*
	 * (non-Javadoc)
	 * 
	 * @see java.lang.Object#hashCode()
	 */
	@Override
	public int hashCode() {
		return ((getName().hashCode() * 397) ^ getCountry().hashCode());
	}
}
