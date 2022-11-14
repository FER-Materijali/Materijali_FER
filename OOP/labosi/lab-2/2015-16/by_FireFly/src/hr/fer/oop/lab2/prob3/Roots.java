
package hr.fer.oop.lab2.prob3;

import java.util.Scanner;

public class Roots {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        double realniDio = sc.nextDouble();
        double imaginarniDio = sc.nextDouble();
        double korijen = sc.nextInt();
    
        // r = sqrt(re^2 + im^2);
        double r = Math.pow( (Math.pow(realniDio,2)+Math.pow(imaginarniDio,2)), 0.5 );
        double kut = Math.atan2(imaginarniDio,realniDio);
        double korijen_iz_r = Math.pow(r, (1/korijen));
   
        System.out.println("You requested calculations of " + korijen + ". roots. Solutions are:");
        for(int i=0; i<korijen; i++){
            System.out.format("%.2f %.2fi %n", korijen_iz_r*(Math.cos((kut + 2*i*Math.PI)/(korijen))), 
                    korijen_iz_r*(Math.sin((kut + 2*i*Math.PI)/(korijen))));
        }
    
    }
}

