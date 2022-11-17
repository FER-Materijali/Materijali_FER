/*
 * z_kod.cpp
 *
 *  Created on: Jan 4, 2011
 *      Author: Leo Osvald
 */

#include <cstdio>
#include <cstring>

#include "../../bit_iterator.h"
#include "../../binary_code.h"
#include "../hamming_code.h"

void print_usage() {
	fprintf(stderr, "Koristenje: z_kod.exe ulazna-datoteka [izlazna-datoteka]\n");
}

int main(int argc, char **argv) {
	if (argc <= 1) {
		print_usage();
		return 1;
	}

	FILE* input_file = (strcmp(argv[1], "-") ? fopen(argv[1], "r") : stdin);
	FILE* output_file = (argc <= 2 ? fopen("34.txt", "w") // XXX hardkodirano
			: (strcmp(argv[2], "-") ? fopen(argv[2], "w") : stdout));

	static const int k = 11; // XXX hardkodirano

	BinaryCode bc;
	FileBitIterator it(input_file);
	while (it.hasNextBit()) {
		int i;
		for (i = 0; i < k && it.hasNextBit(); ++i) {
			bc.append(it.nextBit());
		}
		// ako fali jos bitova, nadopuni nulama
		for (; i < k; ++i)
			bc.append(false);

		// kodiraj
		paritycoding::HammingCode hamming_code(bc, false);
		fputs(hamming_code.toString().c_str(), output_file);
		bc.clear();
	}

	fclose(input_file);
	fclose(output_file);

	return 0;
}
