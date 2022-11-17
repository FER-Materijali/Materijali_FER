import java.util.*;
import java.io.*;

public class automat {

	static ArrayList<String> SvaStanja;// ama bas sva stanja koja ima def
										// automat
	static String pocStanje;// ono jedno stanje koje je pocetno
	static ArrayList<String> Abeceda;// lista znakova abecede
	static ArrayList<String> PrihvStanja;// sve kaze
	//nepotrebno - static ArrayList<String> Prijelazi;
	static ArrayList<String> StaraStanja;// staro stanje u tablici prijelaza
	static ArrayList<String> NovaStanja;// stanje u koje se treba preci u
										// tablici prijelaza
	static ArrayList<String> ZaUlZnak;// znakovi za koje dolazi do prijelaza u
										// tablici
	static ArrayList<String> UlazniNizovi = new ArrayList<String>();;// lista
																		// nizova
																		// ulaznih
																		// znakova
	static String buff;// buffer koji ce pomagati pri splitevima
	static ArrayList<String> trenStanje;
	static ArrayList<String> slijedStanje;
	static ArrayList<String> izlazniNiz = new ArrayList<String>();

	public static void main(String[] args) {

		try {
			BufferedReader reader = new BufferedReader(new FileReader(
					"automat1.txt"));
			ReadMe(reader);
			reader.close();
		} catch (Exception a) {
			System.out.println("No file to read!");
		}

		InTheSimulation();

	}

	public static void Eprijelazi() {
		int index = 0;

		/**
		 * ovdje ne valja uvjet !slijedStanje.contains....
		 * moraš razdijeliti nova stanja tak da sa svakim znakom možeš provjeriti 
		 * jer u novom stanju može biti više znakova npr: s2,p5, a onda provjera
		 * baš nebude korektna jer ako bi provjeravao p5 i nova stanja, onda bi 
		 * on reko da je različito, a ako bi ih podjelio onda bi imao s2 i p5 zasebno
		 * pa bi p5 s kojim provjeravaš odjebao s2, ali bi skužio da je jednak ko i 
		 * p5 iz novih stanja
		 * 
		 * kak to riještit - radi if bez tog uvjeta i za svaki takav if koji zadovolji
		 * samo prva dva uvjeta reci da unutar toga if-a djeliš novaStanja po ,
		 * i baci ih u neko polje i onda for petlja po tom polju (dakle, za svako
		 * novo stanje) unutar koje provjeravaš ovaj 3. uvjet koji je tebi sad unutar
		 * (naravno, moraš ga malo modificirati) i ako je to ispunjeno, onda taj znak
		 * (iz polja stringova u kojem su ti nova stanja) dodaš u listu
		 */
		for (String s1 : trenStanje) {
			for (String s2 : StaraStanja) {
				if (s1.equals(s2) && ZaUlZnak.get(index) == "$"
						&& !slijedStanje.contains(NovaStanja.get(index)))
					slijedStanje.add(NovaStanja.get(index));// trenutno stanje
															// jednako onome u
															// listi gdje je
															// epsilon prijelaz
				index++;
			}
			index = 0;
		}

	}

	public static void OdrediNovaStanja(String str) {
		int index = 0;
		boolean nasaoPrijelaz = false;
		for (String s1 : trenStanje) {
			nasaoPrijelaz = false;
			for (int i = 0; i < StaraStanja.size(); i++) {
				/**
				 * NE jednako nad stringovima...postoji metoda equals, pogledaj u metodi
				 * za određianje e-prijelaza
				 * 
				 * Također, moraš djeliti novaStanja...
				 */
				if (StaraStanja.get(i) == s1 && ZaUlZnak.get(i) == str
						&& !slijedStanje.contains(NovaStanja.get(i))) {
					slijedStanje.add(NovaStanja.get(i));
					nasaoPrijelaz = true;
				}
				if (nasaoPrijelaz == false && !slijedStanje.contains("#"))
					slijedStanje.add("#"); // ako nije bilo definiranih
											// prijelaza, onda se prelazi na
											// prazni niz

				slijedStanje.add(NovaStanja.get(index));// trenutno stanje
														// jednako onome u listi
														// gdje je epsilon
														// prijelaz
				index++;
			}
			index = 0;
		}

	}

	public static void Ispis() {// sortira izlazni niz i ispisuje ga
		Collections.sort(izlazniNiz);
		for (int i = 0; i < izlazniNiz.size(); i++) {
			System.out.print(izlazniNiz.get(i));
			if (!(i + 1 == izlazniNiz.size()))
				System.out.print("|");
		}
		System.out.println(""); /**
		 								može bez "" u zagradama*/

	}

