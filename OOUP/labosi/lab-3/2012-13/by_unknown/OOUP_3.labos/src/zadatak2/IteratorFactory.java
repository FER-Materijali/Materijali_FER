package zadatak2;

import iteratori.Iterator;

import java.lang.reflect.Constructor;
import java.lang.reflect.InvocationTargetException;

public class IteratorFactory {

	@SuppressWarnings("unchecked")
	public static Iterator newInstance(String iteratorKind, Object listaIliStablo) {

		Class<Iterator> klasa = null;

		try {
			klasa = (Class<Iterator>) Class.forName("iteratori." + iteratorKind);
		} catch (ClassNotFoundException e) {
			e.printStackTrace();
		}

		Constructor<?> konstruktor = null;

		try {
			konstruktor = klasa.getConstructor(Object.class);
		} catch (NoSuchMethodException | SecurityException e) {
			e.printStackTrace();
		}

		Iterator iterator = null;
		
		try {
			iterator = (Iterator) konstruktor.newInstance(listaIliStablo);
		} catch (InstantiationException | IllegalAccessException
				| IllegalArgumentException | InvocationTargetException e) {
			e.printStackTrace();
		}
		

		return iterator;
	}


	
}
