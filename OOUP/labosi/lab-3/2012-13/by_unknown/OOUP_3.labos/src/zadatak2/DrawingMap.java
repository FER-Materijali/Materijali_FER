package zadatak2;

import iteratori.Iterator;

import java.util.TreeMap;

public class DrawingMap implements Drawing{

	
	TreeMap<String, Shape> stablo = new TreeMap<String, Shape>();
	
	
	@Override
	public void addShape(Shape pShape) {
		stablo.put(pShape.id(), pShape);
	}
	

	@Override
	public void removeShape(String id) {
		stablo.remove(id);
	}

	
	@Override
	public int nShapes() {
		return stablo.size();
	}

	
	@Override
	public Iterator getIterator() {
		return IteratorFactory.newInstance("DrawingMapIterator", stablo);
	}

	
	
}
