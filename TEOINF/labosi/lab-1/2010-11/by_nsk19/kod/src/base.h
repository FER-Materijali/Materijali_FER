/*
 * base.h
 *
 *  Created on: Dec 24, 2010
 *      Author: Leo Osvald
 */

#ifndef BASE_H_
#define BASE_H_

#define FOREACH(it, c) for (__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

#include <map>

typedef std::map<char, double> ProbabilityMap;

static bool toBit(char bit) {
	if (bit < '0' || bit > '1')
		throw std::exception();
	return bit - '0';
}

static char fromBit(bool bit) {
	return bit + '0';
}

static bool isEndline(char c) {
	return c == '\n' || c == '\r';
}

#endif /* BASE_H_ */
