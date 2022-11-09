#include <cstdio>
#include <ctime>
#include <cstdlib>

#define l1size (1<<16) //32k + 32k L1i + L1d 
#define l2size (1<<21) //2048k L2

void init(char *buff, int size){
	for (int i = 0; i < size; ++i) *(buff + i) = 0;
}

void radikorisno(char *buff, int size){
	unsigned long rez = 0;
	for (int i = 0; i < size; ++i) {
		rez += *(buff + i);
	}
}

float L1bandwidth(){
	char *l1 = (char *)malloc(2 * l1size * sizeof(char));
	double start_time, end_time, total_time;
	double bandwidth = 0;
	float ret[2];

	init(l1, 2 * l1size);

	start_time = clock();
	for (int i = 0; i < 5000; ++i)	{
		for (int step = 0; step < 2 * l1size; ++step) *(l1 + step) += 1;	
	}
	end_time = clock();
	radikorisno(l1, 2 * l1size);

	total_time = (end_time - start_time) / CLOCKS_PER_SEC;
	printf("Total time: %lf\n", total_time);
	bandwidth = 5000 * 2 * l1size / total_time / (1<<20);

	free(l1);
	return bandwidth;	
}

float L2bandwidth(){
	char *l2 = (char *)malloc(2 * l1size * sizeof(char));
	double start_time, end_time, total_time;
	double bandwidth = 0;

	init(l2, 2 * l1size);

	start_time = clock();
	for (int i = 0; i < 10000; ++i)	{
		for (int step = 0; step < 2 * l1size; step += 64) *(l2 + step) += 1;	
	}
	end_time = clock();
	radikorisno(l2, 2 * l1size);

	total_time = (end_time - start_time) / CLOCKS_PER_SEC;
	printf("Total time: %lf\n", total_time);
	bandwidth = 10000 * 2 * l1size / 64 / total_time / (1<<20);

	free(l2);
	return bandwidth;	
}

float RAMbandwidth(){
	char *ram = (char *)malloc(2 * l2size * sizeof(char));
	double start_time, end_time, total_time;
	double bandwidth = 0;

	init(ram, 2 * l2size);

	start_time = clock();
	for (int i = 0; i < 1000; ++i)	{
		for (int step = 0; step < 2 * l2size; step += 64) *(ram + step) += 1;	
	}
	end_time = clock();
	radikorisno(ram, 2 * l2size);

	total_time = (end_time - start_time) / CLOCKS_PER_SEC;
	printf("Total time: %lf\n", total_time);
	bandwidth = l2size / 64 / total_time / (1<<20) * 2 * 1000;
	
	free(ram);
	return bandwidth;	
}

int main(){	
	float L1_bw = L1bandwidth();
	printf("Propusnost L1 %fMb/s\n\n", L1_bw);

	float L2_bw = L2bandwidth();
	printf("Propusnost L2 %fMb/s\n\n", L2_bw);

	float RAM_bw = RAMbandwidth();
	printf("Propusnost RAM %fMb/s\n\n", RAM_bw);

	printf("L1/L2 = %f\n", L1_bw/L2_bw);
	printf("L2/RAM = %f\n", L2_bw/RAM_bw);

	return 0;
}

