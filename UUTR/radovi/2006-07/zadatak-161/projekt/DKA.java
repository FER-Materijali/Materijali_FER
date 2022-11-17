package projekt;
import java.util.LinkedList;
import java.util.TreeSet;
import java.util.Set;

/** 
 * 
 * gl_niz1, gl_niz2 - lista indeksa stanja (npr. q1 = 1...)
 *
 */

public class DKA {

	private LinkedList<Podaci> stanje;
	private int broj_varijabli;
	private int ukupan_broj_stanja; //  q0...qn
	private LinkedList<Integer> gl_niz1, gl_niz2;
	
	private LinkedList<Integer> skup;
	
	private int sloz;
	private int broj_prolaza;
	
	public int citaj_broj_prolaza(){
		return broj_prolaza;
	}
	
	public int citaj_sloz(){
		return sloz;
	}
	public int citaj_ukbrst(){
		return ukupan_broj_stanja;
	}
	
	public int citaj_brvr(){
		return broj_varijabli;
	}
	
	public static class Podaci{
		private String[] prijelazi;
		private boolean prihvatljivost;// true = 1, false = 0
		private boolean dostupnost;
		
		public boolean provjera(){
			return this.dostupnost;
		}
		
		public Podaci(int br_var){
			prijelazi = new String[br_var];
			dostupnost = true;
		}
		
		public void ubaci_stanja(String[] p_stanja){
			
			
			if (p_stanja[p_stanja.length - 1].contentEquals("1"))
				prihvatljivost = true;
			else if (p_stanja[p_stanja.length - 1].contentEquals("0"))
				prihvatljivost = false;
			
			for (int i = 0; i < p_stanja.length - 2; i++){
				prijelazi[i] 
				          = p_stanja[i + 1];
			}
			
		}
		
		public void postavi_prijelaze(int[] indexi){
			for (int i = 0; i < indexi.length; i++){
				prijelazi[i] = new String("q"+indexi[i]);
			}
		}
		
		public void postavi_prijelaz(int index, int stanje){
			
			prijelazi[index] = new String("q"+stanje);
		}
		
		public String[] citaj_prijelaze(){
			return this.prijelazi;
		}
		
		public boolean citaj_prihvatljivost(){
			return this.prihvatljivost;
		}

		public void postavi_dostupnost(boolean vrijednost){
			this.dostupnost = vrijednost;
		}
	}
	
	
	
	public DKA (){
		stanje = new LinkedList<Podaci>();
		skup  = new LinkedList<Integer>();
		broj_varijabli = 0;
		ukupan_broj_stanja = 0;
		sloz = 0;
		broj_prolaza = 0;
	}
	
	
	public void upisi_broj_varijabli(int broj_varijabli2){
		broj_varijabli = broj_varijabli2;
	}
	
	public void upisi_ukupan_broj_stanja(int ukupan_broj_stanja2){
		ukupan_broj_stanja = ukupan_broj_stanja2;
	}
	
	public void ispisi_ukupan_broj_stanja(){
		System.out.println("ukupan broj stanja = " + ukupan_broj_stanja);
	}
	
	public void ispisi_broj_varijabli(){
		System.out.println("ukupan broj varijabli = " + broj_varijabli);
	}
	
	
	public void dodaj(Podaci elem){
		this.stanje.add(elem);
	}
	
	public Podaci dohvati(int i){
		return stanje.get(i);
	}
	
	public static int[] pretvori_u_brojeve(String[] niz_stringova){
		char[] niz_charova1;
		//LinkedList<Char> niz_charova2;
		int[] niz_brojeva = new int[niz_stringova.length];
		for (int i = 0; i < niz_stringova.length; i++){
			
			niz_charova1 = niz_stringova[i].toCharArray();
			niz_charova1[0] = '0';
			String string = new String(niz_charova1);
			niz_brojeva[i] = 
				Integer.parseInt(string);
		}
		return niz_brojeva;
	}
	
