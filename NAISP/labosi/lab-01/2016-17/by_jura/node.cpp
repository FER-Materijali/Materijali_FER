/*
 * node.cpp
 *
 *  Created on: Nov 3, 2016
 *      Author: Jura
 */

#include "node.h"
#include "cstddef"
using namespace std;
node::node(int number) {
	// TODO Auto-generated constructor stub
	depth = 0;
	value = number;
	left_child = NULL;
	right_child = NULL;
}

node::~node() {
	// TODO Auto-generated destructor stub
}
