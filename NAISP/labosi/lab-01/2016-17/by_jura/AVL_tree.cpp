/*
 * AVL_tree.cpp
 *
 *  Created on: Nov 5, 2016
 *      Author: Jura
 */

#include "AVL_tree.h"
#include "node.h"
#include "string.h"
#include "iostream"
#include "fstream"
#include "assert.h"
#include "vector"
#include "cstddef"
#include <stdlib.h>
#include <algorithm>
using namespace std;

AVL_tree::AVL_tree() {
	// TODO Auto-generated constructor stub
	head = NULL;	// when created head points to nothing
}

AVL_tree::~AVL_tree() {
	// TODO Auto-generated destructor stub
	head = NULL;	// when destroyed head points to nothing
}

void AVL_tree::add(int element)
{
	// add node and make head point to root
	head = add_node(head, element);
}

void AVL_tree::preorder(node* nodee)
{
	if (nodee == NULL)
	{
		return;
	}
	printf("%d ", nodee->value);
	preorder(nodee->left_child);
	preorder(nodee->right_child);
}

int AVL_tree::height(node* nodee)
{
	// if node exists return its depth
	if(nodee == NULL)
	{
		return -1;
	}
	else
	{
		return nodee->depth;
	}
}

node* AVL_tree::add_node(node* nodee, int element){
	// if node on passed address doesn't exist create one
	if (nodee == NULL)
	{
		nodee = new node(element);
	}
	// enter if new element has lower value than existing one add his child
	else if(element < nodee->value)
	{
		//call add_node for left child
		nodee->left_child = add_node(nodee->left_child, element);
		// if left sub-tree has 2 more elements than right sub-tree...
		if(height(nodee->left_child) - height(nodee->right_child) == 2)
		{
			// ... check if double rotation needs to be done
			if(element <= nodee->left_child->value)
			{
				nodee = right_rotation(nodee);
			}
			else
			{
				//double rotation
				nodee->left_child = left_rotation(nodee->left_child);
				nodee = right_rotation(nodee);
			}
		}
	}
	// enter if new element has higher value than existing one add his child
	else if(element > nodee->value)
	{
		//analog to previous else if
		nodee->right_child = add_node(nodee->right_child, element);
		if(height(nodee->right_child) - height(nodee->left_child) == 2)
		{
			if(element > nodee->right_child->value)
			{
				nodee = left_rotation(nodee);
			}
			else
			{
				nodee->right_child = right_rotation(nodee->right_child);
				nodee = left_rotation(nodee);
			}
		}
	}
	// refresh node depth for future balance factor calculations
	nodee->depth = max(height(nodee->left_child), height(nodee->right_child)) + 1;
	return nodee;
}

node* AVL_tree::right_rotation(node* nodee){
	// create new help node
	node* leftChild = nodee->left_child;

	// if nodee's doesn't have left child point nodee to NULL, else point nodee to his left child's right child
	nodee->left_child = (leftChild == NULL ? NULL : leftChild->right_child);

	// if nodee's ex left child isn't null point him to his ex parent
	// also refresh depth
	if (leftChild != NULL)
	{
		leftChild->right_child = nodee;
		leftChild->depth = max(height(leftChild->left_child), height(nodee)) + 1;
	}
	nodee->depth = max(height(nodee->left_child), height(nodee->right_child)) + 1;
	// if nodee's left child is null return nodee, else return his ex child
	if (leftChild == NULL)
	{
		return nodee;
	}
	return leftChild;
}

node* AVL_tree::left_rotation(node* nodee){
	// analog to right rotation
	node* rightChild = nodee->right_child;
	nodee->right_child = (rightChild == NULL ? NULL : rightChild->left_child);

	if (rightChild != NULL)
	{
		rightChild->left_child = nodee;
		rightChild->depth = max(height(rightChild->right_child), height(nodee)) + 1;
	}
	nodee->depth = max(height(nodee->left_child), height(nodee->right_child)) + 1;

	if (rightChild == NULL)
	{
		return nodee;
	}
	return rightChild;
}

int main(int argc, char* argv[])
{
	ifstream inputFile;
	vector<int> elementList;

	//open filestream
	inputFile.open(argv[1], fstream::in);
	assert(inputFile.is_open());

	//read file char by char into vector
	while(!inputFile.eof() || !inputFile.fail())
	{
		string buffer;
		getline(inputFile, buffer);
		elementList.push_back(atoi(buffer.c_str()));
	}

	//.txt line terminator generates one more while loop which appends 1 extra element to vector
	elementList.erase(elementList.end()-1, elementList.end());

	//create head and its element
	AVL_tree* tree = new AVL_tree();
	tree->head = new node(elementList[0]);

	// add all other elements to the tree
	for (vector<int>::iterator it = elementList.begin()+1; it!=elementList.end(); it++)
	{
		tree->add(*it);
	}

	//printf in preorder mode
	cout << "ispis preorder: \n";
	tree->preorder(tree->head);

	//infinite loop
	while(1)
	{
		//input any new number in integer range
		string newLine;
		cout << "\n\nUpisite novi element: ";
		cout << "\n Write 'e' to exit \n";
		cin >> newLine;
		int newElement = atoi(newLine.c_str());
		cout << "\n";
		if (newLine[0] == 'e') break;
		tree->add(newElement);
		cout << "Ispis preorder: \n";
		tree->preorder(tree->head);
	}
	// clean memory
	delete (AVL_tree *)tree;
	return 0;
}
