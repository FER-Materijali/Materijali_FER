package raytracing;

/**
 * <p>Title: Ray</p>
 * <p>Description: </p>
 * Klasa predstavlja zraku svjetla u prostoru. Zraka je odredena pocetnom tockom
 * tj. izvoristem i jedinicnim vektorom smjera.
 * <p>Copyright: Copyright (c) 2003</p>
 * @author Milenka Gadze, Miran Mosmondor
 * @version 1.1
 */

public class Ray {

  Point startingPoint;
  Vector direction;

  /**
   * Konstruktor koji stvara zraku odredenu dvijema tockama. Tocka firstPoint
   * predstavlja pocetnu tocku (izvoriste), a tocka secondPoint sluzi za
   * odredivanje vektora smjera zrake.
   *
   * @param firstPoint izvor zrake
   * @param secondPoint tocka prema kojoj je usmjerena zraka
   */
  public Ray(Point firstPoint, Point secondPoint) {
    startingPoint=firstPoint;
    direction=new Vector(firstPoint, secondPoint);
    direction.normalize();
  }

  /**
	* Konstruktor koji stvara zraku odredjenu pocetnom tockom (izvoristem)
	* i vektorom smjera.
	*
	* @param firstPoint pocenta tocka (izvorsite) zrake
	* @param direction vektor smjera zrake
	*/
  public Ray(Point firstPoint, Vector direction) {
    startingPoint = firstPoint;
    this.direction = direction;
    direction.normalize();
  }

  /**
   * Vraca pocetnu tocku zrake.
   *
   * @return pocetna tocka zrake
   */
  public Point getStartingPoint() {
    return startingPoint;
  }

  /**
   * Vraca vektor smjera zrake.
   *
   * @return vektor smjera zrake
   */
  public Vector getDirection() {
    return direction;
  }
}