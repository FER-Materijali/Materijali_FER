package raytracing;

/**
 * <p>Title: Scene</p>
 * <p>Description: </p>
 * Klasa predstvlja scenu kod modela crtanja slike pomocu ray tracinga. Sastoji
 * se od izvora svjetlosti i konacnog broja objekata.
 * <p>Copyright: Copyright (c) 2003</p>
 * @author Milenka Gadze, Miran Mosmondor
 * @version 1.1
 */

import java.awt.*;
import javax.swing.*;
import java.awt.geom.*;
import java.awt.event.*;

public class Scene {

  final int MAXDEPTH=5; //maksimalna dubina rekurzije
  private int numberOfObjects;
  private Sphere[] sphere;
  private Point lightPosition;
  private ColorVector backroundColors=new ColorVector(0, 0, 0);
  private ColorVector light=new ColorVector((float)1 , (float)1,(float)1);
  private ColorVector ambientLight=new ColorVector((float)0.5, (float)0.5, (float)0.5);

  /**
   * Inicijalni konstruktor koji postavlja poziciju svijetla i parametre svih
   * objekata u sceni.
   *
   * @param lightPosition pozicija svijetla
   * @param numberOfObjects broj objekata u sceni
   * @param sphereParameters parametri svih kugli
   */
  public Scene(Point lightPosition, int numberOfObjects, SphereParameters[] sphereParameters) {
    this.lightPosition=lightPosition;
    this.numberOfObjects=numberOfObjects;
    sphere=new Sphere[numberOfObjects];
    for (int i=0; i<numberOfObjects; i++) {
      sphere[i]=new Sphere(sphereParameters[i]);
    }
  }

  /**
   * Metoda provjerava da li postoji sjena na tocki presjeka. Vraca true ako
   * se zraka od mjesta presjeka prema izvoru svjetlosti sjece s nekim objektom.
   *
   * @param intersection tocka presjeka
   * @return true ako postoji sjena u tocki presjeka, false ako ne postoji
   */
  private boolean shadow(Point intersection) {
	  Ray ShadowRay = new Ray (intersection, lightPosition); //nova zraka koja ide od presjecišta sa vektorom do izvora

	  for (int i=0; i< this.numberOfObjects;i++) {				  //za svaki objekt testiran je li zraka prolazi kroz njega
	
		  if(this.sphere[i].intersection(ShadowRay)) return true; //ako se presjeèe, vraæan true
	  }  
	  return false;
  }

