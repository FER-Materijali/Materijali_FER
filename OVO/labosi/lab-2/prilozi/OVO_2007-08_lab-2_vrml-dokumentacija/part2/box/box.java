//
// Program: Red Box, Green Box
//
// Description: Uses the EAI to change the colour of a box to green
//
// Author: Martin Reddy <reddy@ai.sri.com>
// Version: 1.0, 6 March 2001
//
// Compiled against the Cortona 3 EAI classes, corteai.zip
//

import java.applet.*;
import vrml.eai.field.*;
import vrml.eai.Node;
import vrml.eai.BrowserFactory;
import vrml.eai.Browser;

public class box extends Applet {

  public void init() {
    super.init();
  }

  public void start() {
    Browser browser = null;
    Node material = null;
    EventInSFColor boxcolor = null;

    // Get the VRML Browser - try 10 times
    for (int count = 0; count < 10; count++) {
      browser = BrowserFactory.getBrowser(this);
      if (browser != null) break;
      try {
	Thread.sleep(200);
      } catch (InterruptedException ignored) {}
    }
    
    // Get the diffuseColor eventIn of the DEF'd material node
    try {
      material = browser.getNode("BoxMaterial");
      boxcolor = (EventInSFColor) material.getEventIn("set_diffuseColor");
    } catch (vrml.eai.InvalidNodeException ignored) {}

    // Sleep for 1 second
    try {
      Thread.sleep(1000);
    } catch ( InterruptedException ignored ) {}

    // Change the material's diffuse color to green (0,1,0)
    float[] newcolor = new float[3];
    newcolor[0] = 0.0f;  newcolor[1] = 1.0f;  newcolor[2] = 0.0f;
    boxcolor.setValue(newcolor);
  }

}
