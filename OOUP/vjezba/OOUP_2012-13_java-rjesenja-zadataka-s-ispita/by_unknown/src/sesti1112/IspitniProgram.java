package sesti1112;

public class IspitniProgram {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		ParniBrojevi pb = new ParniBrojevi(2, 100); // <== ne sprema kolekciju
		Iterator<Integer> it = pb.iterator();
		while(it.hasNext()){
			System.out.println(it.next());
		}
	}

}
