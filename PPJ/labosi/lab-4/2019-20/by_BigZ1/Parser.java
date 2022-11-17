import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Parser {
    private static ArrayList<String> ulazniZnakovi = new ArrayList<>();
    private static String ispis;

    public void CitanjeNiza() throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String tmp = new String();
        tmp = reader.readLine();
        for (char tmpChar : tmp.toCharArray()) {
            ulazniZnakovi.add(String.valueOf(tmpChar));
        }
        ispis = "";
        izracunParsiranja();
    }

    public void izracunParsiranja(){
        //pozivat cemo sve ove ostale
        if(prijelazS() && ulazniZnakovi.isEmpty()){
            System.out.println(ispis);
            System.out.println("DA");
        }
        else{
            System.out.println(ispis);
            System.out.println("NE");
        }
        return;
    }

    public boolean prijelazS(){
        ispis+="S";
        if(ulazniZnakovi.isEmpty()){
            return false;
        }
        if(ulazniZnakovi.get(0).equals("a")){
            ulazniZnakovi.remove(0);
            if(prijelazA()){
                if(prijelazB()){
                    return true;
                }
            }
            else{
                return false;
            }
        }
        else if(ulazniZnakovi.get(0).equals("b")){
            ulazniZnakovi.remove(0);
            if(prijelazB() && prijelazA()){
                return true;
            }
            else{
                return false;
            }
        }
        else{
            return false;
        }
        return false;
    }

    private boolean prijelazA(){
        ispis+="A";
        if(ulazniZnakovi.isEmpty()){
            return false;
        }
        if(ulazniZnakovi.get(0).equals("a")){
            ulazniZnakovi.remove(0);
            return true;
        }
        else if(ulazniZnakovi.get(0).equals("b")){
            ulazniZnakovi.remove(0);
            if(prijelazC()){
                return true;
            }
        }
        else{
            return false;
        }
        return false;
    }

    private boolean prijelazB(){
        ispis+="B";
        if(!ulazniZnakovi.isEmpty()){
        if(ulazniZnakovi.get(0).equals("c")){
            ulazniZnakovi.remove(0);
            if(ulazniZnakovi.get(0).equals("c")){
                ulazniZnakovi.remove(0);
                if(prijelazS()) {
                    if (ulazniZnakovi.get(0).equals("b")) {
                        ulazniZnakovi.remove(0);
                        if (ulazniZnakovi.get(0).equals("c")) {
                            ulazniZnakovi.remove(0);
                            return true;
                        }
                        else{
                            return false;
                        }
                    }
                    else {
                        return false;
                    }
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
        }
        return true;
    }

    private boolean prijelazC(){
        ispis+="C";
        //buduci da imamo dva puta A
        if(prijelazA()){
            //mozemo zvati ponovo A
            if(prijelazA()) {
                return true;
            }
        }
        return false;
    }

    public static void main(String args[]) throws IOException {
        Parser parser = new Parser();
        parser.CitanjeNiza();
    }

}
