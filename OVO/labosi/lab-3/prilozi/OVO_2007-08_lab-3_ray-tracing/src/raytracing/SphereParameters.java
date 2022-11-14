package raytracing;

/**
 * <p>Title: SphereParameters</p>
 * <p>Description: </p>
 * Pomocna klasa koja objedinjuje sve parametre kugle. Parametri kugle su :
 * pozicija centra kugle, radijus, udjeli pojedinih zraka (odbijene i
 * lomljene) i parametri materijala.
 * <p>Copyright: Copyright (c) 2003</p>
 * @author Milenka Gadze, Miran Mosmondor
 * @version 1.1
 */

public class SphereParameters {
  private Point centerPosition;
  private float radius, ni,n;
  private float[] raysContributions;
  private PropertyVector[] materialParameters;

  /**
   * Inicijalni konstruktor koji postavlja sve parametre.
   *
   * @param centerPosition pozicija centra kugle
   * @param radius radijus kugle
   * @param raysContributions udjeli odbijene i refraktirane zrake
   * @param materialParameters parametri materijala kugle
   * @param n faktor jacine spekularne komponente
   * @param ni faktor refrakcije
   */
  public SphereParameters(Point centerPosition, float radius, float[] raysContributions, PropertyVector[] materialParameters, float n, float ni) {
    this.centerPosition=centerPosition;
    this.radius=radius;
    this.raysContributions=raysContributions;
    this.materialParameters=materialParameters;
    this.n=n;
    this.ni=ni;
  }

  /**
   * Vraca poziciju centra.
   *
   * @return pozicija centra
   */
  public Point getCenterPosition() {
    return centerPosition;
  }

  /**
   * Vraca radijus.
   *
   * @return radijus kugle
   */
  public float getRadius() {
    return radius;
  }


  /**
   * Vraca udjele pojednih zraka (odbijene i lomljene).
   *
   * @return udjeli odbijene i refraktirane zrake
   */
  public float[] getRaysContributions() {
    return raysContributions;
  }

  /**
   * Vraca parametre materijala.
   *
   * @return parametri materijala
   */
  public PropertyVector[] getMaterialParameters() {
    return materialParameters;
  }

  /**
   * Vraca indeks loma
   *
   * @return indeks loma
   */
  public float getNi() {
    return ni;
  }

  /**
   * Vraca faktor jacine spekularne komponente
   *
   * @return faktor jacine spekularne komponente
   */
  public float getN() {
    return n;
  }
}