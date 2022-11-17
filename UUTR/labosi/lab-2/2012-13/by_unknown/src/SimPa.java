import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class SimPa {

	private static List<String> ulazniNizovi;
	private static List<String> skupSvihStanja;
	private static List<String> skupUlaznihZnakova;
	private static List<String> skupZnakovaStoga;
	private static List<String> skupPrihvatljivihStanja;
	private static String pocetnoStanje;
	private static String pocetniZnakStoga;

	private static List<String> stanjePrije;
	private static List<String> citaniZnak;
	private static List<String> citaniZnakStoga;
	private static List<String> novoStanje;
	private static List<String> novoStanjeStoga;

	private static List<String> stog;
	
	private static StringBuilder build;

	private static String trenutnoStanje;

	public static void main(String[] args) throws IOException {

//		Scanner reader = new Scanner(new InputStreamReader(new FileInputStream(
//				new File("C:/Users/Mini Sven/Desktop" +
//						"/utr/test25/test.in")), "UTF-8"));
		Scanner reader = new Scanner(System.in, "UTF-8");
		ulazniNizovi = new ArrayList<String>();
		for (String s : reader.nextLine().trim().split("\\|")) {
			ulazniNizovi.add(s);
		}

		skupSvihStanja = new ArrayList<String>();
		for (String s : reader.nextLine().trim().split(",")) {
			skupSvihStanja.add(s);
		}

		skupUlaznihZnakova = new ArrayList<String>();
		for (String s : reader.nextLine().trim().split(",")) {
			skupUlaznihZnakova.add(s);
		}

		skupZnakovaStoga = new ArrayList<String>();
		for (String s : reader.nextLine().trim().split(",")) {
			skupZnakovaStoga.add(s);
		}

		skupPrihvatljivihStanja = new ArrayList<String>();
		for (String s : reader.nextLine().trim().split(",")) {
			skupPrihvatljivihStanja.add(s);
		}

		pocetnoStanje = reader.nextLine().trim();
		pocetniZnakStoga = reader.nextLine().trim();

		String temp = null;
		stanjePrije = new ArrayList<String>();
		citaniZnak = new ArrayList<String>();
		citaniZnakStoga = new ArrayList<String>();
		novoStanje = new ArrayList<String>();
		novoStanjeStoga = new ArrayList<String>();

		while (reader.hasNextLine()) {
			temp = reader.nextLine().trim();
			if (temp.isEmpty() || temp == null) {
				break;
			}
			String[] prijelaz = temp.split("->");
			String[] ulaz = prijelaz[0].trim().split(",");
			stanjePrije.add(ulaz[0].trim());
			citaniZnak.add(ulaz[1].trim());
			citaniZnakStoga.add(ulaz[2].trim());
			String[] izlaz = prijelaz[1].trim().split(",");
			novoStanje.add(izlaz[0].trim());
			novoStanjeStoga.add(izlaz[1].trim());

		}
		reader.close();

		for (String ulaz : ulazniNizovi) {
			
			build = new StringBuilder();
			boolean fail = false;
			trenutnoStanje = pocetnoStanje;
			stog = new ArrayList<String>();
			stog.add(pocetniZnakStoga);
			build.append(trenutnoStanje).append("#").append(stog.get(0));

			String[] znakovi = ulaz.split(",");
			int duljina = znakovi.length;
			for (int i = 0; i < duljina; i++) {
				if (!odrediPrijelaz(znakovi[i])) {
					if(!odrediEpsilonPrijelaze()) {
						build.append("|fail");
						fail = true;
						break;
					} else {
						if(!odrediPrijelaz(znakovi[i])) {
							build.append("|fail");
							fail = true;
							break;
						}
					}
				} 
				build.append("|").append(trenutnoStanje).append("#");
				int duljina2 = stog.size();
				for(int j=duljina2-1; j>=0; j--) {
					build.append(stog.get(j));
				}
			}
			if(fail) {
				build.append("|0");
			}
			else if (skupPrihvatljivihStanja.contains(trenutnoStanje)) {
				build.append("|1");
			} else {
				if(!odrediEpsilonPrijelaze()) {
					build.append("|0");
				} else {
					if(skupPrihvatljivihStanja.contains(trenutnoStanje)) {
						build.append("|1");
					} else {
						build.append("|0");
					}
				}
			}
			System.out.println(build.toString());
		}
	}

	private static boolean odrediEpsilonPrijelaze() {
		boolean imaPromjene = true;
		short brojac = 0;
		while (imaPromjene && !stog.isEmpty()) {
			imaPromjene = false;
			String stanjeNaStogu = stog.get(stog.size()-1);
			int duljinaStarihStanja = stanjePrije.size();
			
			for (int i = 0; i < duljinaStarihStanja; i++) {
				if (trenutnoStanje.equals(stanjePrije.get(i))
						&& citaniZnak.get(i).equals("$")
						&& stanjeNaStogu.equals(citaniZnakStoga.get(i))) {
					trenutnoStanje = novoStanje.get(i);
					String novoNaStogu = novoStanjeStoga.get(i);
					stog.remove(stog.size() - 1);
					if (novoNaStogu.length() == 1) {
						if (!novoNaStogu.equals("$")) {
							stog.add(String.valueOf(novoNaStogu.charAt(0)));
						}
					} else {
						int size = novoNaStogu.length();
						for(int j = size-1; j >=0; j--) {
							stog.add(String.valueOf(novoNaStogu.charAt(j)));
						}
					}
				build.append("|"+trenutnoStanje).append("#");
				if(stog.isEmpty()) {
					build.append("$");
				} else {
					int size = stog.size();
					for(int j=size - 1; j >= 0; j--) {
						build.append(stog.get(j));
					}
				}
				imaPromjene = true;
				brojac++;
				}
			}
		}
		return brojac > 0 ? true : false;
	}

	private static boolean odrediPrijelaz(String string) {
		if(stog.isEmpty()) return false;
		String stanjeNaStogu = stog.get(stog.size()-1).trim();
		int duljinaStarihStanja = stanjePrije.size();
		for (int i = 0; i < duljinaStarihStanja; i++) {
			if (trenutnoStanje.equals(stanjePrije.get(i).trim()) 
					&& string.equals(citaniZnak.get(i))
					&& stanjeNaStogu.equals(citaniZnakStoga.get(i))) {
				trenutnoStanje = novoStanje.get(i);
				String novoNaStogu = novoStanjeStoga.get(i);
				stog.remove(stog.size() - 1);
				if (novoNaStogu.length() == 1) {
					if (!novoNaStogu.equals("$")) {
						stog.add(String.valueOf(novoNaStogu.charAt(0)));
					}
				} else {
					int size = novoNaStogu.length();
					for(int j = size-1; j >=0; j--) {
						stog.add(String.valueOf(novoNaStogu.charAt(j)));
					}
				}
				return true;
			}
		}
		return false;
	}

}
