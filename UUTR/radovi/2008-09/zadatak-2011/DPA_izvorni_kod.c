#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
    char trenutno_stanje[3];
    char ulazni_znak[3];
    char znak_stoga[3];
    char sljedece_stanje[3];
    char sljedeci_znak_stoga[3];
}FjaPrijelaza; /* d(trenutno_stanje,ulazni_znak,znak_stoga)==(sljedece_stanje,sljedeci_znak_stoga) */

typedef struct
{
    int vrh;
    char *polje;
} Stog;

typedef struct
{
    char stanje[3];
    int  prihvacanje_stogom; /*nacin prihvacanja stanja: stog==1 stanje==0*/
    Stog stog;
    char *prihStanja;
    FjaPrijelaza *prijelazi;
    int kolicinaPrijelaza;
}Automat;

void init_stog(Stog *stog)
{
    stog->vrh = -1;
    stog->polje=(char*)malloc(sizeof(char));
}

int dodaj(char stavka, Stog *stog)
{
    stog->vrh++;
    stog->polje = (char*)realloc(stog->polje,(stog->vrh + 1)*sizeof(char));
    if (stog->polje == NULL)
        return 0;
    stog->polje[stog->vrh] = stavka;
    stog->polje[stog->vrh +1 ] = '\0';
    return 1;
}


int skini(char *stavka, Stog *stog)
{
    if (stog->vrh < 0)
	{
		*stavka = '\0';
		return 0;
	}
    *stavka = stog->polje[stog->vrh];
	stog->polje[stog->vrh] = '\0';
    stog->vrh--;
    return 1;
}

void ispis_stoga(Stog *stog)
{
    int i;
    printf ("\nStog:");
    if (stog->vrh == -1)
        printf ("(prazan stog)");
    else
        for (i=0; i <= stog->vrh; ++i)
            printf ("%c", stog->polje[i]);
}

void ucitaj_automat(Automat *automat)
{
    char *prihStanja,tmp;
    FILE *datoteka;
    int i = 0;
    char temp[50]; /*buffer za citenje iz datoteke, za ispitivanje da li se prihvaca stogom*/
    datoteka = fopen("DPA.txt","r");
    if (datoteka == NULL)
    {
        printf("\nDatoteka ne postoji.");
        exit(-1);
    }
    (*automat).prijelazi = (FjaPrijelaza*)malloc(sizeof(FjaPrijelaza));

    init_stog(&(*automat).stog); /*stvori stog*/
    fscanf(datoteka,"%s %s", (*automat).stanje, temp);/*pocetni uvjeti*/
    for (i = 0;i < strlen(temp);i++)/*stavi pocetni znak(ove) na stog*/
    {
        dodaj(*(temp + i),&(*automat).stog);
    }


    fscanf(datoteka,"%s",temp); /*ucitaj nacin prihvacanja stanja*/
    if (strcmp("stog",temp) == 0)
        (*automat).prihvacanje_stogom = 1;
    else if (strcmp("stanje",temp) == 0)
        (*automat).prihvacanje_stogom = 0;
    else
        printf("\nGreska: prihvacanje_stogom");

    prihStanja = (char*)malloc(1*3*sizeof(char));
    getc(datoteka); /*gornji fprintf nije procitao znak kraja linije pa treba pomaknuti pokazivac u datoteci*/
    i = 0;
    do
    {
        fscanf(datoteka,"%c",&tmp);
        if (tmp == 'q')
        {
            prihStanja = (char*)realloc(prihStanja,3*(i + 1)*sizeof(char));
            *(prihStanja + 3*i) = 'q';
            fscanf(datoteka,"%c",prihStanja + 3*i + 1);
            *(prihStanja + 3*i + 2)=' ';
            i++;
        }
    }
    while (tmp != '\n');
    (*automat).prihStanja = prihStanja;

    for (i = 0;feof(datoteka) == 0;i++)/*ucitavanje tablice prijelaza*/
    {
        (*automat).prijelazi = (FjaPrijelaza*)realloc((*automat).prijelazi, (i+1)*sizeof(FjaPrijelaza));
        if (fscanf(datoteka,"%s%s%s%s%s",
                            ((*automat).prijelazi + i)->trenutno_stanje,
                            ((*automat).prijelazi + i)->ulazni_znak,
                            ((*automat).prijelazi + i)->znak_stoga,
                            ((*automat).prijelazi + i)->sljedece_stanje,
                            ((*automat).prijelazi + i)->sljedeci_znak_stoga
                   )!= 5)
            break;
    } (*automat).kolicinaPrijelaza = i;/*prebaci ovaj 'i' u strukturu automat da znas koliko ima prijelaza*/
    fclose(datoteka);
}

