package raytracing;

/**
 * <p>Title: Point</p>
 * <p>Description: </p>
 * Predstavlja tocku u prostoru.
 * <p>Copyright: Copyright (c) 2003</p>
 * @author Milenka Gadze, Miran Mosmondor
 * @version 1.1
 */

public class Point {

  private double x,y,z;


  /**
   * Glavni konstruktor koji kreira novu tocku s koordinatama x,y i z.
   *
   * @param x koordinata tocke
   * @param y koordinata tocke
   * @param z koordinata tocke
   */
  public Point(double x, double y, double z) {
    this.x=x;
    this.y=y;
    this.z=z;
  }

  /**
   * Konstruktor koji kreira novu tocku koja je za vrijednost t udaljena u
   * smjeru vektora direction od pocetne tocke.
   *
   * @param startingPoint pocetna tocka od koje se odreduje nova tocka
   * @param direction vektor smjera u kojem se odreduje nova tocka
   * @param t udaljenost noce tocke od pocetne
   */
  public Point(Point startingPoint, Vector direction, double t) {
    x=startingPoint.getX()+(direction.getX()*t);
    y=startingPoint.getY()+(direction.getY()*t);
    z=startingPoint.getZ()+(direction.getZ()*t);
  }

  /**
   * Vraca x koordinatu polozaja tocke.
   *
   * @return x koordinata tocke
   */
  public double getX() {
    return x;
  }

  /**
   * Vraca y koordinatu polozaja tocke.
   *
   * @return y koordinata tocke
   */
  public double getY() {
    return y;
  }

  /**
   * Vraca z koordinatu polozaja tocke.
   *
   * @return z koordinata tocke
   */
  public double getZ() {
    return z;
  }

  /**
   * Vraca udajenost tocke od tocke p.
   *
   * @param p tocka od koje se odreduje udaljenost
   * @return udaljenost tocke od tocke p
   */
  public double getDistanceFrom(Point p) {
    return Math.sqrt(Math.pow(x-p.getX(),2) +
                     Math.pow(y-p.getY(),2) +
                     Math.pow(z-p.getZ(),2));
  }
}