//
// Program: Helix Spring.
//
// Description:
//    This program calculates coordinates needed to make a helix spring
//    and sets them in 3D scene. spineLimit x crossSectionLimit = 250 x 10
//    = 2500, and thus satisfies vrml97 conformity requirements for
//    Extrusion node. The animation speed may be adjusted by altering
//    thread.sleep value, but too low values may decrease browser
//    rendering performance.
//
// Author: Vilius Jagminas, vilius@extred.com
// Version: 1.0, 12.11.2000
//
// Edited to produce a more concise spec example by Martin Reddy.
//
// Compiled against the Cortona 3 EAI classes, corteai.zip
//

import java.awt.*;
import java.applet.*;
import vrml.eai.field.*;
import vrml.eai.Node;
import vrml.eai.BrowserFactory;
import vrml.eai.Browser;

public class helix extends Applet implements Runnable {

  EventInMFVec3f spine = null;
  EventInMFVec2f crossSection = null;
  Thread thread = null;
  Choice choice;
  
  int spineLimit = 250;
  float[][] spineValue = new float[spineLimit+1][3];
  int crossSectionLimit = 10;
  float[][] crossSectionValue = new float[crossSectionLimit+1][2];
  float numCoils = 5f;

  // set up the applet controls
  public void init() {
    super.init();
    setBackground(Color.white);
    Panel p1 = new Panel();
    Label lblNCoils = new Label("Number of Coils");
    p1.add(lblNCoils);
    choice= new Choice();
    choice.addItem("5"); choice.addItem("4"); choice.addItem("3");
    choice.addItem("2"); choice.addItem("1");
    p1.add(choice);
    add(p1);
  }

  public void start() {
    // get the VRML Browser reference
    Browser browser = null;
    for (int count = 0; count < 10; count++) {
      browser = BrowserFactory.getBrowser(this);
      if (browser != null) break;
      try { Thread.sleep (200); } catch (InterruptedException e) {}
    }
    if (browser == null) {
      throw new Error("Failed to get the browser after 10 tries!");     
    }

    // get the spine and crossSection fields of the Extrusion node
    try {
      Node coil = browser.getNode("Coil");
      spine = (EventInMFVec3f) coil.getEventIn("set_spine");
      crossSection = (EventInMFVec2f) coil.getEventIn("set_crossSection");
    } catch (vrml.eai.InvalidNodeException ne){
      System.out.println("Node Exception Error:" + ne.getMessage());
    }

    if (thread == null) {
      thread = new Thread(this);
      thread.start();
    } else
      thread.resume();
  }

  public void stop() {
    if (thread != null) thread.suspend();
  }

  public void destroy() {
    thread.stop();
    thread = null;
  }

  public void run() {
    // calculate and set the crossSection values of the Extrusion node
    float thickness = 0.1f;
    float diameter = 1.5f;
    float two_pi = (float) Math.PI * 2.0f;
    for (int j = 0; j <= crossSectionLimit; j++) {
      float angle = j * two_pi / crossSectionLimit;
      crossSectionValue[j][0] = thickness / 2 * (float) Math.sin(angle);
      crossSectionValue[j][1] = thickness / 2 * (float) Math.cos(angle);
    }
    crossSection.setValue(crossSectionValue);

    // oscilate the spring between 0.3 and 1, with 0.05 increments
    float inc = 0.05f;
    float value = 0.3f;
    float springLength = 2f;
    while (true) {
      value += inc;
      //calculate and set the coordinates for the whole spine
      for (int i = 0; i <= spineLimit; i++) {
	float stepsPerCoil = (float) Math.round(spineLimit / numCoils);
	float angle = i * two_pi / stepsPerCoil;
	spineValue[i][0] = diameter / 2 * (float) Math.cos(angle);
	spineValue[i][1] = springLength / numCoils * value * i / stepsPerCoil;
	spineValue[i][2] = diameter / 2 * (float) Math.sin(angle);
      }
      spine.setValue(spineValue);

      // sleep for 0.1 seconds
      try { thread.sleep(100); } catch (InterruptedException e) {}

      // reverse movement direction
      if (value >= 1f && inc == 0.05f)
	inc = -0.05f;
      else if (value <= 0.3 && inc == -0.05f)
	inc = 0.05f;        
    }
  }

  // handle input (deprecated Java API)
  public boolean handleEvent(Event event) {
    if (event.id == Event.ACTION_EVENT && event.target == choice) 
      changeNumCoils();
    return super.handleEvent(event);
  }

  // changes number of coils in the helix
  private void changeNumCoils() {
    String number = choice.getSelectedItem();
    numCoils = (new Float(number)).floatValue();
  }
}
