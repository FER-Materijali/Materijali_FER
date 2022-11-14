package hr.fer.oop.lab1;

/**
 * 
 * @author dinomario10
 */
public class IspisIznadprosjecnih {

	public static void main(String[] args) {
		double prosjekZnakova = izracunajProsjekZnakova(args);
		ispisiZnakove(args, prosjekZnakova);
	}

	/**
	 * Ra?na prosjek znakova argumenata dijeljenjem ukupnog broja znakova sa
	 * brojem argumenata.
	 * 
	 * @param args
	 *            argumenti pri pozivu programa
	 * @param sumaZnakova
	 *            ukupni broj znakova (bez razmaka) svih argumenata
	 * @return Vra? prosjek znakova svih argumenata
	 */
	private static double izracunajProsjekZnakova(String[] args) {
		int sumaZnakova = 0;
		for (int i = 0; i < args.length; i++) {
			sumaZnakova += args[i].length();
		}
		return 1.0 * sumaZnakova / args.length;
	}

	/**
	 * Ispisuje argumente koji imaju ve? broj znakova od prosjeka, s tim da pri
	 * ispisu izostavlja prvi i zadnji znak argumenta.
	 * 
	 * @param args
	 *            argumenti pri pozivu programa
	 * @param prosjekZnakova
	 *            - prosjek znakova svih argmenata
	 */
	private static void ispisiZnakove(String[] args, double prosjekZnakova) {
		System.out.printf("Argumenti s ve?m brojem znakova od prosjeka (%.2f):%n", prosjekZnakova);
		for (int i = 0; i < args.length; i++) {
			if (args[i].length() > prosjekZnakova) {
				System.out.println(args[i].substring(1, args[i].length() - 1));
			}
		}
	}
}
