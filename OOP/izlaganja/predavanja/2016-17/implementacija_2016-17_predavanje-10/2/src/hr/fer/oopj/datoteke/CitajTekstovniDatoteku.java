package hr.fer.oopj.datoteke;

import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.Reader;
import java.nio.charset.StandardCharsets;

public class CitajTekstovniDatoteku {

	public static void main(String[] args) throws IOException {
		String fileName = "./src/hr/fer/oopj/datoteke/KodneStranice.java";
	
		InputStream is = new FileInputStream(fileName);
		Reader reader = new InputStreamReader(is, StandardCharsets.US_ASCII);
		
		while(true) {
			int procitano = reader.read();
			if(procitano==-1) break;
			System.out.print((char)procitano);
		}

		reader.close();
	}
}
