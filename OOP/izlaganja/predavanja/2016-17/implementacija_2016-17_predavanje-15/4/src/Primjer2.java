
// ---------------------------------------
// Izravno povezivanje posla i dretve koja
// ga izvodi
//  - NIJE preporučeno; komentirali smo
//    na predavanjima
// ---------------------------------------

public class Primjer2 {

	private static class DretvaSPoslom extends Thread {
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
		DretvaSPoslom d1 = new DretvaSPoslom();
		DretvaSPoslom d2 = new DretvaSPoslom();

		d1.start();
		d2.start();
		
		System.out.println("Main je gotov!");
	}
	

}
