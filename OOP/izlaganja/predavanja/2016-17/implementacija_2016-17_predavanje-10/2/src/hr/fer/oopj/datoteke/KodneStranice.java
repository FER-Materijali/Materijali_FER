package hr.fer.oopj.datoteke;

import java.nio.charset.StandardCharsets;

public class KodneStranice {

	public static void main(String[] args) {
		String text = "Šišćevapčići šeću šumom.";
		
		byte[] okteti = text.getBytes(StandardCharsets.UTF_8);
		for(byte b : okteti) {
			System.out.println((int)b&0xff);
		}
	}
}
