package fer.ppj.ssp;

import java.io.*;

/** Programsko ostvareni parser Pomakni/Pronadi
 * 
 * @author Nikola Kucak
 *
 */

public class Pomakni_Pronadi {
	// metoda read sluzi za citanje tablice parsera iz tekstualne datoteke
	public static String
	read(String filename) throws IOException{
		BufferedReader in = new BufferedReader
		   (new FileReader(filename));
		String s;
		StringBuilder sb = new StringBuilder();
		while((s = in.readLine()) != null)
			sb.append(s + "\n");
		in.close();
		return sb.toString();
		
	}
	
	public static void main(String[] args) throws IOException{
		
		String tablica = new String();
		String[] prod_gram = new String[15];
		String[][] matrica_akcija = new String[15][15];
		int i=0,j=0,m=0,n=0,gran_matr1=0,provjera = 0,pom1,pom2,pom3,pom4,
		pom5;
		int vrh_stoga=0,brojac=0;
		int duljina_ulaznog_niza,duljina_produkcije;
		char[] z_i_n_znakovi = new char[15];
		// citanje Tablice iz datoteke
		tablica = read("Tablica2.txt");
		System.out.println(tablica);
        char[] k = tablica.toCharArray();
        
        // inicijalizacija parametara parsera (stog,ulazni niz)
        char[] stog = new char[50];
        stog[0]     = '#';
        String ulazni_niz = "bebecea$";
        
        // upisivanje pordukcija gramatike ciju tablicu ucitavamo
        prod_gram[0] = "S -> bASB";
        prod_gram[1] = "S -> bA";
        prod_gram[2] = "A -> dSca";
        prod_gram[3] = "A -> e";
        prod_gram[4] = "B -> cAa";
        prod_gram[5] = "B -> c";
        
        //dvije while petlje koje akcije iz tablice parsera prebacuju u
        //matricu_akcija[m][n] da bi smo ih lakse koristili
	    while(k[i]!=' '){
	    	i++;
	    }
	    while(k[i]==' ' || k[i] == '\n' || k[i]=='\t'){
	    	i++;
	    	if(k[i]=='O' || k[i]=='P'){
	    		if(k[i]== 'O'){
	    			if(gran_matr1 >= n){
	    				matrica_akcija[m][n]="Odbaci";
	    			n++;
	    			i=i+6;
	    			if(provjera == 1 && gran_matr1 == n-1)
	    	    		break;
	    			}
	    			else{
	    				n=0;
	    				m++;
	    				matrica_akcija[m][n]="Odbaci";
		    			n++;
		    			i=i+6;
		    			if(provjera == 1 && gran_matr1 == n-1)
    	    	    		break;
	    			}
	    		}
	    		else{
	    			if(k[i+1]=='o')
	    				if(gran_matr1 >= n){
	    					matrica_akcija[m][n]="Pomakni";	
	    	    			n++;
	    	    			i=i+7;
	    	    			if(provjera == 1 && gran_matr1 == n-1)
	    	    	    		break;
	    	    		}
	    	    		else{
	    	    				n=0;
	    	    				m++;
	    	    				matrica_akcija[m][n]="Pomakni";
	    		    			n++;
	    		    			i=i+7;
	    		    			if(provjera == 1 && gran_matr1 == n-1)
	        	    	    		break;
	    	    		}
	    			else
	    				if(gran_matr1 >= n){
	    	    			matrica_akcija[m][n]="Pronadi";
	    	    			n++;
	    	    			i=i+7;
	    	    			if(provjera == 1 && gran_matr1 == n-1)
	    	    	    		break;
	    	    		}
	    	    		else{
	    	    				n=0;
	    	    				m++;
	    	    				matrica_akcija[m][n]="Pronadi";
		    	    			n++;
		    	    			i=i+7;
		    	    			if(provjera == 1 && gran_matr1 == n-1)
		    	    	    		break;
	    	    		}
	    		}
	    		
	    		
	    	}
	    	else
	    	if(k[i]!=' ' && k[i] != '\n' && k[i]!='\t'){
	    		if(k[i]=='#')provjera = 1;
	    		z_i_n_znakovi[j]= k[i];
	    		j++;
	    		if(k[i]=='$')
	    			gran_matr1 = j-1;
	    		i++;
	    	}
	    }
	    //postavljanje parametara ulaznog niza
	    duljina_ulaznog_niza = ulazni_niz.length();
	    char[] ulaz_niz = ulazni_niz.toCharArray();
	    //prolazi kroz sve produkcije i postavljanje indeksa
	    //matrice matrica_akcija
	    for(pom1 = 0;pom1 < duljina_ulaznog_niza;pom1++){
	    	for(pom2 = 0;pom2 <= gran_matr1;pom2++){
	    		if(ulaz_niz[pom1] == z_i_n_znakovi[pom2]){
	    			n=pom2;
	    		}
	    	}
	    	for(pom2 = gran_matr1+1;pom2 < j;pom2++){
	    		if(stog[vrh_stoga] == z_i_n_znakovi[pom2]){
	    			m=pom2-gran_matr1-1;
	    		}
	    	}
	    	//prepoznavanje akcija iz matrice_akcija
	    	if(matrica_akcija[m][n]=="Odbaci"){
    			System.out.println("Nemoguc nastavak parsiranja:");
    			System.out.println("Na stogu je : "+stog[vrh_stoga]);
    			System.out.println("Znak ulaznog niza je: "+ulaz_niz[pom1]);
    			System.out.println("Primjenjuje se akcija Odbaci.");
    			System.exit(0);
	    	}
	    	if(matrica_akcija[m][n]=="Pomakni"){
	    		System.out.println("Na stogu je : "+stog[vrh_stoga]);
    			System.out.println("Znak ulaznog niza je: "+ulaz_niz[pom1]);
    			System.out.println("Primjenjuje se akcija Pomakni te se" +
    					" znak ulaznog niza "+ulaz_niz[pom1]+" stavlja na stog.");
    			vrh_stoga++;
    			stog[vrh_stoga] = ulaz_niz[pom1];
	    	}
	    	if(matrica_akcija[m][n]=="Pronadi"){
	    		System.out.println("Na stogu je : "+stog[vrh_stoga]);
    			System.out.println("Znak ulaznog niza je: "+ulaz_niz[pom1]);
    			System.out.println("Primjenjuje se akcija Pronadi");
    			// provjeravanje da li se niz moze prihvatiti
    			if((vrh_stoga == 1) && (stog[0] == '#') && 
    					(stog[1] == 'S') && (ulaz_niz[pom1] == '$')){
    				System.out.println("Na stogu su oznaka dna stoga # i" +
    						" pocetni nezavrsni znak S,a " +
    						"znak ulaznog niza je oznaka kraja $.");
    				System.out.println("Niz se prihvaca.");
    			}
    			else{
    			// trazenje odgovarajuce redukcije
    			for(pom3 = 0;pom3 < 15;pom3++){
    				duljina_produkcije=prod_gram[pom3].length();
    				char[] polje_prod = prod_gram[pom3].toCharArray();
    				pom4 = duljina_produkcije-1;
    				pom5 = vrh_stoga;
    				StringBuffer buffer = new StringBuffer();
    				brojac = 0;
    				
    				if(polje_prod[duljina_produkcije-1] == stog[vrh_stoga]){
    					if((duljina_produkcije-5) < vrh_stoga+1)
    					for(pom2 = 5;pom2 <= pom4;pom4--){
    						if(polje_prod[pom4]==stog[pom5]){
    							brojac++;
    							pom5--;
    							buffer.append(polje_prod[pom4]);
    							}
    					}
    					if(brojac == duljina_produkcije-5){
    						stog[vrh_stoga-brojac+1] = polje_prod[0];
    						pom5 = 2;
    						while(vrh_stoga-brojac+pom5 <= vrh_stoga){
    							stog[vrh_stoga-brojac+pom5]= ' ';
    							pom5++;
    						}
    						buffer.reverse();
    						System.out.println("Niz "+buffer+" na stogu " +
    								"zamjenjuje se nezavrsnim znakom "+polje_prod[0]);
    						vrh_stoga = vrh_stoga-brojac+1;
    						pom1--;
    						break;
    						}
    				}
    			}
    			}
	    	}

	    }
	    
	}
			
		
}
