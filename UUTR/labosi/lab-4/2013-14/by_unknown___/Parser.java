import java.io.IOException;
import java.util.*;

/** Parser ostvaren tehnikom rekurzivnog spusta
 * za gramatiku {S -> aAB|bBA} {A->bC|a} 
 * {B->ccSbc|$}  {C->AA}   
 * rezultati na SPRUT-u 20/20
 * 
 */
public class Parser {
	private static Stack<String> niz= new Stack<String>();
	
	public static void main(String[] args) throws IOException  {
		Scanner input = new Scanner(System.in);
		String[] tmp = input.nextLine().split("");
			
		for(int j = tmp.length-1; j >0; j--)
			niz.push(tmp[j]);
	
		boolean prihvatljiv = S();
		System.out.println();
		
		if(!prihvatljiv || !niz.empty()) {
			System.out.println("NE");
			
		} else {
			System.out.println("DA");
		}
	}
	
	/** Funkcija koja provjerava je li
	 * zadovoljena produkcija gramatike :
	 * S->aAB | bBA
	 * @return true ako je jedna od produkcija zadovoljena,
	 * false inace
	 */
	private static boolean S() {
		System.out.print("S");
		boolean check = false;
		try {
			String s = niz.pop();
			if(s.equals("a")) {
				check = A();
				if(check) check = B();
				//else return false;
			} else if(s.equals("b")) {
				check = B();
				if(check) check = A();
				//else return false;
			} 
		} catch (EmptyStackException ese) {
			return false;
		}
		return check;
	}
	
	/** Funkcija koja provjerava je li
	 * zadovoljena produkcija gramatike :
	 * A->bC | a
	 * @return true ako je jedna od produkcija zadovoljena,
	 * false inace
	 */
	private static boolean A() {
		System.out.print("A");
		boolean check = false;
		try {
			String s = niz.pop();
			if(s.equals("b")) {
				check = C();
			} else if(s.equals("a")) check = true;
		} catch (EmptyStackException ese) {
			return false;
		}
		return check;
	}
	
	/** Funkcija koja provjerava je li
	 * zadovoljena produkcija gramatike :
	 * B->ccSbc | $
	 * @return true ako je jedna od produkcija zadovoljena,
	 * false inace
	 */
	private static boolean B() {
		System.out.print("B");
		boolean check = false;
		boolean prvi = false;
		if(niz.empty()) return true;
		String s = "";
		try {
			s = niz.pop(); 
			prvi = true;
			s += niz.pop();
			String s1 = s.split("")[1];
			String s2 = s.split("")[2];
			if(s.equals("cc")) {
				check = S();
				if(check) {
					s = niz.pop() + niz.pop();
					if(s.equals("bc")) check = true;
					else check = false;
				}
			} else {
				niz.push(s2);
				niz.push(s1);
				check = true;
			}
		} catch (EmptyStackException ese) {
			if(prvi) {
				niz.push(s);
				check = true;
			}
		}
		return check;
	}
	
	/** Funkcija koja provjerava je li
	 * zadovoljena produkcija gramatike :
	 * C->AA
	 * @return true ako je produkcija zadovoljena,
	 * false inace
	 */
	private static boolean C() {
		System.out.print("C");
		boolean check = false;
		check = A();
		if(check) check = A();
		return check;
	}

}
