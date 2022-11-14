package peti1112;

public class CopyCommand implements Command {
	
	private Receiver r;
	
	public CopyCommand(Receiver r) {
		super();
		this.r = r;
	}
	
	@Override
	public void execute() {
		// TODO Auto-generated method stub
		System.out.println("Starting Copy Command Execution!");
		r.action();
	}
}
