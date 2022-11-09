#include <cstdio>
#include <cstdlib>
#include <ctime>

void init(unsigned int *buff, int size){
	for (int i = 0; i < size; ++i)	*(buff + i) = 0;
}

int stdinc(unsigned int *buff, int rows, int cols){
	int rez = 0;
	for (int i = 0; i < rows; ++i){
		for (int j = 0; j < cols; ++j){
			*(buff + i * cols + j) += 1;
			rez += (*(buff + i * cols + j));
		}
	}
	return rez;
}

int reverseinc(unsigned int *buff, int rows, int cols){
	int rez = 0;
	for (int j = 0; j < cols; ++j){
		for (int i = 0; i < rows; ++i){
			*(buff + i * cols + j) += 1;
			rez += (*(buff + i * cols + j));
		}
	}
	return rez;
}



int main(int argc, char **argv){
	int n = (1<<11);
	int m = (1<<16) / sizeof(int);
	int size = n * m;
	int rows = n; int cols = m;	
	unsigned int *matrix = (unsigned int *)malloc(size * sizeof(int));
	double start, end, rez;
	int r = 0;

	init(matrix, size);

	start = clock();
	r = stdinc(matrix, rows, cols);
	end = clock();
	rez = (end - start) / CLOCKS_PER_SEC;
	printf("Total time: %lf s\n", rez);
	printf("Result: %d\n\n", r);


	init(matrix, size);
	start = clock();
	r = reverseinc(matrix, rows, cols);
	end = clock();
	rez = (end - start) / CLOCKS_PER_SEC;
	printf("Total time: %lf s\n", rez);
	printf("Result: %d\n\n", r);

	
	return 0;
}
