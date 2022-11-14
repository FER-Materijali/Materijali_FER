package prvi1011;

public class MessageProcessorSound implements MessageProcessor {

	private Message m;

	public MessageProcessorSound(Message m) {
		super();
		this.m = m;
	}

	@Override
	public void execute() {
		// TODO Auto-generated method stub
		System.out.println("Sounding alarm for message " + m.getClass());
		m.action();
	}
	
}
