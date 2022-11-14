package model.factory;

import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Review {

	public static model.Review fromText(String reviewString) {
		model.Review recenzija = new model.Review();

		StringTokenizer st = new StringTokenizer(reviewString, ",");

		model.Osoba recenzent = model.factory.Osoba.fromText(st.nextToken().trim());
		recenzija.setRecenzent(recenzent);

		recenzija.setRecenzija(st.nextToken().trim());

		return recenzija;
	}

	public static void toXML(model.Review review, PrintWriter writer) throws IOException {
		writer.write("    <recenzija>\n");
		writer.write("      <recenzent>\n");
		writer.write("        <ime>" + review.getRecenzent().getIme() + "</ime>\n");
		writer.write("        <prezime>" + review.getRecenzent().getPrezime() + "</prezime>\n");
		writer.write("      </recenzent>\n");
		writer.write("      <sadrzaj>" + review.getRecenzija() + "</sadrzaj>\n");
		writer.write("    </recenzija>\n");
	}
}
