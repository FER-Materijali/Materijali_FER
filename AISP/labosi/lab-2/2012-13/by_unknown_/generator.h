#include <stdlib.h>
#include <stdio.h>

const unsigned long JMBAG = 36461687;

const unsigned short low_character = 32;
const unsigned short high_character = 126;

// vrati 1 ako nije bilo greske
// vrati -1 ako nije bilo greske
int generator_sort(const char* datoteka, int kraj);

// vrati 1 ako nije bilo greske
// vrati -1 ako nije bilo greske
int generator_permute(const char* datoteka, int kraj);
