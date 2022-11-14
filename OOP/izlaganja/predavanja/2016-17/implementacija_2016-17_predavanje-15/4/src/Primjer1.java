
// ---------------------------------------
// Modeliranje posla zasebnim objektom
//  - preporučeno
// ---------------------------------------

public class Primjer1 {

	private static class Posao implements Runnable {
		@Override
		public void run() {
			System.out.println("Započinjem posao... " + Thread.currentThread().getName());
			for(int i = 0; i < 5; i++) {
				System.out.println("Broj je: " + (i+1) + " " + Thread.currentThread().getName());
				try { 
					Thread.sleep(1000);
				} catch(Exception ignorable) {
				}
			}
			System.out.println("Gotov s poslom... " + Thread.currentThread().getName());
		}
	}
	
	public static void main(String[] args) {
		Posao p = new Posao();
		Thread t1 = new Thread(p);
		t1.start();
		Thread t2 = new Thread(p);
		t2.start();
		
		p.run();
		
		System.out.println("Main je gotov!");
	}
	

}
