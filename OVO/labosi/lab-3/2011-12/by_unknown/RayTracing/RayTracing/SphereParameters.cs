using System;

namespace raytracing
{
    /// <summary>
    /// Pomocna klasa koja objedinjuje sve parametre kugle. Parametri kugle su :
    /// pozicija centra kugle, radijus, udjeli pojedinih zraka (odbijene i
    /// lomljene) i parametri materijala.
    /// </summary>
    public class SphereParameters
    {
        private Point centerPosition;
        private float radius, ni, n;
        private float[] raysContributions;
        private PropertyVector[] materialParameters;

        /// <summary>
        /// Inicijalni konstruktor koji postavlja sve parametre.
        /// </summary>
        /// <param name="centerPosition">pozicija centra kugle</param>
        /// <param name="radius">radijus kugle</param>
        /// <param name="raysContributions">udjeli odbijene i refraktirane zrake</param>
        /// <param name="materialParameters">parametri materijala kugle</param>
        /// <param name="n">faktor jacine spekularne komponente</param>
        /// <param name="ni">faktor refrakcije</param>
        public SphereParameters ( Point centerPosition, float radius, float[] raysContributions, 
            PropertyVector[] materialParameters, float n, float ni )
        {
            this.centerPosition = centerPosition;
            this.radius = radius;
            this.raysContributions = raysContributions;
            this.materialParameters = materialParameters;
            this.n = n;
            this.ni = ni;
        }

        /// <summary>
        /// Vraca poziciju centra.
        /// </summary>
        /// <returns>pozicija centra</returns>
        public Point getCenterPosition ()
        {
            return centerPosition;
        }

        /// <summary>
        /// Vraca radijus.
        /// </summary>
        /// <returns>radijus kugle</returns>
        public float getRadius ()
        {
            return radius;
        }

        /// <summary>
        /// Vraca udjele pojednih zraka (odbijene i lomljene).
        /// </summary>
        /// <returns>udjeli odbijene i refraktirane zrake</returns>
        public float[] getRaysContributions ()
        {
            return raysContributions;
        }

        /// <summary>
        /// Vraca parametre materijala.
        /// </summary>
        /// <returns>parametri materijala</returns>
        public PropertyVector[] getMaterialParameters ()
        {
            return materialParameters;
        }

        /// <summary>
        /// Vraca indeks loma
        /// </summary>
        /// <returns>indeks loma</returns>
        public float getNi ()
        {
            return ni;
        }

        /// <summary>
        /// Vraca faktor jacine spekularne komponente
        /// </summary>
        /// <returns>faktor jacine spekularne komponente</returns>
        public float getN ()
        {
            return n;
        }
    }
}