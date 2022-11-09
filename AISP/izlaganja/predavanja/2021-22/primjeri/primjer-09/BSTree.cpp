// using -std=c++11
#include <algorithm>
#include <cmath>
#include <iostream>
#include <memory>
#include <string>
using namespace std;

template <typename T> struct Node {
   T item;
   shared_ptr<Node<T>> left;
   shared_ptr<Node<T>> right;
   // Node();
   Node(const T &newItem) : item(newItem), left(nullptr), right(nullptr) {}
   ~Node() { std::cout << "Destructor (" << item << ")\n"; }
};

// Base class: binary tree
template <typename T> class BinaryTree {
 public:
   BinaryTree() : root(nullptr) {}
   ~BinaryTree() {}

   // non-virtual functions
   bool isEmpty() const { return (root == nullptr); }

   // non-virtual functions (these functions are independent of the tree nodes
   // order)
   bool isBalanced() { return isBalanced(root); }
   int height() { return height(root); }
   void printTree() { printTree(root); }

   void inorder() { inorder(root); }
   void preorder() { preorder(root); }
   void postorder() { postorder(root); }

   // virtual functions
   virtual void insert(const T &item) = 0;
   virtual bool remove(const T &item) = 0;
   virtual bool search(const T &item) = 0;

 protected:
   shared_ptr<Node<T>> root;

 private:
   bool isBalanced(shared_ptr<Node<T>> &);
   int height(shared_ptr<Node<T>> &);
   void printTree(shared_ptr<Node<T>> &, int level = 0);

   void inorder(shared_ptr<Node<T>> &);
   void preorder(shared_ptr<Node<T>> &);
   void postorder(shared_ptr<Node<T>> &);
};

template <typename T>
bool BinaryTree<T>::isBalanced(shared_ptr<Node<T>> &node) {
   if (node) {
      int heightLeft = height(node->left);
      int heightRight = height(node->right);
      return (std::abs(heightLeft - heightRight) <= 1 &&
              isBalanced(node->left) && isBalanced(node->right));
   }
   return true;
}

template <typename T> int BinaryTree<T>::height(shared_ptr<Node<T>> &node) {
   if (node) {
      int heightLeft = height(node->left);
      int heightRight = height(node->right);
      return (1 + std::max(heightLeft, heightRight));
   }
   return 0;
}

template <typename T>
void BinaryTree<T>::printTree(shared_ptr<Node<T>> &node, int level) {
   if (node) {
      printTree(node->right, level + 1);
      std::string spaces(level * 2, ' ');
      std::cout << spaces << node->item << "\n";
      printTree(node->left, level + 1);
   }
}

template <typename T> void BinaryTree<T>::inorder(shared_ptr<Node<T>> &node) {
   if (node) {
      if (node->left) {
         inorder(node->left);
      }
      std::cout << node->item << " ";
      if (node->right) {
         return inorder(node->right);
      }
   }
}

template <typename T> void BinaryTree<T>::preorder(shared_ptr<Node<T>> &node) {
   if (node) {
      std::cout << node->item << " ";
      if (node->left) {
         preorder(node->left);
      }
      if (node->right) {
         preorder(node->right);
      }
   }
}

template <typename T> void BinaryTree<T>::postorder(shared_ptr<Node<T>> &node) {
   if (node) {
      if (node->left) {
         postorder(node->left);
      }
      if (node->right) {
         postorder(node->right);
      }
      std::cout << node->item << " ";
   }
}

// Derived class: binary search tree
template <typename T> class BSTree : public BinaryTree<T> {
 public:
   BSTree() : BinaryTree<T>::BinaryTree() {}
   ~BSTree() {} // Calling base class destructor?

   // virtual functions
   void insert(const T &item) { insert(this->root, item); }
   bool remove(const T &item) { return remove(this->root, item); }
   bool search(const T &item) { return search(this->root, item); }

 private:
   void insert(shared_ptr<Node<T>> &, const T &);
   bool remove(shared_ptr<Node<T>> &, const T &);
   bool search(shared_ptr<Node<T>> &, const T &);
};

template <typename T>
void BSTree<T>::insert(shared_ptr<Node<T>> &node, const T &newItem) { // Ref?
   if (node) {
      if (node->item < newItem) {
         insert(node->right, newItem);
      } else if (node->item > newItem) {
         insert(node->left, newItem);
      } else {
         throw std::invalid_argument("Error: Item " + std::to_string(newItem) +
                                     " already exists in the tree.");
      }
   } else {
      node = std::make_shared<Node<T>>(newItem);
   }
}

template <typename T>
bool BSTree<T>::search(shared_ptr<Node<T>> &node, const T &item) {
   if (node) {
      if (node->item < item) {
         return search(node->right, item);
      } else if (node->item > item) {
         return search(node->left, item);
      } else { // found item
         return true;
      }
   }
   return false;
}

template <typename T>
bool BSTree<T>::remove(shared_ptr<Node<T>> &node, const T &item) {
   if (node) {
      if (node->item < item) {
         return remove(node->right, item);
      } else if (node->item > item) {
         return remove(node->left, item);
      } else {              // found item
         if (!node->left) { // no left subtree
            node = node->right;
         } else if (!node->right) { // no right subtree
            node = node->left;
         } else {
            shared_ptr<Node<T>> tmp = node->left, prev = nullptr;
            while (tmp->right) { // find the rightmost child in the left subtree
               prev = tmp;
               tmp = tmp->right;
            }
            node->item = tmp->item;
            if (prev)
               prev->right = tmp->left;
            else
               node->left = tmp->left;
         }
         return true;
      }
   }
   return false;
}

int main(void) {
   // int A[] = { 4, -3, 5, -2, -4, 2, 6, -2, 9, 8 };
   int A[] = {4, -3, 5, -2, -4, 2, 6, 9, 8};
   constexpr auto n = sizeof(A) / sizeof(int);

   try {
      BSTree<int> bsTree = BSTree<int>();
      for (int i = 0; i < n; i++) {
         bsTree.insert(A[i]);
      }
      std::cout << "Tree:\n";
      bsTree.printTree();
      std::cout << std::endl;
      std::cout << "Tree height: " << bsTree.height() << "\n";
      bool balanced = bsTree.isBalanced();
      auto str = balanced ? " is " : " isn't ";
      std::cout << "The tree " << str << "balanced.\n\n";

      std::cout << "Tree height: " << bsTree.height() << "\n";

      int item1 = 17, item2 = -2;
      auto found = bsTree.search(item1);
      str = found ? " is " : " isn't ";
      std::cout << item1 << str << "found in the binary tree.\n";

      found = bsTree.search(item2);
      str = found ? " is " : " isn't ";
      std::cout << item2 << str << "found in the binary tree.\n\n";

      item2 = 9;
      found = bsTree.remove(item2);
      str = found ? " is " : " isn't ";
      std::cout << item2 << str << "removed from the binary tree.\n";
      std::cout << "Tree:\n";
      bsTree.printTree();
      std::cout << std::endl;

      std::cout << "Inorder traversal: ";
      bsTree.inorder();
      std::cout << "\n\nPreorder traversal: ";
      bsTree.preorder();
      std::cout << "\n\nPostorder traversal: ";
      bsTree.postorder();
      std::cout << "\n";
   } catch (std::exception &e) {
      std::cerr << e.what();
   }
   std::cin.get();
   return 0;
}
