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
	  //zraka od sjecišta predmeta i zrake koju originalno pratimo do izvora svijetlosti
	  Ray ShadowRay = new Ray (intersection, lightPosition);
	  
	  //ako zraka prolazi kroz predmet difuzna i spekularna komponenta imaju doprinos nula
	  //provjeriti za svaki predmet
	  for (int i=0; i< this.numberOfObjects;i++) {
		  if(this.sphere[i].intersection(ShadowRay))
			  return true;
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
	  
	  //poèetna boja je èrna (RGB = 000 => crna)
	  ColorVector C = new ColorVector(0, 0, 0);
	  int tocka_najblizeg_presjeka=-1;
	  boolean presjek=false;
	  
	  //ako rekurzija prijeðe maksimalnu dubinu vraæa se boja pozadine a to je crna
	  if(depth > MAXDEPTH) {
		  C = new ColorVector(0,0,0); 
		  return C;	  
	  }
	  else {
		  //traženje najbližeg objekta kojeg zraka pogaða
		  for(int i=0; i< this.numberOfObjects;i++) {
			  if(sphere[i].intersection(ray)) {
				  presjek=true;
				  
				  if(tocka_najblizeg_presjeka==-1) tocka_najblizeg_presjeka=i;
				  if(ray.getStartingPoint().getDistanceFrom(sphere[tocka_najblizeg_presjeka].getIntersectionPoint())>ray.getStartingPoint().getDistanceFrom(sphere[i].getIntersectionPoint()))
					  tocka_najblizeg_presjeka=i;
			  }
		  }  
		  
		  //ako presjek postoji nastavljamo s radom
		  if(presjek) {
			  
			  //odreðivanje ambijentalnog koeficijenta najbližeg objekta (kugle)
			  PropertyVector ambijetalniKoef = sphere[tocka_najblizeg_presjeka].ka;			  
			  double r, g, b, pom;
			  
			  //raèunanje komponenti boje za ambijentalnu komponentu
			  r = ambientLight.getRed()*ambijetalniKoef.getRedParameter();
			  g = ambientLight.getGreen()*ambijetalniKoef.getGreenParameter();
			  b = ambientLight.getBlue()*ambijetalniKoef.getBlueParameter();
			  //raèunanje boje na temelju komponenata
			  Clocal = new ColorVector((float)r, (float)g, (float)b);
			  
			  Point najblizatocka = sphere[tocka_najblizeg_presjeka].getIntersectionPoint();
			  
			  //odreðivanje difuznog koeficijenta najbližeg objekta (kugle)
			  PropertyVector difuzniKoef = sphere[tocka_najblizeg_presjeka].kd; 
			  
			  //racunanje normale na površinu (N) i smjera upadne zrake (L)
			  Vector L = new Vector(najblizatocka, lightPosition);
			  Vector N = sphere[tocka_najblizeg_presjeka].getNormal(najblizatocka);
		  	  Vector V = new Vector(najblizatocka, ray.getStartingPoint()); 
		  	  Vector R = new Vector();
		  	  R = L.getReflectedVector(N);
		  	
		  	  //normaliziranje vektora
		  	  V.normalize();
		  	  R.normalize();
		  	  L.normalize();
		  	
		  	  //unutar kugle index loma ima reciproènu vrijednost kako bi vektor imao suprotan smjer
		  	  double ni = sphere[tocka_najblizeg_presjeka].getNi();	
		  	  double vn = V.dotProduct( N );
		  	  if( vn < 0 ) {
		  		  N = N.multiple( -1 );  
		  		  ni = 1./ni;
		  	  }
		  	
		  	  //Phongov model osvjetljenja 
		  	  //ako tijelo nije u sijeni te ako je skalarni produkt L i N veæi od nule
		  	  boolean sjena = shadow(najblizatocka);
		  	  
		  	  if((pom=L.dotProduct(N))>0 && !sjena) {
		  		  r = light.getRed()*difuzniKoef.getRedParameter()*pom;
		  		  g = light.getGreen()*difuzniKoef.getGreenParameter()*pom;
		  		  b = light.getBlue()*difuzniKoef.getBlueParameter()*pom;
		  
		  		  ColorVector Cdifuzno = new ColorVector((float)r, (float)g, (float)b);
		  		  //dodavanje difuzne komponente
		  		  Clocal = Clocal.add(Cdifuzno);
		  	  }
				  
		  	  //odreðivanje spekularnog koeficijenta najbližeg objekta (kugle)
		  	  PropertyVector spekularniKoef = sphere[tocka_najblizeg_presjeka].ks;
		  	  
		  	  //ako tijelo nije u sijeni te ako je skalarni produkt R i V veæi od nule
		  	  if((pom=R.dotProduct(V))>0 && !sjena){
		  		  r = light.getRed()*spekularniKoef.getRedParameter()*Math.pow(pom,sphere[tocka_najblizeg_presjeka].getN());
		  		  g = light.getGreen()*spekularniKoef.getGreenParameter()*Math.pow(pom, sphere[tocka_najblizeg_presjeka].getN());
		  		  b = light.getBlue()*spekularniKoef.getBlueParameter()*Math.pow(pom, sphere[tocka_najblizeg_presjeka].getN());
			
		  		  ColorVector Cspekularno= new ColorVector ((float)r, (float)g, (float)b);
		  		  //dodavanje spekularne komponente
		  		  Clocal = Clocal.add(Cspekularno);
		  	  }
		
		  	  //Odbijena zraka
		  	  //raèunanje reflektirane zrake 				  
		  	  Vector ReflektiraniV = new Vector ();
		  	  ReflektiraniV = V.getReflectedVector(N);
		  	  ReflektiraniV.normalize();
		
		  	  //praæenje zrake za reflektirani vektor
		  	  Ray Rrefl = new Ray(najblizatocka, ReflektiraniV);
		  	  ColorVector Crefl = traceRay(Rrefl,depth+1);
				 
				 
		  	  //Lomljena zraka
		  	  //raèunanje refraktirane zrake
		  	  Vector U = new Vector();
		  	  U = V.getRefractedVector(N, ni); 
		  	  U.normalize();
		  	  
		  	  //praæenje refraktirane zrake
			Ray Rrefr = new Ray(najblizatocka, U);
			ColorVector Crefr = traceRay(Rrefr,depth+1);
			
			//dodavanje boje lokalnog osvjetljenje
			C = C.add(Clocal);
				 
			//dodavanje boja odbijene i lomljene zrake pomnoženih odgovarajuæim koeficijentima
			C = C.add(Crefl.multiple(sphere[tocka_najblizeg_presjeka].getReflectionFactor()));
			C = C.add(Crefr.multiple(sphere[tocka_najblizeg_presjeka].getRefractionFactor()));
			//korekcija boje kako bi bila unutar intervala (0,1)
			C.correct(); 
				
			return C;
		  }
		  else {
			  //ako ne postoji sjecište zrake i predmeta (tj. kugle) vraæamo boju pozadine tj. crnu
			  return C = new ColorVector(backroundColors.getRed(), backroundColors.getBlue(), backroundColors.getGreen());
		  }
			  
      }
 }
}