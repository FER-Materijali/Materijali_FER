package hr.fer.ooup.lab3.editor.singleton;

import hr.fer.ooup.lab3.editor.command.EditAction;
import hr.fer.ooup.lab3.editor.observer.stack.StackObserver;

import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

public class UndoManger {

	private static UndoManger uniqueUndoManger;
	
	private Stack<EditAction> undoStack;
	private Stack<EditAction> redoStack;
	
	private List<StackObserver> undoStackObservers;
	private List<StackObserver> redoStackObservers;
	private enum StackState { EMPTY, HAS_ELEMENTS }
	
	private UndoManger() {
		undoStack = new Stack<EditAction>();
		redoStack = new Stack<EditAction>();
		undoStackObservers = new ArrayList<StackObserver>();
		redoStackObservers = new ArrayList<StackObserver>();
	}
	
	public static UndoManger getInstance() {
		if(uniqueUndoManger == null) {
			uniqueUndoManger = new UndoManger();
		}
		return uniqueUndoManger;
	}
	
	public void undo() {
		if(!undoStack.isEmpty()) {
			EditAction action = undoStack.pop();
			action.executeUndo();
			
			if(undoStack.isEmpty()) {
				notifyUndoStackObservers(StackState.EMPTY);
			}
			
			redoStack.push(action);
			notifyRedoStackObservers(StackState.HAS_ELEMENTS);
		} else {
			notifyUndoStackObservers(StackState.EMPTY);
		}
	}
	
	public void redo() {
		if(!redoStack.isEmpty()) {
			EditAction action = redoStack.pop();
			action.executeDo();
			
			if(redoStack.isEmpty()) {
				notifyRedoStackObservers(StackState.EMPTY);
			}
			
			undoStack.push(action);
			notifyUndoStackObservers(StackState.HAS_ELEMENTS);
		} else {
			notifyRedoStackObservers(StackState.EMPTY);
		}
	}
	
	public void push(EditAction action) {
		redoStack.clear();
		undoStack.push(action);
		notifyUndoStackObservers(StackState.HAS_ELEMENTS);
		notifyRedoStackObservers(StackState.EMPTY);
	}
	
	// UNDO STACK OBSERVER
	
	public void addUndoStackObserver(StackObserver observer) {
		if(!undoStackObservers.contains(observer)) {	
			undoStackObservers.add(observer);
		}
	}
	
	public void removeUndoStackObserver(StackObserver observer) {
		undoStackObservers.remove(observer);
	}
	
	private void notifyUndoStackObservers(StackState state) {
		if(state == StackState.EMPTY) {
			for (StackObserver observer : undoStackObservers) {
				observer.stackEmpty();
			}
		} else if(state == StackState.HAS_ELEMENTS) {
			for (StackObserver observer : undoStackObservers) {
				observer.stackHasElements();;
			}
		}
	}
	
	//REDO STACK OBSERVER
	
	public void addRedoStackObserver(StackObserver observer) {
		if(!redoStackObservers.contains(observer)) {	
			redoStackObservers.add(observer);
		}
	}
	
	public void removeRedoStackObserver(StackObserver observer) {
		redoStackObservers.remove(observer);
	}
	
	private void notifyRedoStackObservers(StackState state) {
		if(state == StackState.EMPTY) {
			for (StackObserver observer : redoStackObservers) {
				observer.stackEmpty();
			}
		} else if(state == StackState.HAS_ELEMENTS) {
			for (StackObserver observer : redoStackObservers) {
				observer.stackHasElements();;
			}
		}
	}
}
