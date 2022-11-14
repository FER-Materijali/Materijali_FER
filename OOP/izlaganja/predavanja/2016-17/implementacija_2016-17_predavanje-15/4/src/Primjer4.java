
// ---------------------------------------
// Dretva main čeka dretve radnike metodom
// join
//  - preporučeno
// ---------------------------------------

public class Primjer4 {

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
		
		Thread[] radnici = new Thread[4];
		for(int i = 0; i < radnici.length; i++) {
			radnici[i] = new Thread(p);
			radnici[i].start();
		}
		
		for(int i = 0; i < radnici.length; i++) {
			try {
				radnici[i].join();
			} catch(Exception ignorable) {
			}
		}
		
		System.out.println("Main je gotov!");
	}
	

}
