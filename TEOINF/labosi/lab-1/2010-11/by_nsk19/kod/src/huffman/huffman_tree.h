/*
 * huffman_tree.h
 *
 *  Created on: Dec 24, 2010
 *      Author: Leo Osvald
 */

#ifndef HUFFMAN_TREE_H_
#define HUFFMAN_TREE_H_

#include <cstddef>

#include <set>

namespace entropycoding {

class HuffmanTree {

public:
	class Node;
private:
	Node* root_;
	struct Comparator;

	void destroy(const Node *node) {
		if (node == NULL)
			return ;
		if (node->left_child() != NULL)
			destroy(node->left_child());
		if (node->right_child() != NULL)
			destroy(node->right_child());
		delete node;
	}

public:

	static Node* extractMin(std::multiset<Node*, Comparator>& min_queue) {
		std::multiset<Node*, Comparator>::iterator it = min_queue.begin();
		Node* ret = *it;
		min_queue.erase(it);
		return ret;
	}

	HuffmanTree(const ProbabilityMap& symbol_probabilities) {
		using namespace std;

		// prioritetni red ostvaren preko crveno-crnog stabla
		// prioritet je definiran komparatorom (vidi komparator)
		multiset<Node*, Comparator> priority_queue;
		FOREACH (it, symbol_probabilities) {
			priority_queue.insert(new Node(it->first, it->second));
		}

		// OPREZ: poseban slucaj ako je 1 simbol - tad stvaramo 2 ista cvora
		if (priority_queue.size() == 1) {
			Node* node = *priority_queue.begin();
			priority_queue.insert(new Node(node->symbol(), 0));
		}

		root_ = NULL;
		while (priority_queue.size() > 1U) {
			// uzmi dva cvora iz prioritetnog reda s najmanjom vjerojatnoscu
			Node* min1 = extractMin(priority_queue);
			Node* min2 = extractMin(priority_queue);
			// i dodijeli im zajednickog roditelja (koji je korijen stabla)
			// koji ima vjerojatnost jednak zbroju vjerojatnosti djece
			root_ = new Node(min1, min2);
			priority_queue.insert(root_);
		}

	}

	const Node* root() const {
		return root_;
	}

	virtual ~HuffmanTree() {
		destroy(root_);
	}

	class Node {
		const char symbol_;
		const double probability_;
		const Node* const left_;
		const Node* const right_;

	public:

		Node(char symbol, double probability)
		: symbol_(symbol), probability_(probability),
		  left_(NULL), right_(NULL) {
		}

		Node(const Node* child1, const Node* child2)
		: symbol_(0), probability_(child1->probability_ + child2->probability_),
		  left_(child1), right_(child2) {
		}

		char symbol() const {
			return symbol_;
		}

		double probability() const {
			return probability_;
		}

		const Node* left_child() const {
			return left_;
		}

		const Node* right_child() const {
			return right_;
		}

		const Node* child(bool right) const {
			return right ? right_ : left_;
		}

		bool isLeaf() const {
			return left_ == NULL && right_ == NULL;
		}

		friend class Comparator;
	};

private:

	// usporedjuje cvorove prvo po vjerojatnosti pa po znaku
	struct Comparator {
		bool operator()(const Node* a, const Node* b) {
			if (a->probability_ != b->probability_)
				return a->probability_ < b->probability_;
			return a->symbol_ < b->symbol_;
		}
	};

};

}

#endif /* HUFFMAN_TREE_H_ */
