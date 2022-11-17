import java.util.Scanner;

/**
 * Created by frina on 03.05.17..
 */
public class Parser {
    private static String enteringString = new String();
    private static Integer counter;
    private static boolean stringAcceptence;
    private static String character = new String();

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        enteringString = sc.nextLine();
        counter=0;
        stringAcceptence = true;
        S();
        if(counter == enteringString.split(("(?!^)")).length && stringAcceptence == true) {
            System.out.println();
            System.out.print("DA");
        } else {
            System.out.println();
            System.out.print("NE");
        }

    }
    private static void S() {
        System.out.print("S");
        if (counter != enteringString.split(("(?!^)")).length) {
            character = enteringString.split("(?!^)")[counter];
            counter++;
        }
        switch (character) {
            case "a":
                character="";
                A();
                if (counter != enteringString.split(("(?!^)")).length  || stringAcceptence == true || !character.equals("")) {
                    if(character.equals("") || enteringString.split("(?!^)")[counter].equals("c") ) {
                        B();
                    } else {
                        stringAcceptence = false;
                        return;
                    }
                }
                break;

            case "b":
                character="";
                B();
                if (counter != enteringString.split(("(?!^)")).length  || stringAcceptence == true ||  !character.equals("")) {
                    A();
                }
                break;
            default:
                stringAcceptence = false;
                break;
        }
    }

    private static void A() {
            System.out.print("A");
            if(counter != enteringString.split(("(?!^)")).length && character.equals("")) {
                character = enteringString.split("(?!^)")[counter];
                counter++;
            }

                switch (character) {
                    case "a":
                        character = "";
                        stringAcceptence=true;
                        return;
                    case "b":
                        character="";
                        C();
                        break;
                    default:
                        if(counter != enteringString.split(("(?!^)")).length) {
                        stringAcceptence = false;
                        break;
                    } else {
                            character="";
                        stringAcceptence = false;
                        break;
                    }

                }
    }


    private static void C() {
        System.out.print("C");
        A();
        if(counter != enteringString.split(("(?!^)")).length || stringAcceptence == true) {
            A();
        }
    }


    private static void B() {

        System.out.print("B");
        if (counter != enteringString.split(("(?!^)")).length && character.equals("")) {
            character = enteringString.split("(?!^)")[counter];
            counter++;
        }
        switch (character) {
            case "": {
                stringAcceptence=true;
                return;

            }
            case "c":
                character="";
                if (counter != enteringString.split(("(?!^)")).length && character.equals("")) {
                    character = enteringString.split("(?!^)")[counter];
                    counter++;
                }
                switch (character) {
                    case "c": {
                        character = "";
                        S();
                        if (counter != enteringString.split(("(?!^)")).length && character.equals("")) {
                            character = enteringString.split("(?!^)")[counter];
                            counter++;
                        }
                        switch (character) {
                            case "b":
                                character = "";
                                if (counter != enteringString.split(("(?!^)")).length && character.equals("")) {
                                    character = enteringString.split("(?!^)")[counter];
                                    counter++;
                                }
                                switch (character) {
                                    case "c":
                                        character = "";
                                        stringAcceptence = true;
                                        return;
                                    default:
                                        stringAcceptence = false;
                                        break;
                                }
                                break;
                            default:
                                if (counter != enteringString.split(("(?!^)")).length) {
                                    stringAcceptence = false;
                                    break;
                                } else {
                                    character = "";
                                    stringAcceptence = false;
                                    break;
                                }

                        }
                    }
                    break;
                    default:
                        stringAcceptence = false;
                        break;
                }
        }
    }
}
