package utr1;

public class Prijelazi {
	
	private String trenutno;
	private String simbol;
	private String[] skupStanja;

	public Prijelazi(String line) {
		this.trenutno = line.split(",")[0].trim(); 
		this.simbol = line.split(",")[1].split("->")[0].trim(); 
		this.skupStanja = line.trim().split("->")[1].split(",");
	}
	
	public boolean postojiPrijelaz(String trenunto, String simbol){
		if (this.trenutno.equals(trenunto) && this.simbol.equals(simbol)){
			return true;
		}
		else 
			return false;
	}

	public String[] getSkupStanja(String trenunto, String simbol){
		if (this.trenutno.equals(trenunto) && this.simbol.equals(simbol)){
			return this.skupStanja;
		}
		else
			return null;
	}
	

	public String toString(){
		return trenutno + "," + simbol + "->" + skupStanja[0];
	}
}
