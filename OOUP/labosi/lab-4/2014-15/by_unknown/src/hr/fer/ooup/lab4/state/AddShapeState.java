package hr.fer.ooup.lab4.state;

import hr.fer.ooup.lab4.DocumentModel;
import hr.fer.ooup.lab4.graphics.GraphicalObject;

import java.awt.Point;

public class AddShapeState extends IdleState {
	
	private GraphicalObject prototype;
	private DocumentModel model;

	public AddShapeState(DocumentModel model, GraphicalObject prototype) {
		this.prototype = prototype;
		this.model = model;
	}
	
	@Override
	public void mouseDown(Point mousePoint, boolean shiftDown, boolean ctrlDown) {
			GraphicalObject go = prototype.duplicate();
			go.translate(mousePoint);
			model.addGraphicalObject(go);
	}
}
