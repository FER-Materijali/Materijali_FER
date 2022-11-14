# Prvi dio drugog labosa iz PPI-a
---
**BY: Apeture & DesignatedDriver**

**[ Zadatak 01 ]** S tipkovnice učitati cijeli broj x. Ako učitani broj nije iz zatvorenog intervala [5, 20], tada na zaslon ispisati poruku Neispravan broj i završiti s izvođenjem programa. Ako učitani broj jest iz zatvorenog intervala [5, 20], tada na zaslon ispisati x+1 redaka na sljedeći način:

```c
#include <stdio.h>
int main(void) {
	int broj, i, varijabla;
	scanf("%d", &broj);

	if ((broj > 20) || (broj < 5)) {
		printf("Neispravan broj\n");
		return 0;	
		/*osigurava završetak programa kad je unesen neispravan broj */
	}

	/* u ispisu se traži da se kroz redove jedna varijabla inkrementira	*/

	for (i = 0; i < broj; ++i) {
		varijabla=0;
		while (varijabla <= i) {
			printf("0.%d ", varijabla);
			varijabla++;
		}
		printf("\n");
	}
	return 0;
}
```
**[ Zadatak 02 ]** S tipkovnice učitati niz znakova (string) x koji sigurno neće biti dulji od 60 znakova. Ako je duljina učitanog niza manja od 10, na zaslon ispisati poruku Prekratak niz i završiti s izvođenjem programa. Ako je duljina učitanog niza barem 10, na zaslon ispisati svaki drugi znak učitanog niza, ali samo ako se radi o malom slovu engleske abecede. Svaki znak ispisati u novom retku. Ako je npr. s tipkovnice učitan niz `ab78efghijkl`, na zaslon treba ispisati:
`a`
`e`
`g`
`i`
`k`
```c
#include <stdio.h>
int main (void) {
	/* S tipkovnice učitati niz znakova 
	(string) x koji sigurno neće biti dulji od 60 znakova.

	Znamo sa sigurnošću da nam treba polje od 60 znakova */

	char x[60];
	int len=0, i=0;
	printf("unesite niz\n");
	gets(x);
	/* određivanje duljine niza */
	while (x[len] != '\0') {
		len++;
	}

	if (len < 10) {
		printf("prekratak niz\n");
		return 0;
	}
	/* čitaj od početka pa dok ne dođeš do kraja stringa */
	while (x[i] != '\0') {
		/* ako je znak na parnoj adresi eg niz[0], niz[2]..
		provjeri je li pisano malim slovom, ako ne razumijete ovo
		pogledajte ascii tablicu */
		if ((i%2==0) && (x[i] >= 'a') && (x[i] <= 'z')) 
			printf("%c\n", x[i]);
		/* šetaj dalje */
		i++;
	}
	return 0;
}
```
**[ Zadatak 04 ]** S tipkovnice učitati broj članova cjelobrojnog polja 1 ≤ n ≤ 20 (broj članova polja potrebno je učitavati sve dok se ne unese ispravna vrijednost), a zatim učitati n vrijednosti članova polja. Nakon toga na zaslon ispisati poziciju (indeks člana) i vrijednost za svaki član polja čija je vrijednost iz zatvorenog intervala [10, 20]. Ako su npr. učitani cijeli brojevi:

```c
#include <stdio.h>

int main (void) {
	int n, i;
	int polje[20];
	/*S tipkovnice učitati broj članova cjelobrojnog polja 1 ≤ n ≤ 20 
	(broj članova polja potrebno je
	učitavati sve dok se ne unese ispravna vrijednost) */
	do {
		printf("unesi n: \n");
		scanf("%d", &n);
	} while ((n<1) || (n>20));
	/* ŠABLONA */
	/* učitavanje elemenata polja */
	for ( i = 0; i < n; ++i)
	{
		printf("unesi %d. član: ", i+1);
		scanf ("%d", &polje[i]);
	}
	/* još jednom prošetaj po polju i odradi što se od tebe traži */
	for ( i = 0; i < n; ++i)
	{
		if ((polje[i] >= 10) && (polje[i] <= 20))
		    printf("%2d. %d\n", i, polje[i] );
	}
	return 0;
}
```

**[ Zadatak 05 ]** S tipkovnice pročitati broj članova niza 1 ≤ n ≤ 1000 (broj članova niza potrebno je učitavati sve dok se ne unese ispravna vrijednost), a zatim izračunati broj π pomoću sljedeće parcijalne sume :

