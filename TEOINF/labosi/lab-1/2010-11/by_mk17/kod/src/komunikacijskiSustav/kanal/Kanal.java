package komunikacijskiSustav.kanal;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.io.OutputStream;
/**
 * Klasa koja predstavlja komunikaciju izmeğu prijemnika i predajnika.
 * Uzima na ulaz dvije datoteke. Tamo gdje je u drugoj ( err_vec.txt )
 *  bit 1 korespodentni bit u prvoj ( 34.txt ) datoteci promijeni se sa 0 u 1 
 *  odnosno sa 1 u 0.
 *  Generira datoteku 45.txt
 */
public class Kanal {

	/**
	 * @param imena datoteka
	 */
	public static void main(String[] args) {
		try{
			File src = new File(args[0]);//"34.txt"args[0]
			File dst = new File("45.txt");
			InputStream in = new FileInputStream(src);
		    OutputStream out = new FileOutputStream(dst);
		    
		    
		    File errDat = new File(args[1]);//"err_vec.txt"
			InputStream err = new FileInputStream(errDat);
	

			byte[] buf = new byte[1024];
		    byte[] maska = new byte[1024];
    
		    int len;
		    while ((len = in.read(buf)) > 0) {
		        err.read(maska);
		        for (int i = 0; i < 1024; i++){
		        	if ( maska[i]  == 48 ) continue;
		        	else {
		        		if ( buf[i] == 49 )buf[i] = '0';
		        		else buf[i] = '1';
	
		        	}        	
		        }

		    	out.write(buf, 0, len);
		    }
		    
		    
		    
		    
		    in.close();
		    out.close();
		    err.close();

		 }catch(Exception e){
			 System.out.print("Error: " + e.getMessage());
		 }
	}

}

