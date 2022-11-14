package hr.fer.ooup.lab3.editor;

import hr.fer.ooup.lab3.editor.command.DeleteAfterAction;
import hr.fer.ooup.lab3.editor.command.DeleteBeforeAction;
import hr.fer.ooup.lab3.editor.command.DeleteRangeAction;
import hr.fer.ooup.lab3.editor.command.EditAction;
import hr.fer.ooup.lab3.editor.command.InsertTextAction;
import hr.fer.ooup.lab3.editor.command.ResetDocumentAction;
import hr.fer.ooup.lab3.editor.iterator.Iterator;
import hr.fer.ooup.lab3.editor.iterator.LinesIterator;
import hr.fer.ooup.lab3.editor.observer.cursor.CursorObserver;
import hr.fer.ooup.lab3.editor.observer.text.TextObserver;
import hr.fer.ooup.lab3.editor.singleton.UndoManger;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class TextEditorModel {
	
	private List<String> lines;
	
	private LocationRange selectionRange;
	
	private List<TextObserver> textObservers;
	
	private Location cursorLocation;
	private List<CursorObserver> cursorObservers;
	
	private UndoManger undoManager;
	
	public TextEditorModel(String text) {
		text = text.replace("\t", "    ");
		lines = new ArrayList<String>(Arrays.asList(text.split("\n")));
		cursorObservers = new ArrayList<CursorObserver>();
		textObservers = new ArrayList<TextObserver>();
		undoManager = UndoManger.getInstance();
		cursorLocation = new Location(0, 0);
	}
	
	// CURSOR-OBSERVER
	
	public void addCursorObserver(CursorObserver observer) {
		if(!cursorObservers.contains(observer)) {
			cursorObservers.add(observer);
		}
	}
	
	public void removeCursorObserver(CursorObserver observer) {
		cursorObservers.remove(observer);
	}
	
	public void moveCursorLeft() {
		if(cursorLocation.getY() == 0) {
			if(cursorLocation.getX() != 0) {
				cursorLocation.setLocation(cursorLocation.getX() - 1, lines.get(cursorLocation.getX() - 1).length());
			} else {
				return;
			}
		} else {
			cursorLocation.update(0, -1);
		}
		notifyCursorObservers();
	}
	
	public void moveCursorRight() {
		int lineLength = lines.get(cursorLocation.getX()).length();
		if(cursorLocation.getY() == lineLength) {
			if(cursorLocation.getX() != lines.size() - 1) {
				cursorLocation.setLocation(cursorLocation.getX() + 1, 0);
			} else {
				return;
			}
		} else {
			cursorLocation.update(0, 1);
		}
		notifyCursorObservers();
	}
	
	public void moveCursorUp() {
		if(cursorLocation.getX() != 0) {
			String line = lines.get(cursorLocation.getX() - 1);
			if(cursorLocation.getY() > line.length()) {
				cursorLocation.setLocation(cursorLocation.getX() - 1, line.length());
			} else {
				cursorLocation.update(-1, 0);
			}
			notifyCursorObservers();
		}
	}
	
	public void moveCursorDown() {
		if(cursorLocation.getX() != lines.size() - 1) {
			String line = lines.get(cursorLocation.getX() + 1);
			if(cursorLocation.getY() > line.length()) {
				cursorLocation.setLocation(cursorLocation.getX() + 1, line.length());
			} else {
				cursorLocation.update(1, 0);
			}
			notifyCursorObservers();
		}
	}
	
	public void moveCursorToDocumentStart() {
		cursorLocation.setLocation(0, 0);
		notifyCursorObservers();
	}
	
	public void moveCursorToDocumentEnd() {
		int index = lines.size() - 1;
		cursorLocation.setLocation(index, lines.get(index).length());
		notifyCursorObservers();
	}
	
	public void notifyCursorObservers() {
		for (CursorObserver cursorObserver : cursorObservers) {
			cursorObserver.updateCursorLocation(cursorLocation);
		}
	}
	
	public Location getCursorLocation() {
		return cursorLocation;
	}
	
	public void setCursorLocation(Location location) {
		this.cursorLocation = location;
	}
	
	//TEXT OBSERVERS
	
	public void addTextObserver(TextObserver observer) {
		if(!textObservers.contains(observer)) {
			textObservers.add(observer);
		}
	}
	
	public void removeTextObserver(TextObserver observer) {
		textObservers.remove(observer);
	}
	
	public void notifyTextObservers() {
		for (TextObserver textObserver : textObservers) {
			textObserver.updateText();
		}
	}
	
	//TEXT MANIPULATION
	
	public void insert(char c) {
		EditAction action = new InsertTextAction(this, c);
		action.executeDo();
		undoManager.push(action);
	}
	
	public void insert(String text) {
		EditAction action = new InsertTextAction(this, text);
		action.executeDo();
		undoManager.push(action);
	}
	
	public void deleteBefore() {
		EditAction action = new DeleteBeforeAction(this);
		action.executeDo();
		undoManager.push(action);
	}
	
	public void deleteAfter() {
		EditAction action = new DeleteAfterAction(this);
		action.executeDo();
		undoManager.push(action);
	}
	
	//SELECTIONS
	
	public void deleteRange() {
		EditAction action = new DeleteRangeAction(this);
		action.executeDo();
		undoManager.push(action);
	}
	
	public boolean hasSelection() {
		return selectionRange != null;
	}
	
	public LocationRange getSelectionRange() {
		return selectionRange;
	}
	
	public void setSelectionRange(LocationRange range) {
		this.selectionRange = range;
	}
	
	public void addSelectionOnLeft() {
		if(cursorLocation.getY() == 0) {
			if(cursorLocation.getX() != 0) {
				int index = cursorLocation.getX() - 1;
				while(lines.get(index).isEmpty()) {
					index--;
					if(index < 0) {
						return;
					}
				}
				
				if(selectionRange == null) {
					selectionRange = new LocationRange();
					selectionRange.setStart(new Location(index, lines.get(index).length() - 1));
					selectionRange.setEnd(new Location(index, lines.get(index).length()));
				} else {
					if(cursorLocation.equals(selectionRange.getStart())) {
						selectionRange.setStart(new Location(index, lines.get(index).length() - 1));
					} else {
						selectionRange.setEnd(new Location(index, lines.get(index).length() - 1));
					}
				}
				
				cursorLocation.setLocation(index, lines.get(index).length() - 1);
			} else {
				return;
			}
		} else {
			if(selectionRange == null) {
				selectionRange = new LocationRange(new Location(cursorLocation.getX(), cursorLocation.getY() - 1), new Location(cursorLocation));
			} else {
				if(cursorLocation.equals(selectionRange.getStart())) {
					selectionRange.updateStart(0, -1);
				} else {
					selectionRange.updateEnd(0, -1);
				}
			}
			moveCursorLeft();
		}
		notifyTextObservers();
	}
	
	public void addSelectionRight() {
		if(cursorLocation.getY() == lines.get(cursorLocation.getX()).length()) {
			if(cursorLocation.getX() < lines.size() - 1) {
				int index = cursorLocation.getX() + 1;
				int numOfLines = lines.size();
				while(lines.get(index).isEmpty()) {
					index++;
					if(index > numOfLines) {
						return;
					}
				}
				
				if(selectionRange == null) {
					selectionRange = new LocationRange();
					selectionRange.setStart(new Location(index, 0));
					selectionRange.setEnd(new Location(index, 1));
				} else {
					if(cursorLocation.equals(selectionRange.getStart())) {
						selectionRange.setStart(new Location(index, 1));
					} else {
						selectionRange.setEnd(new Location(index, 1));
					}
				}
				
				cursorLocation.setLocation(index, 1);
			} else {
				return;
			}
		} else {
			if(selectionRange == null) {
				selectionRange = new LocationRange(new Location(cursorLocation), new Location(cursorLocation.getX(), cursorLocation.getY() + 1));
			} else {
				if(cursorLocation.equals(selectionRange.getEnd())) {
					selectionRange.updateEnd(0, 1);
				} else {
					selectionRange.updateStart(0, 1);
				}
			}
			moveCursorRight();
		}
		notifyTextObservers();
	}
	
	public void addSelectionUp() {
		if(cursorLocation.getX() == 0) {
			return;
		}
		
		if(hasSelection()) {
			if(selectionRange.getStart().equals(cursorLocation)) {
				int lineLength = lines.get(cursorLocation.getX() - 1).length();
				if(cursorLocation.getY() > lineLength) {
					selectionRange.setStart(new Location(cursorLocation.getX() - 1, lineLength));
					cursorLocation.setLocation(cursorLocation.getX() - 1, lineLength);
				} else {
					cursorLocation.update(-1, 0);
					selectionRange.setStart(new Location(cursorLocation));
				}
			} else if(selectionRange.getEnd().equals(cursorLocation)) {
				if(selectionRange.getStart().getX() == cursorLocation.getX()) {
					selectionRange.setEnd(selectionRange.getStart());
					int lineLength = lines.get(cursorLocation.getX() - 1).length();
					if(cursorLocation.getY() > lineLength) {
						selectionRange.setStart(new Location(cursorLocation.getX() - 1, lineLength));
						cursorLocation.setLocation(cursorLocation.getX() - 1, lineLength);
					} else {
						cursorLocation.update(-1, 0);
						selectionRange.setStart(new Location(cursorLocation));
					}
				} else {
					if(selectionRange.getStart().getY() > cursorLocation.getY() && selectionRange.getStart().getX() == cursorLocation.getX() - 1) {
						selectionRange.setEnd(selectionRange.getStart());
						cursorLocation.update(-1, 0);
						selectionRange.setStart(new Location(cursorLocation));
					} else {
						int lineLength = lines.get(cursorLocation.getX() - 1).length();
						if(cursorLocation.getY() > lineLength) {
							cursorLocation.setLocation(cursorLocation.getX() - 1, lineLength);
						} else {
							cursorLocation.update(-1, 0);
						}
						selectionRange.setEnd(new Location(cursorLocation));
					}
				}
			}
		} else {
			selectionRange = new LocationRange();
			selectionRange.setEnd(new Location(cursorLocation));
			
			int lineLength = lines.get(cursorLocation.getX() - 1).length();
			if(cursorLocation.getY() > lineLength) {
				selectionRange.setStart(new Location(cursorLocation.getX() - 1, lineLength));
				cursorLocation.setLocation(cursorLocation.getX() - 1, lineLength);
			} else {
				cursorLocation.update(-1, 0);
				selectionRange.setStart(new Location(cursorLocation));
			}
		}
		
		notifyCursorObservers();
	}
	
	public void addSelectionDown() {
		if(cursorLocation.getX() == lines.size() - 1) {
			return;
		}
		
		if(hasSelection()) {
			if(selectionRange.getEnd().equals(cursorLocation)) {
				int lineLength = lines.get(cursorLocation.getX() + 1).length();
				if(cursorLocation.getY() > lineLength) {
					selectionRange.setEnd(new Location(cursorLocation.getX() + 1, lineLength));
					cursorLocation.setLocation(cursorLocation.getX() + 1, lineLength);
				} else {
					cursorLocation.update(1, 0);
					selectionRange.setEnd(new Location(cursorLocation));
				}
			} else if(selectionRange.getStart().equals(cursorLocation)) {
				if(selectionRange.getEnd().getX() == cursorLocation.getX()) {
					selectionRange.setStart(selectionRange.getEnd());
					int lineLength = lines.get(cursorLocation.getX() + 1).length();
					if(cursorLocation.getY() > lineLength) {
						selectionRange.setEnd(new Location(cursorLocation.getX() + 1, lineLength));
						cursorLocation.setLocation(cursorLocation.getX() + 1, lineLength);
					} else {
						cursorLocation.update(1, 0);
						selectionRange.setEnd(new Location(cursorLocation));
					}
				} else {
					if(selectionRange.getEnd().getY() < cursorLocation.getY() && selectionRange.getEnd().getX() == cursorLocation.getX() + 1) {
						selectionRange.setStart(selectionRange.getEnd());
						int lineLength = lines.get(cursorLocation.getX() + 1).length();
						if(cursorLocation.getY() > lineLength) {
							cursorLocation.setLocation(cursorLocation.getX() + 1, lineLength);
						} else {
							cursorLocation.update(1, 0);
						}
						selectionRange.setEnd(new Location(cursorLocation));
					} else {
						int lineLength = lines.get(cursorLocation.getX() + 1).length();
						if(cursorLocation.getY() > lineLength) {
							cursorLocation.setLocation(cursorLocation.getX() + 1, lineLength);
						} else {
							cursorLocation.update(1, 0);
						}
						selectionRange.setStart(new Location(cursorLocation));
					}
				}
			}
		} else {
			selectionRange = new LocationRange();
			selectionRange.setStart(new Location(cursorLocation));
			
			int lineLength = lines.get(cursorLocation.getX() + 1).length();
			if(cursorLocation.getY() > lineLength) {
				selectionRange.setEnd(new Location(cursorLocation.getX() + 1, lineLength));
				cursorLocation.setLocation(cursorLocation.getX() + 1, lineLength);
			} else {
				cursorLocation.update(1, 0);
				selectionRange.setEnd(new Location(cursorLocation));
			}
		}
		
		notifyCursorObservers();
	}
	
	public String getSelectionText() {
		if(selectionRange != null) {
			int numOfLines = selectionRange.getNumOfLinesInRange();
			Location start = selectionRange.getStart();
			Location end = selectionRange.getEnd();
			
			if(numOfLines == 0) {
				return lines.get(start.getX()).substring(start.getY(), end.getY());
			} else {
				StringBuilder sb = new StringBuilder();
				sb.append(lines.get(start.getX()).substring(start.getY())).append(System.lineSeparator());
				
				for (int i = start.getX() + 1; i < end.getX(); i++) {
					sb.append(lines.get(i)).append(System.lineSeparator());
				}
				
				sb.append(lines.get(end.getX()).substring(0, end.getY()));
				
				return sb.toString();
			}
		} else {
			return "";
		}
	}
	
	//ITERATOR
	
	public Iterator<String> allLines() {
		return new LinesIterator(lines);
	}
	
	public Iterator<String> linesRange(int index1, int index2) {
		return new LinesIterator(lines, index1, index2);
	}
	
	//OTHER
	
	public void setLines(List<String> lines) {
		this.lines = lines;
	}
	
	public List<String> getLines() {
		return lines;
	}
	
	public String getLine(int index) {
		return lines.get(index);
	}
	
	public void reset() {
		EditAction action = new ResetDocumentAction(this);
		action.executeDo();
		undoManager.push(action);
	}
}
