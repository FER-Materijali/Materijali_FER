package hr.fer.ooup.lab4.graphics;

import hr.fer.ooup.lab4.listener.GraphicalObjectListener;
import hr.fer.ooup.lab4.render.Renderer;

import java.awt.Point;
import java.awt.Rectangle;
import java.util.List;
import java.util.Stack;

public interface GraphicalObject {

	//object manipulation
	public boolean isSelected();
	public void setSelected(boolean selected);
	public int getNumberOfHotPoints();
	public Point getHotPoint(int index);
	public void setHotPoint(int index, Point point);
	public boolean isHotPointSelected(int index);
	public void setHotPointSelected(int index, boolean selected);
	public double getHotPointDistance(int index, Point mousePoint);
	
	//geometrical operations
	public void translate(Point delta);
	public Rectangle getBoundingBox();
	public double selectionDistance(Point mousePoint);
	
	//observer methods
	public void addGraphicalObjectListener(GraphicalObjectListener listener);
	public void removeGraphicalObjectListener(GraphicalObjectListener listener);
	
	//drawing the object
	public void render(Renderer r);
	
	//prototype support methods
	public String getShapeName();
	public GraphicalObject duplicate();
	
	//support for save and load
	public String getShapeID();
	public void save(List<String> rows);
	public void load(Stack<GraphicalObject> stack, String data);
}
