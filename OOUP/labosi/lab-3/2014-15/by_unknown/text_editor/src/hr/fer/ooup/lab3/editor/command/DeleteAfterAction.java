package hr.fer.ooup.lab3.editor.command;

import hr.fer.ooup.lab3.editor.Location;
import hr.fer.ooup.lab3.editor.TextEditorModel;

import java.util.ArrayList;
import java.util.List;

public class DeleteAfterAction implements EditAction {

	private TextEditorModel model;
	private List<String> previousStateOfLines;
	
	public DeleteAfterAction(TextEditorModel model) {
		this.model = model;
	}
	
	@Override
	public void executeDo() {
		List<String> lines = model.getLines();
		Location cursorLocation = model.getCursorLocation();
		previousStateOfLines = new ArrayList<String>(lines);
		
		if(cursorLocation.getY() == lines.get(cursorLocation.getX()).length()) {
			if(lines.size() > 1) {
				lines.set(cursorLocation.getX(), lines.get(cursorLocation.getX()) + lines.get(cursorLocation.getX() + 1));
				lines.remove(cursorLocation.getX() + 1);
			} else {
				return;
			}
		} else {
			StringBuilder sb = new StringBuilder(lines.get(cursorLocation.getX()));
			sb.deleteCharAt(cursorLocation.getY());
			lines.set(cursorLocation.getX(), sb.toString());
		}
		
		model.notifyTextObservers();
	}

	@Override
	public void executeUndo() {
		model.setLines(previousStateOfLines);
		model.notifyTextObservers();
	}

}
