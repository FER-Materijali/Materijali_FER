package prvi1011;

public class MessageProcessorPrint implements MessageProcessor {
	
	private Message m;

	public MessageProcessorPrint(Message m) {
		super();
		this.m = m;
	}

	@Override
	public void execute() {
		// TODO Auto-generated method stub
		System.out.println("Printing message");
		m.action();
	}

}
