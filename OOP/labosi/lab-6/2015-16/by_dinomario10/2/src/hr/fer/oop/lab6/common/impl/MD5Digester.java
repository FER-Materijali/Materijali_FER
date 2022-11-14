package hr.fer.oop.lab6.common.impl;

import java.io.ByteArrayInputStream;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

import hr.fer.oop.lab6.common.console.Helper;
import hr.fer.oop.lab6.common.iface.InputMessage;
import hr.fer.oop.lab6.common.iface.OutputMessage;
import hr.fer.oop.lab6.common.iface.Processor;

/**
 * Implements the interface {@link Processor}, so it is a {@link Processor}
 * which receives {@link InputMessage}s and generates new {@link OutputMessage}s
 * based on the MD5 cryptographic hash function of the data in {@link
 * InputMessage}.
 * 
 * @author dinomario10
 */
public class MD5Digester implements Processor {

	@Override
	public OutputMessage process(InputMessage in) {
		MessageDigest md;
		try {
			md = MessageDigest.getInstance("MD5");
		} catch (NoSuchAlgorithmException e) {
			e.printStackTrace();
			return null;
		}
		
		byte[] bytes = Helper.inputStreamToBytes(in.getStream());
		byte[] digested = md.digest(bytes);
		
		return new OutputMessageImpl(in, new ByteArrayInputStream(digested));
	}

}
