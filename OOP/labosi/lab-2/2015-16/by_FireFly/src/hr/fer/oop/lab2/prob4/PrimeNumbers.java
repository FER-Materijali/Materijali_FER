
package hr.fer.oop.lab2.prob4;
import java.util.Scanner;

public class PrimeNumbers {
    public static void main(String[] args){
        int n;
        int check = 1;
        int num = 3;
        
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        System.out.println("You requested calculation of first " + n + " prime numbers. Here they are:");
        System.out.println(2);
        //Pretpostavljamo da je 2 prvi prost..check=1, num=3;
        //u "n" upisujemo zeljeni broj prostih brojeva
        for(int i=2; i<=n;){
            for(int j=2; j<=Math.sqrt(num); j++){
                if(num % j == 0){
                    check = 0;
                    break;
                }
            }
            if(check != 0){
                System.out.println(num);
                i++;
            }
            check = 1;
            num++;
        }
        
    }
}