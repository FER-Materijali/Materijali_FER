import vrml.external.*;
import vrml.external.field.*;
import vrml.external.exception.*;
import java.awt.*;
import java.applet.*;
import java.awt.event.*;

public class SuncevSustavEAI extends Applet  {

  Browser browser = null;

  /**
   * Inicijalizaija appleta. 
   * For petljom dobiva se prvi embed (uklju?eni objekt) u html stranici,
   * u nasem slucaju je to VRML scena.
   */
  public void init() {
    for (int i = 0; i < 20; i++)
    {
      browser = Browser.getBrowser(this, "", 0);
      if (browser != null)
        break;
      try
      {
        Thread.sleep(200);
      }
      catch (InterruptedException e)
      {
        break;
      }
    }
  }

  public void start() {
  }

}