```c
#include <stdio.h>
#include <math.h>
int main (void) {
	int n, i;
	double suma=0;
	double razlika;
	do {
		printf("unesi vrijednost članova sume\n");
		scanf ("%d", &n);
	} while ((n<1) || (n>1000));

	for (i = 0; i <=n; ++i) {
		/* česta greška je u razlomak poslati int, rezultat će biti 
		int bez obzira što je suma double, zato sam u brojnik stavio 1.0. 
		pow() osigurava promjenu predznaka  */
		suma += pow(-1, i+1)*(1.0/(2*i-1));
		printf("%f\n", suma);
	}
	suma*=4;
	printf("%f\n", suma);
	razlika=suma-3.141593;
	if (razlika < 0) razlika*=(-1);
	printf("razlika iznosi: %f", razlika);
	return 0;
}
```
**[ Zadatak 06 ]** S tipkovnice učitati broj članova niza 1 ≤ n ≤ 1000 (broj članova niza potrebno je učitavati sve dok se ne unese ispravna vrijednost), a zatim izračunati broj 0.5 pomoću sljedeće parcijalne sume:


```c
#include <stdio.h>

int main (void) {
	double suma=0, razlika;
	int n, i;
	do {
		printf("unesi broj članova\n");
		scanf("%d", &n);
	} while ((n<1) || (n>1000));

	for (i = 1; i <= n; ++i)
	{
		/* opet je u brojniku 1.0 kao u prošlom zadatku */
		suma+= 1.0/((2*i-1)*(2*i+1));
	}
	razlika = suma-0.5;
	if (razlika<0) razlika*=(-1);
	printf("razlika iznosti: %f", razlika);
	return 0;
}
```

**[ Zadatak 08 ]** S tipkovnice učitati niz znakova (string) koji sigurno neće biti dulji od 30 znakova. Ispitati zadovoljava li učitani niz navedene uvjete: niz sadrži barem 7 malih slova engleske abecede, niz sadrži barem dvije znamenke. Te na zaslon ispisuje jednu od poruka: " Ne zadovoljava uvjete", "Zadovoljava uvjete". Npr. za niz znakova "pero21" program ispisuje "Ne zadovoljava uvjete", a za niz "peroPero11" ispisuje " Zadovoljava uvjete".

```c
#include <stdio.h>

int main (void) {
	char string[30];
	int slovo=0, broj=0, i=0;
	printf("unesi string\n");
	gets(string);

	while (string[i] != '\0') {
		if ((string[i] >= 'a') && (string[i] <= 'z')) slovo++;
		if ((string[i] >= '0') && (string[i] <= '9')) broj++;
		i++;
	}
	if ((slovo < 7) || (broj < 2)) printf("Ne zadovoljava uvjete\n");
		else printf("zadovoljava uvjete\n");
	return 0;
}
```
**[ Zadatak 10 ]** S tipkovnice učitati cijeli broj 1 ≤ n ≤ 20 (broj je potrebno učitavati sve dok se ne unese ispravna vrijednost), a zatim učitati n vrijednosti članova cjelobrojnog polja. Nakon učitavanja vrijednosti svih elemenata polja, sve elemente polja čija je vrijednost unutar zatvorenog intervala [-10,10] promijeniti u 0 te ispisati zbroj vrijednosti promijenjenih elemenata. Npr. za učitane članove polja: `-30 -8 311 15 6 0 -1`, program ispisuje:
`Zbroj vrijednosti promijenjenih elemenata: -3`

```c
#include <stdio.h>

int main (void) {
	int n, i, suma=0;
	int polje[20];
	do {
		printf("unesi broj vrijednosti polja\n");
		scanf("%d", &n);
	} while ((n<1) || (n>20));

	for ( i = 0; i < n; ++i) {
		printf("unesi element: ");
		scanf("%d",  &polje[i]);
	/* sumiraj elemente iz zadanog intervala i odmah ih postavljaj na 0 */
		if ((polje[i] > -10) && (polje[i] <= 10)) {
			suma+=polje[i];
			polje[i] = 0;
		}
	}
	printf("Zbroj vrijednosti promijenjenih elemenata: %d\n", suma);

	return 0;

}
```

**[ Zadatak 14 ]** S tipkovnice uzastopno učitavati cijele brojeve iz zatvorenog intervala [1, 30] (pojedini broj je potrebno učitavati sve dok se ne unese ispravna vrijednost). Učitavanje brojeva završiti kada se učita broj koji je već prije bio učitan. Na zaslon ispisati redni broj prvog pojavljivanja tog broja, te ukupan broj učitanih brojeva iz navedenog intervala. Npr. za učitane brojeve: `1 -3 2 4 8 3 4`, na zaslon se ispisuje:
`Broj 4 bio je 3. učitani broj.`
`Ukupno učitano brojeva: 6`

