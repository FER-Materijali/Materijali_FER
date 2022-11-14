using System;
using System.Windows.Forms;

namespace raytracing
{
    /// <summary>
    /// Glavna klasa.
    /// </summary>
    public class Glavni
    {
        public static void Main (string[] args)
        {
            Picture picture = new Picture();
            picture.Visible = true;

            Application.Run(picture);
        }
    }
}