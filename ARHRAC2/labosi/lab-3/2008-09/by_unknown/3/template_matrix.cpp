#include <cstdio>
#include <cstdlib>
#include <ctime>

template <class T>
void init(T *buff, int size){
	for (int i = 0; i < size; ++i)	*(buff + i) = 1;
}

template <class T>
int stdinc(T *buff, int rows, int cols){
	int rez = 0;
	for (int i = 0; i < rows; ++i){
		for (int j = 0; j < cols; ++j){
			*(buff + i * cols + j) *= 23;
			rez += (*(buff + i * cols + j));
		}
	}
	return rez;
}

template <class T>
int reverseinc(T *buff, int rows, int cols){
	int rez = 0;
	for (int j = 0; j < cols; ++j){
		for (int i = 0; i < rows; ++i){
			*(buff + i * cols + j) *= 23;
			rez += (*(buff + i * cols + j));
		}
	}
	return rez;
}

template <class T>
void test(T *buff, const char *type){
	int n = 1 << 11;
	int m = (1 << 16) / sizeof(T);
	int size = n * m;
	int rows = n; int cols = m;
	double start, end, total;
	int r;
	buff = (T *)malloc(size * sizeof(T));

	printf("--- Data type --- %s\n", type);

	init(buff, size);
	start = clock();
	r = stdinc(buff, rows, cols);	
	end = clock();
	total = (end - start) / CLOCKS_PER_SEC;
	printf("Total time (standard order): %lf s\n", total);

	init(buff, size);
	start = clock();
	r = reverseinc(buff, rows, cols);	
	end = clock();
	total = (end - start) / CLOCKS_PER_SEC;
	printf("Total time (reversed order): %lf s\n\n", total);

	free(buff);
}


int main(int argc, char **argv){
	int *intmatrix = NULL;
	char *charmatrix = NULL;
	float *floatmatrix = NULL;
	double *doublematrix = NULL;

	test(intmatrix, "int");
	test(charmatrix, "char");
	test(floatmatrix, "float");
	test(doublematrix, "double");

	return 0;
}
