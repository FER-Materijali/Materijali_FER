package hr.fer.oop.lab2.prob2;

class TreeNode {
	TreeNode left;
	TreeNode right;
	String data;
}

/**
 * This program is run with no arguments.
 * 
 * @author dinomario10
 */
public class TreeProgram {

	public static void main(String[] args) {
		TreeNode node = null;
		node = insert(node, "Jasna");
		node = insert(node, "Ana");
		node = insert(node, "Ivana");
		node = insert(node, "Anamarija");
		node = insert(node, "Vesna");
		node = insert(node, "Kristina");

		System.out.println("Writing tree inorder:");
		writeTree(node);

		node = reverseTreeOrder(node);

		System.out.println("Writing reversed tree inorder:");
		writeTree(node);

		int size = sizeOfTree(node);
		System.out.println("Number of nodes in tree is " + size + ".");

		boolean found = containsData(node, "Ivana");
		System.out.println("Searched element is found: " + found);
	}

	/**
	 * Returns true if given string of data is found in an ordered binary tree.
	 * 
	 * @param treeRoot tree root
	 * @param data data that is searched
	 * @return true if data is found, false otherwise
	 */
	static boolean containsData(TreeNode treeRoot, String data) {
		if (treeRoot == null) {
			return false;
		} else {
			if (data.compareTo(treeRoot.data) == 0) {
				return true;
			} else {
				if (data.compareTo(treeRoot.data) < 0) {
					return containsData(treeRoot.left, data);
				} else {
					return containsData(treeRoot.right, data);
				}
			}
		}
	}

	/**
	 * Returns true if given string of data is found in a tree. The tree
	 * does not have to be ordered.
	 * 
	 * @param treeRoot tree root
	 * @param data data that is searched
	 * @return true if data is found, false otherwise
	 */
	static boolean containsData2(TreeNode treeRoot, String data) {
		if (treeRoot == null) {
			return false;
		} else {
			if (data.compareTo(treeRoot.data) == 0) {
				return true;
			} else {
				return containsData2(treeRoot.left, data) || containsData2(treeRoot.right, data);
			}
		}
	}

	/**
	 * Returns the number of nodes in a tree.
	 * 
	 * @param treeRoot tree root
	 * @return number of nodes
	 */
	static int sizeOfTree(TreeNode treeRoot) {
		if (treeRoot == null) {
			return 0;
		} else {
			int leftSideSize = sizeOfTree(treeRoot.left);
			int rightSideSize = sizeOfTree(treeRoot.right);
			return leftSideSize + rightSideSize + 1;
		}
	}

	/**
	 * Returns the inserted tree node containing data that was passed
	 * as an argument, sorting the tree in order.
	 * 
	 * @param treeRoot tree root
	 * @param data data to be inserted
	 * @return newly inserted tree node
	 */
	static TreeNode insert(TreeNode treeRoot, String data) {
		if (treeRoot == null) {
			return NewTreeNode(data);
		} else if (data.compareTo(treeRoot.data) <= 0) {
			treeRoot.left = insert(treeRoot.left, data);
		} else {
			treeRoot.right = insert(treeRoot.right, data);
		}
		return treeRoot;
	}

	/**
	 * Returns a new {@code TreeNode} class tree node after allocating memory.
	 * 
	 * @param data tree node data
	 * @return newly created tree node
	 */
	static TreeNode NewTreeNode(String data) {
		TreeNode treeRoot = new TreeNode();
		treeRoot.data = data;
		treeRoot.left = null;
		treeRoot.right = null;
		return treeRoot;
	}

	/**
	 * Prints tree inorder on the standard output.
	 * 
	 * @param treeRoot tree root
	 */
	static void writeTree(TreeNode treeRoot) {
		if (treeRoot != null) {
			writeTree(treeRoot.left);
			System.out.println(treeRoot.data);
			writeTree(treeRoot.right);
		}
		return;
	}

	/**
	 * Returns the tree root for the reversed tree order where children bigger
	 * than the parent node go to the left, and children smaller then the parent
	 * node go to the right.
	 * 
	 * @param treeRoot tree root
	 * @return tree root for the reversed tree
	 */
	static TreeNode reverseTreeOrder(TreeNode treeRoot) {
		if (treeRoot != null) {
			TreeNode temp = treeRoot.left;
			treeRoot.left = reverseTreeOrder(treeRoot.right);
			treeRoot.right = reverseTreeOrder(temp);
		}
		return treeRoot;
	}

	/*
	static boolean remove(TreeNode treeRoot, String data) {
		if (treeRoot == null) {
            return false;
        }
		if (data.compareTo(treeRoot.data) == 0) {
			if (treeRoot.left == null && treeRoot.right == null) {
				// leaf node
			    treeRoot = null;
			    return true;
			} else if (treeRoot.left == null) {
				// node with only right child
			    treeRoot = treeRoot.right;
			    treeRoot.right = null;
			    return true;
			} else if (treeRoot.right == null) {
				// node with only left child
			    treeRoot = treeRoot.left;
			    treeRoot.left = null;
			    return true;
			} else {
				// node with two children
				treeRoot = treeRoot.left;
				treeRoot.left = null;
				
				return true;
			}
		} else if (data.compareTo(treeRoot.data) <= 0) {
			return remove(treeRoot.left, data);
		} else {
			return remove(treeRoot.right, data);
		}
	}
	*/
}
