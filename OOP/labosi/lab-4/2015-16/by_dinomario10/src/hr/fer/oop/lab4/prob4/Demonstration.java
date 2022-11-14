package hr.fer.oop.lab4.prob4;

import hr.fer.oop.lab4.prob1.FootballPlayer;
import hr.fer.oop.lab4.prob1.Formation;
import hr.fer.oop.lab4.prob1.PlayingPosition;
import hr.fer.oop.lab4.prob2.ClubTeam;
import hr.fer.oop.lab4.prob2.NationalTeam;
import hr.fer.oop.lab4.prob2.NotEligiblePlayerException;
import hr.fer.oop.lab4.prob2.Team;

/**
 * Demonstrates the fourth problem by all of the previously created classes,
 * class Match, interface IPlayableMatch, enumerations MatchOutcome and
 * MatchType and a new type of Exception, the NotPlayableMatchException.
 *
 * @author OOP ekipa
 */
public class Demonstration {

	public static final int DEF_PLAYER_EMOTION = 100;
	public static final int DEF_PLAYER_SKILL = 0;
	public static final String DEF_NAME_PREFIX = "Player_";
	public static final String DEF_COUNTRY = "Croatia";
	public static final PlayingPosition DEF_PLAYING_POSITION = PlayingPosition.FW;
	public static final int NO_MATCHES = 100000;

	public static void main(String[] args) throws NotEligiblePlayerException, NotPlayableMatchException {

		NationalTeam croatia = new NationalTeam("Croatia", Formation.F442, DEF_COUNTRY);
		ClubTeam varteks = new ClubTeam("Varteks", Formation.F352, 0);

		int playerSuffix = 0;

		for (int i = 0; i < Team.STARTING_ELEVEN_SIZE; i++) {
			FootballPlayer nationalPlayer = new FootballPlayer(DEF_NAME_PREFIX + playerSuffix++, DEF_COUNTRY,
					DEF_PLAYER_EMOTION, DEF_PLAYER_SKILL, DEF_PLAYING_POSITION);
			croatia.registerPlayer(nationalPlayer);
			croatia.addPlayerToStartingEleven(nationalPlayer);

			FootballPlayer clubPlayer = new FootballPlayer(DEF_NAME_PREFIX + playerSuffix++, DEF_COUNTRY,
					DEF_PLAYER_EMOTION, DEF_PLAYER_SKILL, DEF_PLAYING_POSITION);
			varteks.registerPlayer(clubPlayer);
			varteks.addPlayerToStartingEleven(clubPlayer);
		}

		System.out.println(
				"Klub i nacionalni tim imaju igrace jednakih kvaliteta i emocija... Tko pobjedjuje?\nNacionalni tim je domacin.");

		int noHomeWins = 0;
		int noDraws = 0;
		int noAwayWins = 0;

		for (int i = 0; i < NO_MATCHES; i++) {
			Match friendlyMatch = new Match(croatia, varteks, MatchType.FRIENDLY);
			friendlyMatch.play();
			switch (friendlyMatch.getOutcome()) {
			case HOME_WIN:
				noHomeWins++;
				break;
			case DRAW:
				noDraws++;
				break;
			case AWAY_WIN:
				noAwayWins++;
				break;
			case NOT_AVAILABLE:
				System.err.println("Utakmica nije odigrana.");
				break;

			default:
				break;
			}
		}
		System.out.println("Omjeri:");
		System.out.println("HOME(%):" + (float) noHomeWins / NO_MATCHES + ", DRAWS(%):" + (float) noDraws / NO_MATCHES
				+ ", AWAY(%):" + (float) noAwayWins / NO_MATCHES);

	}

}