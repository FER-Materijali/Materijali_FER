package prvi1011;

public class TheMessageApplication {

	public void mainloop(){
		
		Message m1=new MessageType1();
		Message m2=new MessageType2();
		
		MessageProcessor proc1=new MessageProcessorInitialize(m1);
		MessageProcessor proc2=new MessageProcessorInitialize(m2);
		MessageProcessor proc3=new MessageProcessorPrint(m1);
		MessageProcessor proc4=new MessageProcessorPrint(m2);
		MessageProcessor proc5=new MessageProcessorArchive(m1);
		MessageProcessor proc6=new MessageProcessorArchive(m2);
		MessageProcessor proc7=new MessageProcessorSound(m1);
		MessageProcessor proc8=new MessageProcessorSound(m2);
		
		proc1.execute();
		proc2.execute();
		proc3.execute();
		proc4.execute();
		proc5.execute();
		proc6.execute();
		proc7.execute();
		proc8.execute();
	}
	
}
