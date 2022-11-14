package hr.fer.ooup.lab3.editor.observer.clipboard;

import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

public class ClipboardStack {

	private Stack<String> texts;
	private List<ClipboardObserver> clipboardObservers;
	
	public ClipboardStack() {
		texts = new Stack<String>();
		clipboardObservers = new ArrayList<ClipboardObserver>();
	}
	
	public void addClipboardObserver(ClipboardObserver observer) {
		if(!clipboardObservers.contains(observer)) {
			clipboardObservers.add(observer);
		}
	}
	
	public void removeClipobardObserver(ClipboardObserver observer) {
		clipboardObservers.remove(observer);
	}
	
	private void notifyObservers() {
		for (ClipboardObserver clipboardObserver : clipboardObservers) {
			clipboardObserver.updateClipboard();
		}
	}
	
	public boolean hasText() {
		return !texts.isEmpty();
	}
	
	public String getText() {
		return texts.peek();
	}
	
	public String removeText() {
		String text = texts.pop();
		notifyObservers();
		return text;
	}
	
	public void putText(String text) {
		texts.push(text);
		notifyObservers();
	}
}
