import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class SimEnka {

	//deklaracija globalnih varijabli u koje će se učitavati pojedini stringovi
	//učitava se sve, skup stanja i prihvatljiva stanja nisu potrebna
	private static List<String> ulazniNiz; //ulazni niz znakova (1.redak)
	private static List<String> skupSvihStanja; //Q (2.redak)
	private static List<String> skupUlaznihZnakova; //sigma - skup mogućnih znakova na ulazu (3.redak)
	private static List<String> prihvatljivaStanja; //skup prihvatljivih stanja (4.redak), nebitno
	private static String pocetnoStanje; 
	// neka je definiran prijelaz s3,4->s5,s6
	private static List<String> stanjePrije;//s3
	private static List<String> citaniZnak;//4
	private static List<String> novoStanje;//s5,s6
	private static List<String> trenutnaStanja; //skup trenutnih stanja
	private static List<String> tempTrenutnaStanja; //pomoćni skup trenutnih stanja koji koristim kod određivanja novih stanja

	public static void main(String[] args) {
		
		Scanner reader = new Scanner (System.in, "UTF-8"); //čitanje iz konzole
		
		//ubacivanje svih ulaznih nizova u listu
		ulazniNiz = new ArrayList<String>();
		for (String s : reader.nextLine().split("\\|")) {
			ulazniNiz.add(s);
		}
		
		//ubacivanje skupa svih stanja u listu
		skupSvihStanja = new ArrayList<String>();
		for (String s : reader.nextLine().split(",")) {
			skupSvihStanja.add(s);
		}
		
		//ubacivanje skupa ulaznih znakova u abecedu
		skupUlaznihZnakova = new ArrayList<String>();
		for (String s : reader.nextLine().split(",")) {
			skupUlaznihZnakova.add(s);
		}
		
		//ubacivanje prihvatljivih stanja u listu
		prihvatljivaStanja = new ArrayList<String>();
		for (String s : reader.nextLine().split(",")) {
			prihvatljivaStanja.add(s);
		}
		//ubacivanje početnog stanja u varijablu
		pocetnoStanje = reader.nextLine();

		//inicijalizacija varijabli potrebnih za spremanje stringova
		String temp = null;
		stanjePrije = new ArrayList<String>();
		citaniZnak = new ArrayList<String>();
		novoStanje = new ArrayList<String>();
		
		//čita prijelaze tako dugo dok ih ima
		while (reader.hasNextLine()) {
			temp = reader.nextLine();
			if (temp.isEmpty())
				break;
			//podjela pročitanog stringa na dijelove koji se ubacuju u odgovarajuće liste
			String[] prijelazNovoStanje = temp.split("->");
			String[] staroStanjeNoviZnak = prijelazNovoStanje[0].split(",");
			stanjePrije.add(staroStanjeNoviZnak[0]);
			citaniZnak.add(staroStanjeNoviZnak[1]);
			novoStanje.add(prijelazNovoStanje[1]);
		}
		reader.close();
		//čitanje ulaznog niza tako da se čita niz po niz (djelovi odvojeni |)
		StringBuilder build = null;
		for (String s : ulazniNiz) {

			trenutnaStanja = new ArrayList<String>();
			trenutnaStanja.add(pocetnoStanje);

			odrediEpsilonPrijelaze();
			//Sortiranje kako bi se zadržao poredak (abecedni)
			Collections.sort(trenutnaStanja);
			build = new StringBuilder();
			//ispis trenutnih stanja
			if(trenutnaStanja.size() == 1 && trenutnaStanja.get(0).equals("#")) {
				build.append("#");
			} else {
				for (String str : trenutnaStanja) {
					if(!str.equals("#")) {
						build.append(str);
						build.append(",");
					}
				}
			}
			//birisanje zadnjeg zareza
			build.deleteCharAt(build.length() - 1);
			build.append("|");

			String[] ulaz = s.split(",");
			//čitanje ulaznih znakova
			for (String in : ulaz) {
				odrediSlijedecaStanja(in);
				odrediEpsilonPrijelaze();
				Collections.sort(trenutnaStanja);
				//ispis novih stanja
				if(trenutnaStanja.size() == 1 && trenutnaStanja.get(0) == "#") {
					build.append("#");
				} else {
					for (String str : trenutnaStanja) {
						if(!str.equals("#")) {
							build.append(str);
							build.append(",");
						}
					}
				}
				//provjera jesmo li išta dodali pa ako nismo stavljamo #
				if (build.charAt(build.length() - 1) == '|') {
					build.append("#");
				} else {
					//ako jesmo, mičemo zarez
					build.deleteCharAt(build.length() - 1);
				}
				build.append("|");
			}
			//mičemo zadnji pipe (|)
			build.deleteCharAt(build.length() - 1);
			System.out.println(build.toString());
		}
		
	}

	private static void odrediEpsilonPrijelaze() {
		boolean imaPromjene = true;
		while (imaPromjene) {
			imaPromjene = false; //bubbleSortLike variable
			int sizeStarihStanja = stanjePrije.size();
			int sizeTrenutnihStanja = trenutnaStanja.size();
			for (int i = 0; i < sizeTrenutnihStanja; i++) {
				for (int j = 0; j < sizeStarihStanja; j++) {
					if (citaniZnak.get(j).equals("$")
							&& stanjePrije.get(j).equals(trenutnaStanja.get(i))) {
						String[] prijelazi = novoStanje.get(j).split(",");
						for (String s : prijelazi) {
							//Obavezna provjera postoji li to što želimo dodati u listi da se ne bi 
							//zavrtili u inf. loop-u
							if (!trenutnaStanja.contains(s)) {
								trenutnaStanja.add(s);
								imaPromjene = true;
							}
						}
					}
				}
			}
		}
	}

	private static void odrediSlijedecaStanja(String ulaz) {
		int sizeTrenutnihStanja = trenutnaStanja.size();
		int sizeStarihStanja = stanjePrije.size();
		tempTrenutnaStanja = new ArrayList<String>();
		for (int i = 0; i < sizeTrenutnihStanja; i++) {
			for (int j = 0; j < sizeStarihStanja; j++) {
				if (citaniZnak.get(j).equals(ulaz)
						&& stanjePrije.get(j).equals(trenutnaStanja.get(i))) {
					String[] prijelazi = novoStanje.get(j).split(",");
					for (String s : prijelazi) {
						//također, provjera...
						if (!tempTrenutnaStanja.contains(s)) {
							tempTrenutnaStanja.add(s);
						}
					}
				}
			}
		}
		trenutnaStanja.clear();
		trenutnaStanja.addAll(tempTrenutnaStanja);
	}
}
