package prvi1011;

public class MessageProcessorInitialize implements MessageProcessor {

	private Message m;
	
	public MessageProcessorInitialize(Message m) {
		super();
		this.m = m;
	}

	@Override
	public void execute() {
		// TODO Auto-generated method stub
		System.out.println("Initializing message");
		m.action();
	}

}
