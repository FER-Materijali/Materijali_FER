import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Date;


public class tnserver {

	public static void main(String[] args) {
		
		if( args.length != 1 ) {
			System.out.println("usage: java tnserver <port>");
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
			PrintWriter out = null;
			BufferedReader in = null;
			
			try {
				cSocket = ssocket.accept();
				out = new PrintWriter(cSocket.getOutputStream());
				in = new BufferedReader(new InputStreamReader(cSocket.getInputStream()));
			} catch (IOException e) {
				System.out.println("Error in accepting the socket connection");
				System.exit(1);
			}
			
			String clientInfo = cSocket.getInetAddress().getHostName();
			System.out.println("Accepted connection from " +  clientInfo + ".");
			
			while(true) {
			
				try {
					String cmd = in.readLine();
				
					if( cmd.equalsIgnoreCase("time") ) {

						out.println("" + new Date());
						out.flush();
					}
					else if( cmd.equalsIgnoreCase("close") ) {
						break;
					}

					else {
						out.println("not understood: " + cmd);
						out.flush();
					}
				} catch(IOException e) {
					System.out.println("Communication error");
					break;
				}
			}
			
			
			System.out.println("Closing connection with client " + clientInfo + ".");
			
			out.close();
			try {
				in.close();
			} catch (IOException e) {
			}
			try {
				cSocket.close();
			} catch (IOException e) {
			}
			
		}
	}
}
