using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    class cvor
    {
        private int vrijednost;
        private int dubina;
        private cvor leftChild;
        private cvor rightChild;
        public cvor(int number)
        {
            this.dubina = 0;
            this.leftChild = null;
            this.rightChild = null;
            this.vrijednost = number;
        }

        internal void preOrder()
        {
            Console.WriteLine("Vrijednost:"+this.Vrijednost+" dubina cvora:"+ this.dubina);
            if (this.leftChild != null)
            {
                leftChild.preOrder();
            }
            if (this.rightChild != null)
            {
                rightChild.preOrder();
            }
        }

        public int Vrijednost
        {
            get
            {
                return vrijednost;
            }

            set
            {
                vrijednost = value;
            }
        }

        public int Dubina
        {
            get
            {
                return dubina;
            }

            set
            {
                dubina = value;
            }
        }

        internal cvor LeftChild
        {
            get
            {
                return leftChild;
            }

            set
            {
                leftChild = value;
            }
        }

        internal cvor RightChild
        {
            get
            {
                return rightChild;
            }

            set
            {
                rightChild = value;
            }
        }



    }
}
