package jesenski1112;

public class Monster {
	
	private MovingStrategy m;

	public Monster(MovingStrategy m) {
		super();
		this.m = m;
	}
	
	public void move(){
		m.move();
	}

}
