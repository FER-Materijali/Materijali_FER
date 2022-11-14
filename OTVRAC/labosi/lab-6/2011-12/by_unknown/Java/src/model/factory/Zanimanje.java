package model.factory;

import java.util.StringTokenizer;

import model.VrstaDjelatnosti;

public class Zanimanje 
{
	public static model.Zanimanje fromText(String txtZanimanje)
	{
		model.Zanimanje zanimanje = new model.Zanimanje();
		
		StringTokenizer z = new StringTokenizer(txtZanimanje, ",");
		
		String vrstaDjelatnosti = z.nextToken().trim();
		try
		{
			VrstaDjelatnosti vrsta = VrstaDjelatnosti.valueOf(vrstaDjelatnosti);
			zanimanje.setVrsta(vrsta);
		}
		catch (Exception e)
		{
			return null;
		}

		zanimanje.setKljucneRijeci(z.nextToken().trim());
		zanimanje.setNazivTvrtke(z.nextToken().trim());
		
		return zanimanje;
	}
	
	public static String toXML(model.Zanimanje zanimanje)
	{
		if (zanimanje == null) {
			return "";
		}
		
		StringBuilder xmlZanimanje = new StringBuilder();
		
		xmlZanimanje.append(String.format(" <zanimanje vrsta_djelatnosti=\"%s\">\r\n", 
				zanimanje.getVrsta()));
		xmlZanimanje.append(String.format("  <kljucne_rijeci>%s</kljucne_rijeci>\r\n", 
				zanimanje.getKljucneRijeci()));
		xmlZanimanje.append(String.format("  <naziv_tvrtke>%s</naziv_tvrtke>\r\n", 
				zanimanje.getNazivTvrtke()));
		xmlZanimanje.append(" </zanimanje>\r\n");
		
		return xmlZanimanje.toString();
	}
}