	/**
	 * funkcija za izbacivanje nedohvatljivih stanja
	 * stavlja indekse prijelaza (npr. q5 = 5...) u listu skup ako tog indeksa
	 * jos nema u listi
	 * nakon dodavanja svih prijelaza se provjerava koji indeksi stanja nisu 
	 * u listi, i kod tih se stavlja dostupnost na false
	 * 
	 * u slucaju kasnijeg koristenja te funkcije, lista skup se na kraju funkcije
	 * isprazni
	 *
	 */
	public void izbaci_nedohvatljiva_stanja(){
		Podaci dka_podaci;
		String[] prijelazi2;
		int[] indexi;
		skup.add(0);
		int i = 0, brojac = -1;
		boolean pom = true;
		
		while(pom){
			brojac++ ;
			dka_podaci = dohvati(i);
			prijelazi2 = dka_podaci.citaj_prijelaze();
			indexi = pretvori_u_brojeve(prijelazi2);
			for (int j = 0; j < indexi.length; j++){
				if (!skup.contains(indexi[j]))
						skup.add(indexi[j]);
			}
			if (brojac < skup.size()) i = skup.get(brojac);
			else pom = false;
		}
		
		for (int j = 0; j < ukupan_broj_stanja; j++){
			if (!skup.contains(j)){
				dka_podaci = dohvati(j);
				dka_podaci.postavi_dostupnost(false);
			}
		}
		skup.clear();
	}
	
	/**
	 * na poèetku se naprave dva niza, u koja se stavljaju indeksi 
	 * prihvatljivih ili neprihvatljivih stanja 
	 *
	 * podnizovi unutar ta 2 glavna niza se odvajaju sa "-1", i sa "-2" ako
	 * je novonastali podniz
	 * 
	 * 
	 */
	
