package hr.fer.oop.lab2.prob7;

import java.util.Scanner;

/**
 * Additional task for 3 points.
 * 
 * @author dinomario10
 */
public class Palindrom {
	
	public static void main(String[] args) {
		System.out.print("Unesite string: ");
		
		Scanner sc = new Scanner(System.in);
		String s1 = sc.nextLine();
		sc.close();
		// replace all whitespaces
		s1 = s1.replaceAll("\\s+", "");
		s1 = s1.toLowerCase();
		
		String s2 = reverseString(s1);
		if (s1.equals(s2)) {
			System.out.println("String je palindrom.");
		} else {
			System.err.println("String nije palindrom.");
		}
	}
	
	/**
	 * Returns a reversed string.
	 * 
	 * @param s1 input string
	 * @return reversed string
	 */
	private static String reverseString(String s1) {
		String s2 = new String();
		for (int i = s1.length() - 1; i >= 0; i--) {
			s2 += s1.charAt(i);
		}
		return s2;
	}
}
