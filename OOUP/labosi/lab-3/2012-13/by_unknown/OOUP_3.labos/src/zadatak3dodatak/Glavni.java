package zadatak3dodatak;

public class Glavni {


	public static void main(String[] args) {
		
		System.out.println("Čaj:");
		Beverage napitak = new Tea();
		NapitakSaSecerom cajSaSecerom = new NapitakSaSecerom(napitak, 10);
		cajSaSecerom.prepare();
		
		System.out.println("\n\n");
		
		System.out.println("Kava:");
		Beverage napitak2 = new Tea();
		NapitakSaSecerom kavaSaSecerom = new NapitakSaSecerom(napitak2, 20);
		kavaSaSecerom.prepare();
		
		System.out.println("\n\n");

	}

}
