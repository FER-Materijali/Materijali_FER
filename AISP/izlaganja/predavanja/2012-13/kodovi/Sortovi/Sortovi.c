// sortovi.c
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <sys\timeb.h>

typedef int tip;

// vrijeme u ms
int Trajanje (struct timeb *vrijeme1) {
  struct timeb vrijeme2; 
  ftime (&vrijeme2);
  return 1000 * (vrijeme2.time - vrijeme1->time) +
               vrijeme2.millitm - vrijeme1->millitm;
}

// ispis poruke i prekid programa
void Fatalno (char *niz) {
  printf ("\n %s \n", niz);
	exit (1);
}

// zamjena vrijednosti *lijevo i *desno
__inline void Zamijeni (tip *lijevo, tip *desno) {
  tip pom = *lijevo;
  *lijevo = *desno;
  *desno = pom;
}

// sort selekcijom
void SelectionSort (tip A [], int N) {
	int i, j, min;
	for (i = 0; i < N; i++) {
		min = i;
    for (j = i+1; j < N; j++) {
      if (A[j] < A[min]) min = j;
		}
		Zamijeni(&A[i], &A[min]);
	}
}

// mjehuricasti sort
void BubbleSort (tip A [], int N) {
	int i, j;
	for (i = 0; i < N-1; i++) {
    for (j = 0; j < N-1-i; j++) {
      if (A[j+1] < A[j]) Zamijeni (&A[j], &A[j+1]);
		}
	}
}

// mjehuricasti sort - poboljsani
void BubbleSortPoboljsani (tip A [], int N) {
	int i, j, BilaZamjena;
	for (i = 0, BilaZamjena = 1; BilaZamjena; i++) {
		BilaZamjena = 0;
    for (j = 0; j < N-1-i; j++) {
      if (A[j+1] < A[j]) {
				Zamijeni (&A[j], &A[j+1]);  
				BilaZamjena = 1;
			}
		}
	}
}

// sort ubacivanjem (umetanjem)
void InsertionSort (tip A [], int N) {
  int i, j;
  tip pom;
  for (i = 1; i < N; i++) {
    pom = A[i];
    for (j = i; j >= 1 && A[j-1] > pom; j--)
      A[j] = A[j-1];
    A[j] = pom;
  }
}

// Shell sort
void ShellSort (tip A [], int N) {
  int i, j, korak;
  tip pom;
  for (korak = N / 2; korak > 0; korak /= 2) {
		//printf("\nkorak=%d\n", korak);
    // Insertion sort s veæim korakom
    for (i = korak; i < N; i++) {
			//printf("\ni=%d:", i);
      pom = A [i];
      for (j = i; j >= korak && A[j-korak] > pom; j -= korak) {
				//printf("%d:%d ", j, j-korak);
        A [j] = A [j - korak];
      }
      A [j] = pom;
    }
  }
}

// Heap sort - podesavanje gomile
void Podesi (tip A[], int i, int n) {
  int j; 
  tip stavka;
  j = 2*i;
  stavka = A[i];
  while (j <= n ) {
    if ((j < n) && (A[j] < A[j+1])) j++;
    if (stavka >= A[j]) break;
    A[j/2] = A[j];
    j *=2;
  }
  A[j/2] = stavka;
}

// Heap sort - inicijalno stvaranje gomile
void StvoriGomilu (tip A[], int n) {
  int i;
  for (i = n/2; i >= 1; i--) 
    Podesi (A, i, n);
}

// Heap sort 
void HeapSort (tip A[], int n) {
  // A[1:n] sadrzi podatke koje treba sortirati
  int i;
  StvoriGomilu (A, n);
  for (i = n; i >= 2; i--) {
		// Zamijeni korijen i zadnji list, skrati polje za 1 i podesi gomilu
		Zamijeni (&A[1], &A[i]);
    Podesi (A, 1, i-1);
  }
}

