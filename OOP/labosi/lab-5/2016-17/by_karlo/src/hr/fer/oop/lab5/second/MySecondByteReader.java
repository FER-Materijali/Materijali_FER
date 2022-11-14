package hr.fer.oop.lab5.second;

import java.io.*;
import java.nio.file.*;
import java.nio.file.attribute.BasicFileAttributes;
import java.util.ArrayList;
import java.util.TreeSet;

/**
 * The Class MySecondByteReader.
 */
public class MySecondByteReader implements FileVisitor<Path> {

	/** The artikli. */
	public TreeSet<Artikl> artikli;

	/**
	 * Instantiates a new my second byte reader.
	 */
	public MySecondByteReader() {
		artikli = new TreeSet<>();
	}

	/*
	 * (non-Javadoc)
	 * 
	 * @see java.nio.file.FileVisitor#postVisitDirectory(java.lang.Object,
	 * java.io.IOException)
	 */
	@Override
	public FileVisitResult postVisitDirectory(Path dir, IOException exc) throws IOException {
		return FileVisitResult.CONTINUE;
	}

	/*
	 * (non-Javadoc)
	 * 
	 * @see java.nio.file.FileVisitor#preVisitDirectory(java.lang.Object,
	 * java.nio.file.attribute.BasicFileAttributes)
	 */
	@Override
	public FileVisitResult preVisitDirectory(Path dir, BasicFileAttributes attrs) throws IOException {
		return FileVisitResult.CONTINUE;
	}

	/*
	 * (non-Javadoc)
	 * 
	 * @see java.nio.file.FileVisitor#visitFile(java.lang.Object,
	 * java.nio.file.attribute.BasicFileAttributes)
	 */
	@Override
	public FileVisitResult visitFile(Path file, BasicFileAttributes attrs) throws IOException {
		if (file.toString().endsWith(".txt")) {
			BufferedReader br = new BufferedReader(
					new InputStreamReader(new BufferedInputStream(new FileInputStream(file.toFile())), "UTF-8"));

			for (String line = br.readLine(); line != null; line = br.readLine()) {
				if (line.startsWith("Raèun") || line.startsWith("Kupac") || line.startsWith("---")
						|| line.startsWith("Proizvod") || line.startsWith("UKUPNO") || line.isEmpty()) {
					continue;
				}

				String reversedLine = new StringBuffer(line).reverse().toString();
				String[] artiklReversed = reversedLine.split("\\s+");
				ArrayList<String> artikl = new ArrayList<>();
				for (String s : artiklReversed) {
					String original = new StringBuffer(s).reverse().toString();
					if (s.matches("[0-9.]*") || artikl.size() >= 4) {
						artikl.add(original);
					}
				}
				if (artikl.size() == 0) {
					continue;
				}

				String pdv = artikl.get(0);
				String ukupnaCijena = artikl.get(1);
				// String kolicina = artikl.get(2);
				// String cijena = artikl.get(3);

				float cijenaArtikla = Float.parseFloat(pdv) + Float.parseFloat(ukupnaCijena);
				cijenaArtikla = Math.round(cijenaArtikla * 100f) / 100f;

				String imeArtikla = "";
				for (int i = artikl.size() - 1; i >= 4; i--) {
					imeArtikla += artikl.get(i) + " ";
				}

				if (imeArtikla.isEmpty()) {
					continue;
				}
				artikli.add(new Artikl(imeArtikla, cijenaArtikla));
			}
			br.close();
		}
		return FileVisitResult.CONTINUE;
	}
	
	/*
	 * (non-Javadoc)
	 * 
	 * @see java.nio.file.FileVisitor#visitFileFailed(java.lang.Object,
	 * java.io.IOException)
	 */
	@Override
	public FileVisitResult visitFileFailed(Path file, IOException exc) throws IOException {
		return FileVisitResult.CONTINUE;
	}
}
