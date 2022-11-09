#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct podaci {
  long matBroj;
  char ime[25];
  char prezime[25];
  short godRod;
};
typedef struct podaci Podaci;

struct cvor {
  Podaci * student;
  struct cvor * lijevo;
  struct cvor * desno;
};
typedef struct cvor Cvor;

// funkcija dodaje u binarno sortirano stablo
// kljuc je prezime
Cvor * dodajPrezime (Cvor * korijen, Podaci * student) {
  int smjer;
  if (korijen == NULL) {
    korijen = (Cvor *) malloc (sizeof(Cvor));
    if (korijen) {
      korijen->student = student;
      korijen->lijevo = korijen->desno = NULL;
    } 
  } else if ((smjer = strcmp(student->prezime, korijen->student->prezime)) < 0)
            korijen->lijevo = dodajPrezime (korijen->lijevo, student);
    else if (smjer > 0)
            korijen->desno = dodajPrezime (korijen->desno, student);
    else
            printf("Podatak %s vec postoji!\n", student->prezime);
  return korijen;
}
// funkcija dodaje u binarno sortirano stablo
// kljuc je ime
Cvor * dodajIme (Cvor * korijen, Podaci * student) {
  int smjer;
  if (korijen == NULL) {
    korijen = (Cvor *) malloc (sizeof(Cvor));
    if (korijen) {
      korijen->student = student;
      korijen->lijevo = korijen->desno = NULL;
    } 
  } else if ((smjer = strcmp(student->ime, korijen->student->ime)) < 0)
            korijen->lijevo = dodajIme (korijen->lijevo, student);
         else if (smjer > 0)
                 korijen->desno = dodajIme (korijen->desno, student);
              else
                 printf("Podatak %s vec postoji!\n", student->ime);
  return korijen;
}

// funkcija pretrazuje binarno sortirano stablo po kljucu prezime
Cvor * potraziPrezime (Cvor * korijen, char * prezime) {
  int smjer;
  if (korijen) {
    if ((smjer = strcmp(prezime, korijen->student->prezime)) < 0)
       return potraziPrezime (korijen->lijevo, prezime);
    else if (smjer > 0)
       return potraziPrezime (korijen->desno, prezime);
  }
  return korijen;
}

// funkcija inorder ispisuje zadano binarno stablo
void inOrder (Cvor * korijen) {
  if (korijen) {
    inOrder (korijen->lijevo);
    printf("%s, %s;", korijen->student->prezime, korijen->student->ime);
    inOrder (korijen->desno);
  }
}

// funkcija ispisuje sve cvorove zadane dubine
// poziv ispis(korijen, 1, n)
// gdje je n trazena dubina
void ispisi (Cvor * korijen, int trenutnaDubina, int trazenaDubina) {
  if (korijen) {
    if (trenutnaDubina == trazenaDubina)
      printf("%s %s\n", korijen->student->ime, korijen->student->prezime);
    ispisi (korijen->lijevo, trenutnaDubina + 1, trazenaDubina);
    ispisi (korijen->desno, trenutnaDubina + 1, trazenaDubina);
  }
}

// funkcija ispisuje sve cvorove na zadanoj dubini a ispred
// podataka stavlja odgovarajuci broj praznina
// poziv ispis2(korijen, 1, n)
// gdje je n trazena dubina
void ispisi2 (Cvor * korijen, int trenutnaDubina, int trazenaDubina) {
  int i;
  if (korijen) {
    if (trenutnaDubina == trazenaDubina) {
      for (i=0; i<trazenaDubina; i++) printf(" ");
      printf("%s %s\n", korijen->student->ime, korijen->student->prezime);
    }
    ispisi2 (korijen->lijevo, trenutnaDubina + 1, trazenaDubina);
    ispisi2 (korijen->desno, trenutnaDubina + 1, trazenaDubina);
  }
}

// funkcija trazi listove s najvecom i najmanjom razinom
// poziv balansirano (korijen, 1, &maxDub, &minDub);
void balansirano (Cvor * korijen, int trenDub, 
                                     int * maxDub, int * minDub) {
  if (korijen) {
    if (!korijen->lijevo & !korijen->desno) {
      if (*maxDub == 0 || trenDub > *maxDub)
        *maxDub = trenDub;
      if (*minDub == 0 || trenDub < *minDub)
        *minDub = trenDub;
	} else {
      balansirano (korijen->lijevo, trenDub + 1, maxDub, minDub);
      balansirano (korijen->desno, trenDub + 1, maxDub, minDub);
    }
  }
}

