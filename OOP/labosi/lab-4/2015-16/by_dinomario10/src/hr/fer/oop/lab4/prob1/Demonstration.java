package hr.fer.oop.lab4.prob1;

/**
 * Demonstrates the first problem by using classes Person, Coach and
 * FootballPlayer and enumerations Formation and PlayingPosition.
 * 
 * @author OOP ekipa
 * @author dinomario10
 */
public class Demonstration {

	public static void main(String[] args) {

		System.out.println("Stvaranje novog igrača...");
		FootballPlayer pikso = null;
		try {
			pikso = new FootballPlayer("Pikso", "Croatia", 67, -1, PlayingPosition.FW);
		} catch (IllegalArgumentException e) {
			System.out.println("Greška: " + e.toString() + "\nOporavak od pogreške..");
			pikso = new FootballPlayer("Pikso", "Croatia", 77, 85, PlayingPosition.FW);
		}

		System.out.println("Stvaranje novog trenera...");
		Coach klopp = null;
		try {
			klopp = new Coach(null, "Germany", 99, 85, Formation.F442);
		} catch (IllegalArgumentException e) {
			System.out.println("Greška: " + e.toString() + "\nOporavak od pogreške..");
			klopp = new Coach("Klopp", "Germany", 99, 85, Formation.F442);
		}

		Person[] persons = { pikso, klopp };
		System.out.println("Country, Name, Emotion");
		System.out.println("----------------------");
		for (Person person : persons) {
			System.out.println(person.getCountry() + ", " + person.getName() + ", " + person.getEmotion());
		}

		{
			System.out.printf("%nTesting hashCode and equals...%n");
			System.out.println("Pikso: " + pikso.hashCode());
			System.out.println("Klopp: " + klopp.hashCode());
			FootballPlayer tester = new FootballPlayer("Klopp", "Germany", 99, 100, PlayingPosition.GK);
			System.out.println("Tester: " + tester.hashCode());
			System.out.println("Pikso equals Klopp? " + pikso.equals(klopp));
			System.out.println("Tester equals Klopp? " + tester.equals(klopp));
		}
	}
}
