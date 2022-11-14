package hr.fer.ooup.lab4.render;

import java.awt.Color;
import java.awt.Graphics2D;
import java.awt.Point;

public class G2DRendererImpl implements Renderer {
	
	private Graphics2D g2d;
	
	public G2DRendererImpl(Graphics2D g2d) {
		this.g2d = g2d;
	}
	
	@Override
	public void drawLine(Point start, Point end) {
		g2d.setColor(Color.BLUE);
		g2d.drawLine(start.x, start.y, end.x, end.y);
	}

	@Override
	public void fillPolygon(Point[] points) {
		int[] xpoints = new int[points.length];
		int[] ypoints = new int[points.length];
		for (int i = 0; i < points.length; i++) {
			xpoints[i] = points[i].x;
			ypoints[i] = points[i].y;
		}
		
		g2d.setColor(Color.BLUE);
		g2d.fillPolygon(xpoints, ypoints, points.length);
		g2d.setColor(Color.RED);
		g2d.drawPolygon(xpoints, ypoints, points.length);
	}

}
