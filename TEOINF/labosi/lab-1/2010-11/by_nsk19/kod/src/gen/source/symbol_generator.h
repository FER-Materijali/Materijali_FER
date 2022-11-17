/*
 * symbol_generator.h
 *
 *  Created on: Dec 24, 2010
 *      Author: Leo Osvald
 */

#ifndef SYMBOL_GENERATOR_H_
#define SYMBOL_GENERATOR_H_

#include "../random_utils.h"
#include "../../source_properties.h"

namespace source {

	class SymbolGenerator {
	private:
		RandomUtils::DiscreteRandomVariable<char> var_;
	public:

		SymbolGenerator(const ProbabilityMap& symbol_probabilities) : var_(0) {
			FOREACH (it, symbol_probabilities) {
				var_.add(it->first, it->second);
			}
		}

		char get() const {
			return var_.get();
		}

	};

}

#endif /* SYMBOL_GENERATOR_H_ */
