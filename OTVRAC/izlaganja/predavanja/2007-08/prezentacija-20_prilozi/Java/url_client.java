import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.MalformedURLException;
import java.net.URL;
import java.net.URLConnection;


public class url_client {

	public static void main(String[] args) {
		
		if( args.length != 1 ) {
			System.out.println("usage: java url_client <URL>");
			System.exit(1);
		}
		
		URL targetURL = null;
		URLConnection connection = null;
		BufferedReader in = null;
		String lineIn = null;
		
		try {
			 targetURL = new URL(args[0]);
		} catch (MalformedURLException e) {
			System.out.println("Malformed URL: " + args[0]);
			System.exit(1);
		}
		
		try {
			connection = targetURL.openConnection();
			System.out.println("Accessing URL: " + args[0] + " using " + targetURL.getProtocol());
			connection.setReadTimeout(1000);
		} catch (IOException e) {
			System.out.println("Error accessing URL: " + args[0]);
			System.exit(1);
		}
		
		System.out.println("URL Info: content-type=" + connection.getContentType() + ", content-encoding=" +
				connection.getContentEncoding() + ", content-length=" + connection.getContentLength());
		
		try {
			in = new BufferedReader(new InputStreamReader(connection.getInputStream()));
			
			while( (lineIn = in.readLine()) != null )
				System.out.println(lineIn);
		} catch (IOException e) {
			System.out.println("Error accessing URL content: " + args[0]);
			System.exit(1);
		}
		
	}
}
