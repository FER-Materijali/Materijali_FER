using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace WindowsFormsApplication1
{
    public class Produkcija
    {
        int broj=0;
        string nezavrsni;
        string[] desna=new string[10];
        
        
        public Produkcija(string a) {
            nezavrsni = a;
        } 

        public void SetProd(string b) {
            desna[broj] = b;
            broj++;
        }

        public string GetProd(int i) { 
            return desna[i];
        }

        public string Get() {
            return nezavrsni; 
       }
        public int Getb() { 
            return broj;
        }

    }
}