	public void dijeli_po_podudarnosti(){
		LinkedList<Integer> novi_niz2 = new LinkedList<Integer>();
		LinkedList<Integer> novi_niz1 = new LinkedList<Integer>();
		LinkedList<Integer> niz1 = new LinkedList<Integer>();
		LinkedList<Integer> niz2 = new LinkedList<Integer>();
		Podaci dka_podaci;
		int elem1_pom, elem2_pom, elem1, elem2;
		niz1.add(-1);niz2.add(-1);
		
		for (int i = 0; i < ukupan_broj_stanja; i++){
			sloz++;
			dka_podaci = dohvati(i);
			
			if (dka_podaci.provjera()){	
				if (dka_podaci.citaj_prihvatljivost()) 
					niz1.add(i);
				else niz2.add(i);
			}
		}

		novi_niz1 = niz1;
		novi_niz2 = niz2;
		
		
		boolean gotov1 = false, gotov2 = false, pom = false;
		
		int brojac1 = 1, brojac2 = 1, gl_brojac1 = 1, gl_brojac2 = 1;
		int pr = 0;
		int novi1 = gl_brojac1 +1, novi2 = gl_brojac2+1;
		boolean nije_gotovo = true;
		while(nije_gotovo){
			broj_prolaza++;
			sloz++;
			brojac1 = 1; 
			gl_brojac1 = 1; 
			novi1 = gl_brojac1 + 1;
			
			if (niz1.size() == 1) gotov1 = true;
			if (niz2.size() == 1) gotov2 = true;
			
			if (!gotov1){	// provjerava dal je prvi glavni niz veæ obraðen
				while (gl_brojac1 < novi1){
				sloz++;
				brojac1++;
				pom = false;
				elem1 = niz1.get(gl_brojac1);
				elem1_pom = niz1.get(brojac1);
				
				if ((elem1_pom != -1) && (elem1_pom != -2)){
					if (!provjera(elem1, elem1_pom, niz1, niz2)){
						novi_niz1 = dodaj_podesi(gl_brojac1, elem1_pom, niz1);
						pr++;
						brojac1--;
						}
					else pr++;
				}
				else {
						pom = true;
						gl_brojac1 = brojac1 + 1;
						brojac1++;
						novi1 = gl_brojac1 + 1;
					
				}//else
				if (brojac1 == (niz1.size()-1) ) gl_brojac1 = niz1.size()+2;
				if (pom && brojac1 >= niz1.size()) gl_brojac1 = niz1.size()+2;
			}//while petlja
			}//if
			
			

			gl_brojac2 = 1; 
			novi2 = gl_brojac2 + 1;
			brojac2 = 1; 
			
			if (!gotov2){	// provjerava dal je drugi glavni niz veæ obraðen
			while (gl_brojac2 < novi2){
				sloz++;
			brojac2++;
			elem2 = niz2.get(gl_brojac2);
			elem2_pom = niz2.get(brojac2);
			pom = false;
			
			if ((elem2_pom != -1) && (elem2_pom != -2)){
				if (!provjera(elem2, elem2_pom, niz1, niz2)){
					pr++;
					novi_niz2 = dodaj_podesi(gl_brojac2, elem2_pom, niz2);
					brojac2--;
				}
				else pr++;
			}
			else {
					pom = true;
				
					gl_brojac2 = brojac2 + 1;
					brojac2++;
					novi2 = gl_brojac2 + 1;
					
				}//else

			if (brojac2 == (niz2.size()-1)) {
				gl_brojac2 = niz2.size()+2;
			}
			if (pom && brojac2 >= niz2.size()) {
				gl_brojac2 = niz2.size()+2;
			}
			}//while
			}//if

			
			novi_niz1 = makni_markere(novi_niz1);//mice markere "-2"
			novi_niz2 = makni_markere(novi_niz2);//mice markere "-2"

			
			if (niz1.equals(novi_niz1)) {//provjerava dal je podjela na particije ostala
										 // ista za prvi glavni niz
				gotov1 = true; 
			}
			
			if (niz2.equals(novi_niz2)) {//provjerava dal je podjela na particije ostala
				 						 // ista za drugi glavni niz
				gotov2 = true;
			}
			if (gotov1 && gotov2) nije_gotovo = false;
			
			niz1 = novi_niz1;
			niz2 = novi_niz2;
			
			
		}//while
		
		
		gl_niz1 = niz1;
		gl_niz2 = niz2;
	}
	
	/**
	 * mice marker "-2" kod novonastalih podnizova
	 * @param niz - niz sa indeksima stanja
	 * @return niz bez markera "-2"
	 */
	public LinkedList<Integer> makni_markere(LinkedList<Integer> niz){
		LinkedList<Integer> pom_niz = new LinkedList<Integer>();
		
		for (int i = 0; i < niz.size(); i++){
			if (niz.get(i) == -2) pom_niz.add(-1);
			else pom_niz.add(niz.get(i));
		}
		return pom_niz;
	}
	
	/**
	 * funkcija podešava kopiju trenutno obraðivanog niza tako da stavlja na kraj trenutnog niza «-2», 
	 * te na sljedeæe mjesto indeks stanja koje se ne podudara sa usporeðivanim stanjem
	 * @param marker - oznacava pocetak odredjenog podniza kod glavnog niza
	 * @param elem2 - indeks stanja koje se ne podudara sa usporeðivanim stanjem
	 * @param niz - jedan od dva glavna niza, ovisno koji se obradjuje
	 * @return obradjeni niz
	 */
	
