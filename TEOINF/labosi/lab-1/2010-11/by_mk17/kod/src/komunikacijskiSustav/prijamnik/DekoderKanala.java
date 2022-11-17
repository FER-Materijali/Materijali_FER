package komunikacijskiSustav.prijamnik;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashMap;



/**
 * Klasa koja vrši dekodiranje dobivenih podataka.
 */
public class DekoderKanala {
	/** Generirajuæi polinom ciklièkog kodera x^4 + x + 1 */
	static byte[] gP = new  byte[] {1, 1, 0, 0, 1};
	/** Stupanj generiajuæeg polinoma */
	static int stupanj = 4;
	/** Varijabla koja sadrži zakodirane infromacije */
	private static String[] izlaz = new String[10000];
	
	/** Tablica sindroma */
	static HashMap <String, Integer> sindrom = new HashMap<String, Integer>();

	
	
	/**
	 * Podrazumijevani konstrukor klase.
	 * */
	public DekoderKanala(){
		generirajSindrom();
		for(int i = 0; i < 10000; i++)
			izlaz[i] = new String("");
	}
	
	
	/**
	 *  Funkcija raèuna CRC za ulaznu poruku
	 * @param ulazna poruka za koju treba izraèunati CRC
	 * @return CRC
	 */
	public static int[] dekodiraj(int[] ulaznaPoruka){		    	
	    /* Ovo je ekvivalentno mneženju polinoma */
	    int[] bitovi = new int[ulaznaPoruka.length + stupanj]; // Napravi se rezevacija za još dodatnih x^r mjesta
	    for ( int j = bitovi.length - 1 ; j >= 0; j--){
	    	if ( ulaznaPoruka.length > (bitovi.length - 1 - j) ) bitovi[j] = ulaznaPoruka[(bitovi.length - 1 - j)];
            else bitovi[j] = 0;	
	    }
	    //prozor je polje preko kojeg se sve raèuna.
	    int[] prozor = new int[stupanj + 1]; //Prozor je duljine r + 1
	    for ( int index = 0; index <= stupanj;index++ )
	    	prozor[index] = bitovi[bitovi.length - (stupanj + 1 - index)];
	    /* nova vrijednost prozora je ono trenutno u njemu polinomski podijeljeno sa generjuæim polinomom*/
	    prozor = oduzmiBinarno(prozor); 
	    // Nakon izraèuna prozor se shifta u desno za jedno mijesto
	    if (bitovi.length > 5)  // Ovo je zbog toga što broj 1 ne treba shiftati.
	    	prozor = pomakniProzor(prozor);

	    for ( int p = bitovi.length - stupanj - 2; p >= 0; p--){
	    	prozor[0] = bitovi[p]; // Potom se prvi bit puni sa prvim iduæim bitom iz niza
		    /* Ako je vodeæa jedinica onda se binarno odzuima, ako nije onda se samo ide dalje na pomicanje prozora */
	    	if (prozor[stupanj] == 1 ) prozor = oduzmiBinarno(prozor); 
		    if( p == 0) continue; // Ovo je zato što zadnji prolaz nije potrebno izvršiti pomak prozora.
		    prozor = pomakniProzor(prozor);
	    }
	    
	    int[] izlaz = new int[stupanj];
	  
	    int index = stupanj;
	    while ( --index >= 0 ){
	    	izlaz[stupanj - 1 - index] = prozor[index];
	    }
	    return izlaz;
		    
	}
	

	/** Metoda za generiranje sindroma */
	private void generirajSindrom (){
		int[] p = new int[3];
		p[0] = p[1]= p[2] = 1;
		int[] crc = dekodiraj(trimBinary(p));
		
		int[] y = new int[p.length + 4];
		int k = 0 ;
		for ( int j=0; j < p.length + 4; j++){
			if ( j < p.length ) y[j] = p[j];
			else y[j] = crc[k++];		
			//System.out.print(y[j]);
		}
		
		for ( int i = 0; i < 15; i++){		
			int[] test = kopirajPolje(y);
			if ( test[i] == 0 ) test[i] = 1;
			else test[i] = 0;
			int[] s = dekodiraj(trimBinary(test));
			sindrom.put(s[3]+""+s[2]+""+s[1]+""+s[0], i);
		}
		
		//System.out.println(sindrom.entrySet()+"\n");
		
		
	}
	
	/* Funkcija za kopiranje polja */
	private int[] kopirajPolje( int[] a){
		int[] kopija = new int[15]; int k = 0;
		for ( int i = 0; i < 15; i++){
			if ( i < 15 - a.length ) kopija[i] = 0;
			else kopija[i] = a[k++];
		}
		return kopija;
	}
	
