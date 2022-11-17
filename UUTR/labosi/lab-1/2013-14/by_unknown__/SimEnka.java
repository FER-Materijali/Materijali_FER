import java.util.*;
import java.io.*;

/** Simulator epsilon-NKA.
 * rezultat na SPRUT-u 33/33
 *
 */

public class SimEnka {

	private static List<String> ulazniNiz = new ArrayList<String>();
	private static List<String> skupStanja = new ArrayList<String>();
	private static List<String> simboliAbecede = new ArrayList<String>();
	private static List<String> prihvatljivaStanja = new ArrayList<String>();
	private static String pocetnoStanje;

	private static List<String> prethodnaStanja = new ArrayList<String>();
	private static List<String> procitaniZnak = new ArrayList<String>();
	private static List<String> sljedecaStanja = new ArrayList<String>();
	
	private static String buff;

	
	
	public static void main(String[] args) throws IOException {		
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		
		String[] dijelovi;

		//ucitavanje postavki automata
		for(int i = 0; i < 4; i++) {
			buff = reader.readLine();
			if(i == 0) {
				dijelovi = buff.split("\\|");
				for(int j = 0; j < dijelovi.length; j++) 	ulazniNiz.add(dijelovi[j]);
			} else if(i != 0) {
				dijelovi = buff.split(",");
				if(i == 1) 
					for(int j = 0; j < dijelovi.length; j++) 	skupStanja.add(dijelovi[j]);
				else if(i == 2)
					for(int j = 0; j < dijelovi.length; j++) 	simboliAbecede.add(dijelovi[j]);
				else if(i == 3)
					for(int j = 0; j < dijelovi.length; j++) 	prihvatljivaStanja.add(dijelovi[j]);
			}
		}
		pocetnoStanje = reader.readLine();
		
		//ucitavanje prijelaza
		while((buff = reader.readLine()) != null) {
			if(buff.isEmpty()) break;
			String [] delta = buff.split("->");
			String [] deltaArgs = delta[0].split(",");
			prethodnaStanja.add(deltaArgs[0]);
			procitaniZnak.add(deltaArgs[1]);
			sljedecaStanja.add(delta[1]);
		}
	reader.close();
	obradiNiz();
	}

	
	/** Glavna metoda koja obradjuje niz
	 * 
	 * @throws IOException
	 */
	public static void obradiNiz() throws IOException {
		for(String tmp : ulazniNiz) {
			String[] niz  = tmp.split(",");
			ispisi(sljedecaStanja(niz));
		}
	}
	
	
	/** Metoda racuna sve prijelaze za zadani niz
	 * 
	 * @param niz koji dolazi na ulaz u automat
	 * @return sviPrijelazi - lista svih stanja u kojima se automat nasao za vrijeme obrade niza
	 */
	public static List<String> sljedecaStanja(String[] niz) {
		List<String> sviPrijelazi = new ArrayList<String>();
		List<String> tmpTrenutnaStanja = new ArrayList<String>();
		List<String> tmpSljedecaStanja = new ArrayList<String>(); 

		tmpTrenutnaStanja.add(pocetnoStanje);
		
		//u slucaju pogresno zadanog niza
		for(int i = 0; i < niz.length; i++) {
			if(!simboliAbecede.contains(niz[i])) {
				System.err.println("Znak " + niz[i] + " se ne nalazi u abecedi automata, ostali se zanemaruju.");
				return null;
			}
		}

		//zapisivanje prijelaza u sviPrijelazi
		for(int i = 0; i < niz.length; i++) {	
			epsilonPrijelazi(tmpTrenutnaStanja); //provjeri epsilon prijelaze
			
			//ako postoje prijelazi u prazan skup i neko drugo stanje, obrisi prijelaz u prazan skup
			if(tmpTrenutnaStanja.size() != 1 && tmpTrenutnaStanja.contains("#")) tmpTrenutnaStanja.remove("#");		
			for(int j = 0; j < tmpTrenutnaStanja.size(); j++) {														
				for(int k = 0; k < prethodnaStanja.size(); k++) {																			
					if(procitaniZnak.get(k).equals(niz[i])  && tmpTrenutnaStanja.get(j).equals(prethodnaStanja.get(k))) {
						String [] buf = sljedecaStanja.get(k).split(",");
						for (String s : buf) 
							if (!tmpSljedecaStanja.contains(s)) tmpSljedecaStanja.add(s);
					}
				}
			}
			epsilonPrijelazi(tmpSljedecaStanja);
			if(tmpSljedecaStanja.isEmpty()) tmpSljedecaStanja.add("#"); //ako nije bilo prijelaza, stavi prijelaz u prazan skup
			if(tmpSljedecaStanja.size() != 1 && tmpSljedecaStanja.contains("#")) tmpSljedecaStanja.remove("#");
			Collections.sort(tmpTrenutnaStanja);
			
			//dodavanje epsilon prijelaza u listu za ispis
			for(String s: tmpTrenutnaStanja) {
				if(!sviPrijelazi.contains(s)){
					sviPrijelazi.add(s);
					sviPrijelazi.add(",");
				}
			}	
			sviPrijelazi.set(sviPrijelazi.size() - 1, "|");
			tmpTrenutnaStanja.clear();
			tmpTrenutnaStanja.addAll(tmpSljedecaStanja);
			Collections.sort(tmpSljedecaStanja);
			
			//dodavanje svih ostalih prijelaza u listu za ispis
			for(String s: tmpSljedecaStanja) {
				sviPrijelazi.add(s);
				sviPrijelazi.add(",");
			}			
			sviPrijelazi.set(sviPrijelazi.size() - 1, "|");
			tmpSljedecaStanja.clear();
		}

		sviPrijelazi.remove(sviPrijelazi.size() - 1);
		return sviPrijelazi;
	}
	
	/** Metoda racuna epsilon prijelaze 
	 * koji se mogu dogoditi iz stanja  
	 * u kojemu se automat trenutno nasao,
	 * te ih upisuje u listu koju je dobila
	 * kao parametar.
	 * @param trenutnaStanja
	 */
	
	public static void epsilonPrijelazi(List<String> trenutnaStanja) {
		boolean epsilon = true;
	
		/*while sluzi "neprekidnom" provjeravanju epsilon
		prijelaza iz trenutnih stanja*/
		while(epsilon) {
			epsilon = false; //ako se ne dogodi niti jedan epsilon prijelaz, nemoj dalje provjeravati
			for(int i = 0; i < trenutnaStanja.size(); i++) {
				for(int j = 0; j < prethodnaStanja.size(); j++) {
					if(procitaniZnak.get(j).equals("$") && trenutnaStanja.get(i).equals(prethodnaStanja.get(j))) {
						String [] buf1 = sljedecaStanja.get(j).split(",");
						for (String s : buf1) 
							if (!trenutnaStanja.contains(s)){
								trenutnaStanja.add(s);
								epsilon = true; /*ako se dogodio epsilon prijelaz, prodji jos jednom kroz lisu
								 				i provjeri moguce dodatne epsilon prijelaze*/
												
							}
					}
				}
			}
		}	
	}
	
	
	/** Metoda koja na kraju obrade niza
	 * ispisuje sva stanja u kojima
	 * se automat nasao.
	 * @param stanja
	 * @throws IOException
	 */
	public static void ispisi(List<String> stanja) throws IOException  {

		String [] stanja1 = new String[stanja.size()];
		for(int i = 0; i < stanja.size(); i++) {
			stanja1[i] = stanja.get(i);
			
			System.out.printf(stanja1[i]);
		}
		
		System.out.println();
		
		}
	
}
