package raytracing;

/**
 * <p>Title: PropertyVector</p>
 * <p>Description: </p>
 * Pomocna klasa koja predstavlja vektor svojstva, odnosno parametara materijala.
 * Naime, neko svojstvo materijala, na primjer ambijentni koeficijent, je razlicito
 * za razlicite boje (crvenu, zelenu i plavu). Zbog toga se to svojstvo moze
 * prikazati vektorom koji sadrzi tri razlicite parametre (za svaku boju).
 * <p>Copyright: Copyright (c) 2003</p>
 * @author Milenka Gadze, Miran Mosmondor
 * @version 1.1
 */

public class PropertyVector {

  private float red, green, blue;

  /**
   * Inicijalni konstruktor koji postavlja vrijednost parametara za racunanje s
   * crvenom, zelenom i plavom komponentom boje.
   *
   * @param red parametar za racunanje s crvenom komponentom boje
   * @param green parametar za racunanje s zelenom komponentom boje
   * @param blue parametar za racunanje s plavom komponentom boje
   */
  public PropertyVector(float red, float green, float blue) {
    this.red=red;
    this.green=green;
    this.blue=blue;
  }

  /**
   * Vraca parametar za racunanje s crvenom komponentom boje.
   *
   * @return parametar za racunanje s crvenom komponentom boje
   */
  public float getRedParameter() {
    return red;
  }

  /**
   * Vraca parametar za racunanje s zelenom komponentom boje.
   *
   * @return parametar za racunanje s zelenom komponentom boje
   */
  public float getGreenParameter() {
    return green;
  }

  /**
   * Vraca parametar za racunanje s plavom komponentom boje.
   *
   * @return parametar za racunanje s plavom komponentom boje
   */
  public float getBlueParameter() {
    return blue;
  }


  /**
   * Mnozi vektor s skalarom.
   *
   * @param factor skalra s kojim se mnozi
   * @return umnozak vektora s skalarom
   */
  public PropertyVector multiple(double factor) {
    return new PropertyVector((float)factor*red, (float)factor*green, (float)factor*blue);
  }

  /**
   * Koristi se za mnozenje s vektorom boje.
   *
   * @param c vektor boje s kojim se mnozi
   * @return vektor parametarara koji je rezultat mnozenja
   */
  public PropertyVector multiple(ColorVector c) {
    return new PropertyVector(c.getRed()*red, c.getGreen()*green, c.getBlue()*blue);
  }



}