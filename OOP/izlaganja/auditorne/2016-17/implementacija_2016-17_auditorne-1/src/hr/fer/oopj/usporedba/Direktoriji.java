package hr.fer.oopj.usporedba;

import java.io.IOException;
import java.nio.file.FileVisitResult;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.SimpleFileVisitor;
import java.nio.file.attribute.BasicFileAttributes;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Direktoriji {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		Path prvi = unesiDirektorij("prvi", sc);
		Path drugi = unesiDirektorij("drugi", sc);

		Trckalo v1 = new Trckalo(prvi.toString());
		Trckalo v2 = new Trckalo(drugi.toString());
		
		try {
			Files.walkFileTree(prvi, v1);
			Files.walkFileTree(drugi, v2);
		} catch(IOException ex) {
			System.out.println("Greška pri oblikasku direktorija. Detalji: " + ex.getMessage());
			return;
		}
	
		if(v1.objekti.isEmpty() && v2.objekti.isEmpty()) {
			System.out.println("Direktoriji su jednaki!");
			return;
		}
		
		double postotak = usporedi(v1.objekti, v2.objekti);
		
		System.out.println("Postotak slicnosti je: " + postotak);
		
	}

	private static double usporedi(Map<String, Long> mapa1, Map<String, Long> mapa2) {
		int brojIstihZapisa = 0;
		for(Map.Entry<String, Long> par : mapa1.entrySet()) {
			Long vrijednost2 = mapa2.get(par.getKey());
			if(vrijednost2!=null && par.getValue().equals(vrijednost2)) {
				brojIstihZapisa++;
			}
		}
		return brojIstihZapisa / (double)(mapa1.size() + mapa2.size() - brojIstihZapisa) * 100;
	}

	private static Path unesiDirektorij(String kojiDirektorij, Scanner sc) {
		while(true) {
			System.out.print("Molim unesite "+kojiDirektorij+": ");
			String unos = sc.nextLine();
			Path direktorij = Paths.get(unos);
			if(!Files.isDirectory(direktorij)) {
				System.out.println("Morate unijeti direktorij!!!");
				continue;
			}
			return direktorij;
		}
	}
	
	private static class Trckalo extends SimpleFileVisitor<Path> {
		private String korijenskaStaza;
		private Map<String, Long> objekti = new HashMap<>();
		
		public Trckalo(String korijenskaStaza) {
			super();
			this.korijenskaStaza = korijenskaStaza;
		}
		
		@Override
		public FileVisitResult preVisitDirectory(Path dir, BasicFileAttributes attrs) throws IOException {
			String putanja = dir.toString();
			if(putanja.equals(korijenskaStaza)) return FileVisitResult.CONTINUE;
			String relativnoIme =putanja.substring(korijenskaStaza.length());
			objekti.put(relativnoIme, -1L);
			return FileVisitResult.CONTINUE;
		}
		
		@Override
		public FileVisitResult visitFile(Path file, BasicFileAttributes attrs) throws IOException {
			String putanja = file.toString();
			String relativnoIme = putanja.substring(korijenskaStaza.length());
			objekti.put(relativnoIme, attrs.size());
			return FileVisitResult.CONTINUE;
		}		
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}
