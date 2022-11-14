package drugi1112;

public class IspitniProgram {

	public static void main(String[] args) {
		Komponenta k1=new Atom("Matična", 150);
		Komponenta k2=new Atom("Procesor", 300);
		Komponenta k3=new Atom("RAM", 500);
		
		Komponenta komp=new Kompozit("Računalo");
		komp.addChild(k1);
		komp.addChild(k2);
		komp.addChild(k3);
		
		Komponenta komp1=new Kompozit("Računalo + Monitor");
		Komponenta monitor=new Atom("Monitor", 2000);
		komp1.addChild(komp);
		komp1.addChild(monitor);
		
		System.out.println(komp1.ime());
		System.out.println(komp1.cijena());
		
		Komponenta kopija=komp1.getCopy();
		System.out.println(kopija.ime());
		System.out.println(kopija.cijena());
	}
}
