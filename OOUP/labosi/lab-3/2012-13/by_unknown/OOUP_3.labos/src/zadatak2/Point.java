package zadatak2;


public class Point {
	double x=0;
	double y=0;
	
	
	public Point(double x, double y) {
		super();
		this.x = x;
		this.y = y;
	}


	@Override
	public String toString() {
		return "x:" + x + ",y:" + y;
	}
	
	
	
}
