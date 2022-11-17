

import java.util.*;

/**
 * Created by frina on 18.05.17..
 */
public class SimTS {
    private static Set<String> states = new HashSet<>();
    private static Set<String> symbols = new HashSet<>();
    private static Set<String> trackSymbols = new HashSet<>();
    private static String emptyCell = new String();
    private static String[] track = new String[70];
    private static Set<String> acceptableStates = new HashSet<>();
    private static String startingState = new String();
    private static int startingPosition;
    private static Map<String,String> transition = new HashMap<>();
    private static boolean stringAcceptance = true;
    private static String state = new String();

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String line = new String();
        int counter = 0;
        line = sc.nextLine();
        for(String s: line.split("\\,")) {
            states.add(s);
        }
        line = sc.nextLine();
        for(String s: line.split("\\,")) {
            symbols.add(s);
        }
        line = sc.nextLine();
        for(String s: line.split("\\,")) {
            trackSymbols.add(s);
        }
        line = sc.nextLine();
        emptyCell = line;
        line = sc.nextLine();
        for(String s: line.split("(?!^)")) {
            track[counter] = s;
            counter++;
        }
        line = sc.nextLine();
        for(String s: line.split("\\,")) {
            acceptableStates.add(s);
        }
        line = sc.nextLine();
        startingState = line;
        line = sc.nextLine();
        startingPosition = Integer.valueOf(line);
        String currentState = new String();
        String newState = new String();
        state = startingState;
        while (sc.hasNextLine() && !(line = sc.nextLine()).isEmpty()) {
            currentState = line.split("->")[0];
            newState = line.split("->")[1];

            transition.put(currentState, newState);
        }
        simpulateTS();

    }
    private static void simpulateTS() {
        String symbol = new String();
        String change = new String();
        while(stringAcceptance == true && !acceptableStates.contains(state)) {
            symbol = track[Integer.valueOf(startingPosition)];
            if(!transition.containsKey(state+","+symbol)) {
                stringAcceptance = false;
            } else {
                change = transition.get(state+","+symbol);
                if(startingPosition == 69 && change.split(",")[2].equals("R")) {
                    stringAcceptance = false;
                } else if (startingPosition == 0 && change.split(",")[2].equals("L") ) {
                    stringAcceptance = false;
                } else {
                    track[startingPosition] = change.split(",")[1];
                    state = change.split(",")[0];
                    if(change.split(",")[2].equals("R")) {
                        startingPosition++;
                    } else {
                        startingPosition--;
                    }
                    if(acceptableStates.contains(state)) {
                        break;
                    }

                }
            }
        }
        if(stringAcceptance == true) {
            System.out.print(state + "|"+startingPosition+"|");
            for(String s: track) {
                System.out.print(s);
            }
            System.out.print("|");
            System.out.print(1);
        } else {
            System.out.print(state + "|"+startingPosition+"|");
            for(String s: track) {
                System.out.print(s);
            }
            System.out.print("|");
            System.out.print(0);
        }
    }


}
