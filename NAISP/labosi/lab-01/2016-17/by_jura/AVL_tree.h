/*
 * AVL_tree.h
 *
 *  Created on: Nov 3, 2016
 *      Author: Jura
 */

#ifndef AVL_TREE_H_
#define AVL_TREE_H_
#include "node.h"

class AVL_tree {
public:
	AVL_tree();
	virtual ~AVL_tree();
	node* head;

	/* Add new node to tree
	 * arg1	  - node*  	-> pointer to the passed node
	 * arg2   - int	 	-> value of the new element
	 * return - node* 	-> pointer to the created element
	 */
	node* add_node(node*, int);
	/* Rotate with left node
	 * arg1   - node*   -> pointer to the passed node
	 * return - node*	-> pointer to the node which is now on the same position where passed node previously was
	 */
	node* right_rotation(node*);
	/* Rotate with right node
	 * arg1  - node*	-> pinter to the passed node
	 * return- node*	-> pointer to the node which is now on the same position where passed node previously was
	 */
	node* left_rotation(node*);
	/* When adding new node make head point to the root
	 * arg1  - int 		-> value of new element
	 */
	void add(int);
	/* Calculate height on which the node currently is
	 * arg1  - node* 	-> pointer to the passed node
	 * return- int		-> value of node height
	 */
	int height(node*);
	/* Prints out AVL tree elements
	 * arg1	 - node*	-> root of the AVL tree
	 */
	void preorder(node*);

};

#endif /* AVL_TREE_H_ */
