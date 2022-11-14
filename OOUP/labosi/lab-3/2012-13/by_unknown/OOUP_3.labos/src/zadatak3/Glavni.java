package zadatak3;

public class Glavni {


	public static void main(String[] args) {
		
		System.out.println("Čaj:");
		Beverage napitakCaj = new Tea();
		napitakCaj.prepare();
		
		System.out.println("\n\n");
		
		System.out.println("Kava:");
		Beverage napitakKava = new Coffee();
		napitakKava.prepare();

	}

}
