package hr.fer.oopj.datoteke;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.StringReader;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.List;

public class CitanjeDatoteke2 {

	public static void main(String[] args) throws IOException {
		String fileName = "./src/hr/fer/oopj/datoteke/KodneStranice.java";

		Path staza = Paths.get(fileName);
		List<String> retci = Files.readAllLines(staza, StandardCharsets.UTF_8);
		
		byte[] okteti = Files.readAllBytes(staza);
		
		String text = new String(okteti, StandardCharsets.UTF_8);
		System.out.println(text);
		
		BufferedReader br = new BufferedReader(new StringReader(text));
		
		for(int i = 0; i < 3; i++) {
			System.out.println(br.readLine());
		}
	}
}
