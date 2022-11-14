package zadatak3dodatak;

public abstract class Dekorator extends Beverage{

	private Beverage napitak;
	

	public Dekorator(Beverage napitak) {
		super();
		this.napitak = napitak;
	}


	@Override
	void brew() {
		napitak.brew();
	}


}
