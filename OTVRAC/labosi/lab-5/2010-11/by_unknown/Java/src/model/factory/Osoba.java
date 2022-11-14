package model.factory;

import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Osoba {

	public static model.Osoba fromText(String osobaString) {
		model.Osoba osoba = new model.Osoba();

		StringTokenizer st = new StringTokenizer(osobaString, ".");

		osoba.setIme(st.nextToken().trim());

		osoba.setPrezime(st.nextToken().trim());

		return osoba;
	}

	public static void toXML(String uloga, model.Osoba osoba, PrintWriter writer)
			throws IOException {
		writer.write("    <" + uloga + ">\n");
		writer.write("      <ime>" + osoba.getIme() + "</ime>\n");
		writer.write("      <prezime>" + osoba.getPrezime() + "</prezime>\n");
		writer.write("    </" + uloga + ">\n");
	}

}
