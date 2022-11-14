package pp;

public class Spremnik {

	private Integer value;
	
	public Spremnik() {
	}

	public synchronized void postavi(Integer value) {
		while(this.value!=null) {
			try {
				this.wait();
			} catch (InterruptedException ignorable) {
			}
		}
		this.value = value;
		this.notifyAll();
	}
	
	public synchronized Integer preuzmi() {
		while(this.value==null) {
			try {
				this.wait();
			} catch (InterruptedException ignorable) {
			}
		}
		Integer rezultat = value;
		value = null;
		this.notifyAll();
		return rezultat;
	}
}