	public static void Reset() {// brise sve liste stanja i priprema za novi
								// ulazni niz
		//int size = trenStanje.size();
//		for (int i = 0; i < size; i++)
//			trenStanje.remove(i);
		/**
		 * ako radiš ovo gore, i postaje veći, veličina liste se smanjuje
		 * i dolazi do indexOutOfBounds iznimke jer ne mjenjaš size nego je isti
		 * ko i za punu listu
		 * Ako bi htio tako raditi, onda bi za svaku iteraciju morao računati novi
		 * size....ugl, ova funkcija radi taj posao
		 */
		trenStanje.clear();
		
		//size = slijedStanje.size();
//		for (int i = 0; i < size; i++)
//			slijedStanje.remove(i);
		
		slijedStanje.clear();
		
		//size = izlazniNiz.size();
//		for (int i = 0; i < size; i++)
//			izlazniNiz.remove(i);
		
		izlazniNiz.clear();
	}

	public static void InTheSimulation() {

		/**
		 * ne treba ti arrayList naprijed jer ih ti onda ponovo deklariraš i 
	 	 * to ti poništi one globalne koje si napravio
		 */
		trenStanje = new ArrayList<String>();
		slijedStanje = new ArrayList<String>();

		for (String s : UlazniNizovi) {

			trenStanje.add(pocStanje);
			// odredi epsilon prijelaze za poc stanje
			// Stringbuilder i collection.sort i stvara se string za ispis

			String[] ulazniZnakovi = s.split(",");
			for (String str : ulazniZnakovi) {
				Eprijelazi();
				/**
				 * Odredio su e-prijelaze, ali ih nisi ispisao. Moraš ih tu ispisati.
				 */
				OdrediNovaStanja(str);
				/**
				 * I tu sad moraš odrediti nove e-prijalze za stanja koja si dodao
				 * u trenutna stanja ovom funkcijom.
				 */

				for (int i = 0; i < trenStanje.size(); i++) {
					if (!izlazniNiz.contains(trenStanje.get(i)))
						izlazniNiz.add(trenStanje.get(i));
				}

//				for (int i = 0; i < trenStanje.size(); i++)
//					// brisem trenutna stanja
//					trenStanje.remove(i);
				trenStanje.clear(); /** isto ko i prije*/
				for (int i = 0; i < slijedStanje.size(); i++) {// slijedeca
																// stanja idu u
																// trenutna
					trenStanje.add(slijedStanje.get(i));
				}

//				for (int i = 0; i < slijedStanje.size(); i++)
//					// brisem slijedeca stanja
//					slijedStanje.remove(i);
				slijedStanje.clear(); /** i opet...:) */
				// �itaj znak 'str' i odredi slijede�a stanja
				// epsilon prijelazi za slijede�e stanje

			}
			Ispis();
			Reset();

		}

		// trenstanje=slijedstanje
		// slijede�a se prazne
		// prebacujem trenutna stanja u ispis, ako ve� tamo nisu

	}

	public static void ReadMe(BufferedReader reader) {
		String[] buff1 = new String[2];
		String[] buff2 = new String[2];

		try {

			// UlazniZnakovi = new ArrayList<String>();//Ucitavaju se ulazni
			// nizovi koji se moraju podijelit na znakove
			UlazniNizovi = new ArrayList<String>();
			for (String buff : reader.readLine().split("\\|"))
				UlazniNizovi.add(buff);

			SvaStanja = new ArrayList<String>();// Sva stanja
			for (String buff : reader.readLine().split(","))
				SvaStanja.add(buff);

			Abeceda = new ArrayList<String>();// Abeceda, zasto? - for the glory
												// of satan!!!
			for (String buff : reader.readLine().split(","))
				Abeceda.add(buff);

			PrihvStanja = new ArrayList<String>();// Prihvatljiva stanja
			for (String buff : reader.readLine().split(","))
				PrihvStanja.add(buff);

			pocStanje = reader.readLine();// pocetno stanje... samo je jedno,
											// ali vrijedno

			StaraStanja = new ArrayList<String>();
			ZaUlZnak = new ArrayList<String>();
			NovaStanja = new ArrayList<String>();
			try {
				while ((buff = reader.readLine()) != null) {// u while-u se sve
															// strga!
					if (buff.isEmpty())
						break;
					buff1 = buff.split("->");
					buff2 = buff1[0].split(",");
					StaraStanja.add(buff2[0]);
					ZaUlZnak.add(buff2[1]);
					NovaStanja.add(buff1[1]);
				}
			} catch (Exception c) {
				System.out.println("Exception 3!");
			}

		} catch (Exception b) {
			System.out.println("Exception 2!");
		}
	}

}
