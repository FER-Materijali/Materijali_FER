package hr.fer.ooup.lab3.editor.factory.plugin;

import java.util.List;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

import hr.fer.ooup.lab3.editor.TextEditorModel;
import hr.fer.ooup.lab3.editor.observer.clipboard.ClipboardStack;
import hr.fer.ooup.lab3.editor.singleton.UndoManger;

public class CapitalLetterPlugin implements Plugin {

	@Override
	public String getName() {
		return "Capital letter";
	}

	@Override
	public String getDescription() {
		return "Converts every first letter of word to capital";
	}

	@Override
	public void execute(TextEditorModel model, UndoManger undoManager,
			ClipboardStack clipboardStack) {
		List<String> lines = model.getLines();
		int length = lines.size();
		
		Pattern pattern = Pattern.compile(" +([a-z])");
		Matcher matcher = null;
		StringBuffer sb = new StringBuffer();
		
		for (int i = 0; i < length; i++) {
			if(!lines.get(i).isEmpty()) {
				sb.setLength(0);
				matcher = pattern.matcher(lines.get(i));
				while(matcher.find()) {
					matcher.appendReplacement(sb, matcher.group().substring(0, matcher.group().length() - 1) + matcher.group(1).toUpperCase());
				}
				matcher.appendTail(sb);
				sb.setCharAt(0, Character.toUpperCase(sb.charAt(0)));
				lines.set(i, sb.toString());
			}
		}
	}

}
