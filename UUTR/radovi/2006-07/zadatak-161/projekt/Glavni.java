package projekt;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
/**
 *
 * glavni program koji pokrece funkcije za minimizaciju DKA
 * 
 * brojac redova - predstavlja broj stanja DKA, ali se mora oduzeti prvi red jer je
 * on rezerviran za ulazne znakove
 */
public class Glavni {

	public static void main(String[] args) {
		BufferedReader reader = null;
		int brojac_redova = 0;
		int broj_varijabli = 0;
		
		DKA dka = new DKA();
		System.out.println("Ulaz:");
		String[] varijable;
		String gl_linija = "";
		try {
			reader = new BufferedReader(new FileReader("c:\\dka.txt"));
			} catch (FileNotFoundException e) {
				System.out.println("Datoteka dka.txt nije nadjena!");
				System.out.println("Datoteka bi se trebala nalaziti na c:\\dka.txt, " +
						"ili prilagodite program");
				System.exit(11);
			}
			
			
			while(true) {
				String linija = "";
				try {
					linija = reader.readLine();
					}catch(IOException e) {
						System.exit(11);
					}
				if(linija==null) break; // ako je procitan kraj datoteke, gotovi smo
				else {
					System.out.println(linija);
					brojac_redova++;
					if (brojac_redova == 1) gl_linija = linija;
					
					if (brojac_redova == 1) {
						varijable = linija.split("\t");
						broj_varijabli = varijable.length - 1;
						dka.upisi_broj_varijabli(broj_varijabli);
					}
					else {
						String[] stanja = linija.split("\t");
						DKA.Podaci dka_podaci = new DKA.Podaci(broj_varijabli);
						
						dka_podaci.ubaci_stanja(stanja);
						dka.dodaj(dka_podaci);
					}
				}
					
			}
			dka.upisi_ukupan_broj_stanja(brojac_redova - 1);
			
			dka.izbaci_nedohvatljiva_stanja();
			//long pocetak = System.nanoTime();
			dka.dijeli_po_podudarnosti();
			//long kraj = System.nanoTime();
			
			dka.izbaci_duplikate();
			
			dka.izbaci_nedohvatljiva_stanja();
			
			
			DKA.Podaci dka_podaci2 = new DKA.Podaci(broj_varijabli);
			System.out.println();System.out.println();
			System.out.println("Nakon minimizacije:");
			System.out.println();
			System.out.println(gl_linija); // ispisivanje ulaznih znakova
			for (int j = 0; j < (brojac_redova - 1); j ++){
				dka_podaci2 = dka.dohvati(j);
				if (dka_podaci2.provjera()){
					
					System.out.print("q"+j+"	");
					String[] pomocna_var = dka_podaci2.citaj_prijelaze();
					for (int k = 0; k < broj_varijabli; k ++){
						System.out.print(pomocna_var[k]+" 	");
					}
					if (dka_podaci2.citaj_prihvatljivost()) System.out.print("1");
					else System.out.print("0");
					System.out.println();
				}
			}
			//System.out.println("Trajanje: " + (kraj - pocetak)/1000 + " mikrosekundi");
			
	}
}
