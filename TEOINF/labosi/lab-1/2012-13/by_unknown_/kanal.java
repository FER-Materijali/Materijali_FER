import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.*;



public class kanal {

	public kanal() {
		// TODO Auto-generated constructor stub
	}

	/**
	 * @param args
	 */
	public static void main(String[] args)
            throws IOException, IllegalArgumentException
    {



        if (args.length != 2) {
            throw new IllegalArgumentException ("UPORABA: java kanal putanja_do_ulaza/zkoderOut.txt "
                    + "putanja_do_izlaza/kanalOut.txt");
        }


        //Vjerojatnost pojave pogreške 1/2000
            int START = 1;
            int END = 2000;
            Random random = new Random();
            Integer slucajniBroj;

        //Èitanje iz ulazne datoteke zkoderOut.txt zadane sa args[0]
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
        //Iteriranje po svim znakovima i simuliranje pogreške
            for (int i = 0; i < ulazniZnakovi.size(); i++) {
                //ukoliko je RANDOM broj == 1000 onda greška
                //izabran je broj 1000, ali mogao je biti bilo koji
                //drugi prirodni iz intervala [1..2000]
                slucajniBroj = getRandomInteger(START, END, random);
                if (slucajniBroj == 1000) {
                    //Ako je greška napraviti inverziju bita
                    // 1-> 0
                    // 0-> 1
                    ulazniZnakovi.set(i,1-ulazniZnakovi.get(i));
                }
            }

        //Prebacivanje iz Liste u String
            //String kodiraniZnakovi = "";


        //Zapisivanje u datoteku zcoderOut.txt - izlazna struja bitova - zadano na args[1]
        {
            FileWriter fstream = new FileWriter(args[1]);
            BufferedWriter out = new BufferedWriter(fstream);
            for (int i = 0; i < ulazniZnakovi.size(); i++) {
                out.write(ulazniZnakovi.get(i).toString());
            }
            out.close();
        }




	}


    private static int getRandomInteger(int aStart, int aEnd, Random aRandom){
        if ( aStart > aEnd ) {
            throw new IllegalArgumentException("Start cannot exceed End.");
        }
        //get the range, casting to long to avoid overflow problems
        long range = (long)aEnd - (long)aStart + 1;
        // compute a fraction of the range, 0 <= frac < range
        long fraction = (long)(range * aRandom.nextDouble());
        int randomNumber =  (int)(fraction + aStart);

        return randomNumber;
    }

}