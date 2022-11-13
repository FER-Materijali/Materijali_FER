using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Drawing;

namespace AVLtree
{
    public class CvorGraph
    {
        int x;
        int y;
        int podatak;
        public int FR;

        //public int vl;
        //public int vd;

        public CvorGraph(int visina, int sirina,int podatak)
        {
            this.podatak = podatak;
            x = sirina;
            y = visina;
        }

        public void CrtajCvor(bool colorFlag = true)
        {
            Graphics graphicsObj;
            graphicsObj = Algoritmi.graphicsObj;

            Rectangle myRectangle = new Rectangle(x-15, y-15, 30, 30);
            if (colorFlag)
            {
                graphicsObj.FillEllipse(new SolidBrush(Color.ForestGreen), myRectangle);
            }
            else
            {
                graphicsObj.FillEllipse(new SolidBrush(Color.DarkBlue), myRectangle);
            }
            Brush brush = new SolidBrush(System.Drawing.Color.Black);
            graphicsObj.DrawString(podatak.ToString(), new Font("Helvetica", 12, FontStyle.Bold), brush, x-10, y - 10);

            //graphicsObj.DrawString("(" + vl + "," + vd + ")", new Font("Helvetica", 12, FontStyle.Bold), brush, x - 15, y - 50);
        
            graphicsObj.DrawString("[" + FR.ToString() + "]", new Font("Helvetica", 12, FontStyle.Bold), brush, x - 15, y - 30);
        }

     
    }
}
