import java.util.ArrayList;
import java.util.List;

/*
Klasa i metoda koju poziva ispitni sustav SPPRUT.

Nemojte mijenjati:
  - naziv datoteke
  - naziv klase
  - parametre konstruktora klase (konstruktor se poziva bez parametara)
  - naziv metode
  - broj ulaznih parametara
  - tipove ulaznih parametara
  - tip povratne vrijednosti

Ulazni parametri:
  definicijaPA: string s definicijom funkcije prijelaza PushdownMachine
                oblikovan prema uputama na FERWebu
  ulazniNiz: string s nizom znakova za koji PushdownMachine provjerava da li se prihvaca

Povratna vrijednost:
  int: 1 ako PushdownMachine prihvaca niz
       0 ako PushdownMachine ne prihvaca niz
*/

public class utrlab2 {
	
	public utrlab2() {}
	
	public int utrlab2_f(String definicijaPA, String ulazniNiz) {
		
		String[] machineDefinition = definicijaPA.substring(1, definicijaPA.length() - 1).split("%");
		
		String startingState = machineDefinition[3];
		String stackBottom = machineDefinition[4];
		String[] acceptableStates = machineDefinition[5].split(",");
		List<String> transitions = new ArrayList<String>();

		String[] inputStream = ulazniNiz.split("");
		
		List<PushdownMachine> workingMachines = new ArrayList<PushdownMachine>();
		
		for (int i = 6; i < machineDefinition.length; i++) {
			String cause = machineDefinition[i].split("->")[0];
			String[] effect = machineDefinition[i].split("->")[1].split("#");
			
			for (int j = 0; j < effect.length; j++) {
				transitions.add(cause + "->" + effect[j]);
			}
		}
		
		new PushdownMachine(startingState, stackBottom, transitions, workingMachines);
		for (int i = 1; i < inputStream.length; i++) {
			List<PushdownMachine> listOfEpsilonTransitionInvokedMachines = new ArrayList<PushdownMachine>();
			for (PushdownMachine m : workingMachines) {
				m.executeEpsilonProductions(listOfEpsilonTransitionInvokedMachines);
			}
			for (PushdownMachine m : listOfEpsilonTransitionInvokedMachines) {
				workingMachines.add(m);
			}
			List<PushdownMachine> listOfNormalTransitionInvokedMachines = new ArrayList<PushdownMachine>();
			List<PushdownMachine> listOfObsoleteMachines = new ArrayList<PushdownMachine>();
			for (PushdownMachine m : workingMachines) {
				listOfObsoleteMachines.add(m);
				m.feed(inputStream[i], listOfNormalTransitionInvokedMachines);
			}
			for (PushdownMachine m : listOfNormalTransitionInvokedMachines) {
				workingMachines.add(m);
			}
			workingMachines.removeAll(listOfObsoleteMachines);
		}
		
		List<PushdownMachine> listOfEpsilonTransitionInvokedMachines = new ArrayList<PushdownMachine>();
		for (PushdownMachine m : workingMachines) {
			m.executeEpsilonProductions(listOfEpsilonTransitionInvokedMachines);
		}
		
		for (PushdownMachine m : listOfEpsilonTransitionInvokedMachines) {
			workingMachines.add(m);
		}

		for (int i = 0; i < workingMachines.size(); i++) {
			for (int j = 0; j < acceptableStates.length; j++) {
				if ((workingMachines.get(i).getMachineStatus()) && (workingMachines.get(i).getCurrentState().equals(acceptableStates[j]))) {
					return 1;
				}
			}
		}
		return 0;
	}
}
