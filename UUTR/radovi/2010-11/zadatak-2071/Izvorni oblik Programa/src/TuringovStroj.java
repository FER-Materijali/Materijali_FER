import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;

public class TuringovStroj {
	private ArrayList<Prijelaz> prijelazi;
	private ArrayList niz1, niz2;
	private String trenutnoStanje;
	private String filename;
	
	private void NapraviPrijelaze(){
		prijelazi = new ArrayList();
		
		prijelazi.add(new Prijelaz("q0", "0", "B", "q1", "0", "1", "N", "R"));
		prijelazi.add(new Prijelaz("q1", "0", "B", "q2", "0", "1", "N", "R"));
		prijelazi.add(new Prijelaz("q2", "0", "B", "q3", "0", "1", "N", "R"));
		prijelazi.add(new Prijelaz("q0", "1", "B", "q1", "1", "1", "N", "R"));
		prijelazi.add(new Prijelaz("q1", "1", "B", "q2", "1", "1", "N", "R"));
		prijelazi.add(new Prijelaz("q2", "1", "B", "q3", "1", "1", "N", "R"));
		
		prijelazi.add(new Prijelaz("q3", "1", "B", "q4", "1", "1", "R", "R"));
		prijelazi.add(new Prijelaz("q3", "0", "B", "q3", "0", "0", "R", "R"));
		prijelazi.add(new Prijelaz("q4", "1", "B", "q5", "1", "1", "N", "R"));
		prijelazi.add(new Prijelaz("q5", "1", "B", "q3", "1", "0", "R", "R"));
		prijelazi.add(new Prijelaz("q4", "0", "B", "q3", "0", "0", "R", "R"));
		
		prijelazi.add(new Prijelaz("q3", "B", "B", "q6", "B", "1", "N", "R"));
		prijelazi.add(new Prijelaz("q4", "B", "B", "q6", "B", "1", "N", "R"));
		prijelazi.add(new Prijelaz("q6", "B", "B", "q7", "B", "1", "N", "R"));
		prijelazi.add(new Prijelaz("q7", "B", "B", "qp", "B", "1", "N", "R"));
	}

	Prijelaz pronadjiPrijelaz(String znak1, String znak2) {
		Prijelaz pronadeniPrijelaz = new Prijelaz();
		for (Prijelaz prijelaz : prijelazi) {
			if ((prijelaz.trenutniZnak1.equals(znak1)) &&
					(prijelaz.trenutniZnak2.equals(znak2)) &&
						(prijelaz.trenutnoStanje.equals(trenutnoStanje))) {
				pronadeniPrijelaz = prijelaz;
			}
		}
		return pronadeniPrijelaz;
	}
	
	void ispisiPrijelaz(Prijelaz prijelaz) {
		try {
			FileWriter fstream = new FileWriter(filename, true);
			BufferedWriter out = new BufferedWriter(fstream);
			out.write(prijelaz.trenutnoStanje+", "+prijelaz.trenutniZnak1+", "+prijelaz.trenutniZnak2+"  -->  "+prijelaz.novoStanje + ", "+prijelaz.noviZnak1+", "+prijelaz.noviZnak2 +"(" +prijelaz.pomak1+", "+prijelaz.pomak2+")");
			out.newLine();
			out.close();
			fstream.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	public TuringovStroj (String _niz1){
		NapraviPrijelaze();
		niz1 = new ArrayList();
		for (int i = 0; i < _niz1.length(); i++)
			niz1.add(_niz1.toCharArray()[i]);
		niz1.add("B");
		niz2 = new ArrayList();
		trenutnoStanje = "q0";
		
		int pointer1 = 0;
		
		filename="out-"+_niz1+".txt";
		
		FileWriter fstream;
		try {
			fstream = new FileWriter(filename);
			fstream.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
		
		while (trenutnoStanje != "qp") {
			Prijelaz prijelaz = pronadjiPrijelaz(niz1.toArray()[pointer1].toString(), "B");
			niz2.add(prijelaz.noviZnak2);
			if (prijelaz.pomak1 == "R")
				pointer1++;
			trenutnoStanje = prijelaz.novoStanje;
			ispisiPrijelaz(prijelaz);
		}
		
		try {
			fstream = new FileWriter(filename, true);
			BufferedWriter out = new BufferedWriter(fstream);
			for (Object o: niz2){
				String s = (String) o;
				out.write(s);
			}
			out.close();
			fstream.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}