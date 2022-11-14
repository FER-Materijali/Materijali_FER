package iteratori;

import java.util.ArrayList;
import zadatak2.Shape;


public class DrawingVectorIterator implements Iterator{

	ArrayList<Shape> listaOblika;
	int trenutniIndeks;
	
	
	public DrawingVectorIterator(Object lista) {
		super();
		this.listaOblika = (ArrayList<Shape>)lista;
		this.trenutniIndeks = 0;
	}

	
	@Override
	public Shape current() {
		return listaOblika.get(trenutniIndeks);
	}

	
	@Override
	public Shape next() {
		
		//ako smo došli do kraja liste, vrati null
		if(trenutniIndeks == listaOblika.size() ){
			return null;
		}
		
		Shape zaVratiti = listaOblika.get(trenutniIndeks);
		trenutniIndeks++;
		
		return zaVratiti;
	}

	
	@Override
	public boolean hasNext() {
		return (!(trenutniIndeks == listaOblika.size()));
	}

}
