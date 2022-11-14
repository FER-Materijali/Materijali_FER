import java.io.*;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * Servlet implementation class Servlet
 */
public class Servlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
	private String inputFileName;
	
	@Override
	public void init() throws ServletException {
		super.init();
		inputFileName = getServletConfig().getInitParameter("InputFile");
	}

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		//deklaracija objekata koji èitaju podatke
		InputStreamReader inputFile = null;
		BufferedReader reader = null;

		//otvaranje datoteke za èitanje
		//inputFile = new FileReader(inputFileName);
		inputFile = new InputStreamReader(getServletConfig().getServletContext()
				.getResourceAsStream(inputFileName));
		
		//BufferedReader 'nad' datotekom
		reader = new BufferedReader(inputFile);
		
		//stvaranje podatkovne strukture èitanjem tekstualne datoteke
		model.TelefonskiImenik telefonskiImenik = null;
		try {
			telefonskiImenik = model.factory.TelefonskiImenik.fromText(reader);
		} catch(Exception e) {
			System.out.println(e);
			System.exit(1);
		}
		
		response.setContentType("text/xml; charset=UTF-8");
		
		// deklaracija objekta koji piše podatke
		PrintWriter writer = null;

		// pokušaj otvaranja datotke za pisanje
		try {
			writer = response.getWriter();
		} catch (IOException e) {
			System.out.println("Izlazna datoteka ne moze biti stvorena!\n" + e);
		}

		// serijalizacija podatkovne strukture u datoteku
		try {
			model.factory.TelefonskiImenik.toXML(telefonskiImenik, writer);
		} catch (IOException e) {
			System.out.println("Greška u stvaranju XML dokumenta\n" + e);
		}

		System.out.println("Konverzija dovršena!");
		
		try {
			writer.close();
		} catch (Exception ignorable) { }
		try {
			reader.close();
		} catch (Exception ignorable) { }
	}
}
