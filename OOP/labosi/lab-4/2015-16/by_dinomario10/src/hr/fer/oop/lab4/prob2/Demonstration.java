package hr.fer.oop.lab4.prob2;

import hr.fer.oop.lab4.prob1.Formation;

/**
 * Demonstrates the second problem by using classes Team, ClubTeam and
 * NationalTeam, interfaces IManageableTeam and IMatchInspectableTeam and a new
 * type of Exception, the NotEligiblePlayerException.
 * 
 * @author OOP ekipa
 * @author dinomario10
 */
public class Demonstration {

	public static void main(String[] args) {
		System.out.println("Stvaranje novog tima...");
		ClubTeam varteks = null;
		try {
			varteks = new ClubTeam("VARTEKS", Formation.F352, 101);
		} catch (IllegalArgumentException e) {
			System.out.println("Greška: " + e.toString());
			System.out.println("Oporavak od pogreške...");
			varteks = new ClubTeam("VARTEKS", Formation.F352, 75);
		}
		System.out.printf("Naziv: %s, reputacija: %d, formacija: %s",
				varteks.getName(),
				varteks.getReputation(),
				varteks.getFormation());
	}
}
