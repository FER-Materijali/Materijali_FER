#include <iostream>
#include <stdio.h>
#include <string.h> //samo za strlen() kod upisa ulaznog niza na traku
#include <ctype.h> //samo za funkciju toupper()
using namespace std;

//definiranje studentovih ulaznih parametara

#define X \\'r\\'
#define Y \\'m\\'
#define U 2
#define V 3

//oznake radi citljivijeg koda... :-)

#define I -1 //krecemo u prebrojavanja inicijala imena
#define P -2 //prezimena
#define K -3 //provjera da li je ostao neki neoznaceni inicijal

struct Ul_Znak{
	char sadrzaj;
	int oznaka; //oznacuje da li smo prebrojali neki inicijal ili ne
	int start; //oznacuje pocetak valjanog niza - na prvom inicijalu koji se pojavi u nizu
	struct Ul_Znak *slij; //pokazivac na slijedeci
	struct Ul_Znak *prij; //na prijasnji
};

class Traka{
public:
	struct Ul_Znak *poc; //pokazivac na pocetak liste, nece se nakon nastanka mijenjati
	struct Ul_Znak *znak; //pokazivac koji ce sluziti za setnju kroz listu

	Traka(); //konstruktor
	~Traka(); //destruktor

	void Upis_ulaznog_niza(char *ulaz, int n);
	void Ispis_stanja_trake(int x);
};

Traka::Traka(){ //inicijalizacija trake, jedna struktura, prazni znak B - prazna traka
	poc = new struct Ul_Znak;
	poc->sadrzaj= \\'B\\';
	poc->oznaka = 0;
	poc->start = 0;
	poc->prij=NULL;
	poc->slij=NULL;
	znak = poc;
}

Traka::~Traka(){
	
	//brisanje strukturu po strukturu
	struct Ul_Znak *temp;
	struct Ul_Znak *zn = poc;

	do
	{
		temp = zn;
		zn = zn->slij;
		delete temp;
	}
	while(zn != NULL);
}

void Traka::Upis_ulaznog_niza(char *ulaz, int n){

	struct Ul_Znak *zn = poc;

	for(int i=0; i < n; i++)
	{
		zn->sadrzaj = ulaz[i];

		zn->slij = new struct Ul_Znak;
		zn->slij->prij = zn;
		zn->slij->slij = NULL;
		zn->slij->sadrzaj = \\'B\\';
		zn->slij->oznaka = 0;
		zn->slij->start= 0;

		zn = zn->slij;
	}
}

void Traka::Ispis_stanja_trake(int x){

	struct Ul_Znak *zn = poc;

	int i = 0;

	do
	{
		//ispis - veliko slovo za onaj znak gdje je glava - ta informacija se prenosi
		//preko int x
		if(i == x)
		{
			cout << (char)toupper(zn->sadrzaj);
			zn = zn->slij;
		}
		else
		{
			cout << zn->sadrzaj;
			zn = zn->slij;
		}
		i++;
	}
	while( zn!=NULL );

	cout << endl;
}

class TS{
public:
	int q,u; //oznake stanja
	class Traka traka;

	TS();

	void delta();
};

TS::TS(){
	//pocetno stanje:
	q=0;
	u=0;
}