// funkcija za zadano binarno stablo ispisuje listove
void ispisiListove(Cvor * korijen) {
  if (korijen) {
    if (!korijen->lijevo & !korijen->desno)
      printf("%s %s; ", korijen->student->ime, korijen->student->prezime);
    ispisiListove(korijen->lijevo);
    ispisiListove(korijen->desno);
  }
}
// funkcija u zadanom binarnom stablu zbraja broj cvorova (argument
// funkcije) i ukupne godine starosti podataka u stablu (podatak se
// prenosi preko imena funkcije)
int zbroj(Cvor * korijen, int * broj) {
  if (korijen) {
    (*broj)++;
    return 2007 - korijen->student->godRod + 
         zbroj(korijen->lijevo, broj) +
         zbroj(korijen->desno, broj);
  }
  return 0;
}
// funkcija prebroji sve cvorove stabla
int prebroji(Cvor * korijen) {
  if (korijen)
    return 1 + prebroji(korijen->lijevo) + prebroji(korijen->desno);
  else
    return 0;
}
int main () {
  FILE * fUl;
  char buf[256];
  Podaci * student;
  Cvor * korijenPrezime = NULL;
  Cvor * korijenIme = NULL;
  Cvor * trazeni;
  int ukupno, broj = 0;
  int minDubina = 0, maxDubina = 0;
  int i;
  if ((fUl = fopen("stud.txt", "r")) == NULL) {
    fprintf(stderr, "Ne mogu otvoriti 'stud.txt'\n");
    return 1;
  }
  while (fgets(buf, 256, fUl)) {
    student = (Podaci *) malloc(sizeof(Podaci));
    sscanf(buf, "%ld;%[^;];%[^;];%d", &(student->matBroj), student->prezime, 
      student->ime, &(student->godRod));
    korijenPrezime = dodajPrezime(korijenPrezime, student);
    korijenIme = dodajIme(korijenIme, student);
  }
  fclose(fUl);
  inOrder(korijenPrezime);
  printf("\n");
  if(trazeni = potraziPrezime(korijenPrezime, "Maric"))
    printf("Pronasao: %s, %s %ld %d\n", trazeni->student->prezime,
      trazeni->student->ime, trazeni->student->matBroj, trazeni->student->godRod);
  inOrder(korijenIme);
  printf("\nPrezime, listovi:\n");
  ispisiListove(korijenPrezime);
  printf("\nIme, listovi:\n");
  ispisiListove(korijenIme);
  ukupno = zbroj(korijenPrezime, &broj);
  printf ("\nZbroj godina=%d Podataka u listi=%d prosjek=%5.2f\n",
    ukupno, broj, (float)ukupno / broj);
  broj = 0;
  ukupno = zbroj(korijenIme, &broj);
  printf ("\nZbroj godina=%d Podataka u listi=%d prosjek=%5.2f\n",
    ukupno, broj, (float)ukupno / broj);
  printf("Prebroji po prezimenu=%d\n", prebroji(korijenPrezime));
  printf("Prebroji po imenu=%d\n", prebroji(korijenIme));
  balansirano (korijenPrezime, 1, &maxDubina, &minDubina);
  printf("MaxDubina=%d  MinDubina=%d Balansirano=%s\n", maxDubina, minDubina,
    maxDubina - minDubina > 1 ? "false":"true");
  for (i=1; i<=maxDubina; i++) {
    printf("%d razina:\n", i);
    ispisi2(korijenPrezime, 1, i);
  }
  maxDubina = minDubina = 0;
  balansirano (korijenIme, 1, &maxDubina, &minDubina);
  printf("MaxDubina=%d  MinDubina=%d Balansirano=%s\n", maxDubina, minDubina,
    maxDubina - minDubina > 1 ? "false":"true");
  for (i=1; i<=maxDubina; i++) {
    printf("%d razina:\n", i);
    ispisi2(korijenIme, 1, i);
  }
}
