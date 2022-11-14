import java.util.*;
import java.io.*;


public abstract class Lik
{
	abstract double izracunajPovrsinu();
	public abstract String toString();

	protected Vector parsiraj(String redak, int n) 
	{
		Double num=null;
		Vector<Double> stranice = new Vector<Double>();
		StringTokenizer st = new StringTokenizer(redak," ");
		for (int i = 0; i < n; i++) {
			try {
				num = new Double(st.nextToken());
			} catch (NoSuchElementException nsee) {
				fatal("Nema vise brojeva?");
			} catch (NumberFormatException nfe) {
				fatal("Ne mogu pretvoriti string u broj");
			}
			stranice.add(num);
		}
		return stranice;
	}

	public static void fatal(String poruka)
	{	
		System.out.println();
		System.out.print("RasturiLajnu Error: " + poruka);
		System.out.println();
		System.exit(1);
	}
}