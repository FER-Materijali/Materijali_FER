package hr.fer.ooup.lab4.graphics;

import hr.fer.ooup.lab4.listener.GraphicalObjectListener;
import hr.fer.ooup.lab4.util.GeometryUtil;

import java.awt.Point;
import java.util.ArrayList;
import java.util.List;

public abstract class AbstractGraphicalObject implements GraphicalObject {

	private Point[] hotPoints;
	private boolean[] hotPointSelected;
	private boolean selected;
	private List<GraphicalObjectListener> listeners;
	
	public AbstractGraphicalObject(Point[] hotPoints) {
		this.hotPoints = hotPoints;
		hotPointSelected = new boolean[hotPoints.length];
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
		return hotPoints.length;
	}

	@Override
	public Point getHotPoint(int index) {
		if(index < hotPoints.length) {
			return hotPoints[index];
		}
		return null;
	}

	@Override
	public void setHotPoint(int index, Point point) {
		if(index < hotPoints.length) {
			hotPoints[index] = point;
		}
		notifyListeners();
	}

	@Override
	public boolean isHotPointSelected(int index) {
		if(index < hotPointSelected.length) {
			return hotPointSelected[index];
		}
		return false;
	}

	@Override
	public void setHotPointSelected(int index, boolean selected) {
		if(index < hotPointSelected.length) {
			hotPointSelected[index] = selected;
		}
	}

	@Override
	public double getHotPointDistance(int index, Point mousePoint) throws IndexOutOfBoundsException {
		if(index >= hotPoints.length) throw new IndexOutOfBoundsException(index + " is greater than " + hotPoints.length);
		return GeometryUtil.distanceFromPoint(hotPoints[index], mousePoint);
	}

	@Override
	public void translate(Point delta) {
		for (Point point : hotPoints) {
			point.x += delta.x;
			point.y += delta.y;
		}
		notifyListeners();
	}

	@Override
	public void addGraphicalObjectListener(GraphicalObjectListener listener) {
		listeners.add(listener);
	}

	@Override
	public void removeGraphicalObjectListener(
			GraphicalObjectListener listener) {
		listeners.remove(listener);
	}
	
	public void notifyListeners() {
		for (GraphicalObjectListener listener : listeners) {
			listener.graphicalObjectChanged(this);
		}
	}
	
	public void notifySelectionListeners() {
		for (GraphicalObjectListener listener : listeners) {
			listener.graphicalObjectSelectionChanged(this);
		}
	}
}