```c
#include <stdio.h>

int main (void) {
	/*S tipkovnice uzastopno učitavati cijele brojeve iz zatvorenog intervala
	[1, 30] (pojedini broj je potrebno učitavati sve dok se ne unese ispravna
	vrijednost). Učitavanje brojeva završiti kada se učita broj koji je već 
	prije bio učitan.Znači da nam sigurno treba 30 mjesta jer više ne može 
	ni biti učitano. */
	int upis [30], j, i;
	for ( i = 0; i < 30; ++i) {
		do {
			printf("unesi član: ");
			scanf("%d", &upis[i]);
		} while ((upis[i] < 1) || (upis[i] > 30));
	/* ovo nije najsretnije rješenje, moglo se isto tako tražiti broj i 
	nakon provjere zadovoljava li on naše kriteriji ubacivati ga u polje.*/
		for (j=0; j<i; j++) {
			/* provjeri sve brojeve koji su prethodili upisanome, možda se
			neki od njih ponovio. */
			if (upis[i] == upis[j]) {
				printf("Broj %d bio je %d. učitani broj.\n", upis[i], j+1);
				printf("Ukupno učitano brojeva: %d\n", i+1);
				return 0;
			}
		}
	}
}
```

**[ Zadatak 15 ]** S tipkovnice učitavati cijele brojeve iz zatvorenog intervala [1, 40]. Učitavanje brojeva završiti kada se učita broj izvan navedenog intervala. Za svaki učitani broj na zaslon ispisati redni broj njegovog prvog pojavljivanja. Npr. za učitane brojeve: 
`2 1 18 4 4 48`, na zaslon se ispisuje:
`Broj 1 : 2`
`Broj 2 : 1`
`Broj 4 : 4`  
`Broj 18 : 3`

```c
#include <stdio.h> 
/* u ovom zadatku ćemo napraviti polje od koliko mi treba
elemenata i sve u polju ćemo inicijalizirati na 0. Vrtit ću for petlju 40
petlju, isto tako sam mogao staviti while (1). U trenutku kad korisnik
učita broj 2 ja ću u polje staviti,"broj 2 prvi put učitan je taj put" i više
neću dirati to polje. Prije ili kasnije će se ponoviti neki broj, ignorirat 
ću ponavljanja i onda kad budem trebao pisati rezultat samo ću prošetati po
polju i pogledati kada se koji broji prvi put pojavio */ 

int main (void) {

	int broj, i, upis[40]={0};
/*S tipkovnice učitavati cijele brojeve iz zatvorenog intervala [1, 40]. 
Učitavanje brojeva završiti kada se učita broj izvan navedenog intervala.*/
	for (i = 1; i < 40; ++i) {
		printf("unesi broj: ");
		scanf("%d", &broj);
		/* prekid u slučaju da broj nije iz intervala */
		if ((broj < 1) || (broj > 40)) break;
		if (upis[broj-1] == 0) upis[broj-1]=i;
	}
	for (i=0; i<40; i++) {
		if (upis[i] != 0) {
			printf("Broj %d : %d\n", i+1, upis[i]);
		}
	}
	return 0;
}
```


**[ Zadatak 17 ]** S tipkovnice učitati dva niza znakova (string) koji sigurno neće biti dulji od 30 znakova. Promijeniti prvi učitani niz tako da se znakovi koji se nalaze na pozicijama s parnim indeksom zamijene sa znakovima na odgovarajućim pozicijama u drugom nizu, pri čemu duljina prvog znakovnog niza mora ostati nepromijenjena. Znak iz prvog niza za kojeg ne postoji odgovarajući znak iz drugog niza (jer je drugi niz kraći) ostaje nepromijenjen. Na zaslon ispisati prvi niz nakon promjene te broj promijenjenih znakova. Npr. ako su učitani nizovi
`IvicaIMarica`
`SnjeguljicaI7Patuljaka` 
na zaslon se ispisuje:
`Promijenjeni niz: SvjcgIlaiiaa`
`Promijenjeno znakova: 6`

