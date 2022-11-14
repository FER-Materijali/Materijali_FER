using System;

namespace raytracing
{
    /// <summary>
    /// Apstraktna klasa koju nasljeduje svaki objekt u sceni. Predstavlja apstraktni
    /// objekt koji je odreden svojom pozicijom u prostoru, parametrima materijala i
    /// doprinosima pojedine zrake (odbijena i lomljena).
    /// </summary>
    public abstract class Object
    {
        protected Point centerPosition;
        protected PropertyVector ka, kd, ks;
        protected float reflection, refraction, ni, n;

        /// <summary>
        /// Inicijalni konstruktor koji postavlja poziciju objekta, doprinose zraka i
        /// paramtere materijala.
        /// </summary>
        /// <param name="centerPosition">pozicija centra objekta</param>
        /// <param name="raysContributions">doprinosi lomljene i refraktirane zrake</param>
        /// <param name="materialParameters">parametri materijala</param>
        /// <param name="n">faktor jacine spekularne komponente</param>
        /// <param name="ni">indeks loma</param>
        public Object ( Point centerPosition, float[] raysContributions, PropertyVector[] materialParameters, float n, float ni )
        {
            this.centerPosition = centerPosition;
            this.reflection = raysContributions[0];
            this.refraction = raysContributions[1];
            this.ka = materialParameters[0];
            this.kd = materialParameters[1];
            this.ks = materialParameters[2];
            this.n = n;
            this.ni = ni;
        }

        /// <summary>
        /// Vraca poziciju objekta u prostoru.
        /// </summary>
        /// <returns>pozicija centra</returns>
        public Point getCenterPosition ()
        {
            return centerPosition;
        }

        /// <summary>
        /// Vraca koeficijent odbijanja ambijentne komponente materijala.
        /// </summary>
        /// <returns>ambijentni koeficijent</returns>
        public PropertyVector getKa ()
        {
            return ka;
        }

        /// <summary>
        /// Vraca koeficijent odbijanja difuzne komponente materijala.
        /// </summary>
        /// <returns>difuzni koeficijent</returns>
        public PropertyVector getKd ()
        {
            return kd;
        }

        /// <summary>
        /// Vraca koeficijent odbijanja spekularne komponente materijala.
        /// </summary>
        /// <returns>spekularni koeficijent</returns>
        public PropertyVector getKs ()
        {
            return ks;
        }

        /// <summary>
        /// Vraca faktor jacine spekularne komponente
        /// </summary>
        /// <returns>faktor jacine spekularne komponente</returns>
        public float getN ()
        {
            return n;
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
        /// Vraca udio odbijene zrake.
        /// </summary>
        /// <returns>udio odbijene zrake</returns>
        public float getReflectionFactor ()
        {
            return reflection;
        }

        /// <summary>
        /// Vraca udio lomljene zrake.
        /// </summary>
        /// <returns>udio lomljene zrake</returns>
        public float getRefractionFactor ()
        {
            return refraction;
        }

        /// <summary>
        /// Apstraktna metoda koja se implementira u podklasi. Ako postoji presjek
        /// objekta i zrake ray postavlja tocke presjeka nearIntersectionPoint i
        /// farIntersectionPoint, te vraca logicku vrijednost true.
        /// </summary>
        /// <param name="ray">zraka za koju se ispituje presjek sa objektom</param>
        /// <returns>true ako postoji presjek sa zrakom, false ako ne postoji</returns>
        public abstract bool intersection ( Ray ray );

        /// <summary>
        /// Apstraktna metoda koja se implementira u podklasi. Vraca tocku presjeka
        /// objekta sa zrakom koja je bliza pocetnoj tocki zrake.
        /// </summary>
        /// <returns>tocka presjeka objekta sa zrakom, koja je bliza izvoru zrake, a
        /// postavlja se pozivom metode intersection</returns>
        public abstract Point getIntersectionPoint ();

        /// <summary>
        /// Vraca normalu na tijelu u tocki point
        /// </summary>
        /// <param name="point">na kojoj se racuna normala na kugli</param>
        /// <returns>normal vektor normale</returns>
        public abstract Vector getNormal ( Point point );
    }
}