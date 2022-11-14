package hr.fer.ooup.lab4.graphics;

import hr.fer.ooup.lab4.render.Renderer;
import hr.fer.ooup.lab4.util.GeometryUtil;

import java.awt.Dimension;
import java.awt.Point;
import java.awt.Rectangle;
import java.util.List;
import java.util.Stack;

public class LineSegment extends AbstractGraphicalObject {

	public LineSegment() {
		super(new Point[]{ new Point(0, 0), new Point(10, 0) });
	}
	
	public LineSegment(Point hotPoint1, Point hotPoint2) {
		super(new Point[]{ hotPoint1, hotPoint2 });
	}

	@Override
	public Rectangle getBoundingBox() {
		Point point1 = getHotPoint(0);
		Point point2 = getHotPoint(1);
		
		int x = point1.x < point2.x ? point1.x : point2.x;
		int y = point1.y < point2.y ? point1.y : point2.y;
		
		return new Rectangle(new Point(x, y), new Dimension(Math.abs(point1.x - point2.x), Math.abs(point1.y - point2.y)));
	}

	@Override
	public double selectionDistance(Point mousePoint) {
		return GeometryUtil.distanceFromLineSegment(getHotPoint(0), getHotPoint(1), mousePoint);
	}

	@Override
	public String getShapeName() {
		return "Linija";
	}

	@Override
	public GraphicalObject duplicate() {
		return new LineSegment(new Point(getHotPoint(0)), new Point(getHotPoint(1)));
	}

	@Override
	public void render(Renderer r) {
		r.drawLine(getHotPoint(0), getHotPoint(1));	
	}

	@Override
	public String getShapeID() {
		return "@LINE";
	}

	@Override
	public void save(List<String> rows) {
		Point start = getHotPoint(0);
		Point end = getHotPoint(1);
		rows.add(String.format("%s %d %d %d %d", getShapeID(), start.x, start.y, end.x, end.y));
	}

	@Override
	public void load(Stack<GraphicalObject> stack, String data) {
		String[] coordinates = data.trim().split(" ");
		setHotPoint(0, new Point(Integer.parseInt(coordinates[0]), Integer.parseInt(coordinates[1])));//start point
		setHotPoint(1, new Point(Integer.parseInt(coordinates[2]), Integer.parseInt(coordinates[3])));//end point
		stack.push(this);
	}
}