	/**
	 * S[y(x)] = x^r y(x) mod g(x)
	 * Radi samo za jednostruke pogreške. Višestruke pogreške nije u moguænosti ispraviti. 
	 * @param ulaz je konda rijec
	 * @return ispravljeni kod ili 0 u sluèaju da nije mogao ispraviti.
	 */	
	private static String ispravi(int[] y) {
		int[] s = dekodiraj(trimBinary(y));
		String kljucSindroma = new String("");
		
		kljucSindroma += s[3];
		kljucSindroma += s[2];
		kljucSindroma += s[1];
		kljucSindroma += s[0];
		
		/*
		System.out.println("došao mi je:");
		for ( int i: y ) System.out.print(i);
		
		System.out.println("::::");
		//System.out.println("kljuc Sindorma je :" + kljucSindroma);
		 * */
		int kriviBit = 0;
		if ( sindrom.containsKey(kljucSindroma))
			kriviBit = sindrom.get(kljucSindroma);
		else return "00000000000";
		
		/*
		System.out.print("krivi je " + kriviBit +" bit : ");		
		for ( int i : y ) System.out.print(i);

		String popravljen = new String("");
		for ( int i = 0; i < 15; i++){
			if( kriviBit == i ){
				if ( y[kriviBit] == 0) popravljen += "1";
				else popravljen += "0";
			}else 
				popravljen += y[i];
		}
		System.out.println(" -> " + popravljen);
		 */
		
		String vratiPopravljeno = new String("");
		try{
			for ( int i = 0; i < 11; i++){
				if( kriviBit == i ){
					if ( y[kriviBit] == 0) vratiPopravljeno += "1";
					else vratiPopravljeno += "0";
				}else 
					vratiPopravljeno += y[i];
			}		
		}catch ( Exception e ){
			vratiPopravljeno = new String("00000000000");
		}

		
		return vratiPopravljeno;
	}
	
	
	/* Funkcija vrši binarno oduzimanje prozora od generirajuæeg polinoma. */
	private static int[] oduzmiBinarno( int[] prozor){
		int[] rezultat = new int[stupanj + 1];
		for ( int i = 0; i < stupanj + 1; i++){
			rezultat[i] = Math.abs(prozor[i] - gP[i]);
		}
		return rezultat;
		
	}
	/* Funkcija za binarno množenje. - sve pomièe udesno za jedno polje.*/
	private static int[] pomakniProzor( int[] prozor){
		int[] rezultat = new int[stupanj + 1];
		for ( int i = stupanj; i > 0 ; i--){
			rezultat[i] = prozor[i - 1];
		}
		return rezultat; 
	}
	
	/**
	 * Ispisuje izlaz iz entropijskog kodera 
	 * @param datoteka za izlaz
	 */
	public void toFile(String file){
		try{
		    FileWriter fstream = new FileWriter(file);
		    BufferedWriter out = new BufferedWriter(fstream);
		    //final String lineSeparator = System.getProperty ( "line.separator" );
		    for( int i = 0; i < index; i++){
		    	out.write(izlaz[i] );//+ lineSeparator
		    }
		          
			out.close();
		}catch (Exception e){
			 System.err.println("Error: " + e.getMessage());
		}
		
		
	}

	/* Funkcija za brisanje vodeæih nula iz binarnog broja. */
	private static int[] trimBinary ( int[] ulaz ){
		int p = 0;	
		for ( int i = 0; i < ulaz.length; i++){
			if ( ulaz[i] == 0 ) p++;
			else break;
		}
		int[] izlaz = new int[ulaz.length - p];
		for ( int i = 0; i < ulaz.length - p; i++){
			izlaz[i] = ulaz[i + p];
		}
		return izlaz;
	}
	/** Varijabla za praæenje indeksa i broja rijeèi rjeènika */
	static int index = 0;
	/**
	 * Funkcija provjerava je li dobiveni CRC jednak izraèunatom.
	 * @param izracunatCRC
	 * @param dobivenCRC
	 * @return istina ako su jednaki, laž inaèe
	 */
	private static boolean ispravanCRC(int[] izracunatCRC, int[] dobivenCRC) {
		for( int i=0; i<izracunatCRC.length;i++)
			if ( izracunatCRC[i] != dobivenCRC[i]) return false;
		return true;
	}
	
	/** Glavna poktetaèka metoda klase */
	 public static void main(String args[]){
		 DekoderKanala dekoder = new DekoderKanala();
		 try{
			 File file = new File(args[0]);//"45.txt"
			 FileInputStream fis = new FileInputStream(file);
			 int n = 0, i=0, k = 0;
			 int[] buf = new int[11];		//d(x)
			 int[] dobivenCRC = new int[4];// r(x)
			 int[] y = new int[15];			//y(x)
			 while ((n = fis.read()) != -1){
				 char c = (char)n;
				 y[i] = Integer.parseInt(c + "");
				 if ( i < 11 ) buf[i] = Integer.parseInt(c + "") ;
				 else dobivenCRC[k++] = Integer.parseInt(c + "") ;
				 i++;
				 /* Nakon što se bufer napunio provjerava je li došlo do pogreške u kanalu. */
				 if ( i == 15) {
					 if ( trimBinary(buf).length == 0 ){ 
						 //System.out.println("Pogoðen poseban sluèaj.");
						 izlaz[index] = ispravi(dobivenCRC);
						 index++;
						 i = 0;
						 k = 0;
						 continue;
					 }
					 int[] izracunatCRC = DekoderKanala.dekodiraj(trimBinary(buf));					 					 
					 if ( ispravanCRC (izracunatCRC, dobivenCRC)) {	//Ako je isparvno samo stavi u izlaz			 
						 for( int j=0; j < 11; j++){ 
							 izlaz[index] += buf[j];
						 }
					 } else {	//Ako nije onda pošalji u funkciju za ispravljanje				 
						 //for ( int j=0; j < 15; j++) System.out.print(y[j]); System.out.print(" | ");						 
						 izlaz[index] = ispravi(y);
						 //System.out.print(" ispravljam : "+izlaz[index]);
		
					 }
					 //System.out.print(" : "+izlaz[index]);
					 //System.out.println();
					 index++;
					 i = 0;
					 k = 0;
					  
				}
				 
				  
		 }
		 }catch(FileNotFoundException fnfe){
			 System.err.println("FileNotFoundException: " + fnfe.getMessage());
		 }catch(IOException ioe){
			 System.err.println("IOException: " + ioe.getMessage());
		 } 
		 
		 dekoder.toFile("56.txt");
		  
	  }

	
}
