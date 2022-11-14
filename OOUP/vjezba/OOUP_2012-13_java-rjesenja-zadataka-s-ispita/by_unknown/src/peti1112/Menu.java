package peti1112;

import java.util.ArrayList;
import java.util.List;

public class Menu {

	private List<Command> l;
	
	public Menu() {
		// TODO Auto-generated constructor stub
		l=new ArrayList();
	}
	
	public void add(Command c){
		l.add(c);
	}
	
	public void remove(Command c){
		l.remove(c);
	}
	
	public Command getCommand(int n){
		return l.get(n);
	}
	
	public int size(){
		return l.size();
	}
	
}
