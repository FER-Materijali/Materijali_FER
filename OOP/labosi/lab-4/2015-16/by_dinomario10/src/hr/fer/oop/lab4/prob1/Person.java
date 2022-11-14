package hr.fer.oop.lab4.prob1;

import static hr.fer.oop.lab4.prob1.Misc.*;

/**
 * The {@code Person} class represents individual persons, with their name,
 * representing country and emotion level within the range of [0, 100]. This
 * class is used as a base class for its subclasses.
 * 
 * @author dinomario10
 */
public abstract class Person {

	/** Name of the Person */
	private final String name;
	/** Country that the Person represents */
	private final String country;
	/** Emotion level. Person's emotion level goes from 0,
	 * meaning the worst, to 100, meaning the best */
	private final int emotion;
	
	/**
	 * Base constructor for its subclasses. Variables name, country and emotion
	 * are unchangeable after calling this constructor.
	 * 
	 * @param name name of the Person
	 * @param country country that the Person represents
	 * @param emotion Person's emotion level
	 * @throws IllegalArgumentException if the given name or country is null,
	 * or the emotion is not within the range [0, 100]
	 */
	public Person(String name, String country, int emotion) {
		validatePersonArguments(name, country, emotion);
		this.name = name;
		this.country = country;
		this.emotion = emotion;
	}
	
	/**
	 * Validates the {@code Person} class constructor's arguments by testing if
	 * they have been set correctly. If either name or country is {@code null},
	 * or the emotion not within the range [0, 100], this method throws an
	 * {@link IllegalArgumentException}
	 * 
	 * @param name name of the Person
	 * @param country country that the Person represents
	 * @param emotion Person's emotion level
	 */
	private static void validatePersonArguments(String name, String country, int emotion) {
		if (name == null) {
			throw new IllegalArgumentException("Name must not be null.");
		}
		if (country == null) {
			throw new IllegalArgumentException("Country must not be null.");
		}
		if (!isInRange(emotion)) {
			throw new IllegalArgumentException("Emotion out of range: " + emotion);
		}
	}
	
	/**
	 * Returns the Person's name
	 * 
	 * @return the Person's name
	 */
	public String getName() {
		return name;
	}
	
	/**
	 * Returns the country that the Person represents.
	 * 
	 * @return the country that the Person represents
	 */
	public String getCountry() {
		return country;
	}

	/**
	 * Returns the Person's emotion.
	 * 
	 * @return the Person's emotion
	 */
	public int getEmotion() {
		return emotion;
	}
	
	@Override
	public int hashCode() {
		final int prime = 31;
		int result = 1;
		result = prime * result + name.hashCode();
		result = prime * result + country.hashCode();
		result = prime * result + emotion;
		return result;
	}
	
	/**
	 * Returns true if both Person objects are equal. Two Persons are equal if
	 * they have the same name, country that they represent and emotion.
	 * 
	 * @param obj an object. Possibly a Person object
	 * @return true if both Person objects are equal
	 */
	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (!(obj instanceof Person)) {
			return false;
		}
		return personEquals((Person) obj);
	}

	/**
	 * Returns true if both Person's name, country and emotion are equal.
	 * False otherwise.
	 * 
	 * @param person a person
	 * @return true if both Person's name, country and emotion are equal
	 */
	private boolean personEquals(Person person) {
		return this.name.equals(person.name) &&
				this.country.equals(person.country) &&
				this.emotion == person.emotion;
	}
}
