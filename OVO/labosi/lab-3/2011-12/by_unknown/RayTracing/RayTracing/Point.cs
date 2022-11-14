using System;

namespace raytracing
{
    /// <summary>
    /// Predstavlja tocku u prostoru.
    /// </summary>
    public class Point
    {
        private double x, y, z;

        /// <summary>
        /// Glavni konstruktor koji kreira novu tocku s koordinatama x,y i z.
        /// </summary>
        /// <param name="x">x koordinata tocke</param>
        /// <param name="y">y koordinata tocke</param>
        /// <param name="z">z koordinata tocke</param>
        public Point ( double x, double y, double z )
        {
            this.x = x;
            this.y = y;
            this.z = z;
        }

        /// <summary>
        /// Konstruktor koji kreira novu tocku koja je za vrijednost t udaljena u
        /// smjeru vektora direction od pocetne tocke.
        /// </summary>
        /// <param name="startingPoint">pocetna tocka od koje se odreduje nova tocka</param>
        /// <param name="direction">vektor smjera u kojem se odreduje nova tocka</param>
        /// <param name="t">udaljenost nove tocke od pocetne</param>
        public Point ( Point startingPoint, Vector direction, double t )
        {
            x = startingPoint.getX() + (direction.getX() * t);
            y = startingPoint.getY() + (direction.getY() * t);
            z = startingPoint.getZ() + (direction.getZ() * t);
        }

        /// <summary>
        /// Vraca x koordinatu polozaja tocke.
        /// </summary>
        /// <returns>x koordinata tocke</returns>
        public double getX ()
        {
            return x;
        }

        /// <summary>
        /// Vraca y koordinatu polozaja tocke.
        /// </summary>
        /// <returns>y koordinata tocke</returns>
        public double getY ()
        {
            return y;
        }

        /// <summary>
        /// Vraca z koordinatu polozaja tocke.
        /// </summary>
        /// <returns>z koordinata tocke</returns>
        public double getZ ()
        {
            return z;
        }

        /// <summary>
        /// Vraca udajenost tocke od tocke p.
        /// </summary>
        /// <param name="p">tocka od koje se odreduje udaljenost</param>
        /// <returns>udaljenost tocke od tocke p</returns>
        public double getDistanceFrom ( Point p )
        {
            return Math.Sqrt(Math.Pow(x - p.getX(), 2) +
                             Math.Pow(y - p.getY(), 2) +
                             Math.Pow(z - p.getZ(), 2));
        }
    }
}