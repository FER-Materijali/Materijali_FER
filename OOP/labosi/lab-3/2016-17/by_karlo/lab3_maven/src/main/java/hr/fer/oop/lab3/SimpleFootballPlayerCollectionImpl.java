package hr.fer.oop.lab3;

import hr.fer.oop.lab3.welcomepack.SimpleFootballPlayerCollection;

/**
 * This class represents a collection of Football Players. 
 * 
 * @author karlo
 *
 */
public class SimpleFootballPlayerCollectionImpl implements SimpleFootballPlayerCollection {	
	
	/** The players. */
	private FootballPlayer[] players;
	
	/** The max size. */
	private final int maxSize;
	
	/** The size. */
	private int size;
		
	/**
	 * Constructs a new collection of type {@code FootballPlayer} with the provided size.
	 * 
	 * @param maxSize collection size
	 */
	public SimpleFootballPlayerCollectionImpl(int maxSize) {
		this.maxSize = maxSize;
		players = new FootballPlayer[maxSize];
	}

	/* (non-Javadoc)
	 * @see hr.fer.oop.lab3.welcomepack.SimpleFootballPlayerCollection#add(hr.fer.oop.lab3.FootballPlayer)
	 */
	@Override
	public boolean add(FootballPlayer player) {
		if (size >= getMaxSize()) {
			return false;
		}         		
		if(contains(player)) {
			return false;
		}
			
		players[size++] = player;
		return true;
	}

	/* (non-Javadoc)
	 * @see hr.fer.oop.lab3.welcomepack.SimpleFootballPlayerCollection#calculateEmotionSum()
	 */
	@Override
	public int calculateEmotionSum() {
		int sum = 0;
		for (int i = 0; i < size; i++) {
			sum += players[i].getEmotion();
		}
		return sum;
	}

	/* (non-Javadoc)
	 * @see hr.fer.oop.lab3.welcomepack.SimpleFootballPlayerCollection#calculateSkillSum()
	 */
	@Override
	public int calculateSkillSum() {
		int sum = 0;
		for (int i = 0; i < size; i++) {
			sum += players[i].getPlayingSkill();
		}
		return sum;
	}

	/* (non-Javadoc)
	 * @see hr.fer.oop.lab3.welcomepack.SimpleFootballPlayerCollection#clear()
	 */
	@Override
	public void clear() {
		for (int i = 0; i < size; i++) {
			players[i] = null;
		}		
		size = 0;
	}

	/* (non-Javadoc)
	 * @see hr.fer.oop.lab3.welcomepack.SimpleFootballPlayerCollection#contains(hr.fer.oop.lab3.FootballPlayer)
	 */
	@Override
	public boolean contains(FootballPlayer player) {
		for (int i = 0; i < size; i++) {
            if (players[i].equals(player)) {
                return true;
            }
        }
        return false;
	}

	/* (non-Javadoc)
	 * @see hr.fer.oop.lab3.welcomepack.SimpleFootballPlayerCollection#getMaxSize()
	 */
	@Override
	public int getMaxSize() {
		return maxSize;
	}

	/* (non-Javadoc)
	 * @see hr.fer.oop.lab3.welcomepack.SimpleFootballPlayerCollection#getPlayers()
	 */
	@Override
	public FootballPlayer[] getPlayers() {
		return players;
	}

	/* (non-Javadoc)
	 * @see hr.fer.oop.lab3.welcomepack.SimpleFootballPlayerCollection#size()
	 */
	@Override
	public int size() {
		return size;
	}
}
