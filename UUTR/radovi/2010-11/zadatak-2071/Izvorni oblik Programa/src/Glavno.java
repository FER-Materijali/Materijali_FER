import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;


public class Glavno {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		
		BufferedReader in;
		try {
			in = new BufferedReader(new FileReader("in.txt"));
		    String str;
		    while ((str = in.readLine()) != null) {
				TuringovStroj TS = new TuringovStroj(str);
		    }
		    in.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}


	}

}
