package model.factory;

import java.io.IOException;
import java.io.PrintWriter;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;
import java.util.Iterator;
import java.util.StringTokenizer;

public class Book {

	public static model.Book fromText(String line) {
		model.Book book = new model.Book();

		StringTokenizer st = new StringTokenizer(line, "|");

		book.setID(st.nextToken().trim());

		String langauagesList = st.nextToken().trim();
		StringTokenizer languagesTokenizer = new StringTokenizer(langauagesList, ";");

		while (languagesTokenizer.hasMoreElements() == true) {
			String jezik = (String) languagesTokenizer.nextElement();
			book.addJezik(jezik);
		}

		book.setBrojStranica(Integer.parseInt(st.nextToken().trim()));

		book.setIsbn(st.nextToken().trim());

		book.setIzdanje(Integer.parseInt(st.nextToken().trim()));

		book.setUvez(st.nextToken().trim());

		book.setNaslov(st.nextToken().trim());

		book.setPodnaslov(st.nextToken().trim());

		book.setOcjena(Short.parseShort(st.nextToken().trim()));

		book.setNacinDistribucije(st.nextToken().trim());

		book.setKategorija(st.nextToken().trim());

		book.setCijena(st.nextToken().trim());

		String authorsList = st.nextToken().trim();
		StringTokenizer authorsTokenizer = new StringTokenizer(authorsList, ";");

		while (authorsTokenizer.hasMoreElements() == true) {
			String authorString = (String) authorsTokenizer.nextElement();
			model.Osoba autor = model.factory.Osoba.fromText(authorString);

			if (autor != null)
				book.addAutor(autor);
		}

		book.setIzdavac(st.nextToken().trim());

		String datumIzdanjaString = st.nextToken().trim();
		SimpleDateFormat format = new SimpleDateFormat("yyyy-MM-dd");
		Date datumIzdanja;
		try {
			datumIzdanja = format.parse(datumIzdanjaString);
			book.setDatumIzdanja(datumIzdanja);
		} catch (ParseException e) {
			e.printStackTrace();
		}

		if (st.hasMoreElements()) {
			String reviewsList = st.nextToken().trim();
			StringTokenizer reviewsTokenizer = new StringTokenizer(reviewsList, ";");

			while (reviewsTokenizer.hasMoreElements() == true) {
				String reviewString = (String) reviewsTokenizer.nextElement();
				model.Review review = model.factory.Review.fromText(reviewString);

				if (review != null)
					book.addRecenzija(review);
			}
		}
		return book;
	}

	public static void toXML(model.Book book, PrintWriter writer) throws IOException {
		writer.write("  <knjiga id=\"" + book.getID() + "\"");
		writer.write(" jezik=\"");
		Iterator<String> jezici = book.jezici();
		while (jezici.hasNext())
			writer.write(jezici.next() + " ");
		writer.write("\" broj_stranica=\"" + book.getBrojStranica() + "\"");
		writer.write(" isbn=\"" + book.getIsbn() + "\" izdanje=\"" + book.getIzdanje()
				+ "\" uvez=\"" + book.getUvez() + "\">\n");

		writer.write("    <naslov>" + book.getNaslov() + "</naslov>\n");
		if (book.getPodnaslov().length() != 0)
			writer.write("    <podnaslov>" + book.getPodnaslov() + "</podnaslov>\n");

		Iterator<model.Osoba> authors = book.authors();
		while (authors.hasNext())
			model.factory.Osoba.toXML("autor", authors.next(), writer);

		writer.write("    <izdavac>\n");
		writer.write("      <naziv>" + book.getIzdavac() + "</naziv>\n");
		writer.write("    </izdavac>\n");

		Calendar c = Calendar.getInstance();
		c.setTime(book.getDatumIzdanja());
		writer.write("    <datum_izdanja>\n");
		writer.write("      <dan>" + c.get(Calendar.DAY_OF_MONTH) + "</dan>\n");
		writer.write("      <mjesec>" + (c.get(Calendar.MONTH) + 1) + "</mjesec>\n");
		writer.write("      <godina>" + c.get(Calendar.YEAR) + "</godina>\n");
		writer.write("    </datum_izdanja>\n");

		writer.write("    <ocjena>" + book.getOcjena() + "</ocjena>\n");

		writer.write("    <nacin_distribucije>" + book.getNacinDistribucije()
				+ "</nacin_distribucije>\n");

		writer.write("    <kategorija>" + book.getKategorija() + "</kategorija>\n");

		writer.write("    <cijena>" + book.getCijena() + "</cijena>\n");

		Iterator<model.Review> reviews = book.reviews();
		while (reviews.hasNext())
			model.factory.Review.toXML(reviews.next(), writer);

		writer.write("  </knjiga>\n");
	}
}
