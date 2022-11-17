/*
 * analiza.cpp
 *
 *  Created on: Jan 6, 2011
 *      Author: Leo Osvald
 */

#include <cstdio>
#include <cstring>
#include <cmath>

#include <map>
#include <utility>

#include "../base.h"

namespace analysis {

typedef std::pair<char, char> SymbolPair; // par simbola (poslano, primljeno)
typedef std::map<SymbolPair, double> JointProbabilityMap;

const int MAX_CHAR = 0x80;

void printStatistics(const char* name, const ProbabilityMap& prob, int freq[],
		const int symbol_count, const double& h) {
	printf("Broj pojavljivanja simbola za %s\n", name);
	FOREACH(it, prob) {
		printf("n(%c) = %d\n", it->first, freq[(int)it->first]);
	}
	printf("Ukupan broj simbola za %d\n", symbol_count);
	printf("Vjerojatnosti pojavljivanja simbola za %s\n", name);
	FOREACH(it, prob) {
		printf("p(%c) = %lf\n", it->first, it->second);
	}
	printf("Entropija za %s\n", name);
	printf("H(%s) = %lf\n", name, h);
}

ProbabilityMap createSymbolMap(int freq[], int count) {
	ProbabilityMap ret;
	for (int i = 0; i < MAX_CHAR; ++i)
		if (freq[i])
			ret[(char)i] = (double)freq[i] / count;
	return ret;
}

double computeEntropy(const ProbabilityMap& symbol_map) {
	double h = 0;
	FOREACH(it, symbol_map) {
		h -= it->second * log(it->second);
	}
	return h / log(2);
}

double computeTransinformation(const JointProbabilityMap& joint_prob,
		ProbabilityMap& src_p, ProbabilityMap& dest_p) {
	double i = 0;
	FOREACH(jp, joint_prob) {
		// i -= p(xi) * p(yi) * log2(p(xi, yi))
		i -= src_p[jp->first.first] * dest_p[jp->first.second] * log(jp->second);
	}
	return i / log(2);
}

}

void print_usage() {
	fprintf(stderr, "Koristenje: analiza.exe ulazna-datoteka-izvoriste ulazna-datoteka-odrediste\n");
}

int main(int argc, char **argv) {
	if (argc <= 2) {
		print_usage();
		return 1;
	}

	using namespace analysis;

	int src_size = 0, dest_size = 0;
	int src_freq[MAX_CHAR] = {0}, dest_freq[MAX_CHAR] = {0};
	JointProbabilityMap joint_prob; // zdruzene vjerojatnosti
	FILE* input_file_src = (strcmp(argv[1], "-") ? fopen(argv[1], "r") : stdin);
	FILE* input_file_dest = (strcmp(argv[2], "-") ? fopen(argv[2], "r") : stdin);
	for (bool src_eof = false, dest_eof = false; ; ) {
		char src_c, dest_c;
		if (!src_eof) {
			src_c = getc(input_file_src);
			src_eof |= (src_c == EOF || isEndline(src_c));
			if (!src_eof) {
				++src_size;
				++src_freq[(int)src_c];
			}
		}
		if (!dest_eof) {
			dest_c = getc(input_file_dest);
			dest_eof |= (dest_c == EOF || isEndline(dest_c));
			if (!dest_eof) {
				++dest_size;
				++dest_freq[(int)dest_c];
			}
		}

		// ako smo procitali sve i s izvora i s odredista, prekidamo
		if (src_eof && dest_eof)
			break;

		if (!src_eof && !dest_eof)
			joint_prob[SymbolPair(src_c, dest_c)] += 1;
	}
	fclose(input_file_src);
	fclose(input_file_dest);

	// podijeli broj pojava para (poslano, primljeno) s brojem takvih parova
	// da dobijes vjerojatnost
	int min_size = (src_size < dest_size ? src_size : dest_size);
	FOREACH(jp, joint_prob) {
		jp->second /= min_size;
	}

	ProbabilityMap src_prob = createSymbolMap(src_freq, src_size);
	double src_h = computeEntropy(src_prob);
	printStatistics("X", src_prob, src_freq, src_size, src_h);

	ProbabilityMap dest_prob = createSymbolMap(dest_freq, dest_size);
	double dest_h = computeEntropy(dest_prob);
	printStatistics("Y", dest_prob, dest_freq, dest_size, dest_h);

	printf("Transinformacija\n");
	printf("I(X; Y) = %lf\n", computeTransinformation(joint_prob, src_prob, dest_prob));
	printf("Zdruzene vjerojatnosti:\n");
	FOREACH(jp, joint_prob) {
		printf("p(%c, %c) = %lf\n", jp->first.first, jp->first.second, jp->second);
	}

	return 0;
}

