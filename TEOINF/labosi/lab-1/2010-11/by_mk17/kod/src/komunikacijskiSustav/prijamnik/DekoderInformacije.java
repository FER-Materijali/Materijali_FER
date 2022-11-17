package komunikacijskiSustav.prijamnik;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.*;



/**
 * Klasa koja dekodira informacije. 
 * Vrši se dekompresija podataka korištenjem metode LZW rjeènika.
 */
class DekoderInformacije {
	private Map <Integer, String> Rijecnik = new HashMap<Integer, String>();
	private Integer[] Ulaz;
	private String[] Izlaz;
	
	int vektor = 0;
	
	public DekoderInformacije() {

		
	}
	
	public void dekodiraj (Integer[] ulaz ){
		Ulaz = ulaz;
		Dekoder();	
	}
	
	private void Dekoder(){
		Integer broj = 5;
		String RadnaRijec ="";
		Izlaz = new String[Ulaz.length];
		
		int pocetak = 0;
		
		//pocetna abeceda u rijecniku
		Rijecnik.put(1,"a");
		Rijecnik.put(2,"b");
		Rijecnik.put(3,"c");
		Rijecnik.put(4,"d");
		
		//radna rijec postaje prvi znak u nizu
		pocetak = notNullIndex(0);
		RadnaRijec += Rijecnik.get(Ulaz[pocetak]);
		
		for (int j = pocetak+1; j < Ulaz.length; j++)
		{
			j = notNullIndex(j);
			//System.out.println(j);
			vektor = j - 1;
			
			//ako rijecnik sadrzi kljuc
			if (Rijecnik.containsKey(Ulaz[j]))
			{
				//Dodaj sljedeci znak iz ulaznog niza u radnu rijec
				RadnaRijec += Rijecnik.get(Ulaz[j]);
				for (int i = 1; i < RadnaRijec.length(); i++)
				{
		  			//stavljamo u rijec znakove iz radne rijeci sve dok ne naðemo rijec koja se ne nalazi u rijecniku
					String rijec = RadnaRijec.substring(0, i+1);
		  			
		  			if (!Rijecnik.containsValue(rijec))
		  			{
			  			Rijecnik.put(broj, rijec);
			  			++broj;
			  			Izlaz[vektor] = rijec.substring(0, rijec.length()-1);
			  			//System.out.println(rijec.substring(0, rijec.length()-1));

			  			//odbacuje se sve iz radne rijeci sto je stavljeno u rijecnik, osim zadnjeg znaka
			  			RadnaRijec = rijec.substring(rijec.length()-1) + RadnaRijec.substring(i+1);
			  			break;
		  			}
		  			
				}
				
			}else
				{
					RadnaRijec += RadnaRijec.substring(0, 1);
					Rijecnik.put(broj, RadnaRijec);
					++broj;
					Izlaz[vektor] = RadnaRijec.substring(0,RadnaRijec.length()-1);
					//System.out.println(RadnaRijec.substring(0,RadnaRijec.length()-1));
				}
		}
		Izlaz[++vektor] = RadnaRijec;
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
		    for ( String s : Izlaz){
		    	if ( s == null) continue;
		    	//System.out.println(s);
		    	out.write(s);
		    }
		          
			out.close();
		}catch (IOException e){
			 System.err.println("Error: " + e.getMessage());
		}
		
		
	}
	
	
	private static int dekatsko( int[] bin){
		int dek = 0;
		//System.out.println("String je:" + bin);		
		for( int i = 10; i >=0; i--){
			dek  += bin[i] * (int)Math.pow(2,10 - i) ;
			//System.out.println("    :" + (int)bin.charAt(i)%2);
		}
		//System.out.println("Dekatski broj je:" + dek);
		return dek;
	}
	
		
 	private int notNullIndex(int c){
 		 while (Ulaz[c]==0){
 			Izlaz[c]="?";
 			//System.out.println(c + " " + Izlaz[c]); 
 			c++;
 		 }
 		 return c;
 	}
	
	public void View(){
		//System.out.println("Dekodirani niz:" + Izlaz);
		System.out.println(Rijecnik.entrySet()+"\n");
	}
	
	
	static int index = 0;
	
	 public static void main(String args[])
	 {
		 DekoderInformacije dekoder = new DekoderInformacije();
		 Integer[] ulaz = new Integer[10000];
		 try{
			 File file = new File(args[0]);//"56.txt"
			 FileInputStream fis = new FileInputStream(file);
			 int n = 0, i=0;
			 int[] buf = new int[11];
			 while ((n = fis.read()) != -1){
				 char c = (char)n;
				 buf[i++] = Integer.parseInt(c + "") ;
				 
				 if ( i == 11) {
					
					 ulaz[index] = dekatsko(buf);
					 //for ( int j : buf ) System.out.print(j);
					 //for ( int j = 0; j < 11; j++) System.out.print(buf[j]);
					 //System.out.println(":" + ulaz[index]);
					 index++;
					 i = 0;
					  
				 }
		 }
		 }catch(FileNotFoundException fnfe){
			 System.err.println("FileNotFoundException: " + fnfe.getMessage());
		 }catch(IOException ioe){
			 System.err.println("IOException: " + ioe.getMessage());
		 } 
		 
		 Integer[] manji = new Integer[index];
		 for ( int i = 0; i < index; i++)
			 manji[i] = ulaz[i];
		 
		 
		 dekoder.dekodiraj(manji);
		 //dekoder.View();
		 dekoder.toFile("67.txt");
		  
	  }
}

