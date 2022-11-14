package hr.fer.ooup.lab3.editor.command;

import java.util.ArrayList;
import java.util.List;

import hr.fer.ooup.lab3.editor.Location;
import hr.fer.ooup.lab3.editor.LocationRange;
import hr.fer.ooup.lab3.editor.TextEditorModel;
import hr.fer.ooup.lab3.editor.command.EditAction;

public class InsertTextAction implements EditAction {

	private TextEditorModel model;
	
	private List<String> previousStateOfLines;
	private Location previousCursorLocation;
	private LocationRange previousSelectionRange;
	
	private String text;
	private char c;
	
	public InsertTextAction(TextEditorModel model, String text) {
		this.model = model;
		this.text = text;
	}
	
	public InsertTextAction(TextEditorModel model, char c) {
		this.model = model;
		this.c = c;
	}
	
	@Override
	public void executeDo() {
		List<String> lines = model.getLines();
		Location cursorLocation = model.getCursorLocation();
		
		previousStateOfLines = new ArrayList<String>(lines);
		previousCursorLocation = new Location(cursorLocation);
		previousSelectionRange = new LocationRange(model.getSelectionRange());
		
		if(model.hasSelection()) {
			model.deleteRange();
		}	
		
		if(text != null) {
			String[] tmp = text.split(System.lineSeparator());
			String firstPart = lines.get(cursorLocation.getX()).substring(0, cursorLocation.getY());
			String secondPart = lines.get(cursorLocation.getX()).substring(cursorLocation.getY());
			
			if(tmp.length == 1) {
				lines.set(cursorLocation.getX(), firstPart + tmp[0] + secondPart);
				cursorLocation.update(0, tmp[0].length());
			} else {
				lines.set(cursorLocation.getX(), firstPart + tmp[0]);
			
				List<String> tmpLines = new ArrayList<String>();
				
				for (int i = 0; i < lines.size(); i++) {
					if(i == cursorLocation.getX()) {
						tmpLines.add(lines.get(i));
						for (int j = 1; j < tmp.length - 1; j++) {
							tmpLines.add(tmp[j]);
						}
						tmpLines.add(tmp[tmp.length - 1] + secondPart);
					} else {
						tmpLines.add(lines.get(i));
					}
				}
				
				model.setCursorLocation(new Location(cursorLocation.getX() + tmp.length - 1, tmp[tmp.length - 1].length() + secondPart.length()));
				model.setLines(tmpLines);
			}
		} else {
			if(String.valueOf(c).equals(System.lineSeparator())) {
				List<String> tmp = new ArrayList<String>();
				int linesLength = lines.size();
			
				for (int i = 0; i < linesLength; i++) {
					if(cursorLocation.getX() == i) {
						tmp.add(lines.get(i).substring(0, cursorLocation.getY()));
						tmp.add(lines.get(i).substring(cursorLocation.getY()));
					} else {
						tmp.add(lines.get(i));
					}
				}
				cursorLocation.setLocation(cursorLocation.getX() + 1, 0);
				model.setLines(tmp);
			} else {
				StringBuilder sb = new StringBuilder(lines.get(cursorLocation.getX()));
				sb.insert(cursorLocation.getY(), c);
				lines.set(cursorLocation.getX(), sb.toString());
				cursorLocation.update(0, 1);
			}
		}
		
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
