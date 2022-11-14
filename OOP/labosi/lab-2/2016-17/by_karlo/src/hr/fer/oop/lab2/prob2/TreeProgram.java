package hr.fer.oop.lab2.prob2;

/**
 * A struct which represents a binary tree node.
 * 
 * @author karlo
 *
 */
class TreeNode {
	TreeNode left;
	TreeNode right;
	String data;

	TreeNode(String data) {
		this.data = data;
		left = null;
		right = null;
	}
}

/**
 * Program which uses the binary tree implenentation of a list.
 * 
 * @author karlo
 *
 */
class TreeProgram {

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

		boolean found0 = containsData(node, "Ivana");
		System.out.println("Searched element is found: " + found0);

		node = reverseTreeOrder(node);

		System.out.println("Writing reversed tree inorder:");
		writeTree(node);

		int size = sizeOfTree(node);
		System.out.println("Number of nodes in tree is " + size + ".");

		boolean found = containsData(node, "Ivana");
		System.out.println("Searched element is found: " + found);

		boolean found2 = containsData2(node, "Ivana");
		System.out.println("Searched element is found: " + found2);
	}

	/**
	 * Returns true if given string of data is found in an ordered binary tree.
	 * 
	 * @param treeRoot
	 *            tree root
	 * @param data
	 *            data that is searched
	 * @return true if data is found, false otherwise
	 */
	static boolean containsData(TreeNode treeRoot, String data) {
		if (treeRoot == null) {
			return false;
		} else {
			if (data.compareTo(treeRoot.data) == 0) {
				return true;
			} else {
				return data.compareTo(treeRoot.data) < 0 ? containsData(treeRoot.left, data)
						: containsData(treeRoot.right, data);
			}
		}
	}

	/**
	 * Returns true if given string of data is found in a tree. The tree does
	 * not have to be ordered.
	 * 
	 * @param treeRoot
	 *            tree root
	 * @param data
	 *            data that is searched
	 * @return true if data is found, false otherwise
	 */
	static boolean containsData2(TreeNode treeRoot, String data) {
		if (treeRoot == null)
			return false;
		else {
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
	 * @param treeRoot
	 *            tree root
	 * @return number of nodes
	 */
	static int sizeOfTree(TreeNode treeRoot) {
		return treeRoot != null ? 1 + sizeOfTree(treeRoot.left) + sizeOfTree(treeRoot.right) : 0;
	}

	/**
	 * Returns the inserted tree node containing data that was passed as an
	 * argument, sorting the tree inorder, i.e value on the left is smaller than
	 * the value on the right.
	 * 
	 * @param treeRoot
	 *            tree root
	 * @param data
	 *            data to be inserted
	 * @return newly inserted tree node
	 */
	static TreeNode insert(TreeNode treeRoot, String data) {
		if (treeRoot == null) {
			return new TreeNode(data);
		} else {
			if (data.compareTo(treeRoot.data) <= 0) {
				treeRoot.left = insert(treeRoot.left, data);
			} else {
				treeRoot.right = insert(treeRoot.right, data);
			}

			return treeRoot;
		}
	}

	/**
	 * Prints tree inorder using the standard output.
	 * 
	 * @param treeRoot
	 *            tree root
	 */
	static void writeTree(TreeNode treeRoot) {
		if (treeRoot != null) {
			writeTree(treeRoot.left);
			System.out.println(treeRoot.data);
			writeTree(treeRoot.right);
		}
	}

	/**
	 * Returns the tree root for the reversed tree order where children that are
	 * bigger than the parent node go to the left, and children smaller then the
	 * parent node go to the right.
	 * 
	 * @param treeRoot
	 *            tree root
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
}