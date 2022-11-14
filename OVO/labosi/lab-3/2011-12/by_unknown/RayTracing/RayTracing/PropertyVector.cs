using System;

namespace raytracing
{
    /// <summary>
    /// Pomocna klasa koja predstavlja vektor svojstva, odnosno parametara materijala.
    /// Naime, neko svojstvo materijala, na primjer ambijentni koeficijent, je razlicito
    /// za razlicite boje (crvenu, zelenu i plavu). Zbog toga se to svojstvo moze
    /// prikazati vektorom koji sadrzi tri razlicite parametre (za svaku boju).
    /// </summary>
    public class PropertyVector
    {
        private float red, green, blue;

        /// <summary>
        /// Inicijalni konstruktor koji postavlja vrijednost parametara za racunanje s
        /// crvenom, zelenom i plavom komponentom boje.
        /// </summary>
        /// <param name="red">parametar za racunanje s crvenom komponentom boje</param>
        /// <param name="green">parametar za racunanje sa zelenom komponentom boje</param>
        /// <param name="blue">parametar za racunanje s plavom komponentom boje</param>
        public PropertyVector ( float red, float green, float blue )
        {
            this.red = red;
            this.green = green;
            this.blue = blue;
        }

        /// <summary>
        /// Vraca parametar za racunanje s crvenom komponentom boje.
        /// </summary>
        /// <returns>parametar za racunanje s crvenom komponentom boje</returns>
        public float getRedParameter ()
        {
            return red;
        }

        /// <summary>
        /// Vraca parametar za racunanje s zelenom komponentom boje.
        /// </summary>
        /// <returns>parametar za racunanje s zelenom komponentom boje</returns>
        public float getGreenParameter ()
        {
            return green;
        }

        /// <summary>
        /// Vraca parametar za racunanje s plavom komponentom boje.
        /// </summary>
        /// <returns>parametar za racunanje s plavom komponentom boje</returns>
        public float getBlueParameter ()
        {
            return blue;
        }

        /// <summary>
        /// Mnozi vektor s skalarom.
        /// </summary>
        /// <param name="factor">skalra s kojim se mnozi</param>
        /// <returns>umnozak vektora s skalarom</returns>
        public PropertyVector multiple ( double factor )
        {
            return new PropertyVector((float)factor * red, (float)factor * green, (float)factor * blue);
        }

        /// <summary>
        /// Koristi se za mnozenje s vektorom boje.
        /// </summary>
        /// <param name="c">vektor boje s kojim se mnozi</param>
        /// <returns>vektor parametarara koji je rezultat mnozenja</returns>
        public PropertyVector multiple ( ColorVector c )
        {
            return new PropertyVector(c.getRed() * red, c.getGreen() * green, c.getBlue() * blue);
        }
    }
}