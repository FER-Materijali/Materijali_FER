package jesenski1112;

public class IspitniProgram {
	
	public static void main(String args[]){
		Monster m1=new Monster(new MoveRandom());
		Monster m2=new Monster(new MoveTowardsPlayer());
		Monster m3=new Monster(new MoveWithPrediction());
		
		m1.move();
		m2.move();
		m3.move();
	}

}
