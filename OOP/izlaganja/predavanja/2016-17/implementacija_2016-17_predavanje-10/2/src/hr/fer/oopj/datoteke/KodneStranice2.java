package hr.fer.oopj.datoteke;

import java.io.BufferedReader;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.Reader;
import java.nio.charset.StandardCharsets;

public class KodneStranice2 {

	public static void main(String[] args) throws IOException {
		String text = "Šišćevapčići šeću šumom.";
		
		byte[] okteti = text.getBytes(StandardCharsets.UTF_8);
		
		String novi = new String(okteti, StandardCharsets.UTF_8);
		System.out.println(novi);

		InputStream is = new ByteArrayInputStream(okteti);
		Reader reader = new InputStreamReader(is, StandardCharsets.UTF_8);
		BufferedReader br = new BufferedReader(reader);
		
		System.out.println(br.readLine());
		
		
	}
}
