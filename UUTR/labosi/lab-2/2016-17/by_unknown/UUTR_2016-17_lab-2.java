import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Map;
import java.util.Map.Entry;
import java.util.TreeMap;
import java.util.TreeSet;

public class MinDka {

	public static void main(String[] args) throws IOException {
		
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		//1.
		TreeSet<String> stanja = new TreeSet<>();
		String[] skupStanja = reader.readLine().split(",");
		for (String stanje : skupStanja) {
			stanja.add(stanje);
		}
		//2.
		String[] abeceda = reader.readLine().split(",");
		//3.
		TreeSet<String> prihvatljivaStanja = new TreeSet<>();
		String[] skupPrihvatljivihStanja = reader.readLine().split(",");
		for (String stanje : skupPrihvatljivihStanja) {
			prihvatljivaStanja.add(stanje);
		}
		//4.
		String pocetnoStanje = reader.readLine();
		//5.+
		TreeMap<String,String> prijelazi = new TreeMap<>();
		String s = new String();
		while ((s=reader.readLine()) != null) {
			String[] prijelaz=s.split("->");
			prijelazi.put(prijelaz[0], prijelaz[1]);
		}
		
		//NedohvatljivaStanja
		TreeSet<String> dohvatljivaStanja = new TreeSet<>();
		dohvatljivaStanja.add(pocetnoStanje);
		int promjena=1;
		while (promjena != 0) {
			TreeSet<String> novaStanja = new TreeSet<>();
			promjena=0;
			for (String stanje : dohvatljivaStanja) {
				for (String slovo : abeceda) {
					String ulaz = stanje+","+slovo;
					if (prijelazi.containsKey(ulaz)) {
						if (!dohvatljivaStanja.contains(prijelazi.get(ulaz))){
							novaStanja.add(prijelazi.get(ulaz));
							promjena++;
						}
					}
				}
			}
			dohvatljivaStanja.addAll(novaStanja);
		}
		TreeSet<String> nedohvatljivaStanja = new TreeSet<>();
		stanja.removeAll(dohvatljivaStanja);
		nedohvatljivaStanja.addAll(stanja);
		stanja=dohvatljivaStanja;
		prihvatljivaStanja.removeAll(nedohvatljivaStanja);
		for (String stanje : nedohvatljivaStanja) {
			for (String slovo : abeceda) {
				String ulaz = stanje+","+slovo;
				if (prijelazi.containsKey(ulaz)) {
					prijelazi.remove(ulaz);
				}
			}
			for(Entry<String, String> entry : prijelazi.entrySet()) {
				if (entry.getValue()==stanje) {
					prijelazi.remove(entry.getKey());
				}
			}
		}
		
		//IstovjetnaStanja
		TreeMap<String,Boolean> tablica = new TreeMap<>();
		TreeSet<String> istovjetnaStanja = new TreeSet<>();
		String[] tmpStanja = stanja.toArray(new String[0]);
		for (int i=0; i<tmpStanja.length-1; ++i) {
			for (int j=i+1; j<tmpStanja.length; ++j) {
				String kombinacija = tmpStanja[i]+","+tmpStanja[j];
				if (prihvatljivaStanja.contains(tmpStanja[i])) {
					if (!prihvatljivaStanja.contains(tmpStanja[j])) {
						tablica.put(kombinacija, true);
					} else
						tablica.put(kombinacija, false);
				} else if (prihvatljivaStanja.contains(tmpStanja[j])) {
					if (!prihvatljivaStanja.contains(tmpStanja[i])) {
						tablica.put(kombinacija, true);
					} else
						tablica.put(kombinacija, false);
				} else
					tablica.put(kombinacija, false);
			}
		}
		for (int i=0; i<tmpStanja.length-1; ++i) {
			for (int j=i+1; j<tmpStanja.length; ++j) {
				for (String slovo : abeceda) {
					String ulazI = tmpStanja[i]+","+slovo;
					String ulazJ = tmpStanja[j]+","+slovo;
					TreeSet<String> novaKombinacija = new TreeSet<>();
					novaKombinacija.add(prijelazi.get(ulazI));
					novaKombinacija.add(prijelazi.get(ulazJ));
					if (novaKombinacija.size()==2) {
						String kombinacija = new String();
						for (String stanje : novaKombinacija) {
							 kombinacija += stanje+",";
						}
						kombinacija=kombinacija.substring(0, kombinacija.length()-1);
						if (tablica.get(kombinacija)==true) {
							kombinacija=tmpStanja[i]+","+tmpStanja[j];
							tablica.put(kombinacija, true);
						}
					}
				}
			}
		}
		for (Map.Entry<String, Boolean> entry : tablica.entrySet()) {
			String[] parStanja = entry.getKey().split(",");
			if (!parStanja[0].equals(parStanja[1])) {
				if (entry.getValue()==false) {
					istovjetnaStanja.add(parStanja[1]);
					for (Map.Entry<String, String> ulaz : prijelazi.entrySet()) {
						if (ulaz.getValue().equals(parStanja[1]))
							ulaz.setValue(parStanja[0]);
					}
					if (pocetnoStanje.equals(parStanja[1]))
						pocetnoStanje=parStanja[0];
				}
			}
		}
		stanja.removeAll(istovjetnaStanja);
		prihvatljivaStanja.removeAll(istovjetnaStanja);
		for (String stanje : istovjetnaStanja) {
			for (String slovo : abeceda) {
				String ulaz = stanje+","+slovo;
				if (prijelazi.containsKey(ulaz)) {
					prijelazi.remove(ulaz);
				}
			}
			for(Entry<String, String> entry : prijelazi.entrySet()) {
				if (entry.getValue()==stanje) {
					prijelazi.remove(entry.getKey());
				}
			}
		}
		
		//Ispis
		String ispis = new String();
		for (String stanje : stanja) {
			ispis += stanje+",";
		}
		ispis=ispis.substring(0,ispis.length()-1);
		System.out.println(ispis);
		ispis="";
		for (String slovo : abeceda) {
			ispis += slovo+",";
		}
		ispis=ispis.substring(0,ispis.length()-1);
		System.out.println(ispis);
		ispis="";
		if (!prihvatljivaStanja.isEmpty()){
			for (String stanje : prihvatljivaStanja) {
				ispis += stanje+",";
			}
			ispis=ispis.substring(0,ispis.length()-1);
		}
		System.out.println(ispis);
		ispis="";
		System.out.println(pocetnoStanje);
		for(Entry<String, String> entry : prijelazi.entrySet()) {
			ispis += entry.getKey()+"->"+entry.getValue();
			System.out.println(ispis);
			ispis="";
		}
	}
	
}
