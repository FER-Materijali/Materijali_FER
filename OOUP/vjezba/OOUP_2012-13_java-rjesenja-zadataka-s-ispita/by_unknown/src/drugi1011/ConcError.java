package drugi1011;

public class ConcError implements Error {

	private String name;
	
	public ConcError(String name) {
		super();
		this.name = name;
	}

	@Override
	public void print() {
		// TODO Auto-generated method stub
		System.out.println(name);
	}

}
