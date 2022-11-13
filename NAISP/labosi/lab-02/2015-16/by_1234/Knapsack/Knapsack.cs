using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data;
using System.Windows.Forms;

namespace KnapsackNameSpace
{
    public class Item
    {
        public Item(string name, string category, int value, int cost)
        {
            this.name = name;
            this.category = category;
            this.value = value;
            this.cost = cost;
        }

        public string name;
        public string category;
        public int value;
        public int cost;
    }

    public class Knapsack
    {
        List<Item> items;

        Dictionary<string, int> categoryIndex;
        Dictionary<string, int> itemIndexInsideCategory;

        Dictionary<int, int> itemCountByCategory;
        int capacity;

        int[][,] categoryTable;
        bool[][,] decisionTable;

        public Knapsack() 
        {
            itemCountByCategory = new Dictionary<int, int>();

            itemIndexInsideCategory = new Dictionary<string, int>();
            categoryIndex = new Dictionary<string, int>();
            items = new List<Item>();
        }

        int dictionaryIndex = 0;
        public void AddItem(Item item)
        {
            items.Add(item);

            if (!categoryIndex.ContainsKey(item.category))
            {
                categoryIndex.Add(item.category, dictionaryIndex);
                itemCountByCategory.Add(dictionaryIndex, 1);
                dictionaryIndex++;
                itemIndexInsideCategory.Add(item.name, 0);
            }
            else
            {
                int a = categoryIndex[item.category];
                int b = itemCountByCategory[a];

                itemIndexInsideCategory.Add(item.name, itemCountByCategory[categoryIndex[item.category]]);

                itemCountByCategory[categoryIndex[item.category]]++;
                
            }
        }

        public void InitializeTable(int capacity)
        {
            this.capacity = capacity;

            categoryTable = new int[itemCountByCategory.Count][,];
            decisionTable = new bool[itemCountByCategory.Count][,];



            foreach (int i in itemCountByCategory.Keys)
            {
                categoryTable[i] = new int[capacity, itemCountByCategory[i]];
                decisionTable[i] = new bool[capacity, itemCountByCategory[i]];
            }

        }

        public void FillTable()
        {
            for (int j = 0; j < categoryTable.Length; j++)
            {
                for (int k = 0; k < categoryTable[j].GetLength(1); k++)
                {
                    for (int i = 0; i < capacity; i++)
                    {
                        Item currentItem = GetItemByIndex(j, k);
                        int value = currentItem.value;
                        int cost = currentItem.cost;

                        int maxValue = 0;
                        bool decision = false;
                        if (j > 0)
                        {
                            for (int l = 0; l < itemCountByCategory[j - 1]; l++)
                            {
                                int kYes;
                                int kNo = categoryTable[j - 1][i, l];
                                if (cost < i+1)
                                {
                                    kYes = categoryTable[j - 1][i - cost, l] + value;
                                }
                                else if (cost == i+1)
                                {
                                    kYes = value;
                                }
                                else
                                {
                                    kYes = kNo;
                                }

                                if (kYes > kNo)
                                {
                                    if (kYes > maxValue)
                                    {
                                        maxValue = kYes;
                                        decision = true;
                                    }
                                }
                                else
                                {
                                    if (kNo > maxValue)
                                    {
                                        maxValue = kNo;
                                        decision = false;
                                    }
                                }
                            }
                        }
                        else
                        {
                            int kYes;
                            int kNo = 0;
                            if (cost <= i+1)
                            {
                                kYes = value;
                            }
                            else
                            {
                                kYes = kNo;
                            }

                            if (kYes > kNo)
                            {
                                if (kYes > maxValue)
                                {
                                    maxValue = kYes;
                                    decision = true;
                                }
                            }
                            else
                            {
                                if (kNo > maxValue)
                                {
                                    maxValue = kNo;
                                    decision = false;
                                }
                            }
                        }

                        categoryTable[j][i, k] = maxValue;
                        decisionTable[j][i, k] = decision;
                    }
                }
            }
        }

        private string GetCategoryByIndex(int index)
        {
            foreach (string category in categoryIndex.Keys)
            {
                if (categoryIndex[category] == index)
                {
                    return category;
                }
            }
            return null;
        }

        private Item GetItemByIndex(int catIndex, int itemIndex)
        {
            string category = GetCategoryByIndex(catIndex);

            foreach (Item item in items)
            {
                if (item.category == category)
                {
                    if (itemIndexInsideCategory[item.name] == itemIndex)
                    {
                        return item;
                    }
                }
            }
            return null;
        }

        public List<Item> GetItems()
        {
            return items;
        }

