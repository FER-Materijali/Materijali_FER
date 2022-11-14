package model;

import java.util.Date;
import java.util.Iterator;
import java.util.Vector;

public class Book {

	private String ID;
	private String jezik;
	private int brojStranica;
	private String isbn;
	private int izdanje;
	private String uvez;
	private String naslov;
	private String podnaslov;
	private Date datumIzdanja;
	private short ocjena;
	private String nacinDistribucije;
	private String kategorija;
	private String cijena;
	private Vector<Osoba> autori = new Vector<Osoba>();
	private String izdavac;
	private Vector<Review> recenzije = new Vector<Review>();
	private Vector<String> jezici = new Vector<String>();

	public String getID() {
		return ID;
	}

	public void setID(String ID) {
		this.ID = ID;
	}

	public String getJezik() {
		return jezik;
	}

	public int getBrojStranica() {
		return brojStranica;
	}

	public void setBrojStranica(int brojStranica) {
		this.brojStranica = brojStranica;
	}

	public String getIsbn() {
		return isbn;
	}

	public void setIsbn(String isbn) {
		this.isbn = isbn;
	}

	public int getIzdanje() {
		return izdanje;
	}

	public void setIzdanje(int izdanje) {
		this.izdanje = izdanje;
	}

	public String getUvez() {
		return uvez;
	}

	public void setUvez(String uvez) {
		this.uvez = uvez;
	}

	public String getNaslov() {
		return naslov;
	}

	public void setNaslov(String naslov) {
		this.naslov = naslov;
	}

	public String getPodnaslov() {
		return podnaslov;
	}

	public void setPodnaslov(String podnaslov) {
		this.podnaslov = podnaslov;
	}

	public Date getDatumIzdanja() {
		return datumIzdanja;
	}

	public void setDatumIzdanja(Date datumIzdanja) {
		this.datumIzdanja = datumIzdanja;
	}

	public short getOcjena() {
		return ocjena;
	}

	public void setOcjena(short ocjena) {
		this.ocjena = ocjena;
	}

	public String getNacinDistribucije() {
		return nacinDistribucije;
	}

	public void setNacinDistribucije(String nacinDistribucije) {
		this.nacinDistribucije = nacinDistribucije;
	}

	public String getKategorija() {
		return kategorija;
	}

	public void setKategorija(String kategorija) {
		this.kategorija = kategorija;
	}

	public String getCijena() {
		return cijena;
	}

	public void setCijena(String cijena) {
		this.cijena = cijena;
	}

	public Iterator<Review> reviews() {
		return recenzije.iterator();
	}

	public void addRecenzija(Review recenzija) {
		recenzije.add(recenzija);
	}

	public void removeRecenzija(Review recenzija) {
		recenzije.remove(recenzija);
	}

	public Iterator<Osoba> authors() {
		return autori.iterator();
	}

	public void addAutor(Osoba autor) {
		autori.add(autor);
	}

	public void removeAutor(Osoba autor) {
		autori.remove(autor);
	}

	public String getIzdavac() {
		return izdavac;
	}

	public void setIzdavac(String izdavac) {
		this.izdavac = izdavac;
	}

	public Iterator<String> jezici() {
		return jezici.iterator();
	}

	public void addJezik(String jezik) {
		jezici.add(jezik);
	}

	public void removeJezik(String jezik) {
		jezici.remove(jezik);
	}
}
