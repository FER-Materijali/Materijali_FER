#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct perceptron{    
       float w0, w1, w2, w3;
       int izlaz;       
}perceptron;

struct uzorak{ 
       float x0, x1, x2, x3;
       int y;
};
struct uzorak primjer[8]; 

float eta = 0.02; 

void ucitaj_dat(){   
	 FILE *f; 
     char niz[100]; 
     float a, b, c,d ;
     int i; 
             
     strcpy(niz, "ui_lab_zad3-1_primjer1.txt"); //"ui_lab_zad3-1_primjer2.txt"
     f = fopen(niz, "r");
     
     fscanf(f, "%[^\n]s", niz);
     for (i = 0; i < 8; i++){
              fscanf(f, "%f %f %f %f %[^\n]s", &a, &b, &c, &d, niz);
              primjer[i].x0 = 1;
              primjer[i].x1 = a;
              primjer[i].x2 = b;
              primjer[i].x3 = c;
              primjer[i].y = (int)d; 
              
     }
}

int racunaj_izlaz(struct uzorak ulaz){ 
       float izlaz; 
       
       izlaz = ulaz.x0 * perceptron.w0 + ulaz.x1 * perceptron.w1 + ulaz.x2 * perceptron.w2 + ulaz.x3 * perceptron.w3;
       
       if (izlaz >= 0) return 1;
       else return -1;
}

float korekcija(float wx, float xx, int yx, int izlazx){
      float w, epsilon;
	  epsilon= yx-izlazx;
      w = wx + eta*epsilon* xx;
      return w;
}

void main(){
	struct uzorak unos; 
    int br_iter, izlaz_unos; 
    int greska = 8; 
    int br_pr = 0; //trenutni broj primjera koji se ispituje
   
	perceptron.w0 = 1;
    perceptron.w1 = 1;
    perceptron.w2 = 1;
    perceptron.w3 = 1;

    ucitaj_dat();
        
    printf("\nUnesite broj iteracija  ");
    scanf("%d", &br_iter);
    
    br_iter = br_iter * 8;
    
    while(br_iter > 0 && greska != 0){
                      
     perceptron.izlaz = racunaj_izlaz(primjer[br_pr]);
                      
     if(primjer[br_pr].y != perceptron.izlaz){
		 perceptron.w0 = korekcija(perceptron.w0, primjer[br_pr].x0, primjer[br_pr].y, perceptron.izlaz);
         perceptron.w1 = korekcija(perceptron.w1, primjer[br_pr].x1, primjer[br_pr].y, perceptron.izlaz);
         perceptron.w2 = korekcija(perceptron.w2, primjer[br_pr].x2, primjer[br_pr].y, perceptron.izlaz);
         perceptron.w3 = korekcija(perceptron.w3, primjer[br_pr].x3, primjer[br_pr].y, perceptron.izlaz);
        
		 greska = 8;
         }
         
	     else greska--; 
         br_iter--;
                   
                      
          printf("\n %f %f %f %f", perceptron.w0, perceptron.w1, perceptron.w2, perceptron.w3);
          printf("\n %f %f %f ", primjer[br_pr].x1, primjer[br_pr].x2, primjer[br_pr].x3);
          printf("\n %d %d ", perceptron.izlaz, primjer[br_pr].y);
          printf("\n\n");
                      
          br_pr = (br_pr + 1) % 8;                       
    }
       
   
    do{
		printf("\n Unesite primjer: ");
		   
             unos.x0 = 1;
			 scanf("%f, %f, %f, %f", &unos.x1, &unos.x2, &unos.x3);
                          
             izlaz_unos = racunaj_izlaz(unos);
             printf("Izlaz: %d\n",izlaz_unos);
       
        getchar();
    }while(1);
    
    system("pause");
              
}
  
