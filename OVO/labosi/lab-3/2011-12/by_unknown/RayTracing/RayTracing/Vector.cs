using System;

namespace raytracing
{
    /// <summary>
    /// Klasa predstavlja vektor u trodimenzionalnom prostoru.
    /// </summary>
    public class Vector
    {
        private double X, Y, Z;

        /// <summary>
        /// Glavni konstruktor koji stvara vektor s komponentama x, y i z.
        /// </summary>
        /// <param name="x">x komponenta vektora</param>
        /// <param name="y">y komponenta vektora</param>
        /// <param name="z">z komponenta vektora</param>
        public Vector ( double x, double y, double z )
        {
            this.X = x;
            this.Y = y;
            this.Z = z;
        }

        /// <summary>
        /// Konstruktor koji stvara vektor odreden dvijema tockama. Tocka first
        /// predstavlja hvatiste vektora, a tocka second vrh vektora.
        /// </summary>
        /// <param name="first">tocka koja predstavlja pocetak, odnosno hvatiste vektora</param>
        /// <param name="second">tocka koja zadaje vrh vektora</param>
        public Vector ( Point first, Point second )
        {
            X = second.getX() - first.getX();
            Y = second.getY() - first.getY();
            Z = second.getZ() - first.getZ();
        }

        /// <summary>
        /// Vraca x komponentu vektora.
        /// </summary>
        /// <returns>x komponenta vektora</returns>
        public double getX ()
        {
            return X;
        }

        /// <summary>
        /// Vraca y komponentu vektora.
        /// </summary>
        /// <returns>y komponenta vektora</returns>
        public double getY ()
        {
            return Y;
        }

        /// <summary>
        /// Vraca z komponentu vektora.
        /// </summary>
        /// <returns>z komponenta vektora</returns>
        public double getZ ()
        {
            return Z;
        }

        /// <summary>
        /// Metoda normalizira vektor, odnosno stvara jedinicni vektor.
        /// </summary>
        public void normalize ()
        {
            double length = Math.Sqrt(Math.Pow(X, 2) + Math.Pow(Y, 2) + Math.Pow(Z, 2));
            X /= length;
            Y /= length;
            Z /= length;
        }

        /// <summary>
        /// Metoda vraca duzinu vektora.
        /// </summary>
        /// <returns>duzina vektora</returns>
        public double getLength ()
        {
            return Math.Sqrt(Math.Pow(X, 2) + Math.Pow(Y, 2) + Math.Pow(Z, 2));
        }

        /// <summary>
        /// Metoda sluzi za oduzimanje dva vektora.
        /// </summary>
        /// <param name="v">vektor za koji se oduzima</param>
        /// <returns>vektor koji je jednak razlici</returns>
        public Vector sub ( Vector v )
        {
            return new Vector(X - v.getX(), Y - v.getY(), Z - v.getZ());
        }

        /// <summary>
        /// Metoda sluzi za zbrajanje dva vektora.
        /// </summary>
        /// <param name="v">vektor s kojim se zbraja</param>
        /// <returns>vektor koji je jednak zbroju</returns>
        public Vector add ( Vector v )
        {
            return new Vector(X + v.getX(), Y + v.getY(), Z + v.getZ());
        }

        /// <summary>
        /// Metoda sluzi za mnozenje vektora skalarom.
        /// </summary>
        /// <param name="factor">skalar s kojim se mnozi vektor</param>
        /// <returns>vektor koji je jednak umnosku vektora s skalarom</returns>
        public Vector multiple ( double factor )
        {
            return new Vector(X * factor, Y * factor, Z * factor);
        }

        /// <summary>
        /// Koristi se za racunanje skalarnog produkta izmedu dva vektora.
        /// </summary>
        /// <param name="v">vektor s kojim se racuna skalarni produkt</param>
        /// <returns>skalarni produkt dva vektora</returns>
        public double dotProduct ( Vector v )
        {
            return ((X * v.getX()) + (Y * v.getY()) + (Z * v.getZ()));
        }

        /// <summary>
        /// Koristi se za racunanje vektorskog produkta.
        /// </summary>
        /// <param name="v">vektor s kojim se racuna produkt</param>
        /// <returns>vektorski produkt dva vektora</returns>
        public Vector crossProduct ( Vector v )
        {
            double tx = (Y * v.getZ()) - (v.getY() * Z);
            double ty = (Z * v.getX()) - (v.getZ() * X);
            double tz = (X * v.getY()) - (v.getX() * Y);
            return new Vector(tx, ty, tz);
        }

        /// <summary>
        /// Metoda vraca kut u radijanima (od 0 do PI) izmedu doticnog vektora i
        /// vektora v.
        /// </summary>
        /// <param name="v">vektor na odnosu kojeg se odreduje kut</param>
        /// <returns>kut izmedu dva vektora (u radijanima od 0 do PI)</returns>
        public double getAngle ( Vector v )
        {
            return Math.Acos(this.dotProduct(v) / (this.getLength() * v.getLength()));
        }

        /// <summary>
        /// Vraca reflektirani vektor s obzirom na normalu.
        /// </summary>
        /// <param name="normal">normala</param>
        /// <returns>reflektirani vektor</returns>
        public Vector getReflectedVector ( Vector normal )
        {
            Vector R = normal.multiple(2 * this.dotProduct(normal)).sub(this);
            return R;
        }

        /// <summary>
        /// Vraca refraktirani vektor s obzirom na normalu i indekse refrakcije
        /// sredstva upadnog vektora i refraktiranog vektora.
        /// </summary>
        /// <param name="normal">normala</param>
        /// <param name="nI">index loma sredstva</param>
        /// <returns>refraktirani vektor</returns>
        public Vector getRefractedVector ( Vector normal, double nI )
        {
            Vector U = this;
            Vector R;

            double alfa, cosA, a, b, D;

            U.normalize();
            normal.normalize();

            alfa = this.getAngle(normal);
            cosA = Math.Cos(alfa);


            b = nI;

            D = 4 * (b * b * cosA * cosA - b * b + 1);

            a = (-2 * b * cosA + Math.Sqrt(D)) / 2;
            R = normal.multiple(-a).sub(U.multiple(b));

            return R;  
        }
    }
}