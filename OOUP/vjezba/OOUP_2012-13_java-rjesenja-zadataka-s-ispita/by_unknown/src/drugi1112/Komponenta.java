package drugi1112;

public interface Komponenta {
	public String ime();
	public int cijena();
	public void addChild(Komponenta k);
	public void removeChild(Komponenta k);
	public Komponenta getChild(int n);
	public Komponenta getCopy();
}
