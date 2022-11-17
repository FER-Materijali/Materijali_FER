import java.io.*;
import java.util.*;


public class ekoder {

	public ekoder() {
		// TODO Auto-generated constructor stub
	}

	

	/**
	 * @param args
	 */
    @SuppressWarnings("unchecked")
	public static void main(String[] args) 
	throws IOException, IllegalArgumentException
	{
		if (args.length != 3) {
			throw new IllegalArgumentException ("UPORABA: java ekoder putanja_do_izvorista/izvoriste1.txt putanja_do_izlaza/ekoderOut.txt putanja_do_koda/ekoderCode.txt");
		}

        //Uèitavanje iz datoteke zadane parametrom
		    File f = new File(args[0]);
		    Scanner input = new Scanner( f );
            input.useDelimiter("");
        //HashMap spremanje znakova iz datoteke
            HashMap<Character, Integer> znakovi = new HashMap<Character, Integer>();
            Queue<Character> ulazniZnakovi = new LinkedList<Character>();
            HashMap<Character, Double> vjerojatnosti = new HashMap<Character, Double>();
            char znak = ' ';
            int koliko = 0;
        //Èitanje i spremanje svakog znaka u HashMap
            while (input.hasNext()) {
                znak = input.next().charAt(0);
                ulazniZnakovi.add(znak);
                koliko++;
                if (znakovi.containsKey(znak)) {
                    znakovi.put(znak, znakovi.get(znak)+1);
                } else {
                    znakovi.put(znak, 1);
                }
            }
        //Izraèunavanje vjerojatnosti
            double vjerojatnost = 0;

            for (Map.Entry<Character, Integer> item : znakovi.entrySet()) {
                vjerojatnost = (double)item.getValue() / (double)koliko;
                vjerojatnosti.put(item.getKey(), vjerojatnost);
                //System.out.println(item.getKey() + "=>" +item.getValue()+" "+koliko);
            }
        //Uzlazno sortiranje vjerojatnosti
            vjerojatnosti = sortHashMapByValues(vjerojatnosti,"cd");
        //Spremanje kodova u listu kao String - inicijalizacija
            Map<Character, String> kodovi = new LinkedHashMap<Character, String>();
            HashMap<String, Double> tempVjerojatnosti = new HashMap<String, Double>();
            for (Map.Entry<Character, Double> item : vjerojatnosti.entrySet()) {
                kodovi.put(item.getKey(), "");
                tempVjerojatnosti.put(item.getKey().toString(),item.getValue());
            }
        //Sortiranje prije prve iteracije kodiranja
            tempVjerojatnosti = sortHashMapByValues(tempVjerojatnosti,"sd");
        //Huffmanovo kodiranje
            while (!tempVjerojatnosti.isEmpty()) {

                Map.Entry<String, Double> prviZnak = tempVjerojatnosti.entrySet().iterator().next();
                tempVjerojatnosti.remove(prviZnak.getKey());

                try {
                    Map.Entry<String, Double> drugiZnak = tempVjerojatnosti.entrySet().iterator().next();
                    tempVjerojatnosti.remove(drugiZnak.getKey());

                    String noviZnakKey = prviZnak.getKey() + drugiZnak.getKey();
                    Double noviZnakValue = prviZnak.getValue() + drugiZnak.getValue();
                    tempVjerojatnosti.put(noviZnakKey, noviZnakValue);

                    //Uzlazno sortiranje vjerojatnosti za sljedeæu iteraciju kodiranja
                        tempVjerojatnosti = sortHashMapByValues(tempVjerojatnosti,"sd");
                    //Pridruživanje kodova trenutnim znakovima

                        String trenutniPrvi = prviZnak.getKey();
                        String trenutniDrugi = drugiZnak.getKey();

                        for (int i = 0; i < trenutniPrvi.length(); i++) {
                            String trenutniKod = kodovi.get(trenutniPrvi.charAt(i));
                            kodovi.put(trenutniPrvi.charAt(i), "0" + trenutniKod);
                        }

                        for (int i = 0; i < trenutniDrugi.length(); i++) {
                            String trenutniKod = kodovi.get(trenutniDrugi.charAt(i));
                            kodovi.put(trenutniDrugi.charAt(i), "1" + trenutniKod);
                        }

                    //System.out.println(kodovi);

                } catch (Exception ex) {
                    //System.out.println(ex);
                    //Moguæe je da drugiZnak ne postoji, pa time znamo da smo stigli do kraja
                }
            }
        //Zapisivanje u datoteku ecoderOut.txt - izlazna struja bitova - zadano na args[1]
            {
                FileWriter fstream = new FileWriter(args[1]);
                BufferedWriter out = new BufferedWriter(fstream);

                while (!ulazniZnakovi.isEmpty()) {
                    Character trenutniUlazniZnak = ulazniZnakovi.poll();
                    if (trenutniUlazniZnak != null) {
                        out.write( kodovi.get(trenutniUlazniZnak) );
                    }
                }

                out.close();
            }
        //Zapisivanje u datoteku ecoderCode.txt - izlazna abeceda - zadano na args[2]
            {
                FileWriter fstream = new FileWriter(args[2]);
                BufferedWriter out = new BufferedWriter(fstream);
                while (!kodovi.isEmpty()) {
                    Map.Entry<Character, String> kod = kodovi.entrySet().iterator().next();
                    kodovi.remove(kod.getKey());
                    out.write(kod.getKey() + "=" + kod.getValue());
                    if (!kodovi.isEmpty()) {
                        out.write("\r\n");
                    }
                }
                out.close();
            }
		//Zatvaranje scannera
		    input.close();
	}

