package model;

public class Zanimanje 
{
	private VrstaDjelatnosti Vrsta;

	public VrstaDjelatnosti getVrsta() {
		return this.Vrsta;
	}

	public Boolean setVrsta(VrstaDjelatnosti value) {
		this.Vrsta = value;
		return true;
	}
	
	private String KljucneRijeci;

	public String getKljucneRijeci() {
		return this.KljucneRijeci;
	}

	public Boolean setKljucneRijeci(String value) {
		this.KljucneRijeci = value;
		return true;
	}
	
	private String NazivTvrtke;

	public String getNazivTvrtke() {
		return this.NazivTvrtke;
	}

	public Boolean setNazivTvrtke(String value) {
		this.NazivTvrtke = value;
		return true;
	}
}
