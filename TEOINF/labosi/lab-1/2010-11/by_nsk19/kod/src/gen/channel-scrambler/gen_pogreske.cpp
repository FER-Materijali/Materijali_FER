/*
 * gen_pogreske.cpp
 *
 *  Created on: Jan 5, 2011
 *      Author: Leo Osvald
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#include "../../bit_iterator.h"

namespace channel {

const double errorProbability = 1. / 20; // XXX hardkodirano

bool randomBit() {
	return (double)rand() / RAND_MAX < errorProbability;
}

}

void print_usage() {
	fprintf(stderr, "Koristenje: gen_pogreske.exe ulazna-datoteka [izlazna-datoteka]\n");
}

int main(int argc, char **argv) {
	if (argc <= 1) {
		print_usage();
		return 1;
	}

	srand((unsigned)time(NULL));

	FILE* input_file = (strcmp(argv[1], "-") ? fopen(argv[1], "r") : stdin);
	FILE* output_file = (argc <= 2 ? fopen("err_vec.txt", "w") // XXX hardkodirano
			: (strcmp(argv[2], "-") ? fopen(argv[2], "w") : stdout));

	int n = 0;
	for (FileBitIterator in_it(input_file); in_it.hasNextBit(); in_it.nextBit())
		++n;

	while (n-- > 0) {
		putc(fromBit(channel::randomBit()), output_file);
	}

	fclose(input_file);
	fclose(output_file);

	return 0;
}
