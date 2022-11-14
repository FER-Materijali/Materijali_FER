package raytracing;

/**
 * <p>Title: Sphere</p>
 * <p>Description: </p>
 * Klasa predstavlja kuglu u prostoru. Nasljeduje apstraktnu klasu Object. Kugla
 * je odredena svojim polozajem, radijusom, bojom, parametrima materijala i
 * udjelima pojedninih zraka (osnovne, odbijene i lomljene).
 * <p>Copyright: Copyright (c) 2003</p>
 * @author Milenka Gadze, Miran Mosmondor
 * @version 1.1
 */


import java.awt.*;
import javax.swing.*;
import java.awt.geom.*;
import java.awt.event.*;

public class Sphere extends Object{

  private double radius;
  final double Epsilon = 0.0001;
  private double rayDistanceFromCenter;
  private Point IntersectionPoint;

  /**
   * Inicijalni konstruktor koji postavlja sve parametre kugle. Za prijenos
   * parametara koristi se pomocna klasa SphereParameters.
   *
   * @param sphereParameters parametri kugle
   */
  public Sphere(SphereParameters sphereParameters) {
    super(sphereParameters.getCenterPosition(), sphereParameters.getRaysContributions(), sphereParameters.getMaterialParameters(),sphereParameters.getN(), sphereParameters.getNi());
    this.radius=sphereParameters.getRadius();
  }

  /**
   * Metoda ispituje postojanje presjeka zrake ray s kuglom. Ako postoji presjek
   * postavlja tocku presjeka IntersectionPoint, te
   * vraca logicku vrijednost true.
   *
   * @param ray zraka za koju se ispituje postojanje presjeka sa kuglom
   * @return logicku vrijednost postojanja presjeka zrake s kuglom
   */
  public boolean intersection(Ray ray) {
	  
	  double alfa, alfaST, pom, brojnik, nazivnik, duljinaPC;
	  
	  //raèunanje vektora od hvatišta zrake do središta kugle
	  //prema pripremi to je vektor nazvan PC
	  Vector PC = new Vector(ray.startingPoint, this.getCenterPosition());
	  
	  //raèunanje kuta izmedju smjera zrake i vektora PC
	  //raèunanje duljine vektora PC
	  duljinaPC = Math.sqrt(PC.getX()*PC.getX()+PC.getY()*PC.getY()+PC.getZ()*PC.getZ()); // |PC|
	  alfa = ray.direction.getAngle(PC);
	  
	  //kut pretvaramo u stupnjeve iz radijana
	  //ako je kut veæi od 90 stupnjeva zraka nije u smjeru predmeta
	  if((alfa*180.0/Math.PI)>90)
		  return false;
  
	  double d;
	  //koristi se formula d=|PC|*sin(alfa)
	  d = duljinaPC*Math.sin(alfa);
	  rayDistanceFromCenter=d;
	  
	  //testiranje postojanja sjecišta zrake i kugle
	  if(d > this.radius)
		  return false;
	  
	  //ako zraka sijeèe kuglu
	  double PD;
	  //koristi se formula PD=|PC|^2-d^2 
	  PD = Math.sqrt(PC.getLength()*PC.getLength()-d*d);
	  
	  double PBlizi, PDalji;
	  //izraèunavanje udaljenosti hvatišta od bližeg presjeka
	  PBlizi = PD - Math.sqrt(radius*radius - d*d);
	  
	  if(PBlizi <= (0+this.Epsilon))
		  PBlizi = PDalji = PD+(Math.sqrt(radius*radius - d*d));

	  IntersectionPoint = new Point (ray.getStartingPoint(), ray.getDirection() , PBlizi);
	  
	  return true;
  }

  /**
   * Vraca tocku presjeka kugle sa zrakom koja je bliza pocetnoj tocki zrake.
   *
   * @return tocka presjeka zrake s kuglom koja je bliza izvoru zrake
   */
  public Point getIntersectionPoint() {
	  return IntersectionPoint;  
  }

  /**
	* Vraca normalu na kugli u tocki point
	*
	* @param point na kojoj se racuna normala na kugli
	* @return normal vektor normale
	*/
  public Vector getNormal(Point tocka) {
	  //normala se raèuna tako da pustimo zraku kroz središte sfere i zadanu toèku
	  Ray ray = new Ray(this.centerPosition, tocka);
	  Vector normala = ray.direction;
	  
	  return normala;
	    
  }


}