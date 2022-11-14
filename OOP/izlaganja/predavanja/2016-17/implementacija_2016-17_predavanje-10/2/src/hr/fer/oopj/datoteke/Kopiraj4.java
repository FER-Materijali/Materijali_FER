package hr.fer.oopj.datoteke;

import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;

public class Kopiraj4 {

	public static void main(String[] args) {
		String srcFile = "./src/hr/fer/oopj/datoteke/Kopiraj4.java";
		String dstFile = "./Kopiraj4-kopija.java";
		
		try(
			InputStream is = new BufferedInputStream(new FileInputStream(srcFile));
			OutputStream os = new BufferedOutputStream(new FileOutputStream(dstFile))
		) {
			byte[] spremnik = new byte[1024];
			while(true) {
				int procitano = is.read(spremnik);
				if(procitano==-1) break;
				os.write(spremnik, 0, procitano);
			}
		} catch(FileNotFoundException ex) {
			System.out.println("Dragi korisniče, datoteka se ne mopže koristiti. Detalji: "+ex.getMessage());
		} catch(IOException ex) {
			System.out.println("Došlo je do pogreške pri kopiranju.");
		}
	}
	
}
