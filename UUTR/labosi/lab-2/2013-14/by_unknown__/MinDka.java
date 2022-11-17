import java.util.*;
import java.io.*;

/** Minimizator DKA
 * rezultati na SPRUT-u 14/14
 *
 */

public class MinDka {
	
	private static List<String>	stanja = new ArrayList<String>();	
	private static List<String> abeceda	= new ArrayList<String>();
	private static List<String>	prihvatljivaStanja = new ArrayList<String>();
	private static String pocetnoStanje;
	private static List<String> prethodnoStanje	= new ArrayList<String>();
	private static List<String>	procitaniZnak = new ArrayList<String>();
	private static List<String>	sljedeceStanje = new ArrayList<String>();
	
	private static List<String>	novaStanja = new ArrayList<String>();
	private static List<String>	novaPrihvatljivaStanja = new ArrayList<String>();
	private static List<String>	novoPrethodnoStanje = new ArrayList<String>();
	private static List<String>	noviProcitaniZnak = new ArrayList<String>();
	private static List<String>	novoSljedeceStanje = new ArrayList<String>();
	private static int brZnakova;
	
	private static Map<String, Boolean> razlicitaStanja = new HashMap<String,Boolean>();
	
	public static void main (String[] args) throws FileNotFoundException, IOException {
		Scanner fileIn = new Scanner(System.in);

		String buff;
		String[] buffer;
		
		//ucitavanje stanja, abecede, i prihvatljivih stanja
		for(int i = 0; i < 3; i++) {
			buff = fileIn.nextLine();
			buffer = buff.split(",");
			for(String s : buffer) {
				switch(i) {
					case 0:		stanja.add(s);
								break;
					case 1:		abeceda.add(s);
								break;
					case 2:		prihvatljivaStanja.add(s);
								break;
				}
			}
		}
		pocetnoStanje = fileIn.nextLine();
		
		//ucitavanje prijelaza
		while(fileIn.hasNextLine()) {
			buff = fileIn.nextLine();
			if(buff.isEmpty()) break;
			String[] delta = buff.split("->");
			String[] deltaArgs = delta[0].split(",");
			prethodnoStanje.add(deltaArgs[0]);
			procitaniZnak.add(deltaArgs[1]);
			sljedeceStanje.add(delta[1]);
		}	
		obrisiNedohvatljivaStanja();
		brZnakova = abeceda.size();
		
		fileIn.close();
		
		/*	inicijaliziraj map razlicita stanja;
		*	stavi sve kombinacije stanja iz crteza (tablica - 3. algoritam iz knjige)
		*	i postavi ih na false (bez krizica)
		*/
		for(int i = 0; i < prethodnoStanje.size() - 1; i+=brZnakova) {
			for(int j = brZnakova + i; j < prethodnoStanje.size(); j+=brZnakova) {
				String skupStanja = prethodnoStanje.get(i) + "," + prethodnoStanje.get(j);
				razlicitaStanja.put(skupStanja, false);
			}
		}
		
		odrediRazlicitaStanja();
		stvoriMinDka();
	}
	
/** Metoda brise nedohvatljiva stanja stvarajuci
	 *  listu prihvatljivih stanja, odnosno onih do kojih
	 *  se moze doci iz pocetnog stanja, te na temelju
	 *  usporedbe s originalnom listom stanja stvara novu
	 *  listu nedohvatljivih stanja. Pomocu liste nedohvatljivih
	 *  stanja brisu se unosi iz lista koje definiraju prijelaze
	 *  automata (prthodnoStanje, procitaniZnak, sljedeceStanje) 
	 *  i na kraju mijenja originalnu listu stanja.
	 * 
	 */
	private static void obrisiNedohvatljivaStanja() {
		List<String> dohvatljivaStanja = new ArrayList<String>();
		List<String> nedohvatljivaStanja = new ArrayList<String>();
		dohvatljivaStanja.add(pocetnoStanje);
		
		//stvori listu dohvatljivih stanja - onih do kojih se moze doci iz pocetnog
		for(int i = 0; i < dohvatljivaStanja.size(); i++) {
			for(int j = 0; j < prethodnoStanje.size(); j++) {
				for(String s : abeceda) {
					if(prethodnoStanje.get(j).equals(dohvatljivaStanja.get(i)) && procitaniZnak.get(j).equals(s)) {
						if(!dohvatljivaStanja.contains(sljedeceStanje.get(j))) dohvatljivaStanja.add(sljedeceStanje.get(j));
					}
				}
			}
		}
		
		Collections.sort(dohvatljivaStanja);
		for(String s : stanja) {
			if(!dohvatljivaStanja.contains(s) && !nedohvatljivaStanja.contains(s)) nedohvatljivaStanja.add(s);
		}
		
		for(String s : nedohvatljivaStanja) {
			int i = prethodnoStanje.indexOf(s);
			for(int j = 0; j < abeceda.size(); j++) {
				prethodnoStanje.remove(i);
				procitaniZnak.remove(i);
				sljedeceStanje.remove(i);
			}
		}
		stanja.clear();
		for(String s : dohvatljivaStanja) stanja.add(s);
	}
	
	
	/**Metoda radi nad tablicom stanja (kao u knjizi - 3. algoritam).
	 * {1. for petlja} Ako je u paru (p,q) jedno prihvatljivo, a drugo nije 
	 * [(p je prihvatljivo) XOR (q je prihvatljivo)] tada su stanja
	 * razlicita i stavlja se X, odnosno "true".
	 * 
	 * {2. for petlja} Za svaki par stanja (p,q), indeksi i,j te za
	 * svako slovo u abecedi pogledaj je li kucica [p,q] prazna, ako [delta(p,a),delta(q,a)]
	 * ima X, tada su stanja razlicita te je potrebno u kucicu [p,q] staviti X.
	 * i+=brZnakova -> usporedjuje razlicita stanja, a ona su udaljena za brZnakova 
	 * koji je definiran kao duljina liste "abeceda"		
	 * 
	 * @throws IndexOutOfBoundsException
	 */
	private static void odrediRazlicitaStanja() throws IndexOutOfBoundsException {

		for(int i = 0; i < prethodnoStanje.size() - 1; i+= brZnakova) {
			for(int j = brZnakova + i; j < prethodnoStanje.size(); j+=brZnakova) {
				if(stanja.contains(prethodnoStanje.get(j)) && stanja.contains(prethodnoStanje.get(i))) {//mozda ne treba
					if(prihvatljivaStanja.contains(prethodnoStanje.get(i)) ^ prihvatljivaStanja.contains(prethodnoStanje.get(j))) {
						String tmp = prethodnoStanje.get(i) + "," + prethodnoStanje.get(j); 
						razlicitaStanja.put(tmp, true);
					}
				}
			}
		}
		
		for(int i = 0; i < prethodnoStanje.size() - 1; i+=brZnakova) {
			for(int j = brZnakova + i; j < prethodnoStanje.size(); j+=brZnakova) {				
				if(stanja.contains(prethodnoStanje.get(j)) && stanja.contains(prethodnoStanje.get(i))) { 
					String tmp1 = prethodnoStanje.get(i) + "," + prethodnoStanje.get(j); 
					for(int k = 0; k < abeceda.size(); k++) {
						String tmp2;
						//IK - indeksi odnosno delta(stanje[i], znak[k]);
						String deltaIK = sljedeceStanje.get(i+k); 
						String deltaJK = sljedeceStanje.get(j+k);
						int usporedi = deltaIK.compareTo(deltaJK);
						if(usporedi < 0) tmp2 = deltaIK + "," + deltaJK;
						else tmp2 = deltaJK + "," + deltaIK;
						
						//ako je u tablici kucica (p,q) prazna, a (delta(p,a),delta(q,a)) ima X
						//u kucicu (p,q) stavi X
						if(usporedi != 0) {
							if(!razlicitaStanja.get(tmp1) && razlicitaStanja.get(tmp2)) {
								razlicitaStanja.put(tmp1, true);
							}
						}
					}
				}
			}
		}
	}
	
