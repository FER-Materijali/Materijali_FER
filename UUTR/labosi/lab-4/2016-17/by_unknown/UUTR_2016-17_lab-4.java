import java.io.*;
import java.util.ArrayList;

public class Parser {
	
	static String ulaz;
	static String ispis;
	static ArrayList<String> ulazniNiz = new ArrayList<>();
	
	public static void main(String[] args) throws IOException {
		
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		String niz=reader.readLine();
		for (char c : niz.toCharArray()) {
			ulazniNiz.add(String.valueOf(c));
		}
		ispis="";
		boolean ok = S();
		System.out.println(ispis);
		if (ulazniNiz.isEmpty() && ok) {
			System.out.println("DA");
		}	
		else {
			System.out.println("NE");
		}	
		
	}

	private static boolean S() {
		boolean ok=false;
		ispis+="S";
		if (ulazniNiz.isEmpty())
			return false;
		ulaz=ulazniNiz.get(0);
		ulazniNiz.remove(0);
		switch (ulaz) {
			case ("a"):
				if (ok=A()) 
					ok=B(); 
				return ok;
			case ("b"):
				if (ok = B()) 
					ok=A(); 
				return ok;
			default:
				return false;
		}
	}

	private static boolean A() {
		ispis+="A";
		if (ulazniNiz.isEmpty())
			return false;
		switch (ulazniNiz.get(0)) {
			case ("a"):
				ulazniNiz.remove(0);
				return true;
			case ("b"):
				ulazniNiz.remove(0);
				return C();
			default: 
				return false;
		}
	}

	private static boolean B() {
		ispis+="B";
		if (ulazniNiz.isEmpty())
			return true;
		else {
			ulaz=ulazniNiz.get(0);
			if (ulaz.equals("c")) {
				ulazniNiz.remove(0);
				if (!ulazniNiz.isEmpty() && ulazniNiz.get(0).equals("c")) {
					ulazniNiz.remove(0);
					if (S() && !ulazniNiz.isEmpty() && ulazniNiz.get(0).equals("b")) {
						ulazniNiz.remove(0);
						if (!ulazniNiz.isEmpty() && ulazniNiz.get(0).equals("c")) {
							ulazniNiz.remove(0);
							return true;
						} else 
							return false;
					} else 
						return false;
				} else 
					return false;
			} else 
				return true;
		}
	}
	
	private static boolean C() {
		boolean ok = false;
		ispis+="C";
		if (ok = A())
			ok=A();
		return ok;	
	}

}
