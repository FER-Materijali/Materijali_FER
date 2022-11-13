using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Labos2
{
    public class Kromosom
    {
        public static int preciznost = 10000000;
        public static int MutateP = 10;
        public static int duljina = 32;
                
        string x;
        string y;

        public double X
        {
            get { return (double)Convert.ToInt32(x,2) / preciznost; }
        }
        public double Y
        {
            get { return (double)Convert.ToInt32(y,2) / preciznost; }
        }

        int dobrota;

        public int Dobrota
        {
            get { return dobrota; }
            set { dobrota = value; }
        }

        public double Z
        {
            get { return (double)dobrota / preciznost; }
        }

        public void Init()
        {
            Random rand = new Random();
            x="";
            y = "";
            for (int i = 0; i < duljina; i++)
            {
                x += rand.Next(0, 2).ToString();
                y += rand.Next(0, 2).ToString();
            }
            int t = Convert.ToInt32(x, 2);
            this.Funkcija();
        }
        
        public void Mutate()
        {            
            Random rand = new Random();
            char[] tmpX;
            tmpX = x.ToCharArray(); 
            char[] tmpY;
            tmpY = y.ToCharArray();

            for (int i = 0; i < tmpX.Length; i++)
            {
                if (rand.Next(0, 100) <= MutateP)
                {
                    if (tmpX[i] == '0')
                    {
                        tmpX[i] = '1';
                    }
                    else
                    {
                        tmpX[i] = '0';
                    }
                }
            }
            for (int i = 0; i < tmpY.Length; i++)
            {
                if (rand.Next(0, 100) <= MutateP)
                {
                    if (tmpY[i] == '0')
                    {
                        tmpY[i] = '1';
                    }
                    else
                    {
                        tmpY[i] = '0';
                    }
                }
            }            
        }

        public static Tuple<Kromosom,Kromosom> Krizaj(Kromosom prvi, Kromosom drugi)
        {
            string x1 = prvi.x;
            string x2 = drugi.x;
            string y1 = prvi.y;
            string y2 = drugi.y;
            Random rand = new Random();

            int tockaKriz = rand.Next(0, x1.Length);
            string x3 = x1.Substring(0, tockaKriz) + x2.Substring(tockaKriz);
            string x4 = x2.Substring(0, tockaKriz) + x1.Substring(tockaKriz);

            tockaKriz = rand.Next(0,y1.Length);
            string y3 = y1.Substring(0, tockaKriz) + y2.Substring(tockaKriz);
            string y4 = y2.Substring(0, tockaKriz) + y1.Substring(tockaKriz);

            Kromosom k1 = new Kromosom();
            k1.x = x3;
            k1.y = y3;
            k1.Mutate();
            k1.Funkcija();

            Kromosom k2 = new Kromosom();
            k2.x = x4;
            k2.y = y4;
            k2.Mutate();
            k2.Funkcija();

            Tuple<Kromosom, Kromosom> kromosomi = new Tuple<Kromosom, Kromosom>(k1,k2);
            return kromosomi;
        }

        public void Funkcija()
        {
            double x = (double)Convert.ToInt32(this.x,2)/preciznost;
            double y = (double)Convert.ToInt32(this.y, 2) / preciznost;            
            double tmp = 0.5 - (Math.Pow(Math.Sin(Math.Sqrt(x * x + y * y)), 2) - 0.5) /  Math.Pow(1 + 0.001 *(x * x + y * y),2);
            dobrota = (int)(tmp * preciznost);
        }
    }
}
