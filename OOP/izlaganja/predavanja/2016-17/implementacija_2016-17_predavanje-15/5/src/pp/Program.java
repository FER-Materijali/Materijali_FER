package pp;

import java.util.Random;

public class Program {

	public static class Proizvodac implements Runnable {
		private int brojProizvoda;
		private Spremnik spremnik;

		public Proizvodac(int brojProizvoda, Spremnik spremnik) {
			super();
			this.brojProizvoda = brojProizvoda;
			this.spremnik = spremnik;
		};
		
		@Override
		public void run() {
			for(int i = 0; i < brojProizvoda; i++) {
				spremnik.postavi(i);
				try { Thread.sleep(200); } catch(Exception ignorable) {}
			}
		}
	}
	
	public static class Potrosac implements Runnable {
		private int brojProizvoda;
		private Spremnik spremnik;

		public Potrosac(int brojProizvoda, Spremnik spremnik) {
			super();
			this.brojProizvoda = brojProizvoda;
			this.spremnik = spremnik;
		};
		
		@Override
		public void run() {
			Random rand = new Random();
			for(int i = 0; i < brojProizvoda; i++) {
				Integer proizvod = spremnik.preuzmi();
				System.out.println(Thread.currentThread().getName() + " preuzeo: " + proizvod);
				try { Thread.sleep(500+rand.nextInt(1000)); } catch(Exception ignorable) {}
			}
		}
	}
	
	public static void main(String[] args) {
		Spremnik s = new Spremnik();
		new Thread(new Proizvodac(10, s)).start(); 
		new Thread(new Potrosac(5, s), "Potrosac1").start(); 
		new Thread(new Potrosac(5, s), "Potrosac2").start(); 
	}

}
