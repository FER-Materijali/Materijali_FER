package zadatak2;

import iteratori.Iterator;

public interface Drawing {
	
	void addShape(Shape pShape);
	void removeShape(String id);
	int nShapes();
	Iterator getIterator();
}
