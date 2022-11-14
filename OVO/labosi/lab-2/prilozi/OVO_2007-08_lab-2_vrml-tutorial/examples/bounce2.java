//
//  bounce2.java
//	by David R. Nadeau
//
//  This script illustrates the use of a Script node to create a computed
//  animation path.  In particular, the script is written in Java and
//  computes translation values for a vertically bouncing beach ball.
//
//  The bounce path is based upon the projectile motion equation of
//  physics, constrained to create a cyclic bouncing path with a
//  user-selected maximum bounce height.  Also, there is no friction,
//  drag, or damping.  For an explanation of the script, see 'bounce1.wrl'.
//


//
//  Import the VRML script node packages
//
import vrml.*;
import vrml.field.*;
import vrml.node.*;


//
//  bounce2 class
//	The class must extend the Script class
//
public class bounce2
	extends Script
{
	// Parameters for the script
	private float bounceHeight;

	// Script node eventOuts
	private SFVec3f value_changedObj;


	//
	//  Initialize the script - called once at script load
	//
	public void initialize( )
	{
		// Get the fields and eventOut
		SFFloat floatObj = (SFFloat) getField( "bounceHeight" );
		bounceHeight     = (float)   floatObj.getValue( );
		value_changedObj = (SFVec3f) getEventOut( "value_changed" );
	}


	//
	//  Respond to an event on the script's eventIn
	//
	public void processEvent( Event event )
	{
		ConstSFFloat flt = (ConstSFFloat) event.getValue( );
		float frac       = (float) flt.getValue( );

		float y = (float)(4.0 * bounceHeight * frac * (1.0 - frac));

		float[] changed = new float[3];
		changed[0] = (float)0.0;
		changed[1] = y;
		changed[2] = (float)0.0;
		value_changedObj.setValue( changed );
	}
}
