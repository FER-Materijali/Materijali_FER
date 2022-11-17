package utr1;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class E_nka {

	public static void main(String[] args) throws IOException {
		
		BufferedReader bf = new BufferedReader(new FileReader("test2.txt"));

		String[] ulazniNiz = bf.readLine().trim().split("\\|");
		String[] skupStanja = bf.readLine().trim().split(",");   
		String[] skupSimbola = bf.readLine().trim().split(",");
		String[] skupPrihvatljivhStanja =  bf.readLine().trim().split(",");
		String pocetnoStanje= bf.readLine().trim();
		//lista prijelaza, slicna kao  polje ali daje vise funkcija
		List<Prijelazi> fPrijelaza = new ArrayList<>();
		String line;
		//ovdje nastvljamo od 6. reda citati red po red i spremamo to u listu, to su liste prijleaza
		while ( (line = bf.readLine()) != null ){
			fPrijelaza.add(new Prijelazi(line));
		}
		//ovdje vrtimo kljucni dio, prvo niz po niz, pa onda po za svaki simbol se pitamo da li postoji prijelaz, 
		//ako je postojao prijelaz onda provjera postoji li epislon prijlazi, i tako sve ukrug
		for(String ulazniPodniz: ulazniNiz){
			String[] trenutnaStanja = new String[]{pocetnoStanje};
			printPolje(trenutnaStanja);
			String[] trenutniNiz = ulazniPodniz.split(",");
			String[] novaStanja = null;
			String[] sumaNovihStanja = null;
			
			for(String trenutniSimbol: trenutniNiz){
				boolean pronasaoPrijelaz = false;
				for(String trenutnoStanje: trenutnaStanja){
					if (potoji_li_prijelaz(trenutnoStanje, trenutniSimbol, fPrijelaza)){
						novaStanja = daj_mi_nova_stanja(trenutnoStanje, trenutniSimbol, fPrijelaza);
						pronasaoPrijelaz = true;
					}
				}
				

				//epsilon prijelazi
				if(pronasaoPrijelaz){
					for(int i = novaStanja.length-1; i >= 0; i--){
						if(potoji_li_prijelaz(novaStanja[i],"$", fPrijelaza)){
							int staraDuljina = novaStanja.length;
							novaStanja = zbroji_dva_polja( daj_mi_nova_stanja(novaStanja[i], "$", fPrijelaza),novaStanja);
							i += novaStanja.length - staraDuljina-1;
						}
					}
					
					//printPolje(novaStanja);
					sumaNovihStanja = zbroji_dva_polja(sumaNovihStanja, novaStanja);
					trenutnaStanja = novaStanja;
					printPolje(trenutnaStanja);
				}
				else{
					trenutnaStanja = new String[]{"#"};
					System.out.print("|#");
				}
				
			}

				System.out.println();
		
			
		}
		bf.close();
	}

	private static String[] zbroji_dva_polja (String[] polje1, String[] polje2){
		int duljina1, duljina2;
		if(polje1 == null){
			duljina1 = 0;
		}
		else{
			duljina1 = polje1.length;
		}
		if(polje2 == null){
			duljina2 = 0;
		}
		else{
			duljina2 = polje2.length;
		}
		String[] pom = new String[duljina1+duljina2]; 
		int index = 0;
		for(int j = 0; j < duljina1; j++){
			pom[j] = polje1[j];
			index++;
		}
		for(int j = 0; j < duljina2; j++){
			pom[j+index] = polje2[j];
		}
		return pom;
	}
	
	
	private static String[] daj_mi_nova_stanja(String trenutnoStanje, String trenutniSimbol, List<Prijelazi> fPrijelaza) {
		for (Prijelazi trenutniPrijelaz: fPrijelaza){
			if(trenutniPrijelaz.postojiPrijelaz(trenutnoStanje, trenutniSimbol)){
				return trenutniPrijelaz.getSkupStanja(trenutnoStanje, trenutniSimbol);
			}
		}		
		return null;
		
	}

	private static boolean  potoji_li_prijelaz(String trenutnoStanje, String trenutniSimbol, List<Prijelazi> fPrijelaza) {
		for (Prijelazi trenutniPrijelaz: fPrijelaza){
			if(trenutniPrijelaz.postojiPrijelaz(trenutnoStanje, trenutniSimbol)){
				return true;
			}
		}		
		return false;
	}



	private static void printPolje(String[] string){
		if(string.length == 0)
			return;
		System.out.print("|");
		int i = 0;
		for(int j = 0; j < string.length; j++){
			if(i == 0){
				System.out.print(string[j]);
				i++;
				continue;
			}
			System.out.print(","+string[j]);
		}
	}

	
}
