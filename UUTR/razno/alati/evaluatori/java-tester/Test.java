import java.io.BufferedInputStream;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.InputStreamReader;
import java.io.PrintStream;

/**
 * Testna klasa za labose iz UTR-a. Konkretno je napravljena za 2. labos, ali mora raditi za sve jer
 * se temelji na uspoređivanju output datoteka.
 * Redove 21-24 MORATE promijeniti te u 55. redu treba odabrati ime klase koju se testira.
 * @author Murta
 * @version 1.0
 */
public class Test {
	//sve ove konstante treba promijeniti, pazite da se put dijeli znakom \\ jer je
	//za Javu \ escape znak onog iza
	//Put do npr. 12. testa u 2. labosu je kod mene C:\Users\Murta\Desktop\lab2_primjeri\test12\t.ul
	public static final int BR_NAJVISEG_TESTA = 14;	
	public static final String prvi_dio = "C:\\Users\\Murta\\Desktop\\lab2_primjeri\\test";
	public static final String ulazni = "\\t.ul";  //naziv ulaznog filea, paziti na nastavak
	public static final String njihov_izlaz = "\\t.iz"; //naziv njihovog rezultata, paziti na ekstenziju
	public static final String moj_izlaz = "\\test_labosa.iz";	//ovo može ostat isto
	
	public static void main(String[] args) throws Exception {
		PrintStream original = new PrintStream(System.out);
		
		boolean nijeBiloGreske = true;
		
		for(int i = 1; i <= BR_NAJVISEG_TESTA; i++){
			String broj, s; File file;
			if(i < 10){
				broj = "0" + i;
			}
			else{
				broj = ""+ i;
			}
			s = prvi_dio+broj+ulazni;		
			file=new File(s);
			
		    System.setIn(new FileInputStream(file));
			
			BufferedReader reader = new BufferedReader((new InputStreamReader (new BufferedInputStream(System.in))));

			s = prvi_dio+broj+moj_izlaz;		
			file=new File(s);
			
			System.setOut(new PrintStream(new FileOutputStream(file)));
			
			String[] argsum = new String[1];
			argsum[0] = ""+i;
			try{
				MinDka.main(argsum);	//POZIVANJE main PROGRAMA KOJI RADITE
										//šalje se broj testa kao argument komandne linije za unutrašnje
										//debuggiranje ako netko želi tako
			}
			catch(Exception e){
				System.setOut(original);
				System.out.println("Test broj "+ i +" baca exception.");
				nijeBiloGreske = false;
				continue;
			}
			
			//ovdje počinje engine usporedbe
			s = prvi_dio+broj+moj_izlaz;		
			file=new File(s);
			BufferedReader tested = new BufferedReader(new FileReader(file));
			
			s = prvi_dio+broj+njihov_izlaz;		
			file=new File(s);
			BufferedReader right = new BufferedReader(new FileReader(file));
	
			System.setOut(original);
			
			String rjesenje, moje;
			rjesenje = right.readLine();
			moje = tested.readLine();
			int red = 1;
			while((rjesenje != null) && (moje != null)){
				if(!rjesenje.equals(moje)){
					nijeBiloGreske = false;
					System.setOut(original);
					System.out.println("Postoji pogreška u testu broj "+ i +". u "+red+". redu.");
				}
				rjesenje = right.readLine();
				moje = tested.readLine();
				red++;
			}
			reader.close();
			right.close();
			tested.close();
		}
		
		if(nijeBiloGreske == true){
			System.setOut(original);
			System.out.println("Sve je super i sve je za 6 (bodova).");
		}
	}
}
