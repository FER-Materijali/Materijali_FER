package model.factory;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Iterator;
import java.util.StringTokenizer;

import model.Kategorija;

public class Osoba 
{
	public static model.Osoba fromText(String txtOsoba)
	{
		model.Osoba osoba = new model.Osoba();
		
		StringTokenizer o = new StringTokenizer(txtOsoba, "|");
		osoba.setOib(o.nextToken().trim());
		
		String kategorija = o.nextToken().trim();
		try
		{
			Kategorija k = Kategorija.valueOf(kategorija);
			osoba.setKategorija(k);
		}
		catch (Exception e)
		{
			return null;
		}
		
		osoba.setIme(o.nextToken().trim());
		osoba.setPrezime(o.nextToken().trim());
		
		StringTokenizer t = new StringTokenizer(o.nextToken().trim(), ";");
		while (t.hasMoreElements()) {
			osoba.addTelefon(model.factory.Telefon
					.fromText(t.nextToken().trim()));
		}
		
		osoba.setAdresa(model.factory.Adresa.fromText(o.nextToken().trim()));
		osoba.setZanimanje(model.factory.Zanimanje.fromText(o.nextToken().trim()));
		
		StringTokenizer e = new StringTokenizer(o.nextToken().trim(), ";");
		while (e.hasMoreElements()) {
			osoba.addEmail(e.nextToken().trim());
		}
		
		try {
			osoba.setDatumRodjenja(
					new SimpleDateFormat("dd.MM.yyyy.")
					.parse(o.nextToken().trim()));
		} catch (ParseException exc) {
			return null;
		}
		
		return osoba;
	}
	
	public static String toXML(model.Osoba osoba)
	{
		if (osoba == null){
			return "";
		}
		
		StringBuilder xmlOsoba = new StringBuilder();
		
		xmlOsoba.append(String.format("<osoba oib=\"%s\" kategorija=\"%s\">\r\n", 
				osoba.getOib(), osoba.getKategorija()));
		xmlOsoba.append(String.format(" <ime>%s</ime>\r\n", osoba.getIme()));
		xmlOsoba.append(String.format(" <prezime>%s</prezime>\r\n", 
				osoba.getPrezime()));
		for (Iterator<model.Telefon> telefoni = osoba.Telefoni(); 
				telefoni.hasNext();) 
		{
			xmlOsoba.append(model.factory.Telefon.toXML(telefoni.next()));
		}
		xmlOsoba.append(model.factory.Adresa.toXML(osoba.getAdresa()));
		xmlOsoba.append(model.factory.Zanimanje.toXML(osoba.getZanimanje()));
		for (Iterator<String> emails = osoba.Emails(); emails.hasNext();) 
		{
			xmlOsoba.append(String.format(" <mail_adresa>%s</mail_adresa>\r\n", 
					emails.next()));
		}
		xmlOsoba.append(String.format(" <datum_rodjenja>%s</datum_rodjenja>\r\n", 
				new SimpleDateFormat("dd.MM.yyyy.")
				.format(osoba.getDatumRodjenja())));
		xmlOsoba.append("</osoba>\r\n");
		
		return xmlOsoba.toString();
	}
}