void fjaPrijelaza(Automat *automat, char *ulazni_niz)
{
    char znak_stoga;
    char znak_niza;
    char temp;
    int i,j,bioPrijelaz = 1;

    while(bioPrijelaz != 0)
    {
        bioPrijelaz = 0;
        if(skini(&znak_stoga,&(*automat).stog)) /*dohvati prvi znak stoga*/
            dodaj(znak_stoga,&(*automat).stog); /*vrati skinuti znak*/

        if(strlen(ulazni_niz))
        {
            znak_niza = *ulazni_niz;/*dohvati prvi znak ulaznog niza*/
        }
            else
            znak_niza = '|';

        printf("\nUlazni niz:%s\nZnak niza:%c\nZnak stoga:%c\nTrenutno stanje:%s",
               ulazni_niz, znak_niza, znak_stoga, automat->stanje);
        ispis_stoga(&(*automat).stog);

        for(i = 0;i < (*automat).kolicinaPrijelaza;i++) /*dodaj brojac kolicine prijelaza*/
        {
            if (strcmp((*automat).stanje,((*automat).prijelazi + i)->trenutno_stanje) == 0
                &&  (znak_niza == *(((*automat).prijelazi + i)->ulazni_znak)
                    || *(((*automat).prijelazi + i)->ulazni_znak) == '|')
                && znak_stoga == *(((*automat).prijelazi + i)->znak_stoga))
            {
                if(*(((*automat).prijelazi + i)->ulazni_znak) != '|')
                {
                ulazni_niz = ulazni_niz + 1; /*makni procitani ulazni znak*/
                }

                printf("\nPrijelaz: d(%s, %s, %s) ==> d(%s %s)",((*automat).prijelazi + i)->trenutno_stanje,
                                                   ((*automat).prijelazi + i)->ulazni_znak,
                                                   ((*automat).prijelazi + i)->znak_stoga,
                                                   ((*automat).prijelazi + i)->sljedece_stanje,
                                                   ((*automat).prijelazi + i)->sljedeci_znak_stoga);

                strcpy((*automat).stanje,((*automat).prijelazi + i)->sljedece_stanje);
                skini(&temp,&(*automat).stog);
                for(j = strlen(((*automat).prijelazi + i)->sljedeci_znak_stoga) -1;j >= 0 &&
                        ((*automat).prijelazi + i)->sljedeci_znak_stoga[0] != '|';j--)
                {
                    dodaj(((*automat).prijelazi + i)->sljedeci_znak_stoga[j], &(*automat).stog);
                }

                ispis_stoga(&(*automat).stog);
                bioPrijelaz = 1;
                break;
            }
        }
        printf("\n");

    }

   if( strlen(ulazni_niz) == 0 &&
        strstr((*automat).prihStanja, (*automat).stanje) != NULL &&
        automat->prihvacanje_stogom == 0)
    {
            puts("\aNiz se prihvaca");
    }
    else if(strlen(ulazni_niz) == 0 &&
            skini(&temp, &(*automat).stog) == 0 &&
             automat->prihvacanje_stogom == 1)
    {
                puts("\aNiz se prihvaca");
    }
    else
    {
        puts("\aNiz se ne prihvaca");
    }


}

int main()
{
    char *ulazni_niz, tmp;
    int i = 0;

    Automat DPA;
    ucitaj_automat(&DPA);

    ulazni_niz=(char*)malloc(sizeof(char));

    /*ucitaj ulazni niz*/
    puts("Upisi ulazni niz DPA:");
    do
    {
        scanf("%c",&tmp);
        if (tmp != '\n')
        {
            ulazni_niz = (char*)realloc(ulazni_niz, (i + 1)*sizeof(char));
            ulazni_niz[i] = tmp;
            ulazni_niz[++i] = '\0';
        }
    }
    while (tmp != '\n');

    fjaPrijelaza(&DPA, ulazni_niz);

    return 0;
}
