import java.awt.*;
import java.text.CollationElementIterator;
import java.util.*;
import java.util.List;

/**
 * Created by frina on 10.04.17..
 */
public class MinDka {
    private static Set<String> states = new TreeSet<>();
    private static Set<String> symbols = new TreeSet<>();
    private static Set<String> acceptableConditions = new TreeSet<>();
    private static String startingState = new String();
    private static Map<String,String> tableOfTransition = new LinkedHashMap<>();
    private static Map<String,String> listOfStates = new LinkedHashMap<>();
    private static Map<String,String> unlikeStates = new LinkedHashMap<>();

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String line = new String();
        line = sc.nextLine();
        for (String s : line.split("\\,")) {
            states.add(s);
        }
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
            String currentState = new String();
            String newState = new String();

            currentState = line.split("->")[0];
            newState = line.split("->")[1];

            tableOfTransition.put(currentState, newState);
        }
        calculateUnreachableStates();
        calculateSameStates();
        print();


    }

    public static void calculateUnreachableStates() {
        List<String> reachable = new ArrayList<>();
        List<String> deleteState = new ArrayList<>();
        reachable.add(startingState);
        for(int i=0; i < reachable.size(); i++) {
            for(String s: tableOfTransition.keySet()) {
                if(s.split(",")[0].equals(reachable.get(i))) {
                    if(!reachable.contains(tableOfTransition.get(s))) {
                        reachable.add(tableOfTransition.get(s));
                    }
                }
            }
        }

        for(String s: tableOfTransition.keySet()) {
            if(!reachable.contains(s.split(",")[0])) {
                deleteState.add(s);
            }
        }
        for(String s: deleteState) {
            tableOfTransition.remove(s);
        }
        deleteState.clear();
        reachable.sort(null);
        states.clear();
        states.addAll(reachable);
        for(String s: acceptableConditions) {
            if(!(reachable.contains(s))) {
                deleteState.add(s);
            }
        }
        acceptableConditions.removeAll(deleteState);


    }
    public static void print() {
        printList(states);
        printList(symbols);
        printList(acceptableConditions);
        System.out.println(startingState);
        for(Map.Entry<String,String> entry: tableOfTransition.entrySet()) {
            System.out.println(entry.getKey()+"->" +entry.getValue());
        }
    }

    public static void printList(Set<String> list) {
        int i= 0;
        for(String s: list) {
            if(i == list.size()-1) {
                System.out.print(s);
            } else {
                System.out.print(s+",");
                i++;
            }
        }
        System.out.println();
    }
    public static void calculateSameStates() {

        separate();
        calculateXAndLists();
        checkForX();
        Set<String> sameStates = new TreeSet<>();
        sameStates = findSameStates();
        minimazeDka(sameStates);
    }
    public static void minimazeDka(Set<String> state) {
        for(String s: state) {
            for(String d: symbols) {
                tableOfTransition.remove(s.split(",")[1]+","+d);
                states.remove(s.split(",")[1]);
                acceptableConditions.remove(s.split(",")[1]);
                if(s.split(",")[1].equals(startingState)) {
                    startingState = s.split(",")[0];
                }
            }

        }
        for(String k: tableOfTransition.keySet()) {
            for(String d: state) {
                if(tableOfTransition.get(k).equals(d.split(",")[1])) {
                    tableOfTransition.put(k,d.split(",")[0]);
                }
            }
        }
    }
    public static void separate() {
        List<String> list = new ArrayList<>();
        list.addAll(states);
        for(int i= 0; i < states.size()-1; i++) {
            for(int j=i+1; j<states.size(); j++) {
                if(acceptableConditions.contains(list.get(i)) ^
                        (acceptableConditions.contains(list.get(j)))) {
                    String key = list.get(i)+","+list.get(j);
                    unlikeStates.put(key, "X");
                }
            }
        }
    }
    public static void calculateXAndLists() {
        List<String> list = new ArrayList<>();
        list.addAll(states);
        for(int i= 0; i< states.size()-1; i++) {
            for(int j=i+1; j<states.size(); j++) {

                    for(String word:symbols) {
                        String temp1 = list.get(i)+","+word;
                        String temp2 = list.get(j) +","+word;
                        String state1 = tableOfTransition.get(temp1);
                        String state2 = tableOfTransition.get(temp2);
                        if(state1.compareTo(state2)>0) {
                            String temp;
                            temp = state1;
                            state1 = state2;
                            state2=temp;
                        }
                        String key = state1 + "," + state2;
                        if(unlikeStates.containsKey(key)) {
                            unlikeStates.put(list.get(i)+","+list.get(j),"X");
                        } else {
                            listOfStates.put(key,list.get(i)+","+list.get(j));
                        }
                    }

                }
            }

        }

    public static void checkForX() {
        boolean changed = true;
        int i=0;
        do {
            for(String s: listOfStates.keySet()) {
                if(unlikeStates.containsKey(s)) {
                    unlikeStates.put(listOfStates.get(s),"X");
                    i++;
                }
            }
            if(i > listOfStates.size()*4) {
                changed=false;
            }
        } while(changed == true && i!=0);

    }
    public static Set<String> findSameStates() {
        Set<String> set = new TreeSet<>();
        List<String> list = new ArrayList<>();
        list.addAll(states);
        for(int i = 0; i < states.size()-1; i++) {
            for(int j= i+1; j < states.size(); ++j) {
                if(!unlikeStates.containsKey(list.get(i)+","+list.get(j))) {
                    set.add(list.get(i)+","+list.get(j));
                }
            }
        }

        return set;
    }

}
