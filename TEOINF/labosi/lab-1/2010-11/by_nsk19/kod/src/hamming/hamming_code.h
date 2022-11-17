/*
 * hamming_code.h
 *
 *  Created on: Dec 26, 2010
 *      Author: Leo Osvald
 */

#ifndef HAMMING_CODE_H_
#define HAMMING_CODE_H_

#include "../binary_code.h"

namespace paritycoding {

class HammingCode : public BinaryCode {
	static inline int lowBit(int x) {
		return x & -x;
	}

	static inline int log2(int x) {
		int ret = 0;
		while (x >>= 1)
			++ret;
		return ret;
	}

	static inline int highBit(int x) {
		return 1 << log2(x);
	}

	static inline bool isPowerOfTwo(int x) {
		return lowBit(x) == x;
	}

	/**
	 * Vraca broj podatkovnih bitova ispred indeksa podatkovnog bita
	 */
	static inline int dataBitCountBefore(int parityBitIndex) {
		return (1 << parityBitIndex) - parityBitIndex - 1;
	}

	static int fromDataIndex(int data_index) {
		++data_index; // svedi na 1-bazirani indeks
		for (int i = 0; i < 31; ++i) {
			int before_count = dataBitCountBefore(i);
			if (before_count >= data_index)
				return data_index - 1 + i;
		}
		return -1; // ovo se nikad nece niti dogoditi
	}

	void updateParityBits(int index, bool changed) {
		// ako se bit nije promijenio, onda se nije niti jedan paritetni
		if (!changed)
			return ;

		++index; // svedi na 1-bazirani indeks
		// prodji kroz sve bitove
		for (int low_bit; index > 0; index -= low_bit) {
			low_bit = lowBit(index);
			flip(low_bit - 1);
		}
	}

public:
	HammingCode(BinaryCode binary_code, bool hamming) {
		if (hamming) { // ako su ovo bitovi za hammingov kod, samo ih kopiraj
			setBits(binary_code);
		} else { // inace na potencije broja 2 dodaj nule, a ove ostale kopiraj
			int data_index = 0;
			for (int pos = 0; data_index < binary_code.size(); ++pos) {
				if (isParityBit(pos))
					append(false);
				else {
					bool bit = binary_code.isSet(data_index++);
					append(bit);
					updateParityBits(pos, bit);
				}
			}
		}
	}

	bool getDataBit(int index) const {
		return isSet(fromDataIndex(index));
	}

	bool getParityBit(int index) const {
		return isSet(1 << index);
	}

	int parityBitCount() const {
		int s = size();
		return s > 0 ? log2(size()) + 1 : 0;
	}

	int dataBitCount() const {
		int s = size();
		return s > 2 ? s - log2(s) - 1 : 0;
	}

	int errorSyndrome() const {
		int ret = 0;
		for (int pb_index = parityBitCount() - 1; pb_index >= 0; --pb_index) {
			bool parity = false;
			for (int i = 1; i <= size(); ++i)
				if ((1 << pb_index) & i)
					parity ^= isSet(i - 1);

			// ako paritet nije paran (false), onda dodajemo bit (1 << pb_index)
			// (da petlja ide uzlazno bilo bi if (parity) ret |= 1 << pb_index;
			ret = (ret << 1) | parity;
		}

		// ako sindrom upucuje na gresku na indeksu izvan ovog bloka
		// onda je doslo do visestruke greske koju nije moguce ispraviti
		if (ret > size())
			return -1;

		return ret;
	}

	int fix() {
		int error_syndrome = errorSyndrome();

		// ako ima greske i ona se moze ispraviti, popravi je
		if (error_syndrome > 0)
			flip(error_syndrome - 1);

		return error_syndrome;
	}

	static inline bool isParityBit(int pos) {
		return isPowerOfTwo(pos + 1);
	}

};

}

#endif /* HAMMING_CODE_H_ */
