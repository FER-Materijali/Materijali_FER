package iteratori;

import java.util.TreeMap;

import zadatak2.Shape;


public class DrawingMapIterator implements Iterator{

	TreeMap<String, Shape> stabloOblika;
	String trenutniKljuc;
	
	
	public DrawingMapIterator(Object stablo) {
		super();
		this.stabloOblika = (TreeMap<String, Shape>) stablo;
		this.trenutniKljuc = ((TreeMap<String, Shape> ) stablo).firstKey();
	}
	
	
	@Override
	public Shape current() {
		stabloOblika.get(trenutniKljuc);
		return null;
	}

	
	@Override
	public Shape next() {
	
		Shape sljedeciOblik = null;
		sljedeciOblik=stabloOblika.get(trenutniKljuc);
		
		trenutniKljuc = stabloOblika.higherKey(trenutniKljuc);
		
		return sljedeciOblik;
	}

	
	@Override
	public boolean hasNext() {

		if(trenutniKljuc!=null){
			return true;
		}
		
		return false;
	}

	
}
