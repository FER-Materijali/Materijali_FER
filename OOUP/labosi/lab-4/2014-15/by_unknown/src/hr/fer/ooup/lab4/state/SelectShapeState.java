package hr.fer.ooup.lab4.state;

import java.awt.Point;
import java.awt.Rectangle;
import java.awt.event.KeyEvent;
import java.util.ArrayList;
import java.util.List;

import hr.fer.ooup.lab4.DocumentModel;
import hr.fer.ooup.lab4.composite.CompositeShape;
import hr.fer.ooup.lab4.graphics.GraphicalObject;
import hr.fer.ooup.lab4.render.Renderer;

public class SelectShapeState extends IdleState {
	
	private final static int HOT_POINT_BOUNDING_BOX_WIDTH = 3;
	
	private DocumentModel model;
	
	private GraphicalObject selectedGO;
	private int indexOfSelectedHotPoint;
	
	public SelectShapeState(DocumentModel model) {
		this.model = model;
	}
	
	@Override
	public void mouseDown(Point mousePoint, boolean shiftDown, boolean ctrlDown) {
		GraphicalObject go = model.findSelectedGraphicalObject(mousePoint);
		if(go == null) {
			selectedGO = null;
			model.deselectAll();
			return;
		}
		
		if(!ctrlDown) {
			model.deselectAll();
			go.setSelected(true);
			selectedGO = go;
			
		} else {
			selectedGO = null;
			if(!go.isSelected()) {
				go.setSelected(true);
			} else {
				go.setSelected(false);
			}
		}
	}
	
	@Override
	public void keyPressed(int keyCode) {
		switch (keyCode) {
		case KeyEvent.VK_LEFT:
			for (GraphicalObject go : model.getSelectedObjects()) {
				go.translate(new Point(-1, 0));
			}
			break;
			
		case KeyEvent.VK_RIGHT:
			for (GraphicalObject go : model.getSelectedObjects()) {
				go.translate(new Point(1, 0));
			}
			break;

		case KeyEvent.VK_UP:
			for (GraphicalObject go : model.getSelectedObjects()) {
				go.translate(new Point(0, -1));
			}
			break;
			
		case KeyEvent.VK_DOWN:
			for (GraphicalObject go : model.getSelectedObjects()) {
				go.translate(new Point(0, 1));
			}
			break;
			
		case KeyEvent.VK_ADD://numpad plus "+"
		case KeyEvent.VK_PLUS:
			List<GraphicalObject> selectedObjectsPlus = model.getSelectedObjects();
			if(!selectedObjectsPlus.isEmpty() && selectedObjectsPlus.size() == 1) {
				model.increaseZ(selectedObjectsPlus.get(0));
			}
			break;
			
		case KeyEvent.VK_SUBTRACT://numpad minus "-"	
		case KeyEvent.VK_MINUS:
			List<GraphicalObject> selectedObjectsMinus = model.getSelectedObjects();
			if(!selectedObjectsMinus.isEmpty() && selectedObjectsMinus.size() == 1) {
				model.decreaseZ(selectedObjectsMinus.get(0));
			}
			break;
			
		case KeyEvent.VK_G:
			List<GraphicalObject> selectedObjects = model.getSelectedObjects();
			if(!selectedObjects.isEmpty() && selectedObjects.size() > 1) {
				GraphicalObject[] compositeObjects = new GraphicalObject[selectedObjects.size()];
				for (int i = 0; i < compositeObjects.length; i++) {
					compositeObjects[i] = selectedObjects.get(0);
					model.removeGraphicalObject(selectedObjects.get(0));
				}
				GraphicalObject go = new CompositeShape(compositeObjects, false);
				model.addGraphicalObject(go);
				go.setSelected(true);
			}
			break;
			
		case KeyEvent.VK_U:
			List<GraphicalObject> selectedObjectsUngroup = model.getSelectedObjects();
			if(!selectedObjectsUngroup.isEmpty() && selectedObjectsUngroup.size() == 1 && selectedObjectsUngroup.get(0).getShapeName().equals("Composite")) {
				CompositeShape composite = (CompositeShape)selectedObjectsUngroup.get(0);
				GraphicalObject[] objects = composite.getObjects();
				model.removeGraphicalObject(composite);
				for (GraphicalObject go : objects) {
					go.setSelected(true);
					model.addGraphicalObject(go);
				}
			}
			break;
			
		default:
			break;
		}
	}
	
