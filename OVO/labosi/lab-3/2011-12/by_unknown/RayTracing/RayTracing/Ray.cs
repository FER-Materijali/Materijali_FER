using System;

namespace raytracing
{
    /// <summary>
    /// Klasa predstavlja zraku svjetla u prostoru. Zraka je odredena pocetnom tockom
    /// tj. izvoristem i jedinicnim vektorom smjera.
    /// </summary>
    public class Ray
    {
        Point startingPoint;
        Vector direction;

        /// <summary>
        /// Konstruktor koji stvara zraku odredenu dvijema tockama. Tocka firstPoint
        /// predstavlja pocetnu tocku (izvoriste), a tocka secondPoint sluzi za
        /// odredivanje vektora smjera zrake.
        /// </summary>
        /// <param name="firstPoint">izvor zrake</param>
        /// <param name="secondPoint">tocka prema kojoj je usmjerena zraka</param>
        public Ray ( Point firstPoint, Point secondPoint )
        {
            startingPoint = firstPoint;
            direction = new Vector(firstPoint, secondPoint);
            direction.normalize();
        }

        /// <summary>
        /// Konstruktor koji stvara zraku odredjenu pocetnom tockom (izvoristem)
	    /// i vektorom smjera.
        /// </summary>
        /// <param name="firstPoint">pocenta tocka (izvorsite) zrake</param>
        /// <param name="direction">vektor smjera zrake</param>
        public Ray ( Point firstPoint, Vector direction )
        {
            startingPoint = firstPoint;
            this.direction = direction;
            direction.normalize();
        }

        /// <summary>
        /// Vraca pocetnu tocku zrake.
        /// </summary>
        /// <returns>pocetna tocka zrake</returns>
        public Point getStartingPoint ()
        {
            return startingPoint;
        }

        /// <summary>
        /// Vraca vektor smjera zrake.
        /// </summary>
        /// <returns>vektor smjera zrake</returns>
        public Vector getDirection ()
        {
            return direction;
        }
    }
}