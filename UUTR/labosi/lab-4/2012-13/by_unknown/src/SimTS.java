import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;


public class SimTS {

	private static List<String> skupStanja;
	private static List<String> skupUlaznihZnakova;
	private static List<String> skupZnakovaTrake;
	private static String znakPrazneCelije;
	private static char[] traka;
	private static List<String> skupPrihvatljivihStanja;
	private static String pocetnoStanje;
	private static int pocetniPolozajGlave;
	
	private static List<String> staroStanje;
	private static List<String> znakNaTraci;
	private static List<String> novoStanje;
	private static List<String> noviZnakNaTraci;
	private static List<String> smjer;
	
	private static boolean prihvatljivo = true;
	
	public static void main(String[] args) {
		
		Scanner reader = new Scanner(System.in, "UTF-8");
		
		skupStanja = new ArrayList<String>();
		for (String s : reader.nextLine().split(",")) {
			skupStanja.add(s);
		}
		
		skupUlaznihZnakova = new ArrayList<String>();
		for (String s : reader.nextLine().split(",")) {
			skupUlaznihZnakova.add(s);
		}
		
		skupZnakovaTrake = new ArrayList<String>();
		for (String s : reader.nextLine().split(",")) {
			skupZnakovaTrake.add(s);
		}
		
		znakPrazneCelije = reader.nextLine();
		
		traka = reader.nextLine().toCharArray();
		
		skupPrihvatljivihStanja = new ArrayList<String>();
		for (String s : reader.nextLine().split(",")) {
			skupPrihvatljivihStanja.add(s);
		}
		
		pocetnoStanje = reader.nextLine();
		
		pocetniPolozajGlave = Integer.parseInt(reader.nextLine());
		
		String temp;
		staroStanje = new ArrayList<String>();
		znakNaTraci = new ArrayList<String>();
		novoStanje = new ArrayList<String>();
		noviZnakNaTraci = new ArrayList<String>();
		smjer = new ArrayList<String>();
		
		while (reader.hasNextLine()) {
			temp = reader.nextLine();
			if (temp.isEmpty())
				break;
			String[] lijevoDesno = temp.split("->");
			String[] lijevo = lijevoDesno[0].split(",");
			String[] desno = lijevoDesno[1].split(",");
			staroStanje.add(lijevo[0]);
			znakNaTraci.add(lijevo[1]);
			novoStanje.add(desno[0]);
			noviZnakNaTraci.add(desno[1]);
			smjer.add(desno[2]);
		}
		reader.close();
		int index = pocetniPolozajGlave;
		String trenStanje = pocetnoStanje;
		
		while(prihvatljivo) {
			prihvatljivo = false;
			String trenZnak = String.valueOf(traka[index]);
			int size = staroStanje.size();
			for(int i=0; i < size; i++) {
				if(staroStanje.get(i).equals(trenStanje) && znakNaTraci.get(i).equals(trenZnak)) {
					if(index == 69 && smjer.get(i).equals("R")) {
						break;
					}
					if(index == 0 && smjer.get(i).equals("L")) {
						break;
					}
					trenStanje = novoStanje.get(i);
					traka[index] = noviZnakNaTraci.get(i).charAt(0);
					if(smjer.get(i).equals("R")) {
						index++;
					} else {
						index--;
					}
					prihvatljivo = true;
					break;
				}
			}
		}
		if(skupPrihvatljivihStanja.contains(trenStanje)) {
			System.out.println(trenStanje + "|" + index + "|" + String.valueOf(traka) + "|1");
		} else {
			System.out.println(trenStanje + "|" + index + "|" + String.valueOf(traka) + "|0");
		}
	}

}
