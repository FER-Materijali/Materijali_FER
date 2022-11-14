package hr.fer.oop.lab4.prob4;

/**
 * The {@code IPlayableMatch} interface represents a playable match.
 * Implementing this interface means that the match could be playable.
 * An exception is thrown in case of a not playable match.
 * 
 * @author dinomario10
 */
public interface IPlayableMatch {
	
	/**
	 * This method plays the match if the match is playable. To see how a match
	 * is not playable, see {@link NotPlayableMatchException}. The match is
	 * played in a way that ratings of both teams are summed together and each
	 * individual rating is expressed relative to the sum. The match outcome is
	 * determined randomly, considering the team that has a greater rating also
	 * has greater chances to win the match. The match outcome can also be a
	 * draw.
	 * 
	 * @throws NotPlayableMatchException if the match is not playable
	 */
	public void play() throws NotPlayableMatchException;
}
