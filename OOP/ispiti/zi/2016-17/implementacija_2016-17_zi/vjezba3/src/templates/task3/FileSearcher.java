package templates.task3;

import java.io.IOException;
import java.nio.file.FileVisitResult;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.SimpleFileVisitor;
import java.nio.file.attribute.BasicFileAttributes;
import java.util.ArrayList;
import java.util.List;

public class FileSearcher {
	
	private FileSearchMonitor monitor;
	
	public FileSearcher(FileSearchMonitor monitor){
		this.monitor = monitor;
	}

	public List<String> findPDFsInRange(String from, String to){
		
		Pretrazivalo p = new Pretrazivalo(Paths.get(to));
		try {
			Files.walkFileTree(Paths.get(from), p);
		} catch (IOException e) {
			// Sjetite se sto smo komentirali na satu:
			// Bolje: throw new RuntimeException("Greska pri pretraživanju.", e);
			e.printStackTrace();
		}
		
		monitor.searchFinished();
		return p.lista;
	}

	private class Pretrazivalo extends SimpleFileVisitor<Path> {
		private Path lowerDirectory;
		private List<String> lista = new ArrayList<>();
		
		public Pretrazivalo(Path lowerDirectory) {
			this.lowerDirectory = lowerDirectory;
		}

		@Override
		public FileVisitResult visitFile(Path file, BasicFileAttributes attrs) throws IOException {
			String fileName = file.getFileName().toString();
			if(fileName.toLowerCase().endsWith(".pdf")) {
				lista.add(file.toString());
				monitor.fileFound(file.toString());
			}
			return FileVisitResult.CONTINUE;
		}

		@Override
		public FileVisitResult preVisitDirectory(Path dir, BasicFileAttributes attrs) throws IOException {
			if(lowerDirectory.startsWith(dir)) {
				monitor.directoryChangedTo(dir.toString());
				return FileVisitResult.CONTINUE;
			}
			return FileVisitResult.SKIP_SUBTREE;
		}

	}
}