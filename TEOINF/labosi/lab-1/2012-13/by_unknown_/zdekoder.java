import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class zdekoder {

	public zdekoder() {
		// TODO Auto-generated constructor stub
	}

	/**
	 * @param args
	 */
    public static void main(String[] args)
            throws IOException, IllegalArgumentException
    {
        if (args.length != 2) {
            throw new IllegalArgumentException ("UPORABA: java zdekoder putanja_do_ulaza/kanalOut.txt "
                    + "putanja_do_izlaza/zdekoderOut.txt");
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
        //Sklopovi za detektiranje pogreška
            Integer q6;
            Integer q5;
            Integer q4;
            Integer q3;
            Integer q2;
            Integer q1;
            Integer q0;
        //Lista za spremanje kodiranih/izlaznih znakova
            List<Integer> kodiraniZnakovi = new ArrayList<Integer>();
        //Kodiranje po 4 znaka
            for (int i = 0; i < ulazniZnakovi.size(); i+=7)
            {
                //Inicijalizacija
                    R3 = ulazniZnakovi.get(i);
                    R2 = ulazniZnakovi.get(i+1);
                    R1 = ulazniZnakovi.get(i+2);
                    d  = ulazniZnakovi.get(i+3);

                //Postoji 7 iteracija dekodiranja (raèunanja ostatka dijeljenja)
                for (int j = 0; j < 7; j++) {
                    //Uzimanje iz prethodne iteracije
                        tempR3 = R3;
                        tempR2 = R2;
                        tempR1 = R1;
                    //Kodiranje
                        R3 = tempR2 ^ (tempR3 * g2);
                        R2 = tempR1 ^ (tempR3 * g1);
                        R1 = d      ^ (tempR3 * g0);

                    //Ulazni bit
                    if (j < 3) {
                        d = ulazniZnakovi.get(i + 3 + j + 1);
                    } else {
                    //Zadano su zadnja 3 ulazna bita 0
                        d = 0;
                    }
                }

                //Sklopovi za izraèun pogreške
                    q6 = R3     * (1-R2) * (1-R1);
                    q5 = (1-R3) * R2     * (1-R1);
                    q4 = (1-R3) * (1-R2) * R1;
                    q3 = R3     * (1-R2) * R1;
                    q2 = R3     * R2     * R1;
                    q1 = R3     * R2     * (1-R1);
                    q0 = (1-R3) * R2     * R1;

                //Ako je greška na podatkovnim bitovima onda ispraviti i poslati na izlaz
                if (q6 == 1) {
                    kodiraniZnakovi.add(1-ulazniZnakovi.get(i));
                } else {
                    kodiraniZnakovi.add(ulazniZnakovi.get(i));
                }
                if (q5 == 1) {
                    kodiraniZnakovi.add(1-ulazniZnakovi.get(i+1));
                } else {
                    kodiraniZnakovi.add(ulazniZnakovi.get(i+1));
                }
                if (q4 == 1) {
                    kodiraniZnakovi.add(1-ulazniZnakovi.get(i+2));
                } else {
                    kodiraniZnakovi.add(ulazniZnakovi.get(i+2));
                }
                if (q3 == 1) {
                    kodiraniZnakovi.add(1-ulazniZnakovi.get(i+3));
                } else {
                    kodiraniZnakovi.add(ulazniZnakovi.get(i+3));
                }
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