```c
#include <stdio.h>

int main (void) {
	char niz1[30], niz2[30];
	int len1=0, len2=0, brojac=0, i;
	gets(niz1);
	gets(niz2);

	/*utvrdi koji je duži*/
	while (niz1[len1]!='\0') len1++;
	while (niz2[len2] != '\0') len2++;
	
	/* promjena počinje na dužem nizu i traje koliko je 
	dugačak kraći niz */	
	if (len1 > len2) {
		for (i =0 ; i< len2; i++) {
			if (i%2 == 0) {
				niz2[i] = niz1[i];
				brojac++;
			}
		}
		printf("Promijenjeni niz: %s\n", niz2);;
		printf("Promijenjeni znakovi: %d\n", brojac);
	} else {
		for (i =0 ; i< len1; i++) {
			if (i%2 == 0) {
				niz1[i] = niz2[i];
				brojac++;
			}
		}
		printf("Promijenjeni niz: %s\n", niz1);;
		printf("Promijenjeni znakovi: %d\n", brojac);
	}
	return 0;
}
```

**[ Zadatak 20 ]** S tipkovnice učitati cijeli broj iz zatvorenog intervala [1, 99999] (broj je potrebno učitavati sve dok se ne unese ispravna vrijednost). Usporediti prvu i zadnju znamenku učitanog broja i ovisno o rezultatu usporedbe ispisati odgovarajuću poruku: "Broj XXXX: prva znamenka veća od zadnje", "Broj XXXX: prva znamenka manje od zadnje"" ili " Broj XXXX: prva i zadnja znamenka su jednake". Npr. za učitani broj 11290 na zaslon se ispisuje: 
`Broj 11290: prva znamenka je veca od zadnje. jer je prva znamenka 1, a zadnja znamenka je 0.`

```c
#include <stdio.h>

int main(void) {
	int broj, lenBroja;
	int polje[4], i, broj_tmp;
	do {
		printf("unesi broj iz intervala [1, 99999]: \n");
		scanf("%d", &broj);
	} while ((broj < 1) || (broj > 99999));
	/*broj_tmp je varijabla za usporedbu na kraju */
	broj_tmp = broj;
	/*prepiši broj u polje */

	for (i = 0; i <5; i++) {
		if (broj==0) break;
		polje[i] = broj%10;
		broj/=10;
	}
	
	lenBroja=i;
	
	/*broj je u memoriju zapisan naopako*/
	
	if (polje[0] < polje[lenBroja-1]) {
		printf("Broj %d: prva znamenka veća od zadnje\n", broj_tmp);
		return 0;
	}
	if (polje[0] > polje[lenBroja-1]) {
		printf("Broj %d: prva znamenka manja od zadnje\n", broj_tmp);
		return 0;
	} else {
		printf("Broj %d: prva znamenka jednaka kao zadnja\n", broj_tmp);
	}
 	return 0;
}
```

**[ Zadatak 22 ]** S tipkovnice učitati cijeli broj iz zatvorenog intervala [100, 999] (broj je potrebno učitavati sve dok se ne unese ispravna vrijednost). Ispisati broj koji se dobije obrnutim poretkom znamenki učitanog broja, te poruku je li dobiveni broj manji, veći ili jednak učitanom broju. Npr. za učitani broj 293 na zaslon se ispisuje:
`Broj 392 veći je od ucitanog broja.`
dok se za učitani broj 190 na zaslon ispisuje:
`Broj 91 manji je od ucitanog broja.`

```c
#include <stdio.h>

#define MIN 100
#define MAX 999

int main(void)
  {
    int i;
    int a, b;
    
    /* Prompts user for int while not within range */
    do
      {
        printf("Input int [%d, %d]: ", MIN, MAX);
        scanf("%d", &a);
      } while (!(a >= MIN && a <= MAX));
    
    /* Gives the reverse value of a to b */
    i = a; b = 0;
    while (i != 0)
      {
        b *= 10;
        b += i % 10;
        i /= 10;
      }
    
    /* Prints the inputed and reverse number */
    printf("Inputed number:  %d\n"
           "Reversed number: %d\n", a, b);

    /* Prints resulting inequality */
    if (b < a)
        printf("Number %d is smaller than the inputed number.\n", b);
    else if (b > a)
        printf("Number %d is greater than the inputed number.\n", b);
    else
        printf("Number %d is equal to the inputed number.\n", b);

    return 0;
    
  }
```
**[ Zadatak 26 ]** S tipkovnice učitati heksadekadski broj kao znakovni niz (string) koji sigurno neće biti dulji od 5 znakova. Ako učitani niz sadrži neki drugi znak osim heksadekadskih znamenki, ispisati poruku: `Ucitani niz nije ispravno zadan`. 
Ako je učitani niz ispravno zadan, potrebno je ispisati na zaslon najveću heksadekadsku znamenku koja se pojavljuje u učitanom broju. Npr. za učitani niz `90W20` na zaslon se ispisuje: `Ucitani niz nije ispravno zadan`. Npr. za učitani niz `A4b` na zaslon se ispisuje: `Najveca heksadekadska znamenka u ucitanom broju je b`.

