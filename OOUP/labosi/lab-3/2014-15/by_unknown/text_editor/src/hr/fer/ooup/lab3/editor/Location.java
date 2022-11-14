package hr.fer.ooup.lab3.editor;

import java.awt.Point;

public class Location {

	private Point location;
	
	public Location(Location location) {
		this.location = new Point(location.getX(), location.getY());
	}
	
	public Location(int x, int y) {
		this.location = new Point(x, y);
	}
	
	public void update(int dx, int dy) {
		location.x += dx;
		location.y += dy;
	}
	
	public int getX() {
		return location.x;
	}
	
	public int getY() {
		return location.y;
	}
	
	public Point getLocation() {
		return location;
	}
	
	public void setLocation(int x, int y) {
		location.x = x;
		location.y = y;
	}
	
	public void setLocation(Location location) {
		this.location = location.getLocation();
	}
	
	@Override
	public boolean equals(Object obj) {
		if(obj instanceof Location) {
			Location location = (Location)obj;
			if(this.location.equals(location.location)) {
				return true;
			}
		}
		return false;
	}
	
	@Override
	public String toString() {
		return "(" + location.x + "," + location.y + ")";
	}
}
