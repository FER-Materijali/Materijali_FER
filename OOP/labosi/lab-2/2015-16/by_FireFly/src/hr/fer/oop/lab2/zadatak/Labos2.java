
package hr.fer.oop.lab2.zadatak;

/**
 * 
 * @author FireFly
 */
public class Labos2 {
    /**
     * This method is called once the program is run.
      * Arguments are described below
     * @param args Command line arguments
     */
    public static void main(String[] args){
        double zbroj = 0, brojPI;
        
        if(args.length == 0){
            System.out.println("Nije unesen niti jedan argument.");
            return;
        }
        int brojArgumenata = Integer.parseInt(args[0]);
        
        if(brojArgumenata > 1){
            System.out.println("Nije unesen pravi broj argumenata.");
            return;
        }
        int broj = Integer.parseInt(args[0]);
        
        if(broj <= 0){
            System.out.println("Broj mora biti veci od nule");
            return;
        }
        
        for(int i = 1; i <= broj; i++){
            zbroj += 1/(Math.pow(i, 2));
        }
        
        brojPI = Math.sqrt(zbroj*6);
        System.out.println("Broj PI je priblizno jednak " + brojPI +".");
    }
    /**
     * Method which calculates number PI
     * @param zbroj stored value of (PI^2/6)
     * @param n number of sum "members"
     * @param brojPI actual approximation of number PI
     */
}
