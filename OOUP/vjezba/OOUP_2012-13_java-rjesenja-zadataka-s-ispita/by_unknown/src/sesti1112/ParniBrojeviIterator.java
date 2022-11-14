package sesti1112;

public class ParniBrojeviIterator implements Iterator {

	private Integer brElemenata;
	private Integer trenutni;
	
	public ParniBrojeviIterator(Integer prvi, Integer brElemenata) {
		super();
		this.brElemenata = brElemenata;
		trenutni=prvi;
	}

	@Override
	public Integer next() {
		// TODO Auto-generated method stub
		if (brElemenata==0) return null;
		Integer returnVal=trenutni;
		trenutni+=2;
		brElemenata--;
		return returnVal;
	}

	@Override
	public boolean hasNext() {
		// TODO Auto-generated method stub
		if (brElemenata==0) return false;
		return true;
	}
	
}
