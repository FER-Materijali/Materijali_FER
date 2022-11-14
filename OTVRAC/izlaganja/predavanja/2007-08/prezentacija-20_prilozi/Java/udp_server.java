import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.SocketException;
import java.util.Date;


public class udp_server {

	public static void main(String[] args) {
		
		if( args.length != 1 ) {
			System.out.println("usage: java udp_server <port>");
			System.out.println("port between 1024 and 65535");
			System.exit(1);
		}
		
		DatagramSocket ssocket = null;
		
		try {
			ssocket = new DatagramSocket( Integer.parseInt(args[0]));
			System.out.println("Ready to accept connections at port " + args[0]);
		} catch (NumberFormatException e) {
			System.out.println("Argument is not a valid port number: " + args[0]);
			System.exit(1);
		} catch (SocketException e) {
			System.out.println("Error creating a server datagram socket at port " + args[0]);
			System.exit(1);
		}
		
		while(true) {
			
			byte[] buffer = new byte[100];
			DatagramPacket dPacket = new DatagramPacket(buffer, buffer.length);
			String message = null;
			try {
				ssocket.receive(dPacket);
				message = new String(buffer);
				System.out.println("Query received from " + dPacket.getAddress() + " at port " + dPacket.getPort() + ": " + message);
			} catch (IOException e) {
				System.out.println("Error receiving a datagram packet." );
				continue;
			}
			
			String response = null;
			if( message.trim().equalsIgnoreCase("time") )
				response = new Date().toString();
			else
				response = "not understood";
			
			byte[] rBuffer = response.getBytes();
			
			DatagramPacket rPacket = new DatagramPacket(rBuffer, rBuffer.length, dPacket.getAddress(), dPacket.getPort());
			try {
				ssocket.send(rPacket);
			} catch (IOException e) {
				System.out.println("Error sending a datagram packet." );
				System.exit(1);
			}
			
		}
	}
}