	@Override
	public void mouseDragged(Point mousePoint) {
		if(selectedGO != null && indexOfSelectedHotPoint >= 0) {
			if(selectedGO.isHotPointSelected(indexOfSelectedHotPoint)) {
				selectedGO.setHotPoint(indexOfSelectedHotPoint, mousePoint);
			}
		} else {
			if(selectedGO != null) {
				int index = model.findSelectedHotPoint(selectedGO, mousePoint);
				if(index != -1) {
					selectedGO.setHotPointSelected(index, true);
					indexOfSelectedHotPoint = index;
					selectedGO.setHotPoint(index, mousePoint);
				}
			}
		}
	}
	
	@Override
	public void mouseUp(Point mousePoint, boolean shiftDown, boolean ctrlDown) {
		if(selectedGO != null && indexOfSelectedHotPoint >= 0 && indexOfSelectedHotPoint < selectedGO.getNumberOfHotPoints()) {
			selectedGO.setHotPointSelected(indexOfSelectedHotPoint, false);
			indexOfSelectedHotPoint = -1;
		}
	}
	
	@Override
	public void afterDraw(Renderer r, GraphicalObject go) {
		if(!go.isSelected()) return;
		Rectangle rect = go.getBoundingBox();
		//drawing bounding box
		r.drawLine(new Point(rect.x, rect.y), new Point((int)rect.getMaxX(), rect.y));//upper line
		r.drawLine(new Point(rect.x, rect.y), new Point(rect.x, (int)rect.getMaxY()));//left line
		r.drawLine(new Point(rect.x, (int)rect.getMaxY()), new Point((int)rect.getMaxX(), (int)rect.getMaxY()));//bottom line
		r.drawLine(new Point((int)rect.getMaxX(), rect.y), new Point((int)rect.getMaxX(), (int)rect.getMaxY()));//right line
		
		
		if(selectedGO != null && selectedGO.equals(go)) {
			//draw hot points
			List<Point> hotPoints = new ArrayList<Point>();
			for (int i = 0; i < go.getNumberOfHotPoints(); i++) {
				hotPoints.add(go.getHotPoint(i));
			}
			for (Point point : hotPoints) {
				r.drawLine(new Point(point.x - HOT_POINT_BOUNDING_BOX_WIDTH, point.y - HOT_POINT_BOUNDING_BOX_WIDTH), 
						new Point(point.x + HOT_POINT_BOUNDING_BOX_WIDTH, point.y - HOT_POINT_BOUNDING_BOX_WIDTH));//upper line
				r.drawLine(new Point(point.x - HOT_POINT_BOUNDING_BOX_WIDTH, point.y - HOT_POINT_BOUNDING_BOX_WIDTH),
						new Point(point.x - HOT_POINT_BOUNDING_BOX_WIDTH, point.y + HOT_POINT_BOUNDING_BOX_WIDTH));//left line
				r.drawLine(new Point(point.x - HOT_POINT_BOUNDING_BOX_WIDTH, point.y + HOT_POINT_BOUNDING_BOX_WIDTH),
						new Point(point.x + HOT_POINT_BOUNDING_BOX_WIDTH, point.y + HOT_POINT_BOUNDING_BOX_WIDTH));//bottom line
				r.drawLine(new Point(point.x + HOT_POINT_BOUNDING_BOX_WIDTH, point.y - HOT_POINT_BOUNDING_BOX_WIDTH),
						new Point(point.x + HOT_POINT_BOUNDING_BOX_WIDTH, point.y + HOT_POINT_BOUNDING_BOX_WIDTH));//right line
			}
		}
	}
	
	@Override
	public void onLeaving() {
		selectedGO = null;
		model.deselectAll();
	}
}
