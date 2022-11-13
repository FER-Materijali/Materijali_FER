using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using KnapsackNameSpace;

namespace NASP_2LAB
{
    class Program
    {
        static void Main(string[] args)
        {
            Knapsack ks = new Knapsack();
            ks.AddItem(new Item("Lubenica", "Voce", 20, 5));
            ks.AddItem(new Item("Kruška","Voce",10,10));
            ks.AddItem(new Item("Pinceta", "Kozmetika", 5, 8));
            ks.AddItem(new Item("Mitohondrij", "Stanica", 1, 2));
            ks.AddItem(new Item("Jabuka", "Voce", 4, 3));
            ks.AddItem(new Item("Fen", "Kozmetika", 12, 7));

            ks.InitializeTable(20);
            ks.PrintTable();
            ks.FillTable();

            Console.WriteLine();
            ks.PrintTable();
            Console.WriteLine();
            ks.PrintDecisionTable();
            Console.WriteLine();
            ks.PrintItems();
            Console.ReadLine();
        }
    }
}
