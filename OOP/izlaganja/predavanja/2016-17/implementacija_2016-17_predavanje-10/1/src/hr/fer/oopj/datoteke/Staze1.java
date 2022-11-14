package hr.fer.oopj.datoteke;

import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;

public class Staze1 {

	public static void main(String[] args) {
		Path staza = Paths.get(".");
		
		boolean postoji = Files.exists(staza);
		System.out.println(staza.normalize().toAbsolutePath());
	}
}
