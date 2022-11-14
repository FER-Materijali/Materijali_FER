package hr.fer.oop.lab5.second;

import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;

/**
 * The Class Pretrazivanje.
 */
public class Pretrazivanje {

	/** The Constant INPUT. */
	private static final String INPUT = "cjenik.utf8.txt";

	/**
	 * The main method.
	 *
	 * @param args the arguments
	 */
	public static void main(String[] args) {

		try (Scanner sc = new Scanner(System.in)) {
			String[] input = sc.nextLine().split("\\s");

			String naziv = input[0];
			int minCijena = Integer.parseInt(input[1]);
			int maxCijena = Integer.parseInt(input[2]);

			ArrayList<String> artikli = new ArrayList<String>();
			try (BufferedReader br = new BufferedReader(
					new InputStreamReader(new BufferedInputStream(new FileInputStream(INPUT)), "UTF-8"))) {
				String line;
				while ((line = br.readLine()) != null) {
					artikli.add(line);
				}

			} catch (IOException e) {
				e.printStackTrace();
			}

			Collections.sort(artikli, new Comparator<String>() {
				@Override
				public int compare(String s1, String s2) {
					return s2.split("\\s\\s+")[1].compareTo(s1.split("\\s\\s+")[1]);
				}
			});

			for (String a : artikli) {
				String[] artikl = a.split("\\s\\s+");
				String ime = artikl[0];
				float cijena = Float.parseFloat(artikl[1]);

				if (ime.contains(naziv) && cijena < maxCijena && cijena > minCijena) {
					System.out.println(a);
				}
			}
		}
	}

}
