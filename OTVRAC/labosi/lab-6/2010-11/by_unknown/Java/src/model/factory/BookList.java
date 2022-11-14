package model.factory;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Iterator;

public class BookList {

	public static model.BookList fromText(BufferedReader reader) {
		// stvori objekt - listu kartica
		model.BookList booksList = new model.BookList();

		// string koji sadrži pročitani redak datoteke
		String line = null;

		// trenutni redak datoteke
		int currentLine = 0;

		try {

			// do zadnjeg retka u datoteci ...
			while ((line = reader.readLine()) != null) {

				// povecavanje brojaca trenutne linije
				currentLine++;

				// odbaci prazne znakove na početku i kraju retka
				line = line.trim();

				// preskoci prazne retke
				if (line.length() == 0)
					continue;

				// preskoči retke ako počinju sa znakom # (komentari)
				if (line.startsWith("#"))
					continue;

				model.Book book = null;

				// predaj stvoreni string tvornici objekata Kartica
				book = model.factory.Book.fromText(line);

				// dodaj novostvoreni objekt u listu objekata (ako nije null)
				if (book != null)
					booksList.add(book);
			}
		} catch (Exception e) {
			System.out.println("Greska u retku " + currentLine);
			e.printStackTrace();
			return null;
		}
		// vrati novostvorenu listu kartica
		return booksList;
	}

	public static void toXML(model.BookList bookList, PrintWriter writer) throws IOException {
		if (bookList == null)
			return;

		writer.write("<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"no\" ?>\n"
				+ "<!DOCTYPE knjiznica SYSTEM \"gramatika.dtd\">\n"
				+ "<?xml-stylesheet type=\"text/xsl\" href=\"pretvorba.xsl\" ?>\n\n");
		writer.write("<knjiznica>\n");
		Iterator<model.Book> it = bookList.books();
		while (it.hasNext())
			model.factory.Book.toXML(it.next(), writer);
		writer.write("</knjiznica>\n");
		writer.flush();
	}
}
