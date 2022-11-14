package hr.fer.oop.lab3.zadatak;

import java.util.Enumeration;

public class Demonstration {

	public static void main(String[] args) {
		SimpleDictionary<String, String> dic = new SimpleDictionary<>();
		
		dic.put("OOP", "Objektno orijentirano programiranje");
		dic.put("ASP", "Algoritmi i strukture podataka");
		dic.put("PiPI", "Programiranje i programsko inžinjerstvo");
		dic.put("UTR", "Uvod u teoriju računarstva");
		dic.put("ARH", "Arhitektura računala");
		dic.put("PiPI", "Programiranje i programsko inženjerstvo");
		
		System.out.println("Size: " + dic.size());
		System.out.println("Is the dictionary empty? " + dic.isEmpty());
		System.out.println("OOP: " + dic.get("OOP"));
		System.out.println("PiPI: " + dic.get("PiPI"));
		
		dic.remove("ARH");
		System.out.print("Is there \"ARH\" in dictionary? ");
		System.out.println(dic.get("ARH") != null ? "Yes" : "No");
		
		System.out.println("Print: ");
		for (Enumeration<String> e = dic.elements(); e.hasMoreElements();)
		       System.out.println(e.nextElement());
	}

}
