package templates.task4;

import java.util.List;

import javax.swing.SwingUtilities;
import javax.swing.SwingWorker;

import templates.task3.FileSearchMonitor;
import templates.task3.FileSearcher;

public class FileSearcherWorker extends SwingWorker<List<String>, String> {

	private FileSearchMonitor m;
	private String from;
	private String to;
	
	private FileSearchMonitor proxyMonitor = new FileSearchMonitor() {
		@Override
		public void searchFinished() {
			SwingUtilities.invokeLater(()->{ m.searchFinished(); });
		}
		
		@Override
		public void fileFound(String filename) {
			SwingUtilities.invokeLater(()->{ m.fileFound(filename); });
		}
		
		@Override
		public void directoryChangedTo(String directory) {
			SwingUtilities.invokeLater(()->{ m.directoryChangedTo(directory); });
		}
	};
	
	public FileSearcherWorker(FileSearchMonitor m, String from, String to) {
		this.m = m;
		this.from = from;
		this.to = to;
	}

	@Override
	protected List<String> doInBackground() throws Exception {
		FileSearcher searcher = new FileSearcher(proxyMonitor);
		return searcher.findPDFsInRange(from, to);
	}

}
