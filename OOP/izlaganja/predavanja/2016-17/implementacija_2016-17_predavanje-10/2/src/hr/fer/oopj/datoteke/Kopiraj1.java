package hr.fer.oopj.datoteke;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;

public class Kopiraj1 {

	public static void main(String[] args) {
		String srcFile = "./src/hr/fer/oopj/datoteke/Kopiraj1.java";
		String dstFile = "./Kopiraj1-kopija.java";
		InputStream is = null;
		try {
			is = new FileInputStream(srcFile);
		} catch(FileNotFoundException ex) {
			System.out.println("Dragi korisniče, izvorne datoteke "+srcFile+" nema.");
			return;
		}

		OutputStream os = null;
		try {
			os = new FileOutputStream(dstFile);
		} catch(FileNotFoundException ex) {
			System.out.println("Dragi korisniče, odredišnu datoteku "+dstFile+" ne možemo stvoriti.");
			try { is.close(); } catch(IOException ignorable) {}
			return;
		}

		try {
			while(true) {
				int oktet = is.read();
				if(oktet==-1) break;
				os.write(oktet);
			}
		} catch(IOException ex) {
			System.out.println("Došlo je do pogreške pri kopiranju.");
		} finally {
			try { os.close(); } catch(IOException ignorable) {}
			try { is.close(); } catch(IOException ignorable) {}
		}
		
	}
	
}
