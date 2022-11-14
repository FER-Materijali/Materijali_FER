package peti1112;

public class IspitniProgram {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Menu menu=new Menu();
		Receiver r=new Receiver();
		Command c1=new CopyCommand(r);
		Command c2=new CutCommand(r);
		Command c3=new PasteCommand(r);
		Command c4=new PasteCommand(r);
		menu.add(c1);
		menu.add(c2);
		menu.add(c3);
		menu.add(c4);
		for (int i=0; i<menu.size(); i++){
			menu.getCommand(i).execute();
		}
	}

}
