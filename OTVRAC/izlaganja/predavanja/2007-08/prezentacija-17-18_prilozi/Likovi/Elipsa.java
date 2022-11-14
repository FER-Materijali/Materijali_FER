import java.lang.Math;
import java.util.*;
	
public class Elipsa extends Lik
{
	double r1,r2;
	public Elipsa(String linija)
	{
		Vector args=new Vector();
		args=parsiraj(linija,2);
		this.r2=((Double)(args.get(0))).doubleValue();
		this.r1=((Double)(args.get(1))).doubleValue();
	}
	
	double izracunajPovrsinu()
	{
		return r1*r2*Math.PI;
	}
	public String toString()
	{
		return "Elipsa, r1="+r1+", r2="+r2+"\t";
	}
}
