package zadatak3dodatak;

public class NapitakSaSecerom extends Dekorator{

	Integer kolicinaSecera;
	
	
	public NapitakSaSecerom(Beverage napitak, int kolicinaSecera) {
		super(napitak);
		this.kolicinaSecera = kolicinaSecera;
	}

	
	@Override
	void addCondiment() {
		System.out.println("Dodajem " + kolicinaSecera.toString() + " grama šećera");
	}
	

}
