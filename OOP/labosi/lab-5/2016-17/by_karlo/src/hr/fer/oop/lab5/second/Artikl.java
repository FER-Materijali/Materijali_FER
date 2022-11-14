package hr.fer.oop.lab5.second;

/**
 * The Class Artikl.
 */
public class Artikl implements Comparable<Artikl> {
	
	/** The naziv. */
	private final String naziv;
	
	/** The cijena. */
	private final float cijena;
	
	/**
	 * Instantiates a new artikl.
	 *
	 * @param naziv the naziv
	 * @param cijena the cijena
	 */
	public Artikl(String naziv, float cijena) {
		this.naziv = naziv;
		this.cijena = cijena;
	}
	
	/**
	 * Gets the naziv.
	 *
	 * @return the naziv
	 */
	public String getNaziv() {
		return naziv;
	}
	
	/**
	 * Gets the cijena.
	 *
	 * @return the cijena
	 */
	public float getCijena() {
		return cijena;
	}

	/* (non-Javadoc)
	 * @see java.lang.Object#toString()
	 */
	@Override
	public String toString() {
		return String.format("%-100s%s%n", getNaziv(), getCijena());
	}

	/* (non-Javadoc)
	 * @see java.lang.Object#hashCode()
	 */
	@Override
	public int hashCode() {
		final int prime = 31;
		int result = 1;
		result = prime * result + Float.floatToIntBits(cijena);
		result = prime * result + ((naziv == null) ? 0 : naziv.hashCode());
		return result;
	}

	/* (non-Javadoc)
	 * @see java.lang.Object#equals(java.lang.Object)
	 */
	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		Artikl other = (Artikl) obj;
		if (Float.floatToIntBits(cijena) != Float.floatToIntBits(other.cijena))
			return false;
		if (naziv == null) {
			if (other.naziv != null)
				return false;
		} else if (!naziv.equals(other.naziv))
			return false;
		return true;
	}

	/* (non-Javadoc)
	 * @see java.lang.Comparable#compareTo(java.lang.Object)
	 */
	@Override
	public int compareTo(Artikl other) {
		return getNaziv().compareToIgnoreCase(other.getNaziv());
	}

}