/*
 * izvor.cpp
 *
 *  Created on: Jan 3, 2011
 *      Author: Leo Osvald
 */

#include <cstdio>
#include <cstring>

#include "../../source_properties.h"
#include "symbol_generator.h"

void print_usage() {
	fprintf(stderr, "Koristenje: izvor.exe [izlazna-datoteka]\n");
}

int main(int argc, char **argv) {

	FILE* output_file = (argc <= 1 ? fopen("12.txt", "w")
			: (strcmp(argv[1], "-") ? fopen(argv[1], "w") : stdout));
	source::SymbolGenerator gen(source::symbol_probabilities());
	int n = 10000; // XXX hardkodirano
	while (n-- > 0)
		putc(gen.get(), output_file);
	fclose(output_file);

	return 0;
}

