package hr.fer.zemris.ooup.lab3.factory;

import hr.fer.zemris.ooup.lab3.model.Animal;

import java.lang.reflect.Constructor;
import java.lang.reflect.InvocationTargetException;

public class AnimalFactory {

	public static Animal newInstance(String animalKind, String name) throws ClassNotFoundException, NoSuchMethodException, SecurityException, InstantiationException, IllegalAccessException, IllegalArgumentException, InvocationTargetException {
		@SuppressWarnings("unchecked")
		Class<Animal> clazz = (Class<Animal>)Class.forName("hr.fer.zemris.ooup.lab3.model.plugins." + animalKind);
		Constructor<?> ctr = clazz.getConstructor(String.class);
		return (Animal)ctr.newInstance(name);
	}
}