	public LinkedList<Integer> dodaj_podesi(int marker, int elem2, LinkedList<Integer> niz){
		LinkedList<Integer> pom_niz = niz;
		boolean provjera = false, provjera2 = false;
		int marker2 = 0, marker3 = 0;
		
		
		for (int j = marker + 1; j < niz.size(); j++){
			sloz++;
			if ((!provjera) && (niz.get(j) == -1)) {
				provjera = true;
				marker2 = j;
				break;
			}
			
			if ((!provjera2) && (niz.get(j) == -2)) {
				provjera2 = true;
				marker3 = j;
				break;
			}
		}
		
		pom_niz.remove(pom_niz.indexOf(elem2));
		
		if (marker2 == 0) {
			marker2 = pom_niz.size();
		}
		
		
		if (!provjera2){
			if (provjera) {
				pom_niz.add(marker2 - 1, -2);
				pom_niz.add(marker2, elem2);
			}
			else {
				pom_niz.add(marker2, -2);
				pom_niz.add(marker2 + 1, elem2);
			}
		}
		else pom_niz.add(marker3, elem2);
		
		return pom_niz;
	}
	
	/**
	 * funk. provjerava da li dva indeksa imaju prijelaze s obzirom na ulazne znakove u istim podnizovima 
	 * na nacin da prvo procita indekse prijelaza, te zatim provjerava u kojim se podnizovima nalaze
	 * 
	 * @param elem1 indeks stanja
	 * @param elem2 indeks stanja
	 * @param niz1 prvi glavni niz
	 * @param niz2 drugi glavni niz
	 * @return true - ako se podudaraju prijelazi, false - ako se ne podudaraju
	 */
	
	public boolean provjera (int elem1, int elem2, LinkedList<Integer> niz1, 
			LinkedList<Integer> niz2){
		int gotovo = 0;
		
		Podaci dka_podaci1, dka_podaci2;
		dka_podaci1 = dohvati(elem1);
		dka_podaci2 = dohvati(elem2);
		
		int[] podaci1 = pretvori_u_brojeve(dka_podaci1.citaj_prijelaze()),
			  podaci2 = pretvori_u_brojeve(dka_podaci2.citaj_prijelaze());
		boolean nadjen_elem1, nadjen_elem2;
		int brojac1, brojac2;
		
		for (int i = 0; i < broj_varijabli; i++){
			sloz++;
			elem1 = podaci1[i];
			elem2 = podaci2[i];
			if (elem1 == elem2) gotovo++;
			else {
			brojac1 = -1; brojac2 = 0;
			
			while (brojac1 < niz1.size()){
				sloz++;
				nadjen_elem1 = false; 
				nadjen_elem2 = false;
				brojac1++;
				if (niz1.get(brojac1) == -1){
					brojac2 = brojac1 + 1;
					while (niz1.get(brojac2) != -1){
						sloz++;
						if (niz1.get(brojac2) == elem1) nadjen_elem1 = true;
						if (niz1.get(brojac2) == elem2) nadjen_elem2 = true;
						brojac2++;
						if (brojac2 == niz1.size()) break;
					}
				}
				if (nadjen_elem1 && nadjen_elem2) gotovo++;
				if ((nadjen_elem1 && !nadjen_elem2) || (!nadjen_elem1 && nadjen_elem2)) {
					return false;
				}
				brojac1 = brojac2 - 1;
				if (brojac2 == niz1.size()) break;
			}
		
			brojac1 = -1; brojac2 = 0;
			while (brojac1 < niz2.size()){
				sloz++;
				nadjen_elem1 = false; 
				nadjen_elem2 = false;
				brojac1++;
				if (niz2.get(brojac1) == -1){
					brojac2 = brojac1 + 1;
					while (niz2.get(brojac2) != -1){
						sloz++;
						if (niz2.get(brojac2) == elem1) nadjen_elem1 = true;
						if (niz2.get(brojac2) == elem2) nadjen_elem2 = true;
						brojac2++;
						if (brojac2 == niz2.size()) break;
					}
				}
				if (nadjen_elem1 && nadjen_elem2) gotovo++;
				if ((nadjen_elem1 && !nadjen_elem2) || (!nadjen_elem1 && nadjen_elem2)) {
					return false;
				}
				brojac1 = brojac2 - 1;
				if (brojac2 == niz2.size()) break;
			}
			}//else
		}//for petlja
		if (gotovo == broj_varijabli) return true;
		else return false;
	}
	/**
	 * ispisuje odredjeni niz
	 * @param niz
	 */
	public void ispisi_niz(LinkedList<Integer> niz){
		System.out.println();
		System.out.print("Niz: ");
		for (int i = 0; i < niz.size(); i++){
			System.out.print(niz.get(i)+ " ");
		}
		System.out.println();
	}
	
