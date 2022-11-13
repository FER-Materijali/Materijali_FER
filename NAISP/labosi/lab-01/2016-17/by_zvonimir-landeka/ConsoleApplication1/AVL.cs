using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    class AVL
    {
        private cvor root;


        public void add(int data)
        {
            root = insert(root, data);
        }

        public void preOrder()
        {
            Console.WriteLine("Ispis preOrder");
            root.preOrder();
        }

        public cvor insert(cvor cvor, int element)
        {
            if (cvor == null)
            {
                cvor = new cvor(element);
            }
            else if (element < cvor.Vrijednost)
            {
                cvor.LeftChild = insert(cvor.LeftChild, element);
                if (height(cvor.LeftChild) - height(cvor.RightChild) == 2)
                {
                    if (element < cvor.LeftChild.Vrijednost)
                    {
                        cvor = RightRotation(cvor);
                    }
                    else
                    {
                        cvor.LeftChild = leftRotation(cvor.LeftChild);
                        cvor = RightRotation(cvor);
                    }
                }
            }
            else if (element > cvor.Vrijednost)
            {
                cvor.RightChild = insert(cvor.RightChild, element);
                if (height(cvor.RightChild) - height(cvor.LeftChild) == 2)
                {
                    if (element > cvor.RightChild.Vrijednost)
                    {
                        cvor = leftRotation(cvor);
                    }
                    else
                    {
                        cvor.RightChild = RightRotation(cvor.RightChild);
                        cvor = leftRotation(cvor);
                    }
                }
            }
            cvor.Dubina = Math.Max(height(cvor.LeftChild), height(cvor.RightChild)) + 1;
            return cvor;


        }

        private cvor RightRotation(cvor cvor)
        {
            cvor leftChild = cvor.LeftChild;
            if (leftChild == null)
            {
                cvor.LeftChild = null;
            }
            else
            {
                cvor.LeftChild = leftChild.RightChild;
            }
            if (leftChild != null)
            {
                leftChild.RightChild = cvor;
                leftChild.Dubina = Math.Max(height(leftChild.LeftChild), height(cvor)) + 1;
            }
            cvor.Dubina = Math.Max(height(cvor.LeftChild), height(cvor.RightChild)) +1;
            if (leftChild == null) return cvor;
            return leftChild;
        }

        private cvor leftRotation(cvor cvor)
        {
            cvor rightChild = cvor.RightChild;
            if (rightChild == null)
            {
                cvor.RightChild = null;
            }
            else
            {
                cvor.RightChild = rightChild.LeftChild;
            }
            if (rightChild != null)
            {
                rightChild.LeftChild = cvor;
                rightChild.Dubina = Math.Max(height(rightChild.RightChild), height(cvor)) + 1;
            }
            cvor.Dubina = Math.Max(height(cvor.LeftChild), height(cvor.RightChild)) + 1;
            if (rightChild == null) return cvor;
            return rightChild;
        }

        private int height(cvor cvor)
        {
            if (cvor == null) return -1;
            return cvor.Dubina;
        }
    }
}
