package hr.fer.ooup.lab3.editor.factory.plugin;

import hr.fer.ooup.lab3.editor.TextEditorModel;
import hr.fer.ooup.lab3.editor.observer.clipboard.ClipboardStack;
import hr.fer.ooup.lab3.editor.singleton.UndoManger;

public interface Plugin {

	public String getName();
	public String getDescription();
	public void execute(TextEditorModel model, UndoManger undoManager, ClipboardStack clipboardStack);
}
