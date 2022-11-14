package drugi1112;

public class Atom implements Komponenta{

	private String ime;
	private int cijena;
	
	public Atom(String ime, int cijena) {
		super();
		this.ime = ime;
		this.cijena = cijena;
	}

	@Override
	public String ime() {
		// TODO Auto-generated method stub
		return ime;
	}

	@Override
	public int cijena() {
		// TODO Auto-generated method stub
		return cijena;
	}

	@Override
	public void addChild(Komponenta k) {
		// TODO Auto-generated method stub
		System.err.println("Ne možeš staviti elemente u atom!");
	}

	@Override
	public void removeChild(Komponenta k) {
		// TODO Auto-generated method stub
		System.err.println("Ne možeš maknuti elemente s atoma!");
	}

	@Override
	public Komponenta getChild(int n) {
		// TODO Auto-generated method stub
		System.err.println("Atom ne sadrži druge elemente!");
		return null;
	}

	@Override
	public Komponenta getCopy() {
		// TODO Auto-generated method stub
		return new Atom(this.ime, this.cijena);
	}

	
	
}
