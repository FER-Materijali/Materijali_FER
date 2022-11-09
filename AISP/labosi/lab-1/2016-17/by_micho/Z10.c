#include<stdio.h>
#include<stdlib.h>

double f(double z, int k)								//Ova je mozda malo zeznuta za izracunati. Iz dane formule prvo treba izvuci rekurzivnu formulu.
{														//Nacin na koji to radite je takav da raspises osnovni slucaj, te slucaj za k 1 veci od njega. Odmah cete vidjeti kako se izraz mijenja.
	int kk = 2*k + 1;									//kk nam je eksponent z-a i argument faktorijela.
	double faktor = (-z*z) / (kk*(kk-1));				//faktor je ono s cim mnozimo prethodni. Ovisno o k-u, sljedeci broj je trenutni broj pomnozen s ovim faktorom.
	
	if(k == 0)											//Kad je k = 0, cijeli izraz jednak je z.
	return z;
	else
	return faktor * f(z, k-1);							//Za sve ostale, pokusavamo doci do toga kad je k = 0;
	
}

void spc(int x)
{
     while(x--)
     printf("\n");
}

int main()
{
	double z = 0.5;									//Zadatak kaze 0.5, ali ovo radi i za druge realne brojeve. Mozete probati.
	short i;
	
    for(i = 0; i < 11; i++)							//U zadatku pise da treba probati za razlicite k-ove. Ja sam probao sa k element iz [0,10]. Veci k drasticno smanjuje rezultat.
	printf("Za k = %2d, z = %g\n", i, f(z, i));
    
    spc(2);
    system("pause");
    return 0;
}
