package hr.fer.ooup.lab3.editor.command;

import hr.fer.ooup.lab3.editor.Location;
import hr.fer.ooup.lab3.editor.LocationRange;
import hr.fer.ooup.lab3.editor.TextEditorModel;

import java.util.ArrayList;
import java.util.List;

public class ResetDocumentAction implements EditAction {

	private TextEditorModel model;
	
	private List<String> previousStateOfLines;
	private Location previousCursorLocation;
	private LocationRange previousSelectionRange;
	
	public ResetDocumentAction(TextEditorModel model) {
		this.model = model;
	}
	
	@Override
	public void executeDo() {
		previousStateOfLines = new ArrayList<String>(model.getLines());
		previousCursorLocation = new Location(model.getCursorLocation());
		if(model.getSelectionRange() == null) {
			previousSelectionRange = null;
		} else {
			previousSelectionRange = new LocationRange(model.getSelectionRange());
		}
		
		model.getLines().clear();
		model.getLines().add("");
		model.setCursorLocation(new Location(0, 0));
		model.setSelectionRange(null);
		
		model.notifyCursorObservers();
		model.notifyTextObservers();
	}

	@Override
	public void executeUndo() {
		model.setLines(previousStateOfLines);
		model.setCursorLocation(previousCursorLocation);
		model.setSelectionRange(previousSelectionRange);
		
		model.notifyCursorObservers();
		model.notifyTextObservers();
	}
}
