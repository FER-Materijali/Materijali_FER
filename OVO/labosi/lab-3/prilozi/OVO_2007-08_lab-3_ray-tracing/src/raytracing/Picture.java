package raytracing;

/**
 * <p>Title: Picture</p>
 * <p>Description: </p
 * Klasa koja stvara realisticnu sliku pomocu ray tracinga. Svi potrebni
 * parametri unose se pomocu datoteke Input.txt.
 * <p>Copyright: Copyright (c) 2003</p>
 * @author Milenka Gadze, Miran Mosmondor
 * @version 1.1
 */

import java.awt.*;
import javax.swing.*;
import java.awt.geom.*;
import java.awt.event.*;


public class Picture extends JFrame {

  private int screenResolution;
  private Scene scene;
  private Screen screen;
  private Ray ray;
  private Point eyePosition;

  /**
   * Konstruktor koji pomocu klase FileReader iz datoteke Input.txt uzima i
   * postavlja sve potebne parametre za crtanje slike : poziciju oka, rezoluciju
   * ekrana (slike), velicinu ekrana, poziciju svijetla u sceni, broj objekata u
   * sceni, te parametre svih kugli u sceni.
   */
  public Picture() {

    FileReader fileReader=new FileReader("Input.txt");
    fileReader.read();

    eyePosition=fileReader.getEyePosition();
    screenResolution=fileReader.getScreenResolution();
    screen=new Screen(fileReader.getScreenSize(), screenResolution);
    scene=new Scene(fileReader.getLightPosition(), fileReader.getNumberOfObjects(), fileReader.getSphereParameters());

    //izlaz iz programa kada se zatvori prozor
    addWindowListener(new WindowAdapter() {
      public void windowClosing(WindowEvent e) {
        System.exit(0);
      }
    });
  }

  /**
   * Metoda sluzi za crtanje slike. Za svaku tocku slike (ekrana) racuna
   * boju pomocu ray tracinga.
   *
   * @param g
   */
  public void paint(Graphics g) {

    for (int j=0; j<screenResolution; j++) {
      for (int i=0; i<screenResolution; i++) {

        Point screenPoint=screen.getPoint(i,j);
        ray=new Ray(eyePosition, screenPoint);

        ColorVector colors=scene.traceRay(ray,1);
        Color c=new Color(colors.getRed(), colors.getGreen(), colors.getBlue());

        //postavljanje boje
        g.setColor(c);

        //crtanje jedne tocke ekrana
        g.drawRect(i, j, 1, 1);
      }
    }
  }


}