```c
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#define HEX_SIZE 5

int main(void)
  {
    int i, max;
    char hex[HEX_SIZE];
    char c;
    
    printf("Input hex string: ");
    gets(hex);
    
    max = 0;
    for (i = 0; hex[i] != '\0'; i++)
      {
        /* Checks if it is NOT a hex */
        if ( !isxdigit(hex[i]) )
          {
            puts("Invalid input.");
            exit(1);
          }
          
        /* Checks if it is greater than the latest hex[max].
           Assumes that all letters in the ASCII table are above numbers,
           and that all letters are upper case. */
        if (toupper(hex[i]) > hex[max])
            max = i;
      }
    
    printf("The largest hex digit is: %c\n", hex[max]);
    
    return 0;
  }
```

**[ Zadatak 28 ]** S tipkovnice učitavati niz brojeva iz zatvorenog intervala [0,100]. Učitavanje brojeva završiti kada se učita broj izvan navedenog intervala. Ako prvi uneseni broj nije iz zadanog intervala, ispisati poruku o grešci: 
`Nije unesen niti jedan broj iz trazenog intervala` i završiti s izvođenjem programa. Ako je unesen barem jedan broj iz traženog intervala, ispisati zbroj svih unesenih brojeva manjih od 50. Npr. za unesene brojeve `50, 51, 17, 83, 37, 16, 64, -4` ispisati: 
`Zbroj svih unesenih brojeva manjih od 50 je 70`. jer su brojevi 17, 37 i 16 manji od 50.

```c
#include <stdlib.h>
#include <stdio.h>

#define MIN 0
#define MAX 100
#define SUM_MAX 50

#define TRUE 1
#define FALSE 0

int main(void)
  {
    int n;
    int sum, first;
    
    first = TRUE; sum = 0;
    while (TRUE)
      {
        printf("Input int [%d, %d]: ", MIN, MAX);
        scanf("%d", &n);
        
        /* Checks if input is NOT correct*/
        if (!((n >= MIN && n <= MAX)))
            break;
        
        /* Marks the first as false */
        first = FALSE;
        
        /* Sums if meets criteria */
        if (n < SUM_MAX)
            sum += n;
      }
    
    /* Checks the loop was broken at the first */
    if (first)
      {
        puts("No int is within requested interval.");
        exit(1);
      }
    
    /* Prints the result */
    printf("Sum of the numbers smaller than %d is: %d\n", SUM_MAX, sum);

    return 0;
    
  }
```

**[ Zadatak 30 ]** S tipkovnice učitavati niz brojeva iz zatvorenog intervala [0,100]. Učitavanje brojeva završiti kada se učita broj izvan navedenog intervala. Ako jedan od prva dva unesena broja nisu iz zadanog intervala, ispisati poruku o grešci: `Nije uneseno dovoljno brojeva iz trazenog intervala` i završiti s izvođenjem programa, a inače ispisati koliki je ostatak pri dijeljenju najvećeg unesenog broja s drugim najvećim unesenim brojem (ako takav broj postoji). 
Npr. za unesene brojeve `50, 83, 51, 17, 64, 37, 16, 64, -4` ispisati: `Ostatak pri dijeljenju 83 sa 64 je 19`. a za unesene brojeve `50, 83, 51, 17, 83, 83, 16, 64, -4` ispisati: `Ostatak pri dijeljenju 83 sa 83 je 0`.
```c
#include <stdlib.h>
#include <stdio.h>

#define MAX 100
#define MIN 0

#define TRUE 1
#define FALSE 0

int main(void)
  {
    int n;
    int count, max, max2;
    
    count = 0; max = MIN; max2 = MIN;
    while (TRUE)
      {
        printf("Input int [%d, %d]: ", MIN, MAX);
        scanf("%d", &n);
        
        /* Checks if input is NOT correct*/
        if (!((n >= MIN && n <= MAX)))
            break;
        
        /* Increments count */
        count++;
        
        /* Checks if new max or new max2 */
        if (n > max)
          {
            max2 = max;
            max = n;
          }
        else if (n > max2) max2 = n;            	
      }
    
    /* Checks the loop was broken at too early */
    if (count < 2)
      {
        puts("First two int are not within requested interval.");
        exit(1);
      }
    
    /* Prints the result */
    printf("Remainder when dividing %d with %d is: %d\n",
           max, max2, max%max2);

    return 0;
    
  }
```