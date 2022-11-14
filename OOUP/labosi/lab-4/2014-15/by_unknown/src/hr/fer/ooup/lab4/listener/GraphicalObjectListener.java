package hr.fer.ooup.lab4.listener;

import hr.fer.ooup.lab4.graphics.GraphicalObject;

public interface GraphicalObjectListener {

	public void graphicalObjectChanged(GraphicalObject go);
	public void graphicalObjectSelectionChanged(GraphicalObject go);
}
