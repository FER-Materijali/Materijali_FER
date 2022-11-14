using System;

namespace raytracing
{
    /// <summary>
    /// Klasa predstavlja kuglu u prostoru. Nasljeduje apstraktnu klasu Object. Kugla
    /// je odredena svojim polozajem, radijusom, bojom, parametrima materijala i
    /// udjelima pojedninih zraka (osnovne, odbijene i lomljene).
    /// </summary>
    public class Sphere:Object
    {
        private double radius;
        const double Epsilon = 0.0001;
        private double rayDistanceFromCenter;
        private Point IntersectionPoint;

        /// <summary>
        /// Inicijalni konstruktor koji postavlja sve parametre kugle. Za prijenos
        /// parametara koristi se pomocna klasa SphereParameters.
        /// </summary>
        /// <param name="sphereParameters">parametri kugle</param>
        public Sphere ( SphereParameters sphereParameters )
            : base(sphereParameters.getCenterPosition(), sphereParameters.getRaysContributions(),
                sphereParameters.getMaterialParameters(), sphereParameters.getN(),
                sphereParameters.getNi())
        {
            this.radius = sphereParameters.getRadius();
        }

        /// <summary>
        /// Metoda ispituje postojanje presjeka zrake ray s kuglom. Ako postoji presjek
        /// postavlja tocku presjeka IntersectionPoint, te
        /// vraca logicku vrijednost true.
        /// </summary>
        /// <param name="ray">zraka za koju se ispituje postojanje presjeka sa kuglom</param>
        /// <returns>logicku vrijednost postojanja presjeka zrake s kuglom</returns>
        public override bool intersection (Ray ray)
        {
            double alfa, duljinaPC;

            Vector PC = new Vector(ray.getStartingPoint(), this.getCenterPosition());

            
            duljinaPC = Math.Sqrt(PC.getX() * PC.getX() + PC.getY() * PC.getY() + PC.getZ() * PC.getZ());
            alfa = ray.getDirection().getAngle(PC); 

            if ((alfa * 180.0 / Math.PI) > 90)
                return false;

            double d;
            d = duljinaPC * Math.Sin(alfa);
            rayDistanceFromCenter = d;

            if (d > this.radius)
                return false;

            double PD;
            PD = Math.Sqrt(PC.getLength() * PC.getLength() - d * d);

            double PBlizi, PDalji;
            PBlizi = PD - Math.Sqrt(radius * radius - d * d);

            if (PBlizi <= (0 + Epsilon))
                PBlizi = PDalji = PD + (Math.Sqrt(radius * radius - d * d));

            this.IntersectionPoint = new Point(ray.getStartingPoint(), ray.getDirection(), PBlizi);

            return true;
        }

        /// <summary>
        /// Vraca tocku presjeka kugle sa zrakom koja je bliza pocetnoj tocki zrake.
        /// </summary>
        /// <returns>tocka presjeka zrake s kuglom koja je bliza izvoru zrake</returns>
        public override Point getIntersectionPoint ()
        {
            return IntersectionPoint;
        }

        /// <summary>
        /// Vraca normalu na kugli u tocki point
        /// </summary>
        /// <param name="point">point na kojoj se racuna normala na kugli</param>
        /// <returns>normal vektor normale</returns>
        public override Vector getNormal ( Point point )
        {
            Ray ray = new Ray(this.centerPosition, point);
            Vector normala = ray.getDirection();

            return normala;
        }
    }
}