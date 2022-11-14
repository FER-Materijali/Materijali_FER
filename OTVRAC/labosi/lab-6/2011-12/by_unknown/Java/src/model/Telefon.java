package model;

public class Telefon 
{
	private TelefonTip tip;
	
	public TelefonTip getTip()
	{
		return this.tip;
	}
	
	public Boolean setTip(TelefonTip tip)
	{
		this.tip = tip;
		return true;
	}
	
	
	private String pozivni;
	
	public String getPozivni()
	{
		return this.pozivni;
	}
	
	public Boolean setPozivni(String pozivni)
	{
		this.pozivni = pozivni;
		return true;
	}
	
	
	private String broj;
	
	public String getBroj()
	{
		return this.broj;
	}
	
	public Boolean setBroj(String broj)
	{
		if (broj.length() == 8)
		{
			this.broj = broj;
			return true;
		}
		return false;
	}
}
