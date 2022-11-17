using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Text.RegularExpressions;

namespace WindowsFormsApplication1
{
    public  class StvoriProd
    {

        public static Produkcija[] run(string a)
        {
            Produkcija[] polje1 = new Produkcija[100];
            int i=0;
            string pattern;
            //traženje nezavršnih znakova prije znaka %
            pattern = @"[\d\D]+?%";
            MatchCollection mc=Regex.Matches(a,pattern);
            
            pattern = @"\s*([\d\w]+)\s*,?";
            try
            {
                mc = Regex.Matches(mc[0].Value, pattern);
            }
            catch 
            {
                throw;
            }
            GroupCollection gc;
            
            foreach (Match m in mc)
            {
                gc = m.Groups;
                if (!PostojiLi(gc[1].Value, polje1,i))
                {
                    polje1[i] = new Produkcija(gc[1].Value);
                    i++;
                }
            }

            //popunjavanje lijevi strana produkcije
            pattern = @"%[\d\D]+%";
            mc = Regex.Matches(a, pattern);
            
            pattern = @"\s*([\d\w]+)\s*:=\s*([\d\w\$]+)\s*";
            try { mc = Regex.Matches(mc[0].Value, pattern); }
            catch { throw;
            }
            foreach (Match m in mc)
            {
                gc = m.Groups;
                for (int j = 0; j < i; j++)
                    if (polje1[j].Get() == gc[1].Value) 
                        polje1[j].SetProd(gc[2].Value);    
                
            }
            
            
            //smanjivanje polja
            Produkcija[] polje = new Produkcija[i];
            for (int j = 0; j < i; j++) {
                polje[j] = polje1[j];
            }

                return polje;
        }

        
        
        
        private static bool PostojiLi(string p, Produkcija[] polje1,int j)
        {
            for (int i = 0; i < j; i++) 
            {
                if (polje1[i].Get() == p) return true;
            
            
            }
            return false;
        
        }
      }


}

