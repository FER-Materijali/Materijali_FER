package zadatak1;


public interface Drawing {
	
	void addShape(Shape pShape);
	void removeShape(String id);
	Shape getShape(int i);
	int nShapes();
}
