package pp;

import java.util.Random;
import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.BlockingQueue;

public class Program2 {

	public static class Proizvodac implements Runnable {
		private int brojProizvoda;
		private BlockingQueue<Integer> spremnik;

		public Proizvodac(int brojProizvoda, BlockingQueue<Integer> spremnik) {
			super();
			this.brojProizvoda = brojProizvoda;
			this.spremnik = spremnik;
		};
		
		@Override
		public void run() {
			for(int i = 0; i < brojProizvoda; i++) {
				try { spremnik.put(i); } catch(Exception ignorable) {}
				try { Thread.sleep(200); } catch(Exception ignorable) {}
			}
		}
	}
	
	public static class Potrosac implements Runnable {
		private int brojProizvoda;
		private BlockingQueue<Integer> spremnik;

		public Potrosac(int brojProizvoda, BlockingQueue<Integer> spremnik) {
			super();
			this.brojProizvoda = brojProizvoda;
			this.spremnik = spremnik;
		};
		
		@Override
		public void run() {
			Random rand = new Random();
			for(int i = 0; i < brojProizvoda; i++) {
				try {
					Integer proizvod = spremnik.take();
					System.out.println(Thread.currentThread().getName() + " preuzeo: " + proizvod);
				} catch(Exception ignorable) {}
				try { Thread.sleep(500+rand.nextInt(1000)); } catch(Exception ignorable) {}
			}
		}
	}
	
	public static void main(String[] args) {
		BlockingQueue<Integer> s = new ArrayBlockingQueue<>(1);
		new Thread(new Proizvodac(10, s)).start(); 
		new Thread(new Potrosac(5, s), "Potrosac1").start(); 
		new Thread(new Potrosac(5, s), "Potrosac2").start(); 
	}

}
