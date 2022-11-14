package hr.fer.oopj.datoteke;

import java.io.File;

public class Listaj2 {

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
		
		File[] djeca = direktorij.listFiles();
		if(djeca == null) {
			System.out.printf("Objekt %s se ne da čitati.%n", direktorij);
			return;
		}
		for(File dijete : djeca) {
			System.out.printf("%s %s%n", dijete.isDirectory() ? " [DIR]" : "[FILE]", dijete);
		}
		
		
	}

}
