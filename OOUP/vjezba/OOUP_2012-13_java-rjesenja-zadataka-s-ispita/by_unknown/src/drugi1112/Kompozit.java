package drugi1112;

import java.util.ArrayList;
import java.util.List;

public class Kompozit implements Komponenta {

	private List<Komponenta> l;
	private String ime;
	
	public Kompozit(String ime) {
		super();
		this.ime = ime;
		l=new ArrayList();
	}

	@Override
	public String ime() {
		// TODO Auto-generated method stub
		String s=ime + " : ";
		for (Komponenta k:l){
			s+=k.ime() + " ";
		}
		return s;
	}

	@Override
	public int cijena() {
		// TODO Auto-generated method stub
		int sum=0;
		for (Komponenta k:l){
			sum+=k.cijena();
		}
		return sum;
	}

	@Override
	public void addChild(Komponenta k) {
		// TODO Auto-generated method stub
		l.add(k);
	}

	@Override
	public void removeChild(Komponenta k) {
		// TODO Auto-generated method stub
		l.remove(k);
	}

	@Override
	public Komponenta getChild(int i) {
		// TODO Auto-generated method stub
		return l.get(i);
	}

	@Override
	public Komponenta getCopy() {
		// TODO Auto-generated method stub
		Komponenta klon=new Kompozit(this.ime);
		for (Komponenta k:l){
			klon.addChild(k.getCopy());
		}
		return klon;
	}

}
