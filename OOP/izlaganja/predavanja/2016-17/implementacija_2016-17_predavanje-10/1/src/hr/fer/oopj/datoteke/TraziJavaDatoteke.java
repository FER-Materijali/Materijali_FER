package hr.fer.oopj.datoteke;

import java.io.IOException;
import java.nio.file.FileVisitResult;
import java.nio.file.FileVisitor;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.attribute.BasicFileAttributes;
import java.util.ArrayList;
import java.util.List;

public class TraziJavaDatoteke {

	private static class Trazilica implements FileVisitor<Path> {
		
		private List<Path> pronadeneDatoteke = new ArrayList<>();
		
		@Override
		public FileVisitResult preVisitDirectory(Path dir, BasicFileAttributes attrs) throws IOException {
			return FileVisitResult.CONTINUE;
		}

		@Override
		public FileVisitResult visitFile(Path file, BasicFileAttributes attrs) throws IOException {
			String ime = file.getFileName().toString();
			if(ime.endsWith(".java")) {
				pronadeneDatoteke.add(file);
			}
			return FileVisitResult.CONTINUE;
		}

		@Override
		public FileVisitResult visitFileFailed(Path file, IOException exc) throws IOException {
			return FileVisitResult.CONTINUE;
		}

		@Override
		public FileVisitResult postVisitDirectory(Path dir, IOException exc) throws IOException {
			return FileVisitResult.CONTINUE;
		}
		
	}
	
	public static void main(String[] args) {
		if(args.length == 0) {
			System.out.println("Dragi korisniče, ...");
			return;
		}
		
		Path direktorij = Paths.get(args[0]);
		
		if(!Files.isDirectory(direktorij)) {
			System.out.println("Niste dali direktorij!");
			return;
		}

		Trazilica posao = new Trazilica();
		try {
			Files.walkFileTree(direktorij, posao);
		} catch (IOException e) {
			System.out.println("Došlo je do pogreške pri obilasku. Detalji slijede.");
			System.out.println(e.getMessage());
			return;
		}
		
		List<Path> pronadeno = posao.pronadeneDatoteke;
		for(Path datoteka : pronadeno) {
			System.out.println(datoteka.toAbsolutePath().normalize());
		}
		
		
	}
}