	public void ispisi_niz_s_markerom(int marker, LinkedList<Integer> niz){
		System.out.println();
		System.out.print("Niz s markerima: ");
		for (int i = 0; i < niz.size(); i++){
			System.out.print(niz.get(i)+ "("+ i +") ");
		}
		System.out.print("	marker = "+marker);
		System.out.println();System.out.println();
	}
	
	/**
	 * funk. ide po nizovima i provjerava dal postoje duplikati indeksa, te ako
	 * ih nadje, brise ih
	 *
	 */
	
	public void izbaci_duplikate(){
		
		int br = 0,  gl_broj, poc;
		
		while (br < gl_niz1.size() && (gl_niz1.size() > 1)){
			if (gl_niz1.get(br) == -1){
				br++; poc = br;
				
				while (br < gl_niz1.size()){
					if (gl_niz1.get(br) == -1) break;
					br++;
				}
				gl_niz1 = sort(poc, br, gl_niz1);
				gl_broj = gl_niz1.get(poc);
				zamijeni_brojeve(gl_broj, gl_niz1, poc, br);
				br--;
			}
			br++;
		}
		
		br = 0;
		while (br < gl_niz2.size() && (gl_niz2.size() > 1)){
			if (gl_niz2.get(br) == -1){
				
				br++; poc = br;
				while (br < gl_niz2.size()){
					if (gl_niz2.get(br) == -1) break;
					br++;
				}
				gl_niz2 = sort(poc, br, gl_niz2);
				gl_broj = gl_niz2.get(poc);
				zamijeni_brojeve(gl_broj, gl_niz2, poc, br);
				br--;
			}
			br++;
		}
		
		
	}
	
	/**
	 * sortira odredjeni podniz unutar jednog od dva glavna niza
	 * 
	 * @param poc pocetak podniza unutar glavnog niza
	 * @param kraj kraj podniza unutar glanvog niza
	 * @param niz glavni niz
	 * @return vraca sortirani niz
	 */
	public LinkedList<Integer> sort (int poc, int kraj, LinkedList<Integer> niz){
		Set<Integer> set = new TreeSet<Integer>();
		
		
		for (int i = poc; i < kraj; i ++){
		 set.add(niz.get(i));
		}
		int z = poc - 1;
		for (int element : set) {
			z++;
			niz.remove(z);
			niz.add(z, element);
		}
		return niz;
	}
	
	/**
	 * funkcija zamijenjuje indekse stanja za ona stanja koja su jednaka
	 * 
	 * @param broj indeks stanja 
	 * @param niz glavni niz u kojem se obradjuje podniz
	 * @param poc pocetak podniza
	 * @param kraj kraj podniza
	 */
	public void zamijeni_brojeve(int broj, LinkedList<Integer> niz, int poc, int kraj){

		Podaci dka_podaci = dohvati(0);
		int[] indexi;
		
		for (int i = poc; i < kraj; i ++){
			if (niz.get(i) != broj) {
				for (int j = 0; j < ukupan_broj_stanja; j++){
				dka_podaci = dohvati(j);
				if (dka_podaci.provjera()){
					indexi = pretvori_u_brojeve(dka_podaci.citaj_prijelaze());
				
					for (int k = 0; k < broj_varijabli; k++){
						if (indexi[k] != broj && indexi[k] == niz.get(i)){
							dka_podaci.postavi_prijelaz(k, broj);
						}
					}
				}
				}
				
			}
		}
	}
	
}