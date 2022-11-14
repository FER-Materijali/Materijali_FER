package hr.fer.zemris.ooup.lab3;

import hr.fer.zemris.ooup.lab3.factory.AnimalFactory;
import hr.fer.zemris.ooup.lab3.model.Animal;

/**
 * 
 * @author hendrix
 *
 */
public class Main {

	public static void main(String[] args) {
		try {
			Animal parrot = AnimalFactory.newInstance("Parrot", "Modrobradi");
			Animal tiger = AnimalFactory.newInstance("Tiger", "Straško");
			
			parrot.animalPrintGreeting();
			tiger.animalPrintGreeting();
			
			parrot.animalPrintMenu();
			tiger.animalPrintMenu();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}
