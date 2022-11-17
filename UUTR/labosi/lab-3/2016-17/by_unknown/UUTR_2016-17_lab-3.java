import java.io.*;
import java.util.Map;
import java.util.TreeMap;

public class SimPa {

	public static void main(String[] args) throws IOException {
		
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		//1.
        String[] ulazniNizovi = reader.readLine().split("\\|");
        //2.
        String[] stanja = reader.readLine().split(",");
        //3.
        String[] abeceda = reader.readLine().split(",");
        //4.
        String[] stogZnakovi = reader.readLine().split(",");
        //5.
        String[] prihvatljivaStanja = reader.readLine().split(",");
        //6.
        String pocetnoStanje = reader.readLine();
        //7.
        String pocetnoStog = reader.readLine();
        //8.+
        String s = new String();
        TreeMap <String, Map<String, String>> prijelazi= new TreeMap<>();
        while ((s=reader.readLine()) != null) {
        	String[] prijelaz = s.split("->");
			String[] prviDio = prijelaz[0].split(",");
			String trenutnoStanje = prviDio[0];
			String prijelazniZnak = prviDio[1];
			String trenutniStog = prviDio[2];
			String novoStanje = prijelaz[1].split(",")[0];
			String noviStog = prijelaz[1].split(",")[1];
			String kljuc = trenutnoStanje+","+trenutniStog;
			Map<String, String> promjena = new TreeMap<>();
			if (prijelazi.containsKey(kljuc))
				promjena=prijelazi.get(kljuc);
			promjena.put(prijelazniZnak, novoStanje+","+noviStog);
			prijelazi.put(kljuc, promjena);
        }
        //IzracunIspisStanja
        for (String niz : ulazniNizovi) {
        	
        	String[] ulazniZnakovi = niz.split(",");
        	String ispis = new String();
        	String stog = new String();
        	ispis+=pocetnoStanje+"#"+pocetnoStog+"|";
        	stog+=pocetnoStog;
        	String trenutnoStanje = pocetnoStanje;
        	String trenutniStog = pocetnoStog;
        	
        	for (String znak : ulazniZnakovi) {
        		String kljuc=trenutnoStanje+","+trenutniStog;
        		String[] promjena;
        		while (true) {
        			kljuc=trenutnoStanje+","+trenutniStog;
    				if (!stog.equals("") && prijelazi.containsKey(kljuc)) {
    					if (prijelazi.get(kljuc).containsKey("$")) {
    						promjena = prijelazi.get(kljuc).get("$").split(",");
                			trenutnoStanje=promjena[0];
                			if (promjena[1].equals("$")) {
                				stog=stog.substring(1);
                				if (!stog.equals(""))
                						trenutniStog=stog.substring(0, 1);
                				else trenutniStog="$";
                			} else {
                				stog=promjena[1]+stog.substring(1);
                				if (!stog.equals(""))
                					trenutniStog=stog.substring(0, 1);
                				else trenutniStog="$";
                			}
                			if (!stog.equals(""))
                				ispis+=promjena[0]+"#"+stog+"|";
                			else 
                				ispis+=promjena[0]+"#"+"$"+"|";
    					} else
    						break;
    					
    				} else {
    					break;
    				}
    			}
        		if (!prijelazi.containsKey(kljuc)) {
        			ispis+="fail|";
        			break;
        		} else if (!prijelazi.get(kljuc).containsKey(znak)) {
        			ispis+="fail|";
        			break;
        		} else {
        			if (stog.equals("")) {
        				ispis+="fail|";
            			break;
        			}
        			promjena = prijelazi.get(kljuc).get(znak).split(",");
        			trenutnoStanje=promjena[0];
        			if (promjena[1].equals("$")) {
        				stog=stog.substring(1);
        				trenutniStog=stog.substring(0, 1);
        			} else {
        				stog=promjena[1]+stog.substring(1);
        				trenutniStog=stog.substring(0, 1);
        			}
        			ispis+=promjena[0]+"#"+stog+"|";
        				while (true) {
        					if (znak.equals(ulazniZnakovi[ulazniZnakovi.length-1])) {
            					boolean yes = false;
            					for (String stanje : prihvatljivaStanja) {
            						if (trenutnoStanje.equals(stanje)) {
            							yes = true;
                						break;
            						}
            						
            					}
            					if (yes) 
            						break;
            				}
                			kljuc=trenutnoStanje+","+trenutniStog;
            				if (!stog.equals("") && prijelazi.containsKey(kljuc)) {
            					if (prijelazi.get(kljuc).containsKey("$")) {
            						promjena = prijelazi.get(kljuc).get("$").split(",");
                        			trenutnoStanje=promjena[0];
                        			if (promjena[1].equals("$")) {
                        				stog=stog.substring(1);
                        				if (!stog.equals(""))
                        						trenutniStog=stog.substring(0, 1);
                        				else trenutniStog="$";
                        			} else {
                        				stog=promjena[1]+stog.substring(1);
                        				if (!stog.equals(""))
                        					trenutniStog=stog.substring(0, 1);
                        				else trenutniStog="$";
                        			}
                        			if (!stog.equals(""))
                        				ispis+=promjena[0]+"#"+stog+"|";
                        			else 
                        				ispis+=promjena[0]+"#"+"$"+"|";
            					} else
            						break;
            					
            				} else {
            					break;
            				}
            				if (znak.equals(ulazniZnakovi[ulazniZnakovi.length-1])) {
            					boolean yes = false;
            					for (String stanje : prihvatljivaStanja) {
            						if (trenutnoStanje.equals(stanje)) {
            							yes = true;
                						break;
            						}
            						
            					}
            					if (yes) 
            						break;
            				}
            					
            			}
        			
        			
        				
        		}
        	}
        	if (!ispis.endsWith("fail|")) {
        		for (String stanje : prihvatljivaStanja) {
            		if (stanje.equals(trenutnoStanje)) {
            			ispis+="1|";
            			break;
            		}
            	}
        	}
        	if (!ispis.endsWith("1|")) {
        		ispis+="0|";
        	}
        	ispis = ispis.substring(0, ispis.length()-1);
        	System.out.println(ispis);
        }
        	
        
	}
	
}