void TS::delta(){
	
	int i=0;

	while(1)
	{
		traka.Ispis_stanja_trake(i); //ispis trake prije svakog prijelaza
		cout << endl;

		if( q == 5 || q == 6 ) //stanja u kojim se zaustavlja rad TS
			break;

		//nema puno filozofije opet petlja prati definirane funkcije prijelaza ovisno o
		//stanju u kojem se nalazi i ucitanom znaku te mijenja stanje, traku (sadrzaj) i
		//pomice glavu lijevo ili desno
		switch (q)
		{
		case 0:
			{
				if( traka.znak->sadrzaj == \\'B\\' )
				{
					q = 6;
					traka.znak->sadrzaj = \\'?\\';
					traka.znak = traka.znak->slij;
				}
				else if( traka.znak->sadrzaj == X || traka.znak->sadrzaj == Y )
				{
					q = 1;
					u = I;
					traka.znak->start = 1;
					traka.znak = traka.znak->slij;
					i++;
				}
				else
				{
					traka.znak = traka.znak->slij;
					i++;
				}
				break;
			}
		case 1:
			{
				if( traka.znak->start == 1 )
				{
					if( u == I )
					{
						if( traka.znak->sadrzaj == X )
						{
							if( traka.znak->oznaka == 0 )
							{
								q = 2;
								u = U-2;
								traka.znak->oznaka = 1;
								traka.znak = traka.znak->slij;
								i++;
							}
							else if( traka.znak->oznaka == 1 )
							{
								q = 2;
								u = U-1;
								traka.znak = traka.znak->slij;
								i++;
							}
						}
						else
						{
							if( traka.znak->oznaka == 0 )
							{
								q = 2;
								u = U-1;
								traka.znak = traka.znak->slij;
								i++;
							}
							else if( traka.znak->oznaka == 1 )
							{
								q = 2;
								u = U-1;
								traka.znak = traka.znak->slij;
								i++;
							}
						}
					}
					else if( u == P )
					{
						if( traka.znak->sadrzaj == Y && traka.znak->oznaka == 0 )
						{
							q = 3;
							u = V-2;
							traka.znak->oznaka = 1;
							traka.znak = traka.znak->slij;
							i++;
						}
						else
						{
							q = 3;
							u = V-1;
							traka.znak = traka.znak->slij;
							i++;
						}
					}
					else if( u == K )
					{
						q = 4;
						traka.znak = traka.znak->slij;
						i++;
					}
				}
				else if( traka.znak->start == 0)
				{
					traka.znak = traka.znak->prij;
					i--;
				}
				break;
			}
		case 2:
			{
				if( traka.znak->sadrzaj == \\'B\\' )
				{
					q = 6;
					traka.znak->sadrzaj = \\'?\\';
					traka.znak = traka.znak->slij;
					i++;
				}
				else
				{
					if( traka.znak->sadrzaj == X )
					{
						if( u == 0 )
						{
							q = 1;
							u = P;
							traka.znak->oznaka = 1;
							traka.znak = traka.znak->slij;
							i++;
						}
						else
						{
							if( traka.znak->oznaka == 0 )
							{
								q = 2;
								u--;
								traka.znak->oznaka = 1;
								traka.znak = traka.znak->slij;
								i++;
							}
							else if( traka.znak->oznaka == 1 )
							{
								q = 2;
								traka.znak = traka.znak->slij;
								i++;
							}
						}
						
					}
					else
					{
							traka.znak = traka.znak->slij;
							i++;
					}
				}
				break;
			}
		case 3:
			{
				if( traka.znak->sadrzaj == \\'B\\' )
				{
					q = 6;
					traka.znak->sadrzaj = \\'?\\';
					traka.znak = traka.znak->slij;
					i++;
				}
				else
				{
					if( traka.znak->sadrzaj == Y )
					{
						if( u == 0 )
						{
							q = 1;
							u = K;
							traka.znak->oznaka = 1;
							traka.znak = traka.znak->slij;
							i++;
						}
						else
						{
							if( traka.znak->oznaka == 0 )
							{
								q = 3;
								u--;
								traka.znak->oznaka = 1;
								traka.znak = traka.znak->slij;
								i++;
							}
							else if( traka.znak->oznaka == 1 )
							{
								traka.znak = traka.znak->slij;
								i++;
							}
						}
						
					}
					else
					{
							traka.znak = traka.znak->slij;
							i++;
					}
				}
				break;
			}
		case 4:
			{
				if( traka.znak->sadrzaj == \\'B\\' )
				{
					q = 5;
					traka.znak->sadrzaj = \\'!\\';
					traka.znak = traka.znak->slij;
					i++;
				}
				else if( traka.znak->sadrzaj == X || traka.znak->sadrzaj == Y )
				{
					if( traka.znak->oznaka == 0 )
					{
						q = 1;
						u = I;
						traka.znak = traka.znak->slij;
						i--;
					}
					else
					{
						traka.znak = traka.znak->slij;
						i++;
					}
				}
				else
				{
					traka.znak = traka.znak->slij;
					i++;
				}
				
				break;
			}
		default:
			break;
		}
	}
}

int main()
{
	char u[100];

	class TS turing;

	FILE *f;
	f=fopen("ulaz.txt","r");

	fscanf(f,"%s",u);

	//upis ulaznog niza na traku
	turing.traka.Upis_ulaznog_niza(u,strlen(u));
	//pokretanje turingovog stroja
	turing.delta();

	return 0;
}