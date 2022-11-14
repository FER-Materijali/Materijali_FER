package model.factory;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.Writer;
import java.util.Iterator;

public class TelefonskiImenik 
{
	public static model.TelefonskiImenik fromText(BufferedReader input)
	{
		model.TelefonskiImenik telefonskiImenik = new model.TelefonskiImenik();
		
		//string koji sadrži proèitani redak datoteke
		String line = null;
		
		//trenutni redak datoteke
		int currentLine = 0;
		
		try 
		{
			//do zadnjeg retka u datoteci ...
			while((line = input.readLine()) != null) 
			{
				//povecavanje brojaca trenutne linije
				currentLine++;
				
				//odbaci prazne znakove na poèetku i kraju retka
				line = line.trim();
				
				//preskoci prazne retke
				if( line.length() == 0 ) 
				{
					continue;
				}
				
				//preskoèi retke ako poèinju sa znakom # (komentari)
				if( line.startsWith("#") )
				{
					continue;
				}
				
				model.Osoba osoba = null;
				
				//predaj stvoreni string tvornici objekata Kartica
				osoba = model.factory.Osoba.fromText(line);
			
				//dodaj novostvoreni objekt u listu objekata (ako nije null)
				if( osoba != null )
				{
					telefonskiImenik.addOsoba(osoba);
				}
			}
		} catch(Exception e) {
			System.out.println("Greska u retku " + currentLine);
			return null;
		}

		return telefonskiImenik;
	}
	
	public static void toXML(
			model.TelefonskiImenik telefonskiImenik, Writer output) throws IOException
	{
		if(telefonskiImenik == null)
		{
			return;
		}
		
		StringBuilder sb = new StringBuilder();
		
		sb.append("<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"no\" ?>\r\n");
		sb.append("<!DOCTYPE telefonski_imenik SYSTEM \"gramatika.dtd\">\r\n");
		sb.append("<?xml-stylesheet type=\"text/xsl\" href=\"pretvorba.xsl\" ?>\r\n\r\n");

		sb.append("<telefonski_imenik>\r\n\r\n");
		for (Iterator<model.Osoba> osoba = telefonskiImenik.Osobe(); 
				osoba.hasNext();) 
		{
			sb.append(model.factory.Osoba.toXML(osoba.next()));
			sb.append("\r\n");
		}
		sb.append("</telefonski_imenik>\r\n");
		
		output.write(sb.toString());
		output.flush();
	}
}
