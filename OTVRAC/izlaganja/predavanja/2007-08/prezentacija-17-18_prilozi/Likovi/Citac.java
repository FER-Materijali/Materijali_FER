import java.io.*;
import java.util.*;
import java.text.*;


public class Citac {
	public static void main(String [] args) {
		if (args.length != 1) {
			fatal("Pogresan broj parametara: " + args.length + "!\nProgram se koristi na slijedeci nacin:\n	java Citac <ime_datoteke>");
		}
		report("Pokusavam otvoriti datoteku " + args[0] + "...");
		File f = new File(args[0]);
		if (f.exists()) {
			report("Datoteka postoji.");
			if (f.canRead()) {
				report("Datoteka moze biti otvorena za citanje.");
			}
		}
		
		BufferedReader breader = null;
		try {
			breader = new BufferedReader(new FileReader(f));
		} catch (FileNotFoundException fnfe) {
			fatal("Greska prilikom otvaranja datoteke: " + fnfe.getMessage());
		}
		
		String tmp=null, linija=null;
		Vector<Lik> kontejner= new Vector<Lik>();
		System.out.println();
		while(true)
		{
			try 
			{
				tmp = breader.readLine();
				linija = breader.readLine();
			} catch (IOException ioe) {
				fatal(ioe.getMessage());
			}
//			report("tmp=[" +tmp +"]");			
//			report("linija=[" +linija +"]");
	
			if (tmp==null) break;

			switch(tmp.charAt(0))
			{
				case 'P':
					kontejner.add(new Pravokutnik(linija));
					break;
				case 'K':
					kontejner.add(new Kvadrat(linija));
					break;
				case 'T':
					kontejner.add(new Trokut(linija));
					break;
				case 'J':
					kontejner.add(new JednakoStranican(linija));
					break;
				case 'E':
					kontejner.add(new Elipsa(linija));
					break;
				case 'C':
					kontejner.add(new Krug(linija));
					break;			
			}
		}

		double povrsina, ukupna=0;
		DecimalFormat myFormatter = new DecimalFormat("###,###,###,###.##");

		for(int i = 0; i < kontejner.size(); i++)
		{			
			povrsina=kontejner.get(i).izracunajPovrsinu();
			ukupna+=povrsina;
			System.out.print(kontejner.get(i) + " \tpovrsina=[" + myFormatter.format(povrsina) + "]cm^2\n" );
		}
		System.out.println();
		report("Ukupna povrsina = [" +myFormatter.format(ukupna) + "]cm^2\n"); 		    
	}
	public static void report(String text) {
		System.out.println("Citac: " + text);
	}

	public static void fatal(String hehe)
	{	
		System.out.println();
		System.out.print("Citac Error: " + hehe);
		System.out.println();
		System.exit(1);
	}

}
