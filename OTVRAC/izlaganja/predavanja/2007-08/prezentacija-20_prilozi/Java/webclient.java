import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;
import java.net.UnknownHostException;


public class webclient {

	public static void main(String[] args) {
		
		if( args.length != 3 ) {
			System.out.println("usage: java webclient <server> <port> <path>");
			System.exit(1);
		}
		
		Socket socket = null;
		PrintWriter out = null;
		BufferedReader in = null;
		
		try { 
			socket = new Socket(args[0], Integer.parseInt(args[1]) );
			out = new PrintWriter(socket.getOutputStream());
			in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
		} catch (NumberFormatException e) {
			System.out.println("Incorrect port number: " + args[1]);
			System.exit(1);
		} catch (UnknownHostException e) {
			System.out.println("Cannot resolve hostname: " + args[0]);
			System.exit(1);
		} catch (IOException e) {
			System.out.println("Cannot establish a connection with server: " + args[0]);
			System.exit(1);
		}
		
		String request = "GET " + args[2] + " HTTP/1.0\r\n\r\n";
		out.print(request);
		out.flush();
		
		String inLine = null;
		try {
			while( (inLine = in.readLine()) != null)
				System.out.println(inLine);
		} catch (IOException e) {
			System.out.println("Error in communication (connection terminated)");
			System.exit(1);
		}
		
		try {
			in.close();
		} catch (IOException e) {
		}
		out.close();
		try {
			socket.close();
		} catch (IOException e) {
		}
	}
}
