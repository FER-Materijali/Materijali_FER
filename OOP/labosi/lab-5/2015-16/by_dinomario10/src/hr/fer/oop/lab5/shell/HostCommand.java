package hr.fer.oop.lab5.shell;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.net.InetAddress;
import java.net.NetworkInterface;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.SocketException;
import java.util.Enumeration;

/**
 * A command that is used for connecting to another computer running MyShell. In
 * order for another computer to connect to this host, the
 * {@linkplain ConnectCommand} must be executed on another computer with host's
 * IP address and port number.
 *
 * @author dinomario10
 */
public class HostCommand extends AbstractCommand {
	
	/** Defines the proper syntax for using this command */
	private static final String SYNTAX = "host <port>";

	/**
	 * Constructs a new command object of type {@code HostCommand}.
	 */
	public HostCommand() {
		super("HOST", "Hosts this session with the given port number.");
	}
	
	@Override
	public CommandStatus execute(Environment env, String s) {
		if (s == null) {
			printSyntaxError(env, SYNTAX);
			return CommandStatus.CONTINUE;
		}
		
		/* Parse the port number */
		int port;
		try {
			port = Integer.parseInt(s);
		} catch (NumberFormatException e) {
			printSyntaxError(env, SYNTAX);
			return CommandStatus.CONTINUE;
		}
		
		/* Print out a message that the connection is ready */
		env.writeln("Hosting server... connect to " + getIPAddress());
		
		/* Create a host access point and redirect the input and output stream */
		try (
				ServerSocket serverSocket = new ServerSocket(port);
				Socket connectionSocket = serverSocket.accept();
				BufferedReader inFromClient = new BufferedReader(new InputStreamReader(connectionSocket.getInputStream()));
				BufferedWriter outToClient = new BufferedWriter(new OutputStreamWriter(connectionSocket.getOutputStream()));
		){
			String clientAddress = connectionSocket.getRemoteSocketAddress().toString();
			env.writeln(clientAddress + " connected.");

			/* Redirect the streams to client */
			MyShell.connectStreams(inFromClient, outToClient);

			/* Go to the main program and wait for the client to disconnect */
			try {
				MyShell.main(null);
			} catch (Exception e) {}

			/* Redirect the streams back */
			MyShell.disconnectStreams();
			env.writeln(clientAddress + " disconnected.");
		} catch (Exception e) {
			env.writeln(e.getMessage());
		}
		
		return CommandStatus.CONTINUE;
	}

	/**
	 * Returns this computer's local IP address to which another user on the
	 * same LAN network may connect using the {@linkplain ConnectCommand}.
	 * Returns {@code null} if the IP address is inaccessible.
	 * 
	 * @return this computer's local IP address
	 */
	private String getIPAddress() {
		try {
			Enumeration<NetworkInterface> en = NetworkInterface.getNetworkInterfaces();
			while (en.hasMoreElements()) {
				NetworkInterface n = (NetworkInterface) en.nextElement();
				
				Enumeration<InetAddress> ee = n.getInetAddresses();
			    while (ee.hasMoreElements()) {
			        InetAddress addr = (InetAddress) ee.nextElement();
			        if (!addr.isLoopbackAddress() && !addr.isLinkLocalAddress()) {
			        	return addr.getHostAddress();
			        }
			    }
			}
		} catch (SocketException e) {}
		return null;
	}

}
