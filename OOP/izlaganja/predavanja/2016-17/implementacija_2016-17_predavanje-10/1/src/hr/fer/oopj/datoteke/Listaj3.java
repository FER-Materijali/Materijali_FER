package hr.fer.oopj.datoteke;

import java.io.File;
import java.io.IOException;

public class Listaj3 {

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

		try {
			listajRekurzivno(direktorij, 0);
		} catch (IOException e) {
			System.out.println("Došlo je do pogreške pri obilasku. Daljnji ispis je prekinut.");
		}
				
	}

	private static void listajRekurzivno(File direktorij, int dubina) throws IOException {
		if(dubina == 0) {
			System.out.println(direktorij.getCanonicalPath());
		} else {
			System.out.printf("%"+(dubina*2)+"s%s%n", "", direktorij.getName());
		}
		for(File dijete : direktorij.listFiles()) {
			if(dijete.isFile()) {
				System.out.printf("%"+((dubina+1)*2)+"s%s%n", "", dijete.getName());
				continue;
			}
			if(dijete.isDirectory()) {
				listajRekurzivno(dijete, dubina+1);
			}
		}
	}

}
