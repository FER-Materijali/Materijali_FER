package prvi1011;

public class MessageProcessorArchive implements MessageProcessor {

	private Message m;

	public MessageProcessorArchive(Message m) {
		super();
		this.m = m;
	}

	@Override
	public void execute() {
		// TODO Auto-generated method stub
		System.out.println("Archiving message");
		m.action();
	}
	
}
