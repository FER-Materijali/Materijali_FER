/*
 * source_properties.cpp
 *
 *  Created on: Dec 24, 2010
 *      Author: Leo Osvald
 */

#include "source_properties.h"

namespace source {

SourceProperties SourceProperties::INSTANCE;

const ProbabilityMap& symbol_probabilities() {
	return SourceProperties::INSTANCE.symbol_probabilities();
}

}
