package raytracing;

/**
 * <p>Title: Main</p>
 * <p>Description: </p>
 * Glavna klasa.
 * <p>Copyright: Copyright (c) 2003</p>
 * @author Milenka Gadze, Miran Mosmondor
 * @version 1.1
 */

public class Main {

  public Main() {
  }
  public static void main(String[] args) {
    Picture picture=new Picture();
    picture.pack();
    picture.setSize(400,400);
    picture.setVisible(true);
  }
}