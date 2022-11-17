/*
 * bit_iterator.h
 *
 *  Created on: Dec 24, 2010
 *      Author: Leo Osvald
 */

#ifndef BIT_ITERATOR_H_
#define BIT_ITERATOR_H_

#include <cstdio>

#include "base.h"

class BitIterator {
public:
	virtual bool hasNextBit() = 0;
	virtual bool nextBit() = 0;
};

class FileBitIterator : public BitIterator {
	FILE* file_;
	bool look_ahead_;
	bool has_next_;
	bool next_bit_;
public:
	FileBitIterator(FILE* file) : file_(file), look_ahead_(false) { }
	bool hasNextBit() {
		if (!look_ahead_) {
			look_ahead_ = true;
			return has_next_ = readBit(file_, next_bit_);
		}
		return has_next_;
	}
	bool nextBit() {
		if (look_ahead_) {
			look_ahead_ = false;
			return next_bit_;
		}
		bool ret;
		if (!readBit(file_, ret))
			throw std::exception();
		return ret;
	}
	virtual bool readBit(FILE* file, bool& read_bit) {
		char c = getc(file);
		if (c == EOF || isEndline(c)) {
			read_bit = false;
			return false;
		}
		read_bit = toBit(c);
		return true;
	}
};

#endif /* BIT_ITERATOR_H_ */
