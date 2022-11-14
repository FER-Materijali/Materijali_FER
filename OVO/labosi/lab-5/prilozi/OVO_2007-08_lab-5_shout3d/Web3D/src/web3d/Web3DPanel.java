package web3d;

import shout3d.*;
import shout3d.core.*;
import java.util.*;

public class Web3DPanel extends Shout3DPanel{

  /**
   * Konstruktor koji kreira panel velicine cijelog appleta.
   * U ovoj metodi ne treba nista mijenjati.
   *
   * @param applet
   */
  public Web3DPanel (Shout3DApplet applet){
     super(applet);
  }

  /**
   * Konstruktor koji kreira panel velicine width x height.
   * U ovoj metodi ne treba nista mijenjati.
   *
   * @param applet
   * @param width
   * @param height
   */
  public Web3DPanel (Shout3DApplet applet, int width, int height){
    super(applet,width, height);
  }


  /**
   * Metoda koja se zove odmah posto je ucitana scena.
   */

  public void customInitialize() {
    /*****************
     Ovo je metoda u kojoj treba ostvariti animaciju planeta. Da biste to mogli,
     prvi je korak dobiti referencu na cvorove scene. Koristite metodu getNodeByName().

     Tim cvorovima mozete lako mijenjati polozaj i rotaciju.
     Primjerice:
     Transform SuncevSustav=(Transform)getNodeByName("SuncevSustav");
     SuncevSustav.rotation.setValueByString("1.0 0.0 0.0 1.57");

     Ako cete za rotaciju koristiti klase Timer i TimerTask, potrebno je instancirati
     timer i metodom schedule() dodati mu novi objekt klase TimerTask. Buduci je TimerTask apstraktna
     klasa, potrebno ju je ili a) naslijediti i definirati bitnu metodu run();
                               b) instancirati anonimnu klasu (lakse ali manje elegantno rijesenje).

     ****************/
  }

}