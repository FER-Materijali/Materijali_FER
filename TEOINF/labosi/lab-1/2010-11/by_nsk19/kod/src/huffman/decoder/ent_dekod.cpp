/*
 * ent_kod.cpp
 *
 *  Created on: Jan 4, 2011
 *      Author: Leo Osvald
 */

#include <cstdio>
#include <cstring>

#include "../../bit_iterator.h"
#include "../../source_properties.h"
#include "huffman_decoder.h"

void print_usage() {
	fprintf(stderr, "Koristenje: ent_dekod.exe ulazna-datoteka [izlazna-datoteka] [-v]\n");
}

int main(int argc, char **argv) {
	if (argc <= 1) {
		print_usage();
		return 1;
	}

	FILE* input_file = (strcmp(argv[1], "-") ? fopen(argv[1], "r") : stdin);
	FILE* output_file = (argc <= 2 ? fopen("67.txt", "w")
			: (strcmp(argv[2], "-") ? fopen(argv[2], "w") : stdout));
	bool verbose = (strcmp(argv[argc-1], "-v") == 0);

	entropycoding::HuffmanDecoder decoder(source::symbol_probabilities());
	FileBitIterator it(input_file);
	FileBitIterator& it_ref = it;
	BitIterator& bit_it = static_cast<BitIterator&>(it_ref);
	int ret = 0;
	BinaryCode decoded_bits;
	while (it.hasNextBit()) {
		char decoded = decoder.decode(bit_it, decoded_bits);
		if (decoded) {
			putc(decoded, output_file);
			ret += decoded_bits.size();
			if (verbose) {
				fprintf(stderr, "huffman_decode(%s) = %c\n",
						decoded_bits.toString().c_str(), decoded);
			}
		} else {
			fprintf(stderr, "[ENT_DEKOD] greska nakon %d bita\n", ret);
			return 1;
		}
	}

	fclose(input_file);
	fclose(output_file);

	return 0;
}


