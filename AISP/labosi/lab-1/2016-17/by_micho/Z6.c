#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

char *ostaviSlova(char *niz)
{
	char *nniz;
	short velicina = 1, i;											//short radi prezervacije memorije, "i" i "velicina" su mali.
																	//Velicina je 1 jer pretpostavnjam da prazan string ima barem mjesta za /0 na kraju.
	for(i = 0; niz[i] != 0; i++)									//Prvo moram proci po cijelom nizu da vidim koliko ima slova.
	{
		if((tolower(niz[i]) >= 'a') && (tolower(niz[i]) <= 'z'))	//Sve cu prividno promijeniti u mala slova, da nemam puno uvjeta.
		velicina++;
	}
	
	nniz = (char*)malloc(velicina * sizeof(char));					//Sada cu alocirati memorije za novi niz koji ima onoliko mjesta koliko je slova u niz-u (argumentu)
	
	for(i = 0; niz[i] != 0; i++)									//Idemo opet po niz-u, prepisivat cemo vrijednosti koje su slova.
	{
		if((tolower(niz[i]) >= 'a') && (tolower(niz[i]) <= 'z'))
		*(nniz++) = niz[i];											//Za svaki prijepis, niz se automatski pomice na sljedece mjesto
	}
	
	*nniz = 0;														//Nasa petlja jos nije zapisala /0 na kraj niza.
	
	return (nniz - velicina + 1);									//Pomicali smo pokazivac, pa ga moramo vratiti na pocetak. Plus 1 jer velicina ukljucuje i /0 kao znak.
}

void spc(int x)
{
     while(x--)
     printf("\n");
}

int main()
{
	char niz[] = "asp12_i_ASP13";									//Neki ucitani string.
	char *pniz = &niz[0];											//definiramo pokazivac na taj string.
	
	printf("%s", ostaviSlova(niz));									//Printam string koji se nalazi na adresi novonastalog, sredjenog stringa.
	
    spc(2);
    system("pause");
    return 0;
}


