
package hr.fer.oop.lab2.prob6;


public class Shapes {
    public static void main(String[] args){
        plusCrtaPlus();
        premaGoreIDolje("gore");
        premaGoreIDolje("dolje");
        plusCrtaPlus();
        premaGoreIDolje("dolje");
        premaGoreIDolje("gore");
        premaGoreIDolje("gore");
        plusCrtaPlus();
        premaGoreIDolje("dolje");
        plusCrtaPlus();
    }
        
    public static void plusCrtaPlus(){
        System.out.println("+----------+");
    }
    public static void premaGoreIDolje(String smjer){
       if(smjer.compareTo("gore") == 0){
           System.out.println("\\         /");
           System.out.println(" \\_______/");
       }
           else{
                   System.out.println("  _______ ");
                   System.out.println(" /       \\");
                   System.out.println("/         \\");
                   }
            } 
        }   
