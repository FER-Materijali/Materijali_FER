
// ---------------------------------------
// Ilustracija problema koji se javlja kad
// više dretvi radi nad dijeljenim 
// podatcima bez zaštite...
// ---------------------------------------

public class Primjer5 {

	private static class Posao implements Runnable {
		
		private long brojac = 0;
		
		@Override
		public void run() {
			System.out.println("Započinjem posao... " + Thread.currentThread().getName());
			for(int i = 0; i < 5_000_000; i++) {
				brojac++;
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
		
		System.out.println("Konačno stanje brojača je: " + p.brojac);
	}
	

}
