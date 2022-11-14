package hr.fer.zemris.ooup.lab3.model.plugins;

import hr.fer.zemris.ooup.lab3.model.Animal;

public class Parrot extends Animal {

	private String animalName;
	
	public Parrot(String name) {
		this.animalName = name;
	}

	@Override
	public String name() {
		return animalName;
	}

	@Override
	public String greet() {
		return "Sto mu gromova!";
	}

	@Override
	public String menu() {
		return "brazilske orahe";
	}
}