  /**
   * Metoda koja pomocu pracenja zrake racuna boju u tocki presjeka. Racuna se
   * osvjetljenje u tocki presjeka te se zbraja s doprinosima osvjetljenja koje
   * donosi reflektirana i refraktirana zraka.
   *
   * @param ray pracena zraka
   * @param depth dubina rekurzije
   * @return vektor boje u tocki presjeka
   */
  public ColorVector traceRay(Ray ray, int depth) {
	  ColorVector Clocal = backroundColors;
	  ColorVector C = new ColorVector(0, 0, 0); //inicijaliziram boju
	  int najbliza=-1;
	  boolean presjek=false;
	  
	  if(depth > MAXDEPTH) {
		  C = new ColorVector(0,0,0); 	//ako se proðe dubina rekurzije, vraæan crnu boju
		  return C;
		  
		  
	  } else {
		  for(int i=0; i< this.numberOfObjects;i++) {	//petlja traži najbliži objekt koji je zraka pogodila
			  	  if(sphere[i].intersection(ray)) {
			  		  presjek=true; // ako postoji presjek, stavljan true
				 
				  
				  if(najbliza==-1) najbliza=i;
				  if(ray.getStartingPoint().getDistanceFrom(sphere[najbliza].getIntersectionPoint())>ray.getStartingPoint().getDistanceFrom(sphere[i].getIntersectionPoint()))
					  najbliza=i;
			  }
		  }  
		  
		  
if(presjek) {
	
//Mr. Phong
				  

				  PropertyVector ambijetalniKoef = sphere[najbliza].ka;			//èitan ambijentalnu komponentu najbliže kugle  
				  double r, g, b, pom;
				  
				  r = ambientLight.getRed()*ambijetalniKoef.getRedParameter(); //raèunan boje te boju C iz tih komponenata
			  	  g = ambientLight.getGreen()*ambijetalniKoef.getGreenParameter();
			  	  b = ambientLight.getBlue()*ambijetalniKoef.getBlueParameter();
			  	  Clocal = new ColorVector((float)r, (float)g, (float)b);
			  	  Point najblizatocka = sphere[najbliza].getIntersectionPoint();
			  	  
			  	  

				  PropertyVector diKoef = sphere[najbliza].kd; 			//difuzni dio osvjetljenja, raèunanje normale i vektora
				  Vector L = new Vector(najblizatocka, lightPosition);
				  Vector N = sphere[najbliza].getNormal(najblizatocka);
				  Vector V = new Vector(najblizatocka, ray.getStartingPoint()); 
				  Vector R = new Vector();
				  R = L.getReflectedVector(N);

				  V.normalize(); //normaliziram vektore
				  R.normalize();
				  L.normalize();
				  
				  
				  

				  
				  double ni = sphere[najbliza].getNi();	 //ako sam unutar kugle, stavljam reciproènu vrijednost za index loma, da bude suprotan smjer
			      double vn = V.dotProduct( N );
			        if( vn < 0 ) {
			           N = N.multiple( -1 );  
			           ni = 1./ni;
			        }
				  
				  

			      boolean sjena = shadow(najblizatocka); //ako umnozak  L*N veæi od nule i ako nije u sjeni, racunaj osvjetljenje
				  if((pom=L.dotProduct(N))>0 && !sjena) {
				  	r = light.getRed()*diKoef.getRedParameter()*pom;
				  	g = light.getGreen()*diKoef.getGreenParameter()*pom;
				  	b = light.getBlue()*diKoef.getBlueParameter()*pom;
				  	ColorVector Cdifuzno = new ColorVector((float)r, (float)g, (float)b);
				  	Clocal = Clocal.add(Cdifuzno);
				  }
				  
				  
				  
				  PropertyVector spekularniKoef = sphere[najbliza].ks; //èitanje spekularnog koeficijenta najbliže kugle

				  
				  if((pom=R.dotProduct(V))>0 && !sjena){				//ako je umnozak RxV veæi od 0 i ako nije u sjeni racunan spekularno osvjetljenje
				  r = light.getRed()*spekularniKoef.getRedParameter()*Math.pow(pom,sphere[najbliza].getN()); //ponovno raèunanje RGB-a
				  g = light.getGreen()*spekularniKoef.getGreenParameter()*Math.pow(pom, sphere[najbliza].getN());
				  b = light.getBlue()*spekularniKoef.getBlueParameter()*Math.pow(pom, sphere[najbliza].getN());
				  ColorVector Cspekularno= new ColorVector ((float)r, (float)g, (float)b);
				  Clocal = Clocal.add(Cspekularno); //dodajen spekularnu komponentu na color vektor
				  }
							  
Vector ReflektiraniV = new Vector (); //reflekcija
ReflektiraniV = V.getReflectedVector(N);
ReflektiraniV.normalize();

Ray Rrefl = new Ray(najblizatocka, ReflektiraniV); //ponovno pozivan raytrace funkciju za reflektirani vektor, rekurzivno, poveæajen dubinu za jedan
ColorVector Crefl = traceRay(Rrefl,depth+1);
		 
Vector U = new Vector();  //refrakcija
U = V.getRefractedVector(N, ni); 
U.normalize();
				 
				 

Ray Rrefr = new Ray(najblizatocka, U);  //isto kao i gore, samo sa refraktiranim vektorom
ColorVector Crefr = traceRay(Rrefr,depth+1);
				 	
C = C.add(Clocal);//dodavanje komponenti reflektirane i refraktirane zrake pomnozen sa faktorom refleksije/refrakcije
C = C.add(Crefl.multiple(sphere[najbliza].getReflectionFactor()));
C = C.add(Crefr.multiple(sphere[najbliza].getRefractionFactor()));
C.correct(); 
				 // korekcija boje tako da bude unutar intervala (0,1)
				
				  return C;
			  } 
else {		//ako nema boje, vraæam crnu :)
return C = new ColorVector(backroundColors.getRed(), backroundColors.getBlue(), backroundColors.getGreen());
			  }
			  
		  	}
  }
}