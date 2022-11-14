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
	  
	  double alfa,alfaST,pom, brojnik, nazivnik, duljPC;
	  
	  Vector PC = new Vector(ray.startingPoint, this.getCenterPosition());	  //racunan kut izmedju vektora smjera zrake Direction i vektora PC
	  
	  duljPC = Math.sqrt(PC.getX()*PC.getX()+PC.getY()*PC.getY()+PC.getZ()*PC.getZ()); // |PC|
	  alfa= ray.direction.getAngle(PC);
	  if((alfa*180.0/Math.PI)>90) return false; //pretvaran radijane u stupnjeve i gledam je li veæe od 90°
  
	  double d; 				
	  d= duljPC*Math.sin(alfa);		// d= |PC| * sin(alfa)
	  rayDistanceFromCenter=d;
	  
	  if(d>this.radius) return false;   //testiramo dali zraka sjece kuglu
	  double PD; 						//udaljenost hvatista PD = |PC|^2 - d^2 
	  PD= Math.sqrt(PC.getLength()*PC.getLength() - d*d);
	  
	  double PBlizi, PDalji; 						//udaljenost hvatista od blizeg presjeka
	  PBlizi = PD - Math.sqrt(radius*radius - d*d);
	  
	  if(PBlizi <= (0 + this.Epsilon))
		  PBlizi = PDalji = PD + (Math.sqrt(radius*radius - d*d));

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
  public Vector getNormal(Point point) { //raèunan normalu
	  Ray ray = new Ray(this.centerPosition, point);
	  Vector normal = ray.direction;
	  
	  return normal;
	    
  }


}