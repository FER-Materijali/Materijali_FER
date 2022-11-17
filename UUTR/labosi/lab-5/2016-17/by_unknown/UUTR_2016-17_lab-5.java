import java.io.*;
import java.util.ArrayList;
import java.util.Map;
import java.util.TreeMap;

public class SimTS {
	
	public static void main(String[] args) throws IOException {
		
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		String[] stanja = reader.readLine().split(",");
		String[] ulazniZnakovi = reader.readLine().split(",");
		String[] znakoviTrake = reader.readLine().split(",");
		String znakPrazneCelije = reader.readLine();
		String traka = reader.readLine();
		ArrayList<String> znakoviNaTraci = new ArrayList<>();
		for (char c : traka.toCharArray()) {
			znakoviNaTraci.add(String.valueOf(c));
		}
		String[] prihvatljivaStanja = reader.readLine().split(",");
		String pocetnoStanje = reader.readLine();
		Integer pocetniPolozajGlave = Integer.parseInt(reader.readLine());
		String s = new String();
		TreeMap <String, String> prijelazi= new TreeMap<>();
		while ((s=reader.readLine()) != null) {
			prijelazi.put(s.split("->")[0], s.split("->")[1]);
		}
		String kljuc = pocetnoStanje+","+znakoviNaTraci.get(pocetniPolozajGlave);
		String trenutnoStanje = pocetnoStanje;
		Integer trenutniPolozaj = pocetniPolozajGlave;
		while (prijelazi.containsKey(kljuc)) {
			String pomak = prijelazi.get(kljuc).split(",")[2];
			if (trenutniPolozaj.equals(0) && pomak.equals("L") || trenutniPolozaj.equals(69) && pomak.equals("R"))
				break;
			trenutnoStanje=prijelazi.get(kljuc).split(",")[0];
			znakoviNaTraci.set(trenutniPolozaj, prijelazi.get(kljuc).split(",")[1]);
			if (prijelazi.get(kljuc).split(",")[2].equals("L"))
				trenutniPolozaj--;
			else
				trenutniPolozaj++;
			kljuc = trenutnoStanje + "," + znakoviNaTraci.get(trenutniPolozaj);	
		}
		traka="";
		for (String znak : znakoviNaTraci) {
			traka+=znak;
		}
		String ispis=trenutnoStanje+"|"+trenutniPolozaj+"|"+traka+"|";
		for (String stanje : prihvatljivaStanja) {
			if (stanje.equals(trenutnoStanje)) {
				ispis+="1";
				break;
			}
		}
		if (ispis.endsWith("|"))
			ispis+="0";
		System.out.println(ispis);
		
	}

}
