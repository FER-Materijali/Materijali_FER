package model;

import java.util.Iterator;
import java.util.Vector;

public class TelefonskiImenik 
{
	private Vector<Osoba> Osobe = new Vector<Osoba>();

	public void addOsoba(Osoba osoba) {
		this.Osobe.add(osoba);
	}

	public void removeOsoba(Osoba osoba) {
		this.Osobe.remove(osoba);
	}

	public Iterator<Osoba> Osobe() {
		return this.Osobe.iterator();
	}
}
