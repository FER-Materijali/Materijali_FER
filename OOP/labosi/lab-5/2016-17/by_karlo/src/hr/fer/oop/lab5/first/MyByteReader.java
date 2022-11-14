package hr.fer.oop.lab5.first;

import java.io.*;
import java.nio.file.*;
import java.nio.file.attribute.BasicFileAttributes;

/**
 * The Class MyByteReader.
 */
public class MyByteReader implements FileVisitor<Path> {
	
	/** The output. */
	private BufferedOutputStream output;
	
	/**
	 * Instantiates a new my byte reader.
	 *
	 * @param stream the stream
	 */
	public MyByteReader(OutputStream stream) {
		output = new BufferedOutputStream(stream);
	}

	/* (non-Javadoc)
	 * @see java.nio.file.FileVisitor#postVisitDirectory(java.lang.Object, java.io.IOException)
	 */
	@Override
	public FileVisitResult postVisitDirectory(Path dir, IOException exc) throws IOException {
		return FileVisitResult.CONTINUE;
	}

	/* (non-Javadoc)
	 * @see java.nio.file.FileVisitor#preVisitDirectory(java.lang.Object, java.nio.file.attribute.BasicFileAttributes)
	 */
	@Override
	public FileVisitResult preVisitDirectory(Path dir, BasicFileAttributes attrs) throws IOException {
		return FileVisitResult.CONTINUE;
	}

	/* (non-Javadoc)
	 * @see java.nio.file.FileVisitor#visitFile(java.lang.Object, java.nio.file.attribute.BasicFileAttributes)
	 */
	@Override
	public FileVisitResult visitFile(Path file, BasicFileAttributes attrs) throws IOException {
		if (file.toString().endsWith(".txt")) {
			BufferedInputStream input = new BufferedInputStream(new FileInputStream(file.toFile()));		
			byte[] buffer = new byte[1024];
		    int lenght;    
		    while ((lenght = input.read(buffer)) > 0) {
		    	output.write(buffer, 0, lenght);
		    }
		    output.write("\r\n\r\n".getBytes());
		    input.close();
        }
        return FileVisitResult.CONTINUE;
	}

	/* (non-Javadoc)
	 * @see java.nio.file.FileVisitor#visitFileFailed(java.lang.Object, java.io.IOException)
	 */
	@Override
	public FileVisitResult visitFileFailed(Path file, IOException exc) throws IOException {
		return FileVisitResult.CONTINUE;
	}

}
