using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OOuP2lab5
{
    class SlijedBrojeva
    {
        private List<int> brojevi;
        private List<Observer> observers;
        private IIzvorBrojeva izvor;
        public SlijedBrojeva(IIzvorBrojeva izvor)
        {
            this.izvor = izvor;
            brojevi = new List<int>();
            observers = new List<Observer>();
        }
        public List<int> dajBrojeve()
        {
            return brojevi;
        }
        public void Attach(Observer observer)
        {
            observers.Add(observer);
        }
        public void Dettach(Observer observer)
        {
            observers.Remove(observer);
        }
        private void Notify()
        {
            foreach (Observer o in observers)
            {
                o.Update();
            }
        }

        public void Kreni()
        {
            int i;
            do
            {
                i = izvor.UcitajBroj();
                Console.WriteLine(i);
                brojevi.Add(i);
                Notify();
                System.Threading.Thread.Sleep(1000);
            } while (i != -1);
        }

    }
}
