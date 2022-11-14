#include <stdio.h>

//Opet ista struktura
typedef struct _osoba {
    int id;
    char ime[20 + 1], prezime[20 + 1];
    double prosjek;
} Osoba;

int main(void) {

    FILE *datoteka = fopen("izlaz.bin", "r+b");
    
    int id;
    double prosjek;
    Osoba osoba;
    
    int velicina;
    
    //Na neki nacin zeimo znati maksimalan ID koji je zapisan
    //Kako to mozemo znat? Buduci da je datoteka direktna
    //To znaci da je svaki zapis jednake duljine, tj zauzimaju
    //X blokova bajtova. Ako imao N * X blokova bajtova, znamo da 
    //nam je maksimalni ID upravo N
    //Jedino pitanje je kako znati velicinu datoteke? Pa jednostavno
    //Pozicioniramo se na kraj i pitamo gdje se nalazimo
    fseek(datoteka, 0, SEEK_END);
    velicina = ftell(datoteka) / sizeof(Osoba);
    
    //Ponavljamo dok god se ne use 0
    //Tj sami cemo reci kada brejkamo petlju
    while (1) {
        printf("Unesite ID ili 0 za kraj i novi prosjek: ");
        scanf("%d %lf", &id, &prosjek);
        //Ako nam je uneseni ID = 0, napravi break
        if (id == 0) { break ;}
        //U slucaju da je ID < 0 ili je ID > maksimalnog
        //IDa, ispisi gresku
        if (id < 0 || id > velicina) { 
            printf("ID ne postoji\n"); 
            continue;
        }
        //Buduci da je datoteka direktna, znamo gdje se nas zapis
        //nalazi. Iz tog razloga se mozemo pozicionirat na odgovarajuce 
        //mjesto u nasoj datoteci i procitati zapis
        //Mi i dalje ne zamo da li on tamo postoji ili ne, samo znamo
        //gdje se treba nalazit
        fseek(datoteka, (id - 1) * sizeof(Osoba), SEEK_SET);
        fread(&osoba, sizeof(Osoba), 1, datoteka);
        //Nakon sto smo ga procitali, trebamo provjerit da li
        //on stvarno i postoji
        if (osoba.id == 0) { 
            printf("ID ne postoji\n"); 
            continue;
        }
        //Nakon toga moramo promijeniti prosjek
        //Takodjer se moramo ponovno pozicionirat na odgovarajuce mjesto u
        //datoteci i zapisati zapis. Moramo se vratiti natrag
        //jer smo citanjem se odmaknuli za sizeof(Osoba) bajtova prema kraju
        osoba.prosjek = prosjek;
        fseek(datoteka, -sizeof(Osoba), SEEK_CUR);
        fwrite(&osoba, sizeof(Osoba), 1, datoteka);
    }

    //Kako bi se promjene odrazile, moramo prvo datoteku spremit jer
    //na nekim sustavima se ta promjena ne odrazi dok god se ne napuni
    //unutarnji buffer samog diska
    fclose(datoteka);
    FILE *datoteka = fopen("izlaz.bin", "rb");
    
    
    //Ovo nema smisla objasnjavat, samo citamo elemente
    //Ako ID != 0, onda ispisujemo podatke
    while (fread(&osoba, sizeof(Osoba), 1, datoteka) == 1) {
        if (osoba.id == 0) { continue; }
        printf("%d %s %s %.2lf\n", osoba.id, osoba.ime, osoba.prezime, osoba.prosjek);
    }
    
    fclose(datoteka);

    return 0;
}