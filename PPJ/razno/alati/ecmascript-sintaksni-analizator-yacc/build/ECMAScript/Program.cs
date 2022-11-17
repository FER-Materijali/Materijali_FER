using System;
using System.Collections.Generic;
using System.Linq;
using System.Windows.Forms;

namespace ListCollection
{
    static class Glavni
    {
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        public static Forma mojaForma;
                
        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            mojaForma = new Forma();
            Application.Run(mojaForma);
        }

        public static void Ispisi(string zaispisati)
        {
            Glavni.mojaForma.OutputBox.Text= Glavni.mojaForma.OutputBox.Text + zaispisati + Environment.NewLine;
        }
        
    }
}
