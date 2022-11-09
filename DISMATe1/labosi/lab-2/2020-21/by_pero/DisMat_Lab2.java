import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class DisMat_Lab2 {
	static int brojVrhova;
	static boolean nasaoCiklus = false;
	
	public static void main(String[] args) {
		// ucitavanje iz datoteke
		String fileName;
		try(Scanner consoleScanner = new Scanner(System.in)) {
			System.out.println("Unesite ime datoteke: ");
			fileName = consoleScanner.nextLine();
		}
		
		File inputFile = new File(fileName);
		Scanner fileScanner = null;
		try {
			fileScanner = new Scanner(inputFile);
		} catch (FileNotFoundException ex) {
			System.err.println("Datoteka ne postoji");
			return;
		}
		
		brojVrhova = Integer.parseInt(fileScanner.nextLine());
		int[][] graf = new int[brojVrhova][brojVrhova];
		fileScanner.nextLine(); // preskacemo praznu liniju
		
		for(int i = 0; i < brojVrhova; i++) { // popunjavanje matrice
			String[] data = fileScanner.nextLine().split(" ");
			
			for(int j = 0; j < brojVrhova; j++) {
				graf[i][j] = Integer.parseInt(data[j]);
			}
		}
		
		fileScanner.close();
		
		// Trazenje najduljeg ciklusa
		// Za i iz intervala [3, n] ispitujemo postoji li u grafu ciklus duljine i.
		// Kada nademo ciklus, petlja se prekida
		int i;
		for(i = brojVrhova; i > 2; i--) {
			nasaoCiklus = false;
			if(nadjiCiklus(graf, i)) break;
		}
		
		if(i <= 2) {
			System.out.println(0); // nema ciklusa
		} else {
			System.out.println(i); // najdulji ciklus je duljine i
		}
	}
	
	static boolean nadjiCiklus(int graf[][], int n) {
		boolean[] posjeceni = new boolean[brojVrhova]; // polje za pracenje vrhova koje smo posjetili		
		
		// trazimo ciklus kroz svaki vrh
		for (int i = 0; i < brojVrhova; i++) {
			if(nasaoCiklus) return true;
			
            DFS(graf, posjeceni, n-1, i, i); 
              
            posjeceni[i] = true;
        }
		
		return nasaoCiklus;
	}
	
	// koristimo DFS da pronademo sve staze duljine n - 1 u grafu, 
	// a za svaku pronadenu stazu provjerimo zatvara li ciklus s pocetnim vrhom
	static void DFS(int graf[][], boolean[] posjeceni, int n, int vrh, int pocetni) {
		posjeceni[vrh] = true;
		
		if(n == 0) { // pronadena je staza duljine n - 1
			posjeceni[vrh] = false;
			
			// provjeri moze li se zatvoriti ciklus
			if(graf[vrh][pocetni] == 1) {
				nasaoCiklus = true;
			}
			
			return;
		}
		
		for(int i = 0; i < brojVrhova; i++) {
			if(nasaoCiklus) return;
			
			if(!posjeceni[i] && graf[vrh][i] == 1) {
				DFS(graf, posjeceni, n - 1, i, pocetni);
			}
		}
		
		posjeceni[vrh] = false;
	}
}
