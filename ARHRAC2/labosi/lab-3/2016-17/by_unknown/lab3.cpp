#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys\timeb.h>
#include <malloc.h>

// Processor - Intel Core i5-2430M CPU @ 2.40 GHz
// OS Windows 10 Professional 64-bit
// L1	32 KB (instruction) 32 KB (data)	64bit	8-way/8-way associate
// L2	256 KB	64bit	8-way associate
// L3	3 MB	64bit	12-way associate

#define S1 32768
#define B1 64
#define S2 262144
#define B2 64
#define S3 3145728
#define B3 64
#define REDAK 100

void Initialization(char *polje, int size)
{
	int i;
	for (i = 0; i < size; i++)
		polje[i] = 0;
}

double L1_Bandwidth()
{
	int i, j;
	double start, stop, duration, bandwidth;
	char *L1 = (char *)malloc(2 * S1 * sizeof(char));

	Initialization(L1, 2 * S1);

	start = clock();
	for (i = 0; i < 10000; i++)
		for (j = 0; j < 2 * S1; j++)
			L1[j]++;
	stop = clock();

	duration = (stop - start) / CLOCKS_PER_SEC;
	printf("POTPROGRAM A: %.2lf s\n", duration);
	bandwidth = 10000 * 2 * S1 / duration / S1;
	free(L1);
	return bandwidth;
}

double L2_Bandwidth()
{
	int i, j;
	double start, stop, duration, bandwidth;
	char *L2 = (char *)malloc(2 * S1 * sizeof(char));

	Initialization(L2, 2 * S1);

	start = clock();
	for (i = 0; i < 7000; i++)
		for (j = 0; j < 2 * S1; j += B1)
			L2[j]++;
	stop = clock();
	
	duration = (stop - start) / CLOCKS_PER_SEC;
	printf("POTPROGRAM B: %.2lf s\n", duration);
	bandwidth = 7000 * 2 * S1 / B1 / duration / (1 << 18);
	free(L2);
	return bandwidth;
}

double RAM_Bandwidth()
{
	int i, j;
	double start, stop, duration, bandwidth;
	char *RAM = (char*)malloc(2 * S2*sizeof(char));

	Initialization(RAM, 2 * S2);

	start = clock();
	for (i = 0; i < 10000; i++)
		for (j = 0; j < 2 * S2; j += B2)
			RAM[j]++;
	stop = clock();

	duration = (stop - start) / CLOCKS_PER_SEC;
	printf("POTPROGRAM C: %.2lf s\n", duration);
	bandwidth = 10000 * 2 * S2 / B2 / duration / (1 << 18);
	free(RAM);
	return bandwidth;
}


int main()
{
	double tL1, tL2, tRAM;
	tL1 = L1_Bandwidth();
	printf("L1 PROPUSNOST %f MB/s\n\n", tL1);

	tL2 = L2_Bandwidth();
	printf("L2 PROPUSNOST %f MB/s\n\n", tL2);

	tRAM = RAM_Bandwidth();
	printf("RAM PROPUSNOST %f MB/s\n\n", tRAM);

	printf("L2/L1 = %f\n", tL2 / tL1);
	printf("RAM/L3 = %f\n\n\n", tRAM/ tL2);

	return 0;
}