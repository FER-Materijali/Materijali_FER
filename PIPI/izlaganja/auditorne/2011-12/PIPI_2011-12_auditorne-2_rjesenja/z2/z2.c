#include <stdio.h>

//Definiramo strukturu, to je valjda svima jasno
typedef struct _osoba {
    int id;
    char ime[20 + 1], prezime[20 + 1];
    double prosjek;
} Osoba;

int main(void) {

    FILE *in = fopen("ulaz.txt", "r");
    FILE *out = fopen("izlaz.bin", "wb");

    Osoba osoba;
    
    //Citamo u strukturu podatke po formatu %d %s %s %lf iz datoteke
    //buduci da je tako zadano u zadatku.
    //Na to si pazite jer vam je to uvijek zadano u zadatku i to su vam laki
    //bodovi
    while (fscanf(in, "%d %s %s %lf", &osoba.id, osoba.ime, osoba.prezime, &osoba.prosjek) == 4) {
        //Pozicioniramo se na odgovarajucu poziciju buduci da je minimalni ID = 1
        //a datoteka mora biti direktna po IDu. Isto tako, korisimo SEEK_SET jer 
        //tocno znamo kuda zelimo otici
        fseek(out, (osoba.id - 1) * sizeof(Osoba), SEEK_SET);
        //Potom taj sadrzaj samo zapisemo
        fwrite(&osoba, sizeof(Osoba), 1, out);
    }
    
    fclose(in);
    fclose(out);
    
    return 0;
}