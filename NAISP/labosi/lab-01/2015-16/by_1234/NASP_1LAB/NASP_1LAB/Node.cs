using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NASP_1LAB
{
    class Node
    {
        public Node parent;

        public int value;

        public int subtreeDepth;
        public int balanceFactor;


        public Node leftChild;
        public Node rightChild;

        private void updateFactorAndDepth()
        {
            if (leftChild == null && rightChild == null)
            {
                subtreeDepth = 1;
                balanceFactor = 0;
            }

            if (parent != null)
            {
                if (this == this.parent.leftChild)
                {
                    if (subtreeDepth >= parent.subtreeDepth)
                    {
                        parent.subtreeDepth += 1;
                    }
                }
                else
                {
                    if (subtreeDepth >= parent.subtreeDepth)
                    {
                        parent.subtreeDepth += 1;
                    }
                }

                parent.updateBalanceFactor();

                if (parent.balanceFactor == -2)
                {
                    if (balanceFactor == -1)
                    {
                        //Console.WriteLine("Prvi i jedini zahtjeva intervenciju:" + parent.value);
                        rightRotation();
                        return;
                    }
                    else if (balanceFactor == 1)
                    {
                        Node r = rightChild;
                        Node q = this;
                        Node p = parent;

                        r.leftRotation();
                        r.rightRotation();
                        return;
                    }
                    
                }
                else if (parent.balanceFactor == 2)
                {
                    if (balanceFactor == 1)
                    {
                        //Console.WriteLine("Prvi i jedini zahtjeva intervenciju:" + parent.value);
                        leftRotation();
                        return;
                    }
                    else if (balanceFactor == -1)
                    {
                        Node r = leftChild;
                        Node q = this;
                        Node p = parent;

                        r.rightRotation();
                        r.leftRotation();
                        return;
                    }
                    
                }
                parent.updateFactorAndDepth();
            }

        }

        private void rightRotation()
        {
            Node ch = this;
            Node par = this.parent;
            Node gr = par.parent;

            if (gr != null)
            {
                if (par == gr.leftChild)
                {
                    gr.leftChild = ch;
                }
                else
                {
                    gr.rightChild = ch;
                }
            }
            ch.parent = gr;
            par.leftChild = ch.rightChild;
            if (ch.rightChild != null)
            {
                ch.rightChild.parent = par;
            }

            ch.rightChild = par;
            par.parent = ch;

            par.updateTreeDepth();
            par.updateBalanceFactor();

            ch.updateTreeDepth();
            ch.updateBalanceFactor();

            if (gr != null)
            {
                gr.updateTreeDepth();
                gr.updateBalanceFactor();
            }
        }

        private void updateTreeDepth()
        {
            int rightDepth = rightChild != null ? rightChild.subtreeDepth : 0;
            int leftDepth = leftChild != null ? leftChild.subtreeDepth : 0;

            if (rightDepth > leftDepth)
            {
                subtreeDepth = rightDepth + 1;
            }
            else
            {
                subtreeDepth = leftDepth + 1;
            }
        }

        private void leftRotation()
        {
            Node ch = this;
            Node par = this.parent;
            Node gr = par.parent;

            if (gr != null)
            {
                if (par == gr.leftChild)
                {
                    gr.leftChild = ch;
                }
                else
                {
                    gr.rightChild = ch;
                }
            }
            ch.parent = gr;
            par.rightChild = ch.leftChild;
            if (ch.leftChild != null)
            {
                ch.leftChild.parent = par;
            }

            ch.leftChild = par;
            par.parent = ch;

            par.updateTreeDepth();
            par.updateBalanceFactor();

            ch.updateTreeDepth();
            ch.updateBalanceFactor();

            if (gr != null)
            {
                gr.updateTreeDepth();
                gr.updateBalanceFactor();
            }
        }

        private void updateBalanceFactor()
        {
            int rightDepth = rightChild != null ? rightChild.subtreeDepth : 0;
            int leftDepth = leftChild != null ? leftChild.subtreeDepth : 0;
            balanceFactor = rightDepth - leftDepth;
        }

        public static void insertNodeAndBalance(ref Node currentNode, int value)
        {
            
            //možda je ono prije isto bilo dobro
            if (currentNode == null)
            {
                Console.WriteLine("Dodan korijen " + value);
                currentNode = new Node();
                currentNode.value = value;
                
            }
            else if (value < currentNode.value)
            {
                if (currentNode.leftChild == null)
                {
                    currentNode.leftChild = new Node();
                    currentNode.leftChild.value = value;
                    currentNode.leftChild.parent = currentNode;

                    Console.WriteLine("Dodan " + currentNode.leftChild.value + " ispod " + currentNode.value);
                    
                    currentNode.leftChild.updateFactorAndDepth();
                }
                else
                {
                    insertNodeAndBalance(ref currentNode.leftChild, value);
                }
            }
            else
            {
                if (currentNode.rightChild == null)
                {
                    currentNode.rightChild = new Node();
                    currentNode.rightChild.value = value;
                    currentNode.rightChild.parent = currentNode;

                    Console.WriteLine("Dodan " + currentNode.rightChild.value + " ispod " + currentNode.value);
                    
                    currentNode.rightChild.updateFactorAndDepth();
                }
                else
                {
                    insertNodeAndBalance(ref currentNode.rightChild, value);
                }
            }

        }
        
        public Node findMaximum()
        {
            Node current = this;
            while (current.rightChild != null)
            {
                current = current.rightChild;
            }
            return current;
        }

        public static Node getRoot(Node root)
        {
            if (root == null)
            {
                return null;
            }
            else if (root.parent != null)
            {
                return Node.getRoot(root.parent);
            }
            else
            {
                return root;
            }
        }

        public static void deleteByCopying(Node root, int valueToDelete)
        {
            Node nodeToDelete = root;
            while (nodeToDelete.value != valueToDelete)
            {
                if (nodeToDelete.leftChild == null && nodeToDelete.rightChild == null)
                {
                    Console.WriteLine("Node to delete not found!");
                    return;
                }

                if (valueToDelete < nodeToDelete.value)
                {
                    nodeToDelete = nodeToDelete.leftChild;
                }
                else if (valueToDelete > nodeToDelete.value)
                {
                    nodeToDelete = nodeToDelete.rightChild;
                }

            }
            Console.WriteLine("Deleting node "+nodeToDelete.value);

            Node nodeToUpdateFrom = null;
            if (nodeToDelete.leftChild != null && nodeToDelete.rightChild != null)//ako ima oba djeteta
            {
                Node replacementNode = nodeToDelete.leftChild.findMaximum();//sigurno nema desno dijete, lijevo ima ili je null
                
                nodeToDelete.value = replacementNode.value;

                Node replacementNodeParent = replacementNode.parent;
                if (replacementNode == replacementNode.parent.rightChild)
                {
                    replacementNode.parent.rightChild = replacementNode.leftChild; //zamjenski čvor: njegovom roditelju je desno dijete, dok on može imati samo lijevo
                    
                    if(replacementNode.leftChild != null)
                        replacementNode.leftChild.parent = replacementNodeParent;
                }
                else
                {
                    replacementNode.parent.leftChild = replacementNode.leftChild;

                    if (replacementNode.leftChild != null)
                        replacementNode.leftChild.parent = replacementNodeParent;
                    
                }

                nodeToUpdateFrom = replacementNode.parent;//funkcija updatea tek od roditelja
            }
            else
            {
                Node childNode = nodeToDelete.leftChild != null ? nodeToDelete.leftChild : nodeToDelete.rightChild;
                if (nodeToDelete.parent != null)
                {
                    if (nodeToDelete == nodeToDelete.parent.rightChild)//exception ovdje znači da se briše korijen
                    {
                        nodeToDelete.parent.rightChild = childNode; //zamjenski čvor: njegovom roditelju je desno dijete, dok on može imati samo lijevo

                    }
                    else
                    {
                        nodeToDelete.parent.leftChild = childNode;
                    }
                }

                if (childNode != null)
                {
                    childNode.parent = nodeToDelete.parent;
                }

                if (nodeToDelete.parent != null)
                {
                    nodeToUpdateFrom = nodeToDelete.parent;//funkcija updatea tek od roditelja
                }
                else
                {
                    nodeToDelete.value = childNode.value;
                    nodeToDelete.leftChild = childNode.leftChild;
                    nodeToDelete.rightChild = childNode.rightChild;
                    nodeToUpdateFrom = nodeToDelete;
                }
            }
            nodeToUpdateFrom.updateFactorAndDepthDeleting();
        }

        private void updateFactorAndDepthDeleting()
        {
            if (leftChild == null && rightChild == null)
            {
                subtreeDepth = 1;
                balanceFactor = 0;
            }

            int leftDepth = leftChild != null ? leftChild.subtreeDepth : 0;
            int rightDepth = rightChild != null ? rightChild.subtreeDepth : 0;

            if (leftDepth > rightDepth)
            {
                subtreeDepth = leftDepth + 1;
            }
            else
            {
                subtreeDepth = rightDepth + 1;
            }

            updateBalanceFactor();

            if (balanceFactor == -1 || balanceFactor == 1)
            {
                return;
            }
            else if (balanceFactor == 0)
            {
                if (parent != null)
                {
                    parent.updateFactorAndDepthDeleting();
                }
            }
            else if (balanceFactor == -2)
            {
                if (leftChild.balanceFactor == -1 || leftChild.balanceFactor == 0)
                {
                    leftChild.rightRotation();
                }
                else if (leftChild.balanceFactor == 1)
                {
                    Node r = leftChild.rightChild;
                    Node q = leftChild;
                    Node p = this;

                    r.leftRotation();
                    r.rightRotation();
                }

                if (balanceFactor == -1 || balanceFactor == 1)
                {
                    return;
                }

            }
            else if (balanceFactor == 2)
            {
                if (rightChild.balanceFactor == 1 || rightChild.balanceFactor == 0)
                {
                    rightChild.leftRotation();
                }
                else if (rightChild.balanceFactor == -1)
                {
                    Node r = rightChild.leftChild;
                    Node q = rightChild;
                    Node p = this;

                    r.rightRotation();
                    r.leftRotation();
                }

                if (balanceFactor == -1 || balanceFactor == 1)
                {
                    return;
                }
            }
            /*if (parent != null)
            {
                parent.updateFactorAndDepthDeleting();
            }*/
            
        }

        public static void print(Node root, int level)
        {
            if (root == null)
            {
                Console.WriteLine("Korijen stabla je null");
                return;
            }

            string space = "";
            for (int i = 0; i < level; i++)
            {
                space = space + "\t";
            }

            if (root.rightChild != null)
            {
                Node.print(root.rightChild, level + 1);
            }

            string parentString = (root.parent != null) ? " P:" + root.parent.value : " NoP";
            Console.WriteLine(space + "V:" + root.value + " D:" + root.subtreeDepth + " FR:" + root.balanceFactor + parentString);
            //if (Math.Abs(root.balanceFactor) == 2) Console.WriteLine("ERROR, TREE IS NOT BALANCED");

            if (root.leftChild != null)
            {
                Node.print(root.leftChild, level + 1);
            }

        }

        public static void Preorder(Node root)
        {
            if (root != null)
            {
                Console.Write(root.value + " ");
                Preorder(root.leftChild);
                Preorder(root.rightChild);
            }
        }
        public static void Inorder(Node root)
        {
            if (root != null)
            {
                Inorder(root.leftChild);
                Console.Write(root.value + " ");
                Inorder(root.rightChild);
            }
        }
        public static void Postorder(Node root)
        {
            if (root != null)
            {
                Postorder(root.leftChild);
                Postorder(root.rightChild);
                Console.Write(root.value + " ");
            }
        }
    }
}
