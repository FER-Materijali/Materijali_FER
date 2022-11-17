/*
 * kanal.cpp
 *
 *  Created on: Jan 4, 2011
 *      Author: Leo Osvald
 */


#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cstddef>

#include "../bit_iterator.h"

void print_usage() {
	fprintf(stderr, "Koristenje: kanal.exe ulazna-datoteka pogreske-datoteka [izlazna-datoteka]\n");
}

int main(int argc, char **argv) {
	if (argc <= 2) {
		print_usage();
		return 1;
	}

	FILE* input_file = (strcmp(argv[1], "-") ? fopen(argv[1], "r") : stdin);
	FILE* error_vec_file = (strcmp(argv[2], "-") ? fopen(argv[2], "r") : NULL);
	FILE* output_file = (argc <= 3 ? fopen("45.txt", "w") // XXX hardkodirano
			: (strcmp(argv[3], "-") ? fopen(argv[3], "w") : stdout));

	FileBitIterator in_it(input_file);
	FileBitIterator error_vec_it(error_vec_file);
	while (in_it.hasNextBit()) {
		bool bit = in_it.nextBit();
		if (error_vec_it.hasNextBit())
			bit ^= error_vec_it.nextBit();
		putc(fromBit(bit), output_file);
	}

	fclose(input_file);
	fclose(output_file);
	if (error_vec_file != NULL)
		fclose(error_vec_file);

	return 0;
}
