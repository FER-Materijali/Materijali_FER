package zadatak2;

import iteratori.Iterator;

import java.util.ArrayList;

public class DrawingVector implements Drawing {


	ArrayList<Shape> vektor = new ArrayList<Shape>();
	
	
	@Override
	public void addShape(Shape pShape) {
		System.out.println("U listu vektora dodajem oblik sa IDom:" + pShape.id());
		vektor.add(pShape);
	}

	
	@Override
	public void removeShape(String id) {
		
		for (Shape tempOblik : vektor){
			if (tempOblik.id().equals(id)){
				System.out.println("Iz liste vektora brišem oblik sa IDom:" + tempOblik.id());
				vektor.remove(tempOblik);
				return;
			}
		}

		System.out.println("Ne postoji oblik sa IDom:" + id);
		return;

	}


	@Override
	public int nShapes() {
		System.out.println("Veličina vektora je:" + vektor.size());
		return vektor.size();
	}

	@Override
	public Iterator getIterator() {
		return IteratorFactory.newInstance("DrawingVectorIterator", vektor);
	}


}
