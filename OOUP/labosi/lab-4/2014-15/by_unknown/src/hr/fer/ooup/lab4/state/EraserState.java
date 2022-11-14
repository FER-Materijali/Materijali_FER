package hr.fer.ooup.lab4.state;

import java.awt.Point;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

import hr.fer.ooup.lab4.DocumentModel;
import hr.fer.ooup.lab4.graphics.GraphicalObject;
import hr.fer.ooup.lab4.render.Renderer;

public class EraserState extends IdleState {

	private DocumentModel model;
	private List<Point> points;
	
	public EraserState(DocumentModel model) {
		this.model = model;
		points = new ArrayList<Point>();
	}
	
	@Override
	public void mouseDragged(Point mousePoint) {
		points.add(mousePoint);
		model.notifyListeners();
	}
	
	@Override
	public void mouseUp(Point mousePoint, boolean shiftDown, boolean ctrlDown) {
		points.add(mousePoint);
		Set<GraphicalObject> objectsToDelete = new HashSet<GraphicalObject>();
		for (Point point : points) {
			objectsToDelete.addAll(model.findSelectedGraphicalObjects(point));
		}
		for (GraphicalObject go : objectsToDelete) {
			model.removeGraphicalObject(go);
		}
		points.clear();
		model.notifyListeners();
	}
	
	@Override
	public void afterDraw(Renderer r) {
		int length = points.size();
		for (int i = 0; i < length - 1; i++) {
			r.drawLine(points.get(i), points.get(i + 1));
		}
	}
}
