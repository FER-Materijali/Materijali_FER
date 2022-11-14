package hr.fer.ooup.lab4.composite;

import hr.fer.ooup.lab4.graphics.GraphicalObject;
import hr.fer.ooup.lab4.listener.GraphicalObjectListener;
import hr.fer.ooup.lab4.render.Renderer;

import java.awt.Dimension;
import java.awt.Point;
import java.awt.Rectangle;
import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

public class CompositeShape implements GraphicalObject {

	private GraphicalObject[] objects;
	private boolean selected;
	private List<GraphicalObjectListener> listeners;
	
	public CompositeShape() {
		this.selected = false;
		listeners = new ArrayList<GraphicalObjectListener>();
	}
	
	public CompositeShape(GraphicalObject[] objects, boolean selected) {
		this.objects = objects;
		this.selected = selected;
		listeners = new ArrayList<GraphicalObjectListener>();
	}
	
	@Override
	public boolean isSelected() {
		return selected;
	}

	@Override
	public void setSelected(boolean selected) {
		this.selected = selected;
		notifySelectionListeners();
	}

	@Override
	public int getNumberOfHotPoints() {
		return 0;
	}

	@Override
	public Point getHotPoint(int index) {
		return null;
	}

	@Override
	public void setHotPoint(int index, Point point) {}

	@Override
	public boolean isHotPointSelected(int index) {
		return false;
	}

	@Override
	public void setHotPointSelected(int index, boolean selected) {}

	@Override
	public double getHotPointDistance(int index, Point mousePoint) {
		return Double.MAX_VALUE;
	}

	@Override
	public void translate(Point delta) {
		for (GraphicalObject object : objects) {
			object.translate(delta);
		}
		notifyObservers();
	}

	@Override
	public Rectangle getBoundingBox() {
		Rectangle rect = objects[0].getBoundingBox();
		int minX = (int)rect.getMinX();
		int maxX = (int)rect.getMaxX();
		int minY = (int)rect.getMinY();
		int maxY = (int)rect.getMaxY();
		
		for (int i = 1; i < objects.length; i++) {
			rect = objects[i].getBoundingBox();
			minX = rect.getMinX() < minX ? (int)rect.getMinX() : minX;
			maxX = rect.getMaxX() > maxX ? (int)rect.getMaxX() : maxX;
			minY = rect.getMinY() < minY ? (int)rect.getMinY() : minY;
			maxY = rect.getMaxY() > maxY ? (int)rect.getMaxY() : maxY;
		}
		
		return new Rectangle(new Point(minX, minY), new Dimension(maxX - minX, maxY - minY));
	}
	
	public GraphicalObject[] getObjects() {
		return objects;
	}
	
	public void setObjects(GraphicalObject[] objects) {
		this.objects = objects;
	}

	@Override
	public double selectionDistance(Point mousePoint) {
		if(objects.length == 0) {
			return Double.MAX_VALUE;
		}
		
		double[] distances = new double[objects.length];
		for (int i = 0; i < objects.length; i++) {
			distances[i] = objects[i].selectionDistance(mousePoint);
		}
		
		double min = distances[0];
		for (int i = 1; i < distances.length; i++) {
			if(distances[i] < min) {
				min = distances[i];
			}
		}
		return min;
	}

	@Override
	public void addGraphicalObjectListener(GraphicalObjectListener listener) {
		listeners.add(listener);
	}

	@Override
	public void removeGraphicalObjectListener(GraphicalObjectListener listener) {
		listeners.remove(listener);
	}

	@Override
	public void render(Renderer r) {
		for (GraphicalObject object : objects) {
			object.render(r);
		}
	}

	@Override
	public String getShapeName() {
		return "Composite";
	}

	@Override
	public GraphicalObject duplicate() {
		GraphicalObject[] gObjects = new GraphicalObject[objects.length];
		for (int i = 0; i < objects.length; i++) {
			gObjects[i] = objects[i].duplicate();
		}
		return new CompositeShape(gObjects, false);
	}
	
	private void notifyObservers() {
		for (GraphicalObjectListener graphicalObjectListener : listeners) {
			graphicalObjectListener.graphicalObjectChanged(this);
		}
	}
	
	public void notifySelectionListeners() {
		for (GraphicalObjectListener listener : listeners) {
			listener.graphicalObjectSelectionChanged(this);
		}
	}

	@Override
	public String getShapeID() {
		return "@COMP";
	}

	@Override
	public void save(List<String> rows) {
		for (GraphicalObject go : objects) {
			go.save(rows);
		}
		rows.add(String.format("%s %d", getShapeID(), objects.length));
	}

	@Override
	public void load(Stack<GraphicalObject> stack, String data) {
		int numOfObjects = Integer.parseInt(data.trim());
		GraphicalObject[] gObjects = new GraphicalObject[numOfObjects];
		for (int i = 0; i < numOfObjects; i++) {
			gObjects[i] = stack.pop();
		}
		objects = gObjects;
		stack.push(this);
	}
}
