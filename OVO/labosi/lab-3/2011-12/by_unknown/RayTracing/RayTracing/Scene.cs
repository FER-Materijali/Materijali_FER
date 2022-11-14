using System;

namespace raytracing
{
    /// <summary>
    /// Klasa predstvlja scenu kod modela crtanja slike pomocu ray tracinga. Sastoji
    /// se od izvora svjetlosti i konacnog broja objekata.
    /// </summary>
    public class Scene
    {
        const int MAXDEPTH = 5; //maksimalna dubina rekurzije
        private int numberOfObjects;
        private Sphere[] sphere;
        private Point lightPosition;
        private ColorVector backgroundColors = new ColorVector(0, 0, 0);
        private ColorVector light = new ColorVector((float)1, (float)1, (float)1);
        private ColorVector ambientLight = new ColorVector((float)0.5, (float)0.5, (float)0.5);

        /// <summary>
        /// Inicijalni konstruktor koji postavlja poziciju svijetla i parametre svih
        /// objekata u sceni.
        /// </summary>
        /// <param name="lightPosition">pozicija svijetla</param>
        /// <param name="numberOfObjects">broj objekata u sceni</param>
        /// <param name="sphereParameters">parametri svih kugli</param>
        public Scene(Point lightPosition, int numberOfObjects, SphereParameters[] sphereParameters)
        {
            this.lightPosition = lightPosition;
            this.numberOfObjects = numberOfObjects;
            sphere = new Sphere[numberOfObjects];
            for (int i = 0; i < numberOfObjects; i++)
            {
                sphere[i] = new Sphere(sphereParameters[i]);
            }
        }

        /// <summary>
        /// Metoda provjerava da li postoji sjena na tocki presjeka. Vraca true ako
        /// se zraka od mjesta presjeka prema izvoru svjetlosti sjece s nekim objektom.
        /// </summary>
        /// <param name="intersection">tocka presjeka</param>
        /// <returns>true ako postoji sjena u tocki presjeka, false ako ne postoji</returns>
        private bool shadow(Point intersection)
        {
            Ray ShadowRay = new Ray(intersection, lightPosition);


            for (int i = 0; i < this.numberOfObjects; i++)
            {
                if (this.sphere[i].intersection(ShadowRay)) return true;
            }

            return false;

        }

        /// <summary>
        /// Metoda koja pomocu pracenja zrake racuna boju u tocki presjeka. Racuna se
        /// osvjetljenje u tocki presjeka te se zbraja s doprinosima osvjetljenja koje
        /// donosi reflektirana i refraktirana zraka.
        /// </summary>
        /// <param name="ray">pracena zraka</param>
        /// <param name="depth">dubina rekurzije</param>
        /// <returns>vektor boje u tocki presjeka</returns>
        public ColorVector traceRay(Ray ray, int depth)
        {
            ColorVector Clocal = backgroundColors;
	        ColorVector C = new ColorVector(0, 0, 0);
	        int tocka_najblizeg_presjeka=-1;
	        bool presjek=false;

	        if(depth > MAXDEPTH) 
            {
		        C = new ColorVector(0,0,0); 
		        return C;	  
	        }
	        else 
            {
		        for(int i=0; i< this.numberOfObjects;i++) 
                {
			        if(sphere[i].intersection(ray)) 
                    {
				        presjek=true;
				        if(tocka_najblizeg_presjeka==-1) tocka_najblizeg_presjeka=i;
				        if(ray.getStartingPoint().getDistanceFrom(sphere[tocka_najblizeg_presjeka].getIntersectionPoint())>ray.getStartingPoint().getDistanceFrom(sphere[i].getIntersectionPoint())) tocka_najblizeg_presjeka=i;
			        }
		        }  
		  
		    
		    if(presjek) 
            {
                PropertyVector ambijetalniKoef = sphere[tocka_najblizeg_presjeka].getKa();		  
			    double r, g, b, pom;
			  
			    r = ambientLight.getRed()*ambijetalniKoef.getRedParameter();
			    g = ambientLight.getGreen()*ambijetalniKoef.getGreenParameter();
			    b = ambientLight.getBlue()*ambijetalniKoef.getBlueParameter();
			    Clocal = new ColorVector((float)r, (float)g, (float)b);
			  
			    Point najblizatocka = sphere[tocka_najblizeg_presjeka].getIntersectionPoint();
			  
			    PropertyVector difuzniKoef = sphere[tocka_najblizeg_presjeka].getKd();
			  
			    Vector L = new Vector(najblizatocka, lightPosition);
			    Vector N = sphere[tocka_najblizeg_presjeka].getNormal(najblizatocka);
		  	    Vector V = new Vector(najblizatocka, ray.getStartingPoint()); 
		  	    Vector R = L.getReflectedVector(N);
		  	
		  	    V.normalize();
		  	    R.normalize();
		  	    L.normalize();
		  	
		  	    double ni = sphere[tocka_najblizeg_presjeka].getNi();	
		  	    double vn = V.dotProduct( N );
		  	    if( vn < 0 ) 
                {
		  		    N = N.multiple( -1 );  
		  		    ni = 1.0/ni;
		  	    }
		  	
		  	    bool sjena = shadow(najblizatocka);
		  	    
		  	    if((pom=L.dotProduct(N))>0 && !sjena) 
                {
		  		    r = light.getRed()*difuzniKoef.getRedParameter()*pom;
		  		    g = light.getGreen()*difuzniKoef.getGreenParameter()*pom;
		  		    b = light.getBlue()*difuzniKoef.getBlueParameter()*pom;
		  
		  		    ColorVector Cdifuzno = new ColorVector((float)r, (float)g, (float)b);
		  		    Clocal = Clocal.add(Cdifuzno);
		  	    }
				  
		  	    PropertyVector spekularniKoef = sphere[tocka_najblizeg_presjeka].getKs();
		  	  
		  	    if((pom=R.dotProduct(V))>0 && !sjena)
                {
		  		    r = light.getRed()*spekularniKoef.getRedParameter()*Math.Pow(pom,sphere[tocka_najblizeg_presjeka].getN());
		  		    g = light.getGreen()*spekularniKoef.getGreenParameter()*Math.Pow(pom, sphere[tocka_najblizeg_presjeka].getN());
		  		    b = light.getBlue()*spekularniKoef.getBlueParameter()*Math.Pow(pom, sphere[tocka_najblizeg_presjeka].getN());
			
		  		    ColorVector Cspekularno= new ColorVector ((float)r, (float)g, (float)b);
		  		    Clocal = Clocal.add(Cspekularno);
		  	    }
					  
		  	    Vector ReflektiraniV = V.getReflectedVector(N);
		  	    ReflektiraniV.normalize();
		
		  	    Ray Rrefl = new Ray(najblizatocka, ReflektiraniV);
		  	    ColorVector Crefl = traceRay(Rrefl,depth+1);
				 
				 
		  	    Vector U = V.getRefractedVector(N, ni); 
		  	    U.normalize();
		  	  
			    Ray Rrefr = new Ray(najblizatocka, U);
			    ColorVector Crefr = traceRay(Rrefr,depth+1);
			
			    C = C.add(Clocal);
				 
			    C = C.add(Crefl.multiple(sphere[tocka_najblizeg_presjeka].getReflectionFactor()));
			    C = C.add(Crefr.multiple(sphere[tocka_najblizeg_presjeka].getRefractionFactor()));
			    C.correct(); 
				
			    return C;
		    }
		    else 
            {
			    return C = new ColorVector(backgroundColors.getRed(), backgroundColors.getBlue(), backgroundColors.getGreen());
		    }
        }
        }
    }
}