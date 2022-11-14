package hr.fer.oop.lab6.common.console;

import java.io.IOException;
import java.io.InputStream;

/**
 * A Helper class.
 * 
 * @author dinomario10
 */
public class Helper {
	
	/** The hexArray. */
	private final static char[] hexArray = "0123456789ABCDEF".toCharArray();

	/**
	 * Converts the input stream to bytes.
	 *
	 * @param is the input stream
	 * @return an array of bytes
	 */
	public static synchronized byte[] inputStreamToBytes(InputStream is) {
		byte[] byteTest = new byte[200];
		byte[] byteOutput;
		try {
			int n = is.read(byteTest);
			is.reset();
			byteOutput = new byte[n];
			is.read(byteOutput);
		} catch (IOException e) {
			e.printStackTrace();
			return null;
		}
		return byteOutput;
	}
	
	/**
	 * Converts bytes to hex string.
	 *
	 * @param bytes an array of bytes
	 * @return the hex string
	 */
	public static synchronized String bytesToHexString(byte[] bytes) {
		char[] hexChars = new char[bytes.length * 2];
	    for ( int j = 0; j < bytes.length; j++ ) {
	        int v = bytes[j] & 0xFF;
	        hexChars[j * 2] = hexArray[v >>> 4];
	        hexChars[j * 2 + 1] = hexArray[v & 0x0F];
	    }
	    return new String(hexChars);
	}

}
