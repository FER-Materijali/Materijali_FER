package raytracing;

/**
 * <p>Title: Object</p>
 * <p>Description: </p>
 * Apstraktna klasa koju nasljeduje svaki objekt u sceni. Predstavlja apstraktni
 * objekt koji je odreden svojom pozicijom u prostoru, parametrima materijala i
 * doprinosima pojedine zrake (odbijena i lomljena).
 * <p>Copyright: Copyright (c) 2003</p>
 * @author Milenka Gadze, Miran Mosmondor
 * @version 1.1
 */

public abstract class Object {

  protected Point centerPosition;
  protected PropertyVector ka, kd, ks;
  protected float reflection, refraction, ni,n;

  /**
   * Inicijalni konstruktor koji postavlja poziciju objekta, doprinose zraka i
   * paramtere materijala.
   *
   * @param centerPosition pozicija centra objekta
   * @param raysContributions doprinosi lomljene i refraktirane zrake
   * @param materialParameters parametri materijala
   * @param n faktor jacine spekularne komponente
   * @param ni indeks loma
   */
  public Object(Point centerPosition, float[] raysContributions, PropertyVector[] materialParameters,float n, float ni) {
    this.centerPosition=centerPosition;
    this.reflection=raysContributions[0];
    this.refraction=raysContributions[1];
    this.ka=materialParameters[0];
    this.kd=materialParameters[1];
    this.ks=materialParameters[2];
    this.n=n;
    this.ni=ni;
  }

  /**
   * Vraca poziciju objekta u prostoru.
   *
   * @return pozicija centra
   */
  public Point getCenterPosition() {
    return centerPosition;
  }

  /**
   * Vraca koeficijent odbijanja ambijentne komponente materijala.
   *
   * @return ambijentni koeficijent
   */
  public PropertyVector getKa() {
    return ka;
  }

  /**
   * Vraca koeficijent odbijanja difuzne komponente materijala.
   *
   * @return difuzni koeficijent
   */
  public PropertyVector getKd() {
    return kd;
  }

  /**
   * Vraca koeficijent odbijanja spekularne komponente materijala.
   *
   * @return spekularni koeficijent
   */
  public PropertyVector getKs() {
    return ks;
  }

  /**
   * Vraca faktor jacine spekularne komponente
   *
   * @return faktor jacine spekularne komponente
   */
  public float getN() {
    return n;
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
   * Vraca udio odbijene zrake.
   *
   * @return udio odbijene zrake
   */
  public float getReflectionFactor() {
    return reflection;
  }

  /**
   * Vraca udio lomljene zrake.
   *
   * @return udio lomljene zrake
   */
  public float getRefractionFactor() {
    return refraction;
  }

  /**
   * Apstraktna metoda koja se implementira u podklasi. Ako postoji presjek
   * objekta i zrake ray postavlja tocke presjeka nearIntersectionPoint i
   * farIntersectionPoint, te vraca logicku vrijednost true.
   *
   * @param ray zraka za koju se ispituje presjek sa objektom
   * @return true ako postoji presjek sa zrakom, false ako ne postoji
   */
  public abstract boolean intersection(Ray ray);

  /**
   * Apstraktna metoda koja se implementira u podklasi. Vraca tocku presjeka
   * objekta sa zrakom koja je bliza pocetnoj tocki zrake.
   *
   * @return tocka presjeka objekta sa zrakom, koja je bliza izvoru zrake, a
   * postavlja se pozivom metode intersection
   */
  public abstract Point getIntersectionPoint();


    /**
     * Vraca normalu na tijelu u tocki point
     *
     * @param point na kojoj se racuna normala na kugli
     * @return normal vektor normale
     */
  public abstract Vector getNormal(Point point);

}