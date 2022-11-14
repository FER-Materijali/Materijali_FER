import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class MainServlet extends HttpServlet {

	private static final long serialVersionUID = -5111152333462774884L;

	private String ulaznaDatoteka;

	@Override
	public void init() throws ServletException {
		super.init();
		ulaznaDatoteka = getServletConfig().getInitParameter("InputFile");
	}

	@Override
	protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException,
			IOException {

		// deklaracija objekta koji čita podatke
		BufferedReader reader = null;

		// pokušaj otvaranja datoteke za čitanje
		reader = new BufferedReader(new InputStreamReader(getServletConfig().getServletContext()
		// getClass()
				.getResourceAsStream("/WEB-INF/" + ulaznaDatoteka)));

		resp.setContentType("text/xml; charset=UTF-8");

		// stvaranje podatkovne strukture čitanjem tekstualne datoteke
		model.BookList bookList = null;
		try {
			bookList = model.factory.BookList.fromText(reader);
		} catch (Exception e) {
			System.out.println(e);
		}

		// deklaracija objekta koji piše podatke
		PrintWriter writer = null;

		// pokušaj otvaranja datotke za pisanje
		try {
			writer = resp.getWriter();
		} catch (IOException e) {
			System.out.println("Izlazna datoteka ne moze biti stvorena!\n" + e);
		}

		// serijalizacija podatkovne strukture u datoteku
		try {
			model.factory.BookList.toXML(bookList, writer);
		} catch (IOException e) {
			System.out.println("Greška u stvaranju XML dokumenta\n" + e);
		}

		System.out.println("Konverzija dovršena!");
		try {
			writer.close();
		} catch (Exception ignorable) {
		}
		try {
			reader.close();
		} catch (Exception ignorable) {
		}
	}
}
