package raytracing;

/**
 * <p>Title: FileReader</p>
 * <p>Description: </p>
 * Klasa koja sluzi za citanje iz tekstualne datoteke svih podataka potrebnih
 * za crtanje slike pomocu ray tracinga. Pri citanju ignorira sve sto se nalazi
 * unutar ostrih zagrada <>, a kao decimalni broj tretira podatak zapisan izmedu
 * zareza ili dvotocki.
 * <p>Copyright: Copyright (c) 2003</p>
 * @author Milenka Gadze, Miran Mosmondor
 * @version 1.1
 */

import java.io.*;
import java.io.Reader;

public class FileReader {
  private int length, i=0;
  private String input;
  private Point eyePosition, lightPosition;
  private Float screenSize, screenResolution, numberOfObjects;
  private SphereParameters[] sphereParameters;
  private float ni,n;

  /**
   *
   * Konstruktor koji otvara datoteku i cijeli sadrzaj datoteke sprema u
   * varijablu input.
   *
   * @param fileName ime datoteke iz koje se cita
   */
  public FileReader(String fileName) {
    try {
      RandomAccessFile fileIn = new RandomAccessFile(fileName, "r");
      length=(int)fileIn.length();
      byte buff[] = new byte[length];
      fileIn.read(buff);
      input = new String(buff);
      fileIn.close();
    }
    catch(FileNotFoundException e) {
      System.out.println("File <"+fileName+"> not found!");
      System.exit(0);
    }
    catch(IOException e) {
    }
  }

  /**
   * Metoda koja uzima sljedeci niz znakova koji se nalazi unutar zareza ili
   * dvotocki. Sve znakove unutar kosih zagrada <> ignorira.
   *
   * @return slijedeci niz znakova koji se nalazi izmedu zareza ili dvotocki
   */
  public StringBuffer getNextParameter() {
    boolean ignore=false;
    StringBuffer parameter=new StringBuffer();
    for(; i<length; i++) {
      char c=input.charAt(i);

      if (c=='<') ignore=true;

      if (!ignore) {
        if ((c!=':')&&(c!=',')) {
          parameter.append(c);
        }
        else {
          i++;
          return parameter;
        }
      }

      if (c=='>') ignore=false;

    }
    return parameter;
  }

  /**
   * Metoda postavlja sve paramtere potrebne za crtanje slike pomocu ray
   * tracinga.
   */
  public void read() {
    Float x=new Float(getNextParameter().toString());
    Float y=new Float(getNextParameter().toString());
    Float z=new Float(getNextParameter().toString());
    eyePosition=new Point(x.floatValue(), y.floatValue(), z.floatValue());

    screenSize=new Float(getNextParameter().toString());
    screenResolution=new Float(getNextParameter().toString());

    x=new Float(getNextParameter().toString());
    y=new Float(getNextParameter().toString());
    z=new Float(getNextParameter().toString());
    lightPosition=new Point(x.floatValue(), y.floatValue(), z.floatValue());
    numberOfObjects=new Float(getNextParameter().toString());

    sphereParameters=new SphereParameters[numberOfObjects.intValue()];

    for (int j=0; j<numberOfObjects.intValue(); j++) {
      x=new Float(getNextParameter().toString());
      y=new Float(getNextParameter().toString());
      z=new Float(getNextParameter().toString());
      Point centerPosition=new Point(x.floatValue(), y.floatValue(), z.floatValue());

      Float radius=new Float(getNextParameter().toString());

      float[] raysContributions={0,0};
      Float contribution=new Float(getNextParameter().toString());
      raysContributions[0]=contribution.floatValue();
      contribution=new Float(getNextParameter().toString());
      raysContributions[1]=contribution.floatValue();

      PropertyVector[] materialParameters=new PropertyVector[3];
      Float k1=new Float(getNextParameter().toString());
      Float k2=new Float(getNextParameter().toString());
      Float k3=new Float(getNextParameter().toString());
      materialParameters[0]=new PropertyVector(k1.floatValue(), k2.floatValue(), k3.floatValue());

      k1=new Float(getNextParameter().toString());
      k2=new Float(getNextParameter().toString());
      k3=new Float(getNextParameter().toString());
      materialParameters[1]=new PropertyVector(k1.floatValue(), k2.floatValue(), k3.floatValue());

      k1=new Float(getNextParameter().toString());
      k2=new Float(getNextParameter().toString());
      k3=new Float(getNextParameter().toString());
      materialParameters[2]=new PropertyVector(k1.floatValue(), k2.floatValue(), k3.floatValue());

      k1=new Float(getNextParameter().toString());
	  n=k1.floatValue();

      k1=new Float(getNextParameter().toString());

      ni=k1.floatValue();
      sphereParameters[j]=new SphereParameters(centerPosition, radius.floatValue(), raysContributions, materialParameters,n, ni);
    }
 }

  /**
   * Metoda vraca poziciju oka.
   *
   * @return pozicija oka
   */
  public Point getEyePosition() {
    return eyePosition;
  }

  /**
   * Metoda vraca poziciju svijetla.
   *
   * @return pozicija svijetla
   */
  public Point getLightPosition() {
    return lightPosition;
  }

  /**
   * Metoda vraca velicinu ekrana.
   *
   * @return velicina ekrana
   */
  public int getScreenSize() {
    return screenSize.intValue();
  }

  /**
   * Metoda vraca rezoluciju ekrana odnosno slike.
   *
   * @return rezolucija ekrana
   */
  public int getScreenResolution() {
    return screenResolution.intValue();
  }

  /**
   * Metoda vraca broj objekata u sceni.
   *
   * @return broj objekata u sceni
   */
  public int getNumberOfObjects() {
    return numberOfObjects.intValue();
  }

  /**
   * Metoda vraca parametre svih kugli u sceni.
   *
   * @return parametre svih kugli
   */
  public SphereParameters[] getSphereParameters() {
    return sphereParameters;
  }
}