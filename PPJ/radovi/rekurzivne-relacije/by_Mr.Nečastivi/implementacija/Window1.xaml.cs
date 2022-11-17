using System;
using System.IO;
using System.Net;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Media;
using System.Windows.Media.Animation;
using System.Windows.Navigation;

namespace SSPsucelje
{
	public partial class Window1
	{
        private PocetniUvijeti mojiUvjeti;

		public Window1()
		{
			this.InitializeComponent();
            mojiUvjeti = new PocetniUvijeti();
			
			
		}

        private void Zatvori_Program(object sender, RoutedEventArgs e)
        {
            System.Windows.Application.Current.Shutdown();
        }

        private void Drag_EventHandler(object sender, RoutedEventArgs e)
        {
            DragMove();
        }

        private void Pokreni_Program(object sender, RoutedEventArgs e)
        {
            try
            {
                string ulazRelacija = unosRekurzijeBox.Text;
                int n = Int32.Parse(unosnBox.Text);



                Tablica mojaTablica = new Tablica(ulazRelacija);

                Interpretator mojInterpertator = new Interpretator(mojaTablica, mojiUvjeti);
                int rezultat = mojInterpertator.Izracunaj(n);
                rezultatBox.Text = "f(" + n.ToString() + ") = " + rezultat.ToString() +";";
            }
            catch (Exception)
            {

                rezultatBox.Text = "Greška kod unosa rekurzivne relacije";
            }
            
        }

        private void Dodaj_Uvjet(object sender, RoutedEventArgs e) 
        {
            try
            {
                mojiUvjeti.DodajUvjet(Int32.Parse(unosMjestoBox.Text), Int32.Parse(unosnVrijednostBox.Text));
                dodaniUvjeti.Text += "f(" + unosMjestoBox.Text + ") = " + unosnVrijednostBox.Text + ";\n";
                unosnVrijednostBox.Text = "";
                unosMjestoBox.Text = "";
            }
            catch (FormatException)
            {

                rezultatBox.Text = "Greška unosa početnih uvjeta";
            }
            
        }

        private void Obrisi_Sve(object sender, RoutedEventArgs e)
        {
            mojiUvjeti.ObrisiUvjete();
            dodaniUvjeti.Text = "";
        }

      
	}
}