package zadatak3dodatak;

public abstract class Beverage {

	abstract void brew();
	abstract void addCondiment();

	
	public void prepare() {
		boilWater();
		brew();
		addCondiment();
		pourOutWater();
	}

	
	final void boilWater() {
		System.out.println("Zakuhamo vodu");
	}

	final void pourOutWater() {
		System.out.println("Izlijemo u posudu");
	}

}
