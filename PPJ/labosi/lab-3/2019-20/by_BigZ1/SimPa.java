/*import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

//PRIMJER 8 TU SAM STAO PROBLEM JE STO MORAS ISPISAT CIJELI STOG NAVODNO A NE SAMO OVO STOGA SMISLI DRUGACIJE RIJESENJE
//MSM DA CES NEKAKO MORAT SMISLITI TO

public class SimPa {
    private static String[] ulazniNizovi;
    private static String[] stanjaAutomata;
    private static String[] abecedaUlaza;
    private static String[] abecedaStoga;
    private static String[] prihvatljivaStanja;
    private static String pocetnoStanje;
    private static String pocetniZnakStoga;
    String citanje = new String();
    private String stog = new String();
    private static HashMap <String,String> prijelaziAutomata = new HashMap<>();
    private int v,m;

    public void CitanjeAutomata() throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        ulazniNizovi=reader.readLine().split("\\|");
        stanjaAutomata=reader.readLine().split(",");
        abecedaUlaza=reader.readLine().split(",");
        abecedaStoga=reader.readLine().split(",");
        prihvatljivaStanja=reader.readLine().split(",");
        pocetnoStanje=reader.readLine();
        pocetniZnakStoga=reader.readLine();
        //mora postojati barem jedan prijelaz pa ce uci u petlju
        while((citanje=reader.readLine())!=null){
            if(citanje.isEmpty()){
                break;
            }
            prijelaziAutomata.put(citanje.split("->")[0],citanje.split("->")[1]);
        }
    }
    public void izracunAutomata(){
        String prijelaz=new String();
        String epsilon=new String();
        ArrayList<String> Izracun = new ArrayList<String>();
        for(String ulaz:ulazniNizovi){
            Izracun.add(pocetnoStanje+"#"+pocetniZnakStoga+"|");
            stog=pocetniZnakStoga;
            String[] ulazniZnakovi = ulaz.split(",");
            boolean prihvatljivo=false;
//v i m mi prate kada je automat pri kraju za svoj ulazni niz pa ga onda pratim dole vidit ces tamo
            v=0;
            m=0;
            for(int i=0;i<ulazniZnakovi.length;i++){
                boolean preso=false;
//ovo mi prati dalije je otisao negdje uopce
                v++;
                m=ulazniZnakovi.length;
                // sad bi ja kao trebao epsilon prijelaze dodat?
                int brojDohvataPrije=Izracun.size();
//znaci za prvo stanje sam izracunao njegovu cijelu okolinu
                epsilon=izracunEpsilona(Izracun.get(brojDohvataPrije-1).split("#")[0]);
                if(!epsilon.isEmpty()){
                    if(epsilon.split("/").length>=1){
                        for(int l=0;l<epsilon.split("/").length;l++){
                            if(!epsilon.split("/")[0].equals("fail")) {
                                Izracun.add(epsilon.split("/")[l] + "|");
                                preso = true;
                            }
                        }
                    }
                    else {
                        if(!epsilon.equals("/")) {
                            String tmp = epsilon.split("/")[0];
                            if (!tmp.equals("fail")) {
                                Izracun.add(tmp + "|");
                                preso = true;
                            }
                        }
                    }
                }
//nakon sto sam cijelu okolinu izracunao uzimam ZADNJI tj stanje
                int brojDohvata=Izracun.size();
//racun prijelaz od tog stanja
                prijelaz=(izracunPrijelaza(Izracun.get(brojDohvata-1).split("#")[0],ulazniZnakovi[i]));
                if (prijelaz.equals("fail") && preso==false){
                    break;
                }
//malo retardiran kod no pokriva neke uvjete poput toga da nema prijelaz a ima okolinu kao epsilon
                else if(prijelaz.equals("fail") && preso==true){
                    int zadnjiDohvatEpsilona = Izracun.size();
                    epsilon = izracunEpsilona(Izracun.get(zadnjiDohvatEpsilona - 1).split("#")[0]);
                    if (!epsilon.isEmpty()) {
                        if (epsilon.split("/").length > 1) {
                            for (int l = 0; l < epsilon.split("/").length; l++) {
                                if (!epsilon.split("/")[0].equals("fail"))
                                    Izracun.add(epsilon.split("/")[l] + "|");
                            }
                        } else {
                            if (!epsilon.equals("/")) {
                                String tmp = epsilon.split("/")[0];
                                if (!tmp.equals("fail"))
                                    Izracun.add(tmp + "|");
                            }
                        }
                    }
                    zadnjiDohvatEpsilona = Izracun.size();
                    prijelaz=(izracunPrijelaza(Izracun.get(zadnjiDohvatEpsilona-1).split("#")[0],ulazniZnakovi[i]));
                    if(!prijelaz.equals("fail")){
                        Izracun.add(prijelaz+"|");
                    }
//retardirani ifovi da se rijesim tih retardiranih uvjeta koje mi ubace a da mi ispis pase
                    if(prijelaz.equals("fail") && stog.equals("$")){
                        Izracun.add("fail");
                    }
                    if(prijelaz.equals("fail") && !stog.equals("$") && !stog.isEmpty() && epsilon.equals("/")){
                        Izracun.add("fail");
                    }
                    if(prijelaz.equals("fail") && epsilon.equals("fail")  && !stog.isEmpty() && !stog.equals("$")){
                        Izracun.add("fail");
                    }
                    //vidi ovo ipak ako bude sralo
                    zadnjiDohvatEpsilona = Izracun.size();
                    for (int k = 0; k < prihvatljivaStanja.length; k++) {
                        //ovjde ovo treba pormijenit
                        if (Izracun.get(zadnjiDohvatEpsilona - 1).split("#")[0].equals(prihvatljivaStanja[k])) {
                            prihvatljivo = true;
                        }
                    }
//onda sam ovdje kao rijesio te gornje ifove sa jos ifova...
                    if(prijelaz.equals("fail") && stog.equals("$")){
                        Izracun.remove(zadnjiDohvatEpsilona-1);
                    }
                    if(prijelaz.equals("fail") && !stog.equals("$") && !stog.isEmpty() && epsilon.equals("/")){
                        Izracun.remove(zadnjiDohvatEpsilona-1);
                    }

                    if(prijelaz.equals("fail") && epsilon.equals("fail") && !stog.isEmpty() && !stog.equals("$")){
                        Izracun.remove(zadnjiDohvatEpsilona-1);
                    }
                }
                else {
                    Izracun.add(prijelaz + "|");
                    if (i == ulazniZnakovi.length - 1) {
                        int zadnjiDohvat = Izracun.size();
                        epsilon = izracunEpsilona(Izracun.get(zadnjiDohvat - 1).split("#")[0]);
                        if (!epsilon.isEmpty()) {
                            if (epsilon.split("/").length > 1) {
                                for (int l = 0; l < epsilon.split("/").length; l++) {
                                    if (!epsilon.split("/")[0].equals("fail"))
                                        Izracun.add(epsilon.split("/")[l] + "|");
                                }
                            } else {
                                if (!epsilon.equals("/")) {
                                    String tmp = epsilon.split("/")[0];
                                    if (!tmp.equals("fail"))
                                        Izracun.add(tmp + "|");
                                }
                            }
                        }
                        zadnjiDohvat = Izracun.size();
                        for (int k = 0; k < prihvatljivaStanja.length; k++) {
                            //ovjde ovo treba pormijenit
                            if (Izracun.get(zadnjiDohvat - 1).split("#")[0].equals(prihvatljivaStanja[k])) {
                                prihvatljivo = true;
                            }
                        }
                    }
                }
            }
//ovo je za kraj da mi ispis bude okej
            if(prihvatljivo==true){
                Izracun.add("1");
            }
            else if(prijelaz.equals("fail")){
                Izracun.add("fail|0");
            }
            else if(prihvatljivo==false){
                Izracun.add("0");
            }
            ispisAutomata(Izracun);
            Izracun.clear();
        }
    }

    public String izracunPrijelaza(String stanje,String ulazniZnak){
        String rezultat = new String();
        String vrhStoga = stog.split("")[0];
        for(String key:prijelaziAutomata.keySet()){
            if(key.split(",")[0].equals(stanje) && key.split(",")[1].equals(ulazniZnak) && key.split(",")[2].equals(vrhStoga)){
                //okej nasao sam ga,micem znak sa vrha stog
                String tmp=prijelaziAutomata.get(key);
                //OVO POSLIJE # OBRISAT JER NA TO CE ICI STOG
                rezultat=tmp.split(",")[0]+"#";
                //hmm vidi hoce li morat i-1 pa onda iterirat takodjer dodajem ih na stog
                if(tmp.split(",")[1].length()>=1){
                        if(!tmp.split(",")[1].equals("$")){
                            vrhStoga=stog.substring(1);
                            //SAMO DODAM NA POSTOJECE ALI MOZDA U NEKOM PRIMJERU NAS MOGU ZAJEBAT AL NE VJERUJEM DA HOCE
                            stog=tmp.split(",")[1];
                            stog+=vrhStoga;
                            break;
                        }
                        else{
                            vrhStoga=stog.substring(1);
                            stog=vrhStoga;
                            if(stog.equals("") && ulazniZnak.equals("$")){
                                stog="$";
                            }
                        }
                }
            }
        }
        //ako se kao nije nasao adekvatni prijelaz onda bude fail
        if(rezultat.isEmpty()){
            rezultat="fail";
            return rezultat;
        }
        return rezultat+stog;
    }
    public String izracunEpsilona(String Epsilonstanje){
        //rekurzivno da se zove samo od sebe
        //MORAS ISTO STVARI NA STOG DODAT ONDA JER ZA EPSILON PRIJELAZ STVARI SE DODAVAJU NA STOG,ALI TO SE OBAVLJA DEBILU GORE U IZRACUN PRIJELAZA
        String vracanjeNazadOkoline = new String();
        String rezultat=new String();
//ovo je red i njega koristim da si ne zovem fju rekurzivno vec ovako u onoj while petlji idem
        Deque<String> okolina = new ArrayDeque<String>();
        boolean nemojvrtit=false;
//ovo da mi ne bude beskonacna petlja ako je moje to stanje prihvatljivo da kao i u NKA ako je doslo tamo automat ga prihvati
        for(int z=0;z<prihvatljivaStanja.length;z++){
            if(prihvatljivaStanja[z].equals(Epsilonstanje)){
                nemojvrtit=true;
            }
        }
//ovaj m i n koje sam ti gore rekao da kad dodjes u to zadnje stanje nakon svih prijelaza ako je prihvatljivo da se ne vrtis bezveze
        if(m==v && nemojvrtit==true){
            return "fail";
        }
        for(String stanje:prijelaziAutomata.keySet()){
            if(stanje.split(",")[0].equals(Epsilonstanje)){
                if(stanje.split(",")[1].equals("$")) {
                    String tmp=izracunPrijelaza( Epsilonstanje,"$");
                    if(!tmp.equals("fail")){
                        vracanjeNazadOkoline+=tmp+"/";
                    }
                }
            }
        }
//izracunao prijelaz epsilon za to stanje jedno i dodat cu ga u red i u listu
        ArrayList<String> OkolinaBezDuplikata =new ArrayList<>();
        for(int z=0;z<vracanjeNazadOkoline.split("/").length;z++) {
            okolina.add(vracanjeNazadOkoline.split("/")[z]);
            OkolinaBezDuplikata.add(vracanjeNazadOkoline.split("/")[z]);
        }

        boolean prihvatljivoPrije=false;
        for(int k=0;k<prihvatljivaStanja.length;k++) {
            //ovjde ovo treba pormijenit
            for(int g=0;g<OkolinaBezDuplikata.size();g++){
                if(OkolinaBezDuplikata.get(g).split("#")[0].equals(prihvatljivaStanja[k])){
                    prihvatljivoPrije=true;
                }
            }
        }
        if(prihvatljivoPrije==true && m==v){
            for(int z=0;z<OkolinaBezDuplikata.size();z++){
                rezultat+=OkolinaBezDuplikata.get(z)+"/";
            }
            return rezultat;
        }
//rekurzivni dio u koje od tog jednog stanja odem u druga stanaj i tako se vrtim i ako ne postoji dodam ga na red i tako u krug
        while(!okolina.isEmpty()){
            String prijelaz=izracunPrijelaza(okolina.pop().split("#")[0],"$");
            if(!prijelaz.equals("fail")){
                boolean prihvatljivo=false;
                for(int k=0;k<prihvatljivaStanja.length;k++) {
                    //ovjde ovo treba pormijenit
                    if (prijelaz.split("#")[0].equals(prihvatljivaStanja[k])) {
                        prihvatljivo = true;
                    }
                }
                if(prihvatljivo==true && m==v){
			//neki dio useless koda nemam pojma sta je ovo realno ostalo je tu
                }
                else {
                    boolean nalaziSe = false;
                    for (int z = 0; z < OkolinaBezDuplikata.size(); z++) {
                        if (OkolinaBezDuplikata.get(z).split("#")[0].equals(prijelaz)) {
                            nalaziSe = true;
                            break;
                        }
                    }
                    if (nalaziSe == false) {
                        OkolinaBezDuplikata.add(prijelaz);
                        okolina.push(prijelaz);
                    }
                }
            }
            else if(prijelaz.equals("fail") && okolina.isEmpty()){
                //HMM OVJDE MOGUCA GRESKA
//nije greska skuzio sam kasnije na primjerima
                break;
            }
        }
        for(int z=0;z<OkolinaBezDuplikata.size();z++){
            rezultat+=OkolinaBezDuplikata.get(z)+"/";
        }
        return rezultat;
    }
//samo fja za ispis
    public void ispisAutomata(ArrayList<String> ispis){
        for(int i=0;i<ispis.size();i++){
            System.out.print(ispis.get(i));
        }
        System.out.println();
        return;
    }

//klasicni main

    /*public static void main(String args[]) throws IOException {
        SimPa automat = new SimPa();
        automat.CitanjeAutomata();
        automat.izracunAutomata();

    }
    */
}
