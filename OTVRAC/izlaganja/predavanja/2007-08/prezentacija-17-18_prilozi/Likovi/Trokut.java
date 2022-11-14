import java.util.*;
import java.lang.Math;

public class Trokut extends Lik
{
	double a,b,c;
	public Trokut(String redak)
	{
		Vector args=new Vector();
		args=parsiraj(redak,3);
		this.a=((Double)(args.get(0))).doubleValue();
		this.b=((Double)(args.get(1))).doubleValue();
		this.c=((Double)(args.get(2))).doubleValue();
	}
		
	double izracunajPovrsinu()
	{
		double s=(a+b+c)/2;
		return Math.sqrt(s*(s-a)*(s-b)*(s-c));
	}
	public String toString()
	{
		return "Trokut, a="+a+", b="+b+", c="+c+ "\t";
	}
}