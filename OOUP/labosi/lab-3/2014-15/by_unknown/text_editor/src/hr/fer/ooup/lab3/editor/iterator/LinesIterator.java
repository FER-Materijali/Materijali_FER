package hr.fer.ooup.lab3.editor.iterator;

import java.util.List;
import java.util.NoSuchElementException;

public class LinesIterator implements Iterator<String> {

	private List<String> lines;
	private int index;
	private int lastIndex;
	
	public LinesIterator(List<String> lines) {
		this.lines = lines;
		this.index = 0;
		this.lastIndex = lines.size();
	}
	
	public LinesIterator(List<String> lines, int index1, int index2) throws IndexOutOfBoundsException {
		if(index2 > lines.size()) throw new IndexOutOfBoundsException("index2: " + index2 + " is greater than lines length: " + lines.size());
		this.lines = lines;
		this.index = index1;
		this.lastIndex = index2;
	}

	@Override
	public boolean hasNext() {
		if(index < lastIndex && lines.get(index) != null) {
			return true;
		} else {
			return false;
		}
	}

	@Override
	public String next() throws NoSuchElementException {
		if(hasNext()) {
			return lines.get(index++);
		} else {
			throw new NoSuchElementException("Collection has no more elements to return.");
		}
	}
}
