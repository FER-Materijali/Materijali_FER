package peti1112;

public class PasteCommand implements Command {
	private Receiver r;

	public PasteCommand(Receiver r) {
		super();
		this.r = r;
	}

	@Override
	public void execute() {
		// TODO Auto-generated method stub
		System.out.println("Starting Paste Command Execution!");
		r.action();
	}
}
