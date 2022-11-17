public class Prijelaz {
	public String trenutnoStanje;
	public String trenutniZnak1;
	public String trenutniZnak2;
	public String novoStanje;
	public String noviZnak1;
	public String noviZnak2;
	public String pomak1;
	public String pomak2;

	Prijelaz() {
		
	}
	
	Prijelaz(String _trenutnoStanje, String _trenutniZnak1, String _trenutniZnak2, String _novoStanje, String _noviZnak1, String _noviZnak2, String _pomak1, String _pomak2) {
		trenutnoStanje = _trenutnoStanje;
		trenutniZnak1 = _trenutniZnak1;
		trenutniZnak2 = _trenutniZnak2;
		novoStanje = _novoStanje;
		noviZnak1 = _noviZnak1;
		noviZnak2 = _noviZnak2;
		pomak1 = _pomak1;
		pomak2 = _pomak2;
	}
}