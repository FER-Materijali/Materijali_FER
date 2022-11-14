package model.factory;

import java.util.StringTokenizer;

public class Adresa 
{
	public static model.Adresa fromText(String txtAdresa)
	{
		model.Adresa adresa = new model.Adresa();
		
		StringTokenizer a = new StringTokenizer(txtAdresa, ",");
		adresa.setUlica(a.nextToken().trim());
		
		String kucni = a.nextToken().trim();
		if (!isNumber(kucni))
		{
			return null;
		}
		adresa.setKucniBroj(Integer.parseInt(kucni));
		
		adresa.setPostanskiBroj(a.nextToken().trim());
		adresa.setMjesto(a.nextToken().trim());
		adresa.setDrzava(a.nextToken().trim());
		
		return adresa;
	}
	
	public static String toXML(model.Adresa adresa)
	{
		if (adresa == null) {
			return "";
		}
		
		StringBuilder xmlAdresa = new StringBuilder();
		
		xmlAdresa.append(" <adresa>\r\n");
		xmlAdresa.append(String.format("  <ulica>%s</ulica>\r\n", adresa.getUlica()));
		xmlAdresa.append(String.format("  <kucni_broj>%s</kucni_broj>\r\n", 
				adresa.getKucniBroj()));
		xmlAdresa.append(String.format("  <mjesto postanski_broj=\"%s\">%s</mjesto>\r\n", 
				adresa.getPostanskiBroj(), adresa.getMjesto()));
		xmlAdresa.append(String.format("  <drzava>%s</drzava>\r\n", 
				adresa.getDrzava()));
		xmlAdresa.append(" </adresa>\r\n");
		
		return xmlAdresa.toString();
	}
	
	private static boolean isNumber(String intS) 
	{
		try {
			Long.parseLong(intS);
			return true;
		} catch(NumberFormatException e) {
			return false;
		}
	}
}
