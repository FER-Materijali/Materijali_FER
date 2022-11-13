using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using KnapsackNameSpace;

namespace NASP_2LAB_GUI
{
    public partial class KnapsackForm : Form
    {
        Knapsack ks;
        public KnapsackForm()
        {
            InitializeComponent();

            ks = new Knapsack();
            ks.AddItem(new Item("Jabuka", "Voće", 3, 2));
            ks.AddItem(new Item("Kruška", "Voće", 7, 5));

            ks.AddItem(new Item("Krumpir", "Povrće", 3, 3));
            ks.AddItem(new Item("Kupus", "Povrće", 4, 4));

            ks.AddItem(new Item("Jogurt", "Mliječni proizvod", 10, 6));
            ks.AddItem(new Item("Kefir", "Mliječni proizvod", 6, 5));
            ks.AddItem(new Item("Mlijeko", "Mliječni proizvod", 5, 4));

            ks.InitializeTable(10);
            ks.PrintTable();
            ks.FillTable();

            ks.PopulateDataGrid(dataGridViewTable);

        }



        private void UpdateItemGrid(bool optimalOnly = false)
        {

            while (dataGridViewItems.Rows.Count > 1)
            {
                dataGridViewItems.Rows.RemoveAt(0);
            }
            List<Item> items = optimalOnly ? ks.GetOptimalItems() : ks.GetItems();
            foreach(Item item in items)
            {
                var row = new DataGridViewRow();
                row.Cells.Add(new DataGridViewTextBoxCell() { Value = item.name });
                row.Cells.Add(new DataGridViewTextBoxCell() { Value = item.category });
                row.Cells.Add(new DataGridViewTextBoxCell() { Value = item.value });
                row.Cells.Add(new DataGridViewTextBoxCell() { Value = item.cost });
                dataGridViewItems.Rows.Add(row);
            }
        }

        private void buttonAddItem_Click(object sender, EventArgs e)
        {
            try
            {
                ks.AddItem(new Item(textBoxName.Text, textBoxCategory.Text, int.Parse(textBoxValue.Text), int.Parse(textBoxCost.Text)));
            }
            catch(Exception ex)
            {
                MessageBox.Show("Error entering data: "+ex.Message);
            }
            UpdateItemGrid();
        }

        private void buttonInitTable_Click(object sender, EventArgs e)
        {
            int capacity = 0;
            try
            {
                capacity = int.Parse(textBoxCapacity.Text);
                ks.InitializeTable(capacity);
                clearDataGridTable();
                ks.PopulateDataGrid(dataGridViewTable);
            }
            catch
            {
                MessageBox.Show("Error entering capacity.");
            }
        }

        private void buttonFillTable_Click(object sender, EventArgs e)
        {
            ks.FillTable();
            clearDataGridTable();
            ks.PopulateDataGrid(dataGridViewTable);
            UpdateItemGrid(true);
        }

        private void clearDataGridTable()
        {
            while (dataGridViewTable.Rows.Count > 0)
            {
                dataGridViewTable.Rows.RemoveAt(0);
            }
        }
    }
}
