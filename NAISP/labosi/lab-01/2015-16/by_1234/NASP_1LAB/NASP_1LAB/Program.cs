using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NASP_1LAB
{
    class Program
    {
        static void Main(string[] args)
        {
            if (args.Length < 1)
            {
                Console.WriteLine("Nedovoljno argumenata");
                Console.ReadLine();
                Environment.Exit(0);
            }

            List<int> values = new List<int>();
            try
            {
                string text = System.IO.File.ReadAllText(args[0]).Trim();
                if (!String.IsNullOrWhiteSpace(text))
                {
                    Console.WriteLine(text);
                    foreach (string s in text.Split(' '))
                    {
                        values.Add(int.Parse(s));
                    }
                }
            }
            catch(Exception e)
            {
                Console.WriteLine("Pogreška u učitavanju podataka. " + e.Message);
                Console.ReadLine();
                Environment.Exit(0);
            }

            Node currentRoot = null;
            foreach (int value in values)
            {
                if (currentRoot != null)
                    currentRoot = Node.getRoot(currentRoot);
                Node.insertNodeAndBalance(ref currentRoot, value);
            }

            

            do{

                currentRoot = Node.getRoot(currentRoot);

                Console.Write("Postorder: ");
                Node.Postorder(currentRoot);
                Console.WriteLine();
                Console.Write("Preorder: ");
                Node.Preorder(currentRoot);
                Console.WriteLine();
                Console.Write("Inorder: ");
                Node.Inorder(currentRoot);
                Console.WriteLine("\n");

                Node.print(currentRoot, 0);
                


                string command = Console.ReadLine();
                string[] line = command.Split(' ');
                int readvalue;

                try
                {
                    readvalue = int.Parse(line[1]);
                }
                catch
                {
                    Console.WriteLine("Problem parsiranja naredbe");
                    continue;
                }

                if (line[0] == "d")
                {
                    if (currentRoot == null)
                    {
                        Console.WriteLine("Stablo nema čvorova");
                        continue;
                    }
                    else if (currentRoot.value == readvalue && currentRoot.parent == null && currentRoot.leftChild == null && currentRoot.rightChild == null)
                    {
                        Console.WriteLine("Brisanje jedinog čvora stabla");
                        currentRoot = null;
                    }
                    else
                    {
                        Node.deleteByCopying(currentRoot, readvalue);
                    }
                }
                else if (line[0] == "a")
                {
                    Node.insertNodeAndBalance(ref currentRoot, readvalue);
                }
                else
                {

                }

            }while(true);
        }

        
    }




}
