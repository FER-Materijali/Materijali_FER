package hr.fer.oop.lab4.prob4;

import hr.fer.oop.lab4.prob2.IMatchInspectableTeam;

/**
 * {@code Match} class represents a playable match. All teams that participate
 * in a Match must be match-inspectable (must implement
 * {@code IMatchInspectableTeam} interface. Outcome of the match is stored in
 * the {@code outcome} variable after the match ends.
 * 
 * @author dinomario10
 */
public class Match implements IPlayableMatch {

	/** A home team that is inspectable */
	private final IMatchInspectableTeam home;
	/** A guest team that is inspectable */
	private final IMatchInspectableTeam away;
	/** Type of the match */
	private final MatchType type;
	/** Outcome of the match */
	private MatchOutcome outcome;

	/**
	 * Constructs a new {@code Match} with given parameters {@code home} team,
	 * {@code away} team and match {@code type}. Throws an exception if either
	 * of these parameters is {@code null}.
	 * 
	 * @param home a home team
	 * @param away a guest team
	 * @param type type of the match
	 * @see IMatchInspectableTeam
	 */
	public Match(IMatchInspectableTeam home, IMatchInspectableTeam away, MatchType type) {
		validateMatchArguments(home, away, type);
		this.home = home;
		this.away = away;
		this.type = type;
		this.outcome = MatchOutcome.NOT_AVAILABLE;
	}
	
	/**
	 * Validates the {@code Match} class constructor's arguments by testing if
	 * they have been set correctly. If either home or away team is {@code null}, or the
	 * type of the match is {@code null}, this method throws an
	 * {@link IllegalArgumentException}
	 * 
	 * @param home home team
	 * @param away guest team
	 * @param type type of the match
	 */
	private static void validateMatchArguments(IMatchInspectableTeam home, IMatchInspectableTeam away, MatchType type) {
		if (home == null) {
			throw new IllegalArgumentException("Home team must not be null.");
		}
		if (away == null) {
			throw new IllegalArgumentException("Away team must not be null.");
		}
		if (type == null) {
			throw new IllegalArgumentException("Match type must not be null.");
		}
	}
	
	/**
	 * Returns the {@code IMatchInspectableTeam} home team.
	 * 
	 * @return the home team
	 */
	public IMatchInspectableTeam getHome() {
		return home;
	}

	/**
	 * Returns the {@code IMatchInspectableTeam} away team.
	 * 
	 * @return the away team
	 */
	public IMatchInspectableTeam getAway() {
		return away;
	}

	/**
	 * Returns the match type.
	 * 
	 * @return the match type
	 */
	public MatchType getType() {
		return type;
	}
	
	/**
	 * Returns the match outcome.
	 * 
	 * @return the match outcome
	 */
	public MatchOutcome getOutcome() {
		return outcome;
	}

	@Override
	public void play() throws NotPlayableMatchException {
		checkMatchPlayability();
		double homeRating = home.calculateRating();
		double awayRating = away.calculateRating();
		double sumOfTeamsRatings = homeRating + awayRating;
		
		double h = homeRating / sumOfTeamsRatings;
		double a = awayRating / sumOfTeamsRatings;
		double min = Math.min(a, h);
		
		double random = Math.random();
		if (random < h - min/2) {
			outcome = MatchOutcome.HOME_WIN;
		} else if (random > h + min/2) {
			outcome = MatchOutcome.AWAY_WIN;
		} else {
			outcome = MatchOutcome.DRAW;
		}
	}

	/**
	 * Checks if the match is playable. Throws a
	 * {@code NotPlayableMatchException} if match is not playable. To see how a
	 * match is not playable, see {@link NotPlayableMatchException}.
	 * 
	 * @throws NotPlayableMatchException if match is not playable
	 */
	private void checkMatchPlayability() throws NotPlayableMatchException {
		if (home == null) {
			throw new NotPlayableMatchException("Home team must not be null.");
		}
		if (away == null) {
			throw new NotPlayableMatchException("Away team must not be null.");
		}
		if (type == null) {
			throw new NotPlayableMatchException("Match type must not be null.");
		}
		if (type == MatchType.COMPETITIVE) {
			if (home.getClass() != away.getClass()) {
				throw new NotPlayableMatchException(
					"Teams are not of the same type. "
					+ "Both teams must be either club teams or national teams."
				);
			}
		}
		if (!home.isMatchReady()) {
			throw new NotPlayableMatchException("Home team is not ready.");
		}
		if (!away.isMatchReady()) {
			throw new NotPlayableMatchException("Away team is not ready.");
		}
	}
}
