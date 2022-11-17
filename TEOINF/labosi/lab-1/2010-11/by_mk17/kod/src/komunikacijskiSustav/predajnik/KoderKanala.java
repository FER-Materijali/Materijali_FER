package komunikacijskiSustav.predajnik;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Random;

/**
 * Ciklièki koder duljine kodne rijeèi 15.
 * 		:11 podatkovnih bitova
 * 		:4 zaštitna
 * 		:[15,11,4]
 */
public class KoderKanala {	
	/** Generirajuæi polinom ciklièkog kodera x^4 + x + 1 */
	byte[] gP = new  byte[] {1, 1, 0, 0, 1};
	/** Stupanj generiajuæeg polinoma */
	int stupanj = gP.length - 1;
	/** Varijabla koja sadrži zakodirane infromacije */
	private static String[] izlaz = new String[10000];
	
	
	/**
	 * Podrazumijevani konstrukor klase.
	 * */
	public KoderKanala(){
		for(int i = 0; i < 10000; i++)
			izlaz[i] ="";
	}
		
	
	/**
	 *  Funkcija raèuna CRC za ulaznu poruku
	 * @param ulazna poruka za koju treba izraèunati CRC
	 * @return CRC
	 */
	public int[] kodiraj(int[] ulaznaPoruka){		    	
	    /* Ovo je ekvivalentno množenju polinoma */
	    int[] bitovi = new int[ulaznaPoruka.length + stupanj]; // Napravi se rezevacija za još dodatnih x^r mjesta
	    for ( int j = bitovi.length - 1 ; j >= 0; j--){
	    	if ( ulaznaPoruka.length > (bitovi.length - 1 - j) ) bitovi[j] = ulaznaPoruka[(bitovi.length - 1 - j)];
            else bitovi[j] = 0;	
	    	//System.out.print(bitovi[j]);
	    }

	    //System.out.print("bit:"+bitovi.length);
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

	/* Funkcija vrši binarno oduzimanje prozora od generirajuæeg polinoma. */
	private int[] oduzmiBinarno( int[] prozor){
		int[] rezultat = new int[stupanj + 1];
		for ( int i = 0; i < stupanj + 1; i++){
			rezultat[i] = Math.abs(prozor[i] - gP[i]);
		}
		return rezultat;
		
	}
	/* Funkcija za binarno množenje. - sve pomièe udesno za jedno polje.*/
	private int[] pomakniProzor( int[] prozor){
		int[] rezultat = new int[stupanj + 1];
		for ( int i = stupanj; i > 0 ; i--){
			rezultat[i] = prozor[i - 1];
		}
		return rezultat; 
	}
	
	/** Funkcija za dohvat izlaza */
	public String[] getIzlaz(){
		return izlaz;
	}
	
	
	/** Metoda za pregled izlaza iz kodera. */
	public void View(){
		for( String i : izlaz)
			System.out.println(i);
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
		    	out.write(izlaz[i]);//
		    }
		          
			out.close();
		}catch (Exception e){
			 System.err.println("Error: " + e.getMessage());
		}
		
		
	}
	/** Medota koja inicijalizira masku, stvara ju samo ako ona ne postoji veæ. */
	public void intMasku(String file){
		try{
		    if ( new File(file).exists() ) return; 
			
			FileWriter fstream = new FileWriter(file);
		    BufferedWriter out = new BufferedWriter(fstream);
		     
		    
		    for( int i = 0; i < index; i++){
			    String maska = new String("");//"000000000000000"
			   
			    for ( int j = 0;j < 15; j++){
			    	if ( slucajanBrojD() <0.2  ) maska += "1";
			    	else maska += "0";
			    }
		    	//System.out.println("__" + maska);
		    	out.write(maska);
		    }
		          
			out.close();
		}catch (Exception e){
			 System.err.println("Error: " + e.getMessage());
		}
		
		
	}
	/* funkcija za generiranje sloèajnog broja. */
	private double slucajanBrojD(){
		Random Generator = new Random();
		return Generator.nextDouble();
	}
	
	/* Metoda za micanje vodeæih nula iz binarnog broja. */
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
	
	/** Index sadržava broj kompresiranih informacija */
	static int index = 0;
	
	/** Glavna pokretaèka metoda klase */
	public static void main(String args[]){
		
		if ( args.length < 1 ) {
			System.out.println("Fali ime datoteke usage: z_kod 23.txt");
			return;
		}
		
		 KoderKanala koder = new KoderKanala();
		 /* Èita iz ulazne datoteke 11 po 11 bitova i sprema ih u varijablu buf */
		 try{
			 File file = new File(args[0]);//"23.txt"
			 FileInputStream fis = new FileInputStream(file);
			 int n = 0, i=0;
			 int[] buf = new int[11];
			 while ((n = fis.read()) != -1){
				 char c = (char)n;
				 buf[i++] = Integer.parseInt(c + "") ;
				 
				 if ( i == 11) { /* Nakon što se varijabla buf napulina */
					 int[] crc = koder.kodiraj(trimBinary(buf)); // Izraèunava se CRC
					 for( int j=0; j < 11; j++){ //te se potom to dvoje pridružuje u
						 izlaz[index] += buf[j]; //varijablu izlaz.
					 }
					 for( int j = 0; j < 4; j++ ) 
						 izlaz[index] += crc[j];
					 index++;
					 i = 0;		
					 //System.out.println();			  
				 }
				 		  
		 }
		 }catch(FileNotFoundException fnfe){
			 System.err.println("FileNotFoundException: " + fnfe.getMessage());
		 }catch(IOException ioe){
			 System.err.println("IOException: " + ioe.getMessage());
		 } 
		 //System.out.println("udaljenost je: " + udaljenost());
		 koder.toFile("34.txt");
		 koder.intMasku("err_vec.txt");
		  
	  }
	
	
	
	
	
	
	
}
