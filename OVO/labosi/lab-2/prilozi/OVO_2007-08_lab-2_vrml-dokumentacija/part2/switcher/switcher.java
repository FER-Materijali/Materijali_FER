//
// Program: Scene Switcher
//
// Description:
//    Uses the EAI to change the value of all Switch nodes in a scene
//    based upon a couple of buttons that the user can press.
//
// Author: Martin Reddy <reddy@ai.sri.com>
// Version: 1.0, 8 March 2001
//
// Compiled against the Cortona 3 EAI classes, corteai.zip
//

import java.awt.*;
import java.applet.*;
import vrml.eai.Node;
import vrml.eai.BrowserFactory;
import vrml.eai.Browser;
import vrml.eai.field.*;

public class switcher extends Applet {

  Browser browser = null;
  String  button1 = "Flick Switch 1";
  String  button2 = "Flick Switch 2";
  
  // create the two applet buttons and get the browser reference
  public void start() {
    setBackground(Color.white);
    add(new Button(button1));
    add(new Button(button2));

    browser = BrowserFactory.getBrowser(this);
  }

  // search scene graph for all Switch nodes and update their whichChoice
  public void set_switch(int value) {
    browser.beginUpdate();
    Node root = browser.getNode("RootNode");
    set_switch_recur((EventOutMFNode) root.getEventOut("children"), value);
    browser.endUpdate();
  }

  // recursive method to do the scene graph traversal
  public void set_switch_recur(EventOutMFNode children, int value) {
    if (children == null) return;

    Node nodes[]  = children.getValue();
    int num_nodes = nodes.length;

    for (int i = 0; i < num_nodes; ++i) {
      String node_type = nodes[i].getType();

      if (node_type.compareTo("Switch") == 0) {

	// Grab the whichChoice field of the Switch and change it
	EventInSFInt32 whichChoice = (EventInSFInt32)
	  nodes[i].getEventIn("whichChoice");

	whichChoice.setValue(value);

      } else if (node_type.compareTo("Group") == 0 ||
		 node_type.compareTo("Transform") == 0 ||
		 node_type.compareTo("Collision") == 0) {
	
	// recurse into grouping nodes - other grouping nodes possible
	set_switch_recur((EventOutMFNode) nodes[i].getEventOut("children"),
			  value);
      }
    }
  }

  // The button event handling routine
  public boolean action(Event event, Object what) {
    if (event.target instanceof Button && browser != null) {
      Button b = (Button) event.target;
      if (b.getLabel() == button1) {
	set_switch(0);
      } else if (b.getLabel() == button2) {
	set_switch(1);
      }
    }
    return true;
  }

}