// udruzivanje LPoz:LijeviKraj i DPoz:DesniKraj
void Merge (tip A [], tip PomPolje [], int LPoz, int DPoz, int DesniKraj) {
  int i, LijeviKraj, BrojClanova, PomPoz;
  LijeviKraj = DPoz - 1;
  PomPoz = LPoz;
  BrojClanova = DesniKraj - LPoz + 1;
  // glavna pelja
  while (LPoz <= LijeviKraj && DPoz <= DesniKraj) {
    if (A [LPoz] <= A [DPoz])
      PomPolje [PomPoz++] = A [LPoz++];
    else 
	  PomPolje [PomPoz++] = A [DPoz++];
  }
  while (LPoz <= LijeviKraj)
    // Kopiraj ostatak prve polovice
    PomPolje [PomPoz++] = A [LPoz++];
  while (DPoz <= DesniKraj)
    // Kopiraj ostatak druge polovice
    PomPolje [PomPoz++] = A [DPoz++];
  for (i = 0; i < BrojClanova; i++, DesniKraj--)
    // Kopiraj PomPolje natrag
    A [DesniKraj] = PomPolje [DesniKraj];
}

// MergeSort - rekurzivno sortiranje podpolja
void MSort (tip A [], tip PomPolje[], int lijevo, int desno ) {
  int sredina;
  if (lijevo < desno) {
    sredina = (lijevo + desno) / 2;
    MSort (A, PomPolje, lijevo, sredina);
    MSort (A, PomPolje, sredina + 1, desno);
    Merge (A, PomPolje, lijevo, sredina + 1, desno);
  }
}

// MergeSort - sort udruzivanjem
void MergeSort (tip A [], int N) {
  tip *PomPolje;
  PomPolje = malloc (N * sizeof (tip));
  if (PomPolje != NULL) {
    MSort (A, PomPolje, 0, N - 1);
    free (PomPolje);
  } else 
	Fatalno ("Nema mjesta za PomPolje!");
}

// QuickSort - medijan i stozer
// Vrati medijan od lijevo, sredina i desno, 
// poredaj ih i sakrij stozer
tip medijan3 (tip A [], int lijevo, int desno) {
  int sredina = (lijevo + desno) / 2;
  if (A [lijevo] > A  [sredina])
    Zamijeni (&A[lijevo], &A[sredina]);
  if (A [lijevo] > A [desno])
    Zamijeni (&A [lijevo], &A [desno]);
  if (A [sredina] > A [desno])
    Zamijeni (&A [sredina], &A [desno]);
  // Sada je: A[lijevo]<=A[sredina]<=A[desno]
  // Sakrij stozer
  Zamijeni (&A [sredina], &A [desno - 1]);
  // Vrati stozer
  return A [desno - 1];                       
}

// QuickSort - rekurzivno sortiranje podpolja
#define Cutoff (3)

void Qsort (tip A [], int lijevo, int desno) {
  int i, j;
  tip stozer;
  if (lijevo + Cutoff <= desno) {
    stozer = medijan3 (A, lijevo, desno);
    i = lijevo; j = desno - 1;
    while (1) {
      while (A [++i] < stozer);
      while (A [--j] > stozer);
      if (i < j)
        Zamijeni (&A [i], &A [j]);
      else
        break;
    } 
    // Obnovi stozer
    Zamijeni (&A [i], &A [desno - 1]); 
    Qsort (A, lijevo, i - 1);
    Qsort (A, i + 1, desno);
  } else {
    // Sortiraj podpolje
    InsertionSort (A + lijevo, desno - lijevo + 1);
  }
}

// QuickSort
void QuickSort (tip A [], int N) {
  Qsort (A, 0, N - 1);
}

// Quicksort, sožer je prvi element
void Qsort2(tip A[], int lijevo, int desno) {
    int i,j;
    i = lijevo+1;
    j = desno;

    if (lijevo >= desno) return;

    while ((i <= j) && (i<=desno) && (j>lijevo)) {
        while ((A[i] < A[lijevo]) && (i<=desno)) i++;
        while ((A[j] > A[lijevo]) && (j>lijevo)) j--;
        if (i<j) {
            Zamijeni (&A [i], &A [j]);
        }
    }
    if (i > desno) { // stožer je najveæi u polju
        Zamijeni (&A [lijevo], &A [desno]);
        Qsort2(A, lijevo, desno-1);
    }
    else if (j<=lijevo) { // stožer je najmanji u polju
        Qsort2(A, lijevo+1, desno);
    }
    else { // stožer je negdje u sredini
        Zamijeni (&A [lijevo], &A [j]);
        Qsort2(A, lijevo, j-1);
        Qsort2(A, j+1, desno);
    }
}

// QuickSort, stožer je prvi element
void QuickSort2 (tip A [], int N) {
  Qsort2 (A, 0, N - 1);
}


// Testiranje sortova

