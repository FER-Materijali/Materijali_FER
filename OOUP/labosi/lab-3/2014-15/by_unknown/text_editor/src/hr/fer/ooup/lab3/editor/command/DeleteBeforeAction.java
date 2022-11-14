package hr.fer.ooup.lab3.editor.command;

import hr.fer.ooup.lab3.editor.Location;
import hr.fer.ooup.lab3.editor.TextEditorModel;

import java.util.ArrayList;
import java.util.List;

public class DeleteBeforeAction implements EditAction {

	private TextEditorModel model;
	private List<String> previousStateOfLines;
	private Location previousCursorLocation;
	
	public DeleteBeforeAction(TextEditorModel model) {
		this.model = model;
	}
	
	@Override
	public void executeDo() {
		List<String> lines = model.getLines();
		Location cursorLocation = model.getCursorLocation();
		
		previousStateOfLines = new ArrayList<String>(lines);
		previousCursorLocation = new Location(cursorLocation);
		
		if(cursorLocation.getY() == 0) {
			if(cursorLocation.getX() != 0) {
				int previousLineLength = lines.get(cursorLocation.getX() - 1).length();
				lines.set(cursorLocation.getX() - 1, lines.get(cursorLocation.getX() - 1) + lines.get(cursorLocation.getX()));
				lines.remove(cursorLocation.getX());
				cursorLocation.update(-1, previousLineLength);
			} else {
				return;
			}
		} else {
			StringBuilder sb = new StringBuilder(lines.get(cursorLocation.getX()));
			sb.deleteCharAt(cursorLocation.getY() - 1);
			lines.set(cursorLocation.getX(), sb.toString());
			cursorLocation.update(0, -1);
		}
		
		model.notifyCursorObservers();
		model.notifyTextObservers();
	}

	@Override
	public void executeUndo() {
		model.setLines(previousStateOfLines);
		model.setCursorLocation(previousCursorLocation);
		model.notifyCursorObservers();
		model.notifyTextObservers();
	}

}
