//
// Program: Create Sphere
// Description: Uses the EAI to add new geometry to an existing scene
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

public class create extends Applet {

  public void init() {
    super.init();
  }

  public void start() {
    Browser       browser  = null;
    Node          rootnode = null;
    EventInMFNode children = null;

    // Get the VRML Browser - try 10 times
    for (int count = 0; count < 10; count++) {
      browser = BrowserFactory.getBrowser(this);
      if (browser != null) break;
      try { Thread.sleep(200); } catch (InterruptedException e) {}
    }
    
    // Get the set_children eventIn of the DEF'd Group node
    try {
      rootnode = browser.getNode("NewNode");
      children = (EventInMFNode) rootnode.getEventIn("set_children");
    } catch (vrml.eai.InvalidNodeException ignored) {}

    // Create a new blue Sphere Shape node
    String newvrml =
      "#VRML V2.0 utf8\nShape { appearance Appearance { material " +
      "Material { diffuseColor 0 0 1 } } geometry Sphere { radius 1 } }";
    
    // Create and add the new node to the scene graph
    children.setValue( browser.createVrmlFromString( newvrml ) );
  }

}
