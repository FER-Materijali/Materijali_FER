package hr.fer.oop.lab2.prob1;

import java.util.Scanner;

public class Rectangle {
    
	public static void main(String[] args){
		double width, height, area, perimiter;
                
                if(args.length > 0 && args.length != 2)
            System.out.println("Invalid number of arguments was provided.");
                
                else if(args.length == 2){
                    width = Double.parseDouble(args[0]);
                    height = Double.parseDouble(args[1]); 
                    
                    perimiter = opseg(width, height);
                    area = povrsina(width, height);
                    ispis(width, height, perimiter, area);
                }
                else{
                        System.out.println("Please provide width:");
                        width=podaci("width");
                        System.out.println("Please provide height:");
                        height=podaci("height");
                       
                        perimiter = opseg(width, height);
                        area = povrsina(width, height);
                        ispis(width, height, perimiter, area);
            }
        }
//---------------------------------------------------------------------------------------------------------
public static double podaci(String component) {
	double broj;
	String unos;
	Scanner scan = new Scanner(System.in);

	while(true) {
		unos = scan.nextLine();
		if(unos.trim().isEmpty()){
			System.out.println("The " + component + "must not be blank.");
             
                } else {
			broj = Double.parseDouble(unos);
			if(broj<=0)
				System.out.println("The " + component + "must not be negative/zero.");
                        else
                            break;
		}
	}
	return broj;
    }
//---------------------------------------------------------------------------------------------------------
public static double opseg(double sirina, double visina){
        return (2*(sirina + visina));
    }
    public static double povrsina(double sirina, double visina){
        return (sirina * visina);
    }
    public static void ispis(double width,double height,double perimiter,double area){
        System.out.printf("You have specified a rectangle of width %.2f and height %.2f."
                        + "Its area is %.2f and its perimiter is %.2f.", width, height, area, perimiter);
    }
}