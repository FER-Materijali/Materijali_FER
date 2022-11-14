package hr.fer.ooup.lab4.render;

import java.awt.Point;

public interface Renderer {

	public void drawLine(Point start, Point end);
	public void fillPolygon(Point[] points);
}