    @SuppressWarnings("unchecked")
    private static LinkedHashMap sortHashMapByValues(HashMap passedMap, String type) {
        List mapKeys = new ArrayList(passedMap.keySet());
        List mapValues = new ArrayList(passedMap.values());
        Collections.sort(mapValues);


        //Posebno prefiksno sortiranje zbog toga što u sluèaju jednakih vjerojatnosti, združene nemaju prednost nad zasebnim znakovima
        if (type == "sd") {
            int najdulji = 0;
            for (int i = 0; i < mapKeys.size(); i++) {
                if (mapKeys.get(i).toString().length() > najdulji)
                {
                    najdulji = mapKeys.get(i).toString().length();
                }
            }
            //System.out.println(mapKeys);
            //System.out.println(najdulji);


            for (int i = 0; i < mapKeys.size(); i++) {
                String trenutni = mapKeys.get(i).toString();
                for (int j = trenutni.length(); j< najdulji; j++)
                {
                    mapKeys.set(i, '#' + mapKeys.get(i).toString());
                }

            }
            //System.out.println(mapKeys);

            Collections.sort(mapKeys);

            for (int i = 0; i < mapKeys.size(); i++) {
                mapKeys.set(i, mapKeys.get(i).toString().replaceAll("#",""));
            }
            //System.out.println(mapKeys);


        }

        if (type == "cd") {
            Collections.sort(mapKeys);
        }

        LinkedHashMap sortedMap =
                new LinkedHashMap();

        Iterator valueIt = mapValues.iterator();
        while (valueIt.hasNext()) {
            Object val = valueIt.next();
            Iterator keyIt = mapKeys.iterator();

            while (keyIt.hasNext()) {
                Object key = keyIt.next();
                String comp1 = passedMap.get(key).toString();
                String comp2 = val.toString();

                if (comp1.equals(comp2)){
                    passedMap.remove(key);
                    mapKeys.remove(key);
                    if (type == "cd")
                    {
                        sortedMap.put((Character)key, (Double)val);
                    }
                    else
                    {
                        sortedMap.put((String)key, (Double)val);
                    }

                    break;
                }

            }

        }
        return sortedMap;
    }

    public static <K, V>  Object getKey(Map<K, V> in,V value)
    {
        Set<K> key= in.keySet();
        Iterator<K> keyIterator=key.iterator();
        while (keyIterator.hasNext()) {
            K valueObject = (K) keyIterator.next();
            if(in.get(valueObject).equals(value))
            {
                return valueObject;
            }
        }
        return null;
    }

}