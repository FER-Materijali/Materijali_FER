/*
 * node.h
 *
 *  Created on: Nov 3, 2016
 *      Author: Jura
 */

#ifndef NODE_H_
#define NODE_H_

using namespace std;

class node {
public:
	node(int number);
	virtual ~node();

	node* left_child;	// left child of AVL node
	node* right_child;	// left child of AVL node

	int depth; 			// depth of the node
	int value;			// value of the node contains
};

#endif /* NODE_H_ */
