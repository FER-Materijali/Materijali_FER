import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class SimEnka {
    private static String[] ulazniNizovi;
    private static String[] stanjaAutomata;
    private static String[] abecedaUlaza;
    private static String[] prihvatljivaStanja;
    private static String pocetnoStanje;
    String citanje = new String();
    private static HashMap <String,String> prijelaziAutomata = new HashMap<>();

    public void CitanjeAutomata() throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        ulazniNizovi=reader.readLine().split("\\|");
        stanjaAutomata=reader.readLine().split(",");
        abecedaUlaza=reader.readLine().split(",");
        prihvatljivaStanja=reader.readLine().split(",");
        pocetnoStanje=reader.readLine();
        //mora postojati barem jedan prijelaz pa ce uci u petlju
        while((citanje=reader.readLine())!=null){
            if(citanje.isEmpty()){
                break;
            }
            prijelaziAutomata.put(citanje.split("->")[0],citanje.split("->")[1]);
        }
    }

    public void izracunAutomata() {
        ArrayList<String> Izracun = new ArrayList<String>();
        //izracun mi sluzi da na njega dodam pocetna stanja,sad problem moze bit ako dodamo puno stanja dal get(i) radi kako spada
        for (String ulazi : ulazniNizovi
        ) {
            Izracun.add(pocetnoStanje);
            String[] ulazniZnakovi = ulazi.split(",");
            //cini mi se da ovdje ne dodajem nista u ovo prijeIzracuna nova stanja???
            for (int i = 0; i <= ulazniZnakovi.length; i++) {
                //ovo je da mi na svaki znak (pocetni ili koji god) vidi jel on ima epsilon prijelaz da ih doda
                String mogucaEpsilonokolina = izracunEpsilona(Izracun.get(i));
                String tmp=Izracun.get(i);
                Izracun.remove(i);
                if(!mogucaEpsilonokolina.isEmpty()){
                    tmp+=",";
                    tmp+=mogucaEpsilonokolina;
                    Izracun.add(tmp);
                }
                if(mogucaEpsilonokolina.isEmpty()){
                    Izracun.add(tmp);
                }
                TreeSet<String> izbaciPonavljanje = new TreeSet<String>();
                for(int k=0;k<Izracun.get(i).toString().split(",").length;k++){
                    izbaciPonavljanje.add(Izracun.get(i).toString().split(",")[k]);
                }
                Izracun.remove(i);
                if(izbaciPonavljanje.size()>1 && izbaciPonavljanje.contains("#")){
                    izbaciPonavljanje.remove("#");
                }
                String tmp2 = new String();
                for(int k=0;k<izbaciPonavljanje.size();k++) {
                    tmp2 += izbaciPonavljanje.toArray()[k];
                    if (k < izbaciPonavljanje.size() - 1) {
                        tmp2+= ",";
                    }
                }
                Izracun.add(tmp2);
                if(i<ulazniZnakovi.length) {
                    String sljedeceStanjeAutomata = izracunPrijelaza(Izracun.get(i), ulazniZnakovi[i]);
                    Izracun.add(sljedeceStanjeAutomata);
                }
                else break;
            }
            ispisSvihStanja(Izracun);
            Izracun.clear();
            //msm da bi trebao tu ispisati sve prijalze pa onda dodati | i ponovo sve..
        }
        return;
    }

    public static String izracunEpsilona(String moguceEpsilonstanje){
        //rekao je rekurzivno da se zove samo od sebe
        String vracanjeNazadOkoline = new String();
        TreeSet<String> izbaciPonavljanje = new TreeSet<String>();
        Deque<String> okolina = new ArrayDeque<String>();
        TreeSet<String> provjeraZaPonovnoVracanje = new TreeSet<String>();
        for(int j=0;j<moguceEpsilonstanje.split(",").length;j++){
            for(String stanje:prijelaziAutomata.keySet()){
                if(stanje.split(",")[0].equals(moguceEpsilonstanje.split(",")[j])){
                    if(stanje.split(",")[1].equals("$")) {
                        for (int i = 0; i < moguceEpsilonstanje.split(",").length; i++) {
                             izbaciPonavljanje.add(izracunPrijelaza(moguceEpsilonstanje.split(",")[i], "$"));
                             provjeraZaPonovnoVracanje.add(moguceEpsilonstanje);
                        }
                    }
                }
            }
        }
        for(int i=0;i<izbaciPonavljanje.size();i++) {
            vracanjeNazadOkoline += izbaciPonavljanje.toArray()[i];
            okolina.add(vracanjeNazadOkoline);
            if(i==0){
                provjeraZaPonovnoVracanje.add(vracanjeNazadOkoline);
            }
            if (i < izbaciPonavljanje.size() - 1) {
                provjeraZaPonovnoVracanje.add(vracanjeNazadOkoline);
                vracanjeNazadOkoline += ",";
            }
        }
        while(!okolina.isEmpty()){
            String prijelaz=izracunPrijelaza(okolina.pop(),"$");
            for(int i=0;i<prijelaz.split(",").length;i++){
                if(provjeraZaPonovnoVracanje.contains(prijelaz.split(",")[i])){
                    continue;
                }
                else {
                    provjeraZaPonovnoVracanje.add(prijelaz.split(",")[i]);
                    okolina.add(prijelaz.split(",")[i]);
                }
            }
        }
        String vratiNazad=new String();
        for(int i=0;i<provjeraZaPonovnoVracanje.size();i++){
           vratiNazad+=provjeraZaPonovnoVracanje.toArray()[i];
           vratiNazad+=",";
        }
    return vratiNazad;
    }

    public static String izracunPrijelaza(String stanje,String ulazniZnak){
        String sljedeceStanje=new String();
        if(stanje.split(",").length>1){
            TreeSet<String> izbaciPonavljanje=new TreeSet<String>();
            for(int i=0;i<stanje.split(",").length;i++){
                for(String key:prijelaziAutomata.keySet()){
                    if((!key.split(",")[0].contains(stanje)) && (ulazniZnak.equals("$"))){
                        izbaciPonavljanje.add(stanje);
                    }
                    if((!key.split(",")[0].contains(stanje)) && (!ulazniZnak.equals("$"))){
                        izbaciPonavljanje.add("#");
                    }
                    if(key.split(",")[0].equals(stanje.split(",")[i]) && ulazniZnak.equals(key.split(",")[1])){
                        for(int j=0;j<prijelaziAutomata.get(key).split(",").length;j++){
                            izbaciPonavljanje.add(prijelaziAutomata.get(key).split(",")[j]);
                        }
                    }
                }
            }
            if((!izbaciPonavljanje.isEmpty()) && (izbaciPonavljanje.contains("#"))){
                izbaciPonavljanje.remove("#");
            }
            if(izbaciPonavljanje.isEmpty()){
                return "#";
            }
            for(int i=0;i<izbaciPonavljanje.size();i++){
                sljedeceStanje+=izbaciPonavljanje.toArray()[i];
                if(i<izbaciPonavljanje.size()-1){
                    sljedeceStanje+=",";
                }
            }
            return sljedeceStanje;
        }
        for(String key:prijelaziAutomata.keySet()){
            String jedan,dva;
            jedan=key.split(",")[0];
            dva=key.split(",")[1];
            if((jedan.equals(stanje)) && (dva.equals(ulazniZnak))){
                sljedeceStanje=prijelaziAutomata.get(key);
                return sljedeceStanje;
            }
            if(prijelaziAutomata.get(key)=="#"){
                //nesta bi trebalo se napravit tu sigurno cim je prazno stanje
                //mozda ovo
                sljedeceStanje="#";
            }
        }
        if(sljedeceStanje.isEmpty()){
            sljedeceStanje="#";
        }
        return sljedeceStanje;
    }

    public static void ispisSvihStanja(ArrayList<String> trenutnaStanja){
        String ispis=new String();
        for(int i=0;i<trenutnaStanja.size();i++){
            ispis+=trenutnaStanja.get(i)+'|';
        }
        ispis=ispis.substring(0,ispis.length()-1);
        System.out.println(ispis);
        return;
        //OVO JE OKEJ SIGURNO
    }
    public static void main(String args[]) throws IOException{
        SimEnka automat = new SimEnka();
        automat.CitanjeAutomata();
        automat.izracunAutomata();
    }
}
