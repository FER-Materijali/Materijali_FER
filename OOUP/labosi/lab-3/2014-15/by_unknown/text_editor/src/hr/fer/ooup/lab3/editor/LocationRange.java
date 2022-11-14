package hr.fer.ooup.lab3.editor;

public class LocationRange {

	private Location start;
	private Location end;
	
	public LocationRange() {
		start = new Location(0, 0);
		end = new Location(0, 0);
	}
	
	public LocationRange(LocationRange range) {
		this.start = new Location(range.getStart());
		this.end = new Location(range.getEnd());
	}
	
	public LocationRange(Location start, Location end) {
		this.start = start;
		this.end = end;
	}
	
	public int getNumOfLinesInRange() {
		return end.getX() - start.getX();
	}
	
	public void updateStart(int dx, int dy) {
		start.update(dx, dy);
	}
	
	public void updateEnd(int dx, int dy) {
		end.update(dx, dy);
	}
	
	public Location getStart() {
		return start;
	}
	
	public void setStart(Location start) {
		this.start = start;
	}
	
	public Location getEnd() {
		return end;
	}
	
	public void setEnd(Location end) {
		this.end = end;
	}
	
	public void setRange(LocationRange range) {
		this.start = range.getStart();
		this.end = range.getEnd();
	}
	
	@Override
	public boolean equals(Object obj) {
		if(obj instanceof LocationRange) {
			LocationRange range = (LocationRange)obj;
			if(this.start.equals(range.start) && this.end.equals(range.end)) {
				return true;
			}
		}
		return false;
	}
	
	@Override
	public String toString() {
		return "start: " + start + " end " + end;
	}
}
