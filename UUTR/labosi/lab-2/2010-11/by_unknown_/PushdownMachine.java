import java.util.ArrayList;
import java.util.List;
import java.util.Stack;


public class PushdownMachine {
	
	private Stack<String> stack;
	private String currentState;
	private List<String> setOfTransitions;
	private boolean machineStatus;
	private List<PushdownMachine> pushdownMachines;
	
	public PushdownMachine(PushdownMachine pm, List<PushdownMachine> machines) {
		copyParentTransitions(pm.getSetOfTransitions());
		this.pushdownMachines = machines;
		copyParentStack(pm.getStack());
		this.currentState = pm.getCurrentState();
		this.machineStatus = pm.getMachineStatus();
	}
	
	public PushdownMachine(String startingState, String startingStackToken, List<String> transitions, List<PushdownMachine> machines) {
		copyParentTransitions(transitions);
		this.pushdownMachines = machines;
		this.stack = new Stack<String>();
		this.currentState = startingState;
		this.stack.push(startingStackToken);
		this.machineStatus = true;
		this.pushdownMachines.add(this);
	}
	
	public Stack<String> getStack() {
		return this.stack;
	}

	public boolean getMachineStatus() {
		return this.machineStatus;
	}
	
	public List<String> getSetOfTransitions() {
		return this.setOfTransitions;
	}

	public String getCurrentState() {
		return this.currentState;
	}

	private void copyParentTransitions(List<String> parentTransitions) {
		this.setOfTransitions = new ArrayList<String>();
		for (String transition : parentTransitions) {
			this.setOfTransitions.add(new String(transition));
		}
	}
	
	public void feed(String input, List<PushdownMachine> machines) {
		if (this.stack.size() == 0) {
			this.machineStatus = false;
			return;
		}
		List<String> availableTransitions = new ArrayList<String>();
		for (String transition : setOfTransitions) {
			if (transition.startsWith(this.currentState + "," + input + "," + this.stack.peek() + "->")) {
				availableTransitions.add(transition);
			}
		}
		
		if (availableTransitions.size() == 0) {
			this.machineStatus = false;
			return;
		}
		
		for (String transition : availableTransitions) {
			PushdownMachine childMachine = new PushdownMachine(this, machines);
			childMachine.executeOneProduction(transition);
			childMachine.addTo(machines);
		}
	}
	
	public void executeEpsilonProductions(List<PushdownMachine> machines) {
		if (this.stack.size() == 0) {
			this.machineStatus = false;
			return;
		}
		List<String> availableTransitions = new ArrayList<String>();
		for (String transition : setOfTransitions) {
			if (transition.startsWith(this.currentState + ",$," + this.stack.peek() + "->")) {
				availableTransitions.add(transition);
			}
		}
		
		if (availableTransitions.size() == 0) {
			return;
		}
		
		for (String transition : availableTransitions) {
			PushdownMachine childMachine = new PushdownMachine(this, machines);
			childMachine.executeOneProduction(transition);
			childMachine.addTo(machines);
			childMachine.executeEpsilonProductions(machines);
		}
	}
	
	public void executeOneProduction(String production) {
		String[] interest = production.split("->")[1].split(",");
		
		this.currentState = interest[0];
		String[] newStackTop = interest[1].split("");
		this.stack.pop();
		if (!interest[1].equals("$")) {
			for (int i = newStackTop.length - 1; i > 0; i--) {
				this.stack.push(newStackTop[i]);
			}
		}
	}
	
	private void copyParentStack(Stack<String> old) {
		this.stack = new Stack<String>();
		for (int i = 0; i < old.size(); i++) {
			this.stack.push(new String(old.get(i)));
		}
	}
	
	public void addTo(List<PushdownMachine> machines) {
		machines.add(this);
	}
}
