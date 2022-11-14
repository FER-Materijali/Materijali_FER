package drugi0910;

public class GuestA extends Guest {

	private boolean prijava=false;
	private boolean usluga=false;
	private boolean racun=false;
	private String name;
	
	public GuestA(Agencija a, String name) {
		super(a);
		this.name=name;
	}

	@Override
	public String getName() {
		// TODO Auto-generated method stub
		return name;
	}

	@Override
	public void accept(Visitor v) {
		// TODO Auto-generated method stub
		v.operation(this);
	}

	@Override
	public void setPrijava() {
		// TODO Auto-generated method stub
		prijava=true;
	}

	@Override
	public void setUsluga() {
		// TODO Auto-generated method stub
		usluga=true;
	}

	@Override
	public void setRacun() {
		// TODO Auto-generated method stub
		racun=true;
	}
	
	public boolean isPrijava() {
		return prijava;
	}
	
	public boolean isRacun() {
		return racun;
	}
	
	public boolean isUsluga() {
		return usluga;
	}
	
}
