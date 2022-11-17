using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace WindowsFormsApplication1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        public static string text,rez;
        Produkcija[] a;

        
       
        

        private void button1_Click(object sender, EventArgs e)
        {
           text = textBox1.Text;
           try
           {
               a = StvoriProd.run(text);
               rez = ReduciranZnakom.run(a);
               textBox2.Text = rez;
           }
           catch {
               textBox2.Text = "Pogrešan format unosa";
           }
          
        }

        private void button2_Click(object sender, EventArgs e)
        {

            Close();

        }

        public static void ispisi(string a){
        //textBox2.Text=a;
        }

    }
}
