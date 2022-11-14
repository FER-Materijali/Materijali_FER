package hr.fer.oopj.datoteke;

import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;

public class Kopiraj3 {

	public static void main(String[] args) {
		String srcFile = "./src/hr/fer/oopj/datoteke/Kopiraj2.java";
		String dstFile = "./Kopiraj2-kopija.java";
		
		try(
			InputStream is = new BufferedInputStream(new FileInputStream(srcFile));
			OutputStream os = new BufferedOutputStream(new FileOutputStream(dstFile))
		) {
			while(true) {
				int oktet = is.read();
				if(oktet==-1) break;
				os.write(oktet);
			}
		} catch(FileNotFoundException ex) {
			System.out.println("Dragi korisniče, datoteka se ne mopže koristiti. Detalji: "+ex.getMessage());
		} catch(IOException ex) {
			System.out.println("Došlo je do pogreške pri kopiranju.");
		}
	}
	
}
