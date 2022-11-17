package komunikacijskiSustav.predajnik;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.*;


/**
 * Klasa koja kodira informacije. 
 * Vrši se kompresija podataka korištenjem metode LZW rjeènika.
 */
class KoderInformacije {
	String Ulaz="";
	List <Integer> Izlaz ;
	Map <String, Integer> Rijecnik = new HashMap<String, Integer>();
	
	public KoderInformacije(char[] ulaz) {
		for (char c: ulaz )
		Ulaz += c;
		Izlaz = new  ArrayList <Integer>();
		this.Koder();
	}
	
	public Integer[] getIzlaz() {
		return  (Integer[]) Izlaz.toArray(new Integer[0]);
	}
	
	private void Koder(){
	
	Rijecnik.put("a",1);
	Rijecnik.put("b",2);
	Rijecnik.put("c",3);
	Rijecnik.put("d",4);
	
	int i = 0;
	Integer broj = 5;
	String s = ""; 
	
	while (i< Ulaz.length()){
		int j = i+1;
		
		while(j < Ulaz.length()){
			s = Ulaz.substring(i, j+1);
			if (!Rijecnik.containsKey(s)){
				Rijecnik.put(s, broj++);
				Izlaz.add( Rijecnik.get(s.substring(0,s.length()-1)) );
				s = s.substring(s.length()-1);
				break;
			}else{
				j++;
			}
		}
		i = j;
	}
	if ( !Rijecnik.containsKey(s) ){
		Rijecnik.put(s,broj);
		Izlaz.add(Rijecnik.get(s.substring(0,s.length())));
	}else 
		Izlaz .add(Rijecnik.get(s.substring(0,s.length())));
}	 
	
	public void View(){
		System.out.println("Rijeènik:");
		System.out.println(Rijecnik.entrySet());
		System.out.println("Izlazni niz:");
		for (Integer x : Izlaz )
			System.out.print( x + "|");
		System.out.println();
		
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
		    for (Integer x : Izlaz ){
		    	out.write(Nadopuni(Integer.toBinaryString(x)));
		    }     
			 out.close();
		}catch (Exception e){
			 System.err.println("Error: " + e.getMessage());
		}
		
		
	}
	/* Funkcija za nadopunu stringova do dulje kodne rijeèi 15. */
	private String Nadopuni(String by) {
		String izlaz = new String();
		for(int i = 0; i < 11 - by.length(); i++ )
			izlaz += "0";
		return izlaz + by;
	}
	
	/** Glavna pokretaèka metoda klase. */
	 public static void main(String args[])
	 {
		 char[] ulaz = new char[10000];
		 try{
			 File file = new File(args[0]);
			 FileInputStream fis = new FileInputStream(file);
			 int n = 0, i=0;
			 while ((n = fis.read()) != -1){
				 char c = (char)n;
				 ulaz[i++] = c ;
		 }

		 }catch(FileNotFoundException fnfe){
			 System.err.println("FileNotFoundException: " + fnfe.getMessage());
		 }catch(IOException ioe){
			 System.err.println("IOException: " + ioe.getMessage());
		 } 
		 
		 KoderInformacije koder = new KoderInformacije(ulaz);
		 koder.toFile("23.txt");
		 //koder.View();
	  }
}
	
	