	/** Metoda stvara nove liste kojima se definira minimizirani automat.
	 * Na temelju tablice razlicitaStanja stvara listu novih stanja te uklanja 
	 * jednaka stanja. Stvara liste za definiciju automata (novoPrethodnoStanje,
	 * novoSljedeceStanje). Ako je potrebno mijenja pocetno stanje. Stanju
	 * koje se sastoji od skupa stanja ime zamjenjuje leksikografski najmanjim
	 * stanjem. Odredjuje nova prihvatljiva stanja i na kraju ispisuje automat
	 * na System.out.
	 * 
	 * @throws IndexOutOfBoundsException
	 * @throws IOException
	 */
	private static void stvoriMinDka() throws IndexOutOfBoundsException, IOException{
		boolean promjena = false;
		Set<String> tmpPrethSt = new TreeSet<String>();
		List<String> tmpList = new ArrayList<String>();
		String stringStanja = "";
		List<String> istovjetnaStanja = new ArrayList<String>();
		
		//u listu novih stanja dodaj nova (spojena) i eventualno stara (pojedinacna) stanja
		for(int i = 0; i < prethodnoStanje.size() - 1; i+=brZnakova) {
			if(!istovjetnaStanja.contains(prethodnoStanje.get(i))) {
				istovjetnaStanja.clear();
				for(int j = brZnakova + i; j < prethodnoStanje.size(); j+=brZnakova) {
					if(stanja.contains(prethodnoStanje.get(j)) && stanja.contains(prethodnoStanje.get(i))) { 
						String tmp = prethodnoStanje.get(i) + "," + prethodnoStanje.get(j);
						if(!razlicitaStanja.get(tmp)) {
							tmpPrethSt.add(prethodnoStanje.get(i));
							tmpPrethSt.add(prethodnoStanje.get(j));
							promjena = true;
						}
					}
				}
				//ako je stanje jedinstveno prethodna petlja ga nece ubaciti u listu
				if(!promjena) 	tmpPrethSt.add(prethodnoStanje.get(i));
				promjena = false;
				for(String s : tmpPrethSt) 	stringStanja = stringStanja + s + ",";
				//obrisi zadnji zarez
				if(stringStanja.length() > 0 && stringStanja.charAt(stringStanja.length()-1) == ',') stringStanja = stringStanja.substring(0, stringStanja.length() - 1);
				if(!novaStanja.contains(stringStanja))
					novaStanja.add(stringStanja);
				istovjetnaStanja.addAll(tmpPrethSt);
				tmpPrethSt.clear();
				stringStanja = "";
			}
		}
		//ukoliko automat ima samo jedno stanje			
		if(novaStanja.size() == 0) novaStanja.addAll(stanja);
		
		//ukloni nepotrebna stanja
		for(int i = 0; i < novaStanja.size(); i++) {
			String[] s = novaStanja.get(i).split(",");
			if(s.length > 1) {
				for(String s1 : s) {
					for(int k = i+1; k < novaStanja.size(); k++) {
						if(novaStanja.get(k).contains(s1)) {
							novaStanja.remove(novaStanja.get(k));
							k--;
						}
						
					}
				}
			}
		}
		
		
		/* stvori liste:
		 *  - novoPrethodnoStanje
		 *  - novoSljedeceStanje
		 */
		stringStanja = "";
		for(int i = 0; i < novaStanja.size(); i++) {
			for(int j = 0; j < abeceda.size(); j++) {
				String[] s = novaStanja.get(i).split(",");
				for(String s1 : s) {
					for(int k = 0; k < prethodnoStanje.size(); k++) {
						if(prethodnoStanje.get(k).equals(s1) && procitaniZnak.get(k).equals(abeceda.get(j))) 
							tmpList.add(sljedeceStanje.get(k));
					}
				}
				Collections.sort(tmpList);
				for(String s1 : tmpList) {
					stringStanja = stringStanja + s1 + ",";
				}
				if(stringStanja.length() > 0 && stringStanja.charAt(stringStanja.length()-1) == ',') stringStanja = stringStanja.substring(0, stringStanja.length() - 1);
				novoPrethodnoStanje.add(novaStanja.get(i));
				noviProcitaniZnak.add(abeceda.get(j));
				novoSljedeceStanje.add(stringStanja);
				stringStanja = "";
				tmpList.clear();
			}
		}		
		
		/*ukoliko je pocetno stanje jednako nekom drugom, a
		 *  leksikografski je iza njega, treba promijeniti
		 *  na jednako stanje koje je leksikografski
		 *  najmanje
		 */
		if(!novaStanja.contains(pocetnoStanje)){
			for(String s : novaStanja) {
				String[] tmpStanja = s.split(",");
				for(String s1 : tmpStanja) {
					if(pocetnoStanje.equals(s1)) pocetnoStanje = tmpStanja[0];
				}
			}
		}
		
		//ukloni sva nepotrebna imena stanja
		for(int i = 0; i < novoPrethodnoStanje.size(); i++) {
			String[] tmpPrethodnoStanje = novoPrethodnoStanje.get(i).split(",");
			String[] tmpSljedeceStanje = novoSljedeceStanje.get(i).split(",");
			
			/* ako je stanje jednako nekom drugom
			 * a leksikografski vece od njega, promijeni u
			 * leksikografski najmanje
			 */
			for(int z = 0; z < novaStanja.size(); z++) {
				if(novaStanja.get(z).contains(tmpSljedeceStanje[0])) {
					tmpSljedeceStanje = novaStanja.get(z).split(",");
				}
			}
			//stavi leksikografski najmanje stanje koje predstavlja skup jednakih stanja
			novoPrethodnoStanje.set(i, tmpPrethodnoStanje[0]);
			novoSljedeceStanje.set(i,tmpSljedeceStanje[0]);					
		}
		for(int i = 0; i < novaStanja.size(); i++) {
			String[] tmpStanja = novaStanja.get(i).split(",");	
			novaStanja.set(i, tmpStanja[0]);
		}
		
		Collections.sort(novaStanja);
		
		//odredi nova prihvatljiva stanja
		for(String s : novaStanja) {
			if(prihvatljivaStanja.contains(s)) novaPrihvatljivaStanja.add(s);
		}
		
		
		//ispis novog automata
		String listaZaIspis = "";
		//ispis skupa stanja, abecede, novih
		for(int i = 0; i < 4; i++) {
			switch (i) {
				case 0 :	for(String s : novaStanja) listaZaIspis = listaZaIspis + s + ",";
							break;
				case 1 :	for(String s : abeceda) listaZaIspis = listaZaIspis + s + ",";
							break;
				case 2 :	for(String s : novaPrihvatljivaStanja) listaZaIspis = listaZaIspis + s + ",";
							break;
				case 3 :	listaZaIspis = pocetnoStanje;
							break;
				default :	System.err.println("Dogodila se greska!");
							System.exit(0);
			}
			//obrisi zadnji zarez
			if(listaZaIspis.length() > 0 && listaZaIspis.charAt(listaZaIspis.length()-1) == ',') listaZaIspis = listaZaIspis.substring(0, listaZaIspis.length() - 1);
			System.out.println(listaZaIspis);
			listaZaIspis = "";
		}
		for(int i = 0; i < novoPrethodnoStanje.size(); i++) {
			listaZaIspis = novoPrethodnoStanje.get(i) + "," + noviProcitaniZnak.get(i) + "->" + novoSljedeceStanje.get(i);
			System.out.println(listaZaIspis);
			listaZaIspis = "";
		}		
	}
}
