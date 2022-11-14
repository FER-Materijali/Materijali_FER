package peti1112;

public class CutCommand implements Command {

	private Receiver r;

	public CutCommand(Receiver r) {
		super();
		this.r = r;
	}

	@Override
	public void execute() {
		// TODO Auto-generated method stub
		System.out.println("Starting Cut Command Execution!");
		r.action();
	}

}
