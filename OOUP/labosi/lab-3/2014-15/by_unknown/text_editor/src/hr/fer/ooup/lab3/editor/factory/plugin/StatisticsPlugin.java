package hr.fer.ooup.lab3.editor.factory.plugin;

import java.util.List;

import javax.swing.JOptionPane;

import hr.fer.ooup.lab3.editor.TextEditorModel;
import hr.fer.ooup.lab3.editor.observer.clipboard.ClipboardStack;
import hr.fer.ooup.lab3.editor.singleton.UndoManger;

public class StatisticsPlugin implements Plugin {

	@Override
	public String getName() {
		return "Statistics";
	}

	@Override
	public String getDescription() {
		return "Counts rows, words and letters in document";
	}

	@Override
	public void execute(TextEditorModel model, UndoManger undoManager,
			ClipboardStack clipboardStack) {
		List<String> lines = model.getLines();
		int numOfLines = 0;
		int numOfWords = 0;
		int numOfLetters = 0;
		
		String[] tmp = null;
		for (String line : lines) {
			tmp = line.split(" ");
			for (int i = 0; i < tmp.length; i++) {
				if(!tmp[i].isEmpty()) {
					numOfLetters += tmp[i].length();
					numOfWords++;
				}
			}
			numOfLines++;
		}
		
		StringBuilder sb = new StringBuilder();
		sb.append("Number of lines: " + numOfLines).append(System.lineSeparator());
		sb.append("Number of words: " + numOfWords).append(System.lineSeparator());
		sb.append("Number of letters: " + numOfLetters);
		
		JOptionPane.showMessageDialog(null, sb.toString(), "INFO", JOptionPane.INFORMATION_MESSAGE);
	}

}
