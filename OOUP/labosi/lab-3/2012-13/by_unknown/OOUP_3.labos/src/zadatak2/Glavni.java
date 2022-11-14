package zadatak2;

import java.util.ArrayList;
import java.util.List;

import iteratori.Iterator;

public class Glavni {


	public static void main(String[] args) {
		
		List<Shape> listaOblika = new ArrayList<Shape>(); 
		
		listaOblika.add(new ShapeLineSegment(new Point(1, 1), new Point(2, 2)));
		listaOblika.add(new ShapeLineSegment(new Point(3, 3), new Point(4, 4)));
		listaOblika.add(new ShapeLineSegment(new Point(5, 5), new Point(6, 6)));
		listaOblika.add(new ShapeLineSegment(new Point(7, 7), new Point(8, 8)));
	
		
		
		//VEKTOR
		Drawing crtezVektor = new DrawingVector();
		
		for (Shape linija: listaOblika){
			crtezVektor.addShape(linija);
		}
		
		System.out.println("\n\nIteriram po vektoru:");
		
		Iterator iteratorVektora = crtezVektor.getIterator();
		
		while (iteratorVektora.hasNext()){
			System.out.println(iteratorVektora.next());
		}
		
		
		
		//STABLO
		Drawing crtezStablo = new DrawingMap();
		for (Shape linija: listaOblika){
			crtezStablo.addShape(linija);
		}
		
		System.out.println("\n\nIteriram po stablu:");
		
		Iterator iteratorStabla = crtezStablo.getIterator();
		
		while (iteratorStabla.hasNext()){
			System.out.println(iteratorStabla.next());
		}

	}

}
