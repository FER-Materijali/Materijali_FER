#include "generator.h"

int generator_sort(const char* datoteka, int kraj) {
	FILE* f = fopen(datoteka, "w");
	if(NULL != f) {
        srand(JMBAG);
        int i, broj;
        for(i = 0; i < kraj; ++i){
            broj = rand();
            if(!broj)
                broj = 1;
            fprintf(f, "%d\n", broj);
        }
        fclose(f);
        return 1;
    }
	return -1;
}

int generator_permute(const char* datoteka, int kraj) {
    FILE* f = fopen(datoteka, "w");
	if(NULL != f) {
        srand(JMBAG);
        int i;
        char broj;
        for(i = 0; i < kraj; ++i) {
            broj = (high_character - low_character) * rand() / RAND_MAX + low_character;
            fprintf(f, "%c", broj);
        }
        fclose(f);
        return 1;
    }
	return -1;
}
