import java.util.*;
import java.io.*;

/** Simulator potisnog automata
 * rezultat na SPRUT-u 20/25.
 * Greske su u zasebnom fajlu.
 *
 */

public class SimPa {
	private static List<String> ulazniNizovi = new ArrayList<String>();
	private static List<String> stanja = new ArrayList<String>();
	private static List<String> abeceda = new ArrayList<String>();
	private static List<String> znakoviStoga = new ArrayList<String>();
	private static List<String> prihvatljivaStanja = new ArrayList<String>();
	private static String pocetnoStanje = "";
	private static String pocetniZnakStoga = "";
	private static Map<String,String> funkcijaPrijelaza = new HashMap<String,String>();
	
	private static Stack<String> stog = new Stack<String>();

	public static void main(String[] args) throws FileNotFoundException, IOException {
		Scanner input = new Scanner(System.in);
			
		String buff;
		String[] buffer;
		
		//ucitavanje ulaznih nizova
		buffer = input.nextLine().split("\\|");
		for(String s : buffer) 
			ulazniNizovi.add(s);
			
		//ucitavanje stanja, abecede, znakova stoga i prihvatljivih stanja
		for(int i = 0; i < 4; i++) {
			buff = input.nextLine();
			buffer = buff.split(",");
			switch(i) {
				case 0 :
					for(String s : buffer) 
						stanja.add(s);
					break;
				case 1 :
					for(String s : buffer) 
						abeceda.add(s);
					break;
				case 2 :
					for(String s : buffer) 
						znakoviStoga.add(s);
					break;
				case 3 :
					for(String s : buffer)
						prihvatljivaStanja.add(s);
					break;
			}
		}
		pocetnoStanje = input.nextLine();
		pocetniZnakStoga = input.nextLine();
		
		stog.push(pocetniZnakStoga);
		
		//ucitavanje prijelaza
		while(input.hasNextLine()) {
			buff = input.nextLine();
			if(buff.isEmpty()) break;
			String[] delta = buff.split("->");
			funkcijaPrijelaza.put(delta[0], delta[1]);
		}
		input.close();
		prijelazi();
	}
	
	private static String tmpTrenutnoStanje;
	private static boolean prihvatljivoStanje;
	private static boolean fail;
	private static String[] prijelaz = new String[2];
	private static String zaIspis;
	private static String tmpProcitaniZnak1;
	private static String[] prijelaz1 = new String[2];
	
	private static void prijelazi() throws EmptyStackException, FileNotFoundException, UnsupportedEncodingException{		
		prihvatljivoStanje = false;
		fail = false;
		
		//za svaki ulazni niz ...
		for(String s : ulazniNizovi) {
			stog.clear();
			stog.push(pocetniZnakStoga);
			tmpTrenutnoStanje = pocetnoStanje;
			zaIspis = pocetnoStanje + "#" + stog.peek() + "|";
			String[] s1 = s.split(",");
			
			//za svaki znak iz ulaznog niza ...
			for(String tmpProcitaniZnak : s1) {
				prihvatljivoStanje = false;
				tmpProcitaniZnak1 = tmpProcitaniZnak;
				//izracunaj epsilon prijelaz
				try {
					odrediPrijelaz("epsilon");
				} catch(NullPointerException e) {					
				} catch(EmptyStackException m) {
					zaIspis = zaIspis +  tmpTrenutnoStanje + "#" + naStogu() + "|" + "fail|";
					fail = true;
					prihvatljivoStanje = false;
					break;
				}
				//izracunaj obican prijelaz
				try {
					odrediPrijelaz("obican");
				} catch (NullPointerException e23) {
					zaIspis += "fail|";
					prihvatljivoStanje = false;
					fail = true;
					break;
				} catch (EmptyStackException ss) {
					zaIspis = zaIspis +  tmpTrenutnoStanje + "#" + naStogu() + "|" + "fail|";
					fail = true;
					prihvatljivoStanje = false;
					break;
				}
			}

			boolean promjena = false;
			
			if(!prihvatljivoStanje)
					do {
						promjena = false;
						if(!stog.empty() && !fail) {
							try {
								odrediPrijelaz("zadnjiEpsilon");
								promjena = true;
							} catch (NullPointerException e1) {
								break;
							} catch (EmptyStackException ss) {
								fail = true;
								prihvatljivoStanje = false;
							}
						}
					} while (promjena);
			if(prihvatljivoStanje) {
				zaIspis += 1;
				System.out.println(zaIspis);
			} else {
				zaIspis += 0;
				System.out.println(zaIspis);
			}
		}		
	}
	
	public static void odrediPrijelaz(String argVrsta) throws NullPointerException, EmptyStackException {
		String[] pom = new String[2];

		//obican prijelaz
		if (argVrsta.equals("obican")) pom = funkcijaPrijelaza.get(tmpTrenutnoStanje + "," + tmpProcitaniZnak1 + "," + stog.peek()).split(",");
		else pom = funkcijaPrijelaza.get(tmpTrenutnoStanje + "," + "$" + "," + stog.peek()).split(",");

		
		if(prihvatljivaStanja.contains(pom[0])) prihvatljivoStanje = true;
		//ako na stog treba stavit znak
		if(!pom[1].equals("$")) {
			/*ako je zadnji element na stogu dio znakova koje bi trebalo staviti na stog
			 * makni zanji i stavi jedan po jedan obrnutim redom
			 */
			if(pom[1].contains(stog.peek()) || pom[1].equals(stog.peek())) {
				String[] tmp = pom[1].split(""); //provjeri!!!!
				if(!stog.empty()) stog.pop();
				for(int i = tmp.length - 1; i > 0; i--) stog.push(tmp[i]);	
			} else {
				stog.pop();
				String[] tmp = pom[1].split("");
				for(int i = tmp.length - 1; i > 0; i--) stog.push(tmp[i]);
			}
			zaIspis += pom[0] + "#" + naStogu() + "|";
			tmpTrenutnoStanje = pom[0];
		//ako treba maknut znak sa stoga
		} else {
			stog.pop();
			if(argVrsta.equals("obican") || argVrsta.equals("zadnjiEpsilon")) zaIspis += pom[0] + "#" + naStogu() + "|";
			tmpTrenutnoStanje = pom[0];
		}
		if(argVrsta.equals("zadnjiEpsilon"))prijelaz1 = pom.clone();
		else prijelaz = pom.clone();
	}
	
	/** Metoda pretvara elemente
	 * na stogu u string, ali 
	 * obrnutim redosljedom (potrebnim 
	 * za ispis)
	 * @return StringNaStogu - elementi stoga u stringu
	 */
	private static String naStogu() {
		String StringNaStogu = "";
		String pom = "";
		Stack<String> pomocni = new Stack<String>();
		while(!stog.empty()) {
			pom = stog.pop();
			StringNaStogu += pom;
			pomocni.push(pom);
		}
		while(!pomocni.empty()) stog.push(pomocni.pop());
		if(StringNaStogu.equals("")) StringNaStogu = "$";
		return StringNaStogu;
	}
}
