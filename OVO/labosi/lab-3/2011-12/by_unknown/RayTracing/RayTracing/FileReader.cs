using System;
using System.IO;
using System.Text;
using System.Globalization;

namespace raytracing
{
    /// <summary>
    /// Klasa koja sluzi za citanje iz tekstualne datoteke svih podataka potrebnih
    /// za crtanje slike pomocu ray tracinga. Pri citanju ignorira sve sto se nalazi
    /// unutar ostrih zagrada <>, a kao decimalni broj tretira podatak zapisan izmedu
    /// zareza ili dvotocki.
    /// </summary>
    public class FileReader
    {
        private int length, i = 0;
        private String input;
        private Point eyePosition, lightPosition;
        private float screenSize, screenResolution, numberOfObjects;
        private SphereParameters[] sphereParameters;
        private float ni, n;

        /// <summary>
        /// Konstruktor koji otvara datoteku i cijeli sadrzaj datoteke sprema u
        /// varijablu input.
        /// </summary>
        /// <param name="fileName">ime datoteke iz koje se cita</param>
        public FileReader ( string fileName )
        {
            try
            {
                StreamReader reader = new StreamReader(fileName);
                input = reader.ReadToEnd();
                length = input.Length;
                reader.Close();
            }
            catch(FileNotFoundException)
            {
                Console.WriteLine("File <" + fileName + "> not found!");
                Environment.Exit(0);
            }
        }

        /// <summary>
        /// Metoda koja uzima sljedeci niz znakova koji se nalazi unutar zareza ili
        /// dvotocki. Sve znakove unutar kosih zagrada <> ignorira.
        /// </summary>
        /// <returns>slijedeci niz znakova koji se nalazi izmedu zareza ili dvotocki</returns>
        public StringBuilder getNextParameter ()
        {
            bool ignore = false;
            StringBuilder parameter = new StringBuilder();
            for(; i < length; i++)
            {
                char c = input[i];

                if(c == '<')
                    ignore = true;

                if(!ignore)
                {
                    if((c != ':') && (c != ','))
                    {
                        parameter.Append(c);
                    }
                    else
                    {
                        i++;
                        return parameter;
                    }
                }

                if(c == '>')
                    ignore = false;

            }
            return parameter;
        }

        /// <summary>
        /// Metoda postavlja sve paramtere potrebne za crtanje slike pomocu raytracinga
        /// </summary>
        public void read ()
        {
            CultureInfo c = CultureInfo.InvariantCulture;
            float x = float.Parse(getNextParameter().ToString(), c);
            float y = float.Parse(getNextParameter().ToString(), c);
            float z = float.Parse(getNextParameter().ToString(), c);
            eyePosition = new Point(x, y, z);

            screenSize = float.Parse(getNextParameter().ToString(), c);
            screenResolution = float.Parse(getNextParameter().ToString(), c);

            x = float.Parse(getNextParameter().ToString(), c);
            y = float.Parse(getNextParameter().ToString(), c);
            z = float.Parse(getNextParameter().ToString(), c);
            lightPosition = new Point(x, y, z);
            numberOfObjects = float.Parse(getNextParameter().ToString(), c);

            sphereParameters = new SphereParameters[Convert.ToInt32(numberOfObjects)];

            for(int j = 0; j < Convert.ToInt32(numberOfObjects); j++)
            {
                x = float.Parse(getNextParameter().ToString(), c);
                y = float.Parse(getNextParameter().ToString(), c);
                z = float.Parse(getNextParameter().ToString(), c);
                Point centerPosition = new Point(x, y, z);

                float radius = float.Parse(getNextParameter().ToString(), c);

                float[] raysContributions = { 0, 0 };
                float contribution = float.Parse(getNextParameter().ToString(), c);
                raysContributions[0] = contribution;
                contribution = float.Parse(getNextParameter().ToString(), c);
                raysContributions[1] = contribution;

                PropertyVector[] materialParameters = new PropertyVector[3];
                float k1 = float.Parse(getNextParameter().ToString(), c);
                float k2 = float.Parse(getNextParameter().ToString(), c);
                float k3 = float.Parse(getNextParameter().ToString(), c);
                materialParameters[0] = new PropertyVector(k1, k2, k3);

                k1 = float.Parse(getNextParameter().ToString(), c);
                k2 = float.Parse(getNextParameter().ToString(), c);
                k3 = float.Parse(getNextParameter().ToString(), c);
                materialParameters[1] = new PropertyVector(k1, k2, k3);

                k1 = float.Parse(getNextParameter().ToString(), c);
                k2 = float.Parse(getNextParameter().ToString(), c);
                k3 = float.Parse(getNextParameter().ToString(), c);
                materialParameters[2] = new PropertyVector(k1, k2, k3);

                k1 = float.Parse(getNextParameter().ToString(), c);
                n = k1;

                k1 = float.Parse(getNextParameter().ToString(), c);

                ni = k1;
                sphereParameters[j] = new SphereParameters(centerPosition, radius, raysContributions, materialParameters, n, ni);
            }
        }

        /// <summary>
        /// Metoda vraca poziciju oka.
        /// </summary>
        /// <returns>pozicija oka</returns>
        public Point getEyePosition ()
        {
            return eyePosition;
        }

        /// <summary>
        /// Metoda vraca poziciju svijetla.
        /// </summary>
        /// <returns>pozicija svijetla</returns>
        public Point getLightPosition ()
        {
            return lightPosition;
        }

        /// <summary>
        /// Metoda vraca velicinu ekrana.
        /// </summary>
        /// <returns>velicina ekrana</returns>
        public int getScreenSize ()
        {
            return Convert.ToInt32(screenSize);
        }

        /// <summary>
        /// Metoda vraca rezoluciju ekrana odnosno slike.
        /// </summary>
        /// <returns>rezolucija ekrana</returns>
        public int getScreenResolution ()
        {
            return Convert.ToInt32(screenResolution);
        }

        /// <summary>
        /// Metoda vraca broj objekata u sceni.
        /// </summary>
        /// <returns>broj objekata u sceni</returns>
        public int getNumberOfObjects ()
        {
            return Convert.ToInt32(numberOfObjects);
        }

        /// <summary>
        /// Metoda vraca parametre svih kugli u sceni.
        /// </summary>
        /// <returns>parametre svih kugli</returns>
        public SphereParameters[] getSphereParameters ()
        {
            return sphereParameters;
        }
    }
}