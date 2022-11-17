/*
 * ent_kod.cpp
 *
 *  Created on: Jan 4, 2011
 *      Author: Leo Osvald
 */

#include <cstdio>
#include <cstring>

#include "../../source_properties.h"
#include "huffman_coder.h"

void print_usage() {
	fprintf(stderr, "Koristenje: ent_kod.exe ulazna-datoteka [izlazna-datoteka]\n");
}

int main(int argc, char **argv) {
	if (argc <= 1) {
		print_usage();
		return 1;
	}

	FILE* input_file = (strcmp(argv[1], "-") ? fopen(argv[1], "r") : stdin);
	FILE* output_file = (argc <= 2 ? fopen("23.txt", "w")
			: (strcmp(argv[2], "-") ? fopen(argv[2], "w") : stdout));

	entropycoding::HuffmanCoder coder(source::symbol_probabilities());
	for (char c; (c = getc(input_file)) != EOF && !isEndline(c); )
		fputs(coder.code(c).toString().c_str(), output_file);

	fclose(input_file);
	fclose(output_file);

	return 0;
}

