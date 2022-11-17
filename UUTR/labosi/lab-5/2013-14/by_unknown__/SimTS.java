import java.util.*;
import java.io.*;

/** Simulator Turingovog stroja
 * rezultati na SPRUT-u 10/10
 *
 */

public class SimTS {
	private static List<String> stanja = new ArrayList<String>();
	private static List<String> ulazniZnakovi = new ArrayList<String>();
	private static List<String> znakoviTrake = new ArrayList<String>();
	private static String praznaCelija = "";
	private static String[] traka;
	private static List<String> prihvatljivaStanja = new ArrayList<String>();
	private static String pocetnoStanje = "";
	private static int pocetniPolozajGlaveTS = 0;
	private static Map<String,String> prijelazi = new HashMap<String,String>();

	public static void main(String[] args) throws IOException {
		Scanner input = new Scanner(System.in);
		
		String []buffer;
		String buf = "";
		
		for (int i = 0; i < 3; i++) {
			buffer = input.nextLine().split(",");
			switch(i) {
				case 0 :
					for(String s : buffer) stanja.add(s);
					break;
				case 1 :
					for(String s : buffer) ulazniZnakovi.add(s);
					break;
				case 2 :
					for(String s : buffer) znakoviTrake.add(s);
					break;
			}
		}
		
		praznaCelija = input.nextLine();
		
		buf = "";
		buffer = input.nextLine().split("");
		traka = new String[buffer.length-1];
		int i, j;
		for(i = 1,j = 0; i < buffer.length; i++, j++) {
			traka[j] = buffer[i];
		}
		
		buffer = input.nextLine().split(",");
		for(String s : buffer) prihvatljivaStanja.add(s);
		
		pocetnoStanje = input.nextLine();
		
		pocetniPolozajGlaveTS = Integer.parseInt(input.nextLine());
	
		buf = "";
		while(input.hasNextLine()) {
			buf = input.nextLine();
			if(buf.isEmpty()) break;
			String delta[] = buf.split("->");
			prijelazi.put(delta[0], delta[1]);
		}
		TuringovStroj();
	}
	
	
	public static void TuringovStroj() {
		String znak = "";
		String stanje = pocetnoStanje;
		String prijelaz = "";
		int i = pocetniPolozajGlaveTS;
		int prihvatljivo = 0;

		try {
			while(true) {
				znak = traka[i];
				prijelaz = prijelazi.get(stanje + "," + znak);
				String[] novo = prijelaz.split(",");
				stanje = novo[0];
				traka[i] = novo[1];
				if(novo[2].equals("L")) i--;
				else if(novo[2].equals("R")) i++;
				if(i >= 70) throw new IndexOutOfBoundsException();
			}	
		} catch (IndexOutOfBoundsException s) {
			if(i>=70) i--;
			else if(i<=0) i++;
		} catch (NullPointerException a) {
		}
		if(prihvatljivaStanja.contains(stanje)) prihvatljivo = 1;
		String trakaZaIspis = "";
		for(String s : traka) trakaZaIspis += s;
		System.out.println(stanje + "|" + i + "|" +trakaZaIspis + "|" + prihvatljivo);
		
	}
}
