import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Date;


public class tnserverMT {

	public static void main(String[] args) {
		
		if( args.length != 1 ) {
			System.out.println("usage: java tnserverMT <port>");
			System.exit(1);
		}
		
		ServerSocket ssocket = null;
			
		try {
			ssocket = new ServerSocket(Integer.parseInt(args[0]), 2);
		} catch (IOException e) {
			System.out.println("Error creating a server socket at port " + args[0]);
			System.exit(1);
		}
		
		System.out.println("Ready to accept connections at port " + args[0]);
		
		while(true) {
			
			Socket cSocket = null;
			
			try {
				cSocket = ssocket.accept();
				tnserverThread serverThread = new tnserverThread(cSocket);
				new Thread(serverThread).start();
			} catch (IOException e) {
				System.out.println("Error in socket connection");
				System.exit(1);
			}
		}
	}
}
