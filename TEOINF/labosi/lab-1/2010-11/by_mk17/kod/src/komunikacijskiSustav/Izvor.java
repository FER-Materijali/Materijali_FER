package komunikacijskiSustav;
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.util.Arrays;
import java.util.Random;

/**
 * Klasa koja predstavlaj izvor informacija.
 *
 */
public class Izvor {
	/** Struktura podataka koja sadrži sve informacije ( znakove ) */
	private char[] Simbol;
	/** 
	 * Podrazumijevani konstruktor klase.
	 * Stvara generira 10 000 simbola i sprema u varijablu Simbol. 
	 * */
	public Izvor(){
		Simbol = new char[10000];
		for (int i = 0; i<10000; i++){
			Simbol[i] = Znak(this.SlucajanBroj());
		}
	}

	/**
	 * Novi konstruktor koji šalje znakove u datoteku.
	 * @param Odredišna datoteka
	 */
	public Izvor(String imeDat){
		Simbol = new char[10000];
		
		try{
		    FileWriter fstream = new FileWriter(imeDat);
		    BufferedWriter out = new BufferedWriter(fstream);

			for (int i = 0; i<10000; i++){
				Simbol[i] = Znak(this.SlucajanBroj());
				out.write(Simbol[i]);
			}			    
			       
			 out.close();
		}catch (Exception e){
			 System.err.println("Error: " + e.getMessage());
		}
		

	}
	
	
	/** Ako je potrebno generirati x broj simbola*/
	public Izvor(int x){
		Simbol = new char[x];
		for (int i = 0; i<x; i++){
			Simbol[i] = Znak(this.SlucajanBroj());
		 
		}
	}
	
	/** Geter varijable Simbol */
	public char[] getSimbol() {
		return Simbol;
	}
	
	/* funkcija za generiranje sloèajnog broja. */
	private double SlucajanBroj(){
		Random Generator = new Random();
		return Generator.nextDouble();
	}
	
	/* funkcija za odreðivanje koji se znak pojavio. */
	private char Znak(double broj){
		if (broj < 0.1) return 'a' ;
		if (broj < 0.3) return 'b' ;
		if (broj < 0.6) return 'c' ;
		else return 'd' ;
	}
	
	/** Metoda za prikaz generiranih znakova. */
	public void View(){
		System.out.println("Generirani znakovi:");
		System.out.print(Arrays.toString(Simbol));
		System.out.println("\n");
	}
	
	 /** Pokretaèka procedura klase. */
	 public static void main(String args[])
	 {
			 new Izvor("12.txt");
	 }
}
	

