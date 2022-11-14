//
// Program: Viewpoint Switcher

// Description: Uses the EAI to cycle between 3 Viewpoints in a VRML scene
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

public class viewswitch extends Applet {

  public void init() {
    super.init();
  }

  public void start() {
    Browser browser = null;
    EventInSFBool bind1 = null;
    EventInSFBool bind2 = null;
    EventInSFBool bind3 = null;

    // Get the VRML Browser - try 10 times
    for (int count = 0; count < 10; count++) {
      browser = BrowserFactory.getBrowser(this);
      if (browser != null) break;
      try { Thread.sleep(200); } catch (InterruptedException e) {}
    }
    
    // Get the set_bind eventIns for the three DEF'd Viewpoint nodes
    try {
      Node view1 = browser.getNode("View1");
      Node view2 = browser.getNode("View2");
      Node view3 = browser.getNode("View3");
      bind1 = (EventInSFBool) view1.getEventIn("set_bind");
      bind2 = (EventInSFBool) view2.getEventIn("set_bind");
      bind3 = (EventInSFBool) view3.getEventIn("set_bind");
    } catch (vrml.eai.InvalidNodeException ignored) {}

    // cycle through each Viewpoint node at 1 sec intervals
    while (true) {
      try { Thread.sleep(1000); } catch (InterruptedException e) {}
      bind1.setValue(true);
      try { Thread.sleep(1000); } catch (InterruptedException e) {}
      bind2.setValue(true);
      try { Thread.sleep(1000); } catch (InterruptedException e) {}
      bind3.setValue(true);
    }
  }
}
