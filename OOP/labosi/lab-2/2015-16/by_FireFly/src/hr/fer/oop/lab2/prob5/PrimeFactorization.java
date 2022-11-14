
package hr.fer.oop.lab2.prob5;
import java.util.Scanner;

public class PrimeFactorization {
    
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        int broj = scan.nextInt();
        System.out.println("You requested decomposition of number " + broj + " into prime factors. Here they are:");
        double trazi_do = Math.sqrt(broj);
        
        for(int i=2; i<=trazi_do; i++){
            while(broj % i == 0){
                System.out.println(i);
                broj = broj / i;
            }
        }
        if(broj > 1)
            System.out.println(broj);
    }
}
