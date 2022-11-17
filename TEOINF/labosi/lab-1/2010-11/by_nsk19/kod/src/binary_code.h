/*
 * base.h
 *
 *  Created on: Dec 26, 2010
 *      Author: Leo Osvald
 */

#ifndef BINARY_CODE
#define BINARY_CODE

#include <vector>
#include <string>

#include "base.h"
#include "bit_iterator.h"

class BinaryCode {
	std::vector<bool> v_;

	BinaryCode(int length) {
		v_.resize(length);
	}

public:

	BinaryCode() {
	}

	BinaryCode(const BinaryCode& clone) {
		setBits(clone);
	}

	BinaryCode(const std::string& s) {
		for (int i = 0; i < (int)s.size(); ++i)
			v_.push_back(toBit(s[i]));
	}

	bool isSet(int pos) const {
		return v_[pos];
	}

	bool empty() const {
		return v_.empty();
	}

	int size() const {
		return v_.size();
	}

	bool flip(int pos) {
		return !(v_[pos] = !v_[pos]);
	}

	bool set(int pos, bool val) {
		bool changed = (v_[pos] != val);
		v_[pos] = val;
		return changed;
	}

	void setBits(const BinaryCode& bc) {
		v_ = bc.v_;
	}

	BinaryCode* append(const BinaryCode& bc) {
		v_.reserve(v_.size() + bc.size());
		for (int i = 0; i < (int) bc.size(); ++i) {
			v_.push_back(bc.isSet(i));
		}
		return this;
	}

	BinaryCode* append(bool bit) {
		v_.push_back(bit);
		return this;
	}

	BinaryCode* append(char bit) {
		v_.push_back(toBit(bit));
		return this;
	}

	void clear() {
		v_.clear();
	}

	BinaryCode* pop() {
		if (v_.empty())
			throw new std::exception();
		v_.pop_back();
		return this;
	}

	std::string toString() const {
		std::string s;
		int size = (int) v_.size();
		s.reserve(size);
		for (int i = 0; i < size; ++i)
			s.push_back(fromBit(v_[i]));
		return s;
	}

	friend bool operator==(const BinaryCode& a, const BinaryCode& b) {
		return a.v_ == b.v_;
	}

	friend bool operator<(const BinaryCode& a, const BinaryCode& b) {
		return a.v_ < b.v_;
	}

};

class BinaryCodeIterator : public BitIterator {
	BinaryCode bc_;
	int index;
public:
	BinaryCodeIterator(const BinaryCode bc) : bc_(bc) { }
	bool hasNextBit() {
		return index < bc_.size();
	}
	bool nextBit() {
		return bc_.isSet(index++);
	}

	virtual ~BinaryCodeIterator() {
	}

};

#endif
