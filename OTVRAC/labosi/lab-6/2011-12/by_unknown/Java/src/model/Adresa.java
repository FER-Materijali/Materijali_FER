package model;

public class Adresa 
{
	private String Ulica;

	public String getUlica() {
		return this.Ulica;
	}

	public Boolean setUlica(String value) {
		this.Ulica = value;
		return true;
	}
	
	
	private int KucniBroj;

	public int getKucniBroj() {
		return this.KucniBroj;
	}

	public Boolean setKucniBroj(int value) {
		if (value > 0)
		{
			this.KucniBroj = value;
			return true;
		}
		return false;
	}
	
	
	private String Mjesto;

	public String getMjesto() {
		return this.Mjesto;
	}

	public Boolean setMjesto(String value) {
		this.Mjesto = value;
		return true;
	}
	
	
	private String PostanskiBroj;

	public String getPostanskiBroj() {
		return this.PostanskiBroj;
	}

	public Boolean setPostanskiBroj(String value) {
		this.PostanskiBroj = value;
		return true;
	}
	
	
	private String Drzava;

	public String getDrzava() {
		return this.Drzava;
	}

	public Boolean setDrzava(String value) {
		this.Drzava = value;
		return true;
	}
}
