package model.factory;

import java.util.StringTokenizer;

import model.TelefonTip;

public class Telefon 
{
	public static model.Telefon fromText(String txtTelefon)
	{
		model.Telefon telefon = new model.Telefon();
		
		StringTokenizer t = new StringTokenizer(txtTelefon, ",");
		
		String telefonTip = t.nextToken().trim();
		try
		{
			TelefonTip tip = TelefonTip.valueOf(telefonTip);
			telefon.setTip(tip);
		}
		catch (Exception e)
		{
			return null;
		}

		telefon.setPozivni(t.nextToken().trim());
		telefon.setBroj(t.nextToken().trim());
		
		return telefon;
	}
	
	public static String toXML(model.Telefon telefon)
	{
		if (telefon == null) {
			return "";
		}
		
		StringBuilder xmlTelefon = new StringBuilder();
		
		xmlTelefon.append(String.format(" <telefon tip=\"%s\">\r\n", 
				telefon.getTip()));
		xmlTelefon.append(String.format("  <broj pozivni_broj=\"%s\">%s</broj>\r\n", 
				telefon.getPozivni(), telefon.getBroj()));
		xmlTelefon.append(" </telefon>\r\n");
		
		return xmlTelefon.toString();
	}
}
