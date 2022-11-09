// using -std=c++11
#include <algorithm>
#include <cmath>
#include <iostream>
#include <memory>
#include <string>
using std::shared_ptr;

template <typename T> class BinaryTree {
 public:
   BinaryTree() : root(nullptr) {}
   ~BinaryTree() {}

   bool isEmpty() const { return (root == nullptr); }

   void insert(const T &item) { insert(root, item); }
   bool remove(const T &item) { return remove(root, item); }
   bool search(const T &item) { return search(root, item); }
   bool balanced() { return balanced(root); }

   void inorder() { inorder(root); }
   void preorder() { preorder(root); }
   void postorder() { postorder(root); }
   void printTree() { printTree(root); }

   int height() { return height(root); }
   bool operator==(BinaryTree<T> &b) { return compare(root, b.root); }
   int nodes() { return nodes(root); }
   void mirror() { return mirror(root); }

 protected:
   struct Node {
      T item;
      shared_ptr<Node> left;
      shared_ptr<Node> right;
      // Node();
      Node(const T &newItem) : item(newItem), left(nullptr), right(nullptr) {}
      ~Node() { std::cout << "Destructor (" << item << ")\n"; }
   };

   shared_ptr<Node> root;
   void insert(shared_ptr<Node> &, const T &);
   bool remove(shared_ptr<Node> &, const T &);
   bool search(shared_ptr<Node> &, const T &);
   bool balanced(shared_ptr<Node> &);

   void inorder(shared_ptr<Node> &);
   void preorder(shared_ptr<Node> &);
   void postorder(shared_ptr<Node> &);
   void printTree(shared_ptr<Node> &, int level = 0);
   int height(shared_ptr<Node> &);
   bool compare(shared_ptr<Node> &, shared_ptr<Node> &);
   int nodes(shared_ptr<Node> &);
   void mirror(shared_ptr<Node> &);
};

template <typename T>
void BinaryTree<T>::insert(shared_ptr<Node> &node, const T &newItem) {
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
      node = std::make_shared<Node>(newItem);
   }
}

template <typename T>
bool BinaryTree<T>::search(shared_ptr<Node> &node, const T &item) {
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
bool BinaryTree<T>::remove(shared_ptr<Node> &node, const T &item) {
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
            shared_ptr<Node> tmp = node->left, prev = nullptr;
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

template <typename T> bool BinaryTree<T>::balanced(shared_ptr<Node> &node) {
   if (node) {
      int heightLeft = height(node->left);
      int heightRight = height(node->right);
      return std::abs(heightLeft - heightRight) <= 1.0 &&
             balanced(node->left) && balanced(node->right);
   }
   return true;
}

template <typename T> void BinaryTree<T>::inorder(shared_ptr<Node> &node) {
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

template <typename T> void BinaryTree<T>::preorder(shared_ptr<Node> &node) {
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

template <typename T> void BinaryTree<T>::postorder(shared_ptr<Node> &node) {
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

template <typename T>
void BinaryTree<T>::printTree(shared_ptr<Node> &node, int level) {
   if (node) {
      printTree(node->right, level + 1);
      std::string spaces(level * 2, ' ');
      std::cout << spaces << node->item << "\n";
      printTree(node->left, level + 1);
   }
}

template <typename T> int BinaryTree<T>::height(shared_ptr<Node> &node) {
   if (node) {
      int heightLeft = height(node->left);
      int heightRight = height(node->right);
      return (1 + std::max(heightLeft, heightRight));
   }
   return 0;
}

template <typename T>
bool BinaryTree<T>::compare(shared_ptr<Node> &a, shared_ptr<Node> &b) {
   if (a == nullptr && b == nullptr)
      return true;
   if (a == nullptr && b != nullptr)
      return false;
   if (a != nullptr && b == nullptr)
      return false;
   if (a->item != b->item)
      return false;
   return compare(a->left, b->left) && compare(a->right, b->right);
}

template <typename T> int BinaryTree<T>::nodes(shared_ptr<Node> &root) {
   if (root == nullptr)
      return 0;
   return nodes(root->left) + 1 + nodes(root->right);
}

template <typename T> void BinaryTree<T>::mirror(shared_ptr<Node> &root) {
   if (root == nullptr)
      return;
   shared_ptr<Node> tmp = root->left;
   root->left = root->right;
   root->right = tmp;
   mirror(root->left);
   mirror(root->right);
}

int main(void) {
   // int A[] = { 4, -3, 5, -2, -14, 2, 6, -12, 9, 8 };
   int A[] = {4, -3, 5, -2, -4, 2, 6, 9, 8};
   constexpr auto n = sizeof(A) / sizeof(int);

   try {
      BinaryTree<int> bTree = BinaryTree<int>();
      for (int i = 0; i < n; i++) {
         bTree.insert(A[i]);
      }

      BinaryTree<int> otherTree = BinaryTree<int>();
      for (int i = 0; i < n; i++) {
         otherTree.insert(A[i]);
      }
      std::cout << "Tree:\n";
      bTree.printTree();
      std::cout << std::endl;
      std::cout << "Nodes: " << bTree.nodes();

      std::cout << (bTree == otherTree) << std::endl;

      std::cout << "Tree height: " << bTree.height() << "\n";
      bool balanced = bTree.balanced();
      auto str = balanced ? " is " : " isn't ";
      std::cout << "The tree " << str << "balanced.\n\n";

      std::cout << "Tree height: " << bTree.height() << "\n";

      int item1 = 17, item2 = -2;
      auto found = bTree.search(item1);
      str = found ? " is " : " isn't ";
      std::cout << item1 << str << "found in the binary tree.\n";

      found = bTree.search(item2);
      str = found ? " is " : " isn't ";
      std::cout << item2 << str << "found in the binary tree.\n\n";

      // found = bTree.remove(item2);
      // str = found ? " is " : " isn't ";
      // std::cout << item2 << str << "removed from the binary tree.\n";
      // std::cout << "Tree:\n";
      // bTree.printTree();
      // std::cout << std::endl;

      item2 = 9;
      found = bTree.remove(item2);
      str = found ? " is " : " isn't ";
      std::cout << item2 << str << "removed from the binary tree.\n";
      std::cout << "Tree:\n";
      bTree.printTree();
      std::cout << std::endl;

      std::cout << "Inorder traversal: ";
      bTree.inorder();
      std::cout << "\n\nPreorder traversal: ";
      bTree.preorder();
      std::cout << "\n\nPostorder traversal: ";
      bTree.postorder();
      std::cout << "\n";

      std::cout << "Tree:\n";
      bTree.printTree();
      std::cout << "Other tree:\n";
      otherTree.printTree();
      std::cout << (bTree == otherTree) << std::endl;

      std::cout << "Mirrored other tree:\n";
      otherTree.mirror();
      otherTree.printTree();

   } catch (std::exception &e) {
      std::cerr << e.what();
   }
   std::cin.get();
   return 0;
}
