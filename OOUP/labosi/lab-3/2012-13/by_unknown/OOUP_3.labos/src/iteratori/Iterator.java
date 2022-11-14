package iteratori;

import zadatak2.Shape;

public interface Iterator {
	Shape current();
	Shape next();
	boolean hasNext();
}