// generira podatke za sort
void Generiraj (tip A [], int N) {
  int i;
  srand ((unsigned) time (NULL));
	// vrijednosti elemenata kao vrijednosti njihovih indeksa
  for( i = 0; i < N; i++ ) A [i] = i;
	// promijesaj vrijednosti
  for( i = 1; i < N; i++ )
    Zamijeni (&A [i], &A [rand () % (i + 1)]);
}

// provjeri da li svi elementi imaju vrijednost jednaku indeksu
void ProvjeriSort (tip A [], int N) {
  int i, flag = 0;
  for (i = 0; i < N; i++) {
    if (A[i] != i) {
      printf( "Sort ne radi: %d %d\n", i, A [i]);
	    flag = 1;
	  }
  }
  if (!flag) printf( "Provjera zavrsena: sort OK\n" );
}

// kopira polje desno[] u polje lijevo[]
void Kopiraj (tip lijevo [], tip desno [], int N) {
  int i;
  for (i = 0; i < N; i++) lijevo [i] = desno [i];
}

// ispis polja
void ispisi(int A[], int n) {
	int i;
	printf("\n");
	for (i = 0; i < n; i++) printf(" A[%d]",i);
	printf("\n");
	for (i = 0; i < n; i++) printf("%5d", A[i]);
	printf("\n");
}

// pokretanje potprograma za sort
void TestSorta (tip A[], tip B[], int N, char *ImeSorta, void (*Sort) (tip A[], int N)) {
	// A - polje koje se sortira
	// B - polje s podacima za sort
	// N - broj clanova polja
	// ImeSorta - naziv algoritma
	// Sort - pokazivac na funkciju koja obavlja sort
	struct timeb Vrijeme1; 
	// kopiraj podatke iz B u A
	Kopiraj (A, B, N);
	// sortiraj i mjeri vrijeme
	printf ("%s...\n", ImeSorta); 
	ftime (&Vrijeme1);
	if (strcmp(ImeSorta, "Heap Sort") == 0) {
		Sort (A-1, N); // da HeapSort "vidi" A[0] kao A[1]
	} else {
		Sort (A, N);	// standardni poziv
	}
	printf ("Trajanje: %d ms\n", Trajanje(&Vrijeme1)); 
	ProvjeriSort (A, N);

	// sortiraj prethodno sortirano polje A
	printf ("%s sortiranog polja...\n", ImeSorta); 
	ftime (&Vrijeme1);
	if (strcmp(ImeSorta, "Heap Sort") == 0) {
		Sort (A-1, N);
	} else {
		Sort (A, N);
	}
	printf ("Trajanje: %d ms\n", Trajanje(&Vrijeme1)); 
	ProvjeriSort (A, N);
	printf ("Pritisni bilo koju tipku...\n\n");
	getch();
}

int main () {
#if 1
	int *Polje1, *Polje2, Duljina;
	// inicijalizacija  
	printf ("Unesi broj clanova polja >");
	scanf ("%d", &Duljina);
	Polje1 = (int *) malloc (Duljina * sizeof (int));
	Polje2 = (int *) malloc (Duljina * sizeof (int));
	if (!Polje1 || !Polje2) Fatalno ("Nema dovoljno memorije!");
	// generiranje podataka
	Generiraj (Polje2, Duljina);
#else
  int Polje1[] = { 2, 6, 4, 5, 3, 7, 1, 0 };
  int Polje2[] = { 2, 6, 4, 5, 3, 7, 1, 0 };
  int Duljina;
  Duljina = sizeof(Polje1) / sizeof(Polje1[0]);
#endif
	// sortiranje
	TestSorta (Polje1, Polje2, Duljina, "Selection Sort", SelectionSort); 
	TestSorta (Polje1, Polje2, Duljina, "Bubble Sort", BubbleSort); 
	TestSorta (Polje1, Polje2, Duljina, "Bubble Sort poboljsani", BubbleSortPoboljsani); 
	TestSorta (Polje1, Polje2, Duljina, "Insertion Sort", InsertionSort); 
	TestSorta (Polje1, Polje2, Duljina, "Shell Sort", ShellSort);
	TestSorta (Polje1, Polje2, Duljina, "Heap Sort", HeapSort); 
	TestSorta (Polje1, Polje2, Duljina, "Merge Sort", MergeSort); 
	TestSorta (Polje1, Polje2, Duljina, "Quick Sort", QuickSort); 
	TestSorta (Polje1, Polje2, Duljina, "Quick Sort 2", QuickSort2); 
	return 0;
}
