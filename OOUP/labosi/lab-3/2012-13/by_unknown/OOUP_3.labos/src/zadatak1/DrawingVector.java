package zadatak1;

import java.util.ArrayList;

public class DrawingVector implements Drawing {

	//Vector vektor = new Vector();
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
	public Shape getShape(int i) {
		System.out.println("Tražim oblik na "+ i + ". toj poziciji u vektoru");
		return vektor.get(i);
	}

	@Override
	public int nShapes() {
		System.out.println("Veličina vektora je:" + vektor.size());
		return vektor.size();
	}


}
