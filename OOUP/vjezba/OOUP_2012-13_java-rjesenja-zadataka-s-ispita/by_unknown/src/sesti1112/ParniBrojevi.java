package sesti1112;

public class ParniBrojevi {

	private Integer prvi;
	private Integer brElemenata;
	
	public ParniBrojevi(Integer prvi, Integer brElemenata) {
		super();
		this.prvi = prvi;
		this.brElemenata = brElemenata;
	}
	
	public Iterator iterator(){
		return new ParniBrojeviIterator(prvi, brElemenata);
	}
	
}
