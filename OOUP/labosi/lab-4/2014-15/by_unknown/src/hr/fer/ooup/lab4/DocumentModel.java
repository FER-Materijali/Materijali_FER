package hr.fer.ooup.lab4;

import hr.fer.ooup.lab4.graphics.GraphicalObject;
import hr.fer.ooup.lab4.listener.DocumentModelListener;
import hr.fer.ooup.lab4.listener.GraphicalObjectListener;

import java.awt.Point;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;

public class DocumentModel {

	public final static double SELECTION_PROXIMITY = 10;
	
	private List<GraphicalObject> objects;
	private List<GraphicalObject> roObjects;
	
	private List<GraphicalObject> selectedObjects;
	private List<GraphicalObject> roSelectedObjects;
	
	private List<DocumentModelListener> listeners;
	private GraphicalObjectListener goListener = new GraphicalObjectListener() {
		
		@Override
		public void graphicalObjectSelectionChanged(GraphicalObject go) {
			int index = selectedObjects.indexOf(go);
			if(go.isSelected()) {
				if(index == -1) {
					selectedObjects.add(go);
				} else {
					return;
				}
			} else {
				if(index != -1) {
					selectedObjects.remove(index);
				} else {
					return;
				}
			}
			notifyListeners();
		}
		
		@Override
		public void graphicalObjectChanged(GraphicalObject go) {
			notifyListeners();
		}
	};
	
	public DocumentModel() {
		objects = new ArrayList<GraphicalObject>();
		roObjects = Collections.unmodifiableList(objects);
		selectedObjects = new ArrayList<GraphicalObject>();
		roSelectedObjects = Collections.unmodifiableList(selectedObjects);
		listeners = new ArrayList<DocumentModelListener>();
	}
	
	public void clear() {
		for (GraphicalObject go : objects) {
			go.removeGraphicalObjectListener(goListener);
		}
		objects.clear();
		selectedObjects.clear();
		notifyListeners();
	}
	
	public void addGraphicalObject(GraphicalObject go) {
		if(go.isSelected()) {
			selectedObjects.add(go);
		}
		objects.add(go);
		go.addGraphicalObjectListener(goListener);
		notifyListeners();
	}
	
	public void removeGraphicalObject(GraphicalObject go) {
		go.setSelected(false);
		go.removeGraphicalObjectListener(goListener);
		objects.remove(go);
		notifyListeners();
	}
	
	public List<GraphicalObject> list() {
		return roObjects;
	}
	
	public void addDocumentModelListener(DocumentModelListener listener) {
		listeners.add(listener);
	}
	
	public void removeDocumentModelListener(DocumentModelListener listener) {
		listeners.remove(listener);
	}
	
	public void notifyListeners() {
		for (DocumentModelListener documentModelListener : listeners) {
			documentModelListener.documentChanged();
		}
	}
	
	public List<GraphicalObject> getSelectedObjects() {
		return roSelectedObjects;
	}
	
	public void deselectAll() {
		//goListener will delete selected objects from list, we just have to "notify" him...see goListener methods at the beginning of this class
		while(selectedObjects.size() > 0) {
			selectedObjects.get(0).setSelected(false);
		}
	}
	
	public void increaseZ(GraphicalObject go) {
		int index = objects.indexOf(go);
		if(index != -1 && index < objects.size() - 1) {
			objects.set(index, objects.get(index + 1));
			objects.set(index + 1, go);
		}
		notifyListeners();
	}
	
	public void decreaseZ(GraphicalObject go) {
		int index = objects.indexOf(go);
		if(index != -1 && index > 0) {
			objects.set(index, objects.get(index - 1));
			objects.set(index - 1, go);
		}
		notifyListeners();
	}
	
	public GraphicalObject findSelectedGraphicalObject(Point mousePoint) {
		Map<Double, GraphicalObject> possibleSelections = new HashMap<Double, GraphicalObject>();
		for (GraphicalObject go : objects) {
			double distance = go.selectionDistance(mousePoint);
			if(distance <= SELECTION_PROXIMITY) {
				possibleSelections.put(distance, go);
			}
		}
		if(!possibleSelections.isEmpty()) {
			double min = SELECTION_PROXIMITY + 1;
			for (Entry<Double, GraphicalObject> entry : possibleSelections.entrySet()) {
				if(entry.getKey() < min) {
					min = entry.getKey();
				}
			}
			return possibleSelections.get(min);
		}
		return null;
	}
	
	public List<GraphicalObject> findSelectedGraphicalObjects(Point mousePoint) {
		List<GraphicalObject> gObjects = new ArrayList<GraphicalObject>();
		for (GraphicalObject go : objects) {
			if(go.selectionDistance(mousePoint) <= SELECTION_PROXIMITY/2) {
				gObjects.add(go);
			}
		}
		return gObjects;
	}
	
	public int findSelectedHotPoint(GraphicalObject go, Point mousePoint) {
		for (int i = 0; i < go.getNumberOfHotPoints(); i++) {
			if(go.getHotPointDistance(i, mousePoint) <= SELECTION_PROXIMITY) {
				return i;
			}
		}
		return -1;
	}
}