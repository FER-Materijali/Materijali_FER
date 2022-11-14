package drugi0910;

public abstract class Guest {
	
	protected Agencija a;
	
	public Guest(Agencija a) {
		// TODO Auto-generated constructor stub
		this.a=a;
	}
	
	public String getAgencijaName() {
		return a.getName();
	}
	
	public abstract void setPrijava();
	public abstract void setUsluga();
	public abstract void setRacun();
	public abstract boolean isPrijava();
	public abstract boolean isUsluga();
	public abstract boolean isRacun();
	public abstract String getName();
	public abstract void accept(Visitor v);
}
