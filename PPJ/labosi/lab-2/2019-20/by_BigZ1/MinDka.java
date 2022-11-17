import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;


public class MinDka {
    private static String[] stanjaAutomata;
    private static String[] abecedaUlaza;
    private static String[] prihvatljivaStanja;
    private static String pocetnoStanje;
    private static String citanje = new String();
    private static HashMap <String,String> prijelaziAutomata = new HashMap<>();

    private static HashMap <String,String> prijelaziAutomataBezNedohvatljivih = new HashMap<>();
    private static TreeSet<String> dohvatljivaStanja = new TreeSet<>();
    private static List<String> stanjaAutomataZaMinimizaciju = new ArrayList<String>();
    private static List<String> RIJESIPRVOfunkciju = new ArrayList<>();
    private static TreeSet<String> prihvatljivaStanjaBezNeodhvatljivih = new TreeSet<>();

    private static TreeSet<String> KonacniPrijelaziAutomata = new TreeSet<>();
    private static TreeSet<String> KonacnaprihvatljivaStanja = new TreeSet<>();
    private static HashSet<String> KonacnaStanjaAutomata = new HashSet<>();
    private static List<String> istovjetnaStanja = new ArrayList<String>();

    public static void citanjeAutomata() throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
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
        minimizacijaAutomata();
    }

    public static void minimizacijaAutomata(){
        dohvatljivaStanja=dohvatljivaStanjaAutomata();
        //tu cemo ono sto smo dobili staviti cemo ostavit u nasoj mapi prijelazi automata,a ako ne postoji
        //to stanje u vracenom setu onda cemo sve te kljuceve i te vrijednosti maknuti
        String Dohvatljivi= new String();
        TreeSet<String> dohvatljiviBezDuplikata = new TreeSet<>();
        for(String prihvatljivo: prijelaziAutomata.keySet()){
            if(dohvatljivaStanja.contains(prihvatljivo.split(",")[0])){
                String key = prihvatljivo;
                String value = prijelaziAutomata.get(prihvatljivo);
                prijelaziAutomataBezNedohvatljivih.put(key,value);
                dohvatljiviBezDuplikata.add(prihvatljivo.split(",")[0]);
            }
        }
        for(int i=0;i<dohvatljiviBezDuplikata.size();i++) {
            if (i < dohvatljiviBezDuplikata.size() - 1) {
                Dohvatljivi += dohvatljiviBezDuplikata.toArray()[i] + ",";
            }
            else {
                Dohvatljivi+=dohvatljiviBezDuplikata.toArray()[i];
            }
        }
        for(int i=0;i<dohvatljiviBezDuplikata.size();i++) {
            for (int j = 0; j < prihvatljivaStanja.length; j++) {
                if (prihvatljivaStanja[j].equals(dohvatljiviBezDuplikata.toArray()[i])) {
                    prihvatljivaStanjaBezNeodhvatljivih.add(prihvatljivaStanja[j]);
                }
            }
        }
        String prviDio = new String();
        for(int i=0;i<prihvatljivaStanjaBezNeodhvatljivih.size();i++){
            if(i<prihvatljivaStanjaBezNeodhvatljivih.size()-1){
                prviDio+=prihvatljivaStanjaBezNeodhvatljivih.toArray()[i]+",";
            }
            else {
                prviDio+=prihvatljivaStanjaBezNeodhvatljivih.toArray()[i];
            }
        }
        stanjaAutomataZaMinimizaciju.add(prviDio);
        TreeSet<String> drugiDio = new TreeSet<>();
        for(int i=0;i<dohvatljiviBezDuplikata.size();i++) {
                if (!prihvatljivaStanjaBezNeodhvatljivih.contains(dohvatljiviBezDuplikata.toArray()[i])) {
                    drugiDio.add(dohvatljiviBezDuplikata.toArray()[i].toString());
                }
        }
        String DrugiSkup=new String();
        for(int i=0;i<drugiDio.size();i++){
            if(i<drugiDio.size()-1){
                DrugiSkup+=drugiDio.toArray()[i] + ",";
            }
            else {
                DrugiSkup += drugiDio.toArray()[i];
            }
        }
        stanjaAutomataZaMinimizaciju.add(DrugiSkup);
        String tmp,tmp2 = new String();
        tmp=stanjaAutomataZaMinimizaciju.get(0);
        tmp2=stanjaAutomataZaMinimizaciju.get(1);
        stanjaAutomataZaMinimizaciju.clear();
        stanjaAutomataZaMinimizaciju.add(tmp2);
        stanjaAutomataZaMinimizaciju.add(tmp);
        RIJESIPRVOfunkciju=poTreciPut(stanjaAutomataZaMinimizaciju);
        //jos koda za izbacivanje sad tih full nebitnih djelova
        TreeSet<String> tmpTree = new TreeSet<>();
        for(int i=0;i<RIJESIPRVOfunkciju.size();i++){
            if(RIJESIPRVOfunkciju.get(i).split(",").length>1){
                for(int j=0;j<RIJESIPRVOfunkciju.get(i).split(",").length;j++){
                    tmpTree.add(RIJESIPRVOfunkciju.get(i).split(",")[j]);
                    KonacnaStanjaAutomata.add(RIJESIPRVOfunkciju.get(i).split(",")[j]);
                }
            }else {
                if(RIJESIPRVOfunkciju.get(i).equals("")){
                    continue;
                }else {
                    tmpTree.add(RIJESIPRVOfunkciju.get(i));
                    KonacnaStanjaAutomata.add(RIJESIPRVOfunkciju.get(i));
                }
            }
        }
        for(String prihvatljivo: prijelaziAutomata.keySet()){
            if(tmpTree.contains(prihvatljivo.split(",")[0])){
                String key = prihvatljivo;
                String value = prijelaziAutomata.get(prihvatljivo);
                if(KonacnaStanjaAutomata.contains(value)){
                    KonacniPrijelaziAutomata.add(key+"->"+value);
                }else{
                    //e sad sta ces ako ne postoji to stanje
                    if(KonacnaStanjaAutomata.size()==1){
                        KonacniPrijelaziAutomata.add(key+"->"+KonacnaStanjaAutomata.toArray()[0].toString());
                    }else if(true){
                        for(String skup:stanjaAutomataZaMinimizaciju){
                            for(int i=0;i<skup.split(",").length;i++){
                                if(value.equals(skup.split(",")[i])) {
                                    //onda naci njegovo istovjetno stanje
                                    for(int k=0;k<istovjetnaStanja.size();k++) {
                                        for (int j = 0; j < istovjetnaStanja.get(k).split(",").length; j++) {
                                            if (value.equals(istovjetnaStanja.get(k).split(",")[j])) {
                                                value = RIJESIPRVOfunkciju.get(k).split(",")[0];
                                                KonacniPrijelaziAutomata.add(key + "->" + value);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for(int i=0;i<prihvatljivaStanja.length;i++){
            if(tmpTree.contains(prihvatljivaStanja[i])){
                KonacnaprihvatljivaStanja.add(prihvatljivaStanja[i]);
            }
        }
        //OVDJE MORAS POPRAVIT TEST 11 I 12 i 13 i 14  SA SRANJEM KOJEG IZBACI VEZNAOG ZA ISPIS JER STANJA KOJA JE PRIJE ISAO VISE NE POSTOJE PA TO POPRAVI I GOTOV SI
        ispisAutomata();
    }

    public static TreeSet<String> dohvatljivaStanjaAutomata(){
        TreeSet<String> vrati = new TreeSet<>();
        //pocetno je uvijek dohvatljivo
        Deque<String> stanja = new ArrayDeque<>();
        stanja.push(pocetnoStanje);
        vrati.add(pocetnoStanje);
        while(!stanja.isEmpty()) {
            String trenutnoStanje = stanja.pop();
            for (String stanje_Prijelaz : prijelaziAutomata.keySet()) {
                if (trenutnoStanje.equals(stanje_Prijelaz.split(",")[0])) {
                    for (int i = 0; i < abecedaUlaza.length; i++) {
                        String prijelaz = izracunPrijelaza(trenutnoStanje, abecedaUlaza[i]);
                        //ne mora nuzno bit abeceda ulaza moze bit i samo split,ali [1] svejedno je realno
                        if (!prijelaz.equals("#")) {
                            if (!vrati.contains(prijelaz)) {
                                stanja.push(prijelaz);
                                vrati.add(prijelaz);
                            }
                        }
                    }
                }
            }
        }
        return vrati;
    }
    //VALJA F_JA
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
    //VALJA F_JA
    public static List<String> poTreciPut(List<String> skupovi){
        //mozda napravit klasu ili slicno za setove te sugave
        List<String> vrati = new ArrayList<>();
        for(String set:skupovi){
            if(set.split(",").length>1) {
                for (int i = 0; i < set.split(",").length; i++) {
                    //nisam jos siguran jel ovaj string ce dati dobar output kakav zelim
                    String slucajViseStanjaEkvivalencije = new String();
                    String grupa2 = new String();
                    String soloStanje = set.split(",")[i];
                    for (int j = i + 1; j < set.split(",").length; j++) {
                        String s1 = set.split(",")[i];
                        String s2 = set.split(",")[j];
                        if (provjeraStanjaUnutarSeta(skupovi, s1, s2)) {
                            //dodaj if
                            if(slucajViseStanjaEkvivalencije.split(",").length>1){
                                slucajViseStanjaEkvivalencije+=",";
                            }
                            if(StringSkupaSadrziStanje(slucajViseStanjaEkvivalencije,s1)){
                                if(StringSkupaSadrziStanje(slucajViseStanjaEkvivalencije,s2)==false) {
                                    slucajViseStanjaEkvivalencije += s2;
                                }
                            }
                            else {
                                slucajViseStanjaEkvivalencije += s1 + ",";
                                slucajViseStanjaEkvivalencije += s2;
                            }
                        } else {
                            //znacilo bi da drugo stanje ne pripada to setu
                            //String nisuEkivalenti = new String();
                            //nisuEkivalenti += s2;
                            if(!vecPostojiUnutarRjesenja(vrati,s2) && set.split(",").length==2){
                                vrati.add(set);
                            }
                            else if (!vecPostojiUnutarRjesenja(vrati,s2)){
                                //TU JE PROBLEM
                                grupa2+=s2+",";
                            }
                        }

                    }
                    if(!slucajViseStanjaEkvivalencije.equals("")){
                        if(!vecPostojiUnutarRjesenja(vrati,slucajViseStanjaEkvivalencije)){
                            vrati.add(slucajViseStanjaEkvivalencije);
                        }
                    }
                    if(slucajViseStanjaEkvivalencije.equals("")){
                        if(soloStanje.length()>1){
                            if(!vecPostojiUnutarRjesenja(vrati,soloStanje)) {
                                vrati.add(soloStanje);
                            }
                        }
                    }
                    if(!grupa2.equals("")){
                        String tmp=new String();
                        for(int k=0;k<grupa2.split(",").length;k++){
                            if(k<grupa2.split(",").length-1){
                                tmp+=grupa2.split(",")[k]+",";
                            }
                            else{
                                tmp+=grupa2.split(",")[k];
                            }
                        }
                        vrati.add(tmp);
                    }
                }
            }
            else {
                vrati.add(set);
            }
        }
        if(vrati.size()==skupovi.size()){
            List<String> tmp = new ArrayList<>();
            istovjetnaStanja=vrati;
            for(String konacnaProvjera : vrati){
                if(konacnaProvjera.split(",").length>1){
                    if(provjeraStanjaUnutarSeta(vrati,konacnaProvjera.split(",")[0],konacnaProvjera.split(",")[1])){
                        tmp.add(konacnaProvjera.split(",")[0]);
                        if(konacnaProvjera.split(",")[1].equals(pocetnoStanje)){
                            pocetnoStanje=konacnaProvjera.split(",")[0];
                        }
                    }else{
                        tmp.add(konacnaProvjera);
                    }
                }else{
                    tmp.add(konacnaProvjera);
                }
            }
            return tmp;
        }
        return poTreciPut(vrati);
    }
    //ova FJA VALJA,NO BITI CE JOS TESITIRANA
    public static boolean provjeraStanjaUnutarSeta(List<String> setovi,String s1,String s2){
        List<String> prijelazi= new ArrayList<>();
        for(int i=0;i<abecedaUlaza.length;i++){
            prijelazi.add(izracunPrijelaza(s1,abecedaUlaza[i]));
            prijelazi.add(izracunPrijelaza(s2,abecedaUlaza[i]));
        }
        // TU JE PROBLEM TO RIJESI
        int tmp=0;
        TreeSet<Boolean> provjeraIstovjetnosti = new TreeSet<Boolean>();
        boolean konacnaProvjera = false;
        //okej sad imas listu i na neparnim mjestima su od s2 a na parnima s1 prijelazi
        String p1 = new String();
        String p2 = new String();
        for(int i=0;i<prijelazi.size();i++){
            if(i%2==0){
                p1+=prijelazi.get(i)+",";
            }
            else{
                p2+=prijelazi.get(i)+",";
            }
        }

        for(String set:setovi){
            if(set.split(",").length>1){
                //pravim set za laksu provjeru stanja gdje idu
                TreeSet<String> setStanja = new TreeSet<>();
                for(int i=0;i<set.split(",").length;i++){
                    setStanja.add(set.split(",")[i]);
                }
                //vidit cemo hoce li ovo jest govna zbog zareza
                for(int i=0;i<abecedaUlaza.length;i++){
                    if(setStanja.contains(p1.split(",")[i]) && setStanja.contains(p2.split(",")[i])){
                        provjeraIstovjetnosti.add(true);
                    }
                }
            }
            else continue;
        }
        if(provjeraIstovjetnosti.contains(true)){
            konacnaProvjera=true;
        }
        return konacnaProvjera;
    }

    public static boolean vecPostojiUnutarRjesenja(List<String> rjesenje,String stanja){
        boolean postoji = false;
        for(String skup:rjesenje){
            TreeSet<String> skupUSetu = new TreeSet<>();
            for(int i=0;i<skup.split(",").length;i++){
                skupUSetu.add(skup.split(",")[i]);
            }
            if(stanja.length()==1){
                if(skupUSetu.contains(stanja)){
                    return true;
                }
            }
            else {
                for (int i = 0; i < stanja.split(",").length; i++) {
                    if (skupUSetu.contains(stanja.split(",")[i])) {
                        return true;
                    }
                }
            }
        }
        return postoji;
    }

    public static boolean StringSkupaSadrziStanje(String skup,String stanje){
        boolean provjera=false;
        for(int i=0;i<skup.split(",").length;i++){
            if(skup.split(",")[i].equals(stanje)){
                return true;
            }
        }
        return provjera;
    }
    public static void ispisAutomata(){
        String ispisAutomataa= new String();
        int k=0;
        for(String ispis:KonacnaStanjaAutomata){
            if(k<KonacnaStanjaAutomata.size()-1){
                ispisAutomataa+=ispis+",";
                k++;
            }else {
                ispisAutomataa += ispis;
            }
        }
        System.out.println(ispisAutomataa);
        for(int i=0;i<abecedaUlaza.length;i++){
            if(i<abecedaUlaza.length-1){
                System.out.print(abecedaUlaza[i]+",");
            }else {
                System.out.println(abecedaUlaza[i]);
            }
        }
        for(int i=0;i<KonacnaprihvatljivaStanja.size();i++){
            if(i<KonacnaprihvatljivaStanja.size()-1){
                System.out.print(KonacnaprihvatljivaStanja.toArray()[i]+",");
            }else {
                System.out.println(KonacnaprihvatljivaStanja.toArray()[i]);
            }
        }
        if(KonacnaprihvatljivaStanja.size()==0){
            System.out.println();
        }
        System.out.println(pocetnoStanje);

        for(int i=0;i<KonacniPrijelaziAutomata.size();i++){
            System.out.println(KonacniPrijelaziAutomata.toArray()[i].toString());
        }
        return;
    }
    public static void main(String args[]) throws IOException{
        MinDka automat = new MinDka();
        MinDka.citanjeAutomata();
    }
}
