package hr.fer.ooup.lab4.state;

import hr.fer.ooup.lab4.graphics.GraphicalObject;
import hr.fer.ooup.lab4.render.Renderer;

import java.awt.Point;

public interface State {

	public void mouseDown(Point mousePoint, boolean shiftDown, boolean ctrlDown);
	public void mouseUp(Point mousePoint, boolean shiftDown, boolean ctrlDown);
	public void mouseDragged(Point mousePoint);
	public void keyPressed(int keyCode);
	
	public void afterDraw(Renderer r, GraphicalObject go);
	public void afterDraw(Renderer r);
	
	public void onLeaving();
}
