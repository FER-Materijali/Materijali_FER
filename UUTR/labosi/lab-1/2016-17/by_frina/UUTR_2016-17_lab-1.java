import java.util.*;

/**
 * Created by frina on 28.03.17..
 */
public class SimEnka {
    private static Set<String> states = new HashSet<>();
    private static String[] inputStrings;
    private static Set<String> symbols = new HashSet<>();
    private static Set<String> acceptableConditions = new HashSet<>();
    private static String startingState = new String();
    private static Map<String, Map<String, List<String>>> tableOfTransition = new HashMap<>();

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String line = new String();
        line = sc.nextLine();
        inputStrings = line.split("\\|");
        line = sc.nextLine();
        for (String s : line.split("\\,")) {
            states.add(s);
        }
        states.add("#");
        line = sc.nextLine();
        for (String s : line.split("\\,")) {
            symbols.add(s);
        }
        line = sc.nextLine();

        for (String s : line.split("\\,")) {
            acceptableConditions.add(s);
        }
        line = sc.nextLine();
        startingState = line.trim();
        while (sc.hasNextLine() && !(line = sc.nextLine()).isEmpty()) {
            List<String> list;
            String currentState = new String();
            String transitionSymbol = new String();
            String newState = new String();

            int index = line.indexOf(",");//the index 0f ,
            int index2 = line.indexOf("->");//the index of ->
            currentState = line.substring(0, index);
            transitionSymbol = line.substring(index + 1, index2);
            newState = line.substring(index2 + 2);
            Map<String, List<String>> transitionTable = new HashMap<>();
            if (tableOfTransition.containsKey(currentState)) {
                transitionTable = tableOfTransition.get(currentState);
            }
            if (transitionTable.get(transitionSymbol) == null) {
                list = new ArrayList<>();
            } else {
                list = transitionTable.get(transitionSymbol);
            }
            list.add(newState);
            transitionTable.put(transitionSymbol, list);
            tableOfTransition.put(currentState, transitionTable);
        }
        Set<String> state = new TreeSet<>();
        Set<String> newStates = new TreeSet<>();
        List<String> passedStates = new ArrayList<>();
        Set<String> list = new TreeSet<>();
        int j = 0;
        for (int i = 0; i < inputStrings.length; i++) {
            state.clear();
            newStates.clear();
            passedStates.clear();
            j = 0;
            state.add(startingState);
            String[] enteringStrings = inputStrings[i].split(",");
            for (String sim : enteringStrings) {
                if (symbols.contains(sim)) {
                    list.addAll(state);
                    if (j == 0) {
                        while(!(state.containsAll(calculateEpsilonEnviroment(state)))) {
                            state.addAll(calculateEpsilonEnviroment(state));
                        }
                        passedStates.addAll(state);
                        passedStates.add("|");

                    }
                    for(String s: state) {
                        for(String d: calculateTranitions(s,sim)) {
                            if(!(newStates.contains(d))) {
                                newStates.add(d);
                            }
                        }
                    }
                    state.clear();
                    while(!(newStates.containsAll(calculateEpsilonEnviroment(newStates)))) {
                        newStates.addAll(calculateEpsilonEnviroment(newStates));
                    }

                    state.addAll(newStates);
                    newStates.clear();
                    if(state.isEmpty()) {
                        passedStates.add("#");
                        passedStates.add("|");
                    } else {

                        passedStates.addAll(state);
                        passedStates.add("|");
                    }



                    ++j;
                } else {
                    continue;
                }
            }
            for(int k = 0; k < passedStates.size()-1;k++) {
                if(passedStates.get(k+1).equals("|") ||
                        k == (passedStates.size()-1) || passedStates.get(k).equals("|")) {
                    System.out.print(passedStates.get(k));
                } else {
                    System.out.print(passedStates.get(k) +",");
                }
            }
            System.out.println();
        }


        sc.close();
    }

    public static List<String> calculateTranitions(String state, String symbol) {
        List<String> newStates = new ArrayList<String>();

        if (tableOfTransition.containsKey(state)) {
            if (tableOfTransition.get(state).get(symbol) != null) {
                for (String d : tableOfTransition.get(state).get(symbol)) {
                    if(d.equals("#")) {
                        continue;
                    }
                    if(d.split(",") != null) {
                        for(String f: d.split(",")) {
                            newStates.add(f);
                        }
                    } else {
                        newStates.add(d);
                    }
                }
            }

        }

        return newStates;
    }
    public static List<String> calculateEpsilonEnviroment (Set < String > state) {
        List<String> newStates = new ArrayList<String>();
        for (String s : state) {
            if (tableOfTransition.containsKey(s)) {
                if (tableOfTransition.get(s).get("$") != null) {
                    for (String d : tableOfTransition.get(s).get("$")) {
                        if(d.equals("#")) {
                            continue;
                        }
                        if(d.split(",") != null) {
                            for(String f: d.split(",")) {
                                newStates.add(f);
                            }
                        } else {
                            newStates.add(d);
                        }
                    }
                }
            }

        }
        return newStates;
    }
}
