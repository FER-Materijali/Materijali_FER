import java.util.*;
/**
 * Created by frina on 30.04.17..
 */
public class SimPa {
    private static Set<String> states = new HashSet<>();
    private static String[] inputStrings;
    private static Set<String> symbols = new HashSet<>();
    private static Set<String> stackSymbols = new HashSet<>();
    private static Set<String> acceptableStates = new HashSet<>();
    private static String startingState = new String();
    private static Map<String, String> tableOfTransition = new HashMap<>();
    private static String stackStartingState = new String();
    private static boolean stringAcceptence = true;
    private static List<String> stack = new ArrayList<>();
    private static String state = new String();

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String line = new String();
        line = sc.nextLine();
        inputStrings = line.split("\\|");
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
            stackSymbols.add(s);
        }
        line = sc.nextLine();
        for(String s: line.split("\\,")) {
            acceptableStates.add(s);
        }
        line = sc.nextLine();
        startingState = line.trim();
        state = startingState;
        line = sc.nextLine();
        stackStartingState = line.trim();

        if(!(stackStartingState.equals(""))) {
            stack.add(stackStartingState);
        }

        String currentState = new String();
        String newState = new String();
        while (sc.hasNextLine() && !(line = sc.nextLine()).isEmpty()) {
            currentState = line.split("->")[0];
            newState = line.split("->")[1];

            tableOfTransition.put(currentState, newState);
        }
        simulateSimPa();



    }

    private static void simulateSimPa() {
        String newStack = new String();
        String newSymbolOfStack = new String();
        String newState = new String();
        for(int i= 0; i < inputStrings.length; i++) {
            String[] enteringStrings = inputStrings[i].split(",");
            stack.clear();
            stack.add(stackStartingState);
            state = startingState;
            System.out.print(state + "#");
            Collections.reverse(stack);
            if (stack.size() == 0) {
                System.out.print("$|");
            } else {
                for (String s : stack) {
                    System.out.print(s);
                }
                System.out.print("|");
            }
            Collections.reverse(stack);
            for (String sim : enteringStrings) {
                if (stack.size()!=0) {
                    if (tableOfTransition.containsKey(state + "," + sim + "," + (stack.get(stack.size() - 1)))) {
                        newStack = tableOfTransition.get(state + "," + sim + "," + (stack.get(stack.size() - 1)));
                        newSymbolOfStack = newStack.split(",")[1].split("(?!^)")[0];
                        newState = newStack.split(",")[0];
                        state = newState;
                        if (newSymbolOfStack.equals("$")) {
                            stack.remove(stack.size() - 1);

                        } else {
                            if (newStack.split(",")[1].split("(?!^)").length == 2) {
                                stack.add(newSymbolOfStack);
                            }
                        }

                        System.out.print(state + "#");
                        Collections.reverse(stack);
                        if (stack.size() == 0) {
                            System.out.print("$|");
                        } else {
                            for (String s : stack) {
                                System.out.print(s);
                            }
                            System.out.print("|");
                        }

                        Collections.reverse(stack);
                    } else {

                        System.out.print("fail|");
                        stringAcceptence = false;
                        break;

                    }
                    if (tableOfTransition.containsKey(state + "," + "$" + "," + (stack.get(stack.size() - 1)))) {
                        calculateEpsilon();
                    }
                } else {
                    System.out.print("fail|");
                    stringAcceptence = false;
                    break;
                }



            }
            if(acceptableStates.contains(state) && stringAcceptence == true) {
                System.out.print(1);
            } else {
                System.out.print(0);
            }

            System.out.println();

        }

    }
    private static void calculateEpsilon() {
        String newStack = new String();
        String newSymbolOfStack = new String();
        String newState = new String();

            newStack = tableOfTransition.get(state+","+"$"+","+(stack.get(stack.size()-1)));
            newSymbolOfStack = newStack.split(",")[1].split("(?!^)")[0];
            newState = newStack.split(",")[0];
            state=newState;
            if(newSymbolOfStack.equals("$")) {
                stack.remove(stack.size()-1);

            } else {
                if(newStack.split(",")[1].split("(?!^)").length==2) {
                    stack.add(newSymbolOfStack);
                }
            }

            System.out.print(state+"#");
            Collections.reverse(stack);
            if(stack.size()==0) {
                System.out.print("$|");
            } else {
                for(String s: stack) {
                    System.out.print(s);
                }
                System.out.print("|");
            }

    }

}
