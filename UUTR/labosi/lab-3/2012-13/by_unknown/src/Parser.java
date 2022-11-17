import java.io.IOException;
import java.util.Scanner;


public class Parser {

	private static int pozicija = -1;
	private static char[] niz;
	private static boolean prihvacen = true;
	private static StringBuilder build = new StringBuilder(); 
	public static void main(String[] args) throws IOException {
		
//		Scanner s = new Scanner(new InputStreamReader(new FileInputStream("dat.txt"), StandardCharsets.UTF_8));
//		String ulaz;
//		int i = 1;
//		
//		while(s.hasNextLine()) {
//			pozicija = -1;
//			prihvacen = true;
//			build = new StringBuilder();
//			ulaz = s.nextLine();
//			niz = ulaz.toCharArray();
//			S();
//			if(pozicija < niz.length - 1) {
//				prihvacen = false;
//			}
//			
//			System.out.println(i++);
//			System.out.println(build.toString());
//			System.out.println(prihvacen == false ? "NE" : "DA");
//		}
		Scanner s = new Scanner(System.in, "UTF-8");
		
		String ulaz;
		
		
		ulaz = s.nextLine();
		niz = ulaz.toCharArray();
		s.close();
		S();
		if(pozicija < niz.length - 1) {
			prihvacen = false;
		}
		
		//System.out.println(i++);
		System.out.println(build.toString());
		System.out.println(prihvacen == false ? "NE" : "DA");
		
	}
	private static char citaj() {
		pozicija++;
		if(pozicija >= niz.length) {
			return '$';
		}
		return niz[pozicija];
	}
	private static void S() {
		build.append("S");
		char temp = citaj();
		if(temp == 'a') {
			A();
			if(prihvacen == false) {
				return;
			} 
			B();
		} else if (temp == 'b') {
			B();
			if(prihvacen == false) {
				return;
			}
			A();
		} else {
			prihvacen = false;
		}
	}
	
	private static void A() {
		build.append("A");
		char temp = citaj();
		if(temp == 'a') {
			
		} else if(temp == 'b') {
			C();
		} else {
			prihvacen = false;
		}
	}
	
	private static void B() {
		build.append("B");
		char temp = citaj();
		if(temp == '$') {
			
		} else if (temp == 'c') {
			temp = citaj();
			if(temp != 'c') {
				prihvacen = false;
			}
			if(prihvacen == false) {
				return;
			}
			S();
			temp = citaj();
			if(temp != 'b') {
				prihvacen = false;
			}
			temp = citaj();
			if(temp != 'c') {
				prihvacen = false;
			}
		} else if (temp != 'c' && temp != '$') {
			pozicija--;
			temp = '$';
		} else {
			prihvacen = false;
		}
	}

	private static void C() {
		build.append("C");
		A();
		if(prihvacen == false) {
			return;
		}
		A();
	}
}