        public List<Item> GetOptimalItems()
        {
            List<Item> optimalItems = new List<Item>();
            int i = capacity - 1;
            int j = categoryTable.Length - 1;

            do
            {

                int max = categoryTable[j][i, 0];
                bool decision = decisionTable[j][i, 0];
                int indexInside = 0;
                for (int k = 1; k < categoryTable[j].GetLength(1); k++)
                {
                    int current = categoryTable[j][i, k];
                    if (current > max)
                    {
                        max = current;
                        decision = decisionTable[j][i, k];
                        indexInside = k;
                    }
                }

                if (decision == true)
                {
                    Item item = GetItemByIndex(j, indexInside);

                    optimalItems.Add(item);

                    int cost = item.cost;
                    i = i - cost;
                }

                j--;

            } while (i >= 0 && j >= 0);
            return optimalItems;
        }

        public void PopulateDataGrid(DataGridView dataGridView)
        {
            int[][,] data = categoryTable;

            int rowLength = 0;
            for (int m = 0; m < data.Length; m++)
            {
                rowLength += data[m].GetLength(1);
            }
            dataGridView.ColumnCount = rowLength;

            int i = 0;
            for (int j = 0; j < categoryTable.Length; j++)
            {
                for (int k = 0; k < categoryTable[j].GetLength(1); k++)
                {
                    Item item = GetItemByIndex(j, k);
                    dataGridView.Columns[i].Name = item.name + " - " + item.category;
                    i++;
                }
            }


            for (int c = 0; c < capacity; c++)
            {
                var row = new DataGridViewRow();

                for (int j = 0; j < categoryTable.Length; j++)
                {
                    for (int k = 0; k < categoryTable[j].GetLength(1); k++)
                    {
                        row.HeaderCell.Value = "" + (c + 1);

                        row.Cells.Add(new DataGridViewTextBoxCell()
                        {
                            Value = data[j][c, k]
                        });

                    }
                }

                dataGridView.Rows.Add(row);
            }
        }

        public void PrintItems()
        {
            Console.WriteLine("printing items");
            int i = capacity - 1;
            int j = categoryTable.Length - 1;
            //int k = itemCountByCategory[j] - 1;

            do
            {

                int max = categoryTable[j][i, 0];
                bool decision = decisionTable[j][i, 0];
                int indexInside = 0;
                for (int k = 1; k < categoryTable[j].GetLength(1); k++)
                {
                    int current = categoryTable[j][i, k];
                    if (current > max)
                    {
                        max = current;
                        decision = decisionTable[j][i, k];
                        indexInside = k;
                    }
                }


                if (decision == true)
                {
                    Item item = GetItemByIndex(j, indexInside);

                    Console.WriteLine("item:" + item.name + " category:" + j + " inside:" + indexInside);

                    int cost = item.cost;
                    i = i - cost;
                }

                j--;

            } while (i >= 0 && j >= 0);
        }

        public void PrintDecisionTable()
        {
            Console.Write("Cat.\t|");
            for (int j = 0; j < decisionTable.Length; j++)
            {
                Console.Write(j + "\t|");
                for (int k = 0; k < itemCountByCategory[j] - 1; k++)
                {
                    Console.Write("\t|");
                }
            }

            Console.Write("\nItems.\t|");
            for (int j = 0; j < decisionTable.Length; j++)
            {
                for (int k = 0; k < itemCountByCategory[j]; k++)
                {
                    Console.Write(k + "\t|");
                }
            }
            Console.Write("\n--------+-------+-------+-------+-------+-------+\n");

            for (int i = 1; i < capacity + 1; i++)
            {
                Console.Write(i + "\t|");
                for (int j = 0; j < decisionTable.Length; j++)
                {
                    for (int k = 0; k < itemCountByCategory[j]; k++)
                    {
                        Console.Write(decisionTable[j][i - 1, k] + "\t|");
                    }
                }
                Console.Write("\n");
            }
        }

        public void PrintTable()
        {
            Console.Write("Cat.\t|");
            for (int j = 0; j < categoryTable.Length; j++)
            {
                Console.Write(j + "\t|");
                for (int k = 0; k < itemCountByCategory[j] - 1; k++)
                {
                    Console.Write("\t|");
                }
            }

            Console.Write("\nItems.\t|");
            for (int j = 0; j < categoryTable.Length; j++)
            {
                for (int k = 0; k < itemCountByCategory[j]; k++)
                {
                    Console.Write(k + "\t|");
                }
            }
            Console.Write("\n--------+-------+-------+-------+-------+-------+\n");

            for (int i = 1; i < capacity + 1; i++)
            {
                Console.Write(i + "\t|");
                for (int j = 0; j < categoryTable.Length; j++)
                {
                    for (int k = 0; k < itemCountByCategory[j]; k++)
                    {
                        Console.Write(categoryTable[j][i - 1, k] + "\t|");
                    }
                }
                Console.Write("\n");
            }
        }

    }

}
