package hr.fer.ooup.lab4.util;

import java.awt.Point;
import java.awt.geom.Line2D;

public class GeometryUtil {

	public static double distanceFromPoint(Point point1, Point point2) {
		return Math.hypot(Math.abs(point2.x - point1.x), Math.abs(point2.y - point1.y));
	}
	
	public static double distanceFromLineSegment(Point start, Point end, Point point) {
		return Line2D.ptSegDist(start.x, start.y, end.x, end.y, point.x, point.y);
	}
}
