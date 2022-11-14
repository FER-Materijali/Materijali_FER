package hr.fer.oopj.datoteke;

import java.io.File;

public class Listaj {

	public static void main(String[] args) {
		if(args.length != 1) {
			System.out.println("Dragi korisniče, ...");
			return;
		}
		
		String imeDirektorija = args[0];
		File direktorij = new File(imeDirektorija);
		
		if(!direktorij.isDirectory()) {
			System.out.println("Dragi korisniče, ..");
			return;
		}
		
		String[] djeca = direktorij.list();
		if(djeca == null) {
			System.out.printf("Objekt %s se ne da čitati.%n", direktorij);
			return;
		}
		for(String dijete : djeca) {
			System.out.printf("%s %s%n", new File(direktorij, dijete).isDirectory() ? " [DIR]" : "[FILE]", dijete);
		}
		
		
	}

}
