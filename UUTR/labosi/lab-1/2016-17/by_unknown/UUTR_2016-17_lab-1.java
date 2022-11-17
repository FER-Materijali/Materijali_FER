import java.io.*;
import java.util.Map;
import java.util.TreeMap;
import java.util.TreeSet;

public class SimEnka {

	public static void main(String[] args) throws IOException {
		
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		//1.
        String[] ulazniNizovi = reader.readLine().split("\\|");
        //2.
        String[] stanja = reader.readLine().split(",");
        //3.
        String[] abeceda = reader.readLine().split(",");
        //4.
        String[] prihvatljivaStanja = reader.readLine().split(",");
        //5.
        String pocetnoStanje = reader.readLine();
        //6+.
        String s = new String();
        TreeMap <String, Map<String, String[]>> prijelazi= new TreeMap<>();
        while ((s=reader.readLine()) != null) {
			String[] prijelaz = s.split("->");
			String[] prviDio = prijelaz[0].split(",");
			String trenutnoStanje = prviDio[0];
			String prijelazniZnak = prviDio[1];
			String[] novaStanja = prijelaz[1].split(",");
			Map<String, String[]> promjena = new TreeMap<>();
			if (prijelazi.containsKey(trenutnoStanje))
				promjena=prijelazi.get(trenutnoStanje);
			promjena.put(prijelazniZnak, novaStanja);
			prijelazi.put(trenutnoStanje, promjena);	
        }
        //IzracunIspisStanja
        for (String niz : ulazniNizovi) {
        	String ispis = new String();
        	String[] ulazniZnakovi = niz.split(",");
        	TreeSet<String> trenutnaStanja = new TreeSet<>();
        	trenutnaStanja.add(pocetnoStanje);
        	TreeSet<String> sljedecaStanja = new TreeSet<>();
        	for (String znak : ulazniZnakovi) {
        		if (!trenutnaStanja.contains("#")) {
        			//epsilon prijelazi
        			int promjena = 1;
        			while (promjena != 0) {
        				TreeSet<String> novaStanja = new TreeSet<>();
        				promjena=0;
        				for (String stanje : trenutnaStanja) {
        					if (prijelazi.containsKey(stanje)) {
        						if (prijelazi.get(stanje).containsKey("$")) {
        							for (String epsilonStanje : prijelazi.get(stanje).get("$")) {
        								if (!trenutnaStanja.contains(epsilonStanje)) {
        									if (!epsilonStanje.equals("#")) {
        										novaStanja.add(epsilonStanje);
        										promjena++;
        									}
        								}
        							}
        						}
        					}
        				}
        				trenutnaStanja.addAll(novaStanja);
        			}
        		}
        		//stanja u ispis
    			for (String stanje : trenutnaStanja) {
    				ispis += stanje + ',';
    			}
    			ispis = ispis.substring(0, ispis.length()-1);
    			ispis += '|';
    			//sljedeca stanja
    			if (!trenutnaStanja.contains("#")) { 
    				for (String stanje : trenutnaStanja) {
    					if (prijelazi.containsKey(stanje)) {
    						if (prijelazi.get(stanje).containsKey(znak)) {
    							for (String sljedStanje : prijelazi.get(stanje).get(znak)) {
    								if (!sljedecaStanja.contains(sljedStanje)) {
    									if (!sljedStanje.equals("#")) {
    										sljedecaStanja.add(sljedStanje);
    									} 
    								}
    							}
    						}
    					}
    				}
    			}
    			sljedecaStanja.remove("#");
    			if (sljedecaStanja.isEmpty()) {
    				sljedecaStanja.add("#");
    			}
    			trenutnaStanja.removeAll(trenutnaStanja);
    			trenutnaStanja.addAll(sljedecaStanja);
    			sljedecaStanja.removeAll(sljedecaStanja);
        	}
        	if (!trenutnaStanja.contains("#")) {
    			int promjena = 1;
    			while (promjena != 0) {
    				TreeSet<String> novaStanja = new TreeSet<>();
    				promjena=0;
    				for (String stanje : trenutnaStanja) {
    					if (prijelazi.containsKey(stanje)) {
    						if (prijelazi.get(stanje).containsKey("$")) {
    							for (String epsilonStanje : prijelazi.get(stanje).get("$")) {
    								if (!trenutnaStanja.contains(epsilonStanje)) {
    									if (!epsilonStanje.equals("#")) {
    										novaStanja.add(epsilonStanje);
    										promjena++;
    									}
    								}
    							}
    						}
    					}
    				}
    				trenutnaStanja.addAll(novaStanja);
    			}
    		}
        	for (String stanje : trenutnaStanja) {
				ispis += stanje + ',';
			}
        	ispis = ispis.substring(0, ispis.length()-1);
        	System.out.println(ispis);
        }
	}

	
}
