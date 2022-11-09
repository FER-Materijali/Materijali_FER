#include "permute.h"


#include "test.h"
#include <stdio.h>
#include <time.h>


int test_sort(SortPtr sptr, int kraj, int agreg, int start, int korak, int silazazno, const char* datoteka_u, const char* datoteka_i) {
    int ret = -1;
	FILE *ulaz, *izlaz;
	int i = start, j, niz[kraj], broj_clanova, cuvaj[kraj];
	time_t vrijeme1, vrijeme2;
	long trajanje, ukupno_trajanje;
	float prosjek;
	if((ulaz=fopen(datoteka_u,"r")) != NULL) {
        if((izlaz=fopen(datoteka_i,"w")) != NULL) {
            ret = 1;

            do {
                fscanf(ulaz,"%d",&niz[i]);
                cuvaj[i]=niz[i];
                i++;
            } while(i < kraj);

            for(broj_clanova = start; broj_clanova<=kraj; broj_clanova+=korak){
                ukupno_trajanje=0;
                for(i=0;i<agreg;i++) {

                    vrijeme1=clock();
                    sptr(niz, broj_clanova, silazazno); // sortiraj

                    vrijeme2 = clock();

                    trajanje=(vrijeme2-vrijeme1);

                    ukupno_trajanje+=trajanje;

                    for(j=0;j<broj_clanova;j++)
                        niz[j]=cuvaj[j];
                }

                prosjek=(float)ukupno_trajanje/agreg;
                fprintf(izlaz,"%d\t%f\n",broj_clanova,prosjek);
            }
            fclose(izlaz);
        }
        fclose(ulaz);
    }
    return ret;
}

int test_permute(int kraj, int agreg, int start, int korak, int silazazno, const char* datoteka_u, const char* datoteka_i) {
    int ret = -1;
	FILE *ulaz, *izlaz;
	int i=start, j, broj_clanova;
	char niz[kraj], cuvaj[kraj];
	time_t vrijeme1, vrijeme2;
	long trajanje, ukupno_trajanje;
	float prosjek;
	if((ulaz=fopen(datoteka_u,"r")) != NULL) {
        if((izlaz=fopen(datoteka_i,"w"))==NULL) {
            do{
                fscanf(ulaz,"%c",&niz[i]);
                cuvaj[i]=niz[i];
                i++;
            }while(i<kraj);


            for(broj_clanova=start; broj_clanova<=kraj; broj_clanova+=korak){
                ukupno_trajanje=0;
                for(i=0;i<agreg;i++){

                    vrijeme1=clock();
                    permute(niz,niz,broj_clanova);

                    vrijeme2=clock();

                    trajanje=(vrijeme2-vrijeme1);
                    ukupno_trajanje+=trajanje;

                    for(j=0;j<broj_clanova;j++)
                        niz[j]=cuvaj[j];
                }

                prosjek=(float)ukupno_trajanje/agreg;
                fprintf(izlaz,"%d\t%f\n",broj_clanova,prosjek);
            }

            fclose(izlaz);
        }
        fclose(ulaz);
    }
    return ret;
}
