import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.*;

public class zkoder {

	public zkoder() {
		// TODO Auto-generated constructor stub
	}

	/**
	 * @param args
	 */
	public static void main(String[] args)
    throws IOException, IllegalArgumentException
    {
        if (args.length != 2) {
            throw new IllegalArgumentException ("UPORABA: java zkoder putanja_do_ulaza/ekoderOut.txt "
                                                    + "putanja_do_izlaza/zkoderOut.txt");
        }

        //Uèitavanje iz datoteke zadane parametrom
            File f = new File(args[0]);
            Scanner input = new Scanner( f );
            input.useDelimiter("");
        //Lista za spremanje znakova iz datoteke
            List<Integer> ulazniZnakovi = new ArrayList<Integer>();
        //Èitanje i spremanje svakog znaka u ArrayList
            char znak;
            while (input.hasNext()) {
                znak = input.next().charAt(0);
                if (znak == '0') {
                    ulazniZnakovi.add(0);
                } else {
                    ulazniZnakovi.add(1);
                }
            }
        //Zatvaranje scannera
            input.close();
        //Dodavanje nula ukoliko niz nije djeljiv s 4
            int nedostaje = ulazniZnakovi.size() % 4;
            for (int i = 0; i < nedostaje; i++) {
                ulazniZnakovi.add(0);
            }
        //Generirajuæi polinom za ciklièki kod [7,4]
            Integer g3 = 1;
            Integer g2 = 0;
            Integer g1 = 1;
            Integer g0 = 1;
        //Registri sklopa
            Integer R3;
            Integer R2;
            Integer R1;
            Integer tempR3;
            Integer tempR2;
            Integer tempR1;
        //Ulazni bit
            Integer d;
        //Lista za spremanje kodiranih/izlaznih znakova
            List<Integer> kodiraniZnakovi = new ArrayList<Integer>();
        //Kodiranje po 4 znaka
            for (int i = 0; i < ulazniZnakovi.size(); i+=4)
            {
            //Inicijalizacija
                R3 = ulazniZnakovi.get(i);
                R2 = ulazniZnakovi.get(i+1);
                R1 = ulazniZnakovi.get(i+2);
                d  = ulazniZnakovi.get(i+3);
            //Spremanje podatkovnih bitova u izlazni niz
                kodiraniZnakovi.add(R3);
                kodiraniZnakovi.add(R2);
                kodiraniZnakovi.add(R1);
                kodiraniZnakovi.add(d);
            //Postoje 4 iteracije kodiranja (raèunanja ostatka dijeljenja)
                for (int j = 0; j < 4; j++) {
                //Uzimanje iz prethodne iteracije
                    tempR3 = R3;
                    tempR2 = R2;
                    tempR1 = R1;
                //Kodiranje
                    R3 = tempR2 ^ (tempR3 * g2);
                    R2 = tempR1 ^ (tempR3 * g1);
                    R1 = d      ^ (tempR3 * g0);
                //Zadano su zaštitni bitovi 0
                    d = 0;
                }
            //Spremanje zaštitnih bitova u izlazni niz
                kodiraniZnakovi.add(R3);
                kodiraniZnakovi.add(R2);
                kodiraniZnakovi.add(R1);
            }

        //Zapisivanje u datoteku zcoderOut.txt - izlazna struja bitova - zadano na args[1]
        {
            FileWriter fstream = new FileWriter(args[1]);
            BufferedWriter out = new BufferedWriter(fstream);
            for (int i = 0; i < kodiraniZnakovi.size(); i++) {
                out.write(kodiraniZnakovi.get(i).toString());
            }
            out.close();
        }
	}

}