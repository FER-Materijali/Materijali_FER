package model;

import java.util.Date;
import java.util.Iterator;
import java.util.Vector;

public class Osoba 
{
	private String Oib;

	public String getOib() {
		return this.Oib;
	}

	public Boolean setOib(String value) {
		if (value.length() == 11)
		{
			this.Oib = value;
			return true;
		}
		return false;
	}
	
	private Kategorija Kategorija;

	public Kategorija getKategorija() {
		return this.Kategorija;
	}

	public Boolean setKategorija(Kategorija value) {
		this.Kategorija = value;
		return true;
	}
	
	private String Ime;

	public String getIme() {
		return this.Ime;
	}

	public Boolean setIme(String value) {
		this.Ime = value;
		return true;
	}
	
	private String Prezime;

	public String getPrezime() {
		return this.Prezime;
	}

	public Boolean setPrezime(String value) {
		this.Prezime = value;
		return true;
	}
	
	
	private Vector<Telefon> Telefoni = new Vector<Telefon>();

	public Iterator<Telefon> Telefoni() {
		return this.Telefoni.iterator();
	}

	public void addTelefon(Telefon telefon) {
		this.Telefoni.add(telefon);
	}

	public void removeTelefon(Telefon telefon) {
		this.Telefoni.remove(telefon);
	}
	
	
	private Adresa Adresa;

	public Adresa getAdresa() {
		return this.Adresa;
	}

	public Boolean setAdresa(Adresa value) {
		if (value != null)
		{
			this.Adresa = value;
			return true;
		}
		return false;
	}
	
	private Zanimanje Zanimanje;

	public Zanimanje getZanimanje() {
		return this.Zanimanje;
	}

	public Boolean setZanimanje(Zanimanje value) {
		if (value != null)
		{
			this.Zanimanje = value;
			return true;
		}
		return false;
	}
	
	private Vector<String> Emails = new Vector<String>();

	public Iterator<String> Emails() {
		return this.Emails.iterator();
	}

	public void addEmail(String email) {
		this.Emails.add(email);
	}

	public void removeEmail(String email) {
		this.Emails.remove(email);
	}

	
	private Date DatumRodjenja;

	public Date getDatumRodjenja() {
		return this.DatumRodjenja;
	}

	public Boolean setDatumRodjenja(Date value) {
		this.DatumRodjenja = value;
		return true;
	}
}

