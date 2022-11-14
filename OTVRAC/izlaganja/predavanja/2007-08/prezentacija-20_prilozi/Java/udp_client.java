import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.SocketException;
import java.net.UnknownHostException;


public class udp_client {

	public static void main(String[] args) {
		
		if( args.length != 2 ) {
			System.out.println("usage: java udp_client <host> <port>");
			System.exit(1);
		}
		
		DatagramSocket csocket = null;
		
		try {
			csocket = new DatagramSocket();
		} catch (SocketException e) {
			System.out.println("Error creating a client datagram socket");
			System.exit(1);
		}
	
		byte[] buff = "time".getBytes();
		
		InetAddress addr = null;
		try {
			addr = InetAddress.getByName(args[0]);
		} catch (UnknownHostException e) {
			System.out.println("Error: unknown host " + args[0]);
			System.exit(1);
		}
		
		int port = Integer.parseInt(args[1]);
		
		DatagramPacket msg = new DatagramPacket(buff, buff.length, addr, port);
		try {
			csocket.send(msg);
		} catch (IOException e) {
			System.out.println("Error sending a datagram packet");
			System.exit(1);
		}
		
		byte[] rbuff = new byte[100];
		DatagramPacket rPacket = new DatagramPacket(rbuff, rbuff.length);
		try {
			csocket.receive(rPacket);
			System.out.println(new String(rbuff));
		} catch (IOException e) {
			System.out.println("Error receiving a datagram packet");
			System.exit(1);
		}
		
		csocket.close();
		
	}
}
