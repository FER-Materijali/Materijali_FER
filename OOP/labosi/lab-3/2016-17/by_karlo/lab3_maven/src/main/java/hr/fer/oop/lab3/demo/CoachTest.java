package hr.fer.oop.lab3.demo;

import hr.fer.oop.lab3.ClubTeam;
import hr.fer.oop.lab3.Coach;
import hr.fer.oop.lab3.FootballPlayer;
import hr.fer.oop.lab3.welcomepack.Constants;
import hr.fer.oop.lab3.welcomepack.Formation;
import hr.fer.oop.lab3.welcomepack.PlayingPosition;

public class CoachTest {

	public static void main(String[] args) {

		Coach defaultCoach = new Coach();
		Coach mainCoach = new Coach("Main", Constants.DEFAULT_COUNTRY, 1, 1, Formation.F352);
		Coach helpCoach = new Coach();

		if (defaultCoach.equals(null)) {
			System.err.println("TEST FAILED: Coach is null");
		}

		if (mainCoach.equals(defaultCoach)) {
			System.err.println("TEST FAILED: Default and Main coach must be different");
		}

		helpCoach.setCoachingSkill(10);
		helpCoach.setEmotion(10);
		if (!defaultCoach.equals(helpCoach)) {
			System.err.println("TEST FAILED: Wrong comparison of coaches.");
		}
		
		Coach wrongCoach = new Coach(null, null, -5, 150, Formation.F541);
		if(wrongCoach.getName()==null || 
				wrongCoach.getCountry() == null || 
				wrongCoach.getEmotion() <0 ||
				wrongCoach.getCoachingSkill() > 100){
			System.err.println("TEST FAILED: Coach values must be in boundries!!");
		}
		
		Coach coach = new Coach("Dima", "Russia", 80, 80, Formation.F352);
		ClubTeam clubTean = new ClubTeam("TopSkill", Constants.DEFAULT_FORMATION, 50);
		for (int i = 0; i < Constants.MAX_NO_PLAYERS_CLUB; i++) {
			int randomSkill = 50 + (int)(Math.random() * ((100 - 50) + 1)); // random [50, 100]
			PlayingPosition randomPosition = PlayingPosition.values()[i % 4];
			FootballPlayer topSkillPlayer = new FootballPlayer("Player" + i, Constants.DEFAULT_COUNTRY, 80, randomSkill, randomPosition);
			clubTean.registerPlayer(topSkillPlayer);
		}
		coach.setManagingTeam(clubTean);
		if(coach.getManagingTeam() == null) {
			System.err.println("TEST FAILED: Coach is still unemployeed!!");
		}
		coach.forceMyFormation();
		if(clubTean.getFormation() != coach.getFormation()) {
			System.err.println("TEST FAILED: Coach and team formation must be same!!");
		}
		coach.pickStartingEleven();
		if(clubTean.getStartingEleven().size() != Constants.STARTING_ELEVEN_SIZE) {
			System.err.println("TEST FAILED: There is not 11 players in starting eleven!!");
		}
		
		System.out.println("STARTING ELEVEN PLAYER SKILL BEFORE TRAINING:");
		FootballPlayer[] players = coach.getManagingTeam().getRegisteredPlayers().getPlayers();
		for (int i = 0; i < coach.getManagingTeam().getRegisteredPlayers().size(); i++) {
			if(coach.getManagingTeam().getStartingEleven().contains(players[i])) {
				System.out.println("Player: " + players[i].getName() + " \tskill: " + players[i].getPlayingSkill() + " \tposition: " 
						+ players[i].getPlayingPosition().toString());
			}	
		}
		
		coach.performTeamTrainingSession();
		System.out.println("\nSTARTING ELEVEN PLAYER SKILL AFTER TRAINING:");
		for (int i = 0; i < coach.getManagingTeam().getRegisteredPlayers().size(); i++) {
			if(coach.getManagingTeam().getStartingEleven().contains(players[i])) {
				System.out.println("Player: " + players[i].getName() + " \tskill: " + players[i].getPlayingSkill() + " \tposition: " 
						+ players[i].getPlayingPosition().toString());
			}	
		}
	
		//ignore printed system errors displayed from another classes, as described in instructions.
		System.out.println("This is only valid message that should be displayed from this main!!!!");

	}
}
