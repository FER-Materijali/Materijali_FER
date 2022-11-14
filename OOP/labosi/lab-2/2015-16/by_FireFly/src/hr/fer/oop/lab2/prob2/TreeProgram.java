package hr.fer.oop.lab2.prob2;

class TreeNode {
	TreeNode left;
	TreeNode right;
	String data;
}
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
		node = reverseTreeOrder(node);
		System.out.println("Writing reversed tree inorder:");
		writeTree(node);
		int size = sizeOfTree(node);
		System.out.println("Number of nodes in tree is "+size+".");
		boolean found = containsData(node, "Ivana");
		System.out.println("Searched element is found: "+found);
 }
 //-----------------------------------------------------------------------------------------------------------------------
 static boolean containsData(TreeNode treeRoot, String data) {
	 if(treeRoot == null)
             return false;
         if(data.equals(treeRoot.data))
             return (true);
         else if((data.compareTo(treeRoot.data))<0)
             return(containsData(treeRoot.left, data));
         else
             return(containsData(treeRoot.right, data));
                 
}
//-----------------------------------------------------------------------------------------------------------------------
 static int sizeOfTree(TreeNode treeRoot) {
 	if(treeRoot == null) 
            return (0);
 	else
 		return (sizeOfTree(treeRoot.left) + 1 + sizeOfTree(treeRoot.right));
 }
 //-----------------------------------------------------------------------------------------------------------------------
 static TreeNode insert(TreeNode treeRoot, String data) {
	 if(treeRoot == null){ 
		 treeRoot = new TreeNode ();
                 treeRoot.data = data;
	 }
         else{
             if((data.compareTo(treeRoot.data))<0)
                 treeRoot.left = insert(treeRoot.left,data);
             else
                 treeRoot.right = insert(treeRoot.right, data);
         }
         return treeRoot;
 }
//-----------------------------------------------------------------------------------------------------------------------
 static void writeTree(TreeNode treeRoot) {
        if (treeRoot==null){
            return;
        }
        writeTree(treeRoot.left);
        System.out.println("TreeNode Data: " +treeRoot.data);
        writeTree(treeRoot.right);	
}
//-----------------------------------------------------------------------------------------------------------------------
 static TreeNode reverseTreeOrder(TreeNode treeRoot) {
        if(treeRoot==null)
            return null;
        TreeNode temp = new TreeNode();
        temp = treeRoot.left;
        treeRoot.left = treeRoot.right;
        treeRoot.right = temp;
        
        reverseTreeOrder(treeRoot.left);
        reverseTreeOrder(treeRoot.right);
        return treeRoot;
    }
//-----------------------------------------------------------------------------------------------------------------------
static boolean containsData2(TreeNode treeRoot,String data){
        if (treeRoot != null){
        if (treeRoot.data.contains(data)){
            return true;
        }
        else{
            return containsData2(treeRoot.left,data) || containsData2(treeRoot.right,data);	
        }
    }
    return false;	
  